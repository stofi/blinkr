const long DEBOUNCE = 30;
const long INTERVAL = 500;

struct Light
{
  int pin;
  bool state;
  long time;
  long last_blink;
  bool blink_state;
};

struct Button
{
  int pin;
  bool reading;
  bool previous;
  Light light;
};

Button getButton(int in, int out) {
  Button button = {
    in,
    false,
    false,
    {
      out,
      false,
      0,
      0,
      false
    }
  }; 
  return button;
}

void buttonRead(Button &button) {
  const long time = millis();
  const bool time_passed = time - button.light.time > DEBOUNCE;

  button.reading = digitalRead(button.pin);

  if (time_passed && button.reading && !button.previous) {
    button.light.state = !button.light.state;
    button.light.time = time;
  }

  button.previous = button.reading;
}

void lightBlink(Light &light) {
  if (!light.state) {
    light.blink_state = false;
    return;
  }
  
  const long time = millis();
  const bool time_passed = time - light.last_blink >= INTERVAL;

  if (time_passed) {
    light.blink_state = !light.blink_state;
    light.last_blink = time;
  }
}

void buttonsCompare(Button &a, Button &b) {
  if(b.light.state && b.light.time > a.light.time) {
    a.light.state = false;
  }
  if(a.light.state && a.light.time > b.light.time) {
    b.light.state = false;
  }
}

void buttonSetup(Button &button) {
  pinMode(button.pin, INPUT);
  pinMode(button.light.pin, OUTPUT);  
}


Button button_left = getButton(8,3); 
Button button_right = getButton(7,2); 

void setup() {
  buttonSetup(button_left);
  buttonSetup(button_right);
}

void loop() {
  buttonRead(button_left);
  buttonRead(button_right);

  lightBlink(button_left.light);
  lightBlink(button_right.light);

  buttonsCompare(button_left, button_right);

  digitalWrite(button_left.light.pin, button_left.light.blink_state);
  digitalWrite(button_right.light.pin, button_right.light.blink_state);
}
