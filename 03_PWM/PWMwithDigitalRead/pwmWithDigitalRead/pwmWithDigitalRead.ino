// PWM properties
int pwmPort = 6;
int pwmValueLow = 100;
int pwmValueHigh = 255;

// whole content
String incomingContent = "";
// single character
char character;

void setup() {
// SetUp proper pinmode
	pinMode(pwmPort, OUTPUT);
// opens serial port, sets data rate to 9600 bps
	Serial.begin(9600);
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
			analogWrite(pwmPort, convertPercentageToPWM(incomingContent));
		} else {
			Serial.println("Something went wrong");
			analogWrite(pwmPort, pwmValueLow);
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

int convertPercentageToPWM(String incomingContent) {
	float percentage = incomingContent.toFloat();
	Serial.print("Percentage: ");
	Serial.println(percentage);
	float result = (percentage / 100) * pwmValueHigh;
	Serial.print("Writing to PWM: ");
	Serial.println((int) result);
	return (int) result;
}

