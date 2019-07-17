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
		char getUser() const { return user; }
		char getComp() const { return comp; }
		bool boardFull() const;
		bool hasWinner() const;
		bool spaceEmpty(size_t row, size_t col) const;
		bool fullColumn(size_t col) const;
		void addPiece(char entry, size_t col);
};
friend ostream& operator<<(ostream &os);

#endif
