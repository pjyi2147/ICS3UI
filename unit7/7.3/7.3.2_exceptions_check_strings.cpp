// Lab 7.3.2 by Jeongseop Yi
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

class invalidip : public exception {};
class invalidRange : public exception {};

bool ipverifier(string ip)
{
	bool iptrue = true;
	string address[4] = { "","","","" };
	if (ip.length() < 7) {
		cout << "Too less characters in part" << endl;
		cin >> ip;
		throw invalidip();
	}
	if (ip.size() > 15) {
		cout << "Too many characters in part" << endl;
		cin >> ip;
		throw invalidip();
	}
	// find . and divide up to parts
	for (int i = 0; i < 4; i++) {
		int x = ip.find('.');
		string k = "";
		// split
		if (i == 3) {
			k = ip.substr(0, x);
		}
		else if (x > 0) {
			k = ip.substr(0, x);
		}
		address[i] = k;
		// block length validation
		if (address[i].size() > 3) {
			cout << "One of the parts has too many characters" << endl;
			iptrue = false;
			throw invalidip();
		}
		if (address[i].size() <= 0) {
			cout << "One of the parts has no characters." << endl;
			iptrue = false;
			throw invalidip();
		}
			ip = ip.substr(x + 1);
	}
	// number validation
	for (int i = 0; i < 4; i++) {
		if (address[i] > "999") {
			cout << "Only digits and dots allowed" << endl;
			throw invalidip();
		}
		if (stoi(address[i]) > 255) {
			cout << "Too big value of part" << endl;
			throw invalidip();
		}
	}
	// passed
	return true;
}

int rangeVerifier(int r)
{
	if (r == 1)
	{
		return 1;
	}
	if (r % 2 == 1)
	{
		throw invalidRange();
	}
	return rangeVerifier(r / 2);
}

int main() {
	string ip, r;
	cout << "Input ip: ";
	cin >> ip;
	cout << "Input range: ";
	cin >> r;
	try
	{
		ipverifier(ip);
		rangeVerifier(stoi(r));
		for (int i = 1; i <= stoi(r); i++)
		{
			int k = ip[ip.size() - 1] - '0';
			k = k + i;
			if (k < 10)
			{
				cout << ip.substr(0, ip.size() - 1) << k << endl;

			}
		}
	}
	catch (invalidip a)
	{
		cout << "Invalid IP" << endl;
	}
	catch (invalidRange a)
	{
		cout << "Invalid Range" << endl;
	}
	catch (exception a)
	{
		cout << a.what() << endl;
	}
}
