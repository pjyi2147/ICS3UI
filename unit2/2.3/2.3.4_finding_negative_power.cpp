// Lab 2.3.4 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    double base = 1.;
    int power;
    cin >> power;
    for (int i = 0; i < power; i++) {
        base = base / 2;
    }
    cout.precision(20);
    cout << base << endl;
    return 0;
}
