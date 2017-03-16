// Lab 2.3.2 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    double pi4 = 0.;
    long n;
    cout << "Number of iterations? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        double k = 1.0 / (2*i + 1);
        if (i % 2) {                        // when i is odd
            pi4 -= k;
        }
        else {                              // when i is even
            pi4 += k;
        }
    }
    cout.precision(20);
    cout << "Pi = " << pi4 * 4 << endl;
    return 0;
}
