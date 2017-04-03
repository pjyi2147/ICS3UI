// Lab 3.10.2 by Jeongseop Yi
// Lab 3.10.2 by Jeongseop Yi
#include <iostream>
#include <random>
#include <ctime> 
using namespace std;

struct Collection {
	int elno;
	int *elements;
};

void AddToCollection(Collection &col, int element) {
	if (col.elno) {
		int *arr;
		arr = new int[col.elno + 1];
		// copy old data
		for (int i = 0; i < col.elno; i++) {
			arr[i] = col.elements[i];
		}
		// delete old data
		delete[] col.elements;
		// assign new one
		col.elements = arr;
	}
	else {						// when there is not a element
		col.elements = new int[1];
	}
	col.elements[col.elno++] = element;
}

void PrintCollection(Collection col) {
	cout << "[ ";
	for (int i = 0; i < col.elno; i++) {
		cout << col.elements[i] << " ";
	}
	cout << "]" << endl;
}

int main() {
	Collection collection = { 0, NULL };

	int elems;
	cout << "How many elements? ";
	cin >> elems;
	srand(time(NULL));
	/*
	static random_device rd;
	static mt19937_64 rng(rd());
	uniform_int_distribution<int> uni(1, 1000);
	*/
	for (int i = 0; i < elems; i++) {
		AddToCollection(collection, rand() % 1000 + 1);
	}
	PrintCollection(collection);
	delete[] collection.elements;
	return 0;
}
