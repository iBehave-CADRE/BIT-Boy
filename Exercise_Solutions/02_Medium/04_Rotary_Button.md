```C++
#define version "1"

//LED for signal indication
#define LEDPin D12

//Rotary Encoder Definitions
#define encAPin D3
#define encBPin D4
#define encButtonPin D2

#define FW 1 //code for forward direction rotation
#define BW -1 //same for backwards

int ButtonState = 0;
volatile int Direction = 0;
volatile byte RotationDetected = false;
volatile int counter = 0;

volatile byte ButtonPushDetected = false;

volatile unsigned long last_time;  // for debouncing

void DetectButtonPush() {
  ButtonPushDetected = true;
}

void DetectRotation() {
  if ((millis() - last_time) < 50)  // debounce time is 50ms
    return;
  RotationDetected = true;
  if (digitalRead(encAPin) == digitalRead(encBPin)) {
    Direction = BW;
    if (counter >= 1) {
      counter--;
    }
  } else {
    Direction = FW;
    if (counter <= 6) {
      counter++;
      }
    }
  last_time = millis();
}

void setup() {
  Serial.begin(115200);
  Serial.print("BITboy Interface Version ");
  Serial.println(version);
  pinMode(encAPin, INPUT_PULLUP);
  pinMode(encBPin, INPUT_PULLUP);
  pinMode(encButtonPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
  //Attach an Interrupt to the Rotary Encoder and Button Pins
  attachInterrupt(digitalPinToInterrupt(encButtonPin), DetectButtonPush, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encAPin), DetectRotation, FALLING);
}


void loop() {
  RotationAction();
  ButtonAction();
}

void RotationAction() {
  if (RotationDetected == true) {
    Serial.print("Direction: ");
    Serial.print(Direction);
    Serial.print(" Counter: ");
    Serial.println(counter);
    RotationDetected = !RotationDetected;
  } else if (RotationDetected == false) {
    return;
  }
}

void ButtonAction() {
  ButtonState = digitalRead(encButtonPin);
    if (ButtonState == HIGH) {
      digitalWrite(LEDPin, LOW);
      //Serial.println("button released");
    } else {
      digitalWrite(LEDPin, HIGH);
      //Serial.println("button pushed");
    }
}
```