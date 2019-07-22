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
	for(size_t i=0; i<bo.getRows(); i++){
		for(size_t j=0; i<bo.getCols(); j++){
			possibleBoard.setPiece(i,j,bo.getPiece(i,j));
		}
	}
  *parent = NULL;
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
void Node::DFS(const treeNode* b, char turn, Stack<treeNode>& childrenStack){
  // Base Case: returns the winning board or tied board if no other solution possible
  if(*b.possibleBoard.hasWinner()||(*b.possibleBoard.boardFull()&&childrenStack.empty())){ // onlytime you want to print is if board has winner or if full, childrenstack empty isnt necessary
    cout<<*b.possibleBoard;
    while(b->getParent()!=NULL){
      cout<<b->getParent().possibleBoard;
      b=b->getParent();
	// return statement here maybeeeee
    }
  }
  /*
   * If the board isn't full, DFS will push in the child nodes into the childrenStack.
   * Then it will perform DFS on the most leftest child node. If the board is full, it will use the 
   * childrenStack to find the next node to perform DFS on.
   */
  else if(!*b.possibleBoard.boardFull()){
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
  Board in=b.possibleBoard;
  int score=0; level++; size_t consecutive=0; int tempScore=0;
  // adds score based on how many consecutives each board has
	for(size_t i=0; i<rows-3; i++){
		for(size_t j=0; j<columns; j++){
		  if(turn==arr[i][j]==arr[i+1][j]==arr[i+2][j]==arr[i+3][j]){ consecutive=4; }
      else if (turn==arr[i][j]==arr[i+1][j]==arr[i+2][j]){ consecutive=3; }
      else if (turn==arr[i][j]==arr[i+1][j]){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
	for(size_t i=0; i<rows; i++){
		for(size_t j=0; j<columns-3; j++){
			if(turn==arr[i][j]==arr[i][j+1]==arr[i+2][j+2]==arr[i][j+3]){ consecutive=4; }
      else if (turn==arr[i][j]==arr[i][j+1]==arr[i+2][j+2]){ consecutive=3; }
      else if (turn==arr[i][j]==arr[i][j+1]){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
	for(size_t i=0; i<rows-3; i++){
		for(size_t j=0; j<columns-3;j++){
      if(turn==arr[i][j]==arr[i+1][j+1]==arr[i+2][j+2]==arr[i+3][j+3]){ consecutive=4; }
      else if (turn==arr[i][j]==arr[i+1][j+1]==arr[i+2][j+2]){ consecutive=3; }
      else if (turn==arr[i][j]==arr[i+1][j+1]){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
  // sets the board score based on whether the turn is from the computer or user
  if(turn=='O'){ score*-1; }
  in.setScore(score);
}

void evaluateUp(treeNode* b, char turn){
	while(b->getParent()!= NULL){
		b=b->getParent(); 
		if(b->getChild(0)!=NULL && b->getChild(1)!=NULL && b->getChild(2)!=NULL && b->getChild(3)!=NULL
			 && b->getChild(4)!=NULL && b->getChild(5)!=NULL && b->getChild(6)!=NULL){
			int minMax; 
			if(turn=='O') { minMax=100000000; }	
			else { minMax=-100000000; }
			for(size_t i=0; i<7; i++){
				int temp=b->getChild(i).possibleBoard->getScore();
				if(turn=='O' && temp<minMax){ minMax=temp; } 
				else if (temp>minMax) { minMax=temp; }
			}
			b->setScore(minMax);
		}
		else { return; }
	}
	while(b->getChildren()!=NULL){
		for(size_t i=0; i<7;i++){
    	if(b->getChild(i)==NULL) { continue; }
			if(b->getChild(i)==minMax){
				b=b->getChild(i);
				cout<<b;
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
  if (turn == user) {
	  thisTurn == comp;
  } else { thisTurn == user; }
  queue<treeNode *> gameTree;
  stack<Board> winningPath;
  gameTree.push(this);			// queue is a queue of pointers, not boards sooo push this pointer 
  treeNode* currentNode;
  while(!gameTree.empty()) {	
	if(thisTurn == user) {
		thisTurn = comp;
	} else {
		thisTurn = user;
	currentNode = gameTree.front();
	gameTree.pop();
	currentNode->generateChildren(thisTurn);
	for(int i = 0; i < 7; i++) {
		if(currentNode->getChild(i) == nullptr) { continue; }
		gameTree.push(currentNode->getChild(i));
		if(currentNode->getChild(i)->getBoard().hasWinner()) {
			winningPath.push(currentNode->getChild(i)->getBoard());
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
    winningPath.push(rootParent.getBoard());
    rootParent = rootParent->getParent();
  }
  while(!winningPath.empty()) {
    Board path = winningPath.top();
    cout << "->" << path;
    winningPath.pop();    
} 
  
bool treeNode::itdfs(char turn, treeNode* currentNode, Stack<TreeNode*>& nodeStack,int level, int maxLevel) {
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
	  
void treeNode::IT(char turn) {
	treeNode* currentNode;
	currentNode = this;
	for(int = 0; i < 10; i++) {
		Stack<treeNode*> nodeStack;
		dfs(turn, currentNode, nodeStack, 0, i);
	}
}
    
#endif
