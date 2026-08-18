# 🧤 GestureGlove: Universal Appliance Controller & Sign Language Translator

[![Arduino Nano](https://img.shields.io/badge/Microcontroller-Arduino%20Nano-blue.svg)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20Arduino-00979D.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Perangkat keras interaktif berbasis sarung tangan (*wearable device*) yang memanfaatkan 5 sensor kontak jari DIY dan mikrokontroler Arduino Nano untuk menerjemahkan gestur tangan menjadi teks digital secara *real-time* melalui Serial Monitor[cite: 1]. Ditujukan sebagai prototipe alat bantu komunikasi inklusif bagi penyandang disabilitas wicara dan rungu[cite: 1].

---

## 📌 Ringkasan Masalah & Solusi
* **Masalah:** Hambatan komunikasi yang sering dialami oleh penyandang disabilitas wicara karena tidak semua lawan bicara memahami bahasa isyarat[cite: 1].
* **Solusi:** **GestureGlove** mendeteksi status lekukan 5 jari tangan secara mandiri, memberikan umpan balik visual instan melalui LED per jari, dan menerjemahkan kombinasi pola gestur menjadi output teks informatif di layar monitor[cite: 1].

---

## ⚙️ Spesifikasi Perangkat & Pemetaan Pin

### Komponen Utama:
* **Mikrokontroler:** Arduino Nano (ATmega328P)[cite: 1]
* **Sensor:** 5x Sensor Kontak Jari DIY (Konfigurasi `INPUT_PULLUP` Active-LOW)
* **Feedback Visual:** 5x LED Indikator Jari (Pin D2–D6)[cite: 1]
* **Baud Rate Serial:** 9600 bps

### Tabel Koneksi Pin (Wiring Table):
| Jari Tangan | Pin Sensor (Input) | Pin LED Indikator (Output) | Status Terbuka | Status Ditekan/Ditekuk |
| :--- | :---: | :---: | :---: | :---: |
| **Jempol** | D7 | D2 | HIGH (LED Mati) | LOW (LED Nyala) |
| **Telunjuk** | D8 | D3 | HIGH (LED Mati) | LOW (LED Nyala) |
| **Jari Tengah** | D9 | D4 | HIGH (LED Mati) | LOW (LED Nyala) |
| **Jari Manis** | D10 | D5 | HIGH (LED Mati) | LOW (LED Nyala) |
| **Kelingking** | D11 | D6 | HIGH (LED Mati) | LOW (LED Nyala) |

---

## 🖐️ Logika Pemetaan Gestur (Matrix Rules)

| Output Teks | Jempol | Telunjuk | Tengah | Manis | Kelingking | Keterangan Gerakan |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| `TANGAN TERBUKA` | ❌ | ❌ | ❌ | ❌ | ❌ | Semua jari lurus / posisi diam |
| `TERIMA KASIH / TANGAN TERKEPAL` | ✅ | ✅ | ✅ | ✅ | ✅ | Semua jari ditekuk bersamaan |
| `JEMPOL / OK` | ✅ | ❌ | ❌ | ❌ | ❌ | Hanya jempol ditekuk |
| `DIAM / TUNJUK` | ❌ | ✅ | ❌ | ❌ | ❌ | Hanya telunjuk ditekuk |
| `TENGAH` | ❌ | ❌ | ✅ | ❌ | ❌ | Hanya jari tengah ditekuk |
| `PEACE ✌` | ❌ | ✅ | ✅ | ❌ | ❌ | Telunjuk dan jari tengah ditekuk |
| `MINUM` | ✅ | ✅ | ❌ | ❌ | ❌ | Jempol dan telunjuk ditekuk |
| `MAKAN` | ✅ | ✅ | ✅ | ❌ | ❌ | Jempol, telunjuk, dan tengah ditekuk |
| `HALO 👋` | ❌ | ✅ | ✅ | ✅ | ❌ | Telunjuk, tengah, dan manis ditekuk |
| `DIAM ✋` | ❌ | ✅ | ✅ | ✅ | ✅ | Empat jari selain jempol ditekuk |

*(Keterangan: ✅ = Jari Menekuk / Sinyal LOW, ❌ = Jari Terbuka / Sinyal HIGH)*

---

## 📷 Dokumentasi Prototipe

| Prototipe Fisik | Indikator LED Aktif |
| :---: | :---: |
| ![Hardware Prototype](hardware_prototype.jpg) | ![LED Active](hardware_led_active.jpg) |

---

## 📄 Makalah & Laporan Riset
Dokumentasi lengkap mengenai latar belakang, metodologi, rincian biaya komponen, dan hasil pengujian prototipe dapat diakses pada dokumen laporan[cite: 1]:
👉 [**GestureGlove_Laporan_Akhir.pdf**](GestureGlove_Laporan_Akhir.pdf)[cite: 1]

---

## 👥 Tim Pengembang
* Muhammad Raffa Danendra[cite: 1]
* Annisa Putri S.[cite: 1]
* Catteleya Putri K.M.[cite: 1]
* Checilia Shaca A.[cite: 1]
* Fadli Ghifari[cite: 1]
* Kilau Cincin M.[cite: 1]
