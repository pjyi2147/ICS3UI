// Lab 2.11.2 by Jeongseop Yi
#include <iostream>
#include <string>
using namespace std;
struct time {
    int hour, minute;
} t1, t2;
int main() {
    int a, b, c, d;
    int x, y;
    cin >> a >> b >> c >> d;
    t1.hour = a;
    t1.minute = b;
    t2.hour = c;
    t2.minute = d;

    x = t2.hour - t1.hour;
    y = t2.minute - t1.minute;

    if (x < 0) {
        x += 24;
    }
    if (y < 0) {
        y += 60;
        x -= 1;
    }
    cout << x << ":" << y << endl;
    return 0;
}
