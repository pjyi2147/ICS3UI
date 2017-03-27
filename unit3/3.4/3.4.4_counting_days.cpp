// Lab 3.4.4 by Jeongseop Yi
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

bool isEarly(Date startDate, Date endDate) {
    if (startDate.year > endDate.year) {
        return false;
    }
    else if (startDate.year == endDate.year) {
        if (startDate.month > endDate.month) {
            return false;
        }
        else if (startDate.month == endDate.month) {
            if (startDate.day > endDate.day) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return true;
        }
    }
    else {
        return true;
    }
}

int daysBetween(Date startDate, Date endDate) {
    int numDate = 0;
    if (isEarly(startDate, endDate)) {
        if (startDate.year != endDate.year) {
            if (isLeap(startDate.year)) {
                numDate += 366 - dayOfYear(startDate);
            }
            else {
                numDate += 365 - dayOfYear(startDate);
            }
            numDate += dayOfYear(endDate);
            for (int i = startDate.year+1; i < endDate.year; i++) {
                if (isLeap(i)) {
                    numDate += 366;
                }
                else {
                    numDate += 365;
                }
            }
            return numDate;
        }
        else {
            return dayOfYear(endDate) - dayOfYear(startDate);
        }
    }
    else {
        return -1;
    }
}

int main() {
    Date since, to;
    cout << "Enter first date (y m d): ";
    cin >> since.year >> since.month >> since.day;
    cout << "Enter second date (y m d): ";
    cin >> to.year >> to.month >> to.day;
    cout << daysBetween(since, to) <<  endl;
    return 0;
}
