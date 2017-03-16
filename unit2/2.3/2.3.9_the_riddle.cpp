// Lab 2.3.9 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    int n, an;
    cin >> n;
    n = (n+1) /2;
    an = 4*n*n - 8*n + 5;
    cout << an << endl;
    return 0;
}