/**
 * @file fsfloatergrouptitles.h
 * @brief Group title overview and changer
 *
 * $LicenseInfo:firstyear=2012&license=viewerlgpl$
 * Copyright (c) 2012 Ansariel Hiller @ Second Life
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
 * The Phoenix Firestorm Project, Inc., 1831 Oakwood Drive, Fairmont, Minnesota 56031-3225 USA
 * http://www.firestormviewer.org
 * $/LicenseInfo$
 */

#ifndef FS_FLOATERGROUPTITLES_H
#define FS_FLOATERGROUPTITLES_H

#include "llfloater.h"

#include "llagent.h"
#include "llgroupmgr.h"

class FSFloaterGroupTitles;
class LLFilterEditor;
class LLScrollListCtrl;

class FSGroupTitlesObserver : LLGroupMgrObserver
{

public:
	FSGroupTitlesObserver(const LLGroupData& group_data, LLHandle<FSFloaterGroupTitles> parent);
	virtual ~FSGroupTitlesObserver();

	virtual void changed(LLGroupChange gc);

protected:
	LLHandle<FSFloaterGroupTitles>	mParent;
	LLGroupData						mGroupData;
};

class FSFloaterGroupTitles : public LLFloater, public LLGroupMgrObserver, public LLOldEvents::LLSimpleListener
{

public:
	FSFloaterGroupTitles(const LLSD &);
	virtual ~FSFloaterGroupTitles();

	/*virtual*/ BOOL postBuild();
	/*virtual*/ void onOpen(const LLSD& key);
	/*virtual*/ BOOL handleKeyHere(KEY key, MASK mask);
	/*virtual*/ bool hasAccelerators() const { return true; }

	virtual void changed(LLGroupChange gc);
	bool handleEvent(LLPointer<LLOldEvents::LLEvent> event, const LLSD& userdata); // called on agent group list changes

	void processGroupTitleResults(const LLGroupData& group_data);

private:
	void clearObservers();

	void addListItem(const LLUUID& group_id, const LLUUID& role_id, const std::string& title,
		const std::string& group_name, bool is_active, bool is_no_group = true);

	void refreshGroupTitles();
	void activateGroupTitle();
	void selectedTitleChanged();
	void openGroupInfo();
	void onFilterEdit(const std::string& search_string);

	LLButton*			mActivateButton;
	LLButton*			mRefreshButton;
	LLButton*			mInfoButton;
	LLScrollListCtrl*	mTitleList;
	LLFilterEditor*		mFilterEditor;

	std::string			mFilterSubString;
	std::string			mFilterSubStringOrig;

	typedef std::map<LLUUID, FSGroupTitlesObserver*> observer_map_t;
	observer_map_t		mGroupTitleObserverMap;
};

#endif // FS_FLOATERGROUPTITLES_H
