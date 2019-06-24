#include "functions.h"

Button button_left = getButton(10, 2);
Button button_right = getButton(9, 3);

void setup()
{
  buttonSetup(button_left);
  buttonSetup(button_right);
}

void loop()
{
  buttonRead(button_left);
  buttonRead(button_right);

  lightBlink(button_left.light);
  lightBlink(button_right.light);

  buttonsCompare(button_left, button_right);

  digitalWrite(button_left.light.pin, button_left.light.blink_state);
  digitalWrite(button_right.light.pin, button_right.light.blink_state);
}
