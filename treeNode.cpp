#ifndef __TREENODE__CPP
#define __TREENODE__CPP

#include "treeNode.h"

// CONSTRUCTORS 
treeNode::treeNode() {
  setParent(NULL);
  for(int i = 0; i < 7; i++) {
    children[i] = NULL;
  }
}
treeNode::treeNode(size_t col, char user) {        
  Board root;
  root.addPiece(col, user);
  possibleBoard = root;
  setParent(NULL);
  for(int i = 0; i < 7; i++) {
    children[i] = NULL;
  }
}
treeNode::treeNode(Board bo){
	for(size_t i=0; i<bo.getRows(); i++){
		for(size_t j=0; i<bo.getCols(); j++){
			possibleBoard.setPiece(i,j,bo.getPiece(i,j));
		}
	}
  setParent(NULL);
  for(int i = 0; i < 7; i++) {
    children[i] = NULL;
  }
}

// ADD/SET DATA
/* addChild: fills designated slot in children array with pointer to new child
  preconditions: pointer to new child and the column in which the new piece was added */
void treeNode::addChild(treeNode* newChildPtr, int i) {
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
    Board childBoard;
    childBoard = possibleBoard;
    childPtr->setParent(this); 
    if(!childBoard.fullColumn(i)) {           
      childBoard.addPiece(turn, i);            
      addChild(childPtr, i);
    } else {
      addChild(nullptr, i);         
    }  
    childPtr->setBoard(childBoard);
  }
}

// OVERLOADED OPERATORS                                            
void treeNode::operator=(treeNode source) {
  possibleBoard = source.getBoard();
  parent = source.getParent();
  for(int i = 0; i < 7; i++) {
    children[i] = source.getChild(i);
  }
}

/*BFS (breadth first search) by meriselle~
-preconditions: give a turn (user or comp)
-when called parent.BFS(char turn), this function will make 7 children for the parent node, one for each possible column by using the
generateChildren function to fill the node's array of pointers to said children.
-children created will be pushed onto a queue, so it can be visited in the bfs order
-once a winner is found, it will leave the while loop and begin pushing the parent node of the winning board onto a stack and then that parent's parent 
etc until it reaches a parent pointer that is a null pointer (we set the root parent to point to null so we can know when we're done
-then we will print the top of the stack and pop each time so we can print the path of moves that will lead from the root to the winning board*/
void treeNode::BFS(char turn) {
  char thisTurn = turn;
  if(thisTurn == 'O') {               // so that the pieces are switched every time we go down a level (not working as of right now)
    thisTurn = 'X';
  } else {
    thisTurn = 'O';
  }
  bool isWinner = false;              // setting winner as false
  Queue<treeNode*> gameTree;          
  Stack<treeNode*> winningPath;
  gameTree.push(this);			// queue is a queue of pointers, not boards sooo push this pointer so that when we go into the while loop, we generate children from the root first
  treeNode* currentNode;   
  //cout << "before generate children: " << gameTree.front()->getBoard();       //TEST
  while(!gameTree.empty()) {
    if(thisTurn == 'O') {
      thisTurn = 'X';
    } else {
      thisTurn = 'O';
    }
    currentNode = gameTree.front();                 // take the front of the queue to generateChildren then remove it from the queue
    gameTree.pop(); 
    currentNode->generateChildren(thisTurn);
    for(int i = 0; i < 7; i++) {                    // pushing all the generated children to the queue so we can generateChildren for them later
      gameTree.push(currentNode->getChild(i));    
      //cout << "CURRENT PARENT: " << endl << currentNode->getBoard();
      //cout << "current child: " << endl << currentNode->getChild(i)->getBoard() << endl; 
      if(currentNode->getChild(i) == nullptr) {     // however, if its a null pointer, we move on
        continue;
      }      
      if(currentNode->getChild(i)->getBoard().hasWinner()) {  // checking winner
        winningPath.push(currentNode->getChild(i));           // pushing onto winningPath stack if it is a winner
        cout << "WINNER HAS BEEN FOUND!" << endl;
        isWinner = true;
        break;                                                // breaking from for loop
      }
    }
	  if(isWinner) { 
      break;                                                  // breaking from while loop
    }
  }
  treeNode* winner = winningPath.top();                       // winner was stored in the winningPath stack earlier
  cout << "Winning Board: " << endl << winner->getBoard() <<endl;		
  treeNode* rootParent;                                       // keeping track of the parent Nodes
  rootParent = winner->getParent();                           
  cout << "PATH TO WINNING BOARD: " << endl;
  while(rootParent != NULL) {
    winningPath.push(rootParent);                             // so until we reach a pointer pointing to null (root node), we will push onto the stack
    rootParent = rootParent->getParent();
  }
  cout << "Make this move: " << endl;
  while(!winningPath.empty()) {                               // now we are printing the stack, and it will go from the first to last move leading from root to winning board
    Board path = winningPath.top()->getBoard();
    cout << path;
    winningPath.pop(); 
    cout << "Then, make this next move: " << endl;   
  }
  cout << "^Winning board reached^" << endl << "End of Search." << endl;
} 

// the depth first search FOR iterative deepening
// not our actual depth first search
<<<<<<< HEAD
// by meri~
=======
// by meriselle~
>>>>>>> 2e99a8545415a69d400e2b85103e7f7682556877
bool treeNode::itdfs(char turn, treeNode* currentNode, Stack<treeNode*>& nodeStack,int level, int maxLevel) { 
  char thisTurn = turn;                   // going between X and O (currently doesnt work :((    )
  if(thisTurn == 'X') { 
    thisTurn = 'O'; 
  } else {
    thisTurn = 'X';
  }
  if(currentNode->getBoard().hasWinner()) {                       // base case: because its recursive, itll keep calling itself until winner is found
    cout << "-----A WINNING BOARD HAS BEEN FOUND-----" << endl;
  	Stack<treeNode*> winningPath;                                 // same as bfs, filling the stack with the parent pointers of each of the nodes from winning board to root
	  winningPath.push(currentNode);
    cout << "WINNING BOARD: " << endl << currentNode->getBoard() <<endl;
	  while(currentNode->getParent() != NULL) {
	    currentNode = currentNode->getParent();
	    winningPath.push(currentNode);
    }
    treeNode* nextBoard;
    cout << "From here, make this following move: " << endl; // now printing the path of all the boards between root to the winning board
    while(!winningPath.empty()) {
      nextBoard = winningPath.top();
      cout << nextBoard->getBoard() << endl << "Then:" << endl;
      winningPath.pop(); 
    }
    cout << "You're done! You've reached the winning Board!" << endl << "End of Search." << endl;
    return true;
  }
  // if no winner, we go here:
  nodeStack.push(currentNode);                      // since its dfs, we're using a stack to keep track of our nodes so we can back track
  if(level < maxLevel) {
	  for (int i = 0; i < 7; i++) {
      currentNode->generateChildren(thisTurn);      // generating the children here 
      nodeStack.push(currentNode->getChild(i));
		  if (currentNode->getChild(i) == nullptr) {     // don't do anything if the child is a nullptr   
        continue;
      }
      if(itdfs(turn, currentNode->getChild(i), nodeStack, level + 1, maxLevel)) {  
			  return true; // this itdfs will leave when there's a winner, so if it returns true, there's a winner
		  }
	  }
  }
  nodeStack.pop(); 
  return false;
}

// the iterative deepening search is here!
// by meri~
void treeNode::IT(char turn) { 
	treeNode* currentNode;
	currentNode = this;
	for(int i= 0; i < 15; i++) {    
		Stack<treeNode*> nodeStack;
		if(itdfs(turn, currentNode, nodeStack, 0, i)== true) {
			break;
		}
	}
}


// Searching Algorithms
// by gene
void DFS(treeNode*& b, char turn, Stack<treeNode*>& childrenStack){
  // Base Case: returns the winning board or tied board if no other solution possible
  if(b->getBoard().hasWinner()||(b->getBoard().boardFull()&&childrenStack.empty())){ // onlytime you want to print is if board has winner or if full, childrenstack empty isnt necessary
    cout<<b->getBoard(); // winning board
    while(b->getParent()!=nullptr){
      cout<<b->getParent()->getBoard();
      b=b->getParent();
	    return;
    }
  }
  /*
   * If the board isn't full, DFS will push in the child nodes into the childrenStack.
   * Then it will perform DFS on the most leftest child node. If the board is full, it will use the 
   * childrenStack to find the next node to perform DFS on.
   */
  else if(!b->getBoard().boardFull()){
    b->generateChildren(turn);
    for(int i=6; i>=0;i--){
      if((b->getChild(i)) == nullptr) { continue; }
      else { childrenStack.push(b->getChild(i)); }
    }
  } 
  treeNode* onTop=childrenStack.top();
  childrenStack.pop();
  if(turn=='X') turn='O';
  else turn='X';
  DFS(onTop,turn,childrenStack);  
}
// by gene
// computerTurn = 'X; userTurn = 'O'
// by gene
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

<<<<<<< HEAD

=======
>>>>>>> 2e99a8545415a69d400e2b85103e7f7682556877
// by gene
void evaluateUp(treeNode* b, char turn){
	int minMax; 
	if(turn=='O') { minMax=100000000; }	
	else { minMax=-100000000; }
	// while your current subtree isn't the root, you compare yourself to your siblings and based on the turn, you minimize or maximize
	while(b->getParent()!= NULL){
		b=b->getParent(); 
		if(b->getChild(0)!=NULL && b->getChild(1)!=NULL && b->getChild(2)!=NULL && b->getChild(3)!=NULL
			 && b->getChild(4)!=NULL && b->getChild(5)!=NULL && b->getChild(6)!=NULL){
			for(size_t i=0; i<7; i++){
				int temp=(b->getChild(i)->getBoard().getScore());
				// if the current turn is the user, you try to minimize
				if(turn=='O' && temp<minMax){ minMax=temp; } 
				// otherwise, you're maximizing
				else if (temp>minMax) { minMax=temp; }
			}
			b->getBoard().setScore(minMax);                                                            
		}
		// if one of your sibling is NULL, you return the function and wait until it gets a score
		else { return; }
	}
	// for printing the possible board combinations out
	while(b->getChildren()!=NULL){
		for(size_t i=0; i<7;i++){
    	if(b->getChild(i)==NULL) { continue; }
			else if(b->getChild(i)->getBoard().getScore()==minMax){                         
				b=b->getChild(i);
				cout<<b->getBoard();
			}
		}
	}
}
/* by gene
 * Precondition: A root containing board b that can still be filled
 * Postcondition: A tree from that board b with 4 levels of possible board choices. Each node has 7 children.
 * 		When the program finishes, each leaf score is calculated with generateScore. At the end,  
 *		evaluateUp takes each leaf score and "miniMaxes" it upward.
 */

// by gene
void MiniMax(treeNode* b, size_t level, char turn){
  // If the node is null, we generate the score for the parent and stop generating null children
  if(b==NULL){
    if(turn=='O') turn='X';
    else turn='O';
    level++;
    generateScore(b->getParent(),level, turn);
    return;
  }
  if(level==0){
    evaluateUp(b, turn); 
    return;
  }
  // Otherwise, the MiniMax function continues to generate child nodes
  b->generateChildren(turn);
  for(size_t i=0; i<7;i++){
    if(b->getChild(i) == NULL) { continue; }
    if(turn=='O') { turn='X'; }
    else { turn='O'; }
    // for each level, the minimax function will recursively call upon itself to create more children nodes
    if(level>1) {   level--; MiniMax(b->getChild(i),level,turn); }
    // if level is 1, we have to generate child nodes and also their score
    else { level--; generateScore(b->getChild(i),level,turn); }
  }
}
    
#endif
