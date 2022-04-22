/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// Copy Auth Token จาก Email ที่ได้มาจาก Blynk App
char auth[] = "HY5aH08FIKQPVNNln_GZgqUFUg4lekip";
// ชื่อ Network Wifi
char ssid[] = "Yellow_Kaewarpa_2.4G";
// รหัสผ่าน
char pass[] = "0817342981";

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
