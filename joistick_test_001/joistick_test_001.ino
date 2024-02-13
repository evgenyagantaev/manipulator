#include <VarSpeedServo.h>


boolean catchIsClosed = true;
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

    myServo3.attach(3);
    myServo4.attach(4);
    myServo5.attach(5);
    myServo6.attach(6);
    myServo7.attach(7);

    // myServo3.slowmove(90,50);
    // delay(700);
    // myServo4.slowmove(40,30);
    // delay(700);
    // myServo5.slowmove(170,30);
    // delay(700);
    // myServo6.slowmove(170,30);
    // delay(700);
    // myServo7.slowmove(20,30);
    // catchIsClosed = true;
    // delay(3000);

    myServo3.slowmove(90,50);
    delay(700);
    myServo4.slowmove(90,30);
    delay(700);
    myServo5.slowmove(90,30);
    delay(700);
    myServo6.slowmove(90,30);
    delay(700);
    myServo7.slowmove(90,30);
    catchIsClosed = true;
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
        myServo3.slowmove(10,50);
        delay(1500);
        myServo7.slowmove(130,30);
        delay(500);

    } 
    else if (analogRead(A1) > 700) 
    {
        myServo3.slowmove(170,50);
        delay(1500);
        myServo7.attach(7);
        myServo7.slowmove(130,30);
        delay(500);
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