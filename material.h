// Done
#ifndef MATERIAL_H
#define MATERIAL_H

#include "library.h"
#include "struct.h"
#include "validation.h"
#include "menu.h"

void readMaterial() {
    if (materialIndex == 0) { // cek data Material
        showError("Data Material Kosong!");
    } else {
        Header("DAFTAR MATERIAL", 53);
        cout << " " << setw(11) << left << "ID Material" << " | "
            << setw(20) << left << "Nama Material" << " | "
            << setw(15) << left << "Jenis Material"  << endl;
        printLine('-', 53);

        for (int i = 0; i < materialIndex; i++) {
            cout << " " << setw(11) << left << materialDb[i].idMaterial << " | "
                << setw(20) << left << materialDb[i].namaMaterial << " | "
                << setw(15) << left << materialDb[i].jenisMaterial << endl;
        }
        
        printLine('-', 53);
        cout << " Total Material: " << materialIndex << endl;
        printLine('=', 53);
    }
}
// Done
void createMaterial() {
    Header("TAMBAH MATERIAL", 50);

    if (materialIndex >= maxmaterial) { // cek kapasitas
        showError("Kapasitas memori penuh!");
        return;
    }

    // Generate ID
    int maxId = 0;
    for (int i = 0; i < materialIndex; i++) {
        string idStr = materialDb[i].idMaterial;
        if (idStr.length() >= 6 && idStr.substr(0, 3) == "MAT") {  // substr(0, 3) ambil "MAT"
            string numStr = idStr.substr(3);  // ambil angka setelah "MAT"
            int num = stoi(numStr); // konversi ke integer
            if (num > maxId) maxId = num; // ketemu idBaru
        }
    }

    int nextId = maxId + 1;
    string idBaru = "MAT";
    if (nextId < 10) {
        idBaru += "00" + to_string(nextId);
    } else if (nextId < 100) {
        idBaru += "0" + to_string(nextId);
    } else {
        idBaru += to_string(nextId);
    }
    material *newMaterial = &materialDb[materialIndex]; // pointer ke elemen baru

    cout << setw(20) << left << "ID Material" << ": " << idBaru << endl;
    newMaterial->idMaterial = idBaru;
    newMaterial->namaMaterial = getNameMat("Nama Material Baru", materialIndex, 100, 20);
    newMaterial->jenisMaterial = getInput("Jenis Material Baru", 50, 20);
    materialIndex++;
    
    printLine('-', 50);
    showSuccess("Material berhasil ditambahkan!");
}

void updateMaterial() {
    Header("UPDATE MATERIAL", 53);
    
    if (materialIndex == 0) {  // cek data mabel
        showError("Data Material Kosong!");
        return;
    }
    
    readMaterial();

    string idCari = getInput("Input ID material", 50, 20);
    
    // cari indeks produk dengan ID yang cocok
    int indexKetemu = -1;
    for (int i = 0; i < materialIndex; i++) {
        if (materialDb[i].idMaterial == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        showError("Material dengan ID " + idCari + " tidak ditemukan!");
        return;
    }

    // variabel temp
    material *updateMaterial = &materialDb[indexKetemu];
    string namaBaru = updateMaterial->namaMaterial;
    string jenisBaru = updateMaterial->jenisMaterial;
    
    string pilihan;
    while (true) {
        clearScreen();
        Header("DATA MATERIAL SAAT INI", 50);
        cout << setw(25) << left << "ID Material" << " : " << materialDb[indexKetemu].idMaterial << endl;
        cout << setw(25) << left << "Nama Material" << " : " << namaBaru << endl;
        cout << setw(25) << left << "Jenis Material" << " : "<< jenisBaru << endl;
        menuUpdateMat();
        getline(cin, pilihan);
        
        if (pilihan == "1") {
            namaBaru = getNameMat("Nama Material Baru", indexKetemu, 100, 20);
        } 
        else if (pilihan == "2") {
            jenisBaru = getInput("Jenis Baru", 100, 15);
        } 
        else if (pilihan == "0") {
            if (confirm("Simpan perubahan material [Y/N]", 22)) {
                updateMaterial->namaMaterial = namaBaru;
                updateMaterial->jenisMaterial = jenisBaru;
                printLine('-', 50);
                showSuccess("Material berhasil diupdate!");
            } else {
                showInfo("Update material dibatalkan");
            }
            return;
        } 
        else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}

void deleteMaterial() {
    Header("HAPUS MATERIAL", 53);
    
    if (materialIndex == 0) { // cek data mabel
        showError("Data Material Kosong!");
        return;
    }
    
    readMaterial();

    string idCari = getInput("Input ID material", 50, 20);
    
    // cari indeks produk dengan ID yang cocok
    int indexKetemu = -1;
    for (int i = 0; i < materialIndex; i++) {
        if (materialDb[i].idMaterial == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        showError("Material dengan ID " + idCari + " tidak ditemukan!");
        return;
    }
    
    // Cek apakah material sedang digunakan
    bool inUse = false;
    string used = "";
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].material.idMaterial == idCari) {
            inUse = true;
            used = mabel[i].namaProduk;
            break;
        }
    }
    
    if (inUse) {
        printLine('-', 53);
        showError("Material sedang digunakan pada produk " + used );
        showInfo("Hapus produk terlebih dahulu!");
        return;
    }
    
    clearScreen();
    Header("KONFIRMASI HAPUS MATERIAL", 50);
    cout << setw(15) << left << "ID Material" << " : " << materialDb[indexKetemu].idMaterial << endl;
    cout << setw(15) << left << "Nama Material" << " : " << materialDb[indexKetemu].namaMaterial << endl;
    cout << setw(15) << left << "Jenis Material" << " : "<< materialDb[indexKetemu].jenisMaterial << endl;
    printLine('=', 50);
    

    if (confirm("Hapus Material ini [Y/N]", 26)) {
        for (int i = indexKetemu; i < materialIndex - 1; i++) { // array material digeser ke kiri mulai dari indexKetemu hingga mabelIndex-1
            materialDb[i] = materialDb[i + 1];
        }
        materialIndex--;
        printLine('-', 50);
        showSuccess("Material berhasil dihapus!");
    } else {
        showInfo("Penghapusan Material dibatalkan");
    }
}

int pilihMaterial() {
    if (materialIndex == 0) {
        showError("Data Material Kosong!");
        return -1;
    }
    
    while (true) {
        Header("PILIH MATERIAL", 62);
        cout << " " << setw(3) << left << "No" << " | "
            << setw(12) << left << "ID Material" << " | "
            << setw(22) << left << "Nama Material" << " | "
            << setw(15) << left << "Jenis Material" << endl;
        printLine('-', 62);

        for (int i = 0; i < materialIndex; i++) {
            cout << " " << setw(3) << left << i+1 << " | "
                << setw(12) << left << materialDb[i].idMaterial << " | "
                << setw(22) << left << materialDb[i].namaMaterial << " | "
                << setw(15) << left << materialDb[i].jenisMaterial << endl;
        }
        cout << " " << setw(3) << left << "0" << " | Batal" << endl;
        printLine('-', 62);
        
        int input = getInt("Pilih material (nomor)", 22);
        
        if (input == 0) {
            return -1;
        } else if (input >= 1 && input <= materialIndex) {
            return input - 1;
        } else {
            showError("Nomor tidak valid. Silakan coba lagi.");
        }
    }
}

void menuMaterial() {
    string pilihan;
    while (true) {
        clearScreen();
        cout << endl;
        menuMat();
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
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}

#endif