#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << fixed << setprecision(1) << a << endl <<
        setprecision(2) << b << endl << setprecision(6) <<
        c << endl << setprecision(2) << d << endl << setprecision(0) << e << endl;
    return 0;
}
