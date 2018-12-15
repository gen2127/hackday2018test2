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
int primeCount = 0;
int ugoku = 0;
int valServo = 544;

int primeNumber[ ] = {2 , 3, 5, 7, 11,  13,  17,  19,
23, 29,  31,  37,  41,  43,  47,  53,  59};

void setup() {
  // put your setup code here, to run once:
  lcd.print("hatodokei");
  #if 1
    setTime(12, 00, 45, 19, 6, 2016);
  #else
    setTime(86400);
  #endif

  Serial.begin(1000000);
  servo.attach(2);
  servo.write(544);
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
  if(nowminute == primeNumber[primeCount]){
    ugoku = 1;
    primeCount+=1;
  }
  if(primeCount>17){
    primeCount=0;
  }
  if(ugoku==2){
    valServo -= 100;
    servo.write(valServo);
    if(valServo<544){
      ugoku = 0;
    }
  }
  if(ugoku==1){
    valServo += 100;
    servo.write(valServo);
    if(valServo>2300){
      ugoku = 2;
    }
  }
  Serial.print(nowminute);
  Serial.print(" ");
  Serial.println(nowsecond);
  delay(50);
}
