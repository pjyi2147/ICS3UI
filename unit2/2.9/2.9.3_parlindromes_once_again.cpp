//Lab 2.9.3 by Jeongseop Yi
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int vector1[] = {1,7,3,1};
    bool ispalindrome = true;
    int n = sizeof(vector1) / sizeof(vector1[0]);
    for (int i = 0; i < n; i++) {               // maximum i is n-1
        if (vector1[i] != vector1[n-i-1]) {
            ispalindrome = false;
        }
    }

    if (ispalindrome) cout << "It is a palindrome";
    else cout << "It is not a palindrome";
    cout << endl;
    return 0;
}
