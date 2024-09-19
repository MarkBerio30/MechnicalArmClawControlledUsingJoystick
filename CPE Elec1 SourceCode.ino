#include <Servo.h> // add the servo libraries

      Servo myservo1; // create servo object to control a servo
      Servo myservo2;
      Servo myservo3;
      Servo myservo4;

int pos1=90, pos2=90, pos3=90, pos4=90; // define the variable of 4 servo angle,and assign the initial value (that is the boot posture
//angle value)
        const int right_X = A2; // define the right X pin to A2
        const int right_Y = A5; // define the right Y pin to A5
        const int right_key = 7; // define the right key pin to 7（that is the value of Z）
        const int left_X = A3; // define the left X pin to A3
        const int left_Y = A4; // define the left X pin to A4
        const int left_key = 8; //define the left key pin to 8（that is the value of Z）
        int x1,y1,z1; // define the variable, used to save the joystick value it read.
        int x2,y2,z2;

void setup()
{
    // boot posture
    myservo1.write(pos1);
    delay(1000);
    myservo2.write(pos2);
    myservo3.write(pos3);
    myservo4.write(pos4);
    delay(1500);
    pinMode(right_key, INPUT); // set the right/left key to INPUT
    pinMode(left_key, INPUT);
    Serial.begin(9600); // set the baud rate to 9600
}
void loop()
{
    myservo1.attach(3); // set the control pin of servo 1 to D3  dizuo-servo1-3
    myservo2.attach(5); // set the control pin of servo 2 to D5  arm-servo2-5
    myservo3.attach(6); //set the control pin of servo 3 to D6   lower arm-servo-6
    myservo4.attach(9); // set the control pin of servo 4 to D9  claw-servo-9
    x2 = analogRead(right_X); //read the right X value
    y2 = analogRead(right_Y); // read the right Y value
    z2 = digitalRead(right_key); //// read the right Z value
    x1 = analogRead(left_X); //read the left X value
    y1 = analogRead(left_Y); //read the left Y value
    z1 = digitalRead(left_key); // read the left Z value
    //delay(5); // lower the speed overall

    // claw
    claw();

    // rotate
    turn();

    // upper arm
    upper_arm();

    //lower arm
    lower_arm();
}



//***************************************************
//claw
void claw()
{
  //claw
  if(x1<50) // if push the left joystick to the right
  {
    pos4=pos4+3; 
    myservo4.write(pos4); //servo 4 operates the motion, the claw gradually opens. 
    delay(5);

  if(pos4>120) //limit the largest angle when open the claw 
  {
    pos4=120;
  }
  }

  if(x1>1000) ////if push the right joystick to the left 
  {
    pos4=pos4-3; 
    myservo4.write(pos4); // servo 4 operates the action, claw is gradually closed.
    delay(5);
  if(pos4<45) // 
  {
    pos4=45; //limit the largest angle when close the claw
  }

  } 
}



//******************************************************/
// turn
void turn()
{
      if(x2<50) //if push the right joystick to the let 
      {
            pos1=pos1+3; 
            myservo1.write(pos1); // arm turns left
            delay(5);
      if(pos1>180) //limit the angle when turn right 
      {
            pos1=180;
      }

      }

      if(x2>1000) // if push the right joystick to the right
      {
            pos1=pos1-3; 
            myservo1.write(pos1); //servo 1 operates the motion, the arm turns right. 
            delay(5);
      if(pos1<1) // limit the angle when turn left
      {
            pos1=1;
      }
      }
}




//**********************************************************/
// lower arm
void lower_arm()
{
      if(y2>1000) // if push the right joystick downward
      {
            pos2=pos2-2;
            myservo2.write(pos2); // lower arm will draw back
            delay(5);
      if(pos2<25) // limit the retracted angle
      {
            pos2=25;
      }
      }

      if(y2<50) // if push the right joystick upward
      {
            pos2=pos2+2;
            myservo2.write(pos2); // lower arm will stretch out
            delay(5);
      if(pos2>180) // limit the stretched angle
      {
            pos2=180;
      }
      }
}





//*************************************************************/

//upper arm
void upper_arm()
{
      if(y1<50) // if push the left joystick downward
      {
            pos3=pos3-2;
            myservo3.write(pos3); // upper arm will go down
            delay(5);
      if(pos3<1) //  limit the angle when go down 
      {
            pos3=1;
      }
      }
      if(y1>1000) // if push the left joystick upward
      {
            pos3=pos3+2;
            myservo3.write(pos3); // the upper arm will lift
            delay(5);

      if(pos3>135) //limit the lifting angle 
      {
            pos3=135;
      }
      }
}
