// Lab 2.3.7 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    long long n0, n1, n2;
    int x;
    cin >> x;
    n0 = 1;
    n1 = 1;
    n2 = 2;
    if (x == 3) {
        cout << n2;
        return 0;
    }
    else if (x == 2) {
        cout << n1;
        return 0;
    }
    else if (x == 1) {
        cout << n0;
        return 0;
    }

    for (int i = 3; i < x; i++) { // since n2 is the third number in fibonacci sequence
        n0 = n1;
        n1 = n2;
        n2 = n1 + n0;
    }
    cout << n2 << endl;
    return 0;
}
