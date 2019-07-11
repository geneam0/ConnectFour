#ifndef _BOARD_H_
#define _BOARD_H_
#include <iostream>
using namespace std::cout;

class Board{
	private:
		size_t rows=7;
		size_t columns=6;
		char arr[rows][columns];
	public:
		Board(){
			for(size_t i=0; i<rows; i++){
				for(size_t j=0; j<target.columns; j++){
					arr[i][j]="-";
				}
			}
		}
	void printBoard(const Board target) const {
		for(size_t i=0; i<target.rows; i++){
			for(size_t j=0; j<target.columns; j++){
				cout<<target[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
};


#endif
