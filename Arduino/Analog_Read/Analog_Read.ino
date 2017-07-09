const int inputPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int input = analogRead(inputPin);
  
  Serial.println(analogRead(inputPin));

  if(input > 500){
    digitalWrite(2, HIGH); 
  }
  else
  {
    digitalWrite(2, LOW);
  }
}
