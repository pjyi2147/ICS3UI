// Lab 5.1.1 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class Person {
	public:
		string name;
		int age;
		bool sex;
};

void print(Person* person) {
	cout << person->name << " is " << person->age << " years old." << endl;
}

int main() {
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.sex = 0;

	cout << "Meet " << person.name << endl;
	print(&person);
	if (person.sex) {
		cout << person.name << " is male." << endl;
	}
	else {
		cout << person.name << " is female." << endl;
	}
	int x;
	cin >> x;
	return 0;
}
