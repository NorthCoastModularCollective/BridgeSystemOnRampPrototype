/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground through 220 ohm resistor.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fading
*/


//We were looking into https://forum.arduino.cc/t/reading-a-pwm-signal/603967/5 
//Also a library called arduino-pwm-reader

int ledPin = 11;  // LED connected to digital pin 9
int knob01 = A5; 
int pwmin = 6;
unsigned long pwminputhightime;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(pwmin, INPUT);
}

void loop() {
int knobvalue = map(analogRead(knob01), 0, 1023, 0, 255);

analogWrite(ledPin, knobvalue);
pwminputhightime = pulseIn(pwmin, HIGH);
Serial.println(pwminputhightime);



  }

