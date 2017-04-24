// Lab 5.3.1 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
private:
	int id;
	int capacity;
	int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

void FlightBooking::printStatus() {
	cout << "Flight " << this->id << ": " << this->reserved << "/" << this->capacity << " ("
		<< (double) this->reserved / (double) this->capacity * 100<< "%) seats taken" << endl;
}

int main() {
	int reserved = 0;
	int capacity = 0;

	cout << "Provide flight capacity: ";
	cin >> capacity;

	cout << "Provide number of reserved seats: ";
	cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	booking.printStatus();
	return 0;
}
