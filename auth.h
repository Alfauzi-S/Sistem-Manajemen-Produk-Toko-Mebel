#ifndef AUTH_H
#define AUTH_H

#include "library.h"
#include "struct.h"
#include "validation.h"
// Done
bool login(bool *isAdmin, string *currentUser) {
    printLine('=', 50);
    cout << "                     LOGIN                       " << endl;
    printLine('=', 50);

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
                cout << "[LOGIN BERHASIL] Admin" << endl;
                cout << "Selamat Datang, " << inNama << "!" << endl;
                *isAdmin = true;
                *currentUser = inNama;
                return true;
            }
        }

        for (int i = 0; i < userIndex; i++) {
            if (user[i].nama == inNama && user[i].password == inPassword) {
                printLine('-', 50);
                cout << "[LOGIN BERHASIL] User" << endl;
                cout << "Selamat Datang, " << inNama << "!" << endl;
                *isAdmin = false;
                *currentUser = inNama;
                return true;
            }
        }

        kesempatan--;
        if (kesempatan > 0) {
            cout << "[LOGIN GAGAL]" << endl;
            cout << "Sisa percobaan: " << kesempatan << endl;
            printLine('-', 50);
        }
    }
    
    cout << "[LOGIN GAGAL]" << endl;
    cout << "Anda telah mencapai batas maksimal." << endl;
    return false;
}
// Done
void regis() {
    printLine('=', 50);
    cout << "                   REGISTER                      " << endl;
    printLine('=', 50);

    if (userIndex >= maxuser) {
        showError("Kapasitas pengguna penuh!");
        return;
    }

    pengguna* newUser = &user[userIndex];

    newUser->nama = getValidatedName("Nama", userIndex);
    newUser->password = getValidatedPassword("Password", 8, 50);
    newUser->email = getValidatedEmail("Email", userIndex);

    printLine('-', 50);
    newUser->alamat.jalan = getValidatedInput("Alamat Jalan", 100);
    newUser->alamat.kota = getValidatedInput("Kota", 50);
    newUser->alamat.provinsi = getValidatedInput("Provinsi", 50);
    
    newUser->saldo = 0;

    userIndex++;

    printLine('-', 50);
    showSuccess("REGISTER BERHASIL");
}

#endif