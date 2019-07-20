#ifndef __NODE_CPP__
#define __NODE_CPP__

#include "Node.h"

// CONSTRUCTORS 

// default constructor ->>> ??? what else for this
treeNode::treeNode() {
  setParent = NULL;
  new *Children[7];
}

// root treeNode constructor
treeNode::treeNode(size_t col) {        // initial user input board 
    Board root;
    root.addPiece(i, user);
    possibleBoard = root;
    setParent = NULL;
    new *Children[7];
    
}

// do we need a copy constructor since we're using assignment operator?
treeNode::treeNode(treeNode *&source) {} 


// ADD/SET DATA

// addChild: fills designated slot in children array with pointer to new child
// preconditions: pointer to new child and the column in which the new piece was added
void treeNode::addChild(treeNode* newChildPtr, size_t i) {
  children[i] = newChildPtr;
}


/* generateChildren function:
- preconditions: have a turn (user or comp) and an empty children array (the children is a list of pointers pointing from the parent to its 7 children)
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
      addChild(nullptr, i);         // later, when reading children, check whether its null pointer first because youll get an error accessing a null ptr
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

// SEARCH ALGORITHMS

Board Node::DFS(const Board b, char turn){
  // Base Case: returns the winning board or tied board if no other solution possible
  if(b.hasWinner()||(b.boardFull()&&childrenStack.empty())) return b;
  /*
   * If the board isn't full, DFS will push in the child nodes into the childrenStack and the parent nodes into the 
   * parentStack. Then it will perform DFS on the most leftest child node. If the board is full, it will use the 
   * childrenStack to find the next node to perform DFS on.
   */
  else if(!b.boardFull()){
    parentStack.push(b);
    //!!!! IMPLEMENT GENERATE CHILDREN
    b.generateChildren(turn)
    for(size_t i=0; i<7;i++){
     childrenStack.push(b->getChild(i));
    }
  } 
  Board onTop=childrenStack.top();
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
  if(turn == user) {
    char first = user;
    char second = comp;
  } else {
    char first = comp;
    char second = user;
  treeNode currentNode;
  currentNode // SET CURRENTNODE TO THE NODE THAT IS CALLING THIS FUNCTION (necessary for simpler while loop)
  while(!getBoard().hasWinner()) {
    currentNode.generateChildren(first);
    for(int i = 0; i < 7; i++) {
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
      gameTree.push(children[i]);
      if(children[i]->getBoard().hasWinner()) {
        
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
  
  
}

#endif
