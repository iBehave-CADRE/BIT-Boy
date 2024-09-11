#define version "1"

#include "Arduino_LED_Matrix.h"
#include "SignalMapping.h"
#include "DIPSwitch.h"
#include "IOModule.h"
#include "SerialCommunication.h"


#include "pitches.h"
#include "Buzzer.h"
#include "StatusLED.h"

#include "ContinuityCheck.h"
#include "RotaryButton.h"


#include "Oscilloscope.h"

int Mode = 0;

void setup() {
  ConfigSerialCom ();
  
  ConfigDIPSwitch();
  Mode = ReadDIPSwitchSettings();
  ConfigIO(Mode);
  ConfigOscilloscope(Mode);
  ConfigBuzzer();
  ConfigStatusLED();
  ConfigContinuityCheck();
  ConfigRotaryButton();
  
}

void loop() {
  ContinuityCheck();
  ButtonAction(Mode);
  RotationAction();
  calcNextFrame(Mode, ReadIOForDisplay(Mode), ReadOutputForDisplay(Mode));
  matrix.renderBitmap(CurrentFrame, 8, 12);
  delay(TemporalResolution(Mode));
  UpdateConstantAnalogOutput(Mode);
  SerialCom(Mode, ReadIO(Mode), ReadOutput(Mode));
}