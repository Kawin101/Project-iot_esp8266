//for more project visit www.blackkeyhole.com
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const int sensorpin = A0; //กำหนด ตัวแปร Pin ที่อ่านค่าบน Node MCU คือ A0
int sensorValue=0; //กำหนดตัวแปร เก็บค่า input จาก sensor
int outputValue=0; //กำหนดตัวแปร เก็บค่า Output จาก sensor

char auth[] = "HY5aH08FIKQPVNNln_GZgqUFUg4lekip";
char ssid[] = "Yellow_Kaewarpa_2.4G";
char pass[] = "0817342981";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  sensorValue=analogRead(sensorpin); // นำค่าจาก sensorValue ไปเปรียบเทียบ เพื่อสังการคำสั่งต่างๆ
  outputValue=map(sensorValue,0,1023,0,100); // ปรับสเกลค่าเซ็นเซอร์ จาก 0-1023 เป็น 0-100
  delay(1000); //หน่วงเวลา 1000 ms หรือ 1 วินาที
  
  if(outputValue>74) // ถ้าค่า มากกว่า 74 คือ ดินแห้ง ต้องรดน้ำ
  {
       Serial.println("water your plant"); // Print ข้อความ บน Serial
       Serial.print(outputValue); // Print ค่าที่อ่านได้จาก sensor 
       Blynk.notify("water your plant"); // Print ข้อความแจ้งเตือน บน Blynk
       delay(5000); //หน่วงเวลา 5000 ms หรือ 5 วินาที
  }
  else if(outputValue<45) // ถ้าค่า น้อยกว่า 45 คือ ดินชื้นพอสมควร ไม่ต้องรดน้ำเพิ่ม
  {
       Serial.println("soil is wet enough to water"); // Print ข้อความ บน Serial Monitor
       Serial.print(outputValue); // Print ค่าที่อ่านได้จาก sensor  บน Serial Monitor
       Blynk.notify("soil is wet enough to water"); // Print ข้อความแจ้งเตือน บน Blynk
       delay(5000); //หน่วงเวลา 5000 ms หรือ 5 วินาที
  }
  // ส่งข้อมูลเข้าไปยังขา input Virtual V1 บน Blynk App
  Blynk.virtualWrite(V1,outputValue);
  Blynk.run();
}
