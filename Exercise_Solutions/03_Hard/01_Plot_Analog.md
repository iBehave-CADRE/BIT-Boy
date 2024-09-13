```C++
#define version "1"

#include "Arduino_LED_Matrix.h"

#define AnalogDataPin A0
#define DigitalDataPin D5

uint8_t CurrentFrame[8][12];

uint8_t NextFrame[8][12];

uint8_t BootScreen[8][12] = {
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1 },
  { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }
};

//Initialising variables for later use in the script
int MeasuredAnalogInput;

int PlottingValue;

ArduinoLEDMatrix matrix;

void setup() {
  //Setting the resolution to 12 will read in a range of 0-4095, while setting to 10 will read 0-1023
  analogReadResolution(12);
  pinMode(AnalogDataPin, INPUT);

  //Start serial communication

  matrix.begin();
  matrix.renderBitmap(BootScreen, 8, 12);
  delay(1500);



  Serial.begin(115200);
  Serial.print("BITboy Interface Version ");
  Serial.println(version);
}

void loop() {
    readAnalogSignalInput();
    calcNextFrame();
    matrix.renderBitmap(CurrentFrame, 8, 12);
    delay(100);
}

void readAnalogSignalInput() {
    //Reaging analog input and mapping it to 5V for serial print with accurate units.
  MeasuredAnalogInput = map(analogRead(AnalogDataPin), 0, 4095, 7, 0);
  MeasuredAnalogInput = constrain(MeasuredAnalogInput, 0, 7);


  delay(200);

  //Serial printing of analog signal. The first print will allow to name the variable in the serial plotter.
  Serial.print("Analog_In[V]:");
  Serial.println(MeasuredAnalogInput);


}

void MakeAxis(){
  for (int thisRow = 0; thisRow <= 7; thisRow++) {
    NextFrame[thisRow][0] = 1;
  }
}

void calcNextFrame() {
    PlottingValue = MeasuredAnalogInput;
  for (int thisRow = 0; thisRow <= 7; thisRow++) {
    for (int thisColumn = 0; thisColumn <= 11; thisColumn++) {
      NextFrame[thisRow][thisColumn] = CurrentFrame[thisRow][thisColumn+1];
    }
  }

  for (int thisRow = 0; thisRow <= 7; thisRow++) {
    NextFrame[thisRow][11] = 0;
  }

  NextFrame[PlottingValue][11] = 1;
  MakeAxis();
  
  for (int thisRow = 0; thisRow <= 7; thisRow++) {
    for (int thisColumn = 0; thisColumn <= 11; thisColumn++) {
      CurrentFrame[thisRow][thisColumn] = NextFrame[thisRow][thisColumn];
    }
  }
}
```