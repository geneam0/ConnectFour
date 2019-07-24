#ifndef __TREENODE__H
#define __TREENODE__H

#include <cstdlib>
#include "board.h"
#include "Stack.h"
#include "Queue.h"
#include <math.h>       /* pow */

class treeNode {
  private: 
    Board possibleBoard;   // data part of node (board)
    treeNode* parent;
    treeNode* children[7];        // link part of node (array of pointers) 
 
  public:

    // constructors
    treeNode();
    treeNode(size_t col, char user);
    treeNode(Board bo);
  
    // get/set functions
    treeNode* getChild(int i)                              { return children[i]; }
    treeNode** getChildren()                                    { return children; }
    Board getBoard()                                          { return possibleBoard; }
    treeNode* getParent()                                     { return parent; }
    void setBoard(Board b)                                    { possibleBoard = b; }
    void setParent(treeNode* p)                               { parent = p; }
  
    // add functions
    void addChild(treeNode* newChildPtr, int i);   
    void generateChildren(char turn); // given a node, what are the next possible moves

    // overloaded operators
    void operator=(treeNode source);

    // search algorithms
    void BFS(char turn);
    bool itdfs(char turn, treeNode* currentNode, Stack<treeNode*>& nodeStack,int level, int maxLevel);
    void IT(char turn);
};
void DFS(treeNode*& b, char turn, Stack<treeNode*>& childrenStack);
void generateScore(treeNode* b, size_t level, char turn);
void evaluateUp(treeNode* b, char turn);
void MiniMax(treeNode* b, size_t level, char turn);


#endif
