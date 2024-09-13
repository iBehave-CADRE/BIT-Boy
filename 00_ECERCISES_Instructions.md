# Exercises

We prepared a collection of exercises as a guide throuhg different communication channels of laboratory instruments: digital signals, analog signals and serial communication. These exercises are with increasing difficulty from easy, medium to hard. First, individual functional modules of the device will be adressed, later they will be combined for interoperability. Working throuhg them in a sequential manner will allow to built up know how to the point of generating the complete firmware. 

This course will therefore provide essential knowledge for implementing and trouble shooting experimental setups for neuroscience. As a bonus, the resulting device will be a handy companion for future laboratory projects.

You will have to install the Arudino IDE and copy paste the code from GitHub to the sketch area in the GUI.

[Download Arduino IDE](https://www.arduino.cc/en/software)

In some cases Arduino IDE will require installation of additional drivers for the Arduino UNO rev4 board. This will happen automatically. Connecting the Arduino via USB will allow to select the corresponding serial port, compile and upload the sketch code.

General disclaimer: Our BITboy is designed to work in a range of 0-5V and will take damage if connected to higher loads. Therefore, please be careful. We are planning a future version with overvoltage protection.

Useful Resources
--------------------

Here you can find a complete language reference, built in functions, variable types and structural operators:

[Arduino Language Reference](https://www.arduino.cc/reference/en/)

To complete all exercises, you will have to master functions in Arduino. It can be used to create custom functions but also to pass parameters along and return data:

[Using functions in a sketch](https://docs.arduino.cc/learn/programming/functions/)


Serial Printing is your most powerful debugging tool when coding your device:

[Arduino serial communication](https://www.arduino.cc/reference/en/language/functions/communication/serial/)

In some cases you will have to use the Serial Plotter  and/or Serial Monitor of the Arduino IDE:

Tools > Serial Plotter

Tools > Serial Monitor

## Exercises Easy

Here you can make the individual module work and get some first exposure.

[Go To Exercises Easy](01_EXERCISES_easy.md)

### 1. Make the LED Blink

### 2. Make the Buzzer Beep (or Play a Melody if you feel like it)

### 3. Write Analog or Digital Signals and Test them on the Oscilloscope

### 4. Plot an Image on the LED Matrix (or display an animation if you feel like it)

## Exercises Medium

Here modues with more complex functionality are implemented and in some cases integrated.

[Go To Exercises Medium](02_EXERCISES_medium.md)

### 1. Read an Analog or Digital Signal and Plot it via Serial Communication

### 2. Implement the Continuity Check

### 3. Implement the DIP Switch

### 4. Implement the Rotary Encoder with Button

## Exercises Hard

At this point you will build upon the previous exercises and make all functions work together. Here it will be essential to implement Arduino functions with returns for global interacting modules. For example, each fuctional module of the device can be handled as an indepenent library.

You can save code in a separate .h file and include it as follows:

```C++
#include "DIPSwitch.h"
```

In the upper right corner of the Arduino IDE click on "..." and select new tab. You can rename it to DIPSwitch.h to generate an external file with additional code.

This will allow you to create configuration functions for each module and include them in void setup of the main sketch file. In addition zou can create functions for void loop that pass on parameters via return.

[Go To Exercises Hard](03_EXERCISES_hard.md)

### 1. Read an Analog or Digital and Plot it on the LED Matrix Display

### 2. Combine All Modules and Make them Work Together
