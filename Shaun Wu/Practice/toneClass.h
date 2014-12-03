#ifdef TONE_CLASS
#define TONE_CLASS

#include "Arduino.h"

class toneClass
{
public:

    toneClass(int pinNumber);

    enum tone (HIGH_PITCH, LOW_PITCH);

    void setTone(tone val);

    void stopTone();

    void playTone();

private:
    tone currentTone;
    int pin;
};

#endif
