// De Morgan's Law by Jeongseop Yi
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
    int x, y;
    bool state1, state2;

    cout << "According to De Morgans law, the statements 1 and 2:" << endl << "!(x < 5) && !(y >= 7)"
        << " and !(x < 5 || y >= 7) is considered as equivalent statement." << endl;
    cout << "to prove, suppose statement 3 as x < 5 and statement 4 as y >= 7" << endl << endl;

    cout << "when statement 3 = true, and when statement 4 = true, when x = 4, y = 8" << endl;
    x = 4;
    y = 8;
    state1 = !(x < 5) && !(y >= 7);
    state2 = !(x < 5 || y >= 7);
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "when statement 3 = true, and when statement 4 = false, when x = 4, y = 5" << endl;
    y = 5;
    state1 = !(x < 5) && !(y >= 7);
    state2 = !(x < 5 || y >= 7);
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "when statement 3 = false, and when statement 4 = true, when x = 7, y = 8" << endl ;
    x = 7;
    y = 8;
    state1 = !(x < 5) && !(y >= 7);
    state2 = !(x < 5 || y >= 7);
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "when statement 3 = false, and when statement 4 = false, when x = 7, y = 2" << endl;
    y = 2;
    state1 = !(x < 5) && !(y >= 7);
    state2 = !(x < 5 || y >= 7);
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "since the two statements gives same results in 4 different cases," << endl
        << "therefore the two statements are equivalent." << endl;
    return 0;
}
