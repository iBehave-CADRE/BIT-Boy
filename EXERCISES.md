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
Buzzer example
LED example
DIP switch example
Reset button example
Power via Battery example
Continuity check example
BNC example

## Easy

### 1. Make the LED Blink

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

digitalWrite(pin, value)
//pin: Arduino-Pinnummer.
//value: HIGH or LOW.

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

delay(ms)
//ms: the number of milliseconds to pause. Allowed data types: unsigned long.
```

[Here you will find a possible solution](Exercise_Solutions/01_Easy/01_Make_LED_Blink.md)

### 2. Make the Buzzer Beep (or Play a Melody if you feel like it)

```C
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

//Useful functions for this exercise:

tone(pin, frequency)
tone(pin, frequency, duration)
//pin: the Arduino pin on which to generate the tone.
//frequency: the frequency of the tone in hertz. Allowed data types: unsigned int.
//duration: the duration of the tone in milliseconds (optional). Allowed data types: unsigned long.

noTone(pin)
//pin: the Arduino pin on which to stop generating the tone

delay(ms)
//ms: the number of milliseconds to pause. Allowed data types: unsigned long.
```

[Here you will find a possible solution](Exercise_Solutions/01_Easy/02_Make_Buzzer_Beep.md)

[Check out this link if you want to know how to play a melody](https://docs.arduino.cc/built-in-examples/digital/toneMelody/)

### 3. Plot an Image on the LED Matrix (or display an animation if you feel like it)

```C
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

//Useful functions for this exercise:

//You will have to include the LED matrix library
#include "Arduino_LED_Matrix.h"

Serial.begin(speed)
//speed: in bits per second (baud). Allowed data types: long.

//start the LED Matrix by adding this line in void setup:
matrix.begin();

//This is how you can make a two-dimensional array of bytes to encode an image:
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

//This is how you can render and display your two-dimensional array as an image:
matrix.renderBitmap(BootScreen, 8, 12);

```

[More about arrays here](https://www.arduino.cc/reference/en/language/variables/data-types/array/)

[Here you will find a simple solution](Exercise_Solutions/01_Easy/03_Make_LED_Matrix_Image.md)

[Check out this link if you want to know how to play a more complex Animation ](https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/)

### 4. Write an Analog or Digital Signal

## Medium

### 1. Read an Analog or Digital Signal and Plot it via Serial Communication

### 2. Implement the Continuity Check

### 3. Implement the DIP Switch

### 4. Implement the Rotary Encoder with Button

### 5. Implement the Rotary Encoder with Button

## Hard

### 1. Read an Analog or Digital and Plot it on the LED Matrix Display

### 2. Combine All Modules and Make them Work Together






