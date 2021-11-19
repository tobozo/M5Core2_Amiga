/******************************************************************************
* M5Core2_Amiga
* (C)2021 M.Volkel
*
* RTC-Functions
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
#include <M5Core2.h>

#include "M5RTC.h"
#include "M5Settings.h"

/******************************************************************************
* Global Variables
*******************************************************************************/
RTC_TimeTypeDef RTCtime;
RTC_DateTypeDef RTCDate;

/******************************************************************************
* Functions
*******************************************************************************/

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
void m5rtc_setupTime(void)
{
	RTCDate.Year = timeinfo.tm_year;
	RTCDate.Month = timeinfo.tm_mon;
	RTCDate.Date = timeinfo.tm_mday;
	M5.Rtc.SetDate(&RTCDate);

	RTCtime.Hours = timeinfo.tm_hour;
	RTCtime.Minutes = timeinfo.tm_min;
	RTCtime.Seconds = timeinfo.tm_sec;
	M5.Rtc.SetTime(&RTCtime);
}

/*------------------------------------------------------------------------------
-
------------------------------------------------------------------------------*/
void m5rtc_getTime(void)
{
	M5.Rtc.GetTime(&RTCtime);
	globalSettings->hour = RTCtime.Hours;
	globalSettings->mins = RTCtime.Minutes;
}
