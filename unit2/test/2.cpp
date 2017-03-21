// pythagorian triple by Jeongseop Yi
#include <iostream>
#include <string>
using namespace std;
struct tri {
    int s1, s2, h;
} lst[1000];

int main() {
    int counter = 0;
    for (int i = 1; i <= 500; i++) {            // i => hypotenuse
        for (int j = 1; j <= i; j++) {          // j => s1
            for (int k = 1; k <= j; k++ ) {     // k => s2
                if (i*i == j*j + k*k) {
                    lst[counter].s1 = j;
                    lst[counter].s2 = k;
                    lst[counter].h = i;
                    counter += 1;
                }
            }
        }
    }
    cout << "There are " << counter << " sets of integer Pythagorean triangle s1,s2,h <= 500." << endl;
    cout << "The lists are:" << endl;
    for (int z = 0; z < counter; z++) {
        cout << "h: " << lst[z].h << " s1: " << lst[z].s1 << " s2: " << lst[z].s2 << endl;
    }
    return 0;

}
