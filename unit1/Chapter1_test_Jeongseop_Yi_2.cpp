// ICS3UI Chapter 1 test #2 by Jeongseop Yi
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    float average;
    float sum = 0;
    int mark;
    string x;
    string y;
    for(int i = 0; i < 10; ++i) {
        cout << "name:";
        if (i==6) {
            cin >> x >> y;
        }
        else {
            cin >> x;
        }
        cout << "mark:";
        cin >> mark;
        sum += (float)mark;
    }
    cout << "The average mark in class is " << sum / 10 << "%.";
    return 0;
}
