/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* Frame: Wifi-Manager
*******************************************************************************/

/******************************************************************************
* Header-Files
*******************************************************************************/
#include <M5Core2.h>

#include "main.h"
#include "frame_wifiman.h"

/******************************************************************************
* Global Variables
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_WifiMan::Frame_WifiMan(void)
{
	_frame_name = "Frame_WifiMan";

	_list = new GUI_List(10, 10 + (2 * 24), 200, 160);
	_but[0] = new GUI_Button(BUT_ARROWUP, 10 + 200 + 1, 10 + (2 * 24) + 160 - 64, 28, 32);
	_but[1] = new GUI_Button(BUT_ARROWUP, 10 + 200 + 1, 10 + (2 * 24) + 160 - 32, 28, 32);

	exitbtn();
	_key_exit->AddArgs(GUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
	_key_exit->Bind(GUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}
	
/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_WifiMan::~Frame_WifiMan(void)
{
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
int Frame_WifiMan::init(gui_args_vector_t &args)
{
	_is_run = 1;

	// Window
	openWindow(0, 24, 320, 216, _frame_name);

	GUI_AddObject(_list);
	_list->init();

	GUI_AddObject(_but[0]);
	_but[0]->init();
	GUI_AddObject(_but[1]);
	_but[1]->init();

	return 3;
}
