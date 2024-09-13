```C++
#define AnalogPin A0

#define DigitalPin D5

void setup() {
  // put your setup code here, to run once:
  pinMode(AnalogPin, OUTPUT);
  pinMode(DigitalPin, OUTPUT):

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(AnalogPin, 155);
  digitalWrite(DigitalPin, HIGH);
  delay(1000);
  analogWrite(AnalogPin, 0);
  digitalWrite(DigitalPin, LOW);
  delay(1000);
}
```