// Lab 2.3.3 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int power;
    unsigned long long base = 1;
    cin >> power;
    for (int i = 0; i < power; i++) {
        base = base * 2;
    }
    cout << "2 power " << power << " is: " << base << endl;
    return 0;
}
