/*
*  28/04/17
*  ICS3UI
*  Unit test 5 #3
*  Jeongseop Yi
*  Mr. Damian
*/

#include <iostream>
#include <string>

using namespace std;

int power(int base, int exponent) {
    if (exponent <= 0) {
        return 1;
    }
    return base * power(base, exponent -1);
}

int main() {
    cout << "This program calculates power calculation using recursion." << endl << endl;
    int x = 0, y = 0;
    cout << "Input your base: ";
    cin >> x;
    cout << "input your power: ";
    cin >> y;

    cout << x << " power " << y << " equals to " << power(x, y) << endl;
}
