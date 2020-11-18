# Project #001: Measuring distance using UltraSonic Sensor

Measuring distance using HC-SR04 Ultrasonic sensor.

- [Parts](#parts)
- [Schema](#schema)
- [The circuit](#the-circuit)
- [Code](#code)

## Parts
Required parts for this project are:
- Microcontroller ESP32 Dev Module x1
- Breadboard x1
- HC-SR04 x1
- Wires x8

## The circuit:
  - HC-SR04 Gnd (Blue wire) connected to ground.
  - HC-SR04 Vcc (Red wire) connected to 5V.
  - HC-SR04 Trig (Green wire) connected to pin 2.
  - HC-SR04 Echo (Orange wire) connected to pin 5.

## Schema
![The Breadboard](./assets/Schema.png?raw=true)
![Connections](./assets/HC-SR04.jpg?raw=true)

## Code
```c

#define trigPin 2  // These lines assign names to values
#define echoPin 5  // so they can be easily identified.


/* This section of code below runs only one time.
 * It enables the serial monitor to see output and
 * sets the pins to input or output.
*/ 
void setup() {
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
}

/* The remaining part of the code runs in a constant loop.
 * It triggers the ultrasonic sensor and calculates the
 * time it took for the sound waves to return.  It converts
 * the time in milliseconds into distance in centimeters.
 */
void loop() { 
  
  long distance = getDistance();
  
  if (distance > 100 and distance < 150) { 
     Serial.println("Please keep distance of 1.5 Meters");
  }
  if (distance > 50 and distance < 100) { 
      Serial.println("Warning, you are too close");
  }
  if (distance > 0 and distance < 50) { 
      Serial.println("Dangerously close :(");
  }
  
  delay (500);
  
} 

long getDistance(){
    long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
    Serial.print(distance);
    Serial.println(" cm");
  return distance;
}

```