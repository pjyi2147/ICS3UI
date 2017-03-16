#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    bool answer;
    float x, y;
    float a, b;
    cin >> x >> y;
    a = 1.0 / x;
    b = 1.0 / y;
    answer = (a == b);
    cout << (answer ? "Results are equal (by 0.000001 epsilon)" :
        "Results are not equal (by 0.000001 epsilon)") << endl;
    return 0;
}
