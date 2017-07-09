const int buttonInputPin = 3;
const int ledOutputPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonInputPin, INPUT);
  pinMode(ledOutputPin, OUTPUT);
  digitalWrite(ledOutputPin, LOW);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int input = digitalRead(buttonInputPin);
  digitalWrite(ledOutputPin, input);
}
