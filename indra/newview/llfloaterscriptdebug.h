/** 
 * @file llfloaterscriptdebug.h
 * @brief Shows error and warning output from scripts
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

#ifndef LL_LLFLOATERSCRIPTDEBUG_H
#define LL_LLFLOATERSCRIPTDEBUG_H

#include "llmultifloater.h"
#include "llviewerchat.h"

class LLTextEditor;
class LLUUID;

class LLFloaterScriptDebug : public LLMultiFloater
{
public:
	LLFloaterScriptDebug(const LLSD& key);
	virtual ~LLFloaterScriptDebug();
	virtual BOOL postBuild();
	//virtual void setVisible(BOOL visible); // <FS:Ansariel> Improved script debug floater
	static void show(const LLUUID& object_id);

    /*virtual*/ //void closeFloater(bool app_quitting = false); // <FS:Ansariel> Improved script debug floater
	// <FS:Kadah> [FSllOwnerSayToScriptDebugWindow]
	// static void addScriptLine(const std::string &utf8mesg, const std::string &user_name, const LLColor4& color, const LLUUID& source_id);
	static void addScriptLine(const LLChat& chat);

protected:
	// <FS:Ansariel> Script debug icon
	//static LLFloater* addOutputWindow(const LLUUID& object_id);
	static LLFloater* addOutputWindow(const LLUUID& object_id, bool show = false);
	// </FS:Ansariel> Script debug icon

protected:
	static LLFloaterScriptDebug*	sInstance;

// <FS:Kadah> [FSllOwnerSayToScriptDebugWindow]
private:
	/*virtual*/ void onClickCloseBtn(bool app_qutting);
};

class LLFloaterScriptDebugOutput : public LLFloater
{
public:
	LLFloaterScriptDebugOutput(const LLSD& object_id);
	~LLFloaterScriptDebugOutput();

	// <FS:Kadah> [FSllOwnerSayToScriptDebugWindow]
	// void addLine(const std::string &utf8mesg, const std::string &user_name, const LLColor4& color);
	void addLine(const LLChat& chat, const std::string &user_name);

	virtual BOOL postBuild();

	// <FS:Kadah> [FSllOwnerSayToScriptDebugWindow]
	void clear();
	
protected:
	LLTextEditor* mHistoryEditor;

	LLUUID mObjectID;

	// <FS:Kadah> [FSllOwnerSayToScriptDebugWindow]
	std::string mUserName; //KC: This should be "object_name", but LL.
};

#endif // LL_LLFLOATERSCRIPTDEBUG_H
