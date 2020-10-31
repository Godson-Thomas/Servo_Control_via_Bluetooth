#include <Wire.h>
#include<SoftwareSerial.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
SoftwareSerial mySerial(0,1);  //RX,TX
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}


void loop() {
  char x;

if(Serial.available()>0){
   x=mySerial.read();

    if(x=='F') //data sent from the  controller app  on your android phone
    {
      Serial.print("FO");
        
  //FORWARD
for( int angle =1; angle != 0; angle +=10){
      delay(50);
        pwm.setPWM(4, 0, angleToPulse(angle) );
        pwm.setPWM(6, 0, angleToPulse(angle) );
        pwm.setPWM(8, 0, angleToPulse(angle) );
        pwm.setPWM(10, 0, angleToPulse(angle) );
       
       
    }
  
    }
 
if(x=='B') //data sent from the  controller app  on your android phone
  {  

    Serial.print("BA");
    
  //BACKWARD
  for( int angle =360; angle != 0; angle -=10){
      delay(50);
        pwm.setPWM(4, 0, angleToPulse(angle) );
        pwm.setPWM(6, 0, angleToPulse(angle) );
        pwm.setPWM(8, 0, angleToPulse(angle) );
        pwm.setPWM(10, 0, angleToPulse(angle) );
       
    }

  }
  
if(x=='R') //data sent from the  controller app  on your android phone
  {
    
  Serial.print("RI");
  //RIGHT
 
 for( int angle =1; angle != 0; angle +=10){
      delay(50);
        pwm.setPWM(4, 0, angleToPulse(angle) );
        pwm.setPWM(6, 0, angleToPulse(angle) );
        
       
       
    }

  }
  
 if(x=='L') //data sent from the  controller app  on your android phone
  {

  Serial.print("LE");
  //LEFT
  
  for( int angle =1; angle != 0; angle +=10){
      delay(50);
       
        pwm.setPWM(8, 0, angleToPulse(angle) );
        pwm.setPWM(10, 0, angleToPulse(angle) );
   
    }
  
  
}

if(x=='S'){ //data sent from the  controller app  on your android phone

      delay(50);
        pwm.setPWM(4, 0, angleToPulse(0));
        pwm.setPWM(6, 0, angleToPulse(0));
        pwm.setPWM(8, 0, angleToPulse(0));
        pwm.setPWM(10, 0, angleToPulse(0));
}

}
}

 
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
