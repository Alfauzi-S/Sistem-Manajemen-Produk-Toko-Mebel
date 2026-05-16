// Done 
#ifndef MENU_H
#define MENU_H

#include "library.h"

void printLine(char c, int length) {
    for (int i = 0; i < length; i++) {
        cout << c;
    }
    cout << endl;
}

void Header(string c, int length) {
    int padding = (length - c.length()) / 2; // Cari nilai Tengah
    printLine('=', length);
    cout << setw(padding + c.length()) << right << c << endl; // setw nilai tengan + panjang c
    printLine('=', length);
}

void showSuccess(const string& msg) {
    cout << "[SUKSES] " << msg << endl;
}

void showError(const string& msg) {
    cout << "[ERROR] " << msg << endl;
}

void showInfo(const string& msg) {
    cout << "[INFO] " << msg << endl;
}

void menu() {
    Header("SISTEM MANAJEMEN TOKO MEBEL", 50);
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit Program" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuAdmin() {
    Header("MENU ADMIN", 50);
    cout << "1. Read Produk" << endl;
    cout << "2. Create Produk" << endl;
    cout << "3. Update Produk" << endl;
    cout << "4. Delete Produk" << endl;
    cout << "5. Kelola Material" << endl;
    cout << "6. Sort Produk" << endl;
    cout << "7. Search Produk" << endl;
    cout << "8. Liat Seluruh History Transaksi" << endl;
    cout << "0. Logout" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuUser() {
    Header("MENU USER", 50);
    cout << "1. Profil Saya" << endl;
    cout << "2. Beli Produk" << endl;
    cout << "3. Keranjang" << endl;
    cout << "4. Sort Produk" << endl;
    cout << "5. Search Produk" << endl;
    cout << "6. Top Up Saldo" << endl;
    cout << "7. Liat History Transaksi User" << endl;
    cout << "0. Logout" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuUpdate() {
    Header("UPDATE PRODUK", 50);
    cout << "1. Nama Produk" << endl;
    cout << "2. Jenis Produk" << endl;
    cout << "3. Stok" << endl;
    cout << "4. Harga" << endl;
    cout << "5. Material" << endl;
    cout << "0. Simpan & Keluar" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuMat() {
    Header("MENU MATERIAL", 50);
    cout << "1. Lihat Material" << endl;
    cout << "2. Tambah Material" << endl;
    cout << "3. Update Material" << endl;
    cout << "4. Hapus Material" << endl;
    cout << "0. Kembali" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuUpdateMat() {
    Header("UPDATE MATERIAL", 50);
    cout << "1. Nama Material" << endl;
    cout << "2. Jenis Material" << endl;
    cout << "0. Simpan & Keluar" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuUpdateUser() {
    cout << "1. Update Data User" << endl;
    cout << "0. Kembali" << endl;
    printLine('-', 55);
    cout << "Masukan Pilihan: ";
}

void menuUpdateDataUser() {
    cout << "1. Ubah Nama" << endl;
    cout << "2. Ubah Email" << endl;
    cout << "3. Ubah Jalan" << endl;
    cout << "4. Ubah Kota" << endl;
    cout << "5. Ubah Provinsi" << endl;
    cout << "0. Simpan & Keluar" << endl;
    printLine('-', 55);
    cout << "Masukan Pilihan: ";
}

void menuTopup() {
    cout << "1. Top Up" << endl;
    cout << "0. Kembali" << endl;
    printLine('-', 50);
    cout << "Masukan Pilihan: ";
}

void menuJumlah() {
    cout << "1. Ubah Jumlah" << endl;
    cout << "0. Tambah ke Keranjang" << endl;
    printLine('-', 76);
    cout << "Masukan Pilihan: ";
}

void menuCart() {
    cout << "1. Checkout" << endl;
    cout << "2. Update Jumlah" << endl;
    cout << "3. Hapus Item" << endl;
    cout << "0. Kembali" << endl;
    printLine('-', 85);
    cout << "Masukkan Pilihan: ";
}

void menuSort() {
    Header("MENU SORT", 50);
    cout << "1. Sort by ID" << endl;
    cout << "2. Sort by Harga" << endl;
    cout << "0. Kembali" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuSearch() {
    Header("MENU SEARCH", 50);
    cout << "1. Cari by ID Produk" << endl;
    cout << "2. Cari by Nama Produk" << endl;
    cout << "0. Kembali" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuSortHarga() {
    Header("Sort by Harga", 50);
    cout << "1. Termurah ke Termahal (Ascending)" << endl;
    cout << "2. Termahal ke Termurah (Descending)" << endl;
    printLine('-', 50);
    cout << "Pilihan: ";
}

#endif