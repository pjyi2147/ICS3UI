// User input function included.
#include <iostream>
#include <string>
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
    int a, b, g;
    bool state1, state2;

    cout << "According to De Morgans law, the statement 1 and 2" << endl << "!(a == b) || !(g !=5)"
        << " and !(a == b && g !=5) is considered as equivalent statement." << endl;
    cout << "input 3 numbers separated by space for a, b, g, and compare the result of the two statement: ";
    cin >> a >> b >> g;
    state1 = !(a == b) || !(g !=5);
    state2 = !(a == b && g !=5);
    cout << endl << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;
    cout << "since the two statements gives same results in whichever cases given" << endl
        << "therefore the two statements are equivalent." << endl;
    return 0;
}
