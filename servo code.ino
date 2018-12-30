/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo_main;  // create servo object to control a servo

Servo myservo_y;
    // variable to read the value from the analog pin

void setup() {
  myservo_main.attach(9);  // attaches the servo on pin 9 to the servo object

 myservo_y.attach(11);
}

void loop() {
 // val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
 // val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
 // myservo_main.write(31);                  // sets the servo position according to the scaled value
 // myservo_y.write(60);//mean positions
  
  myservo_main.write(45);  //3rd  quadrant                // sets the servo position according to the scaled value
myservo_y.write(80);
  delay(2000);                           // waits for the servo to get there

 

myservo_main.write(21);  //  2nd quardant              // sets the servo position according to the scaled value
myservo_y.write(51);
 delay(2000);

myservo_main.write(50);  //  4th quardant              // sets the servo position according to the scaled value
myservo_y.write(50);
 delay(2000);

  myservo_main.write(24);  //  1st quardant              // sets the servo position according to the scaled value
 myservo_y.write(76);
  delay(2000);
 
 myservo_main.write(31);  //mean  quadrant                // sets the servo position according to the scaled value
 myservo_y.write(60);
  delay(2000);

}
