// Lab 2.5.1 by Jeongseop Yi
#include <iostream>

using namespace std;
int main() {
    int a;
    int x, y;
    cout << "0 - exit \n1 - addition \n2 - subtraction \n3 - multiplication \n4 - division\nYour choice? : ";
    cin >> a;
    switch (a) {
        case 0: break;
        case 1: cout << "Addition: input 2 numbers ";
                cin >> x >> y;
                cout << x + y;
                break;
        case 2: cout << "Subtraction: input 2 numbers ";
                cin >> x >> y;
                cout << x - y;
                break;
        case 3: cout << "Multiplication: input 2 numbers ";
                cin >> x >> y;
                cout << x * y;
                break;
        case 4: cout << "Division: input 2 numbers ";
                cin >> x >> y;
                if (y) {
                    cout << (float)x / (float)y;
                }
                else {
                    cout << "Division by 0 error ";
                }
    }
    return 0;
}
