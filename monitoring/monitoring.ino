// include library untuk wifi
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//konfigurasi wifi
const char* ssid = "A71";
const char* password = "zxzxzxzx";

// alamat IP komputer server
String IPAddr = "192.168.30.4";


// siapkan objek client
WiFiClient NodeMCU;

// siapkan pin untuk LED
#define pinLED 5 // GPIO5 = D1

void setup() {
  // Aktifkan Serial
  Serial.begin(9600);
  // mode pin LED
  pinMode (pinLED, OUTPUT);
  // koneksi ke WiFi
  WiFi.begin(ssid, password);
  // uji status koneksi wifi
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(pinLED, LOW);
    delay(500);
  }
  // apabila terkoneksi, nyalakan lampu LED
  digitalWrite(pinLED, HIGH);
}

void loop() {
  // pastikan koneksi ke web server berhasil
  if(!NodeMCU.connect(IPAddr, 80)) // 80 adalah port apache
  {
    Serial.println("Gagal koneksi ke web server");
    return ;
  }

  int sensorValue = analogRead(0);
  //mapping nilai sensor
  int kekeruhan = map(sensorValue, 0, 750, 0, 100);
  //tampilkan nilai diserial monitor
  Serial.println(kekeruhan);

  // kirim data ke database / aplikasi website
  HTTPClient http;
  String url="http://"+IPAddr+"/IOT/data.php?sensor=" + String(kekeruhan); // IOT pada url ini adalah folder pada server atau htdocs

  // http://localhost/IOT/data.php?sensor=45 ini adalah contoh contoh url yang akan dikirimkan ke server

  // eksekusi link url
  http.begin(NodeMCU, url);
  // mode get
  http.GET();
  // akhiri proses kirim data
  http.end();
  delay(1000);

}
