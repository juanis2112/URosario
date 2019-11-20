#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // put your setup code here, to run once:
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 24; i++) 
  {
    MIDI.sendNoteOn(60 + i, i*2, 1); 
    delay(75); 
  }

  // Delay == Bad! Set up an interrupt based timer instead 
  // (or something like Blink Without Delay)
  delay(2000);
}
