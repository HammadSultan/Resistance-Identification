#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int count=0;
int Vin = 5;
float Vout = 0;
float Rref=100;
float R1 = 0;
int Contrast=72;
int analogPin = 0;
int raw = 0;
float temp=0;

void setup(){
 analogWrite(6,Contrast);
     lcd.begin(16, 2);
}

void loop(){
 
  raw = analogRead(analogPin);
  if(raw){
lcd.setCursor(0, 0);
    lcd.print("Calculating");
    delay(1000);
    temp = raw * Vin;
    Vout = (temp)/1024.0;
    temp = (Vin/Vout) - 1;
    R1 = Rref * temp;
    lcd.clear();
  count=count+1;
if(R1>=20000){
  lcd.clear();

      lcd.setCursor(0, 2);
    lcd.print("Warning! extreme value");
}
 else
 {
   

    lcd.setCursor(0, 0);
    lcd.print("Vout: ");
    lcd.print(Vout);

    lcd.setCursor(0, 1);
    lcd.print("R1: ");
    lcd.print(R1);
    delay(1000);
    count=count-1;
 }
  }
}