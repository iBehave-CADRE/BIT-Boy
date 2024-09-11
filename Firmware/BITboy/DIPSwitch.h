//DIP Switch
#define DIPSwitch1 6
#define DIPSwitch2 7
#define DIPSwitch3 8
#define DIPSwitchPositions 3

#define ON LOW
#define OFF HIGH

#define Digital " Digital"
#define Analog " Analog"
#define Out " Output"
#define In " Input"
#define Constant " Constant"
#define Pulse " Pulse"

//Definition of different execution modes
#define DOCmode 0
#define AOCmode 1
#define DI1mode 2
#define AI1mode 3
#define DOPmode 4
#define AOPmode 5
#define DI2mode 6
#define AI2mode 7

bool SettingsChange = false;
int DIPSwitchSetting = 0;
int DIPPinState = 0;
char SettingsText[25];

const int DIPSwitchPins[3] = {DIPSwitch1, DIPSwitch2, DIPSwitch3};

int ReadDIPSwitchSettings() {
  for (int i = 0; i < DIPSwitchPositions; i++) {
    DIPPinState = digitalRead(DIPSwitchPins[i]);

    if (DIPPinState == ON)
      DIPSwitchSetting |= 1 << (DIPSwitchPositions - i - 1);
  }

  if (DIPSwitchSetting == 0) {
    strcat(SettingsText, Digital);
    strcat(SettingsText, Out);
    strcat(SettingsText, Constant);
  } else if (DIPSwitchSetting == 1) {
    strcat(SettingsText, Analog);
    strcat(SettingsText, Out);
    strcat(SettingsText, Constant);
  } else if (DIPSwitchSetting == 2 || DIPSwitchSetting == 6) {
    strcat(SettingsText, Digital);
    strcat(SettingsText, In);
  } else if (DIPSwitchSetting == 3 || DIPSwitchSetting == 7) {
    strcat(SettingsText, Analog);
    strcat(SettingsText, In);
  } else if (DIPSwitchSetting == 4) {
    strcat(SettingsText, Digital);
    strcat(SettingsText, Out);
    strcat(SettingsText, Pulse);
  } else if (DIPSwitchSetting == 5) {
    strcat(SettingsText, Analog);
    strcat(SettingsText, Out);
    strcat(SettingsText, Pulse);
  }

  Serial.print("BITboy setting: ");
  Serial.print(DIPSwitchSetting);
  Serial.println(SettingsText);

  return DIPSwitchSetting;
}

void ConfigDIPSwitch() {
  for (int i = 0; i < DIPSwitchPositions; i++) {
    pinMode(DIPSwitchPins[i], INPUT_PULLUP);
  }
}