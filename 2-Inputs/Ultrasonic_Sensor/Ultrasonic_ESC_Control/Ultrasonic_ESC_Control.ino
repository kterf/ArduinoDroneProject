// CONNEXIONS
// ULTRASONIC --> ARDUINO
// ECHO --> D4
// TRIG --> D5
// VCC --> 5V
// GND --> GND

/*
*  Valors
*  - Val = 4 comença a girar
*  - Val = 47 és el màxim (amb aspa), 180 sense
*  - Podem passar de 0 a 27 de cop
*  (Do whatever you want with it.)
*/

// Need the Servo library
#include <Servo.h>

// This is our motor.
Servo myMotor;
int increment = 2;
int val = 0;

int inputPin=4;  // define ultrasonic signal receiver pin  ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin TRIG to D5


// Set everything up
void setup()
{
  // Put the motor to Arduino pin #9
  myMotor.attach(10);
  // Required for I/O from Serial monitor
  Serial.begin(9600);
  // Print a startup message
  Serial.println("initializing");
  myMotor.write(0);
  
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  
  delay(500);
}


void loop(){
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  int distance = pulseIn(inputPin, HIGH);  // Read receiver pulse time
  distance= distance/58;   // Transform pulse time to distance
  
  val = distance / 2;
  // Convert the string to an integer
  
  if (val > -1 && val < 100)
    Serial.println(val);
    myMotor.write(val);

    delay(100);
}
