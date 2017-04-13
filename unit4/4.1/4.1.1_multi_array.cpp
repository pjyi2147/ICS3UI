// Lab 4.1.1 by Jeongseop Yi
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int ** scores;
    int nCourses;
    int nMarks = 0;
    float overallFinal = 0;
    cout << fixed << std::setprecision(2);

    cin >> nCourses;
    scores = new int* [nCourses];
    for (int i = 0; i < nCourses; i++){
        int nScores = 0;
        cin >> nScores;
        nMarks += nScores;
        scores[i] = new int[nScores+1];
        scores[i][0] = nScores;
        for (int j = 1; j <= nScores; j++) {
            int mark;
            cin >> mark;
            scores[i][j] = mark;
        }
    }
    for (int i = 0; i < nCourses; i++) {
        float average = 0;
        for (int j = 1; j <= scores[i][0]; j++ ) {
            average += (float)scores[i][j];
        }
        average = average / (float)scores[i][0];
        overallFinal += average;
        cout << "Course " << i+1 << ": final " << average << ", grades: ";
        for (int j = 1; j <= scores[i][0]; j++) {
            cout << scores[i][j] <<  " ";
        }
        cout << endl;
    }

    overallFinal = overallFinal / (float) nCourses;
    cout << nMarks;
    cout << "Overall final " << overallFinal;
}
