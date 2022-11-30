#include "trigger.h"

Trigger::Trigger(Ugen *ug, float threshold, eMode mode)
{
  _t = threshold;
  _mode = mode;
  _ugen = ug;
}

bool Trigger::bang() {
  bool retval = false;
  float t = millis() * 0.001;
  float v = _ugen->sample(t);

  if( (v > _prev) && (v >= _t) && (_mode == ON_ASCENT) ) {
    retval = true;
  }

  if( (v < _prev) && (v <= _t) && (_mode == ON_DESCENT) ) {
    retval = true;
  }

  _prev = v;
  return retval;
}
