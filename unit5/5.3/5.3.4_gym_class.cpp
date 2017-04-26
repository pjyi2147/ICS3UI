// Lab 5.3.4 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class GymMember {
public:
	GymMember();
	GymMember(int id, string name, int sub);
	// get
	int getId();
	string getName();
	int getSub();
	void getStatus();
	// set
	void setId(int id);
	void setName(string name);
	void setSub(int sub);

private:
	int id;
	string name;
	int sub;
};

//initializers
GymMember::GymMember(int id, string name, int sub) {
	this->id = id;
	this->name = name;
	this->sub = sub;
}

GymMember::GymMember() {
	this->id = 0;
	this->name = "";
	this->sub = 0;
}

// get functions
int GymMember::getId() {
	return this->id;
}

string GymMember::getName() {
	return this->name;
}

int GymMember::getSub() {
	return this->sub;
}

void GymMember::getStatus() {
	cout << "Member " << this->id << " : " << this->name << ", "
		<< "subscription vaild for " << this->sub << " months." << endl;
}
// set functions;
void GymMember::setId(int id) {
	this->id = id;
}

void GymMember::setName(string name) {
	this->name = name;
}

void GymMember::setSub(int sub) {
	this->sub = sub;
}

int main() {
	GymMember memberList[10];
	string command = "";
	int nMember = 0;

	while (command != "quit") {
		cout << "Enter command: ";
		cin >> command;
		if (nMember == 0) {
			cout << "There is no member in the list" << endl << endl;
		}
		if (command == "create") {
			GymMember member;
			int id;
			string name;
			cin >> id;
			getline(cin, name);
			name = name.substr(1);
			member.setId(id);
			member.setName(name);

			memberList[nMember] = member;
			memberList[nMember].getStatus();
			nMember += 1;
		}
		else if (command == "delete") {
			// find a member that meets the id;
			GymMember ground;
			int id;
			bool found = false;
			cin >> id;
			for (int i = 0; i < nMember; i++) {
				if (memberList[i].getId() == id) {
					found = true;
					memberList[i] = ground;
					break;
				}
			}
			if (!found) {
				cout << "Cannot perform Operation: member " << id << " is not in the list." << endl;
			}
		}
		else if (command == "extend") {
			int id;
			int sub;
			bool found = false;
			cin >> id >> sub;

			for (int i = 0; i < nMember; i++) {
				if (memberList[i].getId() == id) {
					found = true;
					memberList[i].setSub(memberList[i].getSub() + sub);
					memberList[i].getStatus();
					break;
				}
			}
			if (!found) {
				cout << "Cannot perform Operation: member " << id << " is not in the list." << endl;
			}
		}
		else if (command == "cancel") {
			int id;
			bool found = false;
			cin >> id;


			for (int i = 0; i < nMember; i++) {
				if (memberList[i].getId() == id) {
					found = true;
					memberList[i].setSub(0);
					memberList[i].getStatus();
					break;
				}
			}
			if (!found) {
				cout << "Cannot perform Operation: member " << id << " is not in the list." << endl;
			}
		}
		else if (command == "quit") {
			break;
		}
		else {
			cout << "Operation failed: " << "not known command." << endl;
		}
	}
}
