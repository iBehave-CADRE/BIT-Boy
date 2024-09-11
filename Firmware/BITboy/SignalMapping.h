//Display
#define DisplayMinX 11
#define DisplayMaxX 0

#define DisplayMinY 0
#define DisplayMaxY 7

//Analog IO for Read Resolution of 10 range of 0-1023 and for resolution of 12 0-4095
#define AnalogReadResolution 10

#define AnalogInMin 0
#define AnalogInMax 1023
#define AnalogOutMin 0
#define AnalogOutMax 255

//Digital IO
#define DigitalIOMin LOW
#define DigitalIOMax HIGH 

//Rotary Encoder
#define RotaryEncoderMin 0
#define RotaryEncoderMax 7

// Map Float function for mapping floating values
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x-in_min) * (out_max-out_min) / (in_max - in_min) + out_min;
}