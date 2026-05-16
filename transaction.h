// Done
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "library.h"
#include "struct.h"
#include "validation.h"

using namespace std;

// Mendapatkan waktu saat ini dalam format YYYY-MM-DD HH:MM:SS
string getCurrentDateTime() {
    time_t now = time(0); // tipe data untuk waktu, time(0) ambil waktu saat ini
    struct tm* t = localtime(&now); // konversi ke struktur tm 
    char waktu[80];
    strftime(waktu, sizeof(waktu), "%Y-%m-%d %H:%M:%S", t); //format wa ktu sesuai pola, hasil disimpan ke buffer
    return string(waktu);
}

string generateTransactionId() {
    ifstream file("transaksi.csv"); // baca data dari file 
    string lastId = "TRX000";
    string line;
    // baca semua baris
    while (getline(file, line)) {
        if (!line.empty()) {
            size_t comma = line.find(',');
            if (comma != string::npos)
                lastId = line.substr(0, comma); // ambil ID transaksi sebelum koma
        }
    }
    file.close();

    int maxId = 0;
    if (lastId.length() >= 6 && lastId.substr(0, 3) == "TRX") {
        string numStr = lastId.substr(3); // ambil angka setelah "TRX"
        maxId = atoi(numStr.c_str()); // konversi ke integer
    }

    int nextId = maxId + 1; // ID berikutnya
    string idBaru = "TRX";
    if (nextId < 10) {
        idBaru += "00" + to_string(nextId);
    } else if (nextId < 100) {
        idBaru += "0" + to_string(nextId);
    } else {
        idBaru += to_string(nextId);
    }
    return idBaru;
}

// Menyimpan transaksi ke file CSV
void saveTransaction(const string& namaUser, int total, const string& detail) {
    ofstream file("transaksi.csv", ios::app); //  digunakan untuk menulis data, jika file belum ada akan dibuat otomatis.
    if (!file.is_open()) {
        showError("Gagal membuka file transaksi.csv");
        return;
    }
    string id = generateTransactionId();
    string tanggal = getCurrentDateTime();
    file << id << "," << namaUser << "," << tanggal << "," << total << "," << detail << endl; // tulis transaksi
    file.close();
}

void viewUserTransactions(const string& currentUser) {
    ifstream file("transaksi.csv"); // baca data dari file 
    if (!file.is_open()) {
        showError("Belum ada transaksi.");
        return;
    }

    Header("HISTORI TRANSAKSI ANDA", 132);
    cout << " " << setw(12) << left << "ID Transaksi"
    << " | " << setw(20) << left << "Tanggal"
    << " | " << setw(12) << right << "Total"
    << " | " << setw(10) << left << "ID Produk"
    << " | " << setw(25) << left << "Nama Produk"
    << " | " << setw(6) << right << "Jml"
    << " | " << setw(12) << right << "Harga"
    << " | " << setw(12) << right << "Subtotal" << endl;
    printLine('-', 132);
    
    // baca file baris per baris
    bool found = false;
    string line;
    while (getline(file, line)) {
        stringstream ss(line); // stringstream dari baris yang dibaca
        string id, user, tanggal, total, detail; // variabel untuk setiap kolom
        getline(ss, id, ','); // Membaca dari ss sampai menemukan koma (','), hasil disimpan ke variabel `id`
        getline(ss, user, ',');
        getline(ss, tanggal, ',');
        getline(ss, total, ',');
        getline(ss, detail, ',');

        if (user == currentUser) {
            found = true;
            cout << " " << setw(12) << left << id
                << " | " << setw(20) << left << tanggal
                << " | Rp " << setw(9) << right << total
                << " | " << setw(10) << left << ""
                << " | " << setw(25) << left << ""
                << " | " << setw(6) << right << ""
                << " | " << setw(12) << right << ""
                << " | " << setw(12) << right << "" << endl;

            stringstream detailSs(detail); // stringstream baris per detail yang dibaca, agar bisa dipisah-pisah
            string itemStr;
            while (getline(detailSs, itemStr, ';')) { // pisah baris saat ketemu ;
                if (itemStr.empty()) continue; // lewati iterasi jika string itemStr kosong
                stringstream itemStream(itemStr); // stringstream baris per item yang di baca
                string idProd, namaProd, jumlah, harga, subtotal; // variabel untuk setiap kolom item
                getline(itemStream, idProd, '|'); // Membaca dari itemStream sampai menemukan koma ('|'), hasil disimpan ke variabel `idProd`
                getline(itemStream, namaProd, '|');
                getline(itemStream, jumlah, '|');
                getline(itemStream, harga, '|');
                getline(itemStream, subtotal, '|');
                
                cout << " " << setw(12) << left << ""
                    << " | " << setw(20) << left << ""
                    << " | " << setw(12) << right << ""
                    << " | " << setw(10) << left << idProd
                    << " | " << setw(25) << left << namaProd
                    << " | " << setw(6) << right << jumlah
                    << " | Rp " << setw(9) << right << harga
                    << " | Rp " << setw(9) << right << subtotal << endl;
            }
            printLine('-', 132);
        }
    }
    file.close();

    if (!found) {
        showInfo("Belum ada transaksi untuk user ini.");
    }
    printLine('=', 132);
}

void viewAllTransactions() {
    ifstream file("transaksi.csv"); // baca data dari file
    if (!file.is_open()) {
        showError("Belum ada transaksi.");
        return;
    }
    
    Header("HISTORI TRANSAKSI (SEMUA)", 132);
    cout << " " << setw(12) << left << "ID Transaksi"
        << " | " << setw(20) << left << "Tanggal"
        << " | " << setw(12) << right << "Total"
        << " | " << setw(10) << left << "ID Produk"
        << " | " << setw(25) << left << "Nama Produk"
        << " | " << setw(6) << right << "Jml"
        << " | " << setw(12) << right << "Harga"
        << " | " << setw(12) << right << "Subtotal" << endl;
    printLine('-', 132);

    // baca file baris per baris
    string line;
    while (getline(file, line)) {
        stringstream ss(line); // stringstream dari baris yang dibaca
        string id, user, tanggal, total, detail; // variabel untuk setiap kolom
        getline(ss, id, ','); // Membaca dari ss sampai menemukan koma (','), hasil disimpan ke variabel `id`
        getline(ss, user, ',');
        getline(ss, tanggal, ',');
        getline(ss, total, ',');
        getline(ss, detail, ',');

        cout << " " << setw(12) << left << id
            << " | " << setw(20) << left << tanggal
            << " | Rp " << setw(9) << right << total
            << " | " << setw(10) << left << ""
            << " | " << setw(25) << left << ""
            << " | " << setw(6) << right << ""
            << " | " << setw(12) << right << ""
            << " | " << setw(12) << right << "" << endl;

        stringstream detailSs(detail); // stringstream baris per item yang dibaca, agar bisa dipisah-pisah
        string itemStr;
        while (getline(detailSs, itemStr, ';')) { // pisah baris saat ketemu ;
            if (itemStr.empty()) continue; // lewati iterasi jika string itemStr kosong
            stringstream itemStream(itemStr); // stringstream baris per item yang di baca
            string idProd, namaProd, jumlah, harga, subtotal; // variabel untuk setiap kolom item
            getline(itemStream, idProd, '|'); // Membaca dari itemStream sampai menemukan koma ('|'), hasil disimpan ke variabel `idProd`
            getline(itemStream, namaProd, '|');
            getline(itemStream, jumlah, '|');
            getline(itemStream, harga, '|');
            getline(itemStream, subtotal, '|');
            
            cout << " " << setw(12) << left << ""
                << " | " << setw(20) << left << ""
                << " | " << setw(12) << right << ""
                << " | " << setw(10) << left << idProd
                << " | " << setw(25) << left << namaProd
                << " | " << setw(6) << right << jumlah
                << " | Rp " << setw(9) << right << harga
                << " | Rp " << setw(9) << right << subtotal << endl;
        }
        printLine('-', 132);
    }
    file.close();
    printLine('=', 132);
}

#endif