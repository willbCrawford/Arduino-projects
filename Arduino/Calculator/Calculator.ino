void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  Serial.println("Welcome to the calculator! Please input the two numbers you would like to compute followed by the operator");
  while(!Serial.available()){
    
  }
  int a = Serial.parseInt();
  Serial.println(a);
  while(!Serial.available()){
    
  }
  String operate = Serial.readString();
  Serial.println(operate);
  while(!Serial.available()){
    
  }
  int b = Serial.parseInt();
  Serial.println(b);
  
  int c;
  int d;
  int e;
  int f;
  
   if(operate.equalsIgnoreCase("+")){
      
     c = a + b;

     Serial.println(c);
   }
   else if(operate.equalsIgnoreCase( "-")){
      
      d = a - b;

      Serial.println(d);
   }
   else if(operate.equalsIgnoreCase("*")) {
      
      e = a * b;

      Serial.println(e);
    }
    else if(operate.equalsIgnoreCase("/")){
      
      f = a / b;

      Serial.println(f);
  }
}
