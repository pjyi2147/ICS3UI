// Lab 4.5.5 pattern matching by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

int main() {
	string pattern;
	getline(cin, pattern);

	string sentence;
	getline(cin, sentence);

	string word = "";
	string words[100];
	int nWord = 0;

	string fitPattern[100];
	int nfitWord = 0;

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
		string str = words[i];
		string fitWord = "";
		if (str.size() == pattern.size()) {
			bool patternMade = true;
			int j = 0;              // track the number of the word
			while (patternMade) {
				if (fitWord.size() == pattern.size()) {
					fitPattern[nfitWord] = fitWord;
					nfitWord += 1;
					fitWord = "";
					break;
				}
				else {
                    if (pattern[j] == '?') {
						fitWord += str[j];
                        j += 1;
					}
					else if (pattern[j] == 'A') {
						if (str[j] >= 'A' && str[j] <= 'z') {
							fitWord += str[j];
							j += 1;
						}
						else {
							patternMade = false;
							break;
						}
					}
					else if (pattern[j] == 'D') {
						if (str[j] >= '0' && str[j] <= '9') {
							fitWord += str[j];
							j += 1;
						}
						else {
							patternMade = false;
							break;
						}
					}
					else {
						if (str[j] == pattern[j]) {
							fitWord += str[j];
							j += 1;
						}
						else {
							patternMade = false;
							break;
						}
					}
				}
			}
		}
		else {
			continue;
		}
	}
	sentence.clear();
	for (int i = 0; i < nfitWord; i++) {
		sentence += fitPattern[i];
	}
    cout << sentence << endl;
	return 0;
}

