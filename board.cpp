#ifndef BOARD_CPP
#define BOARD_CPP

#include "board.h"

Board::Board(){
	for(size_t i=0; i<rows; i++){
		for(size_t j=0; j<columns; j++){
			arr[i][j]='-';
		}
	}
	score=0;
}

Board::~Board(){
	for (size_t i = 0; i < rows; i++) {
        	delete[] arr[i];
    	}
	delete[] arr;
	score=0;
}

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
			if(arr[i][j]==arr[i][j+1]==arr[i+2][j+2]==arr[i][j+3]){
				return true;
			}
		}
	}
	// check diagonals
	for(size_t i=0; i<rows-3; i++){
		for(size_t j=0; j<columns-3;j++){
			if(arr[i][j]==arr[i+1][j+1]==arr[i+2][j+2]==arr[i+3][j+3]){
				return true;
			}
		}
	}
	return false;
}

bool Board::spaceEmpty(size_t row, size_t col) const {
  return arr[row][col] == '-';
}

bool Board::fullColumn(size_t col) const {
  for(int i = 0; i < rows; i++) {
    if(arr[i][col] == '-') {
      return false;
    } 
  }
  return true;
}

void Board::addPiece(char entry, size_t col) {
  if(fullColumn(col)) { /* invalid message and reprompt */ return; }
  if(boardFull()) { return; }
  size_t i=0;
  while(!spaceEmpty(i, col)) {
    i++;
  }
  arr[i][col] = entry;
}

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
