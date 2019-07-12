#ifndef __BOARD_CPP__
#define __BOARD_CPP__

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
