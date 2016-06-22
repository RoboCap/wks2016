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

	if (incomingContent != "" && incomingContent.length() == 2) {
		if (validateContent(incomingContent)) {
			Serial.println("Recieved valid percentage value");
		} else {
			Serial.println("Something went wrong");
		}
		incomingContent = "";
	}
}

boolean validateContent(String incomingContent) {
	Serial.print("Recieved content:");
	Serial.println(incomingContent);
	// always = 2
	int stringLength = incomingContent.length();

	boolean result = true;
	for (int i = 0; i < stringLength; i++) {
		char singleChar = incomingContent.charAt(i);
		result &= isDigit(singleChar);
		if (!result) {
			Serial.println("Recieved non digital character");
			return result;
		}
	}
	return result;
}

