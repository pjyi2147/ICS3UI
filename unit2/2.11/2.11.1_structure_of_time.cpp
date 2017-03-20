// Lab 2.11.1 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

struct time {
    int hour, minute;
} t1;

int timecalculator(int z) {
    if (z >= 1440) {
        return timecalculator(z%1440);
    }
    
    else if (z >= 60) {
        int k = z / 60;
        t1.hour += k;
        return timecalculator(z%60);
    }
    else if (z > 0) {
        t1.minute += z;
    }
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    t1.hour = x;
    t1.minute = y;
    timecalculator(z);
    if (t1.minute >= 60) {
        t1.minute -= 60;
        t1.hour += 1;
    }
    if (t1.hour >= 24) t1.hour -= 24;

    cout << t1.hour << ":" << t1.minute << endl;
    return 0;
}
