#ifndef Button_h
#define Button_h

#include "Light.h"

struct Button
{
  int pin;
  bool reading;
  bool previous;
  Light light;
};

#endif