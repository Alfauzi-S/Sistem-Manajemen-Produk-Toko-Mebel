#ifndef USER_H
#define USER_H

#include "struct.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Struct untuk menampung sementara barang yang akan dibeli
struct Keranjang {
    int idProduk;
    string namaProduk;
    long long harga;
    int qty;
};

// Variabel Global khusus User
Keranjang keranjangUser[100];
int jmlKeranjang = 0;

// 1. TUGAS BINTANG: Read Data Saya
inline void readDataUser(string name) {
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == name) {
            cout << "========================================" << endl;
            cout << "            PROFIL PENGGUNA             " << endl;
            cout << "========================================" << endl;
            cout << " Nama   : " << user[i].nama << endl;
            cout << " Email  : " << user[i].email << endl;
            cout << " Alamat : " << user[i].alamat.jalan << ", " << user[i].alamat.kota << endl;
            cout << " Saldo  : Rp " << user[i].saldo << endl;
            cout << "========================================" << endl;
            return;
        }
    }
}

// 5. TUGAS BINTANG: Topup
inline void topup(string name) {
    long long nominal;
    cout << " Masukkan nominal Top Up: Rp ";
    cin >> nominal;

    if (nominal <= 0) {
        cout << " [ERROR] Nominal harus lebih dari 0!" << endl;
        return;
    }

    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == name) {
            user[i].saldo += nominal;
            cout << " [SUKSES] Top Up Berhasil! Saldo saat ini: Rp " << user[i].saldo << endl;
            return;
        }
    }
}

// 2. TUGAS BINTANG: Buy (Memasukkan ke Keranjang)
inline void buy() {
    int id, qty;
    bool found = false;

    cout << " Masukkan ID Produk yang ingin dibeli: "; cin >> id;
    cout << " Masukkan Jumlah (Qty): "; cin >> qty;

    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == id) {
            found = true;
            if (mabel[i].stock >= qty && qty > 0) {
                keranjangUser[jmlKeranjang] = {mabel[i].idProduk, mabel[i].namaProduk, mabel[i].harga, qty};
                jmlKeranjang++;
                cout << " [SUKSES] " << mabel[i].namaProduk << " dimasukkan ke keranjang." << endl;
            } else {
                cout << " [ERROR] Stok tidak cukup atau jumlah tidak valid!" << endl;
            }
            break;
        }
    }
    if (!found) cout << " [ERROR] Produk tidak ditemukan!" << endl;
}

// 3. TUGAS BINTANG: Keranjang & Checkout
inline void checkout(string name) {
    if (jmlKeranjang == 0) {
        cout << " [INFO] Keranjang kosong!" << endl;
        return;
    }

    long long total = 0;
    cout << "==========================================================" << endl;
    cout << left << setw(20) << "Produk" << setw(10) << "Harga" << setw(7) << "Qty" << "Subtotal" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < jmlKeranjang; i++) {
        long long sub = keranjangUser[i].harga * keranjangUser[i].qty;
        total += sub;
        cout << left << setw(20) << keranjangUser[i].namaProduk 
             << setw(10) << keranjangUser[i].harga 
             << setw(7) << keranjangUser[i].qty 
             << "Rp " << sub << endl;
    }
    cout << "----------------------------------------------------------" << endl;
    cout << " TOTAL BELANJA : Rp " << total << endl;

    int idxU = -1;
    for (int i = 0; i < userIndex; i++) if (user[i].nama == name) idxU = i;

    if (user[idxU].saldo >= total) {
        char y;
        cout << " Bayar sekarang? (y/n): "; cin >> y;
        if (y == 'y' || y == 'Y') {
            user[idxU].saldo -= total;
            // Kurangi stok asli di mabel[]
            for (int i = 0; i < jmlKeranjang; i++) {
                for (int j = 0; j < mabelIndex; j++) {
                    if (mabel[j].idProduk == keranjangUser[i].idProduk) {
                        mabel[j].stock -= keranjangUser[i].qty;
                    }
                }
            }
            jmlKeranjang = 0;
            cout << " [SUKSES] Pembayaran Berhasil! Sisa Saldo: Rp " << user[idxU].saldo << endl;
        }
    } else {
        cout << " [ERROR] Saldo tidak cukup! Silakan Top Up." << endl;
    }
}

#endif