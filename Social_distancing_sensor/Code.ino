#include<Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip= Adafruit_NeoPixel(12,3,NEO_RGB+NEO_KHZ800);
long distance,duration;
void setup()
{
pinMode(2, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, INPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);strip.begin();
for(int i = 0; i < 12; i++)
{
strip.setPixelColor(i,strip.Color(0,0,0));
}
strip.show();
}
void loop()
{
digitalWrite(5, LOW);
delayMicroseconds(2);
digitalWrite(5, HIGH);
delayMicroseconds(10);
digitalWrite(5, LOW);
duration = pulseIn(6, HIGH);
distance=0.034*(duration/2);
Serial.println(distance);
int ledsToGlow = 0;
if(distance<300 & distance>280){
ledsToGlow=1;
}
else if(distance<280 & distance>260){
ledsToGlow=2;
}
else if(distance<260 & distance>240){
ledsToGlow=3;
}else if(distance<240 & distance>220){
ledsToGlow=4;
}else if(distance<220 & distance>200){
ledsToGlow=5;
}else if(distance<200 & distance>180){
ledsToGlow=6;
}else if(distance<180 & distance>160){
ledsToGlow=7;
}else if(distance<160 & distance>140){
ledsToGlow=8;
}
else if(distance<140 & distance>125){
ledsToGlow=9;
}
else if(distance<125 & distance>115){
ledsToGlow=10;}
else if(distance<115 & distance>100){
ledsToGlow=11;
}
else if(distance<100){
ledsToGlow=12;
}
if(ledsToGlow==12){
digitalWrite(2,HIGH);
}
else{
digitalWrite(2,LOW);
}
for(int i = 0; i < ledsToGlow; i++)
{
if(i < 4)
{
strip.setPixelColor(i,strip.Color(50,0,0));//green,red,blue
}
else if(i >= 4 && i < 8)
{
strip.setPixelColor(i,strip.Color(50,50,0));//green,red,blue
}
else if(i >= 8 && i < 12)
{
strip.setPixelColor(i,strip.Color(0,50,0));//green,red,blue
}
}
for(int i = ledsToGlow; i < 12; i++)
{
strip.setPixelColor(i,strip.Color(0,0,0));
}
strip.show();
delay(5​ 0);
}
