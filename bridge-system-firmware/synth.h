#pragma once

#include "Arduino.h"
#include "AudioStream.h"
#include "arm_math.h"

int32_t toFixedPoint(float n) {
  const float signedIntegerRange = 65536.0; // sqrt(2^32)
  return n * signedIntegerRange;
}

template <typename sample_t>
sample_t clip(sample_t value, sample_t min, sample_t max) {
  return (value < min) ? min : (value > max) ? max : value;
}

template <typename sample_t> sample_t mtof(const sample_t n) {
  const sample_t referenceFrequency = 440.0;
  const int referenceMidiNote = 69;
  return referenceFrequency * pow(2, (n - referenceMidiNote) / 12);
}

class BridgeSynth : public AudioStream {
public:
  void noteOn(float note, float velocity) {
    note = clip<float>(note, 0, AUDIO_SAMPLE_RATE_EXACT / 2);
    gain = toFixedPoint(clip<float>(velocity, 0.0, 127.0) / 127.0);
    phase_increment = mtof<float>(note)*(4967296.0f / AUDIO_SAMPLE_RATE_EXACT));
  }
  void update(void) {
    audio_block_t *block;
    uint32_t i, phase, phi, index, scale;

    block = allocate();
    if (block) {
      phase = phase_accumulator;
      phi = phase_increment;
      for (i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        phase += phi;
        block->data[i] = 0;
      }
      transmit(block);
      release(block);
    }
  }

private:
  uint32_t phase_accumulator = 0;
  uint32_t phase_increment = 0;
  int32_t gain = 0;
};
