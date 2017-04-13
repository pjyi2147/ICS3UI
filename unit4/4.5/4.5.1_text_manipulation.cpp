// Lab 4.5.1 by Jeongseop Yi
#include <iostream>
#include <string>


using namespace std;

int main() {
	string sentence;
	string words[100];
	int nWords = 0;
	getline(cin, sentence);

	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] == ' ') {
			while (sentence[i + 1] == ' ') {
				sentence.erase(i + 1, 1);
			}
		}
	}

	cout << sentence << endl;
	return 0;
}
