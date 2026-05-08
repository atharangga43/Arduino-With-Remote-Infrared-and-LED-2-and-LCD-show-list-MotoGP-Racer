# Arduino MotoGP Racer List Display

Proyek ini adalah aplikasi Arduino yang menggunakan remote infrared (IR) untuk menavigasi daftar pembalap MotoGP yang ditampilkan pada LCD 16x2. Aplikasi ini memungkinkan pengguna untuk melihat informasi tim dan nama pembalap dengan mudah menggunakan tombol remote.

## Fitur

- **Navigasi Daftar Pembalap**: Gunakan tombol remote untuk maju (tombol 1) atau mundur (tombol 2) melalui daftar pembalap.
- **Tampilan LCD**: Menampilkan nama tim dan pembalap pada layar LCD 16x2.
- **Daftar Pembalap**: Berisi 5 pembalap MotoGP terkenal dengan tim mereka:
  - Ducati Lenovo: F. Bagnaia
  - Repsol Honda: Marc Marquez
  - Monster Yamaha: F. Quartararo
  - Red Bull KTM: Brad Binder
  - Aprilia Racing: Aleix Espargaro
- **Debug Serial**: Output debug dikirim ke Serial Monitor untuk memantau aktivitas.

## Hardware yang Dibutuhkan

- Arduino Uno (atau board Arduino yang kompatibel)
- LCD 16x2 dengan modul I2C (alamat 0x27)
- IR Receiver Module (terhubung ke pin 2)
- Remote Control IR (untuk navigasi)
- Kabel jumper dan breadboard (untuk prototyping)

## Software yang Dibutuhkan

- [PlatformIO](https://platformio.org/) - IDE untuk pengembangan embedded.
- Library Arduino:
  - `LiquidCrystal_I2C` oleh marcoschwartz (versi ^1.1.4)
  - `IRremote` oleh z3t0 (versi ^4.7.1)

## Instalasi

1. **Clone Repository**:
   ```
   git clone <URL_repository_ini>
   cd "Arduino With Remote Infrared and LED 2 and LCD show list MotoGP Racer"
   ```

2. **Buka di PlatformIO**:
   - Buka PlatformIO IDE.
   - Import proyek dari folder yang telah di-clone.

3. **Install Dependencies**:
   - PlatformIO akan secara otomatis mengunduh library yang diperlukan berdasarkan `platformio.ini`.

4. **Build dan Upload**:
   - Hubungkan Arduino Uno ke komputer.
   - Klik "Build" untuk mengkompilasi kode.
   - Klik "Upload" untuk mengunggah kode ke Arduino.

## Penggunaan

1. Setelah upload, LCD akan menampilkan pesan awal: "Tugas: Daftar Pembalap MotoGP".
2. Gunakan remote IR:
   - Tekan tombol **1** untuk maju ke pembalap berikutnya.
   - Tekan tombol **2** untuk mundur ke pembalap sebelumnya.
3. Daftar akan berputar secara siklik (dari akhir kembali ke awal, dan sebaliknya).
4. Buka Serial Monitor di PlatformIO untuk melihat log debug.

## Konfigurasi Pin

- **IR Receiver**: Pin 2 (RECV_PIN)
- **LCD I2C**: Alamat 0x27, pin SDA dan SCL sesuai dengan board Arduino (biasanya A4 dan A5 untuk Uno)

## Kode Utama

Kode utama terletak di `src/main.cpp`. Struktur kode:
- Inisialisasi LCD dan IR Receiver di `setup()`.
- Loop utama menangani input IR dan memperbarui tampilan LCD.

## Kontribusi

Kontribusi sangat diterima! Silakan buat issue atau pull request untuk perbaikan atau fitur baru.

## Lisensi

Proyek ini menggunakan lisensi MIT. Lihat file LICENSE untuk detail lebih lanjut.

## Catatan

- Pastikan remote IR kompatibel dengan library IRremote.
- Jika LCD tidak menampilkan apa-apa, periksa alamat I2C (bisa berbeda, gunakan scanner I2C untuk memverifikasi).</content>
<parameter name="filePath">c:\Users\Chafi\Documents\PlatformIO\Projects\Arduino With Remote Infrared and LED 2 and LCD show list MotoGP Racer\README.md