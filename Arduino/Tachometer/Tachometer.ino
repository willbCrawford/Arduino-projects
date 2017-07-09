const int interruptPin = 2;

int breakCount = 0;
unsigned long startTime = 0;
unsigned long endTime = 0;
float rpm = 0;
int numberOfBlades = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(interruptPin), broken, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(breakCount >= 30){
  endTime = millis();

  float Time;

  Time = endTime - startTime; //Making sure that the relative time between a set of breaks is used

  Time = Time / 60000; // converting milliseconds to minutes
  
  float revolutions; //declaring a float type variable

  revolutions = breakCount /   numberOfBlades; //dividing number of breaks by 4 so that we get revolutions

  rpm = revolutions/Time ;

  Serial.print(rpm);
  Serial.println(" revolutions per minute");

  breakCount = 0; 
 }
}

void broken() {
  if (breakCount == 0){
    startTime = millis();
  }

  breakCount++;
  Serial.println(breakCount);
}

