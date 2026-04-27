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

int main() {
    mabel[0].idProduk = 101;
    mabel[0].namaProduk = "Daun Pintu Kayu Jati";
    mabel[0].jenisProduk = "Pintu";
    mabel[0].stock = 15;
    mabel[0].harga = 2500000;
    mabel[0].material.idMaterial = "MAT001";
    mabel[0].material.namaMaterial = "Kayu Jati";
    mabel[0].material.jenisMaterial = "Kayu Solid";

    mabel[1].idProduk = 102;
    mabel[1].namaProduk = "Daun Pintu HPL";
    mabel[1].jenisProduk = "Pintu";
    mabel[1].stock = 30;
    mabel[1].harga = 350000;
    mabel[1].material.idMaterial = "MAT002";
    mabel[1].material.namaMaterial = "HPL Abu-Abu";
    mabel[1].material.jenisMaterial = "Pelapis";

    mabel[2].idProduk = 103;
    mabel[2].namaProduk = "Jendela Kaca Geser";
    mabel[2].jenisProduk = "Jendela";
    mabel[2].stock = 8;
    mabel[2].harga = 1800000;
    mabel[2].material.idMaterial = "MAT003";
    mabel[2].material.namaMaterial = "Kayu Meranti";
    mabel[2].material.jenisMaterial = "Kayu Solid";

    mabel[3].idProduk = 104;
    mabel[3].namaProduk = "Meja Makan Minimalis";
    mabel[3].jenisProduk = "Meja";
    mabel[3].stock = 12;
    mabel[3].harga = 4500000;
    mabel[3].material.idMaterial = "MAT004";
    mabel[3].material.namaMaterial = "Plywood Biru";
    mabel[3].material.jenisMaterial = "Papan";

    mabel[4].idProduk = 105;
    mabel[4].namaProduk = "Kursi Tamu Kayu";
    mabel[4].jenisProduk = "Kursi";
    mabel[4].stock = 20;
    mabel[4].harga = 1200000;
    mabel[4].material.idMaterial = "MAT001";
    mabel[4].material.namaMaterial = "Kayu Jati";
    mabel[4].material.jenisMaterial = "Kayu Solid";

    user[0].nama = "user";
    user[0].password = "123";
    user[0].email = "user@gmail.com";
    user[0].saldo = 150000000;
    user[0].alamat.jalan = "JL. User";
    user[0].alamat.kota = "Kota User";
    user[0].alamat.provinsi = "Provinsi User";

    admin[0].nama = "admin";
    admin[0].password = "123";
    try
    {        
        string pilihan;
        string currentUser;
        while (true) {
            system("cls");
            menu();
            getline(cin, pilihan);
            if (pilihan == "1") {
                system("cls");
                bool isAdmin = false;
                bool loginSucces = login(isAdmin, currentUser);
                system("pause");
                if (loginSucces) {
                    if (isAdmin && loginSucces) {
                        while (true) {
                            system("cls");
                            menuAdmin();
                            getline(cin, pilihan);
                            if (pilihan == "1") {
                                system("cls");
                                read();
                                system("pause");
                            } else if (pilihan == "2") {
                                system("cls");
                                create();
                                system("pause");
                            } else if (pilihan == "3") {
                                system("cls");
                                update();
                                system("pause");
                            } else if (pilihan == "4") {
                                system("cls");
                                del();
                                system("pause");
                            } else if (pilihan == "5") {
                                system("cls");
                                sort();
                                system("pause");
                            } else if (pilihan == "6") {
                                system("cls");
                                search();
                                system("pause");
                            } else if (pilihan == "0") {
                                break;
                            } else {
                                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                                system("pause");
                            }
                        }
                    } else {
                        while (true) {
                            system("cls");
                            menuUser();
                            getline(cin, pilihan);
                            if (pilihan == "1") {
                                system("cls");
                                readuser();
                                system("pause");
                            } else if (pilihan == "2") {
                                system("cls");
                                read();
                                system("pause");
                            } else if (pilihan == "3") {
                                system("cls");
                                search();
                                system("pause");
                            } else if (pilihan == "4") {
                                system("cls");
                                buy();
                                system("pause");
                            } else if (pilihan == "4") {
                                system("cls");
                                topup();
                                system("pause");
                            } else if (pilihan == "0") {
                                break;
                            } else {
                                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                                system("pause");
                            }
                        }
                    }
                } else {
                    cout << "Login gagal, program berhenti." << endl;
                    return 0;
                }
            } else if (pilihan == "2") {
                system("cls");
                regis();
                system("pause");
            } else if (pilihan == "0") {
                break;
            } else {
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                system("pause");
            }
        }
    } catch (const std::exception& e) {
        cerr << "\nError Fatal: " << e.what() << endl;
        return 1;
    }
}