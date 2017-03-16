#include <iostream>
using namespace std;
int main() {
    int i, j, k;

    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;

    i += 2;                     // increment i by 2
    j -= i;                     // decrement j by i
    k = i / j;                  // divide i by j giving k
    k += k;                     // increment k by k
    k -= 1;                     // decrement k by 1
    j = k % i;                  // assign k modulo i to j
    k += i + k;                     // increment k by k added to i
    k += k / j;                 // increment k by k divided by j
    k = k * k * k;               // assing k times k times k to k
    k += i*j;                    // increment k by i times j

    cout << k;
    return 0;
}
