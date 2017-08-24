#include <Joystick.h>

//Buttons defined according to https://www.w3.org/TR/gamepad/
#define BUTTON_0        0
#define BUTTON_1        1
#define BUTTON_2        2
#define BUTTON_3        3
#define SHOULDER_LEFT   4
#define SHOULDER_RIGHT  5
#define TRIGGER_LEFT    6
#define TRIGGER_RIGHT   7
#define START           8
#define SELECT          9
#define THUMB_LEFT      10
#define THUMB_RIGHT     11
#define HAT_UP          12
#define HAT_DOWN        13
#define HAT_LEFT        14
#define HAT_RIGHT       15
#define HOME            16

#define X_AXIS_PIN      A2 // Pin 20
#define Y_AXIS_PIN      A1 // Pin 19

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins - comment out  any unused
//   pinMode(0, INPUT_PULLUP); 
//   pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
//   pinMode(14, INPUT_PULLUP);
//   pinMode(15, INPUT_PULLUP);
//   pinMode(16, INPUT_PULLUP);
//   pinMode(18, INPUT_PULLUP);
//   pinMode(19, INPUT_PULLUP);
//   pinMode(20, INPUT_PULLUP);
//   pinMode(21, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();

  Joystick.setXAxisRange(1024, 0);
  Joystick.setYAxisRange(1024, 0);
}

//Edit button to pin mapping according to your hardware - use -1 if unused
int pinToButtonMap[20][2] =  {{BUTTON_0,        9},
                              {BUTTON_1,        8},
                              {BUTTON_2,        7},
                              {BUTTON_3,        6},
                              {SHOULDER_LEFT,   4},
                              {SHOULDER_RIGHT,  5},
                              {TRIGGER_LEFT,    -1},
                              {TRIGGER_RIGHT,   -1},
                              {START,           3},
                              {SELECT,          2},
                              {THUMB_LEFT,      10},
                              {THUMB_RIGHT,     -1},
                              {HAT_UP,          -1},
                              {THUMB_LEFT,      -1},
                              {HAT_UP,          -1},
                              {HAT_DOWN,        -1},
                              {HAT_LEFT,        -1},
                              {HAT_RIGHT,       -1},
                              {HOME,            -1}};

int buttonStateMap[20][2] =  {{BUTTON_0, 0},
                              {BUTTON_1, 0},
                              {BUTTON_2, 0},
                              {BUTTON_3, 0},
                              {SHOULDER_LEFT, 0},
                              {SHOULDER_RIGHT, 0},
                              {TRIGGER_LEFT, 0},
                              {TRIGGER_RIGHT, 0},
                              {START, 0},
                              {SELECT, 0},
                              {THUMB_LEFT, 0},
                              {THUMB_RIGHT, 0},
                              {HAT_UP, 0},
                              {THUMB_LEFT, 0},
                              {HAT_UP, 0},
                              {HAT_DOWN, 0},
                              {HAT_LEFT, 0},
                              {HAT_RIGHT, 0},
                              {HOME, 0}};

void loop() {
  for (int i = 0; i < 20; i++)  {
    if(pinToButtonMap[i][1] > -1) {
      int currentState = !digitalRead(pinToButtonMap[i][1]);
      if (currentState != buttonStateMap[i][1]) { // Detect button state change
        Joystick.setButton(i, currentState);
        buttonStateMap[i][1] = currentState;
      }
    }
  }
  Joystick.setXAxis(analogRead(X_AXIS_PIN));
  Joystick.setYAxis(analogRead(Y_AXIS_PIN));
  delay(50);
}
