/*
  Blinking LEDs
  
  Turns ON and OFF of 3 LEDs consequently with a delay of one second.
  The circuit:
  - Red LED attached from pin 12 to ground.
  - Yellow LED attached from pin 14 to ground.
  - Green LED attached from pin 27 to ground.
  
  by more2Learn
*/
const int redLED = 12;        // assign digital pin 12 for the redLED to blink
const int yellowLED = 14;     // assign digital pin 14 for the yellowLED to blink
const int greenLED = 27;      // assign digital pin 27 for the greenLED to blink
const int delayTime=1000;     // duration of delay in milli-seconds


// setup code goes here, to run once:
void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}


// the main code which runs repeatedly:
void loop() {
  digitalWrite(redLED, HIGH);             // turn the redLED on
  delay(delayTime);                       // wait for a second
  
  digitalWrite(redLED, LOW);              // turn the redLED off and turn yellowLED on
  digitalWrite(yellowLED, HIGH);
  delay(delayTime); 
  
  digitalWrite(yellowLED, LOW);           // turn the yellowLED off and turn greenLED on
  digitalWrite(greenLED, HIGH);
  delay(delayTime); 
  
  digitalWrite(greenLED, LOW);            // turn the greenLED off
}
