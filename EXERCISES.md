# Exercises

Serial Printing is you most powerful debugging tool when coding your device.

You will have to install the Arudino IDE and copy paste the code from here to the sketch. Then compile and upload.

Sometimes the Arduino requires an additional driver installation

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

### 2. Make the Buzzer Beep or Play a Melody

### 3. Plot an Image on the LED Matrix

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






