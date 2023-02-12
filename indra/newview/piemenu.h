/**
 * @file piemenu.h
 * @brief Pie menu class
 *
 * $LicenseInfo:firstyear=2001&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2010, Linden Research, Inc.
 * Copyright (C) 2011, Zi Ree @ Second Life
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

#ifndef PIEMENU_H
#define PIEMENU_H

#include "llmenugl.h"
#include "llframetimer.h"

const S32 PIE_MAX_SLICES = 8;

// PieChildRegistry contains a list of allowed child types for the XUI definition
struct PieChildRegistry : public LLChildRegistry<PieChildRegistry>
{
	LLSINGLETON_EMPTY_CTOR(PieChildRegistry);
};

class PieMenu : public LLMenuGL
{
public:
	// parameter block for the XUI factory
	struct Params : public LLInitParam::Block<Params, LLMenuGL::Params>
	{
		Optional<std::string> name;

		Params()
		{
			visible = false;
		}
	};

	// PieChildRegistry contains a list of allowed child types for the XUI definition
	typedef PieChildRegistry child_registry_t;

	PieMenu(const LLMenuGL::Params& p);

	/*virtual*/ void setVisible(BOOL visible);

	// adding and removing "child" slices to the pie
	/*virtual*/ bool addChild(LLView* child, S32 tab_group = 0);
	/*virtual*/ void removeChild(LLView* child);

	/*virtual*/ BOOL handleHover(S32 x, S32 y, MASK mask);
	/*virtual*/ BOOL handleMouseUp(S32 x, S32 y, MASK mask);
	/*virtual*/ BOOL handleRightMouseUp(S32 x, S32 y, MASK mask);

	// does all the hard work of bringing the menu on the screen
	void draw();

	// showing/hiding the menu
	void show(S32 x, S32 y, LLView* spawning_view = NULL);
	void hide();

	// our item list type definition
	typedef std::list<LLView*> slice_list_t;
	// the actual item list
	slice_list_t mMySlices;
	// pointer to the currently used list
	slice_list_t* mSlices;

	// appends a sub pie menu to the current pie
	BOOL appendContextSubMenu(PieMenu* menu);

	// we never rearrange our menu
	void needsArrange() {};
	// arranging does nothing
	virtual void arrange( void ) {};
	// arranging does nothing
	void arrangeAndClear( void ) {};

protected:
	// general mouse button handling
	BOOL handleMouseButtonUp(S32 x, S32 y, MASK mask);
	// font used for the menu
	const LLFontGL* mFont;
	// currently highlighted item, must be tested if it's a slice or submenu
	LLView* mSlice;
	// used to play UI sounds only once on hover slice change, do not dereference!
	LLView* mOldSlice;

	// timer for visual popup effect
	LLFrameTimer mPopupTimer;

	// this is TRUE when the first mouseclick came to display the menu, used for borderless menu
	bool mFirstClick;

	F32 getScaleFactor();

	S32 mCurrentSegment;
};

#endif // PIEMENU_H
