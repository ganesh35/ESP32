#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define CHA 0
#define ENA 32 // this pin must be PWM enabled pin if Arduino board is used
#define IN1 33
#define IN2 25
const int CCW = 2; // do not change
const int CW  = 1; // do not change
#define motor1 1 // do not change
Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA);

void setup() {
  Serial.begin(115200);
  robot.begin();
}

void loop() {
  for(int i=70; i<100; i++){
    robot.rotate(motor1, i, CW);  
    Serial.print("Speed: ");
    Serial.println(i);
    delay(300);
  }
  delay(2000);
  for(int i=70; i<100; i++){
    robot.rotate(motor1, i, CCW);  
    Serial.print("Speed: ");
    Serial.println(i);
    delay(300);
  }
  
  delay(3000);
}