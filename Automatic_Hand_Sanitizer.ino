
#include <Servo.h>
        

const long interval = 700;// wait for 700 millis to confirm detection          

unsigned long currentMillis; // to store the value of current time in millis

unsigned long previousMillis = 0; // store the value of previous time

int sensorPin = 12;// IR sensor Pin

Servo myservo;  // create servo object to control a servo

void setup() {
  pinMode(sensorPin,INPUT);// sets the sensor pin to INPUT
  myservo.attach(11);  // attaches the servo on pin 11 to the servo object
  myservo.write(180);  // take the servo to its normal position
}

void loop() {
    if(digitalRead(sensorPin)==0){ // Detect the hand 
     // 0     ==      0 >> True
      currentMillis = millis(); // start timer
      //5000                0                700
      if (currentMillis - previousMillis >= interval){ // if the hand is still there >>false
        myservo.write(0); // move servo
        delay(1000);      // wait till it's moved
        myservo.write(180);// bring the servo back to its position
        
        while(digitalRead(sensorPin)==0);// wait till the hand has moved away
        delay(1000);            // wait 1 second to confirm    
        previousMillis = currentMillis;// reset the timer
      }        
    }
    else{ // if no hand detected
      previousMillis =millis(); // keep reseting the timer
    }
}
