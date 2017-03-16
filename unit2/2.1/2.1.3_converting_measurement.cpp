// 2.1.3 converting measurement by Jeongseop Yi

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
    int sys;
    double m, ft, in;

    cin >> sys;
    if (sys == 1) { // imperial
        cout << "imperial to metric mode\n";
        cin >> ft >> in;
        m = (ft * 0.3048) + (in * 0.0254);
        cout << m << "m" << endl;
    }
    else if (sys == 0 ){ // metric
        cout << "metric to imperial mode\n";
        cin >> m;
        in = m * 39.37008;
        int ft1 = in / 12;
        in = in - ft1 * 12;
        cout << ft1 << "\'" << in << "\"";
    }
    else {
        cout << "Not supported. Try again\n";
    }
    return 0;
}
