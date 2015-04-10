#include "STEJ_Interrupt_Rotary_Encoder.h"

// create an encoder object
// On the Uno only one encoder can be 
// connected and should be on digital 
// pins 2 and 3
STEJ_Interrupt_Rotary_Encoder encoder;

void setup() 
{
  Serial.begin(9600);

  // The encoder's value can be limited
  encoder.setMinMax(-50, 50);

  // Sets the how much is added or subtracted
  // from the encoder's value for each click
  encoder.setStep(2);

  // If the encoder is in continuous mode then
  // the value will wrap arond when it reaches
  // either the min or max. Otherwise it simply
  // stop when a limit is reached
  encoder.setContinuous(true);

  // before we can read the encoder it has to be started.
  encoder.begin();
}

void loop() 
{
  // check to see if the value of the encoder has changed
  if( encoder.hasChanged() )
  {
    // read the encoder's current value
    Serial.println(encoder.read());
  }
}