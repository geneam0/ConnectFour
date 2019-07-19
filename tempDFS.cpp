#include "Board.h"
#include "Node.h"
#include "Stack.h"

//child stack
// Inorder depth-first search 
private: 
Stack<Board> parentStack;
Stack<Board> childrenStack;

void generateChildren(const Board b){
  
}

Board DFS(const Board b){
  // Base Case: returns the winning board or tied board if no other solution possible
  if(b.hasWinner()||(b.boardFull()&&childrenStack.empty())) return b;
  /*
   * If the board isn't full, DFS will push in the child nodes into the childrenStack and the parent nodes into the 
   * parentStack. Then it will perform DFS on the most leftest child node. If the board is full, it will use the 
   * childrenStack to find the next node to perform DFS on.
   */
  else if(!b.boardFull()){
    parentStack.push(b);
    childrenStack.push(generateChildren(b));
  } 
  Board onTop=childrenStack.top();
  childrenStack.pop();
  DFS(onTop);
}
