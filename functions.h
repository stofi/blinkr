#ifndef functions_h
#define functions_h

#include "Button.h"

void buttonSetup(Button &button);
void buttonsCompare(Button &a, Button &b);
void lightBlink(Light &light);
void buttonRead(Button &button);
Button getButton(int in, int out);

#endif