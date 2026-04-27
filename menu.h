#ifndef MENU_H
#define MENU_H

#include "library.h"
void tampilkanMenuUtama() {
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuAdmin() {
    cout << "1. Read Produk" << endl;
    cout << "2. Create Produk" << endl;
    cout << "3. Update Produk" << endl;
    cout << "4. Delete Produk" << endl;
    cout << "5. Sort Produk" << endl;
    cout << "6. Search Produk" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

void tampilkanMenuUser() {
    cout << "1. Read Data Saya" << endl;
    cout << "2. Read Produk dan Beli" << endl;
    cout << "3. Search Produk" << endl;
    cout << "4. Top Up" << endl;
    cout << "0. Logout" << endl;
    cout << "Masukkan Pilihan: ";
}

#endif