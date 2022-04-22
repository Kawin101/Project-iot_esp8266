const int ledPin = D7; // กำหนดตัวแปรขาที่ต่อกับ LED (const คือค่าคงที่)
int timeOn = 500; // กำหนดค่าระยะเวลาให้ LED ติด
int timeOff = 600;  // กำหนดค่าระยะเวลาให้ LED ดับ
void setup() {
  Serial.begin(9600); // เริ่มต้นการสื่อสาร
  pinMode(ledPin, OUTPUT); // ตั้งค่าให้ขา ledPin เป็นเอ้าต์พุต
  pinMode(LED_BUILTIN, OUTPUT); // ตั้งค่าให้ขา เป็นเอ้าต์พุต
  Serial.println(" LED On/Off "); // ส่งข้อมูลไปที่หน้าต่าง Serial Monitor (Print ค่า String)
  Serial.println(timeOn + timeOff); // ส่งข้อมูลไปที่หน้าต่าง Serial Monitor (Print ผลการคำนวณตัวเลข)
}
void loop() {
  digitalWrite(ledPin, 0); //เอ้าต์พุตขา ledPin เป็น 0 หลอด LED ติด
  digitalWrite(LED_BUILTIN, LOW); //ตั้งค่าให้ขา Built-in LED ติด
  Serial.println("LED On"); // Print สถานะ LED On ที่หน้าต่าง Serial
  delay(timeOn); //หน่วงเวลารอ 500 ms หรือ 0.5 วินาที
  digitalWrite(LED_BUILTIN, HIGH); //ตั้งค่าให้ขา Built-in LED ดับ
  digitalWrite(ledPin, 1); //เอ้าต์พุตขา ledPin เป็น 1 หลอด LED ดับ
  Serial.println("LED Off"); // Print สถานะ LED Off ที่หน้าต่าง Serial
  delay(timeOff); //หน่วงเวลารอ 600 ms หรือ 0.6 วินาที
}
