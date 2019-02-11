/*
 Name:		GPS.ino
 Created:	2019-01-22 오전 11:03:36
 Author:	student
*/

// the setup function runs once when you press reset or power the board

#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define RXPIN 2
#define TXPIN 3
#define GPSBAUD 9600

void getgps(TinyGPS &gps);

TinyGPS gps;
SoftwareSerial uart_gps(RXPIN, TXPIN);

void setup() {

	Serial.begin(9600);
	uart_gps.begin(GPSBAUD);
	Serial.println("");
	Serial.println("GPS Shield QuickStart Example Sketch v12");
	Serial.println(" ...waiting for lock... ");
	Serial.println("");

}

// the loop function runs over and over again until power down or reset
void loop() {
	while (uart_gps.available()) {
		int c = uart_gps.read();
		if (gps.encode(c)) {
			getgps(gps);
		}
	}
}

void getgps(TinyGPS &gps) {
	float latitude, longitude;
	gps.f_get_position(&latitude, &longitude);
	Serial.print("Lat/Long: ");
	Serial.print(latitude, 5); Serial.print(", ");
	Serial.println(longitude, 5);
	int year; byte month, day, hour, minute, second, hundredths;
	gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths);
	Serial.print("Date: ");
	Serial.print(month, DEC);
	Serial.print("/");
	Serial.print(day, DEC);
	Serial.print("/");
	Serial.print(year);

	Serial.print(" Time: ");
	Serial.print(hour, DEC);
	Serial.print(":");
	Serial.print(minute, DEC);
	Serial.print(":");
	Serial.print(second, DEC);
	Serial.print(".");
	Serial.println(hundredths, DEC);
	Serial.print("Altitude (meters): ");
	Serial.println(gps.f_altitude());
	Serial.print("Course (degrees): ");
	Serial.println(gps.f_course());
	Serial.print("Speed(kmph): ");
	Serial.println(gps.f_speed_kmph());
	Serial.println();
	
	delay(10000);
}
