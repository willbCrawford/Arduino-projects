void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
  String userInput = Serial.readString();

  if(userInput.equalsIgnoreCase("ON"))
  {
    digitalWrite(7, HIGH);
    Serial.println("Turning on...");
  }
  else if(userInput.equalsIgnoreCase("OFF"))
  {
    digitalWrite(7, LOW);
    Serial.println("Turning off...");
    //If-else statement allows for user to turn on or off the motor connected to MOSFET
  }
  }

  int voltageDrop = analogRead(A5); 
  //reads voltage across A5
  if(voltageDrop > 0) 
  //sets a loop to calculate the power read so long as the voltage read is above 0;
  {
    double Vr, I, P;
    double Vtotal = 2.45;
    Vr = (double)voltageDrop; 
    //casts Vr as a double 
    Vr = Vr * Vtotal / 1024;
    //converts voltage to AMPS
    I = Vr / 1;
    //uses Ohm's Law
    P = (Vtotal - Vr) * I;
    //calculates power
    
    Serial.print(P);
    Serial.println("W");
    //prints power and then 'W'
  }
}
