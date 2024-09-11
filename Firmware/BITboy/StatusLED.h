#include "api/Common.h"
//LED for signal indication
#define LEDPin D12


void ConfigStatusLED() {
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, HIGH);
  delay(150);
  digitalWrite(LEDPin, LOW);
}