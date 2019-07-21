#ifndef __NODE_CPP__
#define __NODE_CPP__

#include "Node.h"

// CONSTRUCTORS 

// default constructor ->>> ??? what else for this
treeNode::treeNode() {
  setParent(NULL);
  new *children[7];
}

// root treeNode constructor
treeNode::treeNode(size_t col, char user) {        // initial user input board 
    Board root;
    root.addPiece(i, user);
    possibleBoard = root;
    setParent(NULL);
    new *children[7]; 
}

treeNode::treeNode(Board bo){
  possibleBoard=bo;
  setParent(NULL);
  new *children[7];
}
// ADD/SET DATA
// addChild: fills designated slot in children array with pointer to new child
// preconditions: pointer to new child and the column in which the new piece was added
void treeNode::addChild(treeNode* newChildPtr, size_t i) {
  children[i] = newChildPtr;
}

/* generateChildren function:
- preconditions: have a turn (user or comp) and an empty children array (the children is a list of pointers pointing from the parent
  to its 7 children)
- generate children is a member function, so the only parameter it takes is which turn it is (user or comp)
- when you call parent.generateChildren it will fill the array of pointers connected to each Node with pointers to all these children 
- each child will have a new piece, however, if the column is full, that slot in the list will point to NULL
- postconditions: have the list of pointers (children array) pointing to 7 children with full columns pointing to NULL 
*/
void treeNode::generateChildren(char turn) {
  for(int i = 0; i < 7; i++) {
    treeNode *childPtr;
    childPtr = new treeNode;
    childPtr->setBoard(possibleBoard);
    if(!childPtr->getBoard().fullColumn(i)) {
      childPtr->getBoard().addPiece(turn, i);
      addChild(childPtr, i);
    } else {
      addChild(nullptr, i);         // later, when accessing children, check whether its null pointer first to avoid accessing error
    }
    childPtr->setParent(this);      // this is a special pointer function
  }
}

// OVERLOADED OPERATORS
treeNode operator=(treeNode source) {
  possibleBoard = source.possibleBoard;
  parent = source.parent;
  for(int i = 0; i < 7; i++) {
    children[i]  = source.chilren[i];
  }
  // copy over parentStack
  // copy over childrenStack
  // copy over gameTree
  // copy over winningPath
}

// Searching Algorithms
void Node::DFS(const treeNode* b, char turn){
  // Base Case: returns the winning board or tied board if no other solution possible
  if(b.possibleBoard.hasWinner()||(b.possibleBoard.boardFull()&&childrenStack.empty())){
    cout<<b.possibleBoard;
    while(b->getParent()!=NULL){
      cout<<b->getParent().possibleBoard;
      b=b->getParent();
    }
  }
  /*
   * If the board isn't full, DFS will push in the child nodes into the childrenStack and the parent nodes into the 
   * parentStack. Then it will perform DFS on the most leftest child node. If the board is full, it will use the 
   * childrenStack to find the next node to perform DFS on.
   */
  else if(!b.possibleBoard.boardFull()){
    parentStack.push(b);
    b->generateChildren(turn);
    for(size_t i=0; i<7;i++){
      if(children[i] == nullptr) { continue; }
      else { childrenStack.push(b->getChild(i)); }
    }
  } 
  treeNode onTop=childrenStack.top();
  childrenStack.pop();
  if(turn=='X') turn='O';
  else turn='X';
  DFS(onTop,turn);
}

Board treeNode::Minimax(const Board b, size_t level){
  if(level>4) return;
  
}

// meriselle search algorithms 
void treeNode::BFS(turn) {
  char first, second;
  if(turn == user) {
    first = user;
    second = comp;
  } else {
    first = comp;
    second = user;
  treeNode currentNode;
  currentNode // SET CURRENTNODE TO THE NODE THAT IS CALLING THIS FUNCTION (necessary for simpler while loop)
  while(!getBoard().hasWinner()) {
    currentNode.generateChildren(first);
    for(int i = 0; i < 7; i++) {
      if(children[i] == nullptr) { continue; }
      gameTree.push(children[i]);
      if(children[i]->getBoard().hasWinner()) {
        winningPath.push(children[i]->getBoard());
        break;
      }
    }
    treeNode next = gameTree.front();
    gameTree.pop();
    next.generateChildren(second);
    for(int i = 0; i < 7; i++) {
      if(children[i] == nullptr) { continue; }
      gameTree.push(children[i]);
      if(children[i]->getBoard().hasWinner()) {
        winningPath.push(children[i]->getBoard());
        break;
      }
    }
    next.BFS(first);
  }
  treeNode winner = winningPath.top();
  cout << "Winning Board: " << winner.getBoard();
  treeNode *rootParent;
  rootParent = winner.getParent();
  while(rootParent != NULL) {
    winningPath.push(rootParent.Board);
    rootParent = rootParent->getParent();
  }
  while(!winningPath.empty()) {
    Board path = winningPath.top();
    cout << "->" << path;
    winningPath.pop();    
}
  
void IT(turn) {
    char first, second;
  if(turn == user) {
    first = user;
    second = comp;
  } else {
    first = comp;
    second = user;
  } 
  treeNode currentNode;
  currentNode // SET CURRENTNODE TO THE NODE THAT IS CALLING THIS FUNCTION (necessary for simpler while loop)
  currentNode.generateChildren();
  // add while loop here, just not right now for testing purposes
  
 /*  for(int i = 0; i < 7; i++) {
    if(children[i] == nullptr) { continue; } 
    else if(children[i]->getBoard().hasWinner()) {
      break;
    }
    gameTree.push(children[i]->getBoard());
  } 
  */  
}
    
#endif
