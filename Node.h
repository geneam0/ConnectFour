#ifndef __NODE_H__
#define __NODE_H__

#include "board.h"
#include "Stack.h"
#include "PriorityQueue.h"

class treeNode {
public:
  typedef Board nodeDatatype;
  treeNode(size_t col,Board posBoard, treeNode* initLink)   { possibleBoard = posBoard; link = initLink; }

  treeNode getChild(); // get ith child
  treeNode getChild(); //get all children

  void setChild(); // set ith child to a diff state
  void addChild();
  void generateChildren(); // given a node, what are the next possible moves
  Board DFS(const Board b);

private: 
  size_t column; // still needed or no ?
  nodeDatatype possibleBoard; // data 
  treeNode* parent;
  treeNode*& children;
  size_t numChildren;
  size_t capChildren;
  Stack<Board> parentStack;
  Stack<Board> childrenStack;
};


// SEARCH ALGORITHMS
// returning node that contains board and can trace back to parent
treeNode BFS();
treeNode ID();
treeNode Minimax(); 

#endif
