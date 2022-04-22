void setup() {
  pinMode(D7, OUTPUT); // D7 อักษรตัวใหญ่
}
void loop() {
  digitalWrite(D7, HIGH); //LED On
  delay(200);             // หน่วงเวลารอ
  digitalWrite(D7, LOW); //LED Off
  delay(300);            // หน่วงเวลารอ
}
