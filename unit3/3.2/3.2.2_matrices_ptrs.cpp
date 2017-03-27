// Lab 3.2.2 Matrices and pointers by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int matrix[10][10] = { };

    int *row;
    row = matrix[0];
    for (int i = 0; i < 100; i++) {
        if (i < 10) {
            *row = *(row-1) + 1;
        }
        else if (i % 10 == 0) {
            *row = *(row-10) + 1;
        }
        else {
            *row = (*(row-(10*(i/10))))*(*(row-(i%10)));
        }
        row = row + 1;
    }

    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
