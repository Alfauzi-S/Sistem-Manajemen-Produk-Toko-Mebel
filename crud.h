#ifndef CRUD_H
#define CRUD_H

#include "library.h"
#include "struct.h"
#include "validation.h"
#include "menu.h"
#include "material.h"
// Done
void read() {
    if (mabelIndex == 0) {
        showError("Data Produk Kosong!");
    } else {
        Header("DAFTAR PRODUK MEBEL", 127);
        cout << " " << setw(8) << left << "ID" << " | "
            << setw(22) << left << "Nama Produk" << " | "
            << setw(8) << left << "Jenis" << " | "
            << setw(5) << left << "Stock" << " | "
            << setw(15) << "Harga" << " | "
            << setw(11) << left << "ID Material" << " | "
            << setw(20) << left << "Nama Material" << " | "
            << setw(15) << left << "Jenis Material" << endl;
        printLine('-', 127);
    
        for (int i = 0; i < mabelIndex; i++) {
            cout << " " << setw(8) << left << mabel[i].idProduk << " | "
                << setw(22) << left << mabel[i].namaProduk << " | "
                << setw(8) << left << mabel[i].jenisProduk << " | "
                << setw(5) << right << mabel[i].stock << " | "
                << "Rp" << setw(13) << right << mabel[i].harga << " | "
                << setw(11) << left << mabel[i].material.idMaterial << " | "
                << setw(20) << left << mabel[i].material.namaMaterial << " | "
                << setw(15) << left << mabel[i].material.jenisMaterial << endl;
        }
        
        printLine('-', 127);
        cout << " Total Produk: " << mabelIndex << endl;
        printLine('=', 127);
    }
}
// Done
void create() {
    Header("CREATE PRODUK", 50);

    if (mabelIndex >= maxproduk) {
        showError("Kapasitas memori penuh!");
        return;
    }

    int maxId = 0;
    for (int i = 0; i < mabelIndex; i++) {
        string idStr = mabel[i].idProduk;
        if (idStr.length() >= 6 && idStr.substr(0, 3) == "PRD") {  // substr(0, 3) ambil "PRD"
            string numStr = idStr.substr(3);  // ambil "000" setelah "PRD" 
            int num = stoi(numStr); // konversi ke integer
            if (num > maxId) maxId = num; // ketemu idBaru
        }
    }

    int nextId = maxId + 1;
    string idBaru = "PRD";
    if (nextId < 10) {
        idBaru += "00" + to_string(nextId);
    } else if (nextId < 100) {
        idBaru += "0" + to_string(nextId);
    } else {
        idBaru += to_string(nextId);
    }
    
    produk *newMabel = &mabel[mabelIndex];

    cout << setw(15) << left << "ID Produk" << ": " << idBaru << endl;
    newMabel->idProduk = idBaru;
    newMabel->namaProduk = getNamePrd("Nama Baru", mabelIndex, 100, 15);
    newMabel->jenisProduk = getInput("Jenis Produk", 50, 15);
    newMabel->stock = getInt("Stok Produk", 15);
    newMabel->harga = getInt("Harga Produk", 15);

    cout << "Pilih Material untuk produk ini" << endl;
    int materialIndexChoice = pilihMaterial();
    
    if (materialIndexChoice == -1) {
        showInfo("Pembuatan produk dibatalkan!");
        return;
    }
    
    newMabel->material = materialDb[materialIndexChoice];
    mabelIndex++;
    
    printLine('-', 50);
    showSuccess("Produk berhasil ditambahkan!");
}
// Done
void update() {
    Header("UPDATE PRODUK", 127);
    if (mabelIndex == 0) {
        showError("Data Produk Kosong!");
        return;
    };

    read();

    string idCari = getInput("Input ID produk", 50, 20);
    int indexKetemu = -1;

    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        showError("Produk dengan ID " + idCari + " tidak ditemukan!");
        return;
    }

    produk *updateMabel = &mabel[indexKetemu];
    string namaBaru = updateMabel->namaProduk;
    string jenisBaru = updateMabel->jenisProduk;
    int stockBaru = updateMabel->stock;
    int hargaBaru = updateMabel->harga;
    material materialBaru = updateMabel->material;
    
    string pilihan;
    while (true) {
        clearScreen();
        Header("DATA PRODUK SAAT INI", 50);
        cout << setw(15) << left << "ID Produk" << " : " << mabel[indexKetemu].idProduk << endl;
        cout << setw(15) << left << "Nama" << " : " << namaBaru << endl;
        cout << setw(15) << left << "Jenis" << " : "<< jenisBaru << endl;
        cout << setw(15) << left << "Stok" << " : "<< stockBaru << endl;
        cout << setw(15) << left << "Harga" << " : Rp " << hargaBaru << endl;
        cout << setw(15) << left << "Material" << " : " << materialBaru.namaMaterial << endl;
        menuUpdate();
        getline(cin, pilihan);
        
        if (pilihan == "1") {
            namaBaru = getNamePrd("Nama Baru", mabelIndex, 100, 15);
        } else if (pilihan == "2") {
            jenisBaru = getInput("Jenis Baru", 100, 15);
        } else if (pilihan == "3") {
            stockBaru = getInt("Stok Baru", 15);
        } else if (pilihan == "4") {
            hargaBaru = getInt("Harga Baru", 15);
        } else if (pilihan == "5") {
            showInfo("Pilih Material Baru");
            int materialIndexChoice = pilihMaterial();
            if (materialIndexChoice != -1) {
                materialBaru = materialDb[materialIndexChoice];
                showSuccess("Material berhasil diubah!");
            } else {
                showInfo("Perubahan material dibatalkan");
            }
        } else if (pilihan == "0") {
            if (confirm("Hapus produk ini [Y/N]", 22)) {
                updateMabel->namaProduk = namaBaru;
                updateMabel->jenisProduk = jenisBaru;
                updateMabel->stock = stockBaru;
                updateMabel->harga = hargaBaru;
                updateMabel->material = materialBaru;
                printLine('-', 50);
                showSuccess("Produk berhasil diupdate!");
            } else {
                showInfo("Update produk dibatalkan");
            }
            return;
        } else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}
// Done
void del() {
    Header("DELETE PRODUK", 127);
    
    if (mabelIndex == 0) {
        showError("Data Produk Kosong!");
        return;
    };
    
    read();

    string idCari = getInput("Input ID produk", 50, 20);
    int indexKetemu = -1;

    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        showError("Produk dengan ID " + idCari + " tidak ditemukan!");
        return;
    }

    clearScreen();
    Header("KONFIRMASI HAPUS PRODUK", 50);
    cout << setw(15) << left << "ID Produk" << " : " << mabel[indexKetemu].idProduk << endl;
    cout << setw(15) << left << "Nama" << " : " << mabel[indexKetemu].namaProduk << endl;
    cout << setw(15) << left << "Jenis" << " : "<< mabel[indexKetemu].jenisProduk << endl;
    cout << setw(15) << left << "Stok" << " : "<< mabel[indexKetemu].stock << endl;
    cout << setw(15) << left << "Harga" << " : Rp " << mabel[indexKetemu].harga << endl;
    cout << setw(15) << left << "Material" << " : " << mabel[indexKetemu].material.namaMaterial << endl;
    printLine('=', 50);
    
    if (confirm("Hapus produk ini [Y/N]", 23)) {
        for (int i = indexKetemu; i < mabelIndex - 1; i++) {
            mabel[i] = mabel[i + 1];
        }
        mabelIndex--;
        printLine('-', 50);
        showSuccess("Produk berhasil dihapus!");
    } else {
        showInfo("Penghapusan produk dibatalkan");
    }
}

#endif