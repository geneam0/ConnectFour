#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std::cout;

class Board{
	private:
		size_t rows=7;
		size_t columns=6;
		char arr[rows][columns];
		char user = "X";
		char comp = "O";
	public:
		// constructors
		Board();
		char getUser() { return user; }
		char getComp() { return comp; }
		bool boardFull();
		bool hasWinner();
		bool spaceEmpty();
		bool fullColumn(size_t col);
		void addPiece(char entry, size_t col);
};
friend ostream& operator<<(ostream &os);

#endif
