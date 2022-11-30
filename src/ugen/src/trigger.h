#include "ugen.h"

enum eMode {
  ON_ASCENT,
  ON_DESCENT
};

class Trigger {
  public:
    Trigger(Ugen *ug, float threshold = 1.0, eMode mode = ON_ASCENT);
    bool bang();

  private:
    float _prev;

    Ugen *_ugen;
    eMode _mode;
    float _t;
};