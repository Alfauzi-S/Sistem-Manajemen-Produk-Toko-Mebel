#ifndef AUTH_H
#define AUTH_H

#include "library.h"
#include "struct.h"
#include "validation.h"
// Done
bool login(bool *isAdmin, string *currentUser) {
    Header("LOGIN", 50);

    int kesempatan = 3;
    string inNama, inPassword;
    
    while (kesempatan > 0) {
        cout << setw(15) << left << "Username" << ": ";
        getline(cin, inNama);
        cout << setw(15) << left << "Password" << ": ";
        getline(cin, inPassword);

        for (int i = 0; i < adminIndex; i++) {
            if (admin[i].nama == inNama && admin[i].password == inPassword) {
                printLine('-', 50);
                showInfo("LOGIN BERHASIL ADMIN - Selamat Datang " + inNama);
                *isAdmin = true;
                *currentUser = inNama;
                return true;
            }
        }

        for (int i = 0; i < userIndex; i++) {
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
// Done
void regis() {
    Header("REGISTER", 50);

    if (userIndex >= maxuser) {
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