#ifndef __TREENODE_CPP__
#define __TREENODE_CPP__

#include "treeNode.h"

// CONSTRUCTORS 

// default constructor ->>> ??? what else for this
treeNode::treeNode() {
  setParent(NULL);
  new *children[7];
}

// root treeNode constructor
treeNode::treeNode(size_t col, char user) {        // initial user input board 
    Board root;
    root.addPiece(col, user);
    possibleBoard = root;
    setParent(NULL);
    new *children[7]; 
}

treeNode::treeNode(Board bo){
	for(size_t i=0; i<bo.getRows(); i++){
		for(size_t j=0; i<bo.getCols(); j++){
			possibleBoard.setPiece(i,j,bo.getPiece(i,j));
		}
	}
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
- when you call parent.generateChildren it will fill the array of pointers connected to each Node with pointers to all these children 
- However, if the column is full, that slot in the list will point to NULL
- postconditions: have the list of pointers (children array) pointing to 7 children with full columns pointing to NULL */
void treeNode::generateChildren(char turn) {
  for(int i = 0; i < 7; i++) {
    treeNode* childPtr;
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
void DFS(treeNode* b, char turn, Stack<treeNode>& childrenStack){
  // Base Case: returns the winning board or tied board if no other solution possible
  if(b->getBoard().hasWinner()||(b->getBoard().boardFull()&&childrenStack.empty())){ // onlytime you want to print is if board has winner or if full, childrenstack empty isnt necessary
    cout<<b->getBoard();
    while(b->getParent()!=NULL){
      cout<<b->getParent()->getBoard();
      b=b->getParent();
	// return statement here maybeeeee
    }
  }
  /*
   * If the board isn't full, DFS will push in the child nodes into the childrenStack.
   * Then it will perform DFS on the most leftest child node. If the board is full, it will use the 
   * childrenStack to find the next node to perform DFS on.
   */
  else if(!b->getBoard().boardFull()){
    b->generateChildren(turn);
    for(size_t i=6; i>=0;i--){
      if(b->getChild(i) == NULL) { continue; }
      else { childrenStack.push(b->getChild(i)); }
    }
  } 
  treeNode onTop=childrenStack.top();
  childrenStack.pop();
  if(turn=='X') turn='O';
  else turn='X';
  DFS(onTop,turn,childrenStack);
}

// computerTurn = 'X; userTurn = 'O'
void generateScore(treeNode* b, size_t level, char turn){
  // initalize the board and score
  Board in=b->getBoard();
  int score=0; level++; size_t consecutive=0; int tempScore=0;
  // adds score based on how many consecutives each board has
	for(size_t i=0; i<3; i++){
		for(size_t j=0; j<7; j++){
		  if(turn==in.getPiece(i,j)==in.getPiece(i+1,j)==in.getPiece(i+2,j)==in.getPiece(i+3,j)){ consecutive=4; }
      else if (turn==in.getPiece(i,j)==in.getPiece(i+1,j)==in.getPiece(i+2,j)){ consecutive=3; }
      else if (turn==in.getPiece(i,j)){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
	for(size_t i=0; i<3; i++){
		for(size_t j=0; j<4; j++){
			if(turn==in.getPiece(i,j)==in.getPiece(i,j+1)==in.getPiece(i,j+2)==in.getPiece(i,j+3)){ consecutive=4; }
      else if (turn==in.getPiece(i,j)==in.getPiece(i,j+1)==in.getPiece(i,j+2)){ consecutive=3; }
      else if (turn==in.getPiece(i,j)==in.getPiece(i,j+1)){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
	for(size_t i=3; i<6; i++){
		for(size_t j=0; j<4;j++){
      if(turn==in.getPiece(i,j)==in.getPiece(i+1,j+1)==in.getPiece(i+2,j+2)==in.getPiece(i+3,j+3)){ consecutive=4; }
      else if (turn==in.getPiece(i,j)==in.getPiece(i+1,j+1)==in.getPiece(i+2,j+2)){ consecutive=3; }
      else if (turn==in.getPiece(i,j)==in.getPiece(i+1,j+1)){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
	for(size_t i=3; i<6; i++){
		for(size_t j=3; j<7;j++){
			if(turn==in.getPiece(i,j)==in.getPiece(i-1,j-1)==in.getPiece(i-2,j-2)==in.getPiece(i-3,j-3)){ consecutive=4; }
    		  else if (turn==in.getPiece(i,j)==in.getPiece(i-1,j-1)==in.getPiece(i-2,j-2)){ consecutive=3; }
      else if (turn==in.getPiece(i,j)==in.getPiece(i-1,j-1)){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
  in.setScore(score);
}

void evaluateUp(treeNode* b, char turn){
	// while your current subtree isn't the root, you compare yourself to your siblings and based on the turn, you minimize or maximize
	while(b->getParent()!= NULL){
		b=b->getParent(); 
		if(b->getChild(0)!=NULL && b->getChild(1)!=NULL && b->getChild(2)!=NULL && b->getChild(3)!=NULL
			 && b->getChild(4)!=NULL && b->getChild(5)!=NULL && b->getChild(6)!=NULL){
			int minMax; 
			if(turn=='O') { minMax=100000000; }	
			else { minMax=-100000000; }
			for(size_t i=0; i<7; i++){
				int temp=b->getChild(i)->getBoard()->getScore();
				// if the current turn is the user, you try to minimize
				if(turn=='O' && temp<minMax){ minMax=temp; } 
				// otherwise, you're maximizing
				else if (temp>minMax) { minMax=temp; }
			}
			b->setScore(minMax);
		}
		// if one of your sibling is NULL, you return the function and wait until it gets a score
		else { return; }
	}
	// for printing the possible board combinations out
	while(b->getChildren()!=NULL){
		for(size_t i=0; i<7;i++){
    	if(b->getChild(i)==NULL) { continue; }
			else if(b->getChild(i)==minMax){
				b=b->getChild(i);
				cout<<b->getBoard();
			}
		}
	}
}

/*
 * Precondition: A root containing board b that can still be filled
 * Postcondition: A tree from that board b with 4 levels of possible board choices. Each node has 7 children.
 * 		When the program finishes, each leaf score is calculated with generateScore. At the end,  
 *		evaluateUp takes each leaf score and "miniMaxes" it upward.
 */
void MiniMax(const treeNode* b, size_t level, char turn){
  // If the node is null, we generate the score for the parent and stop generating null children
  if(*b==NULL){
    if(turn=='O') turn='X';
    else turn='O';
    level++;
    generateScore(b->getParent(),level, turn);
    return;
  }
  if(level==0){
    evaluateUp(*b, turn); 
    return;
  }
  // Otherwise, the MiniMax function continues to generate child nodes
  b->generateChildren(turn);
  for(size_t i=0; i<7;i++){
    if(b->getChild(i)==NULL) { continue; }
    if(turn=='O') { turn='X'; }
    else { turn='O'; }
    // for each level, the minimax function will recursively call upon itself to create more children nodes
    if(level>1) {   level--; MiniMax(b->getChild(i),level,turn); }
    // if level is 1, we have to generate child nodes and also their score
    else { level--; generateScore(b->getChild(i),level,turn); }
  }
}

// meriselle search algorithms 
void treeNode::BFS(char turn) {
  bool isWinner = false;
  char thisTurn;
  if (turn == 'O') {
	  thisTurn == 'X';
  } else { thisTurn == 'O'; }
  Queue<treeNode*> gameTree;
  Stack<Board> winningPath;
  gameTree.push(this);			// queue is a queue of pointers, not boards sooo push this pointer 
  treeNode* currentNode;
  while(!gameTree.empty()) {	
	if(thisTurn == 'O') {
		thisTurn = 'X';
	} else {
		thisTurn = 'O';
	currentNode = gameTree.front();
	gameTree.pop();
	currentNode->generateChildren(thisTurn);
	for(int i = 0; i < 7; i++) {
		if(currentNode->getChild(i) == nullptr) { continue; }
		gameTree.push(currentNode->getChild(i));
		if(currentNode->getChild(i).getBoard().hasWinner()) {
			winningPath.push(currentNode->getChild(i).getBoard());
			isWinner = true;
			break;
		}
	}
	if(isWinner) { break; }
  }
  treeNode winner = winningPath.top();
  cout << "Winning Board: " << winner.getBoard();		// PRINT BOARD FUNCTION OR COUT OVERLOADED
  treeNode *rootParent;
  rootParent = winner.getParent();
  while(rootParent != NULL) {
    winningPath.push(rootParent->getBoard());
    rootParent = rootParent->getParent();
  }
  while(!winningPath.empty()) {
    Board path = winningPath.top();
    cout << "->" << path;
    winningPath.pop();    
} 
  
bool treeNode::itdfs(char turn, treeNode* currentNode, Stack<treeNode*>& nodeStack,int level, int maxLevel) { // USER PART
	if(currentNode->getBoard().boardFull() || currentNode->getBoard().hasWinner()) {
		//print boards
		return true;
	}
	
	nodeStack.push(currentNode);
	
	if(level < maxLevel) {
		for (int i = 0; i < 7; i++) {
			if ( currentNode->getChild(i) != nullptr) {
				if(itdfs(turn, currentNode->getChild(i), nodeStack, level + 1; maxLevel)) {
					return true;
				}
			}
		}
	}
	nodeStack.pop();
	return false;
}
	  
void treeNode::IT(char turn) { // USER PART
	treeNode* currentNode;
	currentNode = this;
	for(int = 0; i < 10; i++) {
		Stack<treeNode*> nodeStack;
		if(dfs(turn, currentNode, nodeStack, 0, i)) {
			break;
		}
	}
}
    
#endif
