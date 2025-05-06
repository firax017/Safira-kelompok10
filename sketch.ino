#include <LiquidCrystal_I2C.h> //Library untuk mengontrol LCD 12C
#include <DHT.h> //Library untuk menggunakan sensor DHT
#define DHTPIN 8
#define DHTTYPE DHT22
DHT dht (DHTPIN, DHTTYPE); //Membuat Objek bernama 'dht' untuk mengakses sensor
LiquidCrystal_I2C lcd(0x27, 16, 2); // ini objek 'lcd' untuk LCD alamat 12C 0x27, 16 kolom 2 baris

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Mengaktifkan komunikasi serial monitor dengan rate 9600 
  Serial.println("Project Kelompok 10"); //Menampilkan preload saat meRUN simulator
  lcd.begin(16, 2); //Memulai LCD dengan ukuran 16x2 
  dht.begin(); //Memulai sensor DHT22
  pinMode(13, OUTPUT); // Menjadikan pin 13 sebagai output (LED indikator kipas)
}

void loop()  {
  // code utama
  float t = dht.readTemperature(); //Membaca suhu(dalam celsius)
  float h = dht.readHumidity(); //Membaca kelembaban
  delay(500); //Waktu tunggu 0,5 detik sebelum membaca ulang

  if(t>30){
    digitalWrite(13, HIGH); //nyalakan kipas atau LED
  }
  else {
    digitalWrite(13, LOW); //matikan kipas atau LED 
  }
  //menampilkan di lcd 
  lcd.setCursor(0,0); //Baris pertama
  lcd.println("Suhu :");
  lcd.println(t);
  lcd.println(" C");
  lcd.setCursor(0,1); //Baris kedua
  lcd.println("Kelembaban :");
  lcd.println(h);
  lcd.println(" %");

  //Menampilkan di serial monitor
  Serial.println("Suhu : ");
  Serial.println(t);
  Serial.println(" C");
  Serial.println("Kelembaban : ");
  Serial.println(h);
  Serial.println(" %");
}
