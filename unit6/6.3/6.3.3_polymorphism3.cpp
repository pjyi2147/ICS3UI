// Lab 6.3.3 by Jeongseop Yi
#include  <iostream>
#include  <string>

using namespace std;

class IPAddress
{
public:
	IPAddress(string IP);
	string IP;
	virtual void print();
};

class IPAddressChecked : public IPAddress
{
public:
	IPAddressChecked(string IP);
	bool correctIP;
	void print();
};

IPAddress::IPAddress(string IP)
{
	this->IP = IP;
}

void IPAddress::print()
{
	cout << this->IP << endl;
}

IPAddressChecked::IPAddressChecked(string IP) : IPAddress(IP)
{
    // ip validation from 4.5.1 strings in functions
	this->correctIP = true;
	string address[4] = { "","","","" };
	if (IP.length() < 7) {
		this->correctIP = false;
	}
	else if (IP.size() > 15) {
		this->correctIP = false;
	}
	// the length is ok
	else {
		// find . and divide up to parts
		for (int i = 0; i < 4; i++) {
			int x = IP.find('.');
			string k = "";
			if (i == 3) {
				k = IP.substr(0);
			}
			else if (x > 0) {
				k = IP.substr(0, x);
			}
			address[i] = k;
			if (address[i].size() > 3) {
				this->correctIP = false;
				break;
			}
			else if (address[i].size() <= 0) {
				this->correctIP = false;
				break;
			}
			else {
				IP = IP.substr(x + 1);
			}
		}

		if (this->correctIP) {
			for (int i = 0; i < 4; i++) {
				// check if there
				if (address[i] > "999" || address[i] < "0") {
					this->correctIP = false;
					break;
				}
				else if (stoi(address[i]) > 255) {
					this->correctIP = false;
					break;
				}
			}
		}
	}
}

void IPAddressChecked::print()
{
	cout << this->IP << " - ";
	if (!(this->correctIP)) cout << "Not ";
	cout << "Correct" << endl;
}


int main()
{
	string ipadd1;
	string ipadd2;
	string ipadd3;

	cin >> ipadd1 >> ipadd2 >> ipadd3;

	IPAddress ip1(ipadd1);
	IPAddressChecked ip2(ipadd2);
	IPAddressChecked ip3(ipadd3);

	ip1.print();
	ip2.print();
	ip3.print();
}
