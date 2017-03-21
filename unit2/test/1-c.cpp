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
    int i, j;
    bool state1, state2;

    cout << "According to De Morgans law, the statement 1 and 2" << endl << "!((i > 4) || (j <= 6 ))"
        << " and !(i > 4) && !(j <= 6 ) is considered as equivalent statement." << endl;
    cout << "to prove, suppose statement 3 as i > 4 and statement 4 as j <= 6." << endl << endl;
    ////
    cout << "when statement 3 is true, and when statement 4 is true, when i = 5, j = 5" << endl;
    i = 5;
    j = 5;
    state1 = !((i > 4) || (j <= 6 ));
    state2 = !(i > 4) && !(j <= 6 );
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;
    ////
    cout << "when statement 3 = true, and when statement 4 = false, when i = 5, j = 7" << endl;
    j = 7;
    state1 = !((i > 4) || (j <= 6 ));
    state2 = !(i > 4) && !(j <= 6 );
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;
    ////
    cout << "when statement 3 = false, and when statement 4 = true, when i = 3, j = 5" << endl;
    i = 3;
    j = 5;
    state1 = !((i > 4) || (j <= 6 ));
    state2 = !(i > 4) && !(j <= 6 );
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;
    ////
    cout << "when statement 3 = false, and when statement 4 = false, when i = 3, j = 7" << endl;
    j = 7;
    state1 = !((i > 4) || (j <= 6 ));
    state2 = !(i > 4) && !(j <= 6 );
    cout << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;
    ////
    cout << "since the two statements gives same results in 4 different cases," << endl
        << "therefore the two statements are equivalent." << endl;

    return 0;
}
