#include <TimeLib.h>
#include <Servo.h>
#include <stdarg.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(10,9,8,7,6,5,4);

Servo servo;

int nowtime;
int nowminute;
int nowsecond;
int pretime;
int preminute;
int presecond;

void setup() {
  // put your setup code here, to run once:
  lcd.print("hatodokei");
  #if 1
    setTime(23, 59, 45, 19, 6, 2016);
  #else
    setTime(86400);
  #endif

  Serial.begin(1000000);
  servo.attach(2);
  delay(2000);
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print(":");
}

void loop() {
  // put your main code here, to run repeatedly:
  nowtime = hour();
  nowminute = minute();
  nowsecond = second();
  if(nowsecond==0){
      lcd.setCursor(6,1);
      lcd.print(0);
      lcd.setCursor(7,1);
      lcd.print(0);
  }
  if(nowsecond > presecond){
    if(nowsecond<10){
      lcd.setCursor(6,1);
      lcd.print(0);
      lcd.setCursor(7,1);
      lcd.print(nowsecond);
    }else{
      lcd.setCursor(6,1);
      lcd.print(nowsecond);
    }
  }
  if(nowminute==0){
      lcd.setCursor(3,1);
      lcd.print(0);
      lcd.setCursor(4,1);
      lcd.print(0);
  }
  if(nowminute > preminute){
    if(nowminute<10){
      lcd.setCursor(3,1);
      lcd.print(0);
      lcd.setCursor(4,1);
      lcd.print(nowminute);
    }else{
      lcd.setCursor(3,1);
      lcd.print(nowminute);
    }
  }
  if(nowtime==0){
      lcd.setCursor(0,1);
      lcd.print(0);
      lcd.setCursor(1,1);
      lcd.print(0);
  }
  if(nowtime > pretime){
    if(nowtime<10){
      lcd.setCursor(0,1);
      lcd.print(0);
      lcd.setCursor(1,1);
      lcd.print(nowtime);
    }else{
      lcd.setCursor(0,1);
      lcd.print(nowtime);
    }
  }
  pretime = nowtime;
  preminute = nowminute;
  presecond = nowsecond;
  Serial.print(nowminute);
  Serial.print(" ");
  Serial.println(nowsecond);
  
}
