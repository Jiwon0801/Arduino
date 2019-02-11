// 
// 
// 

#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include "WiFiUtil.h"

extern SoftwareSerial softSerial;
int status = WL_IDLE_STATUS; // Wifi 전파 상태

void wifi_init(char * ssid, char * password)
{

	Serial.begin(9600);
	softSerial.begin(9600);

	// SoftwareSerial로 ESP 모듈 연결 및 초기화
	WiFi.init(&softSerial);

	// ESP 모듈 존재 체크
	if (WiFi.status() == WL_NO_SHIELD) {
		Serial.println("WiFi shield not present");
		while (true); // don't continue
	}

	while (status != WL_CONNECTED) {
		Serial.print("Attempting to connect to WPA SSID: ");
		Serial.println(ssid); // WPA/WPA2 네트워크 연결시도
		status = WiFi.begin(ssid, password);
	}

	// 네트워크 연결 성공
	Serial.println("You're connected to the network");
	// 네트워크 정보 출력 함수 호출 - 뒤에서 정의
	printWifiStatus();
}

void printWifiStatus()
{
	// 연결된 네트워크의 SSID 출력
	Serial.print("SSID: ");
	Serial.println(WiFi.SSID());
	
	// 할당된 IP 주소 출력
	IPAddress ip = WiFi.localIP();
	Serial.print("IP Address: ");
	Serial.println(ip);
	
	// 수신된 신호 강도 출력
	long rssi = WiFi.RSSI();
	Serial.print("Signal strength (RSSI):");
	Serial.print(rssi);
	Serial.println(" dBm");
}
