/** 
 * @file llfloatersidepanelcontainer.cpp
 * @brief LLFloaterSidePanelContainer class definition
 *
 * $LicenseInfo:firstyear=2011&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2011, Linden Research, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

#include "llviewerprecompiledheaders.h"

#include "llfloaterreg.h"
#include "llfloatersidepanelcontainer.h"
#include "llpaneleditwearable.h"

// newview includes
#include "llsidetraypanelcontainer.h"
#include "lltransientfloatermgr.h"
#include "llpaneloutfitedit.h"
#include "llsidepanelappearance.h"

//static
const std::string LLFloaterSidePanelContainer::sMainPanelName("main_panel");

// [RLVa:KB] - Checked: 2012-02-07 (RLVa-1.4.5) | Added: RLVa-1.4.5
LLFloaterSidePanelContainer::validate_signal_t LLFloaterSidePanelContainer::mValidateSignal;
// [/RLVa:KB]

LLFloaterSidePanelContainer::LLFloaterSidePanelContainer(const LLSD& key, const Params& params)
:	LLFloater(key, params)
{
	// Prevent transient floaters (e.g. IM windows) from hiding
	// when this floater is clicked.
	LLTransientFloaterMgr::getInstance()->addControlView(LLTransientFloaterMgr::GLOBAL, this);
}

LLFloaterSidePanelContainer::~LLFloaterSidePanelContainer()
{
	LLTransientFloaterMgr::getInstance()->removeControlView(LLTransientFloaterMgr::GLOBAL, this);
}

void LLFloaterSidePanelContainer::onOpen(const LLSD& key)
{
	getChild<LLPanel>(sMainPanelName)->onOpen(key);
}

void LLFloaterSidePanelContainer::closeFloater(bool app_quitting)
{
	LLPanelOutfitEdit* panel_outfit_edit =
		dynamic_cast<LLPanelOutfitEdit*>(LLFloaterSidePanelContainer::findPanel("appearance", "panel_outfit_edit"));
	if (panel_outfit_edit)
	{
		LLFloater *parent = gFloaterView->getParentFloater(panel_outfit_edit);
		if (parent == this )
		{
			LLSidepanelAppearance* panel_appearance = dynamic_cast<LLSidepanelAppearance*>(getPanel("appearance"));
			if ( panel_appearance )
			{
				LLPanelEditWearable *edit_wearable_ptr = panel_appearance->getWearable();
				if (edit_wearable_ptr)
				{
					edit_wearable_ptr->onClose();
				}
				if(!app_quitting)
				{
					panel_appearance->showOutfitsInventoryPanel();
				}
			}
		}
	}
	
	LLFloater::closeFloater(app_quitting);

	// <FS:Ansariel> Special secondary inventory floaters
	//if (getInstanceName() == "inventory" && !getKey().isUndefined())
	if ((getInstanceName() == "inventory" && !getKey().isUndefined()) || getInstanceName() == "secondary_inventory")
	// </FS:Ansariel>
	{
		destroy();
	}
}

LLFloater* LLFloaterSidePanelContainer::getTopmostInventoryFloater()
{
    LLFloater* topmost_floater = NULL;
    S32 z_min = S32_MAX;
    
    LLFloaterReg::const_instance_list_t& inst_list = LLFloaterReg::getFloaterList("inventory");
    // <FS:Ansariel> Fix for sharing inventory when multiple inventory floaters are open:
    //               For the secondary floaters, we have registered those as
    //               "secondary_inventory" in LLFloaterReg, so we have to add those
    //               instances to the instance list!
    //for (LLFloaterReg::const_instance_list_t::const_iterator iter = inst_list.begin(); iter != inst_list.end(); ++iter)
    LLFloaterReg::const_instance_list_t& inst_list_secondary = LLFloaterReg::getFloaterList("secondary_inventory");
    LLFloaterReg::instance_list_t combined_list;
    combined_list.insert(combined_list.end(), inst_list.begin(), inst_list.end());
    combined_list.insert(combined_list.end(), inst_list_secondary.begin(), inst_list_secondary.end());
    for (LLFloaterReg::instance_list_t::const_iterator iter = combined_list.begin(); iter != combined_list.end(); ++iter)
    // </FS:Ansariel>
    {
        LLFloater* inventory_floater = (*iter);

        if (inventory_floater && inventory_floater->getVisible())
        {
            S32 z_order = gFloaterView->getZOrder(inventory_floater);
            if (z_order < z_min)
            {
                z_min = z_order;
                topmost_floater = inventory_floater;
            }
        }
    }
    return topmost_floater;
}

LLPanel* LLFloaterSidePanelContainer::openChildPanel(const std::string& panel_name, const LLSD& params)
{
	LLView* view = findChildView(panel_name, true);
	if (!view) return NULL;

	if (!getVisible())
	{
	openFloater();
	}

	LLPanel* panel = NULL;

	LLSideTrayPanelContainer* container = dynamic_cast<LLSideTrayPanelContainer*>(view->getParent());
	if (container)
	{
		container->openPanel(panel_name, params);
		panel = container->getCurrentPanel();
	}
	else if ((panel = dynamic_cast<LLPanel*>(view)) != NULL)
	{
		panel->onOpen(params);
	}

	return panel;
}

// [RLVa:KB] - Checked: 2012-02-07 (RLVa-1.4.5) | Added: RLVa-1.4.5
bool LLFloaterSidePanelContainer::canShowPanel(const std::string& floater_name, const LLSD& key)
{
	return mValidateSignal(floater_name, sMainPanelName, key);
}

bool LLFloaterSidePanelContainer::canShowPanel(const std::string& floater_name, const std::string& panel_name, const LLSD& key)
{
	return mValidateSignal(floater_name, panel_name, key);
}
// [/RLVa:KB]
	
void LLFloaterSidePanelContainer::showPanel(const std::string& floater_name, const LLSD& key)
{
	LLFloaterSidePanelContainer* floaterp = LLFloaterReg::getTypedInstance<LLFloaterSidePanelContainer>(floater_name);
//	if (floaterp)
// [RLVa:KB] - Checked: 2013-04-16 (RLVa-1.4.8)
	if ( (floaterp) && ((floaterp->getVisible()) || (LLFloaterReg::canShowInstance(floater_name, key))) && (canShowPanel(floater_name, key)) )
// [/RLVa:KB]
	{
		floaterp->openChildPanel(sMainPanelName, key);
	}
}

void LLFloaterSidePanelContainer::showPanel(const std::string& floater_name, const std::string& panel_name, const LLSD& key)
{
	LLFloaterSidePanelContainer* floaterp = LLFloaterReg::getTypedInstance<LLFloaterSidePanelContainer>(floater_name);
//	if (floaterp)
// [RLVa:KB] - Checked: 2013-04-16 (RLVa-1.4.8)
	if ( (floaterp) && ((floaterp->getVisible()) || (LLFloaterReg::canShowInstance(floater_name, key))) && (canShowPanel(floater_name, panel_name, key)) )
// [/RLVa:KB]
	{
		floaterp->openChildPanel(panel_name, key);
	}
}

LLPanel* LLFloaterSidePanelContainer::getPanel(const std::string& floater_name, const std::string& panel_name)
{
	LLFloaterSidePanelContainer* floaterp = LLFloaterReg::getTypedInstance<LLFloaterSidePanelContainer>(floater_name);

	if (floaterp)
	{
		return floaterp->findChild<LLPanel>(panel_name, true);
	}

	return NULL;
}

LLPanel* LLFloaterSidePanelContainer::findPanel(const std::string& floater_name, const std::string& panel_name)
{
	LLFloaterSidePanelContainer* floaterp = LLFloaterReg::findTypedInstance<LLFloaterSidePanelContainer>(floater_name);

	if (floaterp)
	{
		return floaterp->findChild<LLPanel>(panel_name, true);
	}

	return NULL;
}
