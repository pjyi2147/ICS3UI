// Lab 7.5.1 by Jeongseop Yi
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "ipAddress.cpp"

using namespace std;

int main()
{
	string line, ip1, ip2;
	getline(cin, line);
	int n = line.find(',');

	ip1 = line.substr(0,n);
	ip2 = line.substr(n + 2);

	ipAddress adr(ip1, ip2);

	if (adr.pass)
	{
		cout << "Valid IP Header." << endl;
	}
}
