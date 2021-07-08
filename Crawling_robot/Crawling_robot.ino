#include <Servo.h>
Servo servo1, servo2;  // Object of Servo Lib

float distance;     // Var to store Distance 
float sonarTime;    // Var to Store Sonar Time

//prototype of myServo Method
void myServo(Servo servo, int newAngle, int angleInc, int incDelay);

int TRIGGER = 7, ECHO = 8;  // sonar pins

int numberOfEpisodes = 0;       // Var to store the number needed learn the model with
int postion11 = 0;      // servo1 position
int postion21 = 0;      // servo2 position
int postion12 = 0;      // servo1 position
int postion22 = 0;        // servo2 position

// carries the reward of the robot when performs crawling
int postion11High = 0;    // servo1 highest position 
int postion21High = 0;    // servo2 highest position
int postion12High = 0;    // servo1 highest position
int postion22High = 0;    // servo2 highest position
int distanceHigh = 0;   // Var to store the higest distance travelled

// Vars to hold the distance values
float distDifference = 0, distPrevious = 0, distCurrent = 0;

void setup (){
  
  // init for all
  Serial.begin(9600);     // start the console
  servo1.attach(9, 600, 2400);  // set the servo to pin 9, with 600 min (0 - Degree) PWM, 2400 max PWM (180 - Degree)
  servo2.attach(6, 600, 2400);  // set the servo to pin 6, with 600 min PWM, 2400 max PWM 
  
  // set servos to zero position
  myServo(servo1, 0, 1, 8);     
  delay(1000);
  myServo(servo2, 0, 1, 8);
  delay(1000);
  
  // setup sonar
  pinMode(TRIGGER, OUTPUT); 
  pinMode(ECHO, INPUT);
 

  randomSeed(analogRead(0));  // get real random number seed
 
  distPrevious = getDistance(); // get initial distance
  Serial.println(distPrevious); // print distance on the monitor 
  delay(1000);
  
  } // end setup
  
void myServo(Servo servo, int newAngle, int angleInc, int incDelay) {
// routine to control the servo rotation speed
  
  int curAngle = 0;
  curAngle = servo.read();
 
// writing the servo new angle so that it increases by angleInc Var each time
  if (curAngle < newAngle) {
    for(int angle = curAngle; angle < newAngle; angle += angleInc) {
         servo.write(angle);  // apply the new angle to the servo
         delay(incDelay);   // delay to control the speed of the motor by waiting a moment before changing angle   
    }
   }
   else if (curAngle > newAngle) {
      for(int angle = curAngle; angle > newAngle; angle -= angleInc) {
          servo.write(angle); // apply the new angle to the servo
          delay(incDelay);      // delay to control the speed of the motor by waiting a moment before changing angle   
      }
   }
} // end of myServo function

float getDistance() {  
// routine to measure distance = call and average it 5 times
  int numberTriggers = 5;   
  int average = 0;
  for(int i = 0; i < numberTriggers; i++) {
     digitalWrite(TRIGGER, LOW);      // write 0 to the trigger of the Ultrasonic Sensor
     delayMicroseconds(5);          // wait 5 usec
     digitalWrite(TRIGGER, HIGH);     // write 1 to the trigger of the Ultrasonic Sensor
     delayMicroseconds(10);         // wait 10 usec
     digitalWrite(TRIGGER, LOW);      // write 0 to the trigger of the Ultrasonic Sensor
     sonarTime = pulseIn(ECHO, HIGH);   // determine the pulse time between sending wave and recieving it
     distance = sonarTime * 340 / 20000;  // calculating the distance so far based on the duration of the pulse (Speed = Distance / Time) (speed = 0.034 / 2)
     average = average + distance;      // adding to the total average distance
     delay(100);              // wait
  } // end for 
  
  average = average / numberTriggers;   // averaging for better accuracy
return average;

}// end get ultrasonic distance routine


void doTraining() {  
// routine to train the model (find the best postions that will achieve its task)
  Serial.println("Do doTraining...");
  numberOfEpisodes = 40;  
  for (int episode = 0; episode < numberOfEpisodes; episode++) {
    // for 40 episodes (for better learning curve)
    
            postion11 = random(150);        // random number between 0 - 150
            postion21 = random(150);        // random number between 0 - 150
        postion12 = random(150);        // random number between 0 - 150
            postion22 = random(150);        // random number between 0 - 150
    
            myServo(servo1, postion11, 1, 7); // moving the motor with the new postions 
            myServo(servo2, postion21, 1, 7); // moving the motor with the new postions
            myServo(servo1, postion12, 1, 7); // moving the motor with the new postions
            myServo(servo2, postion22, 1, 7); // moving the motor with the new postions
    
    // get distance - note this is not always accurate so sometimes robot will just claw the air
            
        distCurrent = getDistance(); 
            distDifference = distCurrent - distPrevious;
            distPrevious = distCurrent;
    
    // print the Current episode (Learning iteration)
            Serial.print(" episode = ");Serial.print(episode);
    // print the Current Postion of each motor for this episode (Learning iteration)
            Serial.print(" postion11 = ");Serial.print(postion11);
            Serial.print(" postion21 = ");Serial.print(postion21);
            Serial.print(" postion12 = ");Serial.print(postion12);
            Serial.print(" postion22 = ");Serial.print(postion22);
            Serial.print(" distance = ");Serial.println(distDifference);

             if (distCurrent > distanceHigh) { 
     // if current distancee is greater than highest then replace postions
               postion11High = postion11;         // assign new servo position 11
               postion21High = postion21;         // assign new servo position 21
               postion12High = postion12;         // assign new servo position 12
               postion22High = postion22;         // assign new servo position 22
               distanceHigh = distCurrent;        // assign the new highest distance
             } // end if
  }  // end each episode
} // end doTraining

void doLearnedBehavior() {
// routine to do the learned behavior (using the best postions that will achieve its task) 
     Serial.println("Do Learned behavior... ");
     Serial.print("Distance High = ");Serial.println(distanceHigh);

     myServo(servo1, 0, 1, 8);          // re-init the servo
     myServo(servo2, 0, 1, 8);          // re-init the servo
     delay(2000);                 // wait
  
// print the best Postion of each motor for crawling
     Serial.print(" postion11High = ");Serial.print(postion11High);
     Serial.print(" postion21High = ");Serial.print(postion21High);
     Serial.print(" postion12High = ");Serial.print(postion12High);
     Serial.print(" postion22High = ");Serial.print(postion22High);
  
     while(1) {      
  // using the best postion to crawl
       myServo(servo1, postion11High, 1, 7);       
       myServo(servo2, postion21High, 1, 7);
       myServo(servo1, postion12High, 1, 7);
       myServo(servo2, postion22High, 1, 7);
  } // doLearned  
} // end doLearnedBehavior

void loop(){  
  // main loop reads success table and performs actions
  // Later on will implement an Andriod app to interface with the robot
  
   doTraining();      // trial and error training with reinforcement Learning
   
   doLearnedBehavior(); // making the robot crawl
  
  
} // end main loop
