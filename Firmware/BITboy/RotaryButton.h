#include "api/Common.h"
//Rotary Encoder Definitions
#define encAPin 3
#define encBPin 4
#define encButtonPin 2

#define FW 1 //code for forward direction rotation
#define BW -1 //same for backwards

volatile int Direction = 0;
volatile byte RotationDetected = false;
volatile int counter = 0;

volatile byte ButtonPushDetected = false;

volatile unsigned long last_time;  // for debouncing


  
int ToggleCounter = 0;
int Toggle = false;
int ConstantAnalogOut = false;
int ConstantDigitalOut = false;
int DigitalOutputValue = 0;
int AnalogOutputValue = 0;

void ButtonAction(int OutputMode) {
  int ButtonState = 0;
  

  if (ButtonPushDetected==true) {
    if (OutputMode == 0) {// Digital Out Const
      ToggleCounter = ToggleCounter + 1;
      if (ToggleCounter == 2) {
        Toggle =! Toggle;
        if (Toggle == true) {
          DigitalOutputValue = 1;
          digitalWrite(LEDPin, HIGH);
          WriteIO(OutputMode, DigitalOutputValue);
          ToggleCounter = 0;
          ConstantDigitalOut = true;
        } else if (Toggle == false) {
          DigitalOutputValue = 0;
          digitalWrite(LEDPin, LOW);
          WriteIO(OutputMode, DigitalOutputValue);
          ConstantDigitalOut = false;
          ToggleCounter = 0;
        } 
      }
    } else if (OutputMode == 1) {// Analog Out Const
    ToggleCounter = ToggleCounter + 1;
      if (ToggleCounter == 2) {
        Toggle =! Toggle;
        if (Toggle == true) {
          AnalogOutputValue = map(counter, 0, 7, 0, 255);
          AnalogOutputValue = constrain(AnalogOutputValue, 0, 255);
          digitalWrite(LEDPin, HIGH);
          WriteIO(OutputMode, AnalogOutputValue);
          ToggleCounter = 0;
          AnalogOutputValue = 1;
          ConstantAnalogOut = true;
        } else if (Toggle == false) {
          AnalogOutputValue = 0;
          AnalogOutputValue = map(AnalogOutputValue, 0, 7, 0, 255);
          AnalogOutputValue = constrain(AnalogOutputValue, 0, 255);
          digitalWrite(LEDPin, LOW);
          WriteIO(OutputMode, AnalogOutputValue);
          ToggleCounter = 0;
          AnalogOutputValue = 0;
          ConstantAnalogOut = false;
        }
      }
    } else if (OutputMode == 4) {// digital pulse
      ButtonState = digitalRead(encButtonPin);
      if (ButtonState == HIGH) {
        DigitalOutputValue = 0;
        digitalWrite(LEDPin, LOW);
        WriteIO(OutputMode, DigitalOutputValue);
      } else {
        DigitalOutputValue = 1;
        digitalWrite(LEDPin, HIGH);
        WriteIO(OutputMode, DigitalOutputValue);
      }
    } else if (OutputMode == 5) {// analog pulse
      ButtonState = digitalRead(encButtonPin);
      if (ButtonState == HIGH) {
        AnalogOutputValue = 0;
        digitalWrite(LEDPin, LOW);
        WriteIO(OutputMode, AnalogOutputValue);
      } else {
        AnalogOutputValue = map(counter, 0, 7, 0, 255);
        AnalogOutputValue = constrain(AnalogOutputValue, 0, 255);
        digitalWrite(LEDPin, HIGH);
        WriteIO(OutputMode, AnalogOutputValue);
      }
    } else if (OutputMode == 2 || OutputMode == 3 || OutputMode == 6 || OutputMode == 7) {
    return;
    }
    ButtonPushDetected = !ButtonPushDetected;
  } else {
    return;
  }
}  


int UpdateConstantAnalogOutput(int ConstAOMode) {
  if (ConstAOMode == 1 && ConstantAnalogOut == true) {
    //int AnalogOutVal = 0;
    AnalogOutputValue = map(counter, 0, 7, 0, 255);
    AnalogOutputValue = constrain(AnalogOutputValue, 0, 255);
    digitalWrite(LEDPin, HIGH);
    WriteIO(ConstAOMode, AnalogOutputValue);
  }
}



int ReadOutput(int ReadOutMode) {
  int MeasuredOutput = 0;
  if (ReadOutMode == 4) {
    //for digital pulse
    MeasuredOutput = DigitalOutputValue;
    MeasuredOutput = map(MeasuredOutput, 0, 1, 0, 5);
    MeasuredOutput = constrain(MeasuredOutput, 0, 5);
  } else if (ReadOutMode == 0) {
    //for digital out constant
    MeasuredOutput = DigitalOutputValue;
    MeasuredOutput = map(MeasuredOutput, 0, 1, 0, 5);
    MeasuredOutput = constrain(MeasuredOutput, 0, 5);
  } else if (ReadOutMode == 1) {
    //for all analog output modes
    MeasuredOutput = AnalogOutputValue;
    MeasuredOutput = map(MeasuredOutput, 0, 255, 0, 5);
    MeasuredOutput = constrain(MeasuredOutput, 0, 5);
  } else if (ReadOutMode == 5) {
    //for all analog output modes
    MeasuredOutput = AnalogOutputValue;
    MeasuredOutput = map(MeasuredOutput, 0, 255, 0, 5);
    MeasuredOutput = constrain(MeasuredOutput, 0, 5);
  }
  return MeasuredOutput;
}

int ReadOutputForDisplay(int ReadOutMode) {
  int MeasuredOutput = 0;
  if (ReadOutMode == 4) {
    //for digital pulse
    MeasuredOutput = DigitalOutputValue;
    MeasuredOutput = map(MeasuredOutput, 0, 1, 7, 0);
    MeasuredOutput = constrain(MeasuredOutput, 0, 7);
  } else if (ReadOutMode == 0) {
    //for digital out constant
    MeasuredOutput = DigitalOutputValue;
    MeasuredOutput = map(MeasuredOutput, 0, 1, 7, 0);
    MeasuredOutput = constrain(MeasuredOutput, 0, 7);
  } else if (ReadOutMode == 1) {
    //for all analog output modes
    MeasuredOutput = counter;
    MeasuredOutput = map(MeasuredOutput, 0, 7, 7, 0);
    MeasuredOutput = constrain(MeasuredOutput, 0, 7);
  } else if (ReadOutMode == 5) {
    //for all analog output modes
    MeasuredOutput = counter;
    MeasuredOutput = map(MeasuredOutput, 0, 7, 7, 0);
    MeasuredOutput = constrain(MeasuredOutput, 0, 7);
  }
  return MeasuredOutput;
}

void DetectButtonPush() {
  ButtonPushDetected = true;
}

void RotationAction() {
  if (RotationDetected == true) {
    RotationDetected = !RotationDetected;
  } else if (RotationDetected == false) {
    return;
  }
}

void DetectRotation() {
  if ((millis() - last_time) < 50)  // debounce time is 50ms
    return;
  RotationDetected = true;
  if (digitalRead(encAPin) == digitalRead(encBPin)) {
    Direction = BW;
    if (counter >= 1) {
      counter--;
    }
  } else {
    Direction = FW;
    if (counter <= 6) {
      counter++;
      }
    }
  last_time = millis();
}

void ConfigRotaryButton() {
  pinMode(encAPin, INPUT_PULLUP);
  pinMode(encBPin, INPUT_PULLUP);
  pinMode(encButtonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encButtonPin), DetectButtonPush, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encAPin), DetectRotation, FALLING);
}

int TemporalResolution(int ResolutionMode) {
  int AdaptedDelay = 0;
  if (ResolutionMode == 2 || ResolutionMode == 3 || ResolutionMode == 6 || ResolutionMode == 7) {
    AdaptedDelay = map(counter, 0, 7, 1, 100);
    //AdaptedDelay = constrain(AdaptedDelay, 0, 1000);
  } else if (DIPSwitchSetting == 1) {
    AdaptedDelay = 50;
  } else if (DIPSwitchSetting == 5) {
    AdaptedDelay = 50;
  } else {
    AdaptedDelay = 1;
  }
  return AdaptedDelay;
}