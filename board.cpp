#ifndef __BOARD_CPP__
#define __BOARD_CPP__

#include "board.h"



bool Board::fullColumn(size_t column) {
  for(int i = 0; i < rows; i++) {
    if(arr[i][column] == "-") {
      return false;
    } else {
      return true;
    }
}

bool Board::boardFull() {
}

bool Board::spaceEmpty() {
}

void Board::addPiece(char entry, size_t column) {
 
}
