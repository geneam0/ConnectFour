#ifndef __NODE_H__
#define __NODE_H__

#include "board.cpp"

class Node {
private: 
  size_t column;
  size_t cost;
  Board possibleBoard;
  
public:
  void CostDFS();
  void CostBFS();  

};
