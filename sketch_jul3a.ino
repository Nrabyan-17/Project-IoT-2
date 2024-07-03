#include <Wire.h>
#include <ESP8266WiFi.h>
#define Buzzer D0
#define trigPin D1
#define echoPin D2

long duration;
int distance = 0;

void setup() {

pinMode(trigPin, OUTPUT); // Setting triggerPin sebagai output
pinMode(echoPin, INPUT); // Setting echoPin sebagai input
pinMode(Buzzer, OUTPUT); // Setting Buzzer sebagai output
Serial.begin(9600); // Setting kecepatan pengiriman serail Monitor

}

void loop() {

digitalWrite(trigPin, HIGH); //Mengaktifkan sensor ultrasonic
delayMicroseconds(10); // selama 10 microseconds
digitalWrite(trigPin, LOW); // Mematikan sensor ultrasonic
duration = pulseIn(echoPin, HIGH); // baca rentan waktu dari trigPin High sampai echoPin High
distance = duration * 0.034/2; // Konversi selang waktu ke CM

if (distance > 10) { // hanya menampilkan jarak jika jaraknya kurang dari 300 cm/ 3 meter
  Serial.println(distance); // Kirim data jarak ke PC
  digitalWrite(Buzzer, LOW);

} else if(distance < 10 && distance >= 8) {
  Serial.println(distance);
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
  delay(500);

} else if (distance < 8 && distance >= 6) {

Serial.println(distance);
digitalWrite(Buzzer, HIGH);
delay(100);
digitalWrite(Buzzer, LOW);
delay(100);

} else if (distance < 6 && distance >= 4) {

  Serial.println(distance);
  digitalWrite(Buzzer, HIGH);
  delay(50);
  digitalWrite(Buzzer, LOW);
  delay(50);

} else if (distance < 4) {

  Serial.println(distance); // Kirim data jarak ke PC
  digitalWrite(Buzzer, HIGH);
  delay(50);
} 

}

 