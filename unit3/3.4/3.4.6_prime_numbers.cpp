// Lab 3.4.6 by Jeongseop Yi
#include <iostream>
#include <cmath>
using namespace std;


bool isPrime(int num) {
    bool prime = true;
    if (num == 0 || num == 1) {
        prime = false;
    }
    if (num >= 2) {
        for (int i=2; i < sqrt(num); i++) {
            if (num % i == 0) {
                prime = false;
                break;
            }
        }
    }
    return prime;
}

int main() {
    for (int i = 0; i <= 21; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
