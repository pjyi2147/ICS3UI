// Lab 5.1.4 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder {
public:
	ShopItemOrder(string name, double price, int amount);
	void changePrice(double price);
	void changeAmount(int amount);
	void changeName(string name);
	string getName();
	double getPrice();
	int getAmount();
	double getTotalPrice();
private:
	string name;
	double price;
	int amount;
};

ShopItemOrder::ShopItemOrder(string name, double price, int amount)
{
	this->name = name;
	this->price = price;
	this->amount = amount;
}

void ShopItemOrder::changePrice(double price)
{
	this->price = price;
}

void ShopItemOrder::changeAmount(int amount)
{
	this->amount = amount;
}

void ShopItemOrder::changeName(string name)
{
	this->name = name;
}

string ShopItemOrder::getName()
{
	return this->name;
}

double ShopItemOrder::getPrice()
{
	return this->price;
}

int ShopItemOrder::getAmount()
{
	return this->amount;
}

double ShopItemOrder::getTotalPrice()
{
	return this->getAmount()*this->getPrice();
}

int main() {
	ShopItemOrder apple("apple", 3.23, 10);
	cout << "Name: " << apple.getName() << endl
		<< "Price: " << apple.getPrice() << endl
		<< "Amount: " << apple.getAmount() << endl
		<< "Total price: " << apple.getTotalPrice() << endl;

	apple.changeAmount(30);
	apple.changePrice(5.25);
	apple.changeName("Orange");

	cout << "Name: " << apple.getName() << endl
		<< "Price: " << apple.getPrice() << endl
		<< "Amount: " << apple.getAmount() << endl
		<< "Total price: " << apple.getTotalPrice() << endl;
	return 0;
}
