// Lab 4.5.7 by Jeongseop Yi

#include <iostream>
#include <string>

using namespace std;

int main() {
    string password;
    getline(cin, password);

    if (password.size() < 8) {
        cout << "The password must be 8 characters long or longer" << endl;
    }
    bool uppercase = false;
    bool digit = false;
    bool special = false;

    for (int i = 0; i < password.size(); i++) {
        char k = password[i];
        if (k >= '0' && k <= '9') {
            digit = true;
        }
        else if (k >= 'A' && k <= 'Z') {
            uppercase = true;
        }
        else if (k < 'a' || k > 'z') {
            special = true;
        }
    }

    if (!uppercase) {
        cout << "The password must have at least one uppercase character" << endl;
    }
    if (!digit) {
        cout << "The password must have at least one digit character" << endl;
    }
    if (!special) {
        cout << "The password must have at least one special character" << endl;
    }
    return 0;
}
