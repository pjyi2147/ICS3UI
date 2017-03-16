// Lab 2.1.4 by Jeongseop Yi with formula from wikipedia
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
    int year, month, day, remainder;
    int k, j;
    cin >> year >> month >> day;
    if (month <= 2) {
        month += 12;
        year -= 1;
    }
    remainder = ((day + ((13*(month + 1))/5) + year + year/4 - year/100 + year/400) % 7);
    if (remainder == 0) {
        remainder = 6;
    }
    else {
        remainder -= 1;
    }
    cout << remainder << endl;

    return 0;
}
