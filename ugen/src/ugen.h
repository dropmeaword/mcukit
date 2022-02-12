#pragma once
//
//    FILE: functionGenerator.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.2
// PURPOSE: wave form generating functions (use with care)
//     URL: https://github.com/RobTillaart/FunctionGenerator
//

// with some extensions by studio derfunke

#include "Arduino.h"

class Ugen
{
public:
  Ugen(float period = 1.0, float amplitude = 1.0, float phase = 0.0, float yShift = 0.0);

  // configuration
  void  setPeriod(float period = 1.0);
  float getPeriod() { return _period; };
  void  setFrequency(float freq = 1.0) { setPeriod(1/freq); };
  float getFrequency() { return _freq1; };

  void  setAmplitude(float ampl = 1.0) { _amplitude = ampl; };
  float getAmplitude() { return _amplitude; };
  void  setPhase(float phase = 0.0) { _phase = phase; };
  float getPhase() { return _phase; };
  void  setYShift(float yShift = 0.0) { _yShift = yShift; };
  float getYShift() { return _yShift; };
  
  // constant amplitude
  float line();
  // constant zero for calibration
  float zero();
  
  // standard wave forms
  float sawtooth(float t, uint8_t mode = 0);
  float triangle(float t);
  float square(float t);
  float sinus(float t);
  float stair(float t, uint16_t steps = 8, uint8_t mode = 0);
  float random();
  virtual float sample(float t) { return zero(); }

private:
  float _period;
  float _freq0;
  float _freq1;
  float _freq2;
  float _freq4;
  float _amplitude;
  float _phase;
  float _yShift;
  // Marsaglia 'constants'
  uint32_t _m_w = 1;
  uint32_t _m_z = 2; 
  uint32_t _random();
};

class USquare : public Ugen {
  public:
    float sample(float t) {
      return square(t);
    }
};

class USinus : public Ugen {
  public:
    float sample(float t) {
      return sinus(t);
    }
};

class UTriangle : public Ugen {
  public:
    float sample(float t) {
      return triangle(t);
    }
};

class URandom : public Ugen {
  public:
    float sample(float t) {
      return random();
    }
};