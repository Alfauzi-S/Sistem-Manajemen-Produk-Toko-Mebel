// Done
#ifndef AUTH_H
#define AUTH_H

#include "library.h"
#include "struct.h"
#include "validation.h"

bool login(bool *isAdmin, string *currentUser) {
    if (!isAdmin || !currentUser) { // memastikan pointer tidak null
        showError("Pointer tidak valid!");
        return false;
    }

    Header("LOGIN", 50);

    int kesempatan = 3;
    string inNama, inPassword;
    
    while (kesempatan > 0) {
        cout << setw(15) << left << "Username" << ": ";
        getline(cin, inNama);
        cout << setw(15) << left << "Password" << ": ";
        getline(cin, inPassword);

        for (int i = 0; i < adminIndex; i++) { // cek di data admin
            if (admin[i].nama == inNama && admin[i].password == inPassword) {
                printLine('-', 50);
                showInfo("LOGIN BERHASIL ADMIN - Selamat Datang " + inNama);
                *isAdmin = true;
                *currentUser = inNama;
                return true;
            }
        }

        for (int i = 0; i < userIndex; i++) { // cek di data user
            if (user[i].nama == inNama && user[i].password == inPassword) {
                printLine('-', 50);
                showInfo("LOGIN BERHASIL USER - Selamat Datang " + inNama);
                *isAdmin = false;
                *currentUser = inNama;
                return true;
            }
        }

        kesempatan--;
        if (kesempatan > 0) {
            showInfo("LOGIN GAGAL - Sisa percobaan: " + to_string(kesempatan));
            printLine('-', 50);
        }
    }
    showInfo("LOGIN GAGAL - Anda telah mencapai batas maksimal.");
    return false;
}

void regis() {
    Header("REGISTER", 50);

    if (userIndex >= maxuser) { // Cek Kapasitas
        showError("Kapasitas pengguna penuh!");
        return;
    }

    pengguna* newUser = &user[userIndex];

    newUser->nama = getName("Nama", userIndex, 100, 15);
    newUser->password = getPassword("Password", 8, 100, 15);
    newUser->email = getEmail("Email", userIndex, 15);

    printLine('-', 50);
    newUser->alamat.jalan = getInput("Alamat Jalan", 100, 15);
    newUser->alamat.kota = getInput("Kota", 100, 15);
    newUser->alamat.provinsi = getInput("Provinsi", 100, 15);
    
    newUser->saldo = 0;

    userIndex++;

    printLine('-', 50);
    showSuccess("REGISTER BERHASIL");
}

#endif