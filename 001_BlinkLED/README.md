# Blinking an LED with ESP32

Turn on LED for one milli-second and turn of for anotehr one milli-second.

- [Tools and Materials](#tools-and-materials)
- [The circuit](#the-circuit)
- [The Breadboard](#the-breadboard)
- [Code](#code)
- [Conclusion](#conclusion)

## Tools and Materials
Required parts for this project are:
- Microcontroller ESP32 x1
- Breadboard x1
- LED x1
- Resistor 330Ω x1
- Wires x5

## The circuit:
  - RED LED attached from pin 27 to ground.
  ![The Breadboard](./assets/01_BlinkLED_schema.jpg?raw=true)
  
## The Breadboard
![The Breadboard](./assets/01_BlinkLED_Breadboard.PNG?raw=true)

## Code
```c
/*
  Blinking LED
  
  Turns an LED on for one second, then off for one second, repeatedly.
  The circuit:
  - RED LED attached from pin 27 to ground.
  
  by more2Learn
*/
const int blinkLED = 27;    // assign digital pin 27 for the LED to blink
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
```

## Conclusion
Defining constant (const) variable allows us to control the rest of the code without changing much to get different results. For example we change blinkLED variable to any other pin depending on the board (ESP32, Arduino UNO, ESP8266 ...).  Also one can try fiddling with onTime and offTime variable to see different results.
