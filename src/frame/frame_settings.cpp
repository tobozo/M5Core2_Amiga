/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* Frame: Settings
*******************************************************************************/

/******************************************************************************
* Header-Files
*******************************************************************************/
#include <M5Core2.h>
#include "frame_settings.h"

/******************************************************************************
* Functions
*******************************************************************************/

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_Settings::Frame_Settings(void)
{
	_frame_name = "Frame_Settings";

	M5.Lcd.drawBitmap(0, 24, 320, 216, Window);

	exitbtn();
	_key_exit->AddArgs(GUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
	_key_exit->Bind(GUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);

	M5.Lcd.setCursor(24 + 8, 41);
	M5.Lcd.println(_frame_name);
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_Settings::~Frame_Settings(void)
{
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
int Frame_Settings::init(gui_args_vector_t &args)
{
	_is_run = 1;

	M5.Lcd.drawBitmap(0, 24, 320, 216, Window);

	M5.Lcd.setCursor(24 + 8, 41);
	M5.Lcd.println(_frame_name);

	GUI_AddObject(_key_exit);
	_key_exit->init();

	return 3;
}
