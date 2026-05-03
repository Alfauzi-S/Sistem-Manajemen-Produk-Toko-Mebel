#include "library.h"
#include "struct.h"
#include "menu.h"
#include "auth.h"
#include "crud.h"
#include "sort.h"
#include "search.h"
#include "user.h"
#include "error_handling.h"
#include "tools.h"

// Fungsi untuk mengisi data awal (agar main tidak terlalu panjang)
void inisialisasiData() {
    // Data Produk (Mabel)
    mabel[0] = {101, "Daun Pintu Kayu Jati", "Pintu", 15, 2500000, {"MAT001", "Kayu Jati", "Kayu Solid"}};
    mabel[1] = {102, "Daun Pintu HPL", "Pintu", 30, 350000, {"MAT002", "HPL Abu-Abu", "Pelapis"}};
    mabel[2] = {103, "Jendela Kaca Geser", "Jendela", 8, 1800000, {"MAT003", "Kayu Meranti", "Kayu Solid"}};
    mabel[3] = {104, "Meja Makan Minimalis", "Meja", 12, 4500000, {"MAT004", "Plywood Biru", "Papan"}};
    mabel[4] = {105, "Kursi Tamu Kayu", "Kursi", 20, 1200000, {"MAT001", "Kayu Jati", "Kayu Solid"}};
    mabelIndex = 5;

    // Data User Awal
    user[0].nama = "user";
    user[0].password = "123";
    user[0].email = "user@gmail.com";
    user[0].saldo = 150000000;
    user[0].alamat = {"JL. User", "Kota User", "Provinsi User"};
    userIndex = 1;

    // Data Admin Awal
    admin[0].nama = "admin";
    admin[0].password = "123";
    adminIndex = 1;
}

int main() {
    inisialisasiData();

    try {
        string pilihan;
        string currentUser;
        bool isAdmin = false;

        while (true) {
            system("cls");
            menu(); // Menu Awal (Login/Register)
            getline(cin, pilihan);

            if (pilihan == "1") { // LOGIN
                system("cls");
                if (login(isAdmin, currentUser)) {
                    system("pause");
                    
                    if (isAdmin) {
                        // ================= LOOP MENU ADMIN =================
                        while (true) {
                            system("cls");
                            cout << "Logged in as Admin: " << currentUser << endl;
                            menuAdmin();
                            getline(cin, pilihan);

                            if (pilihan == "1") { system("cls"); read(); }
                            else if (pilihan == "2") { system("cls"); create(); }
                            else if (pilihan == "3") { system("cls"); update(); }
                            else if (pilihan == "4") { system("cls"); del(); }
                            else if (pilihan == "5") { system("cls"); sort(); }
                            else if (pilihan == "6") { system("cls"); search(); }
                            else if (pilihan == "0") break; // Logout
                            else cout << "\nPilihan tidak valid.";
                            
                            if (pilihan != "0") system("pause");
                        }
                    } else {
                        // ================= LOOP MENU USER =================
                        while (true) {
                            system("cls");
                            cout << "Logged in as User: " << currentUser << endl;
                            menuUser();
                            getline(cin, pilihan);

                            if (pilihan == "1") { 
                                system("cls"); 
                                readDataUser(currentUser); 
                            } else if (pilihan == "2") { 
                                system("cls"); 
                                read(); // Lihat daftar
                                buy();  // Pilih barang
                            } else if (pilihan == "3") { 
                                system("cls"); 
                                search(); 
                            } else if (pilihan == "4") { 
                                system("cls"); 
                                topup(currentUser); 
                            } else if (pilihan == "5") { 
                                system("cls"); 
                                checkout(currentUser); 
                            } else if (pilihan == "0") {
                                break; // Logout
                            } else {
                                cout << "\nPilihan tidak valid.";
                            }
                            
                            if (pilihan != "0") system("pause");
                        }
                    }
                } else {
                    cout << "\nLogin gagal." << endl;
                    system("pause");
                }

            } else if (pilihan == "2") { // REGISTER
                system("cls");
                regis(); // Pastikan fungsi regis() ada di tools.h atau auth.h
                system("pause");

            } else if (pilihan == "0") { // EXIT
                cout << "\nTerima kasih telah menggunakan sistem kami!" << endl;
                break;

            } else {
                cout << "\nPilihan tidak valid." << endl;
                system("pause");
            }
        }
    } catch (const std::exception& e) {
        cerr << "\nError Fatal: " << e.what() << endl;
        return 1;
    }

    return 0;
}