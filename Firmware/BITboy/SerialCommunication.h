
void ConfigSerialCom () {
  Serial.begin(115200);
  Serial.print("BITboy Interface Version ");
  Serial.println(version);
  Serial.println("Analog In [V], Analog Out [V], Digital In [V], Digital Out [V]");
}

// Divider for Serial Comm ", "
void SerialCom(int SerialComMode, float InputData, int OutputData) {
  if (SerialComMode == 0) {//Digital Out Constant
    int SerialOutputData = OutputData;
    Serial.print("Digital_Out_Constant[V]:");
    Serial.println(SerialOutputData);
    
  } else if (SerialComMode == 1) {//Analog Out Constant
      int SerialOutputData = OutputData;
      Serial.print("Analog_Out_Constant[V]:");
      Serial.println(SerialOutputData);

  } else if (SerialComMode == 2 || SerialComMode == 6) {//Digital In
      int SerialOutputData = InputData;
      Serial.print("Digital_In[V]:");
      Serial.println(SerialOutputData);

  } else if (SerialComMode == 3 || SerialComMode == 7) {//Analog In
      float SerialOutputData = InputData;
      Serial.print("Analog_In[V]:");
      Serial.println(SerialOutputData);

  } else if (SerialComMode == 4) {//Digital Out Pulse
      int SerialOutputData = OutputData;
      Serial.print("Digital_Out_Pulse[V]:");
      Serial.println(SerialOutputData);

  } else if (SerialComMode == 5) {//Analog Out Pulse
      int SerialOutputData = OutputData;
      Serial.print("Analog_Out_Pulse[V]:");
      Serial.println(SerialOutputData);


  }
}