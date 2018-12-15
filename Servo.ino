#include <ServoTimer2.h>

ServoTimer2 servo;
int servo_no_kakudo = 540;
int servo_no_henkaryou = 10;

void setup() {
  servo.attach(2,544,2400);
}

void loop() {
  servo.write(servo_no_kakudo);
  servo_no_kakudo += servo_no_henkaryou;
  if(servo_no_kakudo>1800) servo_no_henkaryou *= -1;
  if(servo_no_kakudo<1000) servo_no_henkaryou *= -1;
  delay(10);
}
