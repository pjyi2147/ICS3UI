#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Input a positive integer less than 100: ";
    cin >> n;
    if (n <= 0) {           // when invaild integer comes in;
        cout << "a negative number or 0 or string. Try again.\n";
    }
    else if (n >= 100) {
        cout << "Too big for side size. Try again.\n";
    }
    else {
        cout << "+";
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << "+" << endl;
        for (int i = 0; i < n; i++ ) {
            cout << "|";
            for (int j = 0; j < n; j++) {
                cout << " ";
            }
            cout << "|" << endl;
        }
        cout << "+";
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << "+" << endl;
    }
    return 0;
}
