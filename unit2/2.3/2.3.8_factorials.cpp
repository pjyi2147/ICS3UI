// Lab 2.3.8 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    int x;
    long long factorial = 1;

    cin >> x;
    if (x == 0) {
        cout << factorial << endl;
        return 0;
    }

    for(int i = 1; i <= x; i++) {
        factorial = factorial * i;
    }
    cout << factorial << endl;
    return 0;
}
