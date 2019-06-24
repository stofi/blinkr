#include "Arduino.h"
#include "functions.h"

const int DEBOUNCE = 200;
const int INTERVAL = 500;

void buttonRead(Button &button)
{
  const long time = millis();
  const bool time_passed = time - button.light.time > DEBOUNCE;

  button.reading = digitalRead(button.pin);

  if (time_passed && button.reading && !button.previous)
  {
    button.light.state = !button.light.state;
    button.light.time = time;
  }

  button.previous = button.reading;
}

void lightBlink(Light &light)
{
  if (!light.state)
  {
    light.blink_state = false;
    return;
  }

  const long time = millis();
  const bool time_passed = time - light.last_blink >= INTERVAL;

  if (time_passed)
  {
    light.blink_state = !light.blink_state;
    light.last_blink = time;
  }
}

void buttonsCompare(Button &a, Button &b)
{
  if (b.light.state && b.light.time > a.light.time)
  {
    a.light.state = false;
  }
  if (a.light.state && a.light.time > b.light.time)
  {
    b.light.state = false;
  }
}

void buttonSetup(Button &button)
{
  pinMode(button.pin, INPUT);
  pinMode(button.light.pin, OUTPUT);
}

Button getButton(int in, int out)
{
  Button button = {
      in,
      false,
      false,
      {out,
       false,
       0,
       0,
       false}};
  return button;
}
