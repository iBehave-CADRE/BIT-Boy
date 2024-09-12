```C++
//Defining the note D7
#define NOTE_D7  2349

//Buzzer pin is on D11
#define BuzzerPin D11

void setup() {
  // put your setup code here, to run once:
  // use semicolons after each line!
  pinMode(BuzzerPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  // use semicolons after each line!
  tone(BuzzerPin, NOTE_D7, 100);
  delay(100);
  noTone(BuzzerPin);
  delay(100);
}
```