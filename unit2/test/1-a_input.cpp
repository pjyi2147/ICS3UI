// 1-a with user input function
#include <iostream>

using namespace std;
string boolean(bool z) {
    if (z) {
        return "true";
    }
    else {
        return "false";
    }
}

int main() {
    int x, y;
    bool state1, state2;
    cout << "According to De Morgans law, the statements 1 and 2:" << endl << "!(x < 5) && !(y >= 7)"
        << " and !(x < 5 || y >= 7) is considered as equivalent statement." << endl;
    cout << "input 2 numbers for x and y, and compare the result of the two separated by space: ";
    cin >> x >> y;
    state1 = !(x < 5) && !(y >= 7);
    state2 = !(x < 5 || y >= 7);
    cout << endl << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;
    cout << "since the two statements gives same results whichever cases given," << endl
        << "therefore the two statements are equivalent." << endl;
    return 0;
}
