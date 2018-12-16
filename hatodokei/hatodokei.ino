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
int valServo = 1000;
//int switch1 = 0;
int switchCount = 0;
int waitCount = 0;
double MS;

int primeNumber[ ] = {2 , 3, 5, 7, 11,  13,  17,  19,
23, 29,  31,  37,  41,  43,  47,  53,  59};

void setup() {
  // put your setup code here, to run once:
  pinMode(A5,INPUT);
  
  lcd.print("hatodokei");
  #if 1
    setTime(12, 40, 00, 19, 6, 2016);
  #else
    setTime(86400);
  #endif

  Serial.begin(1000000);
  servo.attach(2);
  servo.write(1000);
  delay(2000);
  lcd.clear();
  lcd.setCursor(6,1);
  lcd.print(":");
  
  Serial.print(primeCount);
  Serial.print(" ");
  Serial.println(primeNumber[primeCount]);
  while(primeNumber[primeCount]<minute()){
    primeCount += 1;
    Serial.print(primeCount);
    Serial.print(":");
    Serial.println(primeNumber[primeCount]);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  nowtime = hour();
  nowminute = minute();
  nowsecond = second();
  MS = analogRead(A5);
  
  if(MS<5){
    switchCount += 1;
  }else{
    switchCount = 0;
  }
  
  if(switchCount>5){
    ugoku=1;
  }
  
  if(nowsecond==0){
      lcd.setCursor(10,1);
      lcd.print(0);
      lcd.setCursor(11,1);
      lcd.print(0);
  }
  if(nowsecond > presecond){
    if(nowsecond<10){
      lcd.setCursor(10,1);
      lcd.print(0);
      lcd.setCursor(11,1);
      lcd.print(nowsecond);
    }else{
      lcd.setCursor(10,1);
      lcd.print(nowsecond);
    }
  }
  if(nowminute==0){
      lcd.setCursor(7,1);
      lcd.print(0);
      lcd.setCursor(8,1);
      lcd.print(0);
  }
  if(nowminute > preminute){
    if(nowminute<10){
      lcd.setCursor(7,1);
      lcd.print(0);
      lcd.setCursor(8,1);
      lcd.print(nowminute);
    }else{
      lcd.setCursor(7,1);
      lcd.print(nowminute);
    }
  }
  if(nowtime==0){
      lcd.setCursor(4,1);
      lcd.print(0);
      lcd.setCursor(5,1);
      lcd.print(0);
  }
  if(nowtime > pretime){
    if(nowtime<10){
      lcd.setCursor(4,1);
      lcd.print(0);
      lcd.setCursor(5,1);
      lcd.print(nowtime);
    }else{
      lcd.setCursor(4,1);
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
  if(ugoku==3){
    valServo -= 5;
    servo.write(valServo);
    if(valServo<=1000){
      ugoku = 0;
    }
  }
  if(ugoku==2){
    waitCount += 1;
    if(waitCount>500){
      ugoku = 3;
      waitCount=0;
    }
  }
  if(ugoku==1){
    valServo += 20;
    servo.write(valServo);
    if(valServo>2000){
      ugoku = 2;
    }
  }
  if(nowsecond==50){
    lcd.clear();
    LiquidCrystal lcd(10,9,8,7,6,5,4);
    lcd.setCursor(6,1);
    lcd.print(":");
    lcd.setCursor(10,1);
    lcd.print(nowsecond);

    if(nowminute<10){
      lcd.setCursor(7,1);
      lcd.print(0);
      lcd.setCursor(8,1);
      lcd.print(nowminute);
    }else{
      lcd.setCursor(7,1);
      lcd.print(nowminute);
    }

    if(nowtime<10){
      lcd.setCursor(4,1);
      lcd.print(0);
      lcd.setCursor(5,1);
      lcd.print(nowtime);
    }else{
      lcd.setCursor(4,1);
      lcd.print(nowtime);
    }
    
  }
  Serial.print(primeCount);
  Serial.print(" ");
  Serial.println(primeNumber[primeCount]);
  delay(10);
}
