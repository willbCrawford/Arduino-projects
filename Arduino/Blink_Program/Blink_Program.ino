
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  delay(1000);
  digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(2, HIGH);    // turn the LED off by making the voltage LOW
 
  Serial.println("Blink");
}

