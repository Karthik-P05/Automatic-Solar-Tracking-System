#include <Servo.h> //includes the servo library
Servo myservo1,myservo2;
#define ldr1 A0 //set ldr 1 Analog input pin of East ldr as an integer
#define ldr2 A1 //set ldr 2 Analog input pin of West ldr as an integer
int pos1 = 90; // initial position of the Horizontal movement controlling servo motor1
int pos2 = 90; // initial position of the Horizontal movement controlling servo motor2
int tolerance = 10; // allowable tolerance setting - so solar servo motor isn't constantly in motion


void setup ()
{
    myservo1.attach(2); // attaches the servo1 on digital pin 2 to the horizontal movement
    myservo2.attach(3); //attaches the servo2 on digital pin 3 to the horizontal movement
    pinMode (ldr1, INPUT); //set East ldr pin as an input
    pinMode (ldr2, INPUT); //set West ldr pin as an input
    myservo1.write(pos1); // write the starting position of the horizontal movement servo motor1
    myservo2.write(pos2); // write the starting position of the horizontal movement servo motor2
    delay (1000); // 1 second delay to allow the solar panel to move to its staring position before comencing solar tracking
}
void loop ()
{
    int val1 = analogRead(ldr1); // read the value of ldr 1
    int val2 = analogRead(ldr2); // read the value of ldr 2
    if ((abs (val1 - val2) <= tolerance) || (abs (val2 - val1) <= tolerance))
    {
        //no servo motor horizontal movement will take place if the ldr value is within the allowable tolerance
    }
    else
    {
        if (val1 > val2) // if ldr1 senses more light than ldr2
        {
            pos1 = pos1+1; // increment the 90 degree poistion of the horizontal servo motor1
            pos2 = pos2-1; // decrement the 90 degree poistion of the horizontal servo motor2
        }
        if (val1 < val2) // if ldr2 senses more light than ldr1
        {   
            pos1 = pos1-1; //decrement the 90 degree poistion of the horizontal servo motor1
            pos2 = pos2+1; //increment the 90 degree poistion of the horizontal servo motor2
        }
    }
    if (pos1 > 180 && pos2 < 0)
    {
        pos1 = 180;
        pos2 = 0;
    } // reset the horizontal postion of the motor1 to 180 and motor2 to 0 if it tries to move past these point
    if (pos1 < 0 && pos2 > 180)
    {
        pos1 = 0;
        pos2 = 180;
    } // reset the horizontal postion of the motor1 to 180 and motor2 to 0 if it tries to move past these point
    myservo1.write(pos1); //write the starting position to the horizontal motor1
    myservo2.write(pos2); //write the starting position to the horizontal motor2
    delay (500);
}