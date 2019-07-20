#ifndef __NODE_H__
#define __NODE_H__

#include "board.h"
#include "Stack.h"
#include "PriorityQueue.h"

class treeNode {
public:
  typedef Board nodeDatatype;

  // constructors
  treeNode();
  treeNode(nodeDatatype *&source);
  treeNode(size_t col,Board posBoard, treeNode* initLink)   { possibleBoard = posBoard; link = initLink; }

  // get data
  treeNode getChild(size_t i); // get ith child
  treeNode getChildren(); //get all children
  nodeDatatype getBoard() { return possibleBoard; }

  // add/set data
  void addChild(treeNode* newChildPtr, size_t i);
  void generateChildren(char turn); // given a node, what are the next possible moves
  void setBoard(nodeDatatype b) { possibleBoard = b; }

  // overloaded operators
  treeNode operator=(treeNode source);

  // search algorithms
  Board DFS(const Board b);
  Board Minimax(const Board b); 

private: 
  nodeDatatype possibleBoard; // data 
  treeNode* parent;
  size_t numChildren;
  treeNode *children[7];
  size_t capChildren;
  Stack<Board> parentStack;
  Stack<Board> childrenStack;
  Queue<treeNode> gameTree;
};


// SEARCH ALGORITHMS
// returning node that contains board and can trace back to parent
treeNode BFS();
treeNode ID();

#endif
