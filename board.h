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
		Board(Board target){
			for(size_t i=0; i<target.rows; i++){
				for(size_t j=0; j<target.columns; j++){
					arr[i][j]=target.arr[i][j];
				}
			}
		}
		Board(char* a){
			for(size_t i=0; i<r; i++){
				for(size_t j=0; j<c; j++){
					arr[i][j]=a[i][j];
				}
			}
		}
		ostream& operator<<(ostream &os) {
			for(size_t i=0; i<target.rows; i++){
				for(size_t j=0; j<target.columns; j++){
					os << target[i][j]<< "\t";
				}
				os<<"\n";
			}
    		return os;
		}
		void addPiece(char entry, size_t col);
		bool fullColumn(size_t col);
		bool boardFull();
		bool spaceEmpty();
		bool hasWinner();
};
/* Unnecessary bc of ostream
void printBoard(const Board target) const {
	for(size_t i=0; i<target.rows; i++){
		for(size_t j=0; j<target.columns; j++){
			cout<<target[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
*/


#endif
