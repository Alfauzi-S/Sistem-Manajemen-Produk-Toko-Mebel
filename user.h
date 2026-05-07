#ifndef USER_H
#define USER_H

#include "menu.h"
#include "struct.h"
#include "library.h"
// Done
void readUser(string name) {
    if (userIndex == 0) {
        cout << "[Data User Kosong]" << endl;
        return;
    };

    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == name) {
            cout << "========================================" << endl;
            cout << "            PROFIL PENGGUNA             " << endl;
            cout << "========================================" << endl;
            cout << " Nama   : " << user[i].nama << endl;
            cout << " Email  : " << user[i].email << endl;
            cout << " Alamat : " << user[i].alamat.jalan << ", " << user[i].alamat.kota << ", " << user[i].alamat.provinsi << endl;
            cout << " Saldo  : Rp " << user[i].saldo << endl;
            cout << "========================================" << endl;
            return;
        }
    }
}

void readUserandUpdate(string &currentUser) {
    int indexKetemu = -1;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == currentUser) {
            indexKetemu = i;
            break;
        }
    }

    if (indexKetemu == -1) {
        cout << "========================================" << endl;
        cout << "[User " << currentUser << " tidak ditemukan]" << endl;
        return;
    }
    
    string pilihanUtama;
    while (true) {
        system("cls");
        readUser(currentUser);
        cout << "1. Update Data User" << endl;
        cout << "0. Exit" << endl;
        cout << "Masukan Pilihan: ";
        getline(cin, pilihanUtama);
        
        if (pilihanUtama == "1") {
            string namaBaru = user[indexKetemu].nama;
            string emailBaru = user[indexKetemu].email;
            string jalanBaru = user[indexKetemu].alamat.jalan;
            string kotaBaru = user[indexKetemu].alamat.kota;
            string provinsiBaru = user[indexKetemu].alamat.provinsi;
            
            while (true) {
                system("cls");
                cout << "========================================" << endl;
                cout << "              UPDATE PROFIL              " << endl;
                cout << "========================================" << endl;
                cout << " Nama      : " << namaBaru << endl;
                cout << " Email     : " << emailBaru << endl;
                cout << " Alamat    : " << jalanBaru << ", " << kotaBaru << ", " << provinsiBaru << endl;
                cout << "========================================" << endl;
                cout << "1. Ubah Nama" << endl;
                cout << "2. Ubah Email" << endl;
                cout << "3. Ubah Jalan" << endl;
                cout << "4. Ubah Kota" << endl;
                cout << "5. Ubah Provinsi" << endl;
                cout << "0. Simpan & Keluar" << endl;
                cout << "Masukan Pilihan: ";
                
                string pilihanUpdate;
                getline(cin, pilihanUpdate);
                
                if (pilihanUpdate == "1") {
                    string tempNama;
                    while (true) {
                        cout << "Masukkan Nama Baru: ";
                        getline(cin, tempNama);
        
                        bool namaDuplikat = false;
                        for (int i = 0; i < userIndex; i++) {
                            if (user[i].nama == tempNama && i != indexKetemu) {
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
                    namaBaru = tempNama;
                } 
                else if (pilihanUpdate == "2") {
                    cout << "Masukkan Email Baru: ";
                    getline(cin, emailBaru);
                } 
                else if (pilihanUpdate == "3") {
                    cout << "Masukkan Jalan Baru: ";
                    getline(cin, jalanBaru);
                } 
                else if (pilihanUpdate == "4") {
                    cout << "Masukkan Kota Baru: ";
                    getline(cin, kotaBaru);
                } 
                else if (pilihanUpdate == "5") {
                    cout << "Masukkan Provinsi Baru: ";
                    getline(cin, provinsiBaru);
                } 
                else if (pilihanUpdate == "0") {
                    string konfirmasi = yesOrNo("\nSimpan Perubahan (Y/N)? ");
                    if (konfirmasi == "y" || konfirmasi == "Y") {
                        user[indexKetemu].nama = namaBaru;
                        user[indexKetemu].email = emailBaru;
                        user[indexKetemu].alamat.jalan = jalanBaru;
                        user[indexKetemu].alamat.kota = kotaBaru;
                        user[indexKetemu].alamat.provinsi = provinsiBaru;
                        currentUser = user[indexKetemu].nama;
                        cout << "\n[Berhasil Update Data User]" << endl;
                    } else {
                        cout << "\n[Membatalkan Update Data User]" << endl;
                    }
                    break;
                } 
                else {
                    cout << "[Pilihan tidak valid. Silakan coba lagi.]" << endl;
                    system("pause");
                }
            }
        } 
        else if (pilihanUtama == "0") {
            break;
        } 
        else {
            cout << "[Pilihan tidak valid. Silakan coba lagi.]" << endl;
        }
    }
}
// Done
void topup(string name) {
    int indexKetemu = -1;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == name) {
            indexKetemu = i;
            break;
        }
    }

    if (indexKetemu == -1) {
        cout << "[Tidak Ditemukan Data]" << endl;
        return;
    }

    cout << "========================================" << endl;
    cout << " Nama   : " <<user[indexKetemu].nama << endl;
    cout << " Saldo  : Rp " << user[indexKetemu].saldo << endl;
    cout << "========================================" << endl;
    cout << " 1. Checkout" << endl;
    cout << " 0. Exiet" << endl;
    cout << "Masukan Pilihan: ";

    string pilihan;
    getline(cin, pilihan);
    if (pilihan == "1") {
        string inPassword;
        cout <<"Masukkan Password: ";
        getline(cin, inPassword);
        if (inPassword == user[indexKetemu].password) {
            int inNominal = getPositiveInt("Masukan Nominal Top UP");
            user[indexKetemu].saldo = inNominal;
        } else {
            cout << "========================================" << endl;
            cout << "[Password Salah.]" << endl;
        }
    } else if (pilihan == "0") {
        return;
    } else {
        cout << "========================================" << endl;
        cout << "[Pilihan tidak valid. Silakan coba lagi.]" << endl;
        system("pause");
    }
}
// Done
void buy(string name) {
    if (mabelIndex == 0) {
        cout << "[Data Produk Kosong]" << endl;
        return;
    };

    read();
    int indexKetemu = -1;
    int idCari = getPositiveInt("Masukkan ID Produk yang ingin dibeli");
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == idCari) {
            indexKetemu = i;
            break;
        }
    }

    if (indexKetemu == -1) {
        cout << "========================================================================================================================" << endl;
        cout << "[Produk dengan ID " << idCari  << " tidak ditemukan]" << endl;
        return;
    }
    int inJumlah = 0;
    while (true) {
        system("cls");
        cout << "====================================================" << endl;
        cout << "                  PEMBELIAN PRODUK                  " << endl;
        cout << "====================================================" << endl;
        cout << setw(5) << left << "ID" 
            << setw(25) << left << "Nama Produk" 
            << setw(15) << left << "Harga" 
            << setw(15) << left << "Jumlah" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << setw(5) << left << mabel[indexKetemu].idProduk
            << setw(25) << left << mabel[indexKetemu].namaProduk
            << "Rp " << setw(12) << left << mabel[indexKetemu].harga
            << setw(12) << left << inJumlah << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Stok Tersedia: " << mabel[indexKetemu].stock << endl;
        cout << "====================================================" << endl;

        string pilihan;
        menuBuy();
        getline(cin, pilihan);
        cout << "----------------------------------------------------" << endl;
        if (pilihan == "1") {
            while (true) {
                int temp = getPositiveInt("Masukkan Jumlah Beli: ");
                if (temp > mabel[indexKetemu].stock) {
                    cout << "[Jumlah Melebihi Stock Produk yang Tersedia - ID: " << mabel[indexKetemu].idProduk << " stok tersedia: " << mabel[indexKetemu].stock << "]" << endl;
                } else {
                    inJumlah = temp;
                    break;
                }
            }
        } else if (pilihan == "0") {
            string konfirmasi = yesOrNo("Tambahkan Produk ke Keranjang (Y/N)? ");
            if (konfirmasi == "y" || konfirmasi == "Y") {

                bool prdInChart = false;
                for(int i = 0 ; i < keranjangIndex ; i++) {
                    if (keranjangUser[i].nama == name && keranjangUser[i].idProduk == mabel[indexKetemu].idProduk) {
                        keranjangUser[i].jumlah = inJumlah;
                        prdInChart = true;
                        cout << "[Berhasil Memperbarui Produk ke Keranjang - ID: " << mabel[indexKetemu].idProduk << ", Jumlah: " << inJumlah << "]" << endl;
                        break;
                    }
                }

                if (!prdInChart) {
                    keranjangUser[keranjangIndex].nama = name;
                    keranjangUser[keranjangIndex].idProduk = mabel[indexKetemu].idProduk;
                    keranjangUser[keranjangIndex].namaProduk = mabel[indexKetemu].namaProduk;
                    keranjangUser[keranjangIndex].harga = mabel[indexKetemu].harga;
                    keranjangUser[keranjangIndex].jumlah = inJumlah;
                    keranjangIndex++;
                    cout << "[Berhasil Menambahkan Produk ke Keranjang - ID: " << mabel[indexKetemu].idProduk << ", Jumlah: " << inJumlah << "]" << endl;
                }
                return;
            } else {
                cout << "[Membatalkan Penambahan Produk ke Keranjang - ID: " << mabel[indexKetemu].idProduk << "]" << endl;
                return;
            }
        } else {
            cout << "\n[Pilihan tidak valid. Silakan coba lagi.]" << endl;
        }
    }
}

void checkout(string name) {
    int userIdx = -1;
    for (int i = 0; i < userIndex; i++) {
        if (user[i].nama == name) {
            userIdx = i;
            break;
        }
    }

    for (int i = 0; i < keranjangIndex; i++) {
    if (keranjangUser[i].nama == name) {
        for (int j = 0; j < mabelIndex; j++) {
            if (mabel[j].idProduk == keranjangUser[i].idProduk) {
                if (mabel[j].stock < keranjangUser[i].jumlah) {
                    cout << "[Tidak Bisa Checkout: Stok " << mabel[j].namaProduk << " tidak cukup (Sisa: " << mabel[j].stock << ")]" << endl;
                    return;
                    }
                }
            }
        }
    }

    int totalBelanja = 0;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].nama == name) {
            totalBelanja += (keranjangUser[i].harga * keranjangUser[i].jumlah);
        }
    }

    cout << "========================================" << endl;
    cout << "           RINGKASAN PEMBAYARAN         " << endl;
    cout << "========================================" << endl;
    cout << " Nama Pelanggan : " << name << endl;
    cout << " Total Tagihan  : Rp " << totalBelanja << endl;
    cout << " Saldo Anda     : Rp " << user[userIdx].saldo << endl;
    cout << "========================================" << endl;

    string konfirmasi = yesOrNo("Bayar (Y/N)? ");
    if (konfirmasi == "y" || konfirmasi == "Y") {    
        string inPassword;
        cout <<"Masukkan Password: ";
        getline(cin, inPassword);
        if (user[userIdx].password == inPassword) {
            if (user[userIdx].saldo < totalBelanja) {
                cout << "[Checkout Gagal: Saldo tidak mencukupi. Silakan Top Up!]" << endl;
                return;
            }

            for (int i = 0; i < keranjangIndex; i++) {
                if (keranjangUser[i].nama == name) {
                    for (int j = 0; j < mabelIndex; j++) {
                        if (mabel[j].idProduk == keranjangUser[i].idProduk) {
                            mabel[j].stock -= keranjangUser[i].jumlah;
                            break;
                        }
                    }
                }
            }
            user[userIdx].saldo -= totalBelanja;
    
            int j = 0;
            for (int i = 0; i < keranjangIndex; i++) {
                if (keranjangUser[i].nama != name) {
                    keranjangUser[j] = keranjangUser[i];
                    j++;
                }
            }
            keranjangIndex = j;
    
            cout << "---------------------------------------" << endl;
            cout << "[PEMBAYARAN BERHASIL!]" << endl;
            cout << "Sisa Saldo: Rp " << user[userIdx].saldo << endl;
            cout << "Terima kasih telah berbelanja." << endl;
            cout << "========================================" << endl;
        } else {
            cout << "[Password Salah.]" << endl;
            return;
        }
    } else {
        cout << "[Checkout Dibatalkan]" << endl;
        return;
    }
}
// Done
void updateCart(string name) {
    int indeksKeranjang = -1;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].nama == name) {
            indeksKeranjang = i;
        }
    }
    
    if (indeksKeranjang == -1) {
        cout << "[Keranjang Anda Kosong]" << endl;
        return;
    }
    
    system("cls");
    cout << "=========================================================" << endl;
    cout << "                     UPDATE KERANJANG                    " << endl;
    cout << "=========================================================" << endl;
    cout << setw(10) << left << "ID Produk" 
        << setw(25) << left << "Nama Produk" 
        << setw(15) << left << "Harga" 
        << setw(10) << left << "Jumlah" << endl;
    cout << "---------------------------------------------------------" << endl;
    
    for (int i = 0; i < keranjangIndex; i++) {
        cout << setw(10) << left << keranjangUser[i].idProduk
            << setw(25) << left << keranjangUser[i].namaProduk
            << "Rp " << setw(12) << left << keranjangUser[i].harga
            << setw(10) << left << keranjangUser[i].jumlah << endl;
    }
    cout << "=========================================================" << endl;
    int idCari = getPositiveInt("Masukan ID Produk yang ingin diubah");

    int idUpdate = -1;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].idProduk == idCari) {
            idUpdate = i;
            break;
        }
    }

    if (idUpdate == -1) {
        cout << "=========================================================" << endl;
        cout << "[ID Produk tidak ditemukan]" << endl;
        return;
    }

    // Cari produk di mabel
    int indexKetemu = -1;
    for (int i = 0; i < mabelIndex; i++) {
        if (mabel[i].idProduk == keranjangUser[idUpdate].idProduk) {
            indexKetemu = i;
            break;
        }
    }
    
    if (indexKetemu == -1) {
        cout << "=========================================================" << endl;
        cout << "[Produk tidak ditemukan]" << endl;
        return;
    }
    int temp = getPositiveInt("Masukan Jumlah Baru");
    if (temp > mabel[indexKetemu].stock) {
        cout << "[Jumlah Melebihi Stock Produk yang Tersedia - ID: " << mabel[indexKetemu].idProduk << " stok tersedia: " << mabel[indexKetemu].stock << "]" << endl;
    } else {
        keranjangUser[idUpdate].jumlah = temp;
        cout << "[Berhasil Update Jumlah Produk Keranjang - ID: " << mabel[indexKetemu].idProduk << ", Jumlah: " << temp << "]" << endl;
    }
}
// Done
void deleteCart(string name) {
    int indeksKeranjang = -1;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].nama == name) {
            indeksKeranjang = i;
        }
    }
    
    if (indeksKeranjang == -1) {
        cout << "[Keranjang Anda Kosong]" << endl;
        return;
    }
    
    system("cls");
    cout << "=========================================================" << endl;
    cout << "                      HAPUS KERANJANG                    " << endl;
    cout << "=========================================================" << endl;
    cout << setw(10) << left << "ID Produk" 
        << setw(25) << left << "Nama Produk" 
        << setw(15) << left << "Harga" 
        << setw(10) << left << "Jumlah" << endl;
    cout << "---------------------------------------------------------" << endl;
    
    for (int i = 0; i < keranjangIndex; i++) {
        cout << setw(10) << left << keranjangUser[i].idProduk
            << setw(25) << left << keranjangUser[i].namaProduk
            << "Rp " << setw(12) << left << keranjangUser[i].harga
            << setw(10) << left << keranjangUser[i].jumlah << endl;
    }
    cout << "=========================================================" << endl;
    int idCari = getPositiveInt("Masukan ID Produk yang ingin diubah");

    int idDelete = -1;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].idProduk == idCari) {
            idDelete = i;
            break;
        }
    }

    if (idDelete == -1) {
        cout << "=========================================================" << endl;
        cout << "[ID Produk tidak ditemukan]" << endl;
        return;
    }

    string konfirmasi = yesOrNo("Hapus Produk dari Keranjang (Y/N)? ");
    if (konfirmasi == "y" || konfirmasi == "Y") {
        // Hapus item
        for (int i = idDelete; i < keranjangIndex - 1; i++) {
            keranjangUser[i] = keranjangUser[i + 1];
        }
        keranjangIndex--;
        cout << "=========================================================" << endl;
        cout << "[Berhasil Menghapus Produk - ID: " << mabel[idDelete].idProduk << " Dari Keranjang]" << endl;
    } else {
        cout << "[Membatalkan Penghapusan Produk - ID: " << mabel[idDelete].idProduk << " Dari Keranjang]" << endl;
    }
}
// Done
void cart(string name) {
    system("cls");

    if (keranjangIndex == 0) {
        cout << "[Keranjang Kosong]" << endl;
        return;
    };
    cout << "===========================================================================" << endl;
    cout << "                                  KERANJANG                                " << endl;
    cout << "===========================================================================" << endl;
    cout << setw(10) << left << "ID Produk" 
        << setw(25) << left << "Nama Produk" 
        << setw(15) << left << "Harga" 
        << setw(10) << left << "Jumlah" 
        << setw(15) << left << "Sub Total" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    int totalBelanja = 0;
    for (int i = 0; i < keranjangIndex; i++) {
        if (keranjangUser[i].nama == name) {
            int subtotal = (keranjangUser[i].harga) * keranjangUser[i].jumlah;
            totalBelanja += subtotal;
            cout << setw(10) << left << keranjangUser[i].idProduk
                << setw(25) << left << keranjangUser[i].namaProduk
                << "Rp " << setw(12) << left << keranjangUser[i].harga
                << setw(10) << left << keranjangUser[i].jumlah
                << "Rp " << setw(12) << left << subtotal << endl;
        }
    }    
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Total Belanja: Rp " << totalBelanja << endl;
    cout << "===========================================================================" << endl;
    menuKeranjang();

    string pilihan;
    getline(cin, pilihan);

    if (pilihan == "1") {
        checkout(name);
    } else if (pilihan == "2") {
        updateCart(name);
    } else if (pilihan == "3") {
        deleteCart(name);
    } else if (pilihan == "0") {
        return;
    } else {
        cout << "===========================================================================" << endl;
        cout << "[Pilihan tidak valid. Silakan coba lagi.]" << endl;
    }
}

#endif