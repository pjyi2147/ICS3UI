// Lab 5.3.2 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservation(int number_ob_seats);
private:
	int id;
	int capacity;
	int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	if (reserved < (double)capacity * 1.05 && reserved >= 0) {
		this->reserved = reserved;
	}
	else if (reserved < 0) {
		this->reserved = 0;
	}
	else {
		this->reserved = 0;
		cout << "Cannot perform this operation." << endl;
	}
}

void FlightBooking::printStatus() {
	cout << "Flight " << this->id << ": " << this->reserved << "/" << this->capacity << " ("
		<< (double) this->reserved / (double) this->capacity * 100<< "%) seats taken" << endl;
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if (number_ob_seats + this->reserved < (double) this->capacity * 1.05) {
		this->reserved += number_ob_seats;
		return true;
	}
	else {
		cout << "Cannot perform this operation" << endl;
		return false;
	}
}

bool FlightBooking::cancelReservation(int number_ob_seats) {
	if (this->reserved - number_ob_seats < (double) this->capacity
		&& this->reserved - number_ob_seats >= 0) {
		this->reserved -= number_ob_seats;
		return true;
	}
	else {
		cout << "Cannot perform this operation" << endl;
		return false;
	}
}

int main() {
	int reserved = 0;
	int capacity = 0;

	cout << "Provide flight capacity: ";
	cin >> capacity;

	cout << "Provide number of reserved seats: ";
	cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	string command = "";
	int command1 = 0;
	while (command != "quit") {
		booking.printStatus();
		cout << "What would you like to do?: ";
		cin >> command;

		if (command == "add") {
			cin >> command1;
			booking.reserveSeats(command1);
		}
		else if (command == "cancel") {
			cin >> command1;
			booking.cancelReservation(command1);
		}
		else if (command == "quit") {
			break;
		}
		else {
			cout << "Cannot perform this operation" << endl;
		}
	}
	return 0;
}
