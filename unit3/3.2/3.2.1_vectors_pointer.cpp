// Lab 3.2.1 by Jeongseop Yi
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {

    int vector1[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector1) / sizeof(vector1[0]);
    // Insert your code here
    int *ptr;
    ptr = vector1;
    int mini = INT32_MAX;
    for(int i = 0; i < n; i++) {
        if (*ptr < mini) {
            mini = *ptr ;
        }
        ptr = ptr+1;
    }
    cout << mini << endl;
    return 0;
}
