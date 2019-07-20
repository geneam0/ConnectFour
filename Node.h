#ifndef __NODE_H__
#define __NODE_H__

#include "board.h"
#include "Stack.h"
#include "PriorityQueue.h"

class treeNode {
  private: 
    Board possibleBoard;   // data part of node (board)
    treeNode* parent;
    treeNode *children[7];        // link part of node (array of pointers) 
    Stack<Board> parentStack;
    Stack<Board> childrenStack;
    Queue<treeNode> gameTree;
    Stack<Board> winningPath;
  public:

    // constructors
    treeNode();
    treeNode(size_t col);
  
    // get data
    treeNode getChild(size_t i)                               { return children[i]; }
    treeNode getChildren()                                    { return children; }
    Board getBoard()                                          { return possibleBoard; }
    treeNode* getParent()                                     { return parent; }
  
    // add/set data
    void addChild(treeNode* newChildPtr, size_t i);   
    void generateChildren(char turn); // given a node, what are the next possible moves
    void setBoard(Board b)                                    { possibleBoard = b; }
    void setParent(treeNode* p)                               { parent = p; }

    // overloaded operators
    treeNode operator=(treeNode source);

    // search algorithms
    void DFS(const Board b, char turn);
    void Minimax(const Board b); 
    void BFS();
    void ID();
};

#endif
