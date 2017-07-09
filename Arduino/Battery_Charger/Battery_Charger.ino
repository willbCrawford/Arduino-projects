const float voltageDelay = 5000.0;
float lastCheckedVoltageTime = 0.0;

int reading = 0;
int relayPin = 7;
float voltage = 0.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((millis() > voltageDelay + lastCheckedVoltageTime) || lastCheckedVoltageTime == 0.0)
  {
    digitalWrite(relayPin, HIGH);
    delay(1000);
    float analogPin = analogRead(A0);
    
    voltage = 10 * (analogPin / 1024);
    
    digitalWrite(relayPin, LOW);

    Serial.print(voltage);
    Serial.println("V");

    lastCheckedVoltageTime = millis();
  }
}

