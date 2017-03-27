// Lab 3.4.1 by Jeongseop Yi
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1; 
        }
    }
    else {
        return 0;
    }
}

int main() {
    for (int yr = 1995; yr < 2017; yr++) {
        cout << yr << " -> " << isLeap(yr) << endl;
    }
    return 0;
}
