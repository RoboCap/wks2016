#include <OneWire.h>

// sensor Port
const byte ONEWIRE_PIN = 2;

OneWire onewire( ONEWIRE_PIN);

void setup() {
	while (!Serial)
		;
	Serial.begin(9600);
}

void loop() {
	byte address[8];

	onewire.reset_search();
	while (onewire.search(address)) {
		if (address[0] != 0x28)
			continue;

// something went wrong
		if (OneWire::crc8(address, 7) != address[7]) {
			Serial.println("Wrong address");
			break;
		}
// print address starting with Ox
		for (byte i = 0; i < 8; i++) {
			Serial.print(F("0x"));
			Serial.print(address[i], HEX);

			if (i < 7)
				Serial.print(", ");
		}
		Serial.println();
	}

	while (1) {
// "ugly" loop which avoids reading sensors all over again
	}
}

