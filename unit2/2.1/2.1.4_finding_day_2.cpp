// 2.1.4 by Jeongseop Yi from the formula from the pdf
#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;
int main() {
    int year, month, day;
    cin >> year >> month >> day;
    while (true) {


    month -= 2;                     // #1
    if (month <= 0) {               // #2 less than 0 is not correct --> equal or less than 0
        month += 12;
        year -= 1;
    }
    month = month * 83 / 32;        // #3 somethings wrong with it
    //month = 13*(month + 1 + 2) / 5;      // fixed #3
    month = month + day;            // #4
    month = month + year;           // #5
    month = month + year/4;         // #6
    month = month - year/100;       // #7
    month = month + year/400;       // #8
    int remainder = month % 7;      // #9
    /*
    if (remainder == 0) {
        remainder = 6;
    }
    else {
        remainder -= 1;
    }
    */
    cout << remainder << endl;
    cin >> year >> month >> day;
    }

    return 0;
}
