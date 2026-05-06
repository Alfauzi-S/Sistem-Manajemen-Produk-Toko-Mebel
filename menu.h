#ifndef MENU_H
#define MENU_H

#include "library.h"
void menu() {
    cout << "=================================================" << endl;
    cout << "        Sistem Manajemen Produk Toko Mebel       " << endl;
    cout << "=================================================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukan Pilihan: ";
}

void menuAdmin() {
    cout << "===============================================" << endl;
    cout << "                   Menu Admin                  " << endl;
    cout << "===============================================" << endl;
    cout << "1. Read Produk" << endl;
    cout << "2. Create Produk" << endl;
    cout << "3. Update Produk" << endl;
    cout << "4. Delete Produk" << endl;
    cout << "5. Sort Produk" << endl;
    cout << "6. Search Produk" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukan Pilihan: ";
}

void menuUser() {
    cout << "==============================================" << endl;
    cout << "                   Menu User                  " << endl;
    cout << "==============================================" << endl;
    cout << "1. Read Data Saya" << endl;
    cout << "2. Buy" << endl;
    cout << "3. Keranjang" << endl;
    cout << "4. Sort Produk" << endl;
    cout << "5. Search Produk" << endl;
    cout << "6. Top Up" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukan Pilihan: ";
}

void menuUpdate() {
    cout << "1. Update Nama Produk" << endl;
    cout << "2. Update Jenis Produk" << endl;
    cout << "3. Update Stock Produk" << endl;
    cout << "4. Update Harga Produk" << endl;
    cout << "5. Update ID Material" << endl;
    cout << "6. update Nama Material" << endl;
    cout << "7. update Jenis Material" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukan Pilihan: ";
}

void menuKeranjang() {
    cout << "1. Checkout " << endl;
    cout << "2. Update Item Keranjang " << endl;
    cout << "3. Delete Item Keranjang " << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan Pilihan: ";
}

void menuSort() {
    cout << "==============================================" << endl;
    cout << "                   Menu Sort                  " << endl;
    cout << "==============================================" << endl;
    cout << "1. Urutkan ID Produk" << endl;
    cout << "2. Urutkan Harga" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan Pilihan: ";
}

void menuSearch() {
    cout << "==============================================" << endl;
    cout << "                  Menu Search                 " << endl;
    cout << "==============================================" << endl;
    cout << "1. Cari Produk Berdasarkan ID " << endl;
    cout << "2. Cari Produk Berdasarkan Nama " << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan Pilihan: ";
}

void menuBuy() {
    cout << "1. Ubah Jumlah" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan Pilihan: ";
}

#endif