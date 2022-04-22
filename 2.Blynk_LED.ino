/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// Copy Auth Token จาก Email ที่ได้มาจาก Blynk App
char auth[] = "Please input your Auth Token";
// ชื่อ Network Wifi
char ssid[] = "Input name wifi";
// รหัสผ่าน
char pass[] = "Input Password wifi";

void setup()
{
  // Debug console
  Serial.begin(9600);
  // ตัง้ค่าเริ่มต้นให้เชื่อมต่อ กับ เครือข่าย wifi
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  // เริ่มต้นการทำงานบน Blynk App
  Blynk.run();
}
