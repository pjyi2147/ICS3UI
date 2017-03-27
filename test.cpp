#include <iostream>

using namespace std;

int main(void) {
    int *ptr, arr[3], *ptr2, i;
    arr[0] = 3;
    ptr = arr;
    ptr2 = ptr + 1;
    i = ptr2 - ptr;
    cout << ptr << " " << ptr2 << " " << i << endl;
    return 0;
}
