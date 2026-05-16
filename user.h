// Done
#ifndef USER_H
#define USER_H

#include "library.h"
#include "struct.h"
#include "validation.h"
#include "menu.h"
#include "crud.h"
#include "material.h"
#include "transaction.h"

void updateUser(int idx) {
    if (userIndex == 0) { // cek data user
        showError("Data User Kosong!");
        return;
    }

    // variabel temp
    pengguna *updateUser = &user[idx]; // pointer ke user yang akan diupdate.
    string namaBaru = updateUser->nama;
    string emailBaru = updateUser->email;
    string jalanBaru = updateUser->alamat.jalan;
    string kotaBaru = updateUser->alamat.kota;
    string provinsiBaru = updateUser->alamat.provinsi;

    while (true) {
        clearScreen();
        Header("UPDATE PROFIL", 55);
        cout << setw(15) << left << "Nama" << " : " << namaBaru << endl;
        cout << setw(15) << left << "Email" << " : " << emailBaru << endl;
        cout << setw(15) << left << "Alamat" << " : " << jalanBaru << ", " << kotaBaru << ", " << provinsiBaru << endl;
        printLine('=', 55);
        
        string pilihanUpdate;
        menuUpdateDataUser();
        getline(cin, pilihanUpdate);
        
        if (pilihanUpdate == "1") {
            namaBaru = getName("Nama Baru", idx, 100, 15);
        } else if (pilihanUpdate == "2") {
            emailBaru = getEmail("Email Baru", idx, 15);
        } else if (pilihanUpdate == "3") {
            jalanBaru = getInput("Jalan Baru", 100, 15);
        } else if (pilihanUpdate == "4") {
            kotaBaru = getInput("Kota Baru", 100, 15);
        } else if (pilihanUpdate == "5") {
            provinsiBaru =getInput("Provinsi Baru", 100, 15);
        } else if (pilihanUpdate == "0") {
            if (confirm("Simpan perubahan profil [Y/N]", 22)) {
                updateUser->nama = namaBaru;
                updateUser->email = emailBaru;
                updateUser->alamat.jalan = jalanBaru;
                updateUser->alamat.kota = kotaBaru;
                updateUser->alamat.provinsi = provinsiBaru;
                printLine('-', 55);
                showSuccess("Data user berhasil diupdate!");
            } else {
                printLine('-',55);
                showInfo("Update data user dibatalkan");
            }
            return;
        } else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}

void readUser(string &currentUser) {
    if (userIndex == 0) { // cek data user
        showError("Data User Kosong!");
        return;
    }
    
    // cari indeks user dengan nama yang cocok
    int indexKetemu = -1;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == currentUser) {
            indexKetemu = i;
            break;
        }
    }

    if (indexKetemu == -1) {
        showError("User " + currentUser + " tidak ditemukan!");
        return;
    }

    string pilihan;
    while(true) {
        clearScreen();
        Header("PROFIL PENGGUNA", 55);
        cout << setw(15) << left << "Nama" << " : " << user[indexKetemu].nama << endl;
        cout << setw(15) << left << "Email" << " : " << user[indexKetemu].email << endl;
        cout << setw(15) << left << "Alamat" << " : " << user[indexKetemu].alamat.jalan << ", " << user[indexKetemu].alamat.kota << ", " << user[indexKetemu].alamat.provinsi << endl;
        cout << setw(15) << left << "Saldo" << " : RP " << user[indexKetemu].saldo << endl;
        printLine('=', 55);
        menuUpdateUser();
        getline(cin, pilihan);
        if (pilihan == "1") {
            updateUser(indexKetemu);
        } else if (pilihan == "0") {
            break;
        } else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}

void topup(string &currentUser) {
    if (userIndex == 0) { // cek data user
        showError("Data User Kosong!");
        return;
    }
    
    // cari indeks user dengan nama yang cocok
    int indexKetemu = -1;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == currentUser) {
            indexKetemu = i;
            break;
        }
    }

    if (indexKetemu == -1) {
        showError("User " + currentUser + " tidak ditemukan!");
        return;
    }

    pengguna *topupUser = &user[indexKetemu];
    string pilihan;
    while (true) {
        clearScreen();
        Header("TOP UP SALDO", 50);
        cout << setw(15) << left << "Nama" << " : " << topupUser->nama << endl;
        cout << setw(15) << left << "Saldo" << " : Rp " << topupUser->saldo << endl;
        printLine('=', 50);
        menuTopup();
        getline(cin, pilihan);
        if (pilihan == "1") {
            string inPassword;
            cout << setw(15) << left << "Password" << ": ";
            getline(cin, inPassword);
            if (inPassword == topupUser->password) {
                showInfo("Password Benar");
                printLine('-', 50);
                int inNominal = getIntNotZero("Nominal Top Up", 15);
                if (inNominal > 0) {
                    topupUser->saldo = topupUser->saldo + inNominal; // tambah saldo
                    printLine('-', 50);
                    showSuccess("Top up berhasil!");
                    showInfo("Saldo Baru: Rp" + to_string(topupUser->saldo));
                    pauseScreen();
                }
            } else {
                printLine('-', 50);
                showError("Password salah!");
                pauseScreen();
            }
        } else if (pilihan == "0") {
            return;
        } else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
    
}

void buy(string &currentUser) {
    if (mabelIndex == 0) { // cek data user
        showError("Data Produk Kosong!");
        return;
    };

    read();

    string idCari = getInput("Input ID produk", 50, 20);
    
    // cari indeks produk dengan id yang cocok
    int indexKetemu = -1;
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        showError("Produk dengan ID " + idCari + " tidak ditemukan!");
        return;
    }
    
    int inJumlah = 1;
    string pilihan;
    while (true) {
        clearScreen();
        Header("PEMBELIAN PRODUK", 76);
        cout << " " << setw(8) << left << "ID" << " | "
            << setw(22) << left << "Nama Produk" << " | "
            << setw(6) << left << "Stock" << " | "
            << setw(15) << "Harga" << " | "
            << setw(15) << left << "Jumlah Beli" << endl;
        printLine('-', 76);
        cout << " " << setw(8) << left << mabel[indexKetemu].idProduk << " | "
            << setw(22) << left << mabel[indexKetemu].namaProduk << " | "
            << setw(6) << right << mabel[indexKetemu].stock << " | "
            << "Rp" << setw(13) << right << mabel[indexKetemu].harga << " | "
            << setw(15) << left << inJumlah << endl;
        printLine('-', 76);
        menuJumlah();
        getline(cin, pilihan);
        if (pilihan == "1") {
            int temp = getIntNotZero("Jumlah Beli", 15);
            if (temp > mabel[indexKetemu].stock) {
                showError("Jumlah beli melebihi stok yang tersedia : " + to_string(mabel[indexKetemu].stock));
                pauseScreen();
            } else {
                inJumlah = temp;
            }
        } else if (pilihan == "0") {
            if (confirm("Tambahkan Produk ke Keranjang [Y/N]", 35)) {
                bool sudahAda = false;
                keranjang *addKeranjang = &keranjangUser[keranjangIndex];
                for (int i = 0; i < keranjangIndex; i++) { // cek apakah produk sudah ada di keranjang user
                    if (keranjangUser[i].nama == currentUser && keranjangUser[i].idProduk == mabel[indexKetemu].idProduk) {
                        keranjangUser[i].jumlah = inJumlah; // // update jumlah
                        sudahAda = true;
                        printLine('-', 76);
                        showSuccess("Berhasil memperbarui produk di keranjang!");
                        break;
                    }
                }
                
                if (!sudahAda) { 
                    addKeranjang->nama = currentUser;
                    addKeranjang->idProduk = mabel[indexKetemu].idProduk;
                    addKeranjang->namaProduk = mabel[indexKetemu].namaProduk;
                    addKeranjang->harga = mabel[indexKetemu].harga;
                    addKeranjang->jumlah = inJumlah;
                    keranjangIndex++;
                    printLine('-', 76);
                    showSuccess("Produk ditambahkan ke keranjang!");
                }
                return;
            } else {
                printLine('-', 76);
                showInfo("Penambahan produk dibatalkan");
                return;
            }
        } else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}

void checkout(string &currentUser) {
    // cari indeks user dengan nama yang cocok
    int indexKetemu = -1;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == currentUser) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        showError("User tidak ditemukan!");
        return;
    }
    
    // Cek stok untuk setiap item user
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].nama == currentUser) {
            for (int j = 0; j < mabelIndex; j++) {
                if (mabel[j].idProduk == keranjangUser[i].idProduk) { // cari produk di mabel
                    if (mabel[j].stock < keranjangUser[i].jumlah) { // bandingkan stok
                        showError("Stok " + mabel[j].namaProduk + "tidak cukup, stock yang tersedia : " + to_string(mabel[j].stock));
                        return;
                    }
                }
            }
        }
    }

    // Hitung totalBelanja
    int totalBelanja = 0;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].nama == currentUser) {
            totalBelanja += keranjangUser[i].harga * keranjangUser[i].jumlah;
        }
    }
    
    if (totalBelanja == 0) {
        showError("Keranjang kosong!");
        return;
    }

    pengguna *checkoutUser = &user[indexKetemu];

    Header("RINGKASAN PEMBAYARAN ", 50);
    cout << setw(20) << left << "Nama Pelanggan" << " : " << currentUser << endl;
    cout << setw(20) << left << "Total Tagihan" << " : Rp " << totalBelanja << endl;
    cout << setw(20) << left << "Saldo Anda" << " : Rp " << checkoutUser->saldo << endl;
    printLine('=', 50);

    if (confirm("Bayar [Y/N]", 15)) {    
        string inPassword;
        cout << setw(15) << left << "Password" << ": ";
        getline(cin, inPassword);
        if (checkoutUser->password == inPassword) {
            if (checkoutUser->saldo < totalBelanja) {
                showError("Saldo tidak mencukupi. Silakan Top Up!");
                return;
            }
            
            // kurangi stok produk
            for (int i = 0; i < keranjangIndex; i++) {
                if (keranjangUser[i].nama == currentUser) {
                    for (int j = 0; j < mabelIndex; j++) {
                        if (mabel[j].idProduk == keranjangUser[i].idProduk) {
                            mabel[j].stock = mabel[j].stock - keranjangUser[i].jumlah;
                            break;
                        }
                    }
                }
            }
            
            // kurangi saldo user
            checkoutUser->saldo -= totalBelanja;
            
            // simpan transaksi
            string detailTransaksi = "";
            for (int i = 0; i < keranjangIndex; i++) {
                if (keranjangUser[i].nama == currentUser) {
                    int subtotal = keranjangUser[i].harga * keranjangUser[i].jumlah;
                    detailTransaksi += keranjangUser[i].idProduk + "|"
                                    + keranjangUser[i].namaProduk + "|"
                                    + to_string(keranjangUser[i].jumlah) + "|"
                                    + to_string(keranjangUser[i].harga) + "|"
                                    + to_string(subtotal) + ";";
                }
            }
            saveTransaction(currentUser, totalBelanja, detailTransaksi);

            // Hapus keranjang user
            int j = 0;
            for (int i = 0; i < keranjangIndex; i++) {
                if (keranjangUser[i].nama != currentUser) {
                    keranjangUser[j] = keranjangUser[i];
                    j++;
                }
            }
            keranjangIndex = j;

            printLine('-', 50);
            showSuccess("PEMBAYARAN BERHASIL!");
            showInfo("Sisa Saldo : Rp " + to_string(checkoutUser->saldo));
            cout << "Terima kasih telah berbelanja." << endl;
        } else {
            showError("Password salah!");
        }
    } else {
        showInfo("Checkout dibatalkan");
    }
}

void cart(string &currentUser) {
    // cek keranjang user dengan currentUser
    bool adaItem = false;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].nama == currentUser) {
            adaItem = true;
            break;
        }
    }
    
    if (!adaItem) {
        showError("Keranjang anda Kosong!");
        return;
    }
    string pilihan;
    while (true) {
        clearScreen();
        Header("KERANJANG BELANJA", 85);
        cout << " " << setw(8) << left << "ID" << " | "
            << setw(22) << left << "Nama Produk" << " | "
            << setw(15) << "Harga" << " | "
            << setw(11) << left << "Jumlah Beli" << " | "
            << setw(15) << left << "Sub Total" << endl;
        printLine('-', 85);
        int totalBelanja = 0;
        for (int i = 0; i < keranjangIndex; i++) {
            if (keranjangUser[i].nama == currentUser) {
                cout << " " << setw(8) << left << keranjangUser[i].idProduk << " | "
                    << setw(22) << left << keranjangUser[i].namaProduk << " | "
                    << "Rp" << setw(13) << right << keranjangUser[i].harga << " | "
                    << setw(11) << left <<  keranjangUser[i].jumlah << " | "
                    << "Rp" << setw(13) << right << keranjangUser[i].jumlah * keranjangUser[i].harga << endl;
                    totalBelanja += keranjangUser[i].jumlah * keranjangUser[i].harga;
            }
        }
        printLine('-', 85);
        cout << " Total Belanja : Rp " << totalBelanja << endl;
        printLine('=', 85);
        menuCart();
        getline(cin, pilihan);
        if (pilihan == "1") {
            clearScreen();
            checkout(currentUser);
            break;
        } else if (pilihan == "2") {
            string idUpdate = getInput("Input ID produk yang mau di update", 50, 35);
            // cari item di keranjang user
            bool ditemukan = false;
            for (int i = 0; i < keranjangIndex; i++) {
                if (keranjangUser[i].nama == currentUser && keranjangUser[i].idProduk == idUpdate) {
                    ditemukan = true;
                    // cek stok produk dari mabel
                    int stok = 0;
                    for (int j = 0; j < mabelIndex; j++) {
                        if (mabel[j].idProduk == idUpdate) {
                            stok = mabel[j].stock;
                            break;
                        }
                    }
                    int newJml = getIntNotZero("Jumlah Baru (Stok tersedia " + to_string(stok) + ")" , 35);
                    if (newJml <= stok) {
                        keranjangUser[i].jumlah = newJml;
                        printLine('-', 85);
                        showSuccess("Jumlah berhasil diupdate!");
                    } else {
                        printLine('-', 85);
                        showError("Jumlah beli melebihi stok yang tersedia : " + to_string(stok));
                    }
                    break;
                }
            }
            if (!ditemukan) {
                printLine('-', 85);
                showError("Produk dengan ID " + idUpdate + " tidak ditemukan di keranjang!");
            }
            pauseScreen();
        } else if (pilihan == "3") {
            string idDelete = getInput("Input ID produk yang mau di hapus", 50, 35);
            // cari item
            bool ditemukan = false;
            for (int i = 0; i < keranjangIndex; i++) {
                if (keranjangUser[i].nama == currentUser && keranjangUser[i].idProduk == idDelete) {
                    ditemukan = true;
                    if (confirm("Hapus item ini dari keranjang [Y/N]", 35)) {
                        for (int j = i; j < keranjangIndex - 1; j++) {
                            keranjangUser[j] = keranjangUser[j + 1];
                        }
                        keranjangIndex--;
                        printLine('-', 85);
                        showSuccess("Item berhasil dihapus dari keranjang!");
                    }
                    break;
                }
            }
            if (!ditemukan) {
                printLine('-', 85);
                showError("Produk dengan ID " + idDelete + " tidak ditemukan di keranjang!");
            }
            pauseScreen();
        } else if (pilihan == "0") {
            break;
        } else {
            showError("Pilihan tidak valid!");
            pauseScreen();
        }
    }
}

#endif