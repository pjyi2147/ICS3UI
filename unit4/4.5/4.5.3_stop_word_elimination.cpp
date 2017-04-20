// Lab 4.5.2 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

int main() {
	string stopWords[100];
	string stopWord = "";
	int nstopWord = 0;
	string words[100];
	string word = "";
	int nWord = 0;

	string stop_words;
	getline(cin, stop_words);

	string sentence;
	getline(cin, sentence);

	for (int i = 0; i < stop_words.size(); i++) {
		if (stop_words[i] != ',') {
			stopWord += stop_words[i];
		}
		else if ((stop_words[i - 1] != ',' && stop_words[i] == ',')) {
			stopWords[nstopWord] = stopWord;
			nstopWord += 1;
			stopWord = "";
		}
		if (i == stop_words.size() - 1) {
			stopWords[nstopWord] = stopWord;
			nstopWord += 1;
			stopWord = "";
		}
	}

	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] != ' ') {
			if (sentence[i] < 'a' && sentence[i] >= 'A') {
				word += sentence[i] - 'A' + 'a';
			}
			else {
				word += sentence[i];
			}
		}
		else if ((sentence[i - 1] != ' ' && sentence[i] == ' ')) {
			bool therestop = false;
			for (int j = 0; j < nstopWord; j++) {
				if (stopWords[j] == word) {
					therestop = true;
				}
			}
			if (!therestop) {
				words[nWord] = word;
				nWord += 1;
			}
			word = "";
		}
		if (i == sentence.size() - 1) {
			bool therestop = false;
			for (int j = 0; j < nstopWord; j++) {
				if (stopWords[j] == word) {
					therestop = true;
				}
			}
			if (!therestop) {
				words[nWord] = word;
				nWord += 1;
			}
			word = "";
		}
	}
	sentence.clear();
	for (int i = 0; i < nWord; i++) {
		sentence += words[i] + " ";
	}

	cout << sentence << endl;

	return 0;
}
