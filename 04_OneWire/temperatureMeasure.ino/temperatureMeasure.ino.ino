#include <OneWire.h>
#include <DS18B20.h>

// sensor Port
#define ONEWIRE_PIN 2

// Address read from previous program
byte address[8] = { 0x28, 0x65, 0xB3, 0x72, 0x2, 0x0, 0x0, 0xD7 };

// initialize onewireBus
OneWire onewire(ONEWIRE_PIN);
// initialize sensor
DS18B20 sensors(&onewire);

void setup() {
	while (!Serial)
		Serial.begin(9600);

	sensors.begin();
	sensors.request(address);
}

void loop() {
	if (sensors.available()) {
		float temperature = sensors.readTemperature(address);

		Serial.print(temperature);
		Serial.println(" 'C");

		sensors.request(address);
	}

}

