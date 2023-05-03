
#define BLYNK_PRINT Serial
int in1=23,in2=22,in3=21,in4=19;
int f=0,b=0,l=0,r=0;

#define BLYNK_TEMPLATE_ID "TMPL3JpgTMYic"
#define BLYNK_TEMPLATE_NAME "Wifi Control Car"
#define BLYNK_AUTH_TOKEN "6-tzkivRbsKCvInFiLISQHKZmIIlR76m"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SPY";
char pass[] = "120hzpoco";

void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}



BLYNK_WRITE(V2) {
  f = param.asInt();
}
BLYNK_WRITE(V3) {
  b = param.asInt();
}
BLYNK_WRITE(V0) {
  l = param.asInt();
}
BLYNK_WRITE(V1) {
  r = param.asInt();
}
void loop(){
   Blynk.run();
   if(f==1){
    forward();
   }
   if(b==1){
     backward();
   } 
   if(l==1){
    left();
   }
   if(r==1){
    right();
   }
   if(r==0&&l==0&&f==0&&b==0){
    st();
    }
}



void forward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
}
void backward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH); 
}
void left(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
}
void right(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);   
}
void st(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
