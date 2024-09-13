```C++
//BNC Port Definitions
#define version "1"

#define AnalogDataPin A0
#define DigitalDataPin D5   

//Initialising variables for later use in the script
int MeasuredDigitalInput;
int MeasuredAnalogInput;

void setup() {
  //Setting the resolution to 12 will read in a range of 0-4095, while setting to 10 will read 0-1023
  analogReadResolution(12);
  pinMode(AnalogDataPin, INPUT);
  //Test and see what happens if you use INPUT_PULLUP here...
  pinMode(DigitalDataPin, INPUT);
  //Start serial communication
  Serial.begin(115200);
  Serial.print("BITboy Interface Version ");
  Serial.println(version);
}

void loop() {
  //Reaging analog input and mapping it to 5V for serial print with accurate units.
  MeasuredAnalogInput = map(analogRead(AnalogDataPin), 0, 4095, 0, 5);
  MeasuredAnalogInput = constrain(MeasuredAnalogInput, 0, 5);

  //Reaging digital input and mapping it to 5V for serial print with accurate units.
  MeasuredDigitalInput = map(digitalRead(DigitalDataPin), 0, 1, 0, 5);
  MeasuredDigitalInput = constrain(MeasuredDigitalInput, 0, 5);

  delay(200);

  //Serial printing of analog signal. The first print will allow to name the variable in the serial plotter.
  Serial.print("Analog_In[V]:");
  Serial.println(MeasuredAnalogInput);
  //Serial printing of digital signal. The first print will allow to distinguish the secont variable from the first print in the plotter.
  Serial.print("Digital_In[V]:");
  Serial.println(MeasuredDigitalInput);
}
```