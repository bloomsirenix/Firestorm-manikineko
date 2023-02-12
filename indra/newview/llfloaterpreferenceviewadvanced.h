/** 
 * @file llfloaterpreferenceviewadvanced.h
 * @brief floater for adjusting camera position
 *
 * $LicenseInfo:firstyear=2018&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2018, Linden Research, Inc.
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

#ifndef LLFLOATERPREFERENCEVIEWADVANCED_H
#define LLFLOATERPREFERENCEVIEWADVANCED_H

#include "llcontrol.h"
#include "llfloater.h"

class LLFloaterPreferenceViewAdvanced
:	public LLFloater
{
	friend class LLFloaterReg;

public:
	LLFloaterPreferenceViewAdvanced(const LLSD& key);
	virtual void draw();

	void onCommitSettings();
	void updateCameraControl(const LLVector3& vector);
	void updateFocusControl(const LLVector3d& vector3d);
	void onSavePreset(); // <FS:Ansariel> Improved camera floater

private:
	virtual ~LLFloaterPreferenceViewAdvanced();
};

#endif //LLFLOATERPREFERENCEVIEWADVANCED_H

