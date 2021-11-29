/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* Frame: Checkbox-Test
*******************************************************************************/

/******************************************************************************
* Header-Files
*******************************************************************************/
#include <M5Core2.h>

#include <Oscil.h>
#include <tables/sin2048_int8.h>

#include "main.h"
#include "frame_checkbox.h"

/******************************************************************************
* Global Variables
*******************************************************************************/
Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);
uint8_t gain = 255;

/******************************************************************************
* Functions
*******************************************************************************/

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_Checkbox::Frame_Checkbox(void)
{
	_frame_name = "Frame_Checkbox";
	_hasMozzi = true;

	for (uint8_t y = 0; y < 7; y++)
	{
		for (uint8_t x = 0; x < 8; x++)
			_cb[(y * 8) + x] = new GUI_Checkbox(8 + (x * 24), (2 * 24) + 8 + (y * 24));
	}

	_but[0] = new GUI_Button("Ok", 10 + 200 + 28 + 8, 8 + (2 * 24) + (0 * 32), 64, 32);
	_but[1] = new GUI_Button("Exit", 10 + 200 + 28 + 8, 8 + (2 * 24) + (1 * 32) + (1 * 8), 64, 32);
	_but[1]->AddArgs(EVENT_RELEASED, 0, (void *)(&_is_run));
	_but[1]->Bind(EVENT_RELEASED, &Frame_Base::exit_cb);

	exitbtn();
	_key_exit->AddArgs(EVENT_RELEASED, 0, (void *)(&_is_run));
	_key_exit->Bind(EVENT_RELEASED, &Frame_Base::exit_cb);

	aSin.setFreq(1760);
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
Frame_Checkbox::~Frame_Checkbox(void)
{
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
int Frame_Checkbox::init(gui_args_vector_t &args)
{
	_is_run = 1;

	// Window
	openWindow(0, 24, 320, 216, _frame_name);

	for (uint8_t y = 0; y < 7; y++)
	{
		for (uint8_t x = 0; x < 8; x++)
		{
			GUI_AddObject(_cb[(y * 8) + x]);
			_cb[(y * 8) + x]->init();
		}
	}

	for (uint8_t i = 0; i < 2; i++)
	{
		GUI_AddObject(_but[i]);
		_but[i]->init();
	}

	return 3;
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
int Frame_Checkbox::run()
{
	//Frame_Base::run();

	return 1;
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
void Frame_Checkbox::updateControl()
{
	gain -= 3;
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
AudioOutput_t Frame_Checkbox::updateAudio()
{
	return MonoOutput::from16Bit(aSin.next() * gain);
}
