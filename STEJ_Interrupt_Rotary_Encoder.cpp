
#include "STEJ_Interrupt_Rotary_Encoder.h"

static STEJ_Interrupt_Rotary_Encoder * _encoder = NULL;

void _interrupt_a()
{
  noInterrupts();
  _encoder->interrupt_a();
  interrupts();
}

void _interrupt_b()
{
  noInterrupts();
  _encoder->interrupt_b();
  interrupts();
}

STEJ_Interrupt_Rotary_Encoder::STEJ_Interrupt_Rotary_Encoder(uint16_t pin_a, uint16_t pin_b, int16_t min, int16_t max, int16_t step, boolean continuous):
  STEJ_Rotary_Encoder(min, max, step, continuous),
  m_pin_a(pin_a),
  m_pin_b(pin_b),
  m_debounce(1000)
{
}

STEJ_Interrupt_Rotary_Encoder::~STEJ_Interrupt_Rotary_Encoder()
{
}

void STEJ_Interrupt_Rotary_Encoder::setDebounce(uint16_t debounce)
{
  m_debounce = debounce;
}

void STEJ_Interrupt_Rotary_Encoder::begin()
{
  _encoder = this;

  pinMode(m_pin_a, INPUT);
  pinMode(m_pin_b, INPUT);

  digitalWrite(m_pin_a, HIGH); //turn pullup resistor on
  digitalWrite(m_pin_b, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(0, _interrupt_a, CHANGE);
  attachInterrupt(1, _interrupt_b, CHANGE);
}

void STEJ_Interrupt_Rotary_Encoder::interrupt_a()
{
  delayMicroseconds(m_debounce);  // 'debounce'

  boolean _a = digitalRead(m_pin_a) == HIGH;

  // rise
  if( !m_a && _a )
  {
    if( !m_b )
    {
      move_cw();
    }
  }

  m_a = _a;
}

void STEJ_Interrupt_Rotary_Encoder::interrupt_b()
{
  delayMicroseconds(m_debounce);  // 'debounce'

  boolean _b = digitalRead(m_pin_b) == HIGH;

  // rise
  if( !m_b && _b )
  {
    if( !m_a )
    {
      move_ccw();
    }
  }

  m_b = _b;
}
