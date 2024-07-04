#include <HardwareSerial.h>

HardwareSerial GPS(1);

void setup() {
  Serial.begin(115200);
  GPS.begin(9600, SERIAL_8N1, 16, 17); // Adjust RX and TX pins as needed

  delay(1000);
  
  // Check the current rate
  checkRate();
  
  // Set the rate to 10Hz
  setRate10Hz();
  
  // Check the new rate
  checkRate();
}

void loop() {
  if (GPS.available()) {
    Serial.write(GPS.read());
  }
}

void sendCommand(const uint8_t* cmd, size_t len) {
  GPS.write(cmd, len);
  delay(200); // Delay for command to process
  while (GPS.available()) {
    Serial.write(GPS.read());
  }
}

void checkRate() {
  const uint8_t checkRateCmd[] = { 0xB5, 0x62, 0x06, 0x08, 0x00, 0x00, 0x0E, 0x30 };
  sendCommand(checkRateCmd, sizeof(checkRateCmd));
}

void setRate10Hz() {
  const uint8_t setRate10HzCmd[] = { 0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0x64, 0x00, 0x01, 0x00, 0x01, 0x00, 0x7A, 0x12 };
  sendCommand(setRate10HzCmd, sizeof(setRate10HzCmd));
  
  const uint8_t saveConfigCmd[] = { 0xB5, 0x62, 0x06, 0x09, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x31, 0xBF };
  sendCommand(saveConfigCmd, sizeof(saveConfigCmd));
}
