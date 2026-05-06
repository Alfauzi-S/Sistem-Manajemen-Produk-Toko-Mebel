#ifndef SEARCH_H
#define SEARCH_H

#include "library.h"
#include "sort.h"
#include "struct.h"
#include "error_handling.h"

int binarySearch(produk* arr, int n, int target) {
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

int linearSearch(produk* arr, int n, const string& target) {
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
        system("cls");
        menuSearch();
        getline(cin, pilihan);

        if (pilihan == "1") {
            system("cls");
            if (mabelIndex == 0) {
                cout << "\nTidak ada produk untuk dicari." << endl;
            } else {
                bubbleSort(mabel, mabelIndex);
                int target = getPositiveInt("Masukan ID: ");
                int index = binarySearch(mabel, mabelIndex, target);
                if (index != -1) {
                    cout << "\nProduk ditemukan!, " << "Index : " << index << endl;
                    cout << "ID: " << mabel[index].idProduk << endl;
                    cout << "Nama: " << mabel[index].namaProduk << endl;
                    cout << "Harga: Rp " << mabel[index].harga << endl;
                    cout << "Stok: " << mabel[index].stock << endl;
                    cout << "ID Material: " << mabel[index].material.idMaterial << endl;
                    cout << "Nama Material: " << mabel[index].material.namaMaterial << endl;
                    cout << "Jenis Material: " << mabel[index].material.jenisMaterial << endl;
                } else {
                    cout << "\nProduk dengan ID " << target << " tidak ditemukan." << endl;
                }
            }
            system("pause");
        } else if (pilihan == "2") {
            system("cls");
            if (mabelIndex == 0) {
                cout << "\nTidak ada produk untuk dicari." << endl;
            } else {
                string target;
                cout << "Masukan Nama Produk: ";
                getline(cin, target);
                int index = linearSearch(mabel, mabelIndex, target);
                if (index != -1) {
                    cout << "\nProduk ditemukan!, " << "Index : " << index << endl;
                    cout << "ID: " << mabel[index].idProduk << endl;
                    cout << "Nama: " << mabel[index].namaProduk << endl;
                    cout << "Harga: Rp " << mabel[index].harga << endl;
                    cout << "Stok: " << mabel[index].stock << endl;
                    cout << "ID Material: " << mabel[index].material.idMaterial << endl;
                    cout << "Nama Material: " << mabel[index].material.namaMaterial << endl;
                    cout << "Jenis Material: " << mabel[index].material.jenisMaterial << endl;
                } else {
                    cout << "\nProduk dengan Nama " << target << " tidak ditemukan." << endl;
                }
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