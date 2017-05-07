/*
*  28/04/17
*  ICS3UI
*  Unit test 5 #1
*  Jeongseop Yi
*  Mr. Damian
*/

#include <iostream>
#include <string>

using namespace std;

class Product {
public:
	Product(int id, double price);
	double getPrice();
private:
	int id;
	double price;
};

Product::Product(int id, double price)
{
	this->id = id;
	this->price = price;
}

double Product::getPrice() {
    return this->price;
}

int main()
{
	int plist[5] = { 0,0,0,0,0 };
	double total = 0;
	Product p1(1, 2.98);
	Product p2(2, 4.50);
	Product p3(3, 9.98);
	Product p4(4, 4.49);
	Product p5(5, 6.87);
	cout << "This program receives shopping list of the user" << endl
		<< " and prints out the total amount of the shopping list when it quits" << endl << endl;

	cout << "The operation methods are " << endl
		<< "if you are to buy, type buy [id] [amount]" << endl
		<< "if you are to cancel what you have put on list, type cancel [id] [amount]" << endl
		<< "*this method will not work when you try to cancel more than you have put on the list." << endl
		<< "*and the shopping list will remain the same" << endl
		<< "if you are to quit, type quit" << endl << endl;

    cout << "Product 1: id = 1, price = $2.98" << endl;

    cout << "Product 2: id = 2, price = $4.50" << endl;

    cout << "Product 3: id = 3, price = $9.98" << endl;

    cout << "Product 4: id = 4, price = $4.49" << endl;

    cout << "Product 5: id = 5, price = $6.87" << endl << endl;

	string order = "";
	while (order != "quit")
	{
		cout << "Enter command: ";
		cin >> order;

		if (order == "buy")
		{
			int id;
			int amount;
			cin >> id >> amount;
			if (amount >= 0) {
                if (id == 1) {
                    plist[0] += amount;
                    total += p1.getPrice() * amount;
                }
                else if (id == 2) {
                    plist[1] += amount;
                    total += p2.getPrice() * amount;
                }
                else if (id == 3) {
                    plist[2] += amount;
                    total += p3.getPrice() * amount;
                }
                else if (id == 4) {
                    plist[3] += amount;
                    total += p4.getPrice() * amount;
                }
                else if (id == 5) {
                    plist[4] += amount;
                    total += p5.getPrice() * amount;
                }
                else {
                    cout << "Unknown id: try again" << endl;
                }
			}
			else {
                cout << "No negatives in amount: try again" << endl;
			}
		}
		else if (order == "cancel")
		{
			int id;
			int amount;
			cin >> id >> amount;
			if (amount >= 0) {
                if (id == 1) {
                    if (plist[0] >= amount) {
                        plist[0] -= amount;
                        total -= p1.getPrice() * amount;
                    }
                    else {
                        cout << "you did not buy that many: try again" << endl;
                    }
                }
                else if (id == 2) {
                    if (plist[1] >= amount) {
                        plist[1] -= amount;
                        total -= p2.getPrice() * amount;
                    }
                    else {
                        cout << "you did not buy that many: try again" << endl;
                    }
                }
                else if (id == 3) {
                    if (plist[2] >= amount) {
                        plist[2] -= amount;
                        total -= p3.getPrice() * amount;
                    }
                    else {
                        cout << "you did not buy that many: try again" << endl;
                    }
                }
                else if (id == 4) {
                    if (plist[3] >= amount) {
                        plist[3] -= amount;
                        total -= p4.getPrice() * amount;
                    }
                    else {
                        cout << "you did not buy that many: try again" << endl;
                    }
                }
                else if (id == 5) {
                    if (plist[4] >= amount) {
                        plist[4] -= amount;
                        total -= p5.getPrice() * amount;
                    }
                    else {
                        cout << "you did not buy that many: try again" << endl;
                    }
                }
                else {
                    cout << "Unknown id: try again" << endl;
                }
			}
			else {
                cout << "No negatives in amount: try again" << endl;
            }
		}
		else if (order == "quit")
		{
			break;
		}
		else
		{
			cout << "Unknown command: try again" << endl;
		}
	}

    cout << "You bought: " << total << " dollars worth of items" << endl;
	return 0;
}
