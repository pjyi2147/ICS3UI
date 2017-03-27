// Lab 3.4.3 by Jeongseop Yi
#include <iostream>

using namespace std;
struct Date {
    int year, month, day;
};

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

int dayOfYear(Date date) {
    int numDate = 0;
    for(int i = 1; i < date.month; i++) {
        numDate += monthLength(date.year, i);
    }
    numDate += date.day;

    return numDate;
}

int main() {

    Date d;
    cout << "Enter year month day: ";
    cin >> d.year >> d.month >> d.day;
    cout << dayOfYear(d) << endl;
    return 0;
}
