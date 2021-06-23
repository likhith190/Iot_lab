#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup(){
pinMode(9, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
lcd.begin(16, 2);
}
float ip,temp,celsius;
void loop()
{
float moisture=analogRead(A1);
Serial.print(moisture);
ip=analogRead(A0);
temp=(ip*5)/1024;
celsius=(temp-0.5)*100;
lcd.setCursor(0,0);
lcd.print(celsius);
lcd.setCursor(6,0);
lcd.print(moisture);
if(celsius >=25 && moisture >= 500){
digitalWrite(9, LOW);
digitalWrite(7, HIGH);
digitalWrite(8,LOW);
lcd.setCursor(0, 1);
lcd.print("Motor On!");
}
else{
digitalWrite(9, HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
lcd.setCursor(0, 1);
lcd.print("Motor Off");;
}}
