


DIP switch example



## Exercises Medium

### 1. Read an Analog or Digital Signal and Plot it via Serial Communication

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
//Returns the analog reading on the pin.
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

The continuity check allows you to test whether two parts are connected between two pins. If there is continuity, 5V can flow to pin A3 and pull it to a HIGH state. The pulldown resistor ensures a stable reading of the LOW state. Write a code that makes the buzzer beep when there is continuity between the 5V pin and the A3 pin. You can use A3 as a digital pin for simplicity.

```C++

void setup() {

}

void loop() {

}

//Useful functions for this exercise:

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

digitalRead(pin)
//pin: the Arduino pin number you want to read
// Returns HIGH or LOW

tone(pin, frequency)
tone(pin, frequency, duration)
//pin: the Arduino pin on which to generate the tone.
//frequency: the frequency of the tone in hertz. Allowed data types: unsigned int.
//duration: the duration of the tone in milliseconds (optional). Allowed data types: unsigned long.

noTone(pin)
//pin: the Arduino pin on which to stop generating the tone

//You can use an if/else if loop for this task
if (condition1) {
  // do Thing A
}
else if (condition2) {
  // do Thing B
}
else {
  // do Thing C
}
//condition: a boolean expression (i.e., can be true or false).

delay(ms)
//ms: the number of milliseconds to pause. Allowed data types: unsigned long.
```

[Here you will find a possible solution](Exercise_Solutions/02_Medium/02_Continuity_Check.md)

[Here you find information about using pullup and pulldown resistors](https://arduinogetstarted.com/faq/arduino-pull-up-pull-down-resistor)



### 3. Implement the DIP Switch

The DIP switch is used to set the BITBoy's function when powered on. Its state is read out to assign a preset when booting the device. You can implement the code in the setup section to only read it once and serial print the mode. Resetting will allow a new readout.

```C++

void setup() {

}

void loop() {

}

//Useful functions for this exercise:

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

digitalRead(pin)
//pin: the Arduino pin number you want to read
// Returns HIGH or LOW

for (initialization; condition; increment) {
  // statement(s);
}
//initialization: happens first and exactly once.
//condition: each time through the loop, condition is tested; if it’s true, the statement block, and the increment is executed, then the condition is tested again. When the condition becomes false, the loop ends.
//increment: executed each time through the loop when condition is true.

strcat(string1, string2);
//Concatenates string1 with string1. Input tye char.
//Returns concatenated string char.

return value;
//value: Allowed data types: any variable or constant type.

//You can use an if/else if loop for this task
if (condition1) {
  // do Thing A
}
else if (condition2) {
  // do Thing B
}
else {
  // do Thing C
}
//condition: a boolean expression (i.e., can be true or false).

Serial.begin(speed)
//Serial: serial port object.
//speed: in bits per second (baud). Allowed data types: long.

Serial.print(val)
//Serial: serial port object.
//val: the value to print. Allowed data types: any data type.

Serial.println(val) //Serial println adds characters for printing in a new line
//Serial: serial port object.
//val: the value to print. Allowed data types: any data type.
```

[Here you will find a possible solution](Exercise_Solutions/02_Medium/03_DIP_Switch.md)

[Here you find more information about DIP switches](https://arduinogetstarted.com/tutorials/arduino-dip-switch)



### 4. Implement the Rotary Encoder with Button

```C++
void setup() {
  
}


void loop() {

}

pinMode(pin, mode)
//pin: the Arduino pin number to set the mode of.
//mode: INPUT, OUTPUT, or INPUT_PULLUP.

digitalRead(pin)
//pin: the Arduino pin number you want to read
// Returns HIGH or LOW

digitalWrite(pin, value)
//pin: Arduino-Pinnummer.
//value: HIGH or LOW.

return value;
//value: Allowed data types: any variable or constant type.

//You can use an if/else if loop for this task
if (condition1) {
  // do Thing A
}
else if (condition2) {
  // do Thing B
}
else {
  // do Thing C
}

millis()
//Returns the number of milliseconds passed since the Arduino board began running the current program. This number will overflow (go back to zero), after approximately 50 days.

Serial.begin(speed)
//Serial: serial port object.
//speed: in bits per second (baud). Allowed data types: long.

Serial.print(val)
//Serial: serial port object.
//val: the value to print. Allowed data types: any data type.

Serial.println(val) //Serial println adds characters for printing in a new line
//Serial: serial port object.
//val: the value to print. Allowed data types: any data type.


attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)
//interrupt: the number of the interrupt. Allowed data types: int.
//pin: the Arduino pin number.
//ISR: the ISR to call when the interrupt occurs; this function must take no parameters and return nothing. This function is sometimes referred to as an interrupt service routine.
//mode: defines when the interrupt should be triggered. Four constants are predefined as valid values: LOW, CHANGE, RISING, FALLING.
```

[Here you will find a possible solution](Exercise_Solutions/02_Medium/04_Rotary_Button.md)

[Here you find information about attaching an interrupt](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)

[Here you find information rotary encoders](https://arduinogetstarted.com/tutorials/arduino-rotary-encoder)
