#ifndef BOARD_CPP
#define BOARD_CPP

#include "board.h"



bool Board::fullColumn(size_t col) {
  for(int i = 0; i < rows; i++) {
    if(arr[i][col] == "-") {
      return false;
    } 
  }
  return true;
}

bool Board::boardFull() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      if (ar[i][j] == "-") {
        return false;
      }
    }
  }
  return true;
}

bool Board::spaceEmpty(size_t row, size_t col) {
  if(arr[row][col] == "-") {
     return false;
  } else {
    return true;
  }    
}

void Board::addPiece(char entry, size_t col) {
  if(fullColumn) { /* invalid message and reprompt */ return; }
  if(boardFull) { return; }
  while(!spaceEmpty(i, col)) {
    i++;
  }
  arr[i][col] = entry;
}

bool Board::hasWinner(){
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
#endif
