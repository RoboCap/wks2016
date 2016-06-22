// whole content
String incomingContent = "";
// single character
char character;

void setup() {
	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        Serial.println("Please insert value");
}

void loop() {
    
	while (Serial.available()) {
		character = Serial.read();
		incomingContent.concat(character);
	}

	if (incomingContent != "") {
		Serial.println(incomingContent);
                incomingContent = "";
	}
}
