/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* Frame: Main
*******************************************************************************/

/******************************************************************************
* Header-Files
*******************************************************************************/
#include "main.h"
#include "../gui/gui.h"

#include "frame_main.h"
#include "frame_settings.h"

/******************************************************************************
* Functions
*******************************************************************************/

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
void key_app0_cb(gui_args_vector_t &args)
{
	Frame_Base *frame = GUI_GetFrame("Frame_Settings");

	if (frame == NULL)
	{
		frame = new Frame_Settings();
		GUI_AddFrame("Frame_Settings", frame);
	}
	GUI_PushFrame(frame);
	*((int*)(args[0])) = 0;
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_Main::Frame_Main(void): Frame_Base(false)
{
	_frame_name = "Frame_Main";
	_frame_id = 1;

	for (uint8_t y = 0; y < (MAX_APPS / 4); y++)
	{
		for (uint8_t x = 0; x < 4; x++)
		{
			sprintf(buffer, "But%01d", (y * 4) + x);
			switch ((y * 4) + x)
			{
				case 0:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Font_U, Icon_Font_D);
					break;
				case 1:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_IControl_U, Icon_IControl_D);
					break;
				case 2:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Input_U, Icon_Input_D);
					break;
				case 3:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Locale_U, Icon_Locale_D);
					break;
				case 4:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Overscan_U, Icon_Overscan_D);
					break;
				case 5:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Palette_U, Icon_Palette_D);
					break;
				case 6:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Pointer_U, Icon_Pointer_D);
					break;
				case 7:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_ScreenMode_U, Icon_ScreenMode_D);
					break;
				case 8:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Serial_U, Icon_Serial_D);
					break;
				case 9:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Sound_U, Icon_Sound_D);
					break;
				case 10:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_Time_U, Icon_Time_D);
					break;
				case 11:
					_key[(y * 4) + x] = new GUI_Button(buffer, (x * (KEY_W + 8)) + 8, (y * (KEY_H + 24)) + 8 + 24, KEY_W, KEY_H, Icon_WBPattern_U, Icon_WBPattern_D);
					break;
			}
		}
	}

	// Button-Functions
	_key[0]->AddArgs(GUI_Button::EVENT_RELEASED, 0, (void*)(&_is_run));
	_key[0]->Bind(GUI_Button::EVENT_RELEASED, key_app0_cb);

	_time = 0;
	_next_update_time = 0;
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_Main::~Frame_Main()
{
	for (uint8_t i = 0; i < MAX_APPS; i++)
		delete _key[i];
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
void Frame_Main::AppName()
{
	for (uint8_t y = 0; y < (MAX_APPS / 4); y++)
	{
		for (uint8_t x = 0; x < 4; x++)
		{
			switch ((y * 4) + x)
			{
				case 0:
					sprintf(buffer, "Font");
					break;
				case 1:
					sprintf(buffer, "IControl");
					break;
				case 2:
					sprintf(buffer, "Input");
					break;
				case 3:
					sprintf(buffer, "Locale");
					break;
				case 4:
					sprintf(buffer, "Overscan");
					break;
				case 5:
					sprintf(buffer, "Palette");
					break;
				case 6:
					sprintf(buffer, "Pointer");
					break;
				case 7:
					sprintf(buffer, "ScrMode");
					break;
				case 8:
					sprintf(buffer, "Serial");
					break;
				case 9:
					sprintf(buffer, "Sound");
					break;
				case 10:
					sprintf(buffer, "Time");
					break;
				case 11:
					sprintf(buffer, "Pattern");
					break;
			}
			uint16_t xtext = (x * (KEY_W + 8)) + 8 + ((KEY_W / 2) - (M5.Lcd.textWidth(buffer) / 2));
			uint16_t ytext = (y * (KEY_H + 24)) + 8 + 24 + KEY_H + 14;

			M5.Lcd.setCursor(xtext, ytext);
			M5.Lcd.print(buffer);
		}
	}
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
void Frame_Main::StatusBar()
{
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
int Frame_Main::init(gui_args_vector_t &args)
{
	_is_run = 1;

	M5.Lcd.clear(M5.Lcd.color565(149, 149, 149));
	M5.Lcd.drawBitmap(0, 0, 320, 24, titlebar);

	M5.Lcd.setFreeFont(&FreeSans9pt7b);
	M5.Lcd.setTextSize(1);
	M5.Lcd.setTextColor(BLACK);

	M5.Lcd.setCursor(8, 15);
	M5.Lcd.println("Amiga Workbench");

	for (uint8_t i = 0; i < MAX_APPS; i++)
	{
		GUI_AddObject(_key[i]);
		_key[i]->init();
	}

	_time = 0;
	_next_update_time = 0;

	//StatusBar();
	AppName();
	return 9;
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
int Frame_Main::run()
{
	Frame_Base::run();
	//StatusBar();
	return 1;
}
