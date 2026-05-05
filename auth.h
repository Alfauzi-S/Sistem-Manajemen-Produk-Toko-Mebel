#ifndef AUTH_H
#define AUTH_H

#include "library.h"
#include "struct.h"

bool login(bool &isAdmin, string &currentUser) {
    cout << "===============================================" << endl;
    cout << "                      LOGIN                    " << endl;
    cout << "===============================================" << endl;

    int kesempatan = 3;
    string inNama, inPassword;
    while (kesempatan > 0) {
        cout << left << setw(20) <<"Masukkan Nama" << ": ";
        getline(cin, inNama);
        cout << left << setw(20) <<"Masukkan Password" << ": ";
        getline(cin, inPassword);

        for (int i = 0; i < adminIndex; i++) {
            if (admin[i].nama == inNama && admin[i].password == inPassword) {
                cout << "===============================================" << endl;
                cout << "[Login Admin Berhasil! Selamat Datang, " << inNama << "]" << endl;
                isAdmin = true;
                currentUser = admin[i].nama;
                return true;
            }
        }

        for (int i = 0; i < userIndex; i++) {
            if (user[i].nama == inNama && user[i].password == inPassword) {
                cout << "===============================================" << endl;
                cout << "[Login User Berhasil! Selamat Datang, " << inNama << "]" << endl;
                isAdmin = false;
                currentUser = user[i].nama;
                return true;
            }
        }

        kesempatan--;
        if (kesempatan > 0) {
            cout << "\n[Login Gagal! Sisa percobaan: " << kesempatan << "]" << endl;
        } else {
            return false;
        }
    }
    return false;
}

void regis() {
    cout << "==============================================" << endl;
    cout << "                    REGISTER                  " << endl;
    cout << "==============================================" << endl;

    if (userIndex >= maxuser){
        cout << "[kapasitas memori penuh]" << endl;
        return;
    }
    string tempNama;
    while (true) {
        cout << left << setw(20) <<"Masukkan Nama" << ": ";
        getline(cin, tempNama);

        bool namaDuplikat = false;
        for (int i = 0; i < userIndex; i++) {
            if (user[i].nama == tempNama) {
                namaDuplikat = true;
                break; 
            }
        }

        if (namaDuplikat) {
            cout << "[Nama sudah terdaftar. Gunakan nama lain]" << endl;
            continue;
        }
        break; 
    }
    user[userIndex].nama = tempNama;

    cout << left << setw(20) <<"Masukkan Password" << ": ";
    getline(cin, user[userIndex].password);
    cout << left << setw(20) <<"Masukkan Email" << ": ";
    getline(cin, user[userIndex].email);
    cout << "----------------------------------------------" << endl;
    cout << left << setw(20) <<"Masukkan Jalan" << ": ";
    getline(cin, user[userIndex].alamat.jalan);
    cout << left << setw(20) <<"Masukkan Kota" << ": ";
    getline(cin, user[userIndex].alamat.kota);
    cout << left << setw(20) <<"Masukkan provinsi" << ": ";
    getline(cin, user[userIndex].alamat.provinsi);
    user[userIndex].saldo = 0;
    userIndex++;

    cout << "==============================================" << endl;
    cout << "[Register User Berhasil!]" << endl;
}

#endif