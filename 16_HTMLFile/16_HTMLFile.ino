#include <WiFi.h>
#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define CHA 0
#define ENA 32 // this pin must be PWM enabled pin if Arduino board is used
#define IN1 33
#define IN2 25

// motor 2 settings
#define IN3 26
#define IN4 27
#define ENB 14// this pin must be PWM enabled pin if Arduino board is used
#define CHB 1


const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change

const int startSpeed  = 90; // do not change

// for two motors without debug information // Watch video instruciton for this line: https://youtu.be/2JTMqURJTwg
Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA,  IN3, IN4, ENB, CHB);

int ledPin = 12;
int isLedPinActive = 0;

const char* ssid     = "SuchiHome";
const char* password = "Suchi1027!";
String index_html PROGMEM={"<!doctype html>\n<html lang=\"en\">\n\t<head>\n\t\t<base href=\"/\">\n\t\t<meta charset=\"utf-8\">\n\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n\t\t<title>Web Control Panel</title>\n\t\t<!-- Bootstrap core CSS -->\n\t\t<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\">\n\t\t<meta name=\"theme-color\" content=\"#563d7c\">\n\t\t<style>\n\t\t\t.bd-placeholder-img {\n\t\t\tfont-size: 1.125rem;\n\t\t\ttext-anchor: middle;\n\t\t\t-webkit-user-select: none;\n\t\t\t-moz-user-select: none;\n\t\t\t-ms-user-select: none;\n\t\t\tuser-select: none;\n\t\t\t}\n\t\t\t@media (min-width: 768px) {\n\t\t\t.bd-placeholder-img-lg {\n\t\t\tfont-size: 3.5rem;\n\t\t\t}\n\t\t\t}\n\t\t</style>\n\t\t<!-- Custom styles for this template -->\n\t\t<link href=\"https://getbootstrap.com/docs/4.5/examples/floating-labels/floating-labels.css\" rel=\"stylesheet\">\n\t\t<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.1/css/all.min.css\" integrity=\"sha512-+4zCK9k+qNFUR5X+cKL9EIR+ZOhtIloNl9GIKS57V1MyNsYpYcUrUeQc9vNfzsWfV28IaLL3i96P9sdNyeRssA==\" crossorigin=\"anonymous\" />\n\t</head>\n\t<body>\n\t\t<form class=\"form-signin\" style=\"max-width: 750px;\">\n\t\t\t<div class=\"text-center mb-4\">\n\t\t\t\t<h1 class=\"h3 mb-3 font-weight-normal\">Web Joystick</h1>\n\t\t\t</div>\n\t\t\t<div class=\"card\">\n\t\t\t\t<div class=\"card-body\">\n\t\t\t\t\t<div class=\"row\">\n\t\t\t\t\t\t<div class=\"col-md-5\">\n\t\t\t\t\t\t\t<div class=\"card\">\n\t\t\t\t\t\t\t\t<div class=\"card-body\">\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-2\">\n\t\t\t\t\t\t\t\t\t\t<button class=\"btn btn-sm btn-outline-secondary\" disabled><i class=\"far fa-question-circle\" style=\"font-size: 2em;\"></i></button>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-2\">\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/LEFT\"><i class=\"fas fa-arrow-left\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t\t&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/RIGHT\"><i class=\"fas fa-arrow-right\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-2\">\n\t\t\t\t\t\t\t\t\t\t<button class=\"btn btn-sm btn-outline-secondary\" disabled><i class=\"far fa-question-circle\" style=\"font-size: 2em;\"></i></button>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t\t<div class=\"col-md-2\">\n\t\t\t\t\t\t\t<div class=\"card\">\n\t\t\t\t\t\t\t\t<div class=\"card-body\">\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-3\">\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/HOME\"><i class=\"fas fa-home\" style=\"font-size: 1.5em;\"></i></a>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-3\">\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/HORN\"><i class=\"fas fa-bullhorn\" style=\"font-size: 1.5em;\"></i></a>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-2\">\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/LIGHTS\"><i class=\"far fa-lightbulb\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t\t<div class=\"col-md-5\">\n\t\t\t\t\t\t\t<div class=\"card\">\n\t\t\t\t\t\t\t\t<div class=\"card-body\">\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-2\">\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/FORWARD\"><i class=\"fas fa-arrow-up\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-2\">\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/AUTO\"><i class=\"fab fa-autoprefixer\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t\t&nbsp;&nbsp;&nbsp;\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/STOP\"><i class=\"far fa-stop-circle\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t\t&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/DEMO\"><i class=\"fas fa-play\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t\t<div class=\"text-center mb-2\">\n\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-sm btn-outline-info\" href=\"/BACKWARD\"><i class=\"fas fa-arrow-down\" style=\"font-size: 2em;\"></i></a>\n\t\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t\t</div>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div>\n\t\t\t\t</div>\n\t\t\t</div>\n\t\t\t<p class=\"mt-5 mb-3 text-muted text-center\">&copy; 2020-2021</p>\n\t\t</form>\n\t</body>\n</html>"};
String btnPressed = "";
String btnPressedActive = "";

WiFiServer server(80);


int motorSpeed = startSpeed;
String travelDirection = "";    // FORWARD / BACKWARD
String steerDirection = "";     // LEFT / RIGHT


#define trigPin 2  // These lines assign names to values
#define echoPin 5  // so they can be easily identified.


void loop(){
  btnPressed= wifiCheck();
    

  if (btnPressed.equals("FORWARD")) {
    travelDirection = "FORWARD"; 
    robot.brake(1);
  }
  if (btnPressed.equals("BACKWARD")) {
    travelDirection = "BACKWARD"; 
    robot.brake(1);
  }
  if (btnPressed.equals("LEFT")) {
    steerDirection = "LEFT"; 
  }
  if (btnPressed.equals("RIGHT")) {
    steerDirection = "RIGHT"; 
  }
  if (btnPressed.equals("LIGHTS")) {
    if(isLedPinActive == 0){
      isLedPinActive=1;
      digitalWrite(ledPin, HIGH);
    }else{
      isLedPinActive=0;
      digitalWrite(ledPin, LOW);
    }
  }

    long distance = getDistance();
    if (distance > 30 && distance < 62) { 
      Serial.println("distance lessthan 62cm");
      driveRight();
    }
    if (distance > 0 && distance < 31) { 
      Serial.println("distance lessthan 31cm");
      btnPressed = "STOP";
    }

  if (btnPressed.equals("STOP")) {
    travelDirection = "";
    steerDirection = "";
    motorSpeed = startSpeed;
    robot.brake(1);
    robot.brake(2);
  }
  

  if(btnPressed != ""){
    Serial.print("btnPressed: ");
    Serial.println(btnPressed);  
  }

  if(travelDirection != ""){
    Serial.print("travelDirection : ");
    Serial.println(travelDirection );  
  }
  if(steerDirection != ""){
    Serial.print("steerDirection : ");
    Serial.println(steerDirection );  
  }
  if(motorSpeed > startSpeed && motorSpeed <100){
    Serial.print("motorSpeed: ");
    Serial.println(motorSpeed);  
  }



  
  if(travelDirection.equals("FORWARD")){
    robot.rotate(motor1, motorSpeed, CW);
    robot.rotate(motor2, motorSpeed, CW);
    if(motorSpeed < 100) motorSpeed++;
    
  }
  if(travelDirection.equals("BACKWARD")){
    robot.rotate(motor1, motorSpeed, CCW);
    robot.rotate(motor2, motorSpeed, CCW);
    if(motorSpeed < 100) motorSpeed++;
  }
  if(steerDirection.equals("LEFT")){
    robot.rotate(motor1, 100, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
    steerDirection="";
    robot.brake(2);
  }  
  if(steerDirection.equals("RIGHT")){
    robot.rotate(motor1, 100, CCW);// turn motor1 with i% speed in CW direction (whatever is i) 
    steerDirection="";
    robot.brake(2);
  }  
  delay(100);
}

void driveRight(){
  Serial.println("driveRight");
  robot.brake(1);
  robot.brake(2);
  robot.rotate(motor1, 100, CW);
  robot.rotate(motor2, 100, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
  delay(200);
  robot.brake(1);
  
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

String wifiCheck(){
  String btnPressed = "";
  WiFiClient client = server.available();   // listen for incoming clients
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming da
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        //Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print(index_html);
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }else{  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine          
        }
        if (currentLine.endsWith("GET /FORWARD")) { btnPressed="FORWARD"; }
        if (currentLine.endsWith("GET /BACKWARD")) { btnPressed="BACKWARD"; }
        if (currentLine.endsWith("GET /LEFT")) { btnPressed="LEFT"; }
        if (currentLine.endsWith("GET /RIGHT")) { btnPressed="RIGHT"; }
        if (currentLine.endsWith("GET /HOME")) { btnPressed="HOME"; }
        if (currentLine.endsWith("GET /LIGHTS")) { btnPressed="LIGHTS"; }
        if (currentLine.endsWith("GET /HORN")) { btnPressed="HORN"; }
        if (currentLine.endsWith("GET /STOP")) { btnPressed="STOP"; }
        if (currentLine.endsWith("GET /AUTO")) { btnPressed="AUTO"; }
        if (currentLine.endsWith("GET /DEMO")) { btnPressed="DEMO"; }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
  
  return btnPressed;
}
void setup()
{
    Serial.begin(115200);
    pinMode(2, OUTPUT);      // set the LED pin mode
    delay(10);

    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

    robot.begin();
    pinMode(ledPin, OUTPUT);    
    
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);  
}
