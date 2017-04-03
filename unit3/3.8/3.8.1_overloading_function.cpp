// Lab 3.8.1 by Jeongseop Yi
#include <iostream>
#include <cmath>
using namespace std;

void increment(int &k, int i = 1) {
    k += i;
}
void increment(float &k, float i = 1.) {
    k += i;
}

int main() {

    int intvar = 0;
    float floatvar = 1.5;
    for (int i = 0; i < 10; i++) {
        if(i%2) {
            increment(intvar);
            increment(floatvar, sqrt(intvar));
        }
        else {
            increment(intvar, i);
            increment(floatvar);
        }
    }
    cout << intvar * floatvar << endl;
    return 0;
}
