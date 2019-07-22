#ifndef __BOARD_CPP__
#define __BOARD_CPP__

#include "board.h"

// constructors
// fills the 2D array with - and sets score to 0
Board::Board(){
	for(size_t i=0; i<rows; i++){
		for(size_t j=0; j<columns; j++){
			arr[i][j]='-';
		}
	}
	score=0;
}
/*
// deletes each column in the 2d array and the deletes the row array. sets score to 0./
Board::~Board(){
	for (size_t i = 0; i < rows; i++) {
        	delete[] arr[i];
    	}
	delete[] arr;
	score=0;
}
*/
// returns true if the board is full by seeing if there's an empty space anywhere on the board
bool Board::boardFull() const {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      if (arr[i][j] == '-') {
        return false;
      }
    }
  }
  return true;
}
// returns true if the board has a winner by checking 4 cases
bool Board::hasWinner() const{
  // check by column
	for(size_t i=0; i<rows-3; i++){
		for(size_t j=0; j<columns; j++){
		  if(arr[i][j]==arr[i+1][j]==arr[i+2][j]==arr[i+3][j]){
				return true;
			}
		}
	}
	// check by row
	for(size_t i=0; i<rows; i++){
		for(size_t j=0; j<columns-3; j++){
			if(arr[i][j]==arr[i][j+1]==arr[i][j+2]==arr[i][j+3]){
				return true;
			}
		}
	}
	// check up-right diagonals
	for(size_t i=3; i<rows; i++){
		for(size_t j=0; j<columns-3;j++){
			if(arr[i][j]==arr[i+1][j+1]==arr[i+2][j+2]==arr[i+3][j+3]){
				return true;
			}
		}
	}
	// check down-right diagonals
	for(size_t i=3; i<rows; i++){
		for(size_t j=3; j<columns;j++){
			if(arr[i][j]==arr[i-1][j-1]==arr[i-2][j-2]==arr[i-3][j-3]){
				return true;
			}
		}
	}
	return false;
}
// returns true if the space is empty by checking the char at the position of arr[r][c]
bool Board::spaceEmpty(size_t r, size_t c) const {
  return arr[r][c] == '-';
}
// returns true if the column is full by checking the char at each row of arr[i][c]
bool Board::fullColumn(size_t c) const {
  for(int i = 0; i < rows; i++) {
    if(arr[i][c] == '-') {
      return false;
    } 
  }
  return true;
}
// Precondition: the board column has a space to put the chip
// Postcondition: the chip is "dropped" in the board column and placed where the next available row is
void Board::addPiece(char entry, size_t col) {
  if(fullColumn(c)) { /* invalid message and reprompt */ return; }
  size_t i=6;
  while(!spaceEmpty(i, c)) {
    i--;
  }
  arr[i][c] = entry;
}
// prints the board
ostream& operator<<(ostream &os, const Board& source) {
	for(size_t i=0; i<source.rows; i++){
		for(size_t j=0; j<source.columns; j++){
			os << source.arr[i][j]<< " ";
		}	
		os<<"\n";
	}
    return os;
}

#endif
