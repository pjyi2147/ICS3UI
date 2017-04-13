// Lab 4.4.1 by Jeongseop Yi
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	bool panagram = true;
	int alphacount[26];
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= 'A' - 'a';
		}
	}
	// std::transform(str.begin(), str.end(), str.begin, ::tolower);
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		alphacount[i] = 0;
	}

	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == alphabet[j]) {
				alphacount[j] += 1;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphacount[i] == 0) {
			panagram = false;
			break;
		}
	}

	if (panagram) {
		cout << "Pangram" << endl;
	}
	else {
		cout << "Not pangram" << endl;
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << "-" << alphacount[i] << endl;
	}
	return 0;
}
