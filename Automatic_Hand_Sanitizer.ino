
#include <Servo.h>
unsigned long previousMillis = 0;        

const long interval = 700;// wait for 700 millis to confirm detection          

unsigned long currentMillis;

int sensorPin = 12;// IR sensor Pin

Servo myservo;  // create servo object to control a servo

void setup() {
  pinMode(sensorPin,INPUT);// sets the sensor pin to INPUT
  myservo.attach(11);  // attaches the servo on pin 12 to the servo object
  myservo.write(180);  // take the servo to its normal position
}

void loop() {
    if(digitalRead(sensorPin)==0){ // Detect the hand
      
      currentMillis = millis(); // start timer
      
      if (currentMillis - previousMillis >= interval){ // if the hand is still there
        
        myservo.write(0); // move servo
        delay(1000);      // wait till it's moved
        myservo.write(180);// bring the servo back to its position
        
        while(digitalRead(sensorPin)==0);// wait till the hand has moved away
        
        delay(1000);            // wait 1 second to confirm
        
        previousMillis = currentMillis;// reset the timer
      }        
    }
    else{ // if no hand detected
      previousMillis = currentMillis; // keep reseting the timer
    }
}
