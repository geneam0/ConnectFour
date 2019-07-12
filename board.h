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
		Board(){
			for(size_t i=0; i<rows; i++){
				for(size_t j=0; j<columns; j++){
					arr[i][j]="-";
				}
			}
		}
		char getUser() { return user; }
		char getComp() { return comp; }
		void addPiece(char entry, size_t col);
		bool boardFull();
		bool hasWinner();
		bool spaceEmpty();
		bool fullColumn(size_t col);
		ostream& operator<<(ostream &os) {
			for(size_t i=0; i<target.rows; i++){
				for(size_t j=0; j<target.columns; j++){
					os << target[i][j]<< "\t";
				}
				os<<"\n";
			}
    		return os;
		}
};

#endif
