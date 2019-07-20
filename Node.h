#ifndef __NODE_H__
#define __NODE_H__

#include "board.h"
#include "Stack.h"
#include "PriorityQueue.h"

class treeNode {
public:
  typedef Board nodeDatatype;
  treeNode();
  treeNode(nodeDatatype *&source);
  treeNode(size_t col,Board posBoard, treeNode* initLink)   { possibleBoard = posBoard; link = initLink; }

  treeNode getChild(size_t i); // get ith child
  treeNode getChildren(); //get all children

  void addChild(treeNode* newChildPtr, size_t i);
  void generateChildren(char turn); // given a node, what are the next possible moves

  nodeDatatype getData() { return possibleBoard; }

  void setData(nodeDatatype b) { possibleBoard = b; }

  treeNode operator=(treeNode source);
  Board DFS(const Board b);
  Board Minimax(const Board b); 

private: 
  size_t column; // still needed or no ?
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
