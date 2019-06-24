#include "functions.h"

Button button_left = getButton(8,3); 
Button button_right = getButton(7,2);
Button button = getButton(0,0);

void setup() {
  buttonSetup(button_left);
  buttonSetup(button_right);
  buttonSetup(button);
}

void loop() {
  buttonRead(button_left);
  buttonRead(button_right);
  buttonRead(button);

  lightBlink(button_left.light);
  lightBlink(button_right.light);


  buttonsCompare(button_left, button_right);

  digitalWrite(button.light.pin, button.light.state);
  digitalWrite(button_left.light.pin, button_left.light.blink_state);
  digitalWrite(button_right.light.pin, button_right.light.blink_state);
}
  
