String ArduinoInput;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    ArduinoInput = Serial.readString();

    if(ArduinoInput.equalsIgnoreCase("ON"))
    {
      Serial.println("Turning LED on....");
      digitalWrite(2, HIGH);
    }
    else if(ArduinoInput.equalsIgnoreCase("OFF"))
    {
      Serial.println("Turning LED off....");
      digitalWrite(2, LOW);
    }
    else
    {
      Serial.println("Unknown command");
    }
  }
}
