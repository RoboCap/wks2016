
int iterator = 0;

void setup(){
  Serial.begin(9600); 
}

void loop(){
  iterator = iterator + 1;
  Serial.print("Iteration : "); //send the string “hello” and return the length of the string.
  Serial.println(iterator);
  delay(1000);  
}
