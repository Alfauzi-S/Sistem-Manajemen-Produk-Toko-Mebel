#include "library.h"
#include "auth.h"
#include "crud.h"
#include "sort.h"
#include "search.h"
#include "user.h"
#include "error_handling.h"

struct user {

};

struct produk {

};

int main() {
    try
    {        
        string pilihan;
        string currentUser;
        while (true) {
            if (pilihan == "1") {
                bool isAdmin = false;
                bool loginSucces = login();
                if (loginSucces) {
                    if (isAdmin && loginSucces) {
                        while (true) {
                            if (pilihan == "1") {
                                read();
                            } else if (pilihan == "2") {
                                create();
                            } else if (pilihan == "3") {
                                update();
                            } else if (pilihan == "4") {
                                del();
                            } else if (pilihan == "5") {
                                sort();
                            } else if (pilihan == "6") {
                                search();
                            } else if (pilihan == "0") {
                                break;
                            } else {
                                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                            }
                        }
                    } else {
                        while (true) {
                            if (pilihan == "1") {
                                readuser();
                            } else if (pilihan == "2") {
                                read();
                            } else if (pilihan == "3") {
                                search();
                            } else if (pilihan == "4") {
                                buy();
                            } else if (pilihan == "4") {
                                topup();
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
                regis();
            } else if (pilihan == "0") {
                break;
            } else {
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    } catch (const std::exception& e) {
        cerr << "\nError Fatal: " << e.what() << endl;
        return 1;
    }
}