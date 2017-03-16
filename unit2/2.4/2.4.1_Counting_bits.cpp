// Lab 2.4.1 by Jeongseop Yi
#include <iostream>
#include <bitset>

using namespace std;
int main() {
    int counter = 0;
    int x;
    unsigned long long mask = 1;
    cin >> x;
    while (x > 0) {
        if (x & mask) {
            counter += 1;
            x >>= 1;
        } else {
            x >>= 1;
        }
    }
    cout << counter << endl;
    return 0;
}
