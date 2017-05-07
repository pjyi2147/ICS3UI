// Lab 6.4.2 by Jeongseop Yi
#include  <iostream>
#include  <string>

using namespace std;

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input) = 0;
};

class MinLengthValidator : public StringValidator
{
public:
	MinLengthValidator(int min);
	bool isValid(string input);
private:
	int min;
};

MinLengthValidator::MinLengthValidator(int min)
{
	this->min = min;
}

bool MinLengthValidator::isValid(string input)
{
	return (this->min <= input.size()) ? 1 : 0;
}

class MaxLengthValidator : public StringValidator
{
public:
	MaxLengthValidator(int max);
	bool isValid(string input);
private:
	int max;
};

MaxLengthValidator::MaxLengthValidator(int max)
{
	this->max = max;
}

bool MaxLengthValidator::isValid(string input)
{
	return (this->max >= input.size()) ? 1 : 0;
}

class PatternValidator : public StringValidator
{
public:
	PatternValidator(string pattern);
	bool isValid(string input);
private:
	string pattern;
};

PatternValidator::PatternValidator(string pattern)
{
	this->pattern = pattern;
}


bool PatternValidator::isValid(string sentence)
{
	// from 4.5.5 pattern matching
	string word = "";
	string words[100];
	int nWord = 0;

	string fitPattern[100];
	int nfitWord = 0;

	// separate sentence into words
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

	// start matching
	for (int i = 0; i < nWord; i++) {
		string str = words[i];
		string fitWord = "";
		// first the word size should be equal to the pattern
		if (str.size() == pattern.size()) {
			bool patternMade = true;
			// track the index of the word
			int j = 0;
			while (patternMade && nfitWord == 0) {
				if (fitWord.size() == pattern.size()) {
					return true;
				}
				// any letter
				if (pattern[j] == '?') {
					fitWord += str[j];
					j += 1;
				}
				// alphabetical
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
				// numerical
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
				// other letters equal to the letter regardless of big or small
				else {
					char c = tolower(str[j]);
					if (c == pattern[j]) {
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
	return false;
}

void PrintValid(StringValidator* validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator->isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	PrintValid(&min, "hello");
	PrintValid(&min, "welcome");
	cout << endl;

	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	PrintValid(&max, "hello");
	PrintValid(&max, "welcome");
	cout << endl;

	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	PrintValid(&digit, "There are 2 types of sentences in the world");
	PrintValid(&digit, "valid and invalid ones");
	cout << endl;

	return 0;
}
