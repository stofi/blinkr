#ifndef Light_h
#define Light_h

struct Light
{
  int pin;
  bool state;
  long time;
  long last_blink;
  bool blink_state;
};

#endif