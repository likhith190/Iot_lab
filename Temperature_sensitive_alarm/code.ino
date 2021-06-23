void setup()
{
pinMode(A0,INPUT);
pinMode(11,OUTPUT);
pinMode(13, OUTPUT);
}
float ip,temp,celsius;
void loop()
{
ip=analogRead(A0);
temp=(ip*5)/1024;
celsius=(temp-0.5)*100;
Serial.println(celsius);
if(celsius >=25){
digitalWrite(11, HIGH);
}
else{
digitalWrite(11, LOW);}
}
