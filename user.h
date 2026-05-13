// #ifndef USER_H
// #define USER_H

// #include "library.h"
// #include "struct.h"
// #include "validation.h"
// #include "menu.h"
// #include "crud.h"
// #include "material.h"

// void readUser(string name) {
//     cout << endl;
//     printLine('=', 50);
//     cout << "                 PROFIL PENGGUNA                  " << endl;
//     printLine('=', 50);
    
//     for (int i = 0; i < userIndex; i++) {
//         if (user[i].nama == name) {
//             cout << "     Nama      : " << user[i].nama << endl;
//             cout << "     Email     : " << user[i].email << endl;
//             cout << "     Alamat    : " << user[i].alamat.jalan << ", " 
//                  << user[i].alamat.kota << ", " << user[i].alamat.provinsi << endl;
//             cout << "     Saldo     : Rp " << user[i].saldo << endl;
//             printLine('=', 50);
//             return;
//         }
//     }
// }

// void readUserandUpdate(string &currentUser) {
//     int indexKetemu = -1;
//     for (int i = 0; i < userIndex; i++) {
//         if (user[i].nama == currentUser) {
//             indexKetemu = i;
//             break;
//         }
//     }

//     if (indexKetemu == -1) {
//         cout << endl << "     [ERROR] User " << currentUser << " tidak ditemukan!" << endl;
//         return;
//     }
    
//     string pilihanUtama;
//     while (true) {
//         clearScreen();
//         readUser(currentUser);
//         cout << endl;
//         cout << "     1. Update Data User" << endl;
//         cout << "     0. Exit" << endl;
//         cout << endl;
//         printLine('-', 50);
//         cout << "     Masukan Pilihan: ";
//         getline(cin, pilihanUtama);
        
//         if (pilihanUtama == "1") {
//             string namaBaru = user[indexKetemu].nama;
//             string emailBaru = user[indexKetemu].email;
//             string jalanBaru = user[indexKetemu].alamat.jalan;
//             string kotaBaru = user[indexKetemu].alamat.kota;
//             string provinsiBaru = user[indexKetemu].alamat.provinsi;
            
//             while (true) {
//                 clearScreen();
//                 cout << endl;
//                 printLine('=', 50);
//                 cout << "                 UPDATE PROFIL                  " << endl;
//                 printLine('=', 50);
//                 cout << "     Nama      : " << namaBaru << endl;
//                 cout << "     Email     : " << emailBaru << endl;
//                 cout << "     Alamat    : " << jalanBaru << ", " << kotaBaru << ", " << provinsiBaru << endl;
//                 printLine('=', 50);
//                 cout << endl;
//                 cout << "     1. Ubah Nama" << endl;
//                 cout << "     2. Ubah Email" << endl;
//                 cout << "     3. Ubah Jalan" << endl;
//                 cout << "     4. Ubah Kota" << endl;
//                 cout << "     5. Ubah Provinsi" << endl;
//                 cout << "     0. Simpan & Keluar" << endl;
//                 cout << endl;
//                 printLine('-', 50);
//                 cout << "     Masukan Pilihan: ";
                
//                 string pilihanUpdate;
//                 getline(cin, pilihanUpdate);
                
//                 if (pilihanUpdate == "1") {
//                     cout << endl;
//                     namaBaru = getValidatedName("     Nama Baru", indexKetemu);
//                 } 
//                 else if (pilihanUpdate == "2") {
//                     cout << endl;
//                     emailBaru = getValidatedEmail("     Email Baru", indexKetemu);
//                 } 
//                 else if (pilihanUpdate == "3") {
//                     cout << "     Jalan Baru : ";
//                     getline(cin, jalanBaru);
//                     if (jalanBaru.empty()) {
//                         cout << "     [ERROR] Jalan tidak boleh kosong!" << endl;
//                         jalanBaru = user[indexKetemu].alamat.jalan;
//                         pauseScreen();
//                     }
//                 } 
//                 else if (pilihanUpdate == "4") {
//                     cout << "     Kota Baru : ";
//                     getline(cin, kotaBaru);
//                     if (kotaBaru.empty()) {
//                         cout << "     [ERROR] Kota tidak boleh kosong!" << endl;
//                         kotaBaru = user[indexKetemu].alamat.kota;
//                         pauseScreen();
//                     }
//                 } 
//                 else if (pilihanUpdate == "5") {
//                     cout << "     Provinsi Baru : ";
//                     getline(cin, provinsiBaru);
//                     if (provinsiBaru.empty()) {
//                         cout << "     [ERROR] Provinsi tidak boleh kosong!" << endl;
//                         provinsiBaru = user[indexKetemu].alamat.provinsi;
//                         pauseScreen();
//                     }
//                 } 
//                 else if (pilihanUpdate == "0") {
//                     cout << endl;
//                     if (confirm("     Simpan perubahan")) {
//                         user[indexKetemu].nama = namaBaru;
//                         user[indexKetemu].email = emailBaru;
//                         user[indexKetemu].alamat.jalan = jalanBaru;
//                         user[indexKetemu].alamat.kota = kotaBaru;
//                         user[indexKetemu].alamat.provinsi = provinsiBaru;
//                         currentUser = user[indexKetemu].nama;
//                         cout << endl;
//                         printLine('=', 50);
//                         cout << "     [SUKSES] Data berhasil diupdate!" << endl;
//                         printLine('=', 50);
//                     } else {
//                         cout << endl;
//                         printLine('=', 50);
//                         cout << "     [INFO] Update data dibatalkan" << endl;
//                         printLine('=', 50);
//                     }
//                     break;
//                 } 
//                 else {
//                     cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
//                     pauseScreen();
//                 }
//             }
//         } 
//         else if (pilihanUtama == "0") {
//             break;
//         } 
//         else {
//             cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
//             pauseScreen();
//         }
//     }
// }

// void topup(string name) {
//     int indexKetemu = -1;
//     for (int i = 0; i < userIndex; i++) {
//         if (user[i].nama == name) {
//             indexKetemu = i;
//             break;
//         }
//     }

//     if (indexKetemu == -1) {
//         cout << endl << "     [ERROR] User tidak ditemukan!" << endl;
//         return;
//     }

//     cout << endl;
//     printLine('=', 50);
//     cout << "                  TOP UP SALDO                   " << endl;
//     printLine('=', 50);
//     cout << "     Nama          : " << user[indexKetemu].nama << endl;
//     cout << "     Saldo Saat Ini: Rp " << user[indexKetemu].saldo << endl;
//     printLine('=', 50);
    
//     cout << endl;
//     cout << "     1. Top Up" << endl;
//     cout << "     0. Exit" << endl;
//     cout << endl;
//     printLine('-', 50);
//     cout << "     Masukan Pilihan: ";

//     string pilihan;
//     getline(cin, pilihan);
    
//     if (pilihan == "1") {
//         string inPassword;
//         cout << "     Password : ";
//         getline(cin, inPassword);
        
//         if (inPassword == user[indexKetemu].password) {
//             int inNominal = getPositiveInt("     Nominal Top Up");
//             if (inNominal > 0) {
//                 user[indexKetemu].saldo = user[indexKetemu].saldo + inNominal;
//                 cout << endl;
//                 printLine('=', 50);
//                 cout << "     [SUKSES] Top up berhasil!" << endl;
//                 cout << "     Saldo Baru: Rp " << user[indexKetemu].saldo << endl;
//                 printLine('=', 50);
//             }
//         } else {
//             cout << endl << "     [ERROR] Password salah!" << endl;
//         }
//     } else if (pilihan == "0") {
//         return;
//     } else {
//         cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
//     }
// }

// void buy(string name) {
//     if (mabelIndex == 0) {
//         cout << endl << "     [ERROR] Data Produk Kosong!" << endl;
//         return;
//     };

//     read();
    
//     int idCari = getPositiveInt("     ID Produk yang ingin dibeli");
//     int indexKetemu = -1;
    
//     for (int i = 0; i < mabelIndex; i++) {
//         if (mabel[i].idProduk == idCari) {
//             indexKetemu = i;
//             break;
//         }
//     }

//     if (indexKetemu == -1) {
//         cout << endl << "     [ERROR] Produk dengan ID " << idCari << " tidak ditemukan!" << endl;
//         return;
//     }
    
//     int inJumlah = 0;
//     while (true) {
//         clearScreen();
//         cout << endl;
//         printLine('=', 70);
//         cout << "                    PEMBELIAN PRODUK                     " << endl;
//         printLine('=', 70);
        
//         cout << " ID   | Nama Produk              | Harga      | Jumlah | Stok" << endl;
//         printLine('-', 70);
        
//         // Format output
//         cout << " " << setw(3) << right << mabel[indexKetemu].idProduk << " | ";
//         string nama = mabel[indexKetemu].namaProduk;
//         if (nama.length() > 22) nama = nama.substr(0, 19) + "...";
//         cout << setw(22) << left << nama << " | ";
//         cout << "Rp" << setw(8) << right << mabel[indexKetemu].harga << " | ";
//         cout << setw(6) << right << inJumlah << " | ";
//         cout << setw(4) << right << mabel[indexKetemu].stock << endl;
        
//         printLine('=', 70);
//         cout << endl;
//         cout << "     1. Ubah Jumlah" << endl;
//         cout << "     0. Tambah ke Keranjang" << endl;
//         cout << endl;
//         printLine('-', 70);
//         cout << "     Masukan Pilihan: ";
        
//         string pilihan;
//         getline(cin, pilihan);
        
//         if (pilihan == "1") {
//             while (true) {
//                 int temp = getPositiveInt("     Jumlah Beli");
//                 if (temp > mabel[indexKetemu].stock) {
//                     cout << "     [ERROR] Jumlah melebihi stok! Tersedia: " << mabel[indexKetemu].stock << endl;
//                 } else if (temp <= 0) {
//                     cout << "     [ERROR] Jumlah harus lebih dari 0!" << endl;
//                 } else {
//                     inJumlah = temp;
//                     break;
//                 }
//             }
//         } else if (pilihan == "0") {
//             if (inJumlah == 0) {
//                 cout << endl << "     [ERROR] Belum memilih jumlah!" << endl;
//                 pauseScreen();
//                 return;
//             }
            
//             cout << endl;
//             if (confirm("     Tambahkan Produk ke Keranjang")) {
//                 bool sudahAda = false;
//                 for (int i = 0; i < keranjangIndex; i++) {
//                     if (keranjangUser[i].nama == name && keranjangUser[i].idProduk == mabel[indexKetemu].idProduk) {
//                         keranjangUser[i].jumlah = inJumlah;
//                         sudahAda = true;
//                         cout << endl;
//                         printLine('=', 50);
//                         cout << "     [SUKSES] Berhasil memperbarui produk di keranjang!" << endl;
//                         printLine('=', 50);
//                         break;
//                     }
//                 }
                
//                 if (!sudahAda) {
//                     keranjangUser[keranjangIndex].nama = name;
//                     keranjangUser[keranjangIndex].idProduk = mabel[indexKetemu].idProduk;
//                     keranjangUser[keranjangIndex].namaProduk = mabel[indexKetemu].namaProduk;
//                     keranjangUser[keranjangIndex].harga = mabel[indexKetemu].harga;
//                     keranjangUser[keranjangIndex].jumlah = inJumlah;
//                     keranjangIndex++;
//                     cout << endl;
//                     printLine('=', 50);
//                     cout << "     [SUKSES] Produk ditambahkan ke keranjang!" << endl;
//                     printLine('=', 50);
//                 }
//                 return;
//             } else {
//                 cout << endl;
//                 printLine('=', 50);
//                 cout << "     [INFO] Penambahan produk dibatalkan" << endl;
//                 printLine('=', 50);
//                 return;
//             }
//         } else {
//             cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
//             pauseScreen();
//         }
//     }
// }

// void checkout(string name) {
//     int userIdx = -1;
//     for (int i = 0; i < userIndex; i++) {
//         if (user[i].nama == name) {
//             userIdx = i;
//             break;
//         }
//     }
    
//     if (userIdx == -1) {
//         cout << endl << "     [ERROR] User tidak ditemukan!" << endl;
//         return;
//     }
    
//     // Cek stok
//     for (int i = 0; i < keranjangIndex; i++) {
//         if (keranjangUser[i].nama == name) {
//             for (int j = 0; j < mabelIndex; j++) {
//                 if (mabel[j].idProduk == keranjangUser[i].idProduk) {
//                     if (mabel[j].stock < keranjangUser[i].jumlah) {
//                         cout << endl << "     [ERROR] Stok " << mabel[j].namaProduk 
//                              << " tidak cukup (Sisa: " << mabel[j].stock << ")" << endl;
//                         return;
//                     }
//                 }
//             }
//         }
//     }

//     int totalBelanja = 0;
//     for (int i = 0; i < keranjangIndex; i++) {
//         if (keranjangUser[i].nama == name) {
//             totalBelanja = totalBelanja + (keranjangUser[i].harga * keranjangUser[i].jumlah);
//         }
//     }
    
//     if (totalBelanja == 0) {
//         cout << endl << "     [ERROR] Keranjang kosong!" << endl;
//         return;
//     }

//     cout << endl;
//     printLine('=', 50);
//     cout << "               RINGKASAN PEMBAYARAN               " << endl;
//     printLine('=', 50);
//     cout << "     Nama Pelanggan : " << name << endl;
//     cout << "     Total Tagihan  : Rp " << totalBelanja << endl;
//     cout << "     Saldo Anda     : Rp " << user[userIdx].saldo << endl;
//     printLine('=', 50);

//     if (confirm("     Bayar")) {    
//         string inPassword;
//         cout << "     Password : ";
//         getline(cin, inPassword);
        
//         if (user[userIdx].password == inPassword) {
//             if (user[userIdx].saldo < totalBelanja) {
//                 cout << endl << "     [ERROR] Saldo tidak mencukupi. Silakan Top Up!" << endl;
//                 return;
//             }
            
//             // Kurangi stok
//             for (int i = 0; i < keranjangIndex; i++) {
//                 if (keranjangUser[i].nama == name) {
//                     for (int j = 0; j < mabelIndex; j++) {
//                         if (mabel[j].idProduk == keranjangUser[i].idProduk) {
//                             mabel[j].stock = mabel[j].stock - keranjangUser[i].jumlah;
//                             break;
//                         }
//                     }
//                 }
//             }
            
//             // Kurangi saldo
//             user[userIdx].saldo = user[userIdx].saldo - totalBelanja;
    
//             // Hapus keranjang user
//             int j = 0;
//             for (int i = 0; i < keranjangIndex; i++) {
//                 if (keranjangUser[i].nama != name) {
//                     keranjangUser[j] = keranjangUser[i];
//                     j++;
//                 }
//             }
//             keranjangIndex = j;
    
//             cout << endl;
//             printLine('-', 50);
//             cout << "     [SUKSES] PEMBAYARAN BERHASIL!" << endl;
//             cout << "     Sisa Saldo : Rp " << user[userIdx].saldo << endl;
//             cout << "     Terima kasih telah berbelanja." << endl;
//             printLine('=', 50);
//         } else {
//             cout << endl << "     [ERROR] Password salah!" << endl;
//         }
//     } else {
//         cout << endl << "     [INFO] Checkout dibatalkan" << endl;
//     }
// }

// void cart(string name) {
//     bool adaItem = false;
//     for (int i = 0; i < keranjangIndex; i++) {
//         if (keranjangUser[i].nama == name) {
//             adaItem = true;
//             break;
//         }
//     }
    
//     if (!adaItem) {
//         cout << endl << "     [ERROR] Keranjang Kosong!" << endl;
//         return;
//     }
    
//     while (true) {
//         clearScreen();
//         cout << endl;
//         printLine('=', 80);
//         cout << "                     KERANJANG BELANJA                      " << endl;
//         printLine('=', 80);
//         cout << " ID    | Nama Produk           | Harga      | Jumlah | Sub Total" << endl;
//         printLine('-', 80);
        
//         int totalBelanja = 0;
//         for (int i = 0; i < keranjangIndex; i++) {
//             if (keranjangUser[i].nama == name) {
//                 int subtotal = keranjangUser[i].harga * keranjangUser[i].jumlah;
//                 totalBelanja = totalBelanja + subtotal;
                
//                 cout << " " << setw(4) << right << keranjangUser[i].idProduk << " | ";
//                 string nama = keranjangUser[i].namaProduk;
//                 if (nama.length() > 18) nama = nama.substr(0, 15) + "...";
//                 cout << setw(18) << left << nama << " | ";
//                 cout << "Rp" << setw(8) << right << keranjangUser[i].harga << " | ";
//                 cout << setw(6) << right << keranjangUser[i].jumlah << " | ";
//                 cout << "Rp" << setw(9) << right << subtotal << endl;
//             }
//         }
//         printLine('-', 80);
//         cout << "     Total Belanja: Rp " << totalBelanja << endl;
//         printLine('=', 80);
        
//         cout << endl;
//         cout << "     1. Checkout" << endl;
//         cout << "     2. Update Jumlah" << endl;
//         cout << "     3. Hapus Item" << endl;
//         cout << "     0. Kembali" << endl;
//         cout << endl;
//         printLine('-', 80);
//         cout << "     Masukan Pilihan: ";
        
//         string pilihan;
//         getline(cin, pilihan);
        
//         if (pilihan == "1") {
//             checkout(name);
//             if (confirm("\n     Kembali ke menu utama")) {
//                 return;
//             }
//         } else if (pilihan == "2") {
//             int idUpdate = getPositiveInt("     ID Produk yang ingin diubah");
//             bool ditemukan = false;
//             for (int i = 0; i < keranjangIndex; i++) {
//                 if (keranjangUser[i].nama == name && keranjangUser[i].idProduk == idUpdate) {
//                     ditemukan = true;
//                     int stok = 0;
//                     for (int j = 0; j < mabelIndex; j++) {
//                         if (mabel[j].idProduk == idUpdate) {
//                             stok = mabel[j].stock;
//                             break;
//                         }
//                     }
//                     int newJml = getPositiveInt("     Jumlah Baru");
//                     if (newJml <= stok && newJml > 0) {
//                         keranjangUser[i].jumlah = newJml;
//                         cout << endl << "     [SUKSES] Jumlah berhasil diupdate!" << endl;
//                     } else {
//                         cout << endl << "     [ERROR] Jumlah tidak valid! Stok tersedia: " << stok << endl;
//                     }
//                     break;
//                 }
//             }
//             if (!ditemukan) {
//                 cout << endl << "     [ERROR] Produk dengan ID " << idUpdate << " tidak ditemukan di keranjang!" << endl;
//             }
//             pauseScreen();
//         } else if (pilihan == "3") {
//             int idDelete = getPositiveInt("     ID Produk yang ingin dihapus");
//             bool ditemukan = false;
//             for (int i = 0; i < keranjangIndex; i++) {
//                 if (keranjangUser[i].nama == name && keranjangUser[i].idProduk == idDelete) {
//                     ditemukan = true;
//                     if (confirm("     Hapus item ini dari keranjang")) {
//                         for (int j = i; j < keranjangIndex - 1; j++) {
//                             keranjangUser[j] = keranjangUser[j + 1];
//                         }
//                         keranjangIndex--;
//                         cout << endl << "     [SUKSES] Item berhasil dihapus dari keranjang!" << endl;
//                     }
//                     break;
//                 }
//             }
//             if (!ditemukan) {
//                 cout << endl << "     [ERROR] Produk dengan ID " << idDelete << " tidak ditemukan di keranjang!" << endl;
//             }
//             pauseScreen();
//         } else if (pilihan == "0") {
//             break;
//         } else {
//             cout << endl << "     [ERROR] Pilihan tidak valid!" << endl;
//             pauseScreen();
//         }
//     }
// }

// #endif