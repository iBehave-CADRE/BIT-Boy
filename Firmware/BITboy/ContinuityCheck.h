//Continuity Check
#define ContinuityPin A3

int ContinuityStatus = 0;


void ConfigContinuityCheck() {
  pinMode(ContinuityPin, INPUT);
}

void ContinuityCheck() {
  ContinuityStatus = digitalRead(ContinuityPin);
  //delay(10);
  //ContinuityStatus = digitalRead(ContinuityPin); if analog read the values need to be dumped because of DAC switching and multiplexing but did not work for me

  if (ContinuityStatus == HIGH) {
    tone(BuzzerPin, NOTE_D7);
    
  } else if (ContinuityStatus == LOW) {
    noTone(BuzzerPin);

  }
}