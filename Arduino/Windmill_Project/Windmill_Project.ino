#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

int displaySetting = 1;
const int MAX_DISPLAYS = 4;
const int buttonPin = 3;
unsigned long lastDisplaySwitch = millis();
const int DISPLAY_DELAY = 250;

float efficiency;

float Power_in;
float power_out;
float torque_out;
float Time;

const int interruptPin = 2;

int breakCount = 0;
unsigned long startTime = 0;
unsigned long endTime = 0;
float rpm = 0; 
int numberOfBlades = 4;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.display();
  //initializes lcd to start printing on 16x2 section of the lcd
  pinMode(buttonPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeDisplaySetting, FALLING);
  //makes the button pin as an input and as an interruptor to detect a FALLING change in voltage
  
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), broken, FALLING);
  //attaches interrupt pin as an input and as an interruptor to detect a FALLING change in voltage
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

  if(breakCount >= 30){
  endTime = millis();
  //tests if the break count is less than or equal to 30 and runs following code
  
  Time = endTime - startTime; //Making sure that the relative time between a set of breaks is used

  Time = Time / 60000; // converting milliseconds to minutes
  
  float revolutions; //declaring a float type variable

  revolutions = breakCount / numberOfBlades; //dividing number of breaks by 4 so that we get revolutions

  rpm = revolutions/Time ;
  
  float rpm_out;

  rpm_out = (rpm * 8);
  
  torque_out = ((rpm_out - 320) / 39.99);
  //uses equations in the handout to determine the torque of the DC motor
  
  float torque_in;
   
  torque_in = ((0.00057658/0.00032258) * (torque_out  * 0.0000980665));
  //uses ratio of radii of the gears and the above torque to find the torque produced by the windmill
  Power_in = ((rpm * torque_in)/ 9549) * 1000;
  //uses the relation to determine power of the windmill
  
  if(torque_out <= 48) 
  {
    efficiency = ((((-0.001618)*((torque_out) * (torque_out))) + (0.363542*(torque_out)) + 49.3765)); 
  } 
  else
  {
    efficiency = ((((-0.000434)*((torque_out) * (torque_out))) + (0.072269*(torque_out)) + 67.5668));
  }
  //uses the piece-wise function for efficiency to relate torque out and efficency
  
  power_out = (((rpm_out) * (efficiency/100)));
  //power of the DC motor to determine the torque of the windmill to the efficiency
  
  breakCount = 0;
  }
  
  displayLCD();
}

void displayLCD()
{
  switch(displaySetting)
  {
    case 1:
      lcd.clear();
      lcd.print(rpm);
      lcd.println(" rpm");
      break;
    case 2:
      lcd.clear();
      lcd.print(power_out);
      lcd.println(" W");
      break;
    case 3:
      lcd.clear();
      lcd.print(efficiency);
      lcd.println("%");
      break;
    case 4:
      lcd.clear();
      lcd.print(Time);
      lcd.println(" mins");
      break;
    default:
      lcd.clear();
      lcd.print("Unknown Setting");
  }
  //when the button is pushed it changes the display to the above variables
}

void changeDisplaySetting(){
  if(lastDisplaySwitch + DISPLAY_DELAY < millis()) {
    
    lastDisplaySwitch = millis();
    displaySetting++;
    
    if(displaySetting > MAX_DISPLAYS) {
      
      displaySetting = 1;
    }
    displayLCD();
  }
}

void broken(){
  if(breakCount == 0) {
    startTime = millis();
  }
  breakCount++;

  Serial.println(breakCount);
}

