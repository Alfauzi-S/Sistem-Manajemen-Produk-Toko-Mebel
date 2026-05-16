// Done
#ifndef VALIDATION_H
#define VALIDATION_H

#include "menu.h"
#include "library.h"
#include "struct.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
}

string getName(const string& prompt, int exclude, int maxLen, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Nama tidak boleh kosong!");
            }
            
            bool onlySpaces = true;
            for (char c : input) { // cek setiap index sama seperti for (int i = 0; i < input.length(); i++)
                if (!isspace(c)) { // cek karakter hanya ada whitespace
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Nama tidak boleh hanya spasi!");
            }
            
            if (input.length() > maxLen) {
                throw invalid_argument("Maksimal " + to_string(maxLen) + " karakter!");
            }
            
            bool duplicate = false;
            for (int i = 0; i < userIndex; i++) {
                if (user[i].nama == input && i != exclude) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                for (int i = 0; i < adminIndex; i++) {
                    if (admin[i].nama == input) {
                        duplicate = true;
                        break;
                    }
                }
            }
            
            if (duplicate) {
                throw invalid_argument("Nama sudah terdaftar!");
            }
            
            return input;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

string getNamePrd(const string& prompt, int exclude, int maxLen, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            
            bool onlySpaces = true;
            for (char c : input) {
                if (!isspace(c)) {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Input tidak boleh hanya spasi!");
            }
            
            if (input.length() > maxLen) {
                throw invalid_argument("Maksimal " + to_string(maxLen) + " karakter!");
            }
            
            bool duplicate = false;
            for (int i = 0; i < mabelIndex; i++) {
                if (mabel[i].namaProduk == input && i != exclude) {
                    duplicate = true;
                    break;
                }
            }
            
            if (duplicate) {
                throw invalid_argument("Nama Produk sudah terdaftar!");
            }
            
            return input;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

string getNameMat(const string& prompt, int exclude, int maxLen, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            
            bool onlySpaces = true;
            for (char c : input) {
                if (!isspace(c)) {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Input tidak boleh hanya spasi!");
            }
            
            if (input.length() > maxLen) {
                throw invalid_argument("Maksimal " + to_string(maxLen) + " karakter!");
            }
            
            bool duplicate = false;
            for (int i = 0; i < materialIndex; i++) {
                if (materialDb[i].namaMaterial == input && i != exclude) {
                    duplicate = true;
                    break;
                }
            }
            
            if (duplicate) {
                throw invalid_argument("Nama Material sudah terdaftar!");
            }
            
            return input;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

string getPassword(const string& prompt, int minLen, int maxLen , int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            
            bool onlySpaces = true;
            for (char c : input) {
                if (!isspace(c)) {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Input tidak boleh hanya spasi!");
            }
            
            if (input.length() > maxLen) {
                throw invalid_argument("Maksimal " + to_string(maxLen) + " karakter!");
            }

            if (input.length() < minLen) {
                throw invalid_argument("Minimal " + to_string(minLen) + " karakter!");
            }
            
            return input;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

string getEmail(const string& prompt, int exclude, int space) {
    string email;
    while (true) {
        try {
            cout << setw(space) << prompt << ": ";
            getline(cin, email);

            
            if (email.empty()) {
                throw invalid_argument("Email tidak boleh kosong!");
            }

            bool onlySpaces = true;
            for (char c : email) {
                if (!isspace(c)) {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Input tidak boleh hanya spasi!");
            }

            if (email.find("@gmail.com") == string::npos) { // apakah string email tidak mengandung substring "@gmail.com"
                throw invalid_argument("Email harus menggunakan domain @gmail.com!");
            }
            
            bool isEmailDuplicate = false;
            for (int i = 0; i < userIndex; i++) {
                if (user[i].email == email && i != exclude) {
                    isEmailDuplicate = true;
                }
            }

            if (isEmailDuplicate) {
                throw invalid_argument("Email sudah terdaftar!");
            }
            cout << setw(space) << left << " " << ">> Email terdaftar: " << email << endl;
            return email;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

string getInput(const string& prompt, int maxLen, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            
            bool onlySpaces = true;
            for (char c : input) {
                if (!isspace(c)) {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Input tidak boleh hanya spasi!");
            }
            
            if (input.length() > maxLen) {
                throw invalid_argument("Maksimal " + to_string(maxLen) + " karakter!");
            }
            
            return input;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

int getInt(const string& prompt, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            
            bool onlySpaces = true;
            for (char c : input) {
                if (!isspace(c)) {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Input tidak boleh hanya spasi!");
            }
            
            if (input[0] == '-') { // cek di index 0
                throw invalid_argument("Harus bernilai positif!");
            }
            
            for (char c : input) { // cek setiap index sama seperti for (int i = 0; i < input.length(); i++)
                if (!isdigit(c)) { // cek semua karakter adalah digit
                    throw invalid_argument("Harus berupa angka bulat positif!");
                }
            }
            
            int angka = stoi(input); // konversi ke int, jika melebihi stoi bisa throw out_of_range
            return angka;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const out_of_range& e) {
            cout << setw(space) << left << " " << "[ERROR] Angka terlalu besar (maksimum 2147483647)!" << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

int getIntNotZero(const string& prompt, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            
            bool onlySpaces = true;
            for (char c : input) {
                if (!isspace(c)) {
                    onlySpaces = false;
                    break;
                }
            }
            if (onlySpaces) {
                throw invalid_argument("Input tidak boleh hanya spasi!");
            }
            
            if (input[0] == '-') { // cek di index 0
                throw invalid_argument("Harus bernilai positif!");
            }
            
            for (char c : input) { // cek setiap index sama seperti for (int i = 0; i < input.length(); i++)
                if (!isdigit(c)) { // cek semua karakter adalah digit
                    throw invalid_argument("Harus berupa angka bulat positif!");
                }
            }
            
            int angka = stoi(input); // konversi ke int, jika melebihi stoi bisa throw out_of_range
            
            if (angka <= 0) {
                throw invalid_argument("Harus lebih besar dari 0!");
            }

            return angka;
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        } catch (const out_of_range& e) {
            cout << setw(space) << left << " " << "[ERROR] Angka terlalu besar (maksimum 2147483647)!" << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

bool confirm(const string& prompt, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input == "y" || input == "Y") {
                return true;
            } else if (input == "n" || input == "N") {
                return false;
            } else {
                throw invalid_argument("Masukkan y atau n!");
            }    
        } catch (const invalid_argument& e) {
            cout << setw(space) << left << "  " << "[ERROR] " << e.what() << endl;
        } catch (const exception& e) {
            cout << setw(space) << left << "  " << "[ERROR] " << e.what() << endl;
        }
    }
}

#endif