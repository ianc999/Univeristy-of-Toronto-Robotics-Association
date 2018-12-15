#include "Timer.h"
Timer t;

int interval = 200;
int enL = 6;
int enR = 11;
int inL1 = 7;
int inL2 = 8;
int inR1 = 12;
int inR2 = 13;
int linesensor = 1;
int trig =2;
int echo = 3;

void setup() {
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(linesensor,INPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(inL1, OUTPUT);
  pinMode(inL2, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(inR2, OUTPUT);
  t.every(interval, digitalWrite);
}

void loop() {
  int number = digitalRead(linesensor);
  if (number == 0)//black
  {
  analogWrite(enL,255);
  digitalWrite(inL1,HIGH);
  digitalWrite(inL2,LOW);
  //analogWrite(enR,255);
  //digitalWrite(inR1,HIGH);
  //digitalWrite(inR2,LOW);
  delay(1000);
  }
  else
  {
  analogWrite(enL,255);
  digitalWrite(inL1,LOW);
  digitalWrite(inL2,HIGH);
  //analogWrite(enR,255);
  //digitalWrite(inR1,LOW);
  //digitalWrite(inR2,HIGH);
  delay(1000);
  }

  digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  int tim = pulseIn(echo,HIGH);
  int dis = (0.034/2)*tim;
  if (dis >= 5)
  {
  analogWrite(enR,255);
  digitalWrite(inR1,HIGH);
  digitalWrite(inR2,LOW);
 //delay(1000);
  }
  else
  {
  analogWrite(enR,255);
  digitalWrite(inR1,LOW);
  digitalWrite(inR2,HIGH);
  //delay(1000);  
  }
  
  {
  t.update();
  
  }
}

void digitalWrite(){
  inR1,LOW;
}
