/** 
* @file llfloaterinspect.h
* @author Cube
* @date 2006-12-16
* @brief Declaration of class for displaying object attributes
*
* $LicenseInfo:firstyear=2006&license=viewerlgpl$
* Second Life Viewer Source Code
* Copyright (C) 2010, Linden Research, Inc.
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

#ifndef LL_LLFLOATERINSPECT_H
#define LL_LLFLOATERINSPECT_H

#include "llavatarname.h"
#include "llfloater.h"
#include "llviewerobject.h" // PoundLife - Improved Object Inspect

//class LLTool;
class LLObjectSelection;
class LLScrollListCtrl;
class LLUICtrl;
// [RLVa:KB] - Checked: RLVa-2.0.1
class LLSelectNode;
// [/RLVa:KB]
class LLMenuButton; // <FS:Ansariel> FIRE-22292: Configurable columns

class LLFloaterInspect : public LLFloater
{
	friend class LLFloaterReg;
public:

//	static void show(void* ignored = NULL);
	void onOpen(const LLSD& key);
	virtual BOOL postBuild();
	void dirty();
	LLUUID getSelectedUUID();
	virtual void draw();
	virtual void refresh();
//	static BOOL isVisible();
	virtual void onFocusReceived();
	void onClickCreatorProfile();
	void onClickOwnerProfile();
	void onSelectObject();
	// PoundLife - Improved Object Inspect
	U64 mStatsMemoryTotal;
	// PoundLife - End
	LLScrollListCtrl* mObjectList;
protected:
	// protected members
	void setDirty() { mDirty = TRUE; }
	bool mDirty;

// [RLVa:KB] - Checked: RLVa-2.0.1
	const LLSelectNode* getSelectedNode() /*const*/;
// [/RLVa:KB]

private:
	// PoundLife - Improved Object Inspect
	void getObjectTextureMemory(LLViewerObject* object, U32& object_texture_memory, U32& object_vram_memory);
	void calculateTextureMemory(LLViewerTexture* texture, uuid_vec_t& object_texture_list, U32& object_texture_memory, U32& object_vram_memory);
	uuid_vec_t mTextureList;
	U32 mTextureMemory;
	U32 mTextureVRAMMemory;
	// PoundLife - End
	void onGetOwnerNameCallback();
	void onGetCreatorNameCallback();
	
	LLFloaterInspect(const LLSD& key);
	virtual ~LLFloaterInspect(void);

	LLSafeHandle<LLObjectSelection> mObjectSelection;
	boost::signals2::connection mOwnerNameCacheConnection;
	boost::signals2::connection mCreatorNameCacheConnection;

	// <FS:Ansariel> FIRE-22292: Configurable columns
	void						onColumnDisplayModeChanged();
	void						onColumnVisibilityChecked(const LLSD& userdata);
	bool						onEnableColumnVisibilityChecked(const LLSD& userdata);

	LLMenuButton*				mOptionsButton;
	LLHandle<LLView>			mOptionsMenuHandle;

	std::map<std::string, U32>	mColumnBits;
	S32							mLastResizeDelta;
	boost::signals2::connection	mFSInspectColumnConfigConnection;
	// </FS:Ansariel>
};

#endif //LL_LLFLOATERINSPECT_H
