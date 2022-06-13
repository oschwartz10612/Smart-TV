#include <arduino.h>

int IRledPin = 13; // LED connected to digital pin 13
int input = 2;
int state;
boolean onOff = false; // true = on

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs)
{
    // we'll count down from the number of microseconds we are told to wait

    cli(); // this turns off any background interrupts

    while (microsecs > 0)
    {
        // 38 kHz is about 13 microseconds high and 13 microseconds low
        digitalWrite(IRledPin, HIGH); // this takes about 3 microseconds to happen
        delayMicroseconds(10);        // hang out for 10 microseconds
        digitalWrite(IRledPin, LOW);  // this also takes about 3 microseconds
        delayMicroseconds(10);        // hang out for 10 microseconds

        // so 26 microseconds altogether
        microsecs -= 26;
    }

    sei(); // this turns them back on
}

void sendSoundUp()
{
    delayMicroseconds(4696);
    pulseIR(4560);
    delayMicroseconds(4680);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(500);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(620);
    pulseIR(520);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(620);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(1820);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(620);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(620);
    pulseIR(520);
    delayMicroseconds(620);
    pulseIR(520);
    delayMicroseconds(620);
    pulseIR(520);
    delayMicroseconds(620);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(500);
    delayMicroseconds(640);
    pulseIR(520);
    delayMicroseconds(1780);
    pulseIR(520);
    delayMicroseconds(1800);
    pulseIR(520);
}
void sendSound()
{
    delayMicroseconds(5244);
    pulseIR(4600);
    delayMicroseconds(4620);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(580);
    pulseIR(560);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(560);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(580);
    delayMicroseconds(1740);
    pulseIR(560);
    delayMicroseconds(1740);
    pulseIR(580);
}
void sendTV()
{
    delayMicroseconds(22216);
    pulseIR(4680);
    delayMicroseconds(4620);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(580);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(580);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(580);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(580);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(48280);
    pulseIR(4660);
    delayMicroseconds(4640);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(580);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(560);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(560);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(1700);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
    delayMicroseconds(1720);
    pulseIR(600);
    delayMicroseconds(1720);
    pulseIR(580);
}

void setup()
{
    // initialize the IR digital pin as an output:
    pinMode(IRledPin, OUTPUT);
    pinMode(input, INPUT);
}

void loop()
{
    state = digitalRead(input);
    //Serial.println(state);
    if (state == LOW && onOff == false)
    {
        sendTV();
        delay(100);
        // sendSound();
        // delay(30000);
        // for (int i = 0; i < 21; i++)
        // {
        //     sendSoundUp();
        //     delay(500);
        // }
        onOff = true;
    }
    else if (state == LOW && onOff == true)
    {
        sendTV();
        delay(100);
        // sendSound();
        // delay(100);
        // sendSound();
        onOff = false;
    }
}