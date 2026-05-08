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
void showSuccess(const string& msg) {
    cout << "[SUKSES] " << msg << endl;
}
// Done
void showError(const string& msg) {
    cout << "[ERROR] " << msg << endl;
}
// Done
void showInfo(const string& msg) {
    cout << "[INFO] " << msg << endl;
}
// Done
string getValidatedName(const string& prompt, int exclude) {
    string input;
    while (true) {
        try {
            cout << setw(15) << left << prompt << ": ";
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
            
            if (input.length() > 50) {
                throw invalid_argument("Nama maksimal 50 karakter!");
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
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
string getValidatedPassword(const string& prompt, int minLen, int maxLen) {
    string input;
    while (true) {
        try {
            cout << setw(15) << left << prompt << ": ";
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
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
string getValidatedEmail(const string& prompt, int exclude) {
    string email;
    while (true) {
        try {
            cout << setw(15) << prompt << ": ";
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
            cout << setw(15) << left << " " << ">> Email terdaftar: " << email << endl;
            return email;
        }
        catch (const invalid_argument& e) {
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}
// Done
string getValidatedInput(const string& prompt, int maxLen) {
    string input;
    while (true) {
        try {
            cout << setw(15) << left << prompt << ": ";
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
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << setw(15) << left << " " << "[ERROR] " << e.what() << endl;
        }
    }
}

int getPositiveInt(const string& prompt) {
    string input;
    while (true) {
        try {
            cout << prompt << ": ";
            getline(cin, input);
            
            if (input.empty()) {
                throw invalid_argument("Input tidak boleh kosong!");
            }
            
            for (char c : input) {
                if (c < '0' || c > '9') {
                    throw invalid_argument("Harus berupa angka!");
                }
            }
            
            int angka = 0;
            for (int i = 0; i < input.length(); i++) {
                angka = angka * 10 + (input[i] - '0');
            }
            
            if (angka < 0) {
                throw invalid_argument("Harus bernilai positif!");
            }
            
            return angka;
        }
        catch (const invalid_argument& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
    }
}

bool confirm(const string& prompt) {
    string input;
    while (true) {
        try {
            cout << prompt << " (y/n): ";
            getline(cin, input);
            
            if (input == "y" || input == "Y") return true;
            if (input == "n" || input == "N") return false;
            throw invalid_argument("Masukkan y atau n!");
        }
        catch (const invalid_argument& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "     [ERROR] " << e.what() << endl;
        }
    }
}

#endif