// Lab 2.3.1 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    unsigned c0;
    cin >> c0;
    int counter = 0;
    while (c0 != 1) {
        if (c0 % 2) {   // when c0 is odd
            c0 = 3*c0 + 1;
            cout << c0 << endl;
        }
        else {          // when c0 is even
            c0 = c0 / 2;
            cout << c0 << endl;
        }
        counter += 1;
    }
    cout << "steps = " << counter << endl;
}
