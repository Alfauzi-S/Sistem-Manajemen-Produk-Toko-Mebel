#ifndef SEARCH_H
#define SEARCH_H

#include "library.h"
#include "struct.h"
#include "sort.h"
#include "menu.h"
#include "validation.h"

int binarySearch(produk arr[], int n, const string& target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid].idProduk == target) {
            return mid;
        } else if (arr[mid].idProduk < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int linearSearch(produk arr[], int n, string target) {
    for (int i = 0; i < n; i++) {
        if (arr[i].namaProduk == target) {
            return i;
        }
    }
    return -1;
}

void Search() {
    string pilihan;
    while (true) {
        clearScreen();
        menuSearch();
        getline(cin, pilihan);
        
        if (pilihan == "1") {
            if (mabelIndex == 0) {
                cout << endl << "     [ERROR] Tidak ada produk untuk dicari!" << endl;
            } else {
                // Urutkan array berdasarkan idProduk (string)
                bubbleSort(mabel, mabelIndex);
                
                cout << endl;
                printLine('-', 50);
                cout << "     Masukkan ID Produk (angka saja) : ";
                string inputId;
                getline(cin, inputId);
                
                // Validasi input berupa angka
                bool valid = true;
                for (char c : inputId) {
                    if (!isdigit(c)) {
                        valid = false;
                        break;
                    }
                }
                
                if (!valid || inputId.empty()) {
                    cout << endl << "     [ERROR] ID harus berupa angka!" << endl;
                    pauseScreen();
                    continue;
                }
                
                // Konversi ke integer
                int idNum = stoi(inputId);
                
                // Format menjadi "PRDxxx"
                stringstream ss;
                ss << "PRD" << setw(3) << setfill('0') << idNum;
                string targetId = ss.str();
                
                // Cari dengan binary search
                int index = binarySearch(mabel, mabelIndex, targetId);
                
                if (index != -1) {
                    cout << endl;
                    printLine('=', 50);
                    cout << "                 HASIL PENCARIAN                 " << endl;
                    printLine('=', 50);
                    cout << "     ID Produk      : " << mabel[index].idProduk << endl;
                    cout << "     Nama Produk    : " << mabel[index].namaProduk << endl;
                    cout << "     Jenis Produk   : " << mabel[index].jenisProduk << endl;
                    cout << "     Harga          : Rp " << mabel[index].harga << endl;
                    cout << "     Stok           : " << mabel[index].stock << endl;
                    cout << "     ID Material    : " << mabel[index].material.idMaterial << endl;
                    cout << "     Nama Material  : " << mabel[index].material.namaMaterial << endl;
                    cout << "     Jenis Material : " << mabel[index].material.jenisMaterial << endl;
                    printLine('=', 50);
                } else {
                    cout << endl << "     [ERROR] Produk dengan ID " << targetId << " tidak ditemukan!" << endl;
                }
            }
            pauseScreen();
        } 
        else if (pilihan == "2") {
            // Pencarian berdasarkan nama (linear search) tidak perlu diubah
            if (mabelIndex == 0) {
                cout << endl << "     [ERROR] Tidak ada produk untuk dicari!" << endl;
            } else {
                cout << endl;
                printLine('-', 50);
                cout << "     Masukkan Nama Produk : ";
                string target;
                getline(cin, target);
                
                int index = linearSearch(mabel, mabelIndex, target);
                
                if (index != -1) {
                    cout << endl;
                    printLine('=', 50);
                    cout << "                 HASIL PENCARIAN                 " << endl;
                    printLine('=', 50);
                    cout << "     ID Produk      : " << mabel[index].idProduk << endl;
                    cout << "     Nama Produk    : " << mabel[index].namaProduk << endl;
                    cout << "     Jenis Produk   : " << mabel[index].jenisProduk << endl;
                    cout << "     Harga          : Rp " << mabel[index].harga << endl;
                    cout << "     Stok           : " << mabel[index].stock << endl;
                    cout << "     ID Material    : " << mabel[index].material.idMaterial << endl;
                    cout << "     Nama Material  : " << mabel[index].material.namaMaterial << endl;
                    cout << "     Jenis Material : " << mabel[index].material.jenisMaterial << endl;
                    printLine('=', 50);
                } else {
                    cout << endl << "     [ERROR] Produk dengan nama '" << target << "' tidak ditemukan!" << endl;
                }
            }
            pauseScreen();
        } 
        else if (pilihan == "0") {
            break;
        } 
        else {
            cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
            pauseScreen();
        }
    }
}

#endif