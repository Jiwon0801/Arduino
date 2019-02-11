// WiFiUtil.h

#ifndef _WIFIUTIL_h
#define _WIFIUTIL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



// WiFi ���� �Լ�
// �Ű����� SSID�� ��й�ȣ
 void wifi_init(char *ssid, char *password);

// WiFi ���� ���� ��� �Լ�
void printWifiStatus();
	




#endif

