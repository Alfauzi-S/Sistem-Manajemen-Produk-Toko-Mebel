#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include "library.h"

int getInt(const string& prompt) {
    int value;
    while (true) {
        try {
            cout << prompt;
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Silakan coba lagi." << endl;
        }
    }
}

int getPositiveInt(const string& prompt) {
    int value;
    while (true) {
        try {
            cout << prompt;
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka");
            }
            
            if (value < 0) {
                throw invalid_argument("Nilai tidak boleh negatif");
            }
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Silakan coba lagi." << endl;
        }
    }
}

#endif