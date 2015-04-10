/*
 STEJ_Rotary_Encoder by Jonathan Meyer

 */

#ifndef _STEJ_ROTARY_ENCODER_H_
#define _STEJ_ROTARY_ENCODER_H_

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class STEJ_Rotary_Encoder
{
  public:
    virtual ~STEJ_Rotary_Encoder();

    void setValue(int16_t value);
    void setStep(int16_t step);
    void setMinMax(int16_t min, int16_t max);
    void setContinuous(boolean continuous);
    
    virtual void begin() = 0;
    
    int16_t read() const;
    boolean hasChanged() const;

  protected:
    STEJ_Rotary_Encoder(int16_t min, int16_t max, int16_t step, boolean continuous);

    void move_cw();
    void move_ccw();
    
  private:    
    int16_t m_min;
    int16_t m_max;
    int16_t m_step;
    
    boolean m_continuous;
    
    int16_t m_value;
    mutable boolean m_changed;

    STEJ_Rotary_Encoder(const STEJ_Rotary_Encoder & rhs);
    STEJ_Rotary_Encoder & operator=(const STEJ_Rotary_Encoder & rhs);

    void update();
};

#endif // _STEJ_ROTARY_ENCODER_H_
