// Lab 2.1.5 by Jeongseop Yi
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
    int year;
    cin >> year;
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (a * 19 + 24) % 30;
    int e = (2*b + 4*c + 6*d + 5) % 7;
    if (d+e < 10) {
        cout << "Easter for year " << year << " is: " << "March " << d + e + 22 << endl;
    }
    else {
        cout << "Easter for year " << year << " is: " << "April " << d + e - 9 << endl;
    }
    return 0;
}
