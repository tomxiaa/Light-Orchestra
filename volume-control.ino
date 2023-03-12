// Volume Library 1KHz Sketch (c) 2016 Connor Nishijima
// Released under the GPLv3 license

#include "Volume.h" // Include the Volume library

Volume vol; // Plug your speaker into the default pin for your board type:
            // https://github.com/connornishijima/arduino-volume1#supported-pins
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  vol.begin();
}
// the loop routine runs over and over again forever:
void loop() {
  int analogValue = analogRead(A0);
  float louder = map(analogValue, 50,500, 100,3000);
  float mv = constrain(louder/ 10, 0, 100) / 50.00;

  Serial.println(mv);
  vol.tone(524, 255*mv);
}
