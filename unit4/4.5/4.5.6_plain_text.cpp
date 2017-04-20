// Lab 4.5.6 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

int main()[
    string sentence;
    getline(cin, sentence);

    string word = "";
    string words[100];
    int nWord = 0;

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
        if (str[0] == '*' && str[str.size() - 1] = '*') {

        }
        else if (str[0] == '_' && str[str.size() - 1] = '_') {

        }
    }




    cout << sentence << endl;
    return 0;
]
