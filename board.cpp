#ifndef __BOARD_CPP__
#define __BOARD_CPP__

#include "board.h"



bool Board::fullColumn(size_t column) {
  for(int i = 0; i < rows; i++) {
    if(arr[i][column] == "-") {
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

bool Board::spaceEmpty(size_t row, size_t column) {
  if(arr[row][column] == "-") {
     return false;
  } else {
    return true;
  }    
}

void Board::addPiece(char entry, size_t column) {
  if(fullColumn) { /* invalid message and reprompt */ return; }
  if(boardFull) { return; }
  while(!spaceEmpty(i, column)) {
    i++;
  }
  arr[i][column] = entry;
}
