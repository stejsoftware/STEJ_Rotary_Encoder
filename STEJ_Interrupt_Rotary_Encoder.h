/*
 STEJ_Interrupt_Rotary_Encoder by Jonathan Meyer

 */

#ifndef _STEJ_INTERRUPT_ROTARY_ENCODER_H_
#define _STEJ_INTERRUPT_ROTARY_ENCODER_H_

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "STEJ_Rotary_Encoder.h"

class STEJ_Interrupt_Rotary_Encoder : public STEJ_Rotary_Encoder
{
  public:
    STEJ_Interrupt_Rotary_Encoder(uint16_t pin_a = 2, uint16_t pin_b = 3, int16_t min = 0, int16_t max = 254, int16_t step = 1, boolean continuous = false);
    virtual ~STEJ_Interrupt_Rotary_Encoder();

    void setDebounce(uint16_t debounce);
    
    virtual void begin();

    void interrupt_a();
    void interrupt_b();
   
  private:
    uint16_t m_pin_a;
    uint16_t m_pin_b;

    uint16_t m_debounce;
    
    boolean m_a;
    boolean m_b;
  
    STEJ_Interrupt_Rotary_Encoder(const STEJ_Interrupt_Rotary_Encoder & rhs);
    STEJ_Interrupt_Rotary_Encoder & operator=(const STEJ_Interrupt_Rotary_Encoder & rhs);
};

#endif // _STEJ_INTERRUPT_ROTARY_ENCODER_H_
