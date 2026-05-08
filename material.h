#ifndef MATERIAL_H
#define MATERIAL_H

#include "library.h"
#include "struct.h"
#include "validation.h"

string generateMaterialId() {
    string id = "MAT";
    int num = materialIndex + 1;
    
    if (num < 10) {
        id = id + "00" + to_string(num);
    } else if (num < 100) {
        id = id + "0" + to_string(num);
    } else {
        id = id + to_string(num);
    }
    return id;
}

void readMaterial() {
    cout << endl;
    printLine('=', 65);
    cout << "                   DAFTAR MATERIAL                    " << endl;
    printLine('=', 65);
    
    cout << " No   | ID Material | Nama Material            | Jenis Material" << endl;
    printLine('-', 65);
    
    if (materialIndex == 0) {
        cout << "                    [Belum ada material]                    " << endl;
    } else {
        for (int i = 0; i < materialIndex; i++) {
            cout << " " << setw(3) << right << i + 1 << " | ";
            cout << setw(11) << left << materialDb[i].idMaterial << " | ";
            
            string nama = materialDb[i].namaMaterial;
            if (nama.length() > 23) nama = nama.substr(0, 20) + "...";
            cout << setw(23) << left << nama << " | ";
            
            cout << setw(15) << left << materialDb[i].jenisMaterial << endl;
        }
    }
    
    printLine('=', 65);
    cout << " Total Material: " << materialIndex << endl;
    printLine('=', 65);
}

void createMaterial() {
    cout << endl;
    printLine('=', 50);
    cout << "                   TAMBAH MATERIAL                   " << endl;
    printLine('=', 50);

    if (materialIndex >= maxmaterial) {
        cout << "     [ERROR] Kapasitas material penuh!" << endl;
        return;
    }

    string idMaterial = generateMaterialId();
    cout << "     ID Material : " << idMaterial << " (Auto Generate)" << endl;
    
    string namaMaterial;
    while (true) {
        try {
            cout << "     Nama Material : ";
            getline(cin, namaMaterial);
            if (namaMaterial.empty()) {
                throw invalid_argument("Nama material tidak boleh kosong!");
            }
            break;
        }
        catch (const invalid_argument& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
    }
    
    string jenisMaterial;
    while (true) {
        try {
            cout << "     Jenis Material : ";
            getline(cin, jenisMaterial);
            if (jenisMaterial.empty()) {
                throw invalid_argument("Jenis material tidak boleh kosong!");
            }
            break;
        }
        catch (const invalid_argument& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
    }
    
    materialDb[materialIndex].idMaterial = idMaterial;
    materialDb[materialIndex].namaMaterial = namaMaterial;
    materialDb[materialIndex].jenisMaterial = jenisMaterial;
    materialIndex++;
    
    cout << endl;
    printLine('=', 50);
    cout << "     [SUKSES] Material berhasil ditambahkan!" << endl;
    printLine('=', 50);
}

void updateMaterial() {
    cout << endl;
    printLine('=', 50);
    cout << "                   UPDATE MATERIAL                   " << endl;
    printLine('=', 50);
    
    if (materialIndex == 0) {
        cout << "     [ERROR] Belum ada material untuk diupdate!" << endl;
        return;
    }
    
    readMaterial();
    
    cout << endl;
    cout << "     ID Material yang akan diupdate : ";
    string idCari;
    getline(cin, idCari);
    
    int indexKetemu = -1;
    for (int i = 0; i < materialIndex; i++) {
        if (materialDb[i].idMaterial == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        cout << "     [ERROR] ID Material tidak ditemukan!" << endl;
        return;
    }
    
    cout << endl;
    printLine('-', 50);
    cout << "     Data Lama:" << endl;
    cout << "       ID Material   : " << materialDb[indexKetemu].idMaterial << endl;
    cout << "       Nama Material : " << materialDb[indexKetemu].namaMaterial << endl;
    cout << "       Jenis Material: " << materialDb[indexKetemu].jenisMaterial << endl;
    printLine('-', 50);
    
    cout << endl;
    cout << "     Nama Baru (kosongkan jika tidak berubah): ";
    string namaBaru;
    getline(cin, namaBaru);
    if (!namaBaru.empty()) {
        materialDb[indexKetemu].namaMaterial = namaBaru;
    }
    
    cout << "     Jenis Baru (kosongkan jika tidak berubah): ";
    string jenisBaru;
    getline(cin, jenisBaru);
    if (!jenisBaru.empty()) {
        materialDb[indexKetemu].jenisMaterial = jenisBaru;
    }
    
    cout << endl;
    printLine('=', 50);
    cout << "     [SUKSES] Material berhasil diupdate!" << endl;
    printLine('=', 50);
}

void deleteMaterial() {
    cout << endl;
    printLine('=', 50);
    cout << "                   HAPUS MATERIAL                    " << endl;
    printLine('=', 50);
    
    if (materialIndex == 0) {
        cout << "     [ERROR] Belum ada material untuk dihapus!" << endl;
        return;
    }
    
    readMaterial();
    
    cout << endl;
    cout << "     ID Material yang akan dihapus : ";
    string idCari;
    getline(cin, idCari);
    
    int indexKetemu = -1;
    for (int i = 0; i < materialIndex; i++) {
        if (materialDb[i].idMaterial == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        cout << "     [ERROR] ID Material tidak ditemukan!" << endl;
        return;
    }
    
    // Cek apakah material sedang digunakan
    bool sedangDigunakan = false;
    string digunakanPada = "";
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].material.idMaterial == idCari) {
            sedangDigunakan = true;
            digunakanPada = mabel[i].namaProduk;
            break;
        }
    }
    
    if (sedangDigunakan) {
        cout << endl;
        printLine('=', 50);
        cout << "     [ERROR] Material sedang digunakan pada produk: " << digunakanPada << endl;
        cout << "     [ERROR] Hapus produk terlebih dahulu!" << endl;
        printLine('=', 50);
        return;
    }
    
    cout << endl;
    printLine('-', 50);
    cout << "     Data yang akan dihapus:" << endl;
    cout << "       ID Material   : " << materialDb[indexKetemu].idMaterial << endl;
    cout << "       Nama Material : " << materialDb[indexKetemu].namaMaterial << endl;
    cout << "       Jenis Material: " << materialDb[indexKetemu].jenisMaterial << endl;
    printLine('-', 50);
    
    cout << endl;
    cout << "     Hapus material ini (y/t): ";
    string konfirmasi;
    getline(cin, konfirmasi);
    
    if (konfirmasi == "y" || konfirmasi == "Y") {
        for (int i = indexKetemu; i < materialIndex - 1; i++) {
            materialDb[i] = materialDb[i + 1];
        }
        materialIndex--;
        cout << endl;
        printLine('=', 50);
        cout << "     [SUKSES] Material berhasil dihapus!" << endl;
        printLine('=', 50);
    } else {
        cout << endl;
        printLine('=', 50);
        cout << "     [INFO] Penghapusan dibatalkan" << endl;
        printLine('=', 50);
    }
}

int pilihMaterial() {
    if (materialIndex == 0) {
        cout << endl;
        cout << "     [ERROR] Belum ada material. Silakan tambah material terlebih dahulu!" << endl;
        return -1;
    }
    
    while (true) {
        try {
            cout << endl;
            printLine('=', 50);
            cout << "                  PILIH MATERIAL                   " << endl;
            printLine('=', 50);
            
            for (int i = 0; i < materialIndex; i++) {
                cout << "     " << i + 1 << ". " 
                     << materialDb[i].idMaterial << " - " 
                     << materialDb[i].namaMaterial << " (" 
                     << materialDb[i].jenisMaterial << ")" << endl;
            }
            cout << "     0. Batal" << endl;
            printLine('=', 50);
            cout << "     Pilih material (nomor): ";
            
            string input;
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Pilihan tidak boleh kosong!");
            }
            
            for (char c : input) {
                if (c < '0' || c > '9') {
                    throw invalid_argument("Harus berupa angka!");
                }
            }
            
            int pilihan = 0;
            for (int i = 0; i < input.length(); i++) {
                pilihan = pilihan * 10 + (input[i] - '0');
            }
            
            if (pilihan == 0) return -1;
            if (pilihan >= 1 && pilihan <= materialIndex) return pilihan - 1;
            
            throw invalid_argument("Pilihan tidak valid!");
        }
        catch (const invalid_argument& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
    }
}

void menuMaterial() {
    string pilihan;
    while (true) {
        clearScreen();
        cout << endl;
        printLine('=', 50);
        cout << "                   MENU MATERIAL                    " << endl;
        printLine('=', 50);
        cout << endl;
        cout << "     1. Lihat Material" << endl;
        cout << "     2. Tambah Material" << endl;
        cout << "     3. Update Material" << endl;
        cout << "     4. Hapus Material" << endl;
        cout << "     0. Kembali" << endl;
        cout << endl;
        printLine('-', 50);
        cout << "     Masukkan Pilihan: ";
        getline(cin, pilihan);
        
        if (pilihan == "1") {
            clearScreen();
            readMaterial();
            pauseScreen();
        } else if (pilihan == "2") {
            clearScreen();
            createMaterial();
            pauseScreen();
        } else if (pilihan == "3") {
            clearScreen();
            updateMaterial();
            pauseScreen();
        } else if (pilihan == "4") {
            clearScreen();
            deleteMaterial();
            pauseScreen();
        } else if (pilihan == "0") {
            break;
        } else {
            cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
            pauseScreen();
        }
    }
}

#endif