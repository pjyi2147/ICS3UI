// Lab 6.4.3 by Jeongseop Yi
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

class LengthValidator : public StringValidator
{
public:
	LengthValidator(int min, int max);
	bool isValid(string input);
private:
	MinLengthValidator min_validator;
	MaxLengthValidator max_validator;
};

LengthValidator::LengthValidator(int min, int max) : min_validator(min), max_validator(max)
{
}

bool LengthValidator::isValid(string input)
{
	return (min_validator.isValid(input) && max_validator.isValid(input));
}

class UppercaseValidator : public StringValidator
{
public:
	bool isValid(string input);
};

bool UppercaseValidator::isValid(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			return true;
		}
	}
	return false;
}

class LowercaseValidator : public StringValidator
{
public:
	bool isValid(string input);
};

bool LowercaseValidator::isValid(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			return true;
		}
	}
	return false;
}

class DigitValidator : public StringValidator
{
public:
	bool isValid(string input);
};

bool DigitValidator::isValid(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			return true;
		}
	}
	return false;
}

class SpecialValidator : public StringValidator
{
public:
	bool isValid(string input);
};

bool SpecialValidator::isValid(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (!isalnum(input[i]))
		{
			return true;
		}
	}
	return false;
}


void PrintValid(StringValidator* validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator->isValid(input) ? "valid" : "invalid") << endl << endl;
}

int main()
{
	LengthValidator length(5, 7);
	UppercaseValidator pass1;
	LowercaseValidator pass2;
	DigitValidator pass3;
	SpecialValidator pass4;

	PrintValid(&length, "password");
	PrintValid(&length, "passwo");

	PrintValid(&pass1, "Upper");
	PrintValid(&pass1, "noupper");

	PrintValid(&pass2, "noupper");
	PrintValid(&pass2, "UPPER");

	PrintValid(&pass3, "Upper0");
	PrintValid(&pass3, "noupper");

	PrintValid(&pass4, "Uppe[]");
	PrintValid(&pass4, "noupper");

	return 0;
}
