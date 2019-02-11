// WiFiUtil.h

#ifndef _WIFIUTIL_h
#define _WIFIUTIL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



// WiFi 연결 함수
// 매개변수 SSID와 비밀번호
 void wifi_init(char *ssid, char *password);

// WiFi 연결 상태 출력 함수
void printWifiStatus();
	




#endif

