#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;

class Board{
	private:
		static const size_t rows=7;
		static const size_t columns=6;
		static const char user = 'X';
		static const char comp = 'O';
		char arr[rows][columns];
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

		friend ostream& operator<<(ostream& os, const Board& source);
};

#endif
