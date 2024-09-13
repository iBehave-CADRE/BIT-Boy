## Exercises Hard

### 1. Read an Analog Signals and Plot it on the LED Matrix Display

```C++
void setup() {

}

void loop() {

}

//Useful functions for this exercise:

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

analogReadResolution(bits);
//Can be set to 10 or 13 bits for read resolution (0-1023 for 10 bits or 0-4095 for 12 bits).

analogRead(pin)
//pin: the name of the analog input pin to read from.
//Returns the analog reading on the pin.
//Data type: int.


map(value, fromLow, fromHigh, toLow, toHigh)
//value: the number to map.
//fromLow: the lower bound of the value’s current range.
//fromHigh: the upper bound of the value’s current range.
//toLow: the lower bound of the value’s target range.
//toHigh: the upper bound of the value’s target range.


constrain(x, a, b)
//x: the number to constrain Allowed data types: all data types.
//a: the lower end of the range. Allowed data types: all data types.
//b: the upper end of the range. Allowed data types: all data types.
//Returns x: if x is between a and b. /a: if x is less than a. /b: if x is greater than b.

Serial.begin(speed)
//Serial: serial port object.
//speed: in bits per second (baud). Allowed data types: long.

Serial.print(val)
//Serial: serial port object.
//val: the value to print. Allowed data types: any data type.

Serial.println(val) //Serial println adds characters for printing in a new line
//Serial: serial port object.
//val: the value to print. Allowed data types: any data type.

//You will have to include the LED matrix library
#include "Arduino_LED_Matrix.h"

Serial.begin(speed)
//speed: in bits per second (baud). Allowed data types: long.

//start the LED Matrix by adding this line in void setup:
matrix.begin();

//This is how you can make a two-dimensional array of bytes to encode an image:
uint8_t BootScreen[8][12] = {};

//This is how you can render and display your two-dimensional array as an image:
matrix.renderBitmap(BootScreen, 8, 12);

delay(ms)
//ms: the number of milliseconds to pause. Allowed data types: unsigned long.
```

[Here you will a possible solution](Exercise_Solutions/03_Hard/01_Plot_Analog.md)

### 2. Combine All Modules and Make them Work Together

At this point you will build upon the previous exercises and make all functions work together.

Here it will be essential to implement arduino functions with returns for global interacting modules.

For example, each fuctional module of the device can be handled as an indepenent library.

You can save code in a separate .h file and include it as follows:

#include "DIPSwitch.h"

In the upper right corner click on "..." and select new tab. You can rename it to DIPSwitch.h to generate an external file with additional code.

This will allow you to create configuration functions for each module and include them in the main code in void setup. In addition once can create functions to include in the loop that pass on parameters via return.

[Here you will find the finished firmware](Firmware\BITboy)
