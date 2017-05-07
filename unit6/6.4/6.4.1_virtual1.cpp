// Lab 6.4.1 by Jeongseop Yi
#include  <iostream>
#include  <string>

using namespace std;

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input) = 0;
};

class ExactValidator : public StringValidator
{
public:
	ExactValidator(string password);
	virtual bool isValid(string input);
private:
	string password;
};

ExactValidator::ExactValidator(string password)
{
	this->password = password;
}

bool ExactValidator::isValid(string input)
{
	return (input == this->password) ? 1 : 0;
}

class DummyValidator : public StringValidator
{
public:
	DummyValidator();
	virtual bool isValid(string input);
private:
	string password;
};

DummyValidator::DummyValidator()
{
	this->password = "change";
}

bool DummyValidator::isValid(string input)
{
	return (this->password == input) ? 1 : 0;
}

void PrintValid(StringValidator* validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator->isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
	DummyValidator dummy;
	PrintValid(&dummy, "hello");
	cout << endl;


	ExactValidator exact("secret");
	PrintValid(&exact, "hello");
	PrintValid(&exact, "secret");

	return 0;
}
