#include <VarSpeedServo.h>


boolean catchIsClosed = true;
int horizontalAngle;
boolean catchControl = false;

VarSpeedServo myServo3;
VarSpeedServo myServo4;
VarSpeedServo myServo5;
VarSpeedServo myServo6;
VarSpeedServo myServo7;

void setup() 
{
    Serial.begin(9600);
    Serial.println("Hello SETUP...");
    pinMode(8, INPUT_PULLUP);

    delay(3000);
    myServo3.attach(3);
    delay(700);
    myServo4.attach(4);
    delay(700);
    myServo5.attach(5);
    delay(700);
    myServo6.attach(6);
    delay(700);
    myServo7.attach(7);
    delay(3000);

    horizontalAngle = 90;
    myServo3.slowmove(horizontalAngle,30);
    delay(700);
    myServo4.slowmove(90,30);
    delay(700);
    myServo5.slowmove(90,30);
    delay(700);
    myServo6.slowmove(90,30);
    delay(700);
    myServo7.slowmove(90,30);
    delay(700);
    myServo7.slowmove(20,30);
    catchIsClosed = true;
    delay(3000);

    myServo4.slowmove(40,30);
    delay(700);
    myServo5.slowmove(170,30);
    delay(700);
    myServo6.slowmove(170,30);
    delay(700);
    delay(3000);
}

void loop() 
{
    Serial.print(analogRead(A0));
    Serial.print(" ");
    Serial.println(analogRead(A1));

    if (analogRead(A0) < 100) 
    {
        myServo4.slowmove(90,20);
        delay(500);
        myServo5.slowmove(110,20);
        delay(500);
        myServo6.slowmove(130,20);
        delay(500);
    } 
    else if (analogRead(A0) > 700) 
    {
        myServo4.slowmove(70,20);
        delay(500);
        myServo5.slowmove(170,20);
        delay(500);
        myServo6.slowmove(170,20);
        delay(500);
        myServo7.slowmove(20,30);
        delay(500);

    } 
    else if (analogRead(A1) < 100) 
    {
        horizontalAngle = horizontalAngle - 1;
        if(horizontalAngle < 10)
        {
            horizontalAngle = 10;
        }
        myServo3.slowmove(horizontalAngle,50);
        delay(10);
    } 
    else if (analogRead(A1) > 700) 
    {
        horizontalAngle = horizontalAngle + 1;
        if(horizontalAngle > 170)
        {
            horizontalAngle = 170;
        }
        myServo3.slowmove(horizontalAngle,50);
        delay(10);
    }

    if (digitalRead(8) == 0) 
    {
        if (catchIsClosed) 
        {
            myServo7.slowmove(130,30);
            delay(2000);
            catchIsClosed = false;
        }
        else
        {
            myServo7.slowmove(20,30);
            delay(2000);
            catchIsClosed = true;
        }
    }
}