#ifndef _FRAME_WINDEMO_H_
#define _FRAME_WINDEMO_H_

/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* Frame: Window-Demo
*******************************************************************************/

/******************************************************************************
* Header-Files
*******************************************************************************/
#include "frame_base.h"
#include "../gui/gui.h"

/******************************************************************************
* Class Definition
*******************************************************************************/
class Frame_WinDemo : public Frame_Base
{
	public:
		Frame_WinDemo();
		~Frame_WinDemo();
		int init(gui_args_vector_t &args);

	private:
};

#endif
