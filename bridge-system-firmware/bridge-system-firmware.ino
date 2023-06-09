/*
  North Coast Modular Collective Bridge System: On Ramp
  ---------------------------------------------------------
  Copyright 2023 North Coast Modular Collective
  MIT License:
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
  ----------------------------------------------------------

  Note: Make sure "MIDI" is selected from the "Tools > USB Type" menu in the
  Arduino IDE so that it shows up as a MIDI interface.
*/
#include <Bounce2.h>

#define DECAY_IN_PIN 0                 // Decay In
#define MISO_LCD_PIN 1                 // MISO (LCD Screen)
#define TRIGGER_BUTTON_PIN 2           // Trigger button
#define SHAPER_IN_PIN 3                // shaper in
#define FILTER_IN_PIN 4                // filter in
#define ATTACK_IN_PIN 5                // attack in
#define WAVEFORM_IN_PIN 6              // waveform in
#define DIN_AUDIO_PIN 7                // DIN (SGTL5000 Audio Chip)
#define DOUT_AUDIO_PIN 8               // DOUT (SGTL5000 Audio Chip)
#define CLOCK_OUT_PIN 9                // clock Out
#define TRIGGER_OUT_PIN 10             // trigger Out
#define MOSI_LCD_PIN 11                // MOSI (LCD Screen)
#define SEQUENCER_OUT_PIN 12           // Sequencer Out
#define LFO_WAVE_KNOB_PIN 14           // LFO Wave
#define ENV_ATTACK_KNOB_PIN 15         // Envelope Attack
#define SHAPER_KNOB_PIN 16             // Shaper
#define FILTER_KNOB_PIN 17             // Filter
#define SDA_AUDIO_PIN 18               // SDA (SGTL5000 Audio Chip)
#define SCL_AUDIO_PIN 19               // SCL (SGTL5000 Audio Chip)
#define LRCLCK_AUDIO_PIN 20            // LRCLCK (SGTL5000 Audio Chip)
#define BLCK_AUDIO_PIN 21              // BLCK (SGTL5000 Audio Chip)
#define LFO_RATE_KNOB_PIN 22           // LFO Rate
#define LFO_AMOUNT_KNOB_PIN 23         // LFO Amount
#define SEQ_FADER1_PIN 24              // Sequencer fader 1
#define SEQ_FADER2_PIN 25              // Sequencer fader 2
#define SEQ_FADER3_PIN 26              // Sequencer fader 3
#define SEQ_FADER4_PIN 27              // Sequencer fader 4
#define LFO_OUT_PIN 28                 // LFO Output
#define SEQUENCER_LED1_PIN 29          // Sequencer 1st LED
#define SEQUENCER_LED2_PIN 30          // Sequencer 2nd LED
#define SEQUENCER_LED3_PIN 31          // Sequencer 3rd LED
#define SEQUENCER_LED4_PIN 13          // Sequencer 4th LED
#define RESET_LCD_PIN 32               // reset (LCD Screen)
#define MCLK_AUDIO_PIN 33              // MCLK (SGTL5000 Audio Chip)
#define CLOCK_START_STOP_BUTTON_PIN 34 // Clock Start/stop Button
#define CLOCK_SPEED_ENCODER_PINA 35    // Rotary Encoder A (clock speed)
#define RS_LCD_PIN 36                  // RS (LCD Screen)
#define CS1_LCD_PIN 37                 // CS1 (LCD Screen)
#define CLOCK_SPEED_ENCODER_PINB 38    // Rotary Encoder B (clock speed)
#define CLOCK_LED_PIN 39               // Clock LED
#define ENVELOPE_DECAY_KNOB_PIN 40     // Envelope Decay
#define OSCILLATOR_WAVE_KNOB_PIN 41    // Oscillator Wave Form
#define NUM_SEQ_STEPS 4
short seqFaderPins[NUM_SEQ_STEPS] = {SEQUENCER_LED1_PIN, SEQUENCER_LED2_PIN,
                                     SEQUENCER_LED3_PIN, SEQUENCER_LED4_PIN};
Bounce clockStartStopButton = Bounce();
Bounce triggerButton = Bounce();

// the MIDI channel number to send messages
const int midiChannel = 1;

int faderValues[NUM_SEQ_STEPS] = {0, 0, 0, 0};
int faderCCNumbers[NUM_SEQ_STEPS] = {44,45,46,47};

void setup() {
  clockStartStopButton.attach(CLOCK_START_STOP_BUTTON_PIN);
  triggerButton.attach(TRIGGER_BUTTON_PIN);
}

void loop() {
  readFaders();
  updateMidi();
  delay(20);
}

void readFaders() {

  for (int i = 0; i < NUM_SEQ_STEPS; i++) {
    faderValues[i] = analogRead(seqFaderPins[i]);
  }
}
void updateMidi() {

  for (int i = 0; i < NUM_SEQ_STEPS; i++) {
    usbMIDI.sendControlChange(faderCCNumbers[i],map(faderValues[i], 0, 1023, 0, 127), midiChannel);
  }
}
