#ifndef _MAIN_H
#define _MAIN_H

/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* Main-Program
*******************************************************************************/

// Comment templates

/******************************************************************************
*
*******************************************************************************/

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/

/******************************************************************************/

/******************************************************************************
* Header-Files
*******************************************************************************/
#include <Arduino.h>
#include <LinkedList.h>

/******************************************************************************
* Prototypes
*******************************************************************************/
bool InitI2SSpeakerOrMic(int mode);
void i2s_task(void *arg);

/******************************************************************************
* Definitions
*******************************************************************************/
#define CONFIG_I2S_BCK_PIN 12
#define CONFIG_I2S_LRCK_PIN 0
#define CONFIG_I2S_DATA_PIN 2
#define CONFIG_I2S_DATA_IN_PIN 34

#define Speak_I2S_NUMBER I2S_NUM_0
#define MODE_MIC 0
#define MODE_SPK 1

#define MWB_GRAY	0x9492
#define MWB_BLACK	0x0000
#define MWB_WHITE	0xFFFF
#define MWB_BLUE	0x3B33
#define MWB_GRAY2	0x73CE
#define MWB_GRAY3	0xAD75
#define MWB_BROWN	0xA46F
#define MWB_PINK	0xFD32

/******************************************************************************
* Global Variables
*******************************************************************************/
extern const unsigned char previewR[120264];

extern char buffer[16];

#endif
