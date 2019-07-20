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
  treeNode(Board posBoard, treeNode* initLink)   { possibleBoard = posBoard; link = initLink; }

  // get data
  treeNode getChild(size_t i)                               { return children[i]; }
  treeNode getChildren();                                   { return children; }
  nodeDatatype getBoard()                                   { return possibleBoard; }

  // add/set data
  void addChild(treeNode* newChildPtr, size_t i);   
  void generateChildren(char turn); // given a node, what are the next possible moves
  void setBoard(nodeDatatype b)                             { possibleBoard = b; }

  // overloaded operators
  treeNode operator=(treeNode source);

  // search algorithms
  Board DFS(const Board b, char turn);
  Board Minimax(const Board b); 

private: 
  nodeDatatype possibleBoard;   // data part of node ("parent" board)
  treeNode* parent;
  treeNode *children[8];        // link part of node (array of pointers) [8 slots because: 7 children and last slot will be a pointer to the parent treeNode]
  Stack<Board> parentStack;
  Stack<Board> childrenStack;
  Queue<treeNode> gameTree;
};


// SEARCH ALGORITHMS
// returning node that contains board and can trace back to parent
treeNode BFS();
treeNode ID();

#endif
