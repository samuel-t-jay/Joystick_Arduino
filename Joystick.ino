const int JoyStick_pin = 8; // Joystick-Button auf Pin 8
const int X_pin = A0;       // Joystick X auf Pin A0
const int Y_pin = A1;       // Joystick Y auf Pin A1

int xCenter;
int yCenter;
int xc;
int yc;
int JSButton;

void setup() {
  pinMode(JoyStick_pin, INPUT_PULLUP);
  Serial.begin(115200);

  // Kalibrierung der Mittelwerte
  xCenter = analogRead(X_pin);
  yCenter = analogRead(Y_pin);

  Serial.print("xCenter: ");
  Serial.println(xCenter);
  Serial.print("yCenter: ");
  Serial.println(yCenter);
}

void loop() {
  int x = analogRead(X_pin) - xCenter;  // Dynamische Kalibrierung verwenden
  int y = analogRead(Y_pin) - yCenter;

  if (x < -20) { // Schwellenwerte angepasst
    xc = 0;
  } else if (x > 20) {
    xc = 2;
  } else {
    xc = 1;
  }

  if (y < -20) {
    yc = 2;
  } else if (y > 20) {
    yc = 0;
  } else {
    yc = 1;
  }

  int buttonStates = 0;
  buttonStates |= ((digitalRead(JoyStick_pin) == LOW) ? 1 : 0) << 0;

  Serial.print("S");
  Serial.print(xc);
  Serial.print(",");
  Serial.print(yc);
  Serial.print(",");
  Serial.println(buttonStates);

  delay(40);
}
