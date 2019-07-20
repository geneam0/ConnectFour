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
  treeNode(treeNode *&source);

  // get data
  treeNode getChild(size_t i)                               { return children[i]; }
  treeNode getChildren()                                    { return children; }
  nodeDatatype getBoard()                                   { return possibleBoard; }
  treeNode* getParent()                                     { return parent; }
  

  // add/set data
  void addChild(treeNode* newChildPtr, size_t i);   
  void generateChildren(char turn); // given a node, what are the next possible moves
  void setBoard(nodeDatatype b)                             { possibleBoard = b; }
  void setParent(treeNode* p)                               { parent = p; }

  // overloaded operators
  treeNode operator=(treeNode source);

  // search algorithms
  Board DFS(const Board b, char turn);
  Board Minimax(const Board b); 

private: 
  nodeDatatype possibleBoard;   // data part of node ("parent" board)
  treeNode* parent;
  treeNode *children[7];        // link part of node (array of pointers) 
  Stack<Board> parentStack;
  Stack<Board> childrenStack;
  Queue<treeNode> gameTree;
  Stack<Board> winningPath;
};


// SEARCH ALGORITHMS
// returning node that contains board and can trace back to parent
treeNode BFS();
treeNode ID();

#endif
