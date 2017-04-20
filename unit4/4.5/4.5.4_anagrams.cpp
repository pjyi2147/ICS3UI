// Lab 4.5.4 anagrams by Jeongseop Yi

#include <iostream>
#include <string>

using namespace std;

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    string alphabet = "abcdefghijklnmopqrstuvwxyz";
    int alphaWord1[26];
    int alphaWord2[26];
    for (int i = 0; i < 26; i++) {
        alphaWord1[i] = 0;
        alphaWord2[i] = 0;
    }

    bool isAnagram = true;
    if (word1.size() != word2.size()) {
        isAnagram = false;
    }
    if (isAnagram) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < word1.size(); j++) {
                if (alphabet[i] == word1[j]) {
                    alphaWord1[i] += 1;
                }
                if (alphabet[i] == word2[j]) {
                    alphaWord2[i] += 1;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (alphaWord1[i] != alphaWord2[i]) {
                isAnagram = false;
                break;
            }
        }
        if (isAnagram) {
            cout << "anagrams" << endl;
        }
        else {
            cout << "not anagrams" << endl;
        }
    }
    else {
        cout << "not anagrams" << endl;
    }
    return 0;
}
