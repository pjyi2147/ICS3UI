// Lab 3.4.2 by Jeongseop Yi
#include <iostream>

using namespace std;
bool isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int monthLength(int year, int month) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if (isLeap(year)) {
        return 29;
    }
    else {
        return 28;
    }
}

int main() {
    for(int yr = 2000; yr < 2002; yr++) {
        for (int mo = 1; mo <= 12; mo++ ) {
            cout << monthLength(yr, mo) << " ";
        }
        cout << endl;
    }
    return 0;
}
