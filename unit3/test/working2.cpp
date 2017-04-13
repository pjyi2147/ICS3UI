/*
*  03/04/17
*  ICS3UI
*  Unit test 3 #2
*  Jeongseop Yi
*  Master Damian
*/

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;


struct maze {
	char map[12][12];
	int dir = 0;				// 0 right, 1 down, 2 left, 3 up (modulo) ;; counterclockwise
};

void printMap(maze);

bool isExit(int x, int y) {
	if (x == 11 || y == 11 || y == 0) {
		return 1;
	}
	else return 0;
}


bool frontBlocked(int x, int y, maze maze) {
	if (x < 0 || y < 0) {
		return 1;
	}
	if (maze.dir % 4 == 0) {				// going to the right
		if (maze.map[y][x+1] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (maze.dir % 4 == 1) {			// going to the downward
		if (maze.map[y+1][x] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (maze.dir % 4 == 2) {			// going to the left
		if (maze.map[y][x-1] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {									// going to upward
		if (maze.map[y-1][x] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
}

bool rightBlocked(int x, int y, maze maze) {
	maze.dir += 1;							// does not affect original, turn right
	if (x < 0 || y < 0) {
		return 1;
	}
	if (maze.dir % 4 == 0) {				// going to the right
		if (maze.map[y][x + 1] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (maze.dir % 4 == 1) {			// going to the downward
		if (maze.map[y + 1][x] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (maze.dir % 4 == 2) {			// going to the left
		if (maze.map[y][x - 1] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {									// going to upward
		if (maze.map[y - 1][x] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
}

bool leftBlocked(int x, int y, maze maze) {
	maze.dir += 3;							// does not affect original, turn left
	if (x < 0 || y < 0) {
		return 1;
	}
	if (maze.dir % 4 == 0) {				// going to the right
		if (maze.map[y][x + 1] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (maze.dir % 4 == 1) {			// going to the downward
		if (maze.map[y + 1][x] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (maze.dir % 4 == 2) {			// going to the left
		if (maze.map[y][x - 1] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {									// going to upward
		if (maze.map[y - 1][x] == '#') {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void proceed(maze &maze, int &x, int &y) {
	if (maze.dir % 4 == 0) {				// goint to the right
		x += 1;
		maze.map[y][x-1] = '.';				// reset
		maze.map[y][x] = 'x';
	}
	else if (maze.dir % 4 == 1) {			// going to the downward
		y += 1;
		maze.map[y-1][x] = '.';				// reset
		maze.map[y][x] = 'x';
	}
	else if (maze.dir % 4 == 2) {			// going to the left
		x -= 1;
		maze.map[y][x+1] = '.';				// reset
		maze.map[y][x] = 'x';
	}
	else if (maze.dir % 4 == 3) {									// going to upward
		y -= 1;
		maze.map[y+1][x] = '.';				// reset
		maze.map[y][x] = 'x';
	}
}

void mazeTraverse(maze &maze, int &x, int &y, int*z, int*z1) {
	maze.map[y][x] = 'x';
	printMap(maze);
	// while the coordinate is not exit
	while (!isExit(x, y)) {
		// exception for starting point
		if (x == 0 && y == 1) {
			if (frontBlocked(x, y, maze)) {
				//printMap(maze);
				break;
			}
			else {
				proceed(maze, x, y);
				printMap(maze);
			}
		}
		else {
			// if right wall is blocked
			if (rightBlocked(x, y, maze)) {
				// check the front wall blocked
				if (frontBlocked(x, y, maze)) {
					// check the left wall blocked
					if (leftBlocked(x, y, maze)) {
						// go backwards
						maze.dir += 2;
						proceed(maze, x, y);
						printMap(maze);
					}
					// go left
					else {
						maze.dir += 3;
						proceed(maze, x, y);
						printMap(maze);
					}
				}
				// not blocked, proceed
				else {
					proceed(maze, x, y);
					printMap(maze);
				}
			}
			// if not, turn right and proceed.
			else {
				maze.dir += 1;
				proceed(maze, x, y);
				printMap(maze);
			}
		}
	}
	if (isExit(x,y)) {
		cout << "we found the exit" << endl;
	}
	else {
		cout << "This maze is not connected to exit" << endl;
	}
}

void mazeGenerator(maze &maze) {
	srand(time(NULL));
	for (int i = 0; i < 12; i++) {                  // row
		for (int j = 0; j < 12; j++) {              // column
			if (i == 0 || i == 11) {
				maze.map[i][j] = '#';
			}
			else if (j == 0 || j == 11) {
				maze.map[i][j] = '#';
			}
			else {
				if (rand() % 4) {                       // to have some more dots than hashtag
					maze.map[i][j] = '.';
				}
				else {									// walls
					maze.map[i][j] = '#';
				}
			}
		}
	}
	maze.map[1][0] = '.';
	maze.map[10][11] = '.';
}

void printMap(maze maze) {
	for (int i = 0; i < 12; i++) {                  // row
		for (int j = 0; j < 12; j++) {              // column
			cout << maze.map[i][j];
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}

int main() {
	maze maze;
	cout << "This program generates a random maze and follows the path using right hand rule" << endl << endl;
    mazeGenerator(maze);
    //maze.map[12][12] = {
	cout << "The initial maze: " << endl << endl;
	printMap(maze);
	int x = 0;
	int y = 1;
	int*x1 = &x;
	int*y1 = &y;
	cout << "Searching route from (0,1)" << endl << endl;
	mazeTraverse(maze, x, y, x1, y1);
	return 0;
}
