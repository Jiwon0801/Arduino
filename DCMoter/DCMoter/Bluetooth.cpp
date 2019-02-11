// 
// 
// 

#include "Bluetooth.h"
#include <Arduino.h>

Bluetooth::Bluetooth(int rx, int tx, long boardrate) : SoftwareSerial(rx,tx)
{
	begin(boardrate);
}

String Bluetooth::readLine()
{
	String message = "";
	while (available()) {
		char data = (char)read();

		if (data == '\r') break;

		message += data;
		delay(5); // ¼ö½Å ¹®ÀÚ¿­ ²÷±è ¹æÁö
	}
	return message;
}
