/* 
  North Coast Modular Collective Bridge System: On Ramp
  ---------------------------------------------------------
  Copyright 2023 North Coast Modular Collective
  MIT License:
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
  documentation files (the "Software"), to deal in the Software without restriction, including without limitation 
  the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and 
  to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of 
  the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  ----------------------------------------------------------
   
  Note: Make sure "MIDI" is selected from the "Tools > USB Type" menu in the Arduino IDE
  so that it shows up as a MIDI interface. 
*/

//bounce include for buttons
#include <Bounce2.h>
Bounce ClockStartStop = Bounce(); //The button that starts and stops the clock
Bounce BigButton = Bounce(); //The button that is a trigger button on the lower left

// the MIDI channel number to send messages
const int channel = 1;

// MIDI CC data for each input, we'll be reusing a lot of these and ignoring their original 
// intention since they'll be mapped in a DAW
//The knobs
// const int BDCut = 10; 

// set pin numbers:
const int ledSeq1 = 29;  // the number of the LED pin
const int ledSeq2 = 30;  // the number of the LED pin
const int ledSeq3 = 31;  // the number of the LED pin
const int ledSeq4 = 13;  // the number of the LED pin




void setup() {
  //Set button pins to input and to use pullup resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);

   // Setup the buttons
 pinMode( 34 ,INPUT); //Clock start/stop
 pinMode( 2 ,INPUT);  //Trigger button
 // Activate internal pull-up (optional) 
 digitalWrite( 34 ,HIGH); //Clock start/stop
 digitalWrite( 2 ,HIGH);  //Trigger button

 // After setting up the button, setup the object
 ClockStartStop.attach( 34 ); //Clock start/stop button
 ClockStartStop.interval(5);
 BigButton.attach( 2 ); //Trigger Button
 BigButton.interval(5);

 // set up the LED pins
 pinMode(ledSeq1, OUTPUT);
 pinMode(ledSeq2, OUTPUT);
 pinMode(ledSeq3, OUTPUT);
 pinMode(ledSeq4, OUTPUT);
}



void loop() {

//Update all the buttons to see their state
ClockStartStop.update();
BigButton.update(); 


 //test LEDs
   digitalWrite(ledSeq1, HIGH);
   digitalWrite(ledSeq2, HIGH);
   digitalWrite(ledSeq3, HIGH);
   digitalWrite(ledSeq4, HIGH);

/*
//Buttons: Check if pressed, and if so, is it being muted or un-muted
  if (ClockStartStop.fallingEdge()) { //if the button is pressed...
      usbMIDI.sendControlChange(20, 126, channel); //Send "high" CC data (126)  usbMIDI.sendControlChange(control, value, channel);
    } else { //otherwise, if the button was not pressed...
      usbMIDI.sendControlChange(20, 0, channel); //Send "low" CC data (0)
    }
  } 

  if (BigButton.fallingEdge()) { //if the button is pressed...
      usbMIDI.sendControlChange(21, 126, channel); //Send "high" CC data (126)  usbMIDI.sendControlChange(control, value, channel);
    } else { //otherwise, if the button was not pressed...
      usbMIDI.sendControlChange(21, 0, channel); //Send "low" CC data (0)
    }
  } 
*/


unsigned long msec = millis();
  if (msec >= 20) {
      // only check the analog inputs 50 times per second,
      // to prevent a flood of MIDI messages
  msec = 0;



//Get current values from inputs
 //knobs   
   // int BDCutValue = abs(map(analogRead(A15), 0, 1023, 0, 127) - 127);

  //  int AUXCutValue = map(analogRead(A4), 0, 1023, 0, 127);


//Transmit values over MIDI    
    // only transmit MIDI messages if analog input changed
   // if ((BDCutValue > previousBDCut + 1) || (BDCutValue < previousBDCut - 1)) { //If the current value is different from the last value
  //    usbMIDI.sendControlChange(BDCut, BDCutValue, channel); //send MIDI CC
  //    previousBDCut = BDCutValue; //set the new previous value for next time
    }
   


  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  //while (usbMIDI.read()) {
    // ignore incoming messages
  //}
//}

