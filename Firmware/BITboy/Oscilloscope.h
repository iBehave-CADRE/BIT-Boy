//would be cool if I could set the time axis when in input mode and reading signals
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

void MakeAxis(){
  for (int thisRow = 0; thisRow <= 7; thisRow++) {
    NextFrame[thisRow][0] = 1;
  }
}

ArduinoLEDMatrix matrix;


void ConfigOscilloscope(int PlottingMode) {
  matrix.begin();
  matrix.renderBitmap(BootScreen, 8, 12);
  //matrix.play(true);
  delay(1500);
  //matrix.play(false);
  //matrix.renderBitmap(CurrentFrame, 8, 12);
}

void calcNextFrame(int PlottingMode, int PlottingSignalInput, int PlottingSignalOutput) {
  int PlottingValue;
  if (PlottingMode == 2 || PlottingMode == 6  || PlottingMode == 3  || PlottingMode == 7) {
    //for all input modes 0 1 4 5
    PlottingValue = PlottingSignalInput;
  } else if (PlottingMode == 0 || PlottingMode == 1  || PlottingMode == 4  || PlottingMode == 5) {
    //for all output modes 2 6 3 7
    PlottingValue = PlottingSignalOutput;
  }

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



