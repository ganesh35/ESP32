
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
