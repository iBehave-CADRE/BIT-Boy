//Buzzer 
#define BuzzerPin D11

//#define NOTE_D7  2349

void ConfigBuzzer() {
    pinMode(BuzzerPin, OUTPUT);
    tone(BuzzerPin, NOTE_D7, 100);
    delay(100);
    noTone(BuzzerPin);
}