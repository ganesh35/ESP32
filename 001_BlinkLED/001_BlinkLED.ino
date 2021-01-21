/*
  Blinking LED
  
  Turns an LED on for one second, then off for one second, repeatedly.
  The circuit:
  - RED LED attached from pin 27 to ground.
  
  by more2Learn
*/
const int blinkLED = 27;    // assign digital pin 12 for the LED to blink
const int onTime=1000;      // duration of LED to stay ON in milli-seconds
const int offTime=1000;     // duration of LED to stay OFF in milli-seconds

// setup code goes here, to run once:
void setup() {
  pinMode(blinkLED , OUTPUT);
}


// the main code which runs repeatedly:
void loop() {
  digitalWrite(blinkLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(onTime);                       // wait for a second
  digitalWrite(blinkLED, LOW);    // turn the LED off by making the voltage LOW
  delay(offTime);                       // wait for a second
}
