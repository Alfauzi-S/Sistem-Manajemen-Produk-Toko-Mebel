#include "library.h"
#include "struct.h"
#include "validation.h"
#include "menu.h"
#include "auth.h"
#include "crud.h"
#include "sort.h"
#include "search.h"
#include "user.h"
#include "material.h"

int main() {
    mabel[0].idProduk = "PRD001";
    mabel[0].namaProduk = "Daun Pintu Kayu Jati";
    mabel[0].jenisProduk = "Pintu";
    mabel[0].stock = 15;
    mabel[0].harga = 2500000;
    mabel[0].material.idMaterial = "MAT001";
    mabel[0].material.namaMaterial = "Kayu Jati";
    mabel[0].material.jenisMaterial = "Kayu Solid";

    mabel[1].idProduk = "PRD002";
    mabel[1].namaProduk = "Daun Pintu HPL";
    mabel[1].jenisProduk = "Pintu";
    mabel[1].stock = 30;
    mabel[1].harga = 350000;
    mabel[1].material.idMaterial = "MAT002";
    mabel[1].material.namaMaterial = "HPL Abu-Abu";
    mabel[1].material.jenisMaterial = "Pelapis";

    mabel[2].idProduk = "PRD003";
    mabel[2].namaProduk = "Jendela Kaca Geser";
    mabel[2].jenisProduk = "Jendela";
    mabel[2].stock = 8;
    mabel[2].harga = 1800000;
    mabel[2].material.idMaterial = "MAT003";
    mabel[2].material.namaMaterial = "Kayu Meranti";
    mabel[2].material.jenisMaterial = "Kayu Solid";

    mabel[3].idProduk = "PRD004";
    mabel[3].namaProduk = "Meja Makan Minimalis";
    mabel[3].jenisProduk = "Meja";
    mabel[3].stock = 12;
    mabel[3].harga = 4500000;
    mabel[3].material.idMaterial = "MAT004";
    mabel[3].material.namaMaterial = "Plywood Biru";
    mabel[3].material.jenisMaterial = "Papan";

    mabel[4].idProduk = "PRD005";
    mabel[4].namaProduk = "Kursi Tamu Kayu";
    mabel[4].jenisProduk = "Kursi";
    mabel[4].stock = 20;
    mabel[4].harga = 1200000;
    mabel[4].material.idMaterial = "MAT001";
    mabel[4].material.namaMaterial = "Kayu Jati";
    mabel[4].material.jenisMaterial = "Kayu Solid";

    materialDb[0].idMaterial = "MAT001";
    materialDb[0].namaMaterial = "Kayu Jati";
    materialDb[0].jenisMaterial = "Kayu Solid";

    materialDb[1].idMaterial = "MAT002";
    materialDb[1].namaMaterial = "HPL Abu-Abu";
    materialDb[1].jenisMaterial = "Pelapis";

    materialDb[2].idMaterial = "MAT003";
    materialDb[2].namaMaterial = "Kayu Meranti";
    materialDb[2].jenisMaterial = "Kayu Solid";

    materialDb[3].idMaterial = "MAT004";
    materialDb[3].namaMaterial = "Plywood Biru";
    materialDb[3].jenisMaterial = "Papan";

    user[0].nama = "user";
    user[0].password = "123";
    user[0].email = "user@gmail.com";
    user[0].saldo = 150000000;
    user[0].alamat.jalan = "JL. User";
    user[0].alamat.kota = "Kota User";
    user[0].alamat.provinsi = "Provinsi User";

    admin[0].nama = "admin";
    admin[0].password = "123";

    string pilihan;
    string currentUser;
    
    while (true) {
        try {
            clearScreen();
            menu();
            getline(cin, pilihan);
            
            if (pilihan == "1") {
                clearScreen();
                bool isAdmin = false;
                if (login(&isAdmin, &currentUser)) {
                    pauseScreen();
                    
                    if (isAdmin) {
                        while (true) {
                            clearScreen();
                            menuAdmin();
                            getline(cin, pilihan);
                            
                            if (pilihan == "1") {
                                clearScreen();
                                if (mabelIndex == 0) {
                                    showError("Data Produk Kosong!");
                                } else {
                                    read();
                                }
                                pauseScreen();
                            }
                            else if (pilihan == "2") {
                                clearScreen();
                                create();
                                pauseScreen();
                            }
                            else if (pilihan == "3") {
                                clearScreen();
                                update();
                                pauseScreen();
                            }
                            else if (pilihan == "4") {
                                clearScreen();
                                del();
                                pauseScreen();
                            }
                            else if (pilihan == "5") {
                                Sort();
                            }
                            else if (pilihan == "6") {
                                Search();
                            }
                            else if (pilihan == "7") {
                                menuMaterial();
                            }
                            else if (pilihan == "0") {
                                break;
                            }
                            else {
                                showError("Pilihan tidak valid!");
                                pauseScreen();
                            }
                        }
                    } else {
                        while (true) {
                            clearScreen();
                            menuUser();
                            getline(cin, pilihan);
                            
                            // if (pilihan == "1") {
                            //     clearScreen();
                            //     readUserandUpdate(currentUser);
                            //     pauseScreen();
                            // }
                            // else if (pilihan == "2") {
                            //     clearScreen();
                            //     buy(currentUser);
                            //     pauseScreen();
                            // }
                            // else if (pilihan == "3") {
                            //     clearScreen();
                            //     cart(currentUser);
                            //     pauseScreen();
                            // }
                            // else if (pilihan == "4") {
                            //     Sort();
                            // }
                            // else if (pilihan == "5") {
                            //     Search();
                            // }
                            // else if (pilihan == "6") {
                            //     clearScreen();
                            //     topup(currentUser);
                            //     pauseScreen();
                            // }
                            // else if (pilihan == "0") {
                            //     break;
                            // }
                            // else {
                            //     showError("Pilihan tidak valid!");
                            //     pauseScreen();
                            // }
                        }
                    }
                } else {
                    printLine('-', 50);
                    cout << "Program akan keluar..." << endl;
                    return 0;
                }
            } 
            else if (pilihan == "2") {
                clearScreen();
                regis();
                pauseScreen();
            } 
            else if (pilihan == "0") {
                printLine('-', 50);
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                cout << "Keluar dari program..." << endl;
                break;
            } 
            else {
                showError("Pilihan tidak valid!");
                pauseScreen();
            }
        }
        catch (const exception& e) {
            cout<< "[FATAL ERROR] " << e.what() << endl;
            pauseScreen();
        }
    }
    
    return 0;
}