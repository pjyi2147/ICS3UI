// Lab 4.5.1 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

int main() {
	string ip;
	cin >> ip;
	while (ip != "q") {
		bool iptrue = true;
		string address[4] = { "","","","" };
		if (ip.length() < 7) {
			cout << "Too less characters in part" << endl;
			cin >> ip;
			continue;
		}
		else if (ip.size() > 15) {
			cout << "Too many characters in part" << endl;
			cin >> ip;
			continue;
		}
		// the length is ok
		else {
			// find . and divide up to parts
			for (int i = 0; i < 4; i++) {
				int x = ip.find('.');
				string k = "";
				if (i == 3) {
					k = ip.substr(0, x);
				}
				else if (x > 0) {
					k = ip.substr(0, x);
				}
				address[i] = k;
				if (address[i].size() > 3) {
					cout << "One of the parts has too many characters" << endl;
					iptrue = false;
					break;
				}
				else if (address[i].size() <= 0) {
					cout << "One of the parts has no characters." << endl;
					iptrue = false;
					break;
				}
				else {
					ip = ip.substr(x + 1);
				}
			}
			if (!iptrue) {
				cin >> ip;
				continue;
			}
			else {
				for (int i = 0; i < 4; i++) {
					if (address[i] > "999") {
						cout << "Only digits and dots allowed" << endl;
						cin >> ip;
						break;
					}
					else if (stoi(address[i]) > 255) {
						cout << "Too big value of part" << endl;
						cin >> ip;
						break;
					}
				}
				cout << "Correct IP" << endl;
				cin >> ip;
			}
		}
	}
}
