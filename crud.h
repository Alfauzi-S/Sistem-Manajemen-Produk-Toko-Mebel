#ifndef CRUD_H
#define CRUD_H

#include "library.h"

void read() {
    cout << "========================================================================================================================" << endl;
    cout << "                                                  DAFTAR PRODUK MABEL                                                   " << endl;
    cout << "========================================================================================================================" << endl;
    cout << setw(5) << left << "ID" 
        << setw(25) << left << "Nama Produk" 
        << setw(15) << left << "Jenis Produk" 
        << setw(10) << left << "Stok" 
        << setw(15) << left << "Harga" 
        << setw(15) << left << "ID Material" 
        << setw(20) << left << "Nama Material" 
        << setw(15) << left << "Jenis Material" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < mabelIndex; i++) {
        cout << setw(5) << left << mabel[i].idProduk 
            << setw(25) << left << mabel[i].namaProduk 
            << setw(15) << left << mabel[i].jenisProduk  
            << setw(10) << left << mabel[i].stock 
            << "Rp " << setw(12) << left << mabel[i].harga
            << setw(15) << left << mabel[i].material.idMaterial
            << setw(20) << left  << mabel[i].material.namaMaterial 
            << setw(15) << mabel[i].material.jenisMaterial << endl;
    }
    
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Total Produk: " << mabelIndex << endl;
    cout << "========================================================================================================================" << endl;
}

void create(){
    cout << "================================================" << endl;
    cout << "                   CREATE PRODUK                " << endl;
    cout << "================================================" << endl;

    if (mabelIndex >= maxproduk){
        cout << "Kapasitas memori penuh" << endl;
        return;
    }

    // auto generate id
    int idBaru;
    if (mabelIndex == 0) {
        idBaru = 101;
    } else {
        idBaru = mabel[mabelIndex - 1].idProduk + 1;
    }

    cout << left << setw(25) << "ID Produk" << ": " << idBaru << endl;
    mabel[mabelIndex].idProduk = idBaru;

    cout << left << setw(25) << "Masukkan nama produk" << ": ";
    getline(cin, mabel[mabelIndex].namaProduk);

    cout << left << setw(25) << "Masukkan jenis produk" << ": ";
    getline(cin, mabel[mabelIndex].jenisProduk);

    mabel[mabelIndex].stock = getPositiveInt("Masukkan stok produk") ;
    mabel[mabelIndex].harga = getPositiveInt("Masukkan harga produk");

    cout << left << setw(25) << "Masukkan ID material" << ": ";
    getline(cin, mabel[mabelIndex].material.idMaterial);
    
    cout << left << setw(25) << "Masukkan nama material" << ": ";
    getline(cin, mabel[mabelIndex].material.namaMaterial);

    cout << left << setw(25) << "Masukkan jenis material" << ": ";
    getline(cin, mabel[mabelIndex].material.jenisMaterial);
    mabelIndex++;

    cout << "================================================" << endl;
    cout << "[Produk telah ditambahkan]" << endl;
}

void update(){
    cout << "========================================================================================================================" << endl;
    cout << "                                                      UPDATE PRODUK                                                     " << endl;
    cout << "========================================================================================================================" << endl;

    if (mabelIndex == 0) {
        cout << "[Data Produk Kosong]" << endl;
        return;
    };

    read();

    int idCari = getPositiveInt("Masukkan ID produk");
    int indexKetemu = -1;

    for(int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1){
        cout << "========================================================================================================================" << endl;
        cout << "[Produk dengan ID " << idCari  << " tidak ditemukan]" << endl;
        return;
    }

    string pilihan;
    produk temp = mabel[indexKetemu];
    string namaBaru = temp.namaProduk;
    string jenisBaru = temp.jenisProduk;
    int stockBaru = temp.stock;
    int hargaBaru = temp.harga;
    string idMatBaru = temp.material.idMaterial;
    string namaMatBaru = temp.material.namaMaterial;
    string jenisMatBaru = temp.material.jenisMaterial;

    while(true) {
        system("cls");
        cout << "========================================================================================================================" << endl;
        cout << setw(5) << left << "ID" 
            << setw(25) << left << "Nama Produk" 
            << setw(15) << left << "Jenis Produk" 
            << setw(10) << left << "Stok" 
            << setw(15) << left << "Harga" 
            << setw(15) << left << "ID Material" 
            << setw(20) << left << "Nama Material" 
            << setw(15) << left << "Jenis Material" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(5) << left << mabel[indexKetemu].idProduk 
            << setw(25) << left << namaBaru 
            << setw(15) << left << jenisBaru 
            << setw(10) << left << stockBaru 
            << "Rp " << setw(12) << left << hargaBaru
            << setw(15) << left << idMatBaru
            << setw(20) << left  << namaMatBaru
            << setw(15) << jenisMatBaru << endl;
        cout << "========================================================================================================================" << endl;

        menuUpdate();
        getline(cin, pilihan);
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        if (pilihan == "1") {
            cout << left << setw(25) << "Masukkan nama produk" << ": ";
            getline(cin, namaBaru);
        } else if (pilihan == "2") {
            cout << left << setw(25) << "Masukkan jenis produk" << ": ";
            getline(cin, jenisBaru);
        } else if (pilihan == "3") {
            stockBaru = getPositiveInt("Masukkan stok produk");
        } else if (pilihan == "4") {
            hargaBaru = getPositiveInt("Masukkan harga produk");
        } else if (pilihan == "5") {
            cout << left << setw(25) << "Masukkan ID material" << ": ";
            getline(cin, idMatBaru);
        } else if (pilihan == "6") {
            cout << left << setw(25) << "Masukkan nama material" << ": ";
            getline(cin, namaMatBaru);
        } else if (pilihan == "7") {
            cout << left << setw(25) << "Masukkan jenis material" << ": ";
            getline(cin, jenisMatBaru);
        } else if (pilihan == "0" ) {
            cout << "========================================================================================================================" << endl;
            string konfirmasi = yesOrNo("Save Produk(Y/N)? ");
            if (konfirmasi == "y" || konfirmasi == "Y") {
                mabel[indexKetemu].namaProduk = namaBaru;
                mabel[indexKetemu].jenisProduk = jenisBaru;
                mabel[indexKetemu].stock = stockBaru;
                mabel[indexKetemu].harga = hargaBaru;
                mabel[indexKetemu].material.idMaterial = idMatBaru;
                mabel[indexKetemu].material.namaMaterial = namaMatBaru;
                mabel[indexKetemu].material.jenisMaterial = jenisMatBaru;
                cout << "[Berhasil Update Produk dengan ID : " << mabel[indexKetemu].idProduk  << "]" << endl;
                return;
            } else {
                cout << "[Membatalkan Update Produk dengan ID : " << mabel[indexKetemu].idProduk  << "]" << endl;
                return;
            }
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            system("pause");
        }
    }
}

void del(){
    cout << "========================================================================================================================" << endl;
    cout << "                                                      DELETE PRODUK                                                     " << endl;
    cout << "========================================================================================================================" << endl;
    
    if (mabelIndex == 0) {
        cout << "[Data Produk Kosong]" << endl;
        return;
    };
    read();

    int idCari = getPositiveInt("Masukkan ID Produk");
    int indexKetemu = -1;

    for(int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    if (indexKetemu == -1) {
        cout << "========================================================================================================================" << endl;
        cout << "produk dengan ID " << idCari << " tidak ditemukan" << endl;
        return;
    }

    system("cls");
    cout << "========================================================================================================================" << endl;
    cout << setw(5) << left << "ID" 
        << setw(25) << left << "Nama Produk" 
        << setw(15) << left << "Jenis Produk" 
        << setw(10) << left << "Stok" 
        << setw(15) << left << "Harga" 
        << setw(15) << left << "ID Material" 
        << setw(20) << left << "Nama Material" 
        << setw(15) << left << "Jenis Material" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(5) << left << mabel[indexKetemu].idProduk 
        << setw(25) << left << mabel[indexKetemu].namaProduk 
        << setw(15) << left << mabel[indexKetemu].jenisProduk
        << setw(10) << left << mabel[indexKetemu].stock
        << "Rp " << setw(12) << left << mabel[indexKetemu].harga
        << setw(15) << left << mabel[indexKetemu].material.idMaterial
        << setw(20) << left  << mabel[indexKetemu].material.namaMaterial
        << setw(15) << mabel[indexKetemu].material.jenisMaterial << endl;
    cout << "========================================================================================================================" << endl;
    string konfirmasi = yesOrNo("Hapus Produk(Y/N)? ");
    if (konfirmasi == "y" || konfirmasi == "Y"){
        for (int i = indexKetemu; i < mabelIndex -1; i++){
            mabel[i] = mabel[i + 1];
        }
        mabelIndex--;
        cout << "[Berhasil Menghapus Produk dengan ID : " << mabel[indexKetemu].idProduk  << "]" << endl;
    } else {
        cout << "[Membatalkan Penghapusan Produk dengan ID : " << mabel[indexKetemu].idProduk  << "]" << endl;
    }
}

#endif