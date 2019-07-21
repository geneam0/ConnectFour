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
		int score;
	public:
		// constructors
		Board();
		~Board();
		char getUser() const { return user; }
		char getComp() const { return comp; }
		char getPiece(size_t r, size_t c) { return arr[r][c]; }
		int getScore() const { return score; }
		void setScore(int targetScore) { score=targetScore; }
		bool boardFull() const;
		bool hasWinner() const;
		bool spaceEmpty(size_t row, size_t col) const;
		bool fullColumn(size_t col) const;
		void addPiece(char entry, size_t col);
};
friend ostream& operator<<(ostream &os);

#endif
