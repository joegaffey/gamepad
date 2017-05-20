#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();

  Joystick.setXAxisRange(1024, 0);
  Joystick.setYAxisRange(1024, 0);
}

// Last state of the button
int lastButtonState[9] = {0,0,0,0,0,0,0,0,0};

// Array index is joystick button number
int pinToButtonMap[9] = {9,8,7,6,4,5,10,3,2};

void loop() {

  // Read pin values
  for (int index = 0; index < 9; index++)
  {
    int currentButtonState = !digitalRead(pinToButtonMap[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  Joystick.setXAxis(analogRead(A2));
  Joystick.setYAxis(analogRead(A1));

  delay(50);
}

