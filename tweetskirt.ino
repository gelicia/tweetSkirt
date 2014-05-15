#include "letterArrays.h"

#define LED_PIN 13

boolean ledState = false;
CycleTiming timer(500);


void setup() {
  pinMode(LED_PIN, OUTPUT);
}


void loop() {
  if (timer.check()) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}