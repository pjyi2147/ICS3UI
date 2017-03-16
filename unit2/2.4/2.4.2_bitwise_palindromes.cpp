// Lab 2.4.2 by Jeongseop Yi
#include <iostream>
#include <bitset>

using namespace std;
int main() {

    unsigned int val;
    bool ispalindrome = false;
    unsigned int reversed = 0;
    cout << "value = ";
    cin >> val;
    unsigned int a = val;
    // my code here
    while (val > 0) {
         reversed = (reversed << 1) | (val & 1);
         val >>= 1;
    }

    ispalindrome = (a == reversed);
    if (ispalindrome) {
        cout << a << " is a bitwise palindrome" << endl;
    }
    else {
        cout << a << " is not a bitwise palindrome" << endl;
    }
    return 0;
}
