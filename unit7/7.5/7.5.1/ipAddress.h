#ifndef __ipAddress
#define __ipAddress

#include <iostream>
#include <string>
#include <cstdbool>

using namespace std;
class ipAddress
{
public:
	ipAddress(string sourceIp, string destineIp);
	bool pass = false;
private:
	string sourceIp;
	string destineIp;
	bool validateIp(string ip);
};

class invalidip : public exception {};

#endif // __ipAddress
