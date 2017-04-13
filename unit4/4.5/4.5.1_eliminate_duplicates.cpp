// Lab 4.5.1 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

int main() {
	string sentence;
	string words[100];
	int nWord = 0;
	getline(cin, sentence);
	string word = "";
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] != ' ') {
			word += sentence[i];
		}
		else if ((sentence[i - 1] != ' ' && sentence[i] == ' ')) {
			bool thereis = false;
			for (int j = 0; j < nWord; j++) {
				if (words[j] == word) {
					thereis = true;
				}
			}
			if (!thereis) {
				words[nWord] = word;
				nWord += 1;
			}
			word = "";
		}
		if (i == sentence.size() - 1) {
			bool thereis = false;
			for (int j = 0; j < nWord; j++) {
				if (words[j] == word) {
					thereis = true;
				}
			}
			if (!thereis) {
				words[nWord] = word;
				nWord += 1;
			}
			word = "";
		}
	}
	sentence.clear();
	for (int i = 0; i < nWord + 1; i++) {
		sentence += words[i] + ' ';
	}
	std::cout << sentence << endl;
	return 0;
}

