# 🏠 Sistem Manajemen Produk Toko Mebel

Aplikasi desktop untuk mengelola produk, stok, dan transaksi penjualan mebel dengan fitur login multi-user (admin dan user) serta sistem transaksi berbasis keranjang belanja.

---

## 👥 Anggota Tim

| No | Nama | NIM | Peran |
|:--:|------|-----|-------|
| 1 | **Muhammad Alfauzi Syahputra** | 2509106006 | Ketua / Developer |
| 2 | **Muhammad Fakih Nabal** | 2509106009 | Anggota / Developer |
| 3 | **Bintang Dhana Permadi** | 2509106014 | Anggota / Developer |

---

## ✨ Fitur Program

### 🔐 Menu Utama
- **Login** – Verifikasi identitas pengguna (admin/user) berdasarkan username dan password
- **Register** – Mendaftarkan pengguna baru dengan peran default sebagai user
- **Keluar** – Mengakhiri program dengan konfirmasi

### 🛠️ Menu Admin (Manajemen Data)
- **Read Produk** – Menampilkan seluruh katalog produk mebel (lengkap dengan material)
- **Create Produk** – Menambah produk baru ke gudang (ID otomatis format `PRDxxx`)
- **Update Produk** – Mengubah detail produk yang sudah ada
- **Delete Produk** – Menghapus produk dari katalog
- **Kelola Material** – CRUD data material (bahan baku) yang digunakan oleh produk
- **Sort Produk** – Mengurutkan produk berdasarkan ID atau harga (ascending/descending)
- **Search Produk** – Mencari produk berdasarkan ID (binary search) atau nama (linear search)
- **Lihat Seluruh History Transaksi** – Menampilkan semua riwayat transaksi dari file CSV
- **Logout** – Keluar dari sesi admin dan kembali ke Menu Utama

### 🛒 Menu User (Transaksi)
- **Profil Saya** – Menampilkan data diri (nama, email, alamat, saldo) dan opsi update profil
- **Beli Produk** – Menampilkan katalog produk, memilih produk dan jumlah pembelian, lalu menambahkan ke keranjang
- **Keranjang** – Menampilkan isi keranjang belanja, mengubah jumlah, menghapus item, atau melakukan checkout
- **Sort Produk** – Mengurutkan katalog produk
- **Search Produk** – Mencari produk
- **Top Up Saldo** – Menambah saldo akun user setelah verifikasi password
- **Lihat History Transaksi User** – Menampilkan riwayat pembelian milik user tersebut saja
- **Logout** – Keluar dari sesi user dan kembali ke Menu Utama

---

## 🛠️ Teknologi yang Digunakan

| Komponen | Detail |
|----------|--------|
| **Bahasa Pemrograman** | C++ |
| **Struktur Data** | Array statis (in-memory database) |
| **Penyimpanan Data** | File CSV untuk riwayat transaksi |
| **Algoritma Sorting** | Bubble Sort, Selection Sort |
| **Algoritma Searching** | Binary Search, Linear Search |

---

## 🚀 Cara Menjalankan Program

### Prerequisites
- Compiler C++ (g++, clang, atau MSVC)
- Terminal/Command Prompt

### Langkah-Langkah

1. **Clone atau Download Repository**
   ```bash
   git clone https://github.com/Alfauzi-S/Sistem-Manajemen-Produk-Toko-Mebel.git
   cd Sistem-Manajemen-Produk-Toko-Mebel
   ```

2. **Kompilasi Program**
   ```bash
   g++ main.cpp -o program
   ```
   
   Atau jika ada multiple files:
   ```bash
   g++ *.cpp -o program
   ```

3. **Jalankan Program**
   - **Linux/Mac:**
     ```bash
     ./program
     ```
   - **Windows:**
     ```bash
     program.exe
     ```

4. **Login Pertama Kali**
   - Pilih **Register** untuk membuat akun baru
   - Atau gunakan akun demo (jika tersedia)
   - Login dengan username dan password yang telah terdaftar

---

---

## 💡 Fitur Unggulan

✅ **Multi-User System** – Admin dan User dengan hak akses berbeda  
✅ **CRUD Operations** – Manajemen produk, material, dan user yang lengkap  
✅ **Smart Search** – Binary search untuk performa optimal  
✅ **Sorting Flexible** – Multiple sort options untuk kemudahan pengguna  
✅ **Shopping Cart** – Sistem keranjang belanja yang intuitif  
✅ **Transaction History** – Pencatatan lengkap semua transaksi dalam CSV  
✅ **User Wallet** – Sistem top-up saldo untuk kemudahan pembayaran  

---

## 📝 Lisensi

Project ini merupakan tugas akademik dan bebas digunakan untuk keperluan pendidikan.

---
