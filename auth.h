#ifndef AUTH_H
#define AUTH_H

#include "struct.h"

bool login(bool &isAdmin, string &currentUser) {
    int kesempatan = 3;
    string inNama, inPassword;
    while (kesempatan > 0) {
        cout << "Masukkan Nama: ";
        getline(cin, inNama);
        cout << "Masukkan Password: ";
        getline(cin, inPassword);

        for (int i = 0; i < adminIndex; i++) {
            if (admin[i].nama == inNama && admin[i].password == inPassword) {
                cout << "\nLogin Admin Berhasil! Selamat Datang, " << inNama << endl;
                isAdmin = true;
                currentUser = admin[i].nama;
                return true;
            }
        }

        for (int i = 0; i < userIndex; i++) {
            if (user[i].nama == inNama && user[i].password == inPassword) {
                cout << "\nLogin User Berhasil! Selamat Datang, " << inNama << endl;
                isAdmin = false;
                currentUser = user[i].nama;
                return true;
            }
        }

        kesempatan--;
        if (kesempatan > 0) {
            cout << "\nLogin Gagal! Sisa percobaan: " << kesempatan << endl;
        } else {
            cout << "\nLogin Gagal! Anda telah mencapai batas percobaan maksimal." << endl;
            cout << "Program akan keluar..." << endl;
            return false;
        }
    }
    return false;
}

void regis(){
    if (userIndex >= maxuser){
        cout << "kapasitas memori penuh" << endl;
        return;
    }
    string tempNama;
    while (true) {
        cout << "Masukkan Nama : ";
        getline(cin, tempNama);

        if (!isValidName(tempNama)) {
            cout << "Nama hanya boleh berisi huruf dan spasi" << endl;
            continue; 
        }

        bool namaDuplikat = false;
        for (int i = 0; i < userIndex; i++) {
            if (user[i].nama == tempNama) {
                namaDuplikat = true;
                break; 
            }
        }

        if (namaDuplikat) {
            cout << "(Nama sudah terdaftar. Gunakan nama lain)" << endl;
            continue;
        }
        break; 
    }
    user[userIndex].nama = tempNama;

    cout << "Masukkan Password : ";
    getline(cin, user[userIndex].password);

    while (true){
        cout << "Masukkan Email : ";
        getline(cin, user[userIndex].email);
        if (!isValidEmail(user[userIndex].email)){
            cout << "(Email harus menggunakan '@' dan '.')" << endl;
        } else {
            break;
        }
    }

    cout << "===Masukkan alamat===" << endl;
    cout << "Masukkan Jalan : ";
    getline(cin, user[userIndex].alamat.jalan);

    while (true) {
        cout << "Masukkan Kota : ";
        getline(cin, user[userIndex].alamat.kota);
        if (!isValidName(user[userIndex].alamat.kota)) {
            cout << "(Kota hanya boleh huruf dan spasi)" << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "Masukkan provinsi : ";
        getline(cin, user[userIndex].alamat.provinsi);
        if (!isValidName(user[userIndex].alamat.provinsi)){
            cout << "(provinsi hanya huruf dan spasi)" << endl;
        } else {
            break;
        }
    }

    user[userIndex].saldo = 0;
    cout << "===Registrasi berhasil===" << endl;
    userIndex++;
}

#endif