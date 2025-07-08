# ⚽ Aplikasi Data Liga Sepakbola (CLI C++)

Aplikasi ini merupakan program berbasis*Command Line Interface (CLI) yang dibuat menggunakan bahasa C++, bertujuan untuk mengelola data liga sepak bola yang meliputi klub, stadion, nomor tanding, dan jumlah kemenangan.

> 📁 Semua data disimpan ke dalam file `.txt`, dan dapat diurutkan serta ditampilkan kembali.

---

## 🎯 Fitur Utama

- ✅ Input data liga sepakbola ke file
- ➕ Tambah data ke file yang sudah ada
- 👀 Tampilkan data dari file eksternal
- 🔃 Urutkan data berdasarkan Nomor Tanding menggunakan Bubble Sort
- 💾 Simpan hasil output ke file

---

## 🏗️ Struktur Data

```cpp
struct LigaSepakbola {
    int Nomor_Tanding;
    int Total_Menang;
    char Nama_Klub[200];
    char Stadion[200];
};
