/*
2.1.1 Lab by Jeongseop Yi
*/
#include <iostream>
#include <string>

using namespace std;
int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if (year < 1532) {
        cout << "Warning: The year is before the Gregorian calendar.\n";
    }

    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0) {
                cout << "Leap year" << endl;
            }
            else {
                cout << "Common year" << endl;
            }
        }
        else {
            cout << "Leap year" << endl;
        }
    }
    else {
        cout << "Common year" << endl;
    }
    return 0;
}
