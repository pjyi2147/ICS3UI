// De Morgan's Law
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
    cout << "to prove, suppose statement 3 as a == b and statement 4 as g != 5" << endl << endl;

    cout << "when statement 3 = true, and when statement 4 = true, when a = b = 1, g = 3" << endl;
    a = 1;
    b = 1;
    g = 3;
    state1 = !(a == b) || !(g !=5);
    state2 = !(a == b && g !=5);
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "when statement 3 = true, and when statement 4 = false, when a = b = 1, g = 5" << endl;
    g = 5;
    state1 = !(a == b) || !(g !=5);
    state2 = !(a == b && g !=5);

    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "when statement 3 = false, and when statement 4 = true, when a = 1, b = 2, g = 3" << endl;
    b = 2;
    g = 3;
    state1 = !(a == b) || !(g !=5);
    state2 = !(a == b && g !=5);
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "when statement 3 = false, and when statement 4 = false, when a = b = 1" << endl;
    g = 5;
    state1 = !(a == b) || !(g !=5);
    state2 = !(a == b && g !=5);
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;

    cout << "since the two statements gives same results in 4 different cases," << endl
        << "therefore the two statements are equivalent." << endl;
    return 0;
}
