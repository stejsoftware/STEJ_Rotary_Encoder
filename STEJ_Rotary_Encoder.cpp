
#include "STEJ_Rotary_Encoder.h"

STEJ_Rotary_Encoder::STEJ_Rotary_Encoder(int16_t min, int16_t max, int16_t step, boolean continuous):
  m_step(step),
  m_continuous(continuous)
{
  setMinMax(min, max);
  setValue(0);
}

STEJ_Rotary_Encoder::~STEJ_Rotary_Encoder()
{
}

void STEJ_Rotary_Encoder::setValue(int16_t value)
{
  m_value = value;
  m_changed = true;
}

void STEJ_Rotary_Encoder::setStep(int16_t step)
{
  m_step = step;
}

void STEJ_Rotary_Encoder::setMinMax(int16_t min, int16_t max)
{
  m_min = min < max ? min : max;
  m_max = max > min ? max : min;
}

void STEJ_Rotary_Encoder::setContinuous(boolean continuous)
{
  m_continuous = continuous;
}

int16_t STEJ_Rotary_Encoder::read() const
{
  m_changed = false;
  return m_value;
}

boolean STEJ_Rotary_Encoder::hasChanged() const
{
  return m_changed;
}

void STEJ_Rotary_Encoder::move_cw()
{
  m_value += m_step;
  m_changed = true;

  update();  
}

void STEJ_Rotary_Encoder::move_ccw()
{
  m_value -= m_step;
  m_changed = true;

  update();  
}
 
void STEJ_Rotary_Encoder::update()
{
  if( m_value > m_max )
  {
    m_value = m_continuous ? m_min : m_max;
    m_changed = false;
  }
  
  if( m_value < m_min )
  {
    m_value = m_continuous ? m_max : m_min;
    m_changed = false;
  }  
}
  