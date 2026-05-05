#ifndef MENU_H
#define MENU_H

#include "library.h"
void menu() {
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukan Pilihan: ";
}

void menuAdmin() {
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

#endif