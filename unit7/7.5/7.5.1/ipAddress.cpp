#include "ipAddress.h"
#include <stdexcept>
#include <exception>

using namespace std;

ipAddress::ipAddress(string sourceIp, string destineIp)
{
	try
	{
		if (validateIp(sourceIp))
		{
			this->sourceIp = sourceIp;
		}
	}
	catch (exception ex)
	{
		cout << "Invalid IP Header - Source IP Address is invalid." << endl;
	}
	try
	{
		if (validateIp(destineIp))
		{
			this->destineIp = destineIp;
		}
		this->pass = true;
	}
	catch (exception ex)
	{
		cout << "Invalid IP Header - Destination IP Address is invalid." << endl;
	}
}

bool ipAddress::validateIp(string ip)
{
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
			throw invalidip();
		}
		if (address[i].size() <= 0) {
			cout << "One of the parts has no characters." << endl;
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
			cout << "Too big value of a section" << endl;
			throw invalidip();
		}
	}
	// passed
	return true;
}
