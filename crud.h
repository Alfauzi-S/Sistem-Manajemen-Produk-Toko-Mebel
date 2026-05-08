#ifndef CRUD_H
#define CRUD_H

#include "library.h"
#include "struct.h"
#include "validation.h"
#include "menu.h"
#include "material.h"
// Done
void read() {
    Header("DAFTAR PRODUK MEBEL", 122);
    cout << " " << setw(3) << left << "ID" << " | "
        << setw(22) << left << "Nama Produk" << " | "
        << setw(8) << left << "Jenis" << " | "
        << setw(6) << left << "Stock" << " | "
        << setw(15) << "Harga" << " | "
        << setw(11) << left << "ID Material" << " | "
        << setw(20) << left << "Nama Material" << " | "
        << setw(15) << left << "Jenis Material" << endl;
    printLine('-', 122);

    for (int i = 0; i < mabelIndex; i++) {
        cout << " " << setw(3) << left << mabel[i].idProduk << " | "
            << setw(22) << left << mabel[i].namaProduk << " | "
            << setw(8) << left << mabel[i].jenisProduk << " | "
            << setw(6) << right << mabel[i].stock << " | "
            << "Rp" << setw(13) << right << mabel[i].harga << " | "
            << setw(11) << left << mabel[i].material.idMaterial << " | "
            << setw(20) << left << mabel[i].material.namaMaterial << " | "
            << setw(15) << left << mabel[i].material.jenisMaterial << endl;
    }
    
    printLine('-', 122);
    cout << " Total Produk: " << mabelIndex << endl;
    printLine('=', 122);
}

void create() {
    Header("CREATE PRODUK", 50);

    if (mabelIndex >= maxproduk) {
        cout << "[ERROR] Kapasitas memori penuh!" << endl;
        return;
    }

    int idBaru;
    if (mabelIndex == 0) {
        idBaru = 101;
    } else {
        idBaru = mabel[mabelIndex - 1].idProduk + 1;
    }

    cout << setw(15) << left << "ID Produk" << ": " << idBaru << endl;
    mabel[mabelIndex].idProduk = idBaru;

    cout << "Nama Produk : ";
    getline(cin, mabel[mabelIndex].namaProduk);

    cout << "Jenis Produk : ";
    getline(cin, mabel[mabelIndex].jenisProduk);

    mabel[mabelIndex].stock = getPositiveInt("Stok Produk");
    mabel[mabelIndex].harga = getPositiveInt("Harga Produk");

    cout << endl;
    cout << "Pilih Material untuk produk ini]" << endl;
    int materialIndexChoice = pilihMaterial();
    
    if (materialIndexChoice == -1) {
        cout << endl << "[INFO] Pembuatan produk dibatalkan!" << endl;
        return;
    }
    
    mabel[mabelIndex].material = materialDb[materialIndexChoice];
    mabelIndex++;
    
    cout << endl;
    printLine('-', 50);
    cout << "[SUKSES] Produk berhasil ditambahkan!" << endl;
}

void update() {
    cout << endl;
    printLine('=', 50);
    cout << "                    UPDATE PRODUK                   " << endl;
    printLine('=', 50);
    cout << endl;

    if (mabelIndex == 0) {
        cout << "     [ERROR] Data Produk Kosong!" << endl;
        return;
    };

    read();

    int idCari = getPositiveInt("     Masukkan ID produk");
    int indexKetemu = -1;

    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        cout << endl << "     [ERROR] Produk dengan ID " << idCari << " tidak ditemukan!" << endl;
        return;
    }

    string pilihan;
    string namaBaru = mabel[indexKetemu].namaProduk;
    string jenisBaru = mabel[indexKetemu].jenisProduk;
    int stockBaru = mabel[indexKetemu].stock;
    int hargaBaru = mabel[indexKetemu].harga;
    material materialBaru = mabel[indexKetemu].material;

    while (true) {
        clearScreen();
        cout << endl;
        printLine('=', 50);
        cout << "                 DATA PRODUK SAAT INI              " << endl;
        printLine('=', 50);
        cout << "     ID Produk : " << mabel[indexKetemu].idProduk << endl;
        cout << "     Nama      : " << namaBaru << endl;
        cout << "     Jenis     : " << jenisBaru << endl;
        cout << "     Stok      : " << stockBaru << endl;
        cout << "     Harga     : Rp " << hargaBaru << endl;
        cout << "     Material  : " << materialBaru.namaMaterial << endl;
        printLine('=', 50);

        menuUpdate();
        getline(cin, pilihan);
        
        if (pilihan == "1") {
            cout << "     Nama Baru : ";
            getline(cin, namaBaru);
        } 
        else if (pilihan == "2") {
            cout << "     Jenis Baru : ";
            getline(cin, jenisBaru);
        } 
        else if (pilihan == "3") {
            stockBaru = getPositiveInt("     Stok Baru");
        } 
        else if (pilihan == "4") {
            hargaBaru = getPositiveInt("     Harga Baru");
        } 
        else if (pilihan == "5") {
            cout << endl << "     [Pilih Material Baru]" << endl;
            int materialIndexChoice = pilihMaterial();
            if (materialIndexChoice != -1) {
                materialBaru = materialDb[materialIndexChoice];
                cout << endl << "     [SUKSES] Material berhasil diubah!" << endl;
            } else {
                cout << endl << "     [INFO] Perubahan material dibatalkan" << endl;
            }
        } 
        else if (pilihan == "0") {
            if (confirm("     Simpan perubahan")) {
                mabel[indexKetemu].namaProduk = namaBaru;
                mabel[indexKetemu].jenisProduk = jenisBaru;
                mabel[indexKetemu].stock = stockBaru;
                mabel[indexKetemu].harga = hargaBaru;
                mabel[indexKetemu].material = materialBaru;
                cout << endl;
                printLine('=', 50);
                cout << "     [SUKSES] Produk berhasil diupdate!" << endl;
                printLine('=', 50);
            } else {
                cout << endl << "     [INFO] Update produk dibatalkan" << endl;
            }
            return;
        } 
        else {
            cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
            pauseScreen();
        }
    }
}

void del() {
    cout << endl;
    printLine('=', 50);
    cout << "                    DELETE PRODUK                   " << endl;
    printLine('=', 50);
    cout << endl;
    
    if (mabelIndex == 0) {
        cout << "     [ERROR] Data Produk Kosong!" << endl;
        return;
    };
    
    read();

    int idCari = getPositiveInt("     Masukkan ID Produk");
    int indexKetemu = -1;

    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        cout << endl << "     [ERROR] Produk dengan ID " << idCari << " tidak ditemukan!" << endl;
        return;
    }

    int deletedId = mabel[indexKetemu].idProduk;
    string deletedName = mabel[indexKetemu].namaProduk;

    clearScreen();
    cout << endl;
    printLine('=', 50);
    cout << "              KONFIRMASI HAPUS PRODUK               " << endl;
    printLine('=', 50);
    cout << "     ID Produk : " << mabel[indexKetemu].idProduk << endl;
    cout << "     Nama      : " << mabel[indexKetemu].namaProduk << endl;
    cout << "     Jenis     : " << mabel[indexKetemu].jenisProduk << endl;
    cout << "     Stok      : " << mabel[indexKetemu].stock << endl;
    cout << "     Harga     : Rp " << mabel[indexKetemu].harga << endl;
    printLine('=', 50);
    
    if (confirm("     Hapus produk ini")) {
        for (int i = indexKetemu; i < mabelIndex - 1; i++) {
            mabel[i] = mabel[i + 1];
        }
        mabelIndex--;
        cout << endl;
        printLine('=', 50);
        cout << "     [SUKSES] Produk berhasil dihapus!" << endl;
        cout << "     ID: " << deletedId << " | Nama: " << deletedName << endl;
        printLine('=', 50);
    } else {
        cout << endl << "     [INFO] Penghapusan produk dibatalkan" << endl;
    }
}

#endif