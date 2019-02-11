// 
// 
// 

#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include "WiFiUtil.h"

extern SoftwareSerial softSerial;
int status = WL_IDLE_STATUS; // Wifi ���� ����

void wifi_init(char * ssid, char * password)
{

	Serial.begin(9600);
	softSerial.begin(9600);

	// SoftwareSerial�� ESP ��� ���� �� �ʱ�ȭ
	WiFi.init(&softSerial);

	// ESP ��� ���� üũ
	if (WiFi.status() == WL_NO_SHIELD) {
		Serial.println("WiFi shield not present");
		while (true); // don't continue
	}

	while (status != WL_CONNECTED) {
		Serial.print("Attempting to connect to WPA SSID: ");
		Serial.println(ssid); // WPA/WPA2 ��Ʈ��ũ ����õ�
		status = WiFi.begin(ssid, password);
	}

	// ��Ʈ��ũ ���� ����
	Serial.println("You're connected to the network");
	// ��Ʈ��ũ ���� ��� �Լ� ȣ�� - �ڿ��� ����
	printWifiStatus();
}

void printWifiStatus()
{
	// ����� ��Ʈ��ũ�� SSID ���
	Serial.print("SSID: ");
	Serial.println(WiFi.SSID());
	
	// �Ҵ�� IP �ּ� ���
	IPAddress ip = WiFi.localIP();
	Serial.print("IP Address: ");
	Serial.println(ip);
	
	// ���ŵ� ��ȣ ���� ���
	long rssi = WiFi.RSSI();
	Serial.print("Signal strength (RSSI):");
	Serial.print(rssi);
	Serial.println(" dBm");
}
