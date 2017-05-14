// Lab 6.5.1 by Jeongseop Yi
#include  <iostream>
#include  <string>

using namespace std;

class IpAddress
{
public:
	IpAddress();
	IpAddress(string ip);
	string ip;
};

IpAddress::IpAddress(string ip)
{
	this->ip = ip;
}

class Network
{
public:
	IpAddress* ipaddresses[3];
	void Appendip(IpAddress* a);
	void PrintIp();
	int ipcount = 0;
};

void Network::Appendip(IpAddress* a)
{
	this->ipaddresses[ipcount] = a;
	ipcount += 1;
}

void Network::PrintIp()
{
	for (int i = 0; i < ipcount; i++)
	{
		cout << this->ipaddresses[i]->ip << endl;
	}
}

int main()
{
	IpAddress* addresses[5];
	for (int i = 0; i < 5; i++)
	{
		string ip;
		cin >> ip;
		// make pointers to ipaddresses
		IpAddress* address = new IpAddress(ip);
		addresses[i] = address;
	}

	Network net1;
	Network net2;

	for (int i = 0; i < 3; i++)
	{
		net1.Appendip(addresses[i]);
	}
	for (int i = 2; i < 5; i++)
	{
		net2.Appendip(addresses[i]);
	}

	cout << "Network 1:" << endl;
	net1.PrintIp();
	cout << "Network 2:" << endl;
	net2.PrintIp();
}
