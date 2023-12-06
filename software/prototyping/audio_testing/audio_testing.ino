/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=216,320
AudioInputI2S            i2s1;           //xy=229,647
AudioOutputUSB           usb1;           //xy=414,319
AudioEffectBitcrusher    bitcrusher1;    //xy=460,252
AudioFilterStateVariable filter1;        //xy=658,250
AudioEffectEnvelope      envelope1;      //xy=863,249
AudioConnection          patchCord1(waveform1, 0, usb1, 0);
AudioConnection          patchCord2(waveform1, 0, usb1, 1);
// GUItool: end automatically generated code


// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the trigger pushbutton pin
const int ledPin = 39;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

//oscillator waveform
int current_waveform=0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

  //set up the oscillator (waveform1)
    waveform1.frequency(440);
    waveform1.amplitude(1.0);
    current_waveform = WAVEFORM_SAWTOOTH;
    waveform1.begin(current_waveform);
}

void loop() {
  
    AudioNoInterrupts();
  // use Knob A2 to adjust the frequency of both waveforms
  waveform1.frequency(440); //just hardcode it to 440 for now
  AudioInterrupts();


      AudioNoInterrupts();  //select the waveform here
      current_waveform = WAVEFORM_SAWTOOTH; //hardcode to sawtooth for now
    waveform1.begin(current_waveform);
    //waveform2.begin(WAVEFORM_SINE);
    AudioInterrupts();
  
  
  // read the state of the trigger pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);
  }
}
