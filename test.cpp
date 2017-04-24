#include <iostream>
using namespace std;

int pairSum(int a, int b) {
    return a + b;
}

int main() {
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        sum += pairSum(i, i+1);
    }
    cout << sum;
}
