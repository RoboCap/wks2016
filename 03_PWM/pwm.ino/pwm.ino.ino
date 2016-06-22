int pwmPort = 6;
int pwmValueLow = 100;
int pwmValueHigh = 255;
void setup() {
	// SetUp proper pinmode
	pinMode(pwmPort, OUTPUT);

}

void loop() {
	// write proper value to PWM output
	analogWrite(pwmPort, pwmValueLow);
	//Delay
	delay(3000);

	// write proper value to PWM output
	analogWrite(pwmPort, pwmValueHigh);
	//Delay
	delay(3000);
}

