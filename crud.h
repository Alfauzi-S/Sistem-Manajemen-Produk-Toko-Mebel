#ifndef CRUD_H
#define CRUD_H

#include "library.h"

void read() {
    cout << "======================================================================================" << endl;
    cout << "                                 DAFTAR PRODUK MABEL                                  " << endl;
    cout << "======================================================================================" << endl;
    cout << setw(5) << left << "ID" 
         << setw(25) << left << "Nama Produk" 
         << setw(10) << left << "Stok" 
         << setw(15) << left << "Harga" 
         << "Material" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < mabelIndex; i++) {
        cout << setw(5) << left << mabel[i].idProduk 
             << setw(25) << left << mabel[i].namaProduk 
             << setw(10) << left << mabel[i].stock 
             << "Rp " << setw(12) << left << mabel[i].harga 
             << mabel[i].material.namaMaterial << " (" << mabel[i].material.jenisMaterial << ")" << endl;
    }
    
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "Total Produk: " << mabelIndex << endl;
    cout << "======================================================================================" << endl;
}

void create(){

}

void update(){

}

void del(){

}

#endif