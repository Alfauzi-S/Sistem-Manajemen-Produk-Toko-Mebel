#ifndef MENU_H
#define MENU_H

#include "library.h"
// Done
void printLine(char c, int length) {
    for (int i = 0; i < length; i++) {
        cout << c;
    }
    cout << endl;
}
// Done
void Header(string c, int length) {
    int padding = (length - c.length()) / 2;
    printLine('=', length);
    cout << setw(padding + c.length()) << right << c << endl;
    printLine('=', length);
}
// Done
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
    cout << "5. Sort Produk" << endl;
    cout << "6. Search Produk" << endl;
    cout << "7. Kelola Material" << endl;
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

void menuKeranjang() {
    Header("MENU KERANJANG", 50);
    cout << "1. Checkout" << endl;
    cout << "2. Update Jumlah" << endl;
    cout << "3. Hapus Item" << endl;
    cout << "0. Kembali" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

void menuSort() {
    Header("MENU SORT", 50);
    cout << "1. Sort by ID (Ascending)" << endl;
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

void menuBuy() {
    Header("MENU BELI", 50);
    cout << "1. Ubah Jumlah" << endl;
    cout << "0. Tambah ke Keranjang" << endl;
    printLine('-', 50);
    cout << "Masukkan Pilihan: ";
}

#endif