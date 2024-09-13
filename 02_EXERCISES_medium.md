# Exercises

Serial Printing is you most powerful debugging tool when coding your device.

You will have to install the Arudino IDE and copy paste the code from here to the sketch. Then compile and upload.

[Download Arduino IDE](https://www.arduino.cc/en/software)



Sometimes the Arduino requires an additional driver installation. 

Easy and medium are thought in a way that you can make each individual function work individually. Each excersise can be an individual code. You can try to make modules while coding thisn. And then in hard the task is to bring the individual functions to gether and make them work all at once.

Be careful, do not use more than 5V on the BNCs, since we do not have an überspannungs schutz.

Useful Resources
--------------------
Here you can find a complete language reference, built in functions, variable types and structural operators:

[Arduino Language Reference](https://www.arduino.cc/reference/en/)

pullup and pulldown resistors
Rotary encoder example
Continuity check example
DIP switch example

Arduino Function Overview for How to make them nicely interactive

## Exercises Medium

### 1. Read an Analog or Digital Signal and Plot it via Serial Communication

For this exercise you will have to use the Serial Plotter and/or Serial Monitor of the Arduino IDE.

Tools > Serial Plotter

Tools > Serial Monitor

Life hack: Serial plotting is a very poferful debugging tool and coding help!

```C
void setup() {
  // put your setup code here, to run once:
  // use semicolons after each line!

}

void loop() {
  // put your main code here, to run repeatedly:
  // use semicolons after each line!

}

//Useful functions for this exercise:

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

analogReadResolution(bits);
//Can be set to 10 or 13 bits for read resolution (0-1023 for 10 bits or 0-4095 for 12 bits).

analogRead(pin)
//pin: the name of the analog input pin to read from.
//Returns the analog reading on the pin, limited to the resolution of the analog to digital converter (0-1023 for 10 bits or 0-4095 for 12 bits).
//Data type: int.

digitalRead(pin)
//pin: the Arduino pin number you want to read
// Returns HIGH or LOW

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

delay(ms)
//ms: the number of milliseconds to pause. Allowed data types: unsigned long.
```

[Here you will find a possible solution](Exercise_Solutions/02_Medium/01_Analog_Digital_Read_Serial.md)

### 2. Implement the Continuity Check

### 3. Implement the DIP Switch

### 4. Implement the Rotary Encoder with Button

### 5. Implement the Rotary Encoder with Button

## Hard

### 1. Read an Analog or Digital and Plot it on the LED Matrix Display

### 2. Combine All Modules and Make them Work Together