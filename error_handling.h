#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include "library.h"

int getPositiveInt(const string& prompt) {
    int value;
    while (true) {
        try {
            cout << left << setw(25) << prompt << ": ";
            cin >> value;
            if (cin.fail()) {
                throw invalid_argument("Input harus berupa angka!");
            }
            
            if (value < 0) {
                throw runtime_error("Bilangan harus bernilai positif!");
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        catch (const invalid_argument& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << left << setw(27) << " " << "Error: " << e.what() << endl;
            cout << left << setw(27) << " " << "Silakan coba lagi." << endl;
        }
        catch (const runtime_error& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << left << setw(27) << " " << "Error: " << e.what() << endl;
            cout << left << setw(27) << " " << "Silakan coba lagi." << endl;
        }
    }
}

string yesOrNo(const string& prompt) {
    string input;
    while (true) {
        try {
            cout << prompt;
            getline(cin, input);
            if (input == "Y" || input == "y") {
                return input;
            } else if (input == "N" || input == "n") {
                return input; 
            } else {
                throw invalid_argument("Jawaban tidak valid!. Harap masukkan [Y/y/N/n]");
            }
        } catch (const exception& e) {
            cout << "  Error: " << e.what() << endl;
            cout << "  Silakan coba lagi.\n";
        }
    }
}


bool isValidName(string name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' '){
            return false;
        }
    }
    return true;
}

bool isValidEmail(string email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.');
    if (atPos == string::npos || dotPos == string::npos){
        return false;
    }
    if (dotPos < atPos){
        return false;
    }
    return true;
}

#endif