// Lab 3.10.1 by Jeongseop Yi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int main() {
    int maxball;
    int ballsno;

    cout << "Max ball number? ";
    cin >> maxball;
    cout << "How many balls? ";
    cin >> ballsno;

    // code

    int *balls;
    balls = new int[ballsno];
    random_device rd;                   // initialise seed engine
    mt19937 rng(rd());                  // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(1, maxball);  // guaranteed unbiased
    for (int i = 0; i < ballsno; i++) {
        balls[i] = uni(rng);                  // 32267
    }

    for (int i = 0; i < ballsno; i++) {
        cout << balls[i] << " ";
    }
    cout << endl;
    delete [] balls;
    return 0;
}
