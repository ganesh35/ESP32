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
  robot.begin();
}

void loop() {
  robot.rotate(motor1, 100, CW);  
  delay(2000);
  robot.rotate(motor1, 100, CCW);  
  delay(3000);
}
