```C++
#define ledPin 12 // LED connected to digital pin 13, we define it as a constant value here.

//Instead of defining a constant value, one can also define a variable.

//int ledPin = 12;              

void setup() {
  pinMode(ledPin, OUTPUT);    // sets the digital pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // sets the LED on
  delay(1000);                // waits for a second
  digitalWrite(ledPin, LOW);  // sets the LED off
  delay(1000);                // waits for a second
}
```