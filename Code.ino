const int Temp_Pin =A0;
const int Fan_Pin = 6;
const int Heater_Pin =13;

#include <LiquidCrystal.h>

float Min_Temp =20, Max_Temp=25;

LiquidCrystal LCD (12,11,5,4,3,2);

void setup(){
  
  LCD.begin(16,2);
  pinMode(Heater_Pin ,OUTPUT);
  pinMode (Fan_Pin ,OUTPUT);
  pinMode (Temp_Pin ,INPUT);
  
  LCD.print("Room Temp(C) : ");
  LCD.setCursor(2,1);
  LCD.print(Min_Temp);
  LCD.print("-");
  LCD.print(Max_Temp);
  delay(2000);
  
}

void loop(){
 float Equ_volt = analogRead(Temp_Pin)*5.0/1023;
 float SensorTemp = 100.0*Equ_volt-50.0;
  
 LCD.clear();
 LCD.print("Sensor Reading: ");
 LCD.setCursor(2,1);
 LCD.print(SensorTemp); LCD.print(" C");
  
 delay(2000);
  
  
 if(SensorTemp > Max_Temp) {
   LCD.clear();
   LCD.print("Temp is HIGHER !");
   LCD.setCursor(0,1);
   LCD.print("Turn On Fan");
   for(int i=0; i<=255; i++){
       analogWrite(Fan_Pin ,i);
   }
   delay(2000);
   LCD.print(" NOW Temp is Ok !");
   LCD.setCursor(0,1);
   LCD.print("Turn OFF Fan");
   for(int i=255; i>=0; i--){
       analogWrite(Fan_Pin ,i);
   }  
   delay(2000);
             
  }
  else if(SensorTemp <Min_Temp){
      LCD.clear();
      LCD.print("Temp is Lower");
      LCD.setCursor(0,1);
      LCD.print(" Turn ON Heater");
              
      digitalWrite(Heater_Pin ,HIGH);
      delay(2000); 
                
      LCD.clear();
      LCD.print("Now Temp Is Ok!");
      LCD.setCursor(0,1);
      LCD.print(" Turn OFF Heater");
              
      digitalWrite(Heater_Pin ,LOW);
      delay(2000);
      LCD.clear();
      }
              
  else if(SensorTemp > Min_Temp && SensorTemp <Max_Temp){
      LCD.clear();
      LCD.print("Temp Is Normal!");
      LCD.setCursor(2,1);
      LCD.print(" Turn OFF All");
      delay(2000);
           }
            
  else {
      LCD.clear();
      LCD.print("Something is Wrong");
      LCD.setCursor(2,1);
      LCD.print(" Wrong in circuit");
      delay(2000);
      LCD.clear();
       }
      delay(2000);
}
     
     
