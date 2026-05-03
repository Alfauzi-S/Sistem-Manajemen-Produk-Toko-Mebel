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
    cout << "=== Create Produk ===" << endl;
    if (mabelIndex >= maxproduk){
        cout << "Kapasitas memori penuh" << endl;
        return;
    }
    int idBaru = getPositiveInt("Masukkan ID produk: ");
    for (int i = 0; i < mabelIndex; i++){
        if (mabel[i].idProduk == idBaru) {
            cout << "ID produk " << idBaru << "sudah ada" << endl;
            return;
        }
    }
    mabel[mabelIndex].idProduk = idBaru;
    
    cout << "Masukkan nama produk: ";
    getline(cin, mabel[mabelIndex].namaProduk);

    cout << "Masukkan jenis produk: ";
    getline(cin, mabel[mabelIndex].jenisProduk);

    mabel[mabelIndex].stock = getPositiveInt("Masukkan stok produk: ");
    mabel[mabelIndex].harga = getPositiveInt("Masukkan harga produk: ");

    cout << "=== Data Material ===" << endl;
    cout << "Masukkan ID material: ";
    getline(cin, mabel[mabelIndex].material.idMaterial);
    
    cout << "Masukkan nama material: ";
    getline(cin, mabel[mabelIndex].material.namaMaterial);

    cout << "Masukkan jenis material: ";
    getline(cin, mabel[mabelIndex].material.jenisMaterial);
    mabelIndex++;
    cout << "\nProduk telah ditambahkan" << endl;
}

void update(){
    cout << "=== Uptade Produk ===" << endl;
    read();

    int idCari = getPositiveInt("Masukkan ID produk yang ingin diubah: ");
    int indexKetemu = -1;

    for(int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1){
        cout << "Produk dengan ID " << idCari << " tidak ditemukan" << endl;
        return;
    }
    cout <<"\nProduk ditemukan " << mabel[indexKetemu].namaProduk << endl;
    cout << "Masukkan nama produk baru: ";
    getline(cin, mabel[indexKetemu].namaProduk);

    cout << "Masukkan jenis produk baru: ";
    getline(cin, mabel[indexKetemu].jenisProduk);

    mabel[indexKetemu].stock = getPositiveInt("Masukkan stok produk: ");
    mabel[indexKetemu].harga = getPositiveInt("Masukkan harga produk: ");

    cout << "=== Data Material Baru ===" << endl;
    cout << "Masukkan ID produk baru: ";
    getline(cin, mabel[indexKetemu].material.idMaterial);

    cout << "Masukkan nama material baru: ";
    getline(cin, mabel[indexKetemu].material.namaMaterial);

    cout << "Masukkan jenis material baru: ";
    getline(cin, mabel[indexKetemu].material.jenisMaterial);
    cout << "\nData produk berhasik diuptade" << endl;
}

void del(){
    cout << "=== Delete Produk ===" << endl;
    read();

    int idCari = getPositiveInt("Masukkan ID Produk yang ingin dihapus: ");
    int indexKetemu = -1;

    for(int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    if (indexKetemu == -1) {
        cout << "produk dengan ID " << idCari << " tidak ditemukan" << endl;
        return;
    }
    cout << "Yakin ingin menghapus produk " << mabel[indexKetemu].namaProduk << "'? (y/n): " << endl;
    string konfirmasi;
    getline(cin, konfirmasi);

    if (konfirmasi == "y" || konfirmasi == "Y"){
        for (int i = indexKetemu; i < mabelIndex -1; i++){
            mabel[i] = mabel[i + 1];
        }
        mabelIndex--;
        cout << "\nProduk berhasil dihapus" << endl;
    } else {
        cout << "\nPenghapusan dibatalkan" << endl;
    }
}

#endif