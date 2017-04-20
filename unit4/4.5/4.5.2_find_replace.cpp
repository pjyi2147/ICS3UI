// Lab 4.5.2 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

int main() {
	string words[100];
	string word = "";
	int nWord = 0;

	string form;
	getline(cin, form);

	string to;
	getline(cin, to);

	string sentence;
	getline(cin, sentence);

	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] != ' ') {
			word += sentence[i];
		}
		else if ((sentence[i - 1] != ' ' && sentence[i] == ' ')) {
			words[nWord] = word;
			nWord += 1;
			word = "";
		}
		if (i == sentence.size() - 1) {
			words[nWord] = word;
			nWord += 1;
			word = "";
		}
	}
	for (int i = 0; i < nWord; i++) {
		if (words[i] == form) {
			words[i] = to;
		}
	}
	sentence.clear();
	for (int i = 0; i < nWord; i++) {
		sentence += words[i] + " ";
	}

	cout << sentence << endl;

	return 0;
}
