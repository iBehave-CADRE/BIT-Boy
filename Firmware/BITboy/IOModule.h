//BNC Port Definitions
#define AnalogDataPin A0
#define DigitalDataPin D5

void ConfigIO(int IOMode) {
  if (IOMode == 2 || IOMode == 6  || IOMode == 3  || IOMode == 7) {
    //for all input modes 0 1 4 5
    analogReadResolution(12);
    pinMode(AnalogDataPin, INPUT);
    pinMode(DigitalDataPin, INPUT);
  } else if (IOMode == 0 || IOMode == 1  || IOMode == 4  || IOMode == 5) {
    //for all output modes 2 6 3 7
    pinMode(AnalogDataPin, OUTPUT);
    pinMode(DigitalDataPin, OUTPUT);
  }
}

int ReadIOForDisplay(int InMode) {
  int MeasuredInput;
  if (InMode == 2 || InMode == 6) {
    //for all digital input modes
    MeasuredInput = map(digitalRead(DigitalDataPin), 0, 1, 7, 0);
    MeasuredInput = constrain(MeasuredInput, 0, 7);
  } else if (InMode == 3 || InMode == 7) {
    //for all analog input modes
    MeasuredInput = map(analogRead(AnalogDataPin), 0, 4095, 7, 0); //4095
    MeasuredInput = constrain(MeasuredInput, 0, 7);
  } 
  return MeasuredInput;
}

float ReadIO(int InMode) {
  float MeasuredInput = 0.00;
  if (InMode == 2 || InMode == 6) {
    //for all digital input modes
    MeasuredInput = map(digitalRead(DigitalDataPin), 0, 1, 0, 5);
    MeasuredInput = constrain(MeasuredInput, 0, 5);
  } else if (InMode == 3 || InMode == 7) {
    //for all analog input modes
    MeasuredInput = analogRead(AnalogDataPin);
    MeasuredInput = mapfloat(MeasuredInput, 0, 4095, 0, 5); //4095
  } 
  return MeasuredInput;
}

int WriteIO(int OutMode, int value) {
  if (OutMode == 0 || OutMode == 4) {
    //for all digital output modes
    digitalWrite(DigitalDataPin, value); //HIGH LOW
  } else if (OutMode == 1 || OutMode == 5) {
    //for all analog output modes
    analogWrite(AnalogDataPin, value); //0-255
  }
}