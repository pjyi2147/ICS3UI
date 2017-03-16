// Lab 2.9.2 by Jeongseop Yi
#include <iostream>
#include <vector>

using namespace std;
int banknote(int n) {
    if (n >= 50) {
        cout << "50 ";
        return banknote(n-50);
    }
    else if (n >= 20) {
        cout << "20 ";
        return banknote(n-20);
    }
    else if (n >= 10) {
        cout << "10 ";
        return banknote(n-10);
    }
    else if (n >= 5) {
        cout << "5 ";
        return banknote(n-5);
    }
    else if (n >= 1) {
        cout << "1 ";
        return banknote(n-1);
    }
    else {
        return 0;
    }
}
int main() {
    int m;
    cin >> m;
    banknote(m);
    return 0;
}
