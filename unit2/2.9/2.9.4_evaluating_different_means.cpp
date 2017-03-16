// Lab 2.9.4 by Jeongseop Yi
#include <iostream>
#include <cmath>

using namespace std;
int main() {

    double vector1[] = {1.,2.,3.,4.,5.};
    int n = sizeof(vector1) / sizeof(vector1[1]);
    double ArithmeticMean = 0.;
    double HarmonicMean = 0.;
    double GeometricMean = 1.;                  // since Geometric mean will be multiplied by some value
    double RootMeanSquare = 0.;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        ArithmeticMean += vector1[i];
        HarmonicMean += (1. / vector1[i]);
        GeometricMean *= vector1[i];
        RootMeanSquare += pow(vector1[i], 2);
    }

    ArithmeticMean = ArithmeticMean / n;
    HarmonicMean = (double) n / HarmonicMean;
    GeometricMean = pow(GeometricMean, (double) (1./(double) n) );
    RootMeanSquare = sqrt(RootMeanSquare / (double)n);


    cout << "Arithmetic Mean = " << ArithmeticMean << endl;
    cout << "Harmonic Mean = " << HarmonicMean << endl;
    cout << "Geometric Mean = " << GeometricMean << endl;
    cout << "RootMean Square = " << RootMeanSquare << endl;

    cout << endl;
    return 0;
}
