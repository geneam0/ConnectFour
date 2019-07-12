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
		void addPiece(char entry, size_t column);
		bool fullColumn(size_t column);
		bool boardFull();
		bool spaceEmpty();
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
