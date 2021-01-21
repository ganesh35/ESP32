# Blinking three LEDs with ESP32

Working with multiple LEDs to create a sequence of turning ON and OFF of each LED with a delay of one milli-second.

- [Tools and Materials](#tools-and-materials)
- [The circuit](#the-circuit)
- [Schema](#schema)
- [Code](#code)
- [Conclusion](#conclusion)

## Tools and Materials
Required parts for this project are:
- Microcontroller ESP32 x1
- Breadboard x1
- LED x3  (Red, Green, Yellow)
- Resistor 330Ω x3
- Wires x10 (approximately)

## The circuit:
  - Red LED attached from pin 12 to ground.
  - Yellow LED attached from pin 14 to ground.
  - Green LED attached from pin 27 to ground.

  ![The Breadboard](./assets/Schema.png?raw=true)
## The Breadboard
![The Breadboard](./assets/Breadboard.png?raw=true)

## Code
```c
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
```

## Conclusion
Changing delayTime and ordering of LEDs in the loop will generate different results. Fiddling with delayTime with random numbers will produce disco lights effect.
