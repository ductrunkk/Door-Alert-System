#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// Chân kết nối
#define PIR_PIN 2 // Cảm biến hồng ngoại E18-D80NK
#define RX_PIN 10 // RX của JQ6500
#define TX_PIN 11 // TX của JQ6500

// Giao tiếp với module MP3 JQ6500
SoftwareSerial mySerial(RX_PIN, TX_PIN);
DFRobotDFPlayerMini mp3;

void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);

  if (!mp3.begin(mySerial)) {
    Serial.println("Not find mp3");
    while (true);
  }

  Serial.println("MP3 ready");
  mp3.volume(25); // Đặt âm lượng (0-30)
}

void loop() {
  int motion = digitalRead(PIR_PIN);
  if (motion == LOW) { // Cảm biến phát hiện vật cản
    Serial.println("Có khách");
    mp3.play(1); // Phát file MP3 số 1 trên thẻ nhớ
    delay(3000); // Chờ để tránh lặp lại âm thanh quá nhanh
  }
}