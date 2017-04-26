// Lab 5.3.3 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking();
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservation(int number_ob_seats);
	int getId() { return id; };
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

FlightBooking::FlightBooking()
{
	this->id = 0;
	this->capacity = 0;
	this->reserved = 0;
}

void FlightBooking::printStatus() {
	cout << "Flight " << this->id << ": " << this->reserved << "/" << this->capacity << " ("
		<< (double) this->reserved / (double) this->capacity * 100 << "%) seats taken" << endl;
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
	FlightBooking bookingList[10];
	string command = "";
	int command1 = 0;
	int nBooking = 0;
	while (command != "quit") {
		cout << "What would you like to do?: ";
		cin >> command;
		if (nBooking == 0) {
			cout << "No flights in the system" << endl;
		}

		if (command == "create") {
			int id, cap;
			cin >> id >> cap;
			FlightBooking k(id, cap, 0);
			bookingList[nBooking] = k;
			bookingList[nBooking].printStatus();
			nBooking += 1;
		}

		else if (command == "delete") {
			int id;
			cin >> id;
			FlightBooking booking;
			bool found = false;
			for (int i = 0; i < nBooking; i++) {
				if (bookingList[i].getId() == id) {
					found = true;
					bookingList[i] = booking;
					break;
				}
			}
			if (!found) {
				cout << "Cannot perform this operation: flight " << id << " not found." << endl;
			}
		}
		else if (command == "add") {
			int id;
			cin >> id >> command1;
			bool found = false;
			for (int i = 0; i < nBooking; i++) {
				if (bookingList[i].getId() == id) {
					found = true;
					bookingList[i].reserveSeats(command1);
					bookingList[i].printStatus();
					break;
				}
			}
			if (!found) {
				cout << "Cannot perform this operation: flight " << id << " not found." << endl;
			}
		}

		else if (command == "cancel") {
			int id;
			bool found = false;
			cin >> id >> command1;
			for (int i = 0; i < nBooking; i++) {
				if (bookingList[i].getId() == id) {
					found = true;
					bookingList[i].cancelReservation(command1);
					bookingList[i].printStatus();
					break;
				}
			}
			if (!found) {
				cout << "Cannot perform this operation: flight " << id << " not found." << endl;
			}
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
