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
                showError("Tidak ada produk untuk dicari!");
            } else {
                bubbleSort(mabel, mabelIndex);
                string inputId = getInput("Input ID produk", 50, 16);

                int index = binarySearch(mabel, mabelIndex, inputId);

                if (index == -1) {
                    showError("Produk dengan ID " + inputId + " tidak ditemukan!");
                    return;
                }

                Header("HASIL PENCARIAN", 50);
                cout << setw (17) << left << "ID Produk" << ": " << mabel[index].idProduk << endl;
                cout << setw (17) << left << "Nama Produk" << ": " << mabel[index].namaProduk << endl;
                cout << setw (17) << left << "Jenis Produk" << ": " << mabel[index].jenisProduk << endl;
                cout << setw (17) << left << "Harga" << ": Rp " << mabel[index].harga << endl;
                cout << setw (17) << left << "Stok" << ": " << mabel[index].stock << endl;
                cout << setw (17) << left << "ID Material" << ": " << mabel[index].material.idMaterial << endl;
                cout << setw (17) << left << "Nama Material" << ": " << mabel[index].material.namaMaterial << endl;
                cout << setw (17) << left << "Jenis" << ": " << mabel[index].material.jenisMaterial << endl;
                printLine('=', 50);
            }
            pauseScreen();
        } 
        else if (pilihan == "2") {
            if (mabelIndex == 0) {
                showError("Tidak ada produk untuk dicari!");
            } else {
                string inputNama = getInput("Masukkan Nama Produk", 50, 20);
                                
                int index = linearSearch(mabel, mabelIndex, inputNama);
                
                if (index == -1) {
                    showError("Produk dengan ID " + inputNama + " tidak ditemukan!");
                    return;
                }

                Header("HASIL PENCARIAN", 50);
                cout << setw (17) << left << "ID Produk" << ": " << mabel[index].idProduk << endl;
                cout << setw (17) << left << "Nama Produk" << ": " << mabel[index].namaProduk << endl;
                cout << setw (17) << left << "Jenis Produk" << ": " << mabel[index].jenisProduk << endl;
                cout << setw (17) << left << "Harga" << ": Rp " << mabel[index].harga << endl;
                cout << setw (17) << left << "Stok" << ": " << mabel[index].stock << endl;
                cout << setw (17) << left << "ID Material" << ": " << mabel[index].material.idMaterial << endl;
                cout << setw (17) << left << "Nama Material" << ": " << mabel[index].material.namaMaterial << endl;
                cout << setw (17) << left << "Jenis" << ": " << mabel[index].material.jenisMaterial << endl;
                printLine('=', 50);
            }
            pauseScreen();
        } 
        else if (pilihan == "0") {
            break;
        } 
        else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}

#endif