#ifndef SORT_H
#define SORT_H

#include "library.h"
#include "crud.h"
#include "struct.h"

void bubbleSort(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].idProduk > arr[j + 1].idProduk) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void selectionSort(produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga > arr[min_idx].harga) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

void menuSort() {
    string pilihan;
    while (true) {
        system("cls");
        cout << "1. Urutkan ID Produk" << endl;
        cout << "2. Urutkan Harga" << endl;
        cout << "0. Kembali ke Menu Sebelumnya" << endl;
        cout << "Masukkan Pilihan: ";
        getline(cin, pilihan);

        if (pilihan == "1") {
            system("cls");
            if (mabelIndex == 0) {
                cout << "\nTidak ada produk untuk diurutkan." << endl;
            } else {
                bubbleSort(mabel, mabelIndex);
                read();
            }
            system("pause");
        } else if(pilihan == "2") {
            system("cls");
            if (mabelIndex == 0) {
                cout << "\nTidak ada produk untuk diurutkan." << endl;
            } else {
                selectionSort(mabel, mabelIndex);
                read();
            }
            system("pause");
        } else if (pilihan == "0") {
            break;
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            system("pause");
        }
    }
}

#endif