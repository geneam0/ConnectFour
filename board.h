#ifndef __BOARD_H__
#define __BOARD_H__

#include <cstdlib>
#include <iostream>
using std::cout;
using std::ostream;


class Board{
	private:
		static const size_t rows=6;
		static const size_t columns=7;
		static const char user = 'O';
		static const char comp = 'X';
		char arr[rows][columns];
		int score;
	public:
		// constructors
		Board();
		// get and set functions
		char getRows() const { return rows; }
		char getCols() const { return columns; }
		char getUser() const { return user; }
		char getComp() const { return comp; }
		char getPiece(size_t r, size_t c) const { return arr[r][c]; }
		int getScore() const { return score; }
		void setPiece(size_t r, size_t c, char piece) { arr[r][c]=piece; }
		void setScore(int targetScore) { score=targetScore; }
		// other helpful functions 
		bool boardFull() const; // returns true if the board is completed
		bool hasWinner() const; // returns true if there's a winner by checking by column, row, and diagonal
		bool spaceEmpty(size_t r, size_t c) const; // same as getPiece(r,c)=='-'
		bool fullColumn(size_t c) const; // returns true a chip can't be placed in a column as it is full
		void addPiece(char entry, size_t c); // adds the piece in a column at the next available row
		// for printing the board
		friend ostream& operator<<(ostream& os, const Board& source); 
};

#include "board.cpp"
#endif
