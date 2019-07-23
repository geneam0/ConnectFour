#ifndef __TREENODE_H__
#define __TREENODE_H__

#include "board.h"
#include "Stack.h"
#include "Queue.h"
#include <math.h>       /* pow */

class treeNode {
  private: 
    Board possibleBoard;   // data part of node (board)
    treeNode* parent;
    treeNode** children;        // link part of node (array of pointers) 
 
  public:

    // constructors
    treeNode();
    treeNode(size_t col, char user);
    treeNode(Board bo);
  
    // get data
    treeNode* getChild(size_t i)                              { return children[i]; }
   //git treeNode* getChildren()                                    { return **children; }
    Board getBoard()                                          { return possibleBoard; }
    treeNode* getParent()                                     { return parent; }
  
    // add/set data
    void addChild(treeNode* newChildPtr, size_t i);   
    void generateChildren(char turn); // given a node, what are the next possible moves
    void setBoard(Board b)                                    { possibleBoard = b; }
    void setParent(treeNode* p)                               { parent = p; }

    // overloaded operators
    void operator=(treeNode source);

    // search algorithms
    void BFS(char turn);
    bool itdfs(char turn, treeNode* currentNode, Stack<treeNode*>& nodeStack,int level, int maxLevel);
    void IT(char turn);
};
void DFS(treeNode* b, char turn, Stack<treeNode>& childrenStack);
void generateScore(treeNode* b, size_t level, char turn);
void evaluateUp(treeNode* b, char turn);
void MiniMax(treeNode* b, size_t level, char turn);

#endif
