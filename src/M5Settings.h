#ifndef _M5SETTINGS_H_
#define _M5SETTINGS_H_

/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* Settings-Functions
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
#include <ArduinoJson.h>
#include <LinkedList.h>
#include <SPIFFS.h>

#include "M5Wifi.h"

/******************************************************************************
* Prototypes
*******************************************************************************/
void m5set_initSettings(void);
void m5set_createSettings(void);
void m5set_saveSettings(void);
void m5set_loadSettings(void);
void m5set_clearSettings(void);
void m5set_printWifiList(void);

/******************************************************************************
* Definitions
*******************************************************************************/
struct Settings
{
	char wifiSsid[32];
	char wifiPwd[32];
	boolean isWifiConnected;
	boolean isNTPTime;
	uint8_t hour, mins;
};

/******************************************************************************
* Global Variables
*******************************************************************************/
extern struct Settings *globalSettings;

#endif
