// Lab 2.3.6 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int h;
    cout << "Input h: ";
    cin >> h;
    // do this for the h lines
    // maximum i equals to h - 1
    for (int i = 0; i < h; i++) {
        // do three times to make a three triangle
        // first spaces
        for (int k = 0; k < 5; k++) {
            cout << " ";
        }
        // printing one line
        // three triangles
        for(int j = 0; j < 3; j++) {
            // the first half of triangle
            // leading spaces
            for (int k = h; k > i+1; k--) {
                cout << " ";
            }
            // star
            cout << "*";
            // following spaces
            for (int k = 0; k < i; k++) {
                // last line
                if (i == h-1) {
                    cout << "*";
                }
                // not last line
                else cout << " ";
            }
            // the second half of triangle
            // filling space backwards
            // first line
            if (i == 0) {
                for (int k = 0; k < h - 1; k++) {
                    cout << " ";
                }
            }
            // other lines
            else if (i != h-1) {
                //leading spaces
                for (int k = 0; k < i - 1; k++) {
                    cout << " ";
                }
                // star
                cout << "*";
                // following spaces
                for (int k = 0; k < h - 1 - i; k++) {
                    cout << " ";
                }
            }
            // last line
            else {
                for (int k = 0; k < h - 1; k++) {
                    cout << "*";
                }
            }
            // extra space between triangles
            for (int k = 0; k < 9 - h; k++) {
                cout << " ";
            }
        }
        // end of a line
        cout << endl;
    }
    return 0;
}
