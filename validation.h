#ifndef VALIDATION_H
#define VALIDATION_H

#include "menu.h"
#include "library.h"
#include "struct.h"
// Done
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
// Done
void pauseScreen() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
}
// Done
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
            for (char c : input) {
                if (!isspace(c)) {
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
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
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
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
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
                throw invalid_argument("Nama Produk sudah terdaftar!");
            }
            
            return input;
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
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
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
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

            if (email.find("@gmail.com") == string::npos) {
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
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
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
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
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
            
            // Trim spasi di awal dan akhir
            size_t start = input.find_first_not_of(" \t");
            if (start == string::npos) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            size_t end = input.find_last_not_of(" \t");
            string trimmed = input.substr(start, end - start + 1);
            
            // Cek negatif setelah trim
            if (trimmed[0] == '-') {
                throw invalid_argument("Harus bernilai positif!");
            }
            
            // Validasi semua karakter adalah digit
            for (char c : trimmed) {
                if (!isdigit(c)) {
                    throw invalid_argument("Harus berupa angka bulat positif!");
                }
            }
            
            int angka = stoi(trimmed); // jika melebihi stoi bisa throw out_of_range
            return angka;
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << setw(space) << left << " " << "[ERROR] Angka terlalu besar (maksimum 2147483647)!" << endl;
        }
        catch (const exception& e) {
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
            
            // Trim spasi di awal dan akhir
            size_t start = input.find_first_not_of(" \t");
            if (start == string::npos) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            size_t end = input.find_last_not_of(" \t");
            string trimmed = input.substr(start, end - start + 1);
            
            // Cek negatif setelah trim
            if (trimmed[0] == '-') {
                throw invalid_argument("Harus bernilai positif!");
            }
            
            // Validasi semua karakter adalah digit
            for (char c : trimmed) {
                if (!isdigit(c)) {
                    throw invalid_argument("Harus berupa angka bulat positif!");
                }
            }
            
            int angka = stoi(trimmed); // jika melebihi stoi bisa throw out_of_range
            return angka;

            if (angka <= 0) {
                throw invalid_argument("Harus lebih besar dari 0!");
            }
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << setw(space) << left << " " << "[ERROR] Angka terlalu besar (maksimum 2147483647)!" << endl;
        }
        catch (const exception& e) {
            cout << setw(space) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
bool confirm(const string& prompt, int space) {
    string input;
    while (true) {
        try {
            cout << setw(space) << left << prompt << ": ";
            getline(cin, input);
            
            if (input == "y" || input == "Y") return true;
            if (input == "n" || input == "N") return false;
            throw invalid_argument("Masukkan y atau n!");
        }
        catch (const invalid_argument& e) {
            cout << setw(space) << left << "  " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(space) << left << "  " << "[ERROR] " << e.what() << endl;
        }
    }
}

#endif