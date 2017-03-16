#include <iostream>
#include <string>

using namespace std;
int main() {
    float sum = 0;
    string x;
    for(int i = 0; i < 10; i++) {
        getline(cin, x);
        int pos = x.find("%");
        if(x.length() > 0) {
            x = x.substr(pos-2, 2);
            sum += stof(x);
        }
    }
    cout << "The average mark of 10 students: " << sum / 10 << "%" << endl;
    return 0;
}
