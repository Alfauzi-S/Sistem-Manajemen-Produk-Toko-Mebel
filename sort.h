#ifndef SORT_H
#define SORT_H

#include "library.h"
#include "struct.h"
#include "crud.h"
#include "menu.h"
#include "validation.h"

void bubbleSort(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].idProduk > arr[j + 1].idProduk) {
                produk temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void sortHargaAsc(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga < arr[minIdx].harga) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            produk temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void sortHargaDesc(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga > arr[maxIdx].harga) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            produk temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}

void Sort() {
    string pilihan;
    while (true) {
        clearScreen();
        menuSort();
        getline(cin, pilihan);
        
        if (pilihan == "1") {
            if (mabelIndex == 0) {
                cout << endl << "     [ERROR] Tidak ada produk untuk diurutkan!" << endl;
            } else {
                bubbleSort(mabel, mabelIndex);
                read();
                cout << endl << "     [SUKSES] Produk berhasil diurutkan berdasarkan ID (Ascending)" << endl;
            }
            pauseScreen();
        } 
        else if (pilihan == "2") {
            if (mabelIndex == 0) {
                cout << endl << "     [ERROR] Tidak ada produk untuk diurutkan!" << endl;
            } else {
                cout << endl;
                printLine('-', 50);
                cout << "     1. Termurah ke Termahal (Ascending)" << endl;
                cout << "     2. Termahal ke Termurah (Descending)" << endl;
                printLine('-', 50);
                cout << "     Pilihan: ";
                string sub;
                getline(cin, sub);
                
                if (sub == "1") {
                    sortHargaAsc(mabel, mabelIndex);
                    cout << endl << "     [SUKSES] Produk diurutkan dari harga termurah ke termahal" << endl;
                } else if (sub == "2") {
                    sortHargaDesc(mabel, mabelIndex);
                    cout << endl << "     [SUKSES] Produk diurutkan dari harga termahal ke termurah" << endl;
                } else {
                    cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
                    pauseScreen();
                    continue;
                }
                read();
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