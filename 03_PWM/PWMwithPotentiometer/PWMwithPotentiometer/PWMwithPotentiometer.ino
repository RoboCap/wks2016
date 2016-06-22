int inputPin = A0;  // set input pin for the potentiometer
int inputValue = 0; // potentiometer input variable
int ledPin = 6;     // set output pin for the LED

void setup() {
	// declare the ledPin as an OUTPUT:
	pinMode(ledPin, OUTPUT);
	// opens serial port, sets data rate to 9600 bps
	Serial.begin(9600);
}

void loop() {
	// read the value from the potentiometer:
	inputValue = analogRead(inputPin);
	Serial.print("Potentiometer value: ");
	Serial.println(inputValue);
	// send the square wave signal to the LED:
	analogWrite(ledPin, inputValue / 4);
        delay(500);
}
