## Exercises Easy

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

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

digitalWrite(pin, value)
//pin: Arduino-Pinnummer.
//value: HIGH or LOW.

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

### 3. Write Analog or Digital Signals and Test it on the Oscilloscope

```C
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

//Useful functions for this exercise:

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

digitalWrite(pin, value)
//pin: Arduino-Pinnummer.
//value: HIGH or LOW.

analogWrite(pin, value)
//pin: the Arduino pin to write to. Allowed data types: int.
//value: the duty cycle: between 0 (always off) and 255 (always on). Allowed data types: int.

```

[Here you will find a possible solution](Exercise_Solutions/01_Easy/03_Write_Analog_Digital_Signals.md)

### 4. Plot an Image on the LED Matrix (or display an animation if you feel like it)

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

[Here you will find a simple solution](Exercise_Solutions/01_Easy/04_Make_LED_Matrix_Image.md)

[Check out this link if you want to know how to play a more complex Animation ](https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/)