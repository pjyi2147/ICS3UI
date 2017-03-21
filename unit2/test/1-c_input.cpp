// user input function enabled one 
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
    cout << "Input two numbers separated by space for i, j, and compare the results: ";
    cin >> i >> j;
    state1 = !((i > 4) || (j <= 6 ));
    state2 = !(i > 4) && !(j <= 6 );
    cout << endl << "Result of statement 1: " << boolean(state1) << ", statement 2: " << boolean(state2) << endl << endl;
    
    cout << "since the two statements gives same results whichever given cases," << endl
        << "therefore the two statements are equivalent." << endl;

    return 0;

}