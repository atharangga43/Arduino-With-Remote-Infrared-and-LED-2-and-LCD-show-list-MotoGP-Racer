#include <Arduino.h>

#include <Arduino.h>
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

// --- Konfigurasi Pin ---
const int RECV_PIN = 2;

// --- Nilai command tombol remote ---
#define CMD_NEXT 0x30    // Tombol 1 untuk Maju
#define CMD_PREV 0x18    // Tombol 2 untuk Mundur

// --- Inisialisasi LCD ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Data Pembalap ---
struct Pembalap {
  String tim;
  String nama;
};

Pembalap daftarPembalap[5] = {
  {"Ducati Lenovo", "F. Bagnaia"},
  {"Repsol Honda", "Marc Marquez"},
  {"Monster Yamaha", "F. Quartararo"},
  {"Red Bull KTM", "Brad Binder"},
  {"Aprilia Racing", "Aleix Espargaro"}
};

int currentIndex = -1; // -1 berarti layar awal sebelum tombol ditekan

void tampilkanPembalap(int index) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(daftarPembalap[index].tim);
  lcd.setCursor(0, 1);
  lcd.print(daftarPembalap[index].nama);
  
  // Debug ke Serial Monitor
  Serial.print("Menampilkan: ");
  Serial.println(daftarPembalap[index].nama);
}

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  
  lcd.init();
  lcd.backlight();
  
  // Tampilan awal
  lcd.setCursor(0, 0);
  lcd.print("Tugas: Daftar");
  lcd.setCursor(0, 1);
  lcd.print("Pembalap MotoGP");
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;

    // Logika Tombol 1 (Next / Maju)
    if (command == CMD_NEXT) {
      currentIndex++;
      if (currentIndex > 4) { 
        currentIndex = 0; // Kembali ke awal jika sudah di akhir
      }
      tampilkanPembalap(currentIndex);
    } 
    
    // Logika Tombol 2 (Previous / Mundur)
    else if (command == CMD_PREV) {
      currentIndex--;
      if (currentIndex < 0) {
        currentIndex = 4; // Lari ke akhir jika mundur dari posisi awal
      }
      tampilkanPembalap(currentIndex);
    }

    IrReceiver.resume(); 
  }
}