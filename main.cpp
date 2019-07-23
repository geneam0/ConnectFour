#include "treeNode.h"

// for when we want to make a Player vs AI Connect Four Game
/*
void makeMove(char Player, Board& b){
	if(Player==init.getUser()){
		size_t playerInput;
		cin>>playerInput;
		b.addPiece(Player,playerInput);
	} 
	else{
		size_t AI_Input=ai.move(b);
		b.addPiece(Player,AI_Input);
	}
	cout<<init;
}
*/

int main(){
	char user = 'O';
	char comp = 'X';
	
	// Depth First Search
	// initialize the board and stack
	Board initDFS; 
	Stack<treeNode> s;
	initDFS.addPiece(comp,0); initDFS.addPiece(user,0); initDFS.addPiece(comp,0); 
	initDFS.addPiece(user,0); initDFS.addPiece(comp,0); initDFS.addPiece(user,0);
	initDFS.addPiece(comp,1); initDFS.addPiece(user,1); initDFS.addPiece(comp,1); 
	initDFS.addPiece(user,1); initDFS.addPiece(comp,1); initDFS.addPiece(user,1);
	initDFS.addPiece(comp,2); initDFS.addPiece(user,2); initDFS.addPiece(comp,2); 
	initDFS.addPiece(user,2); initDFS.addPiece(comp,2); 
	/*
	Before               Mid		  After
	O O - - - - -        O O O - - - -	  O O O - - - -
	X X X - - - -        X X X - - - -	  X X X - - - -
	O O O - - - - _____\ O O O - - - - _____\ O O O - - - -
	X X X - - - -      / X X X - - - -      / X X X - - - -
	O O O - - - -        O O O - - - -	  O O O - - - -
	X X X - - - -        X X X - - - -	  X X X X - - - (wow, that glo' up tho)
	*/
	//test DFS
	treeNode dFirst;
	dFirst.treeNode(initDFS);
	DFS(depth,'O',s); 
	
	// Breadth First Search
	// initialize the board again
	//Board initBFS = new Board();
	// test BFS
	
	//delete initBFS;
	/*
	Board initMM;
	initMM.addPiece(user,1); initMM.addPiece(user,3); initMM.addPiece(user,5);
	initMM.addPiece(comp,2); initMM.addPiece(comp,4); initMM.addPiece(user,2);
	initMM.addPiece(comp,3); initMM.addPiece(comp,4); initMM.addPiece(user,3); 
	cout<<initMM;
	*/
	/* Should look liek dis:
	Before		     Mid		  Second Mid		Final
	- - - - - - -        - - - - - - -	  - - - - - - -        - - - - - - -
	- - - - - - -        - - - - - - -        - - - - - - -        - - - - - - -
	- - - - - - - _____\ - - - - - - - _____\ - - - - - - - _____\ - - - - - - -
	- - - O - - -      / - - X O - - -      / - - X O O - -      / - - X O O - -
	- - O X X - -        - - O X X - -        - - O X X - -        - - O X X X -
	- O X O X O -        - O X O X O -        - O X O X O -        - O X O X O -
	*/
	//treeNode mini = new treeNode(initMM);
	//MiniMax(initMM,4,comp);
	/*
	// initalize the board again
	Board initID = new Board();
	// test Iterative Deepening
	
	delete initID;
	*/
	// for when we want to make a Player vs AI Connect Four Game
	/*
	// playerInput is the column the player chooses to put a chip into
	while(!init.hasWinner() && !init.boardFull()){
		makeMove(init.getUser(),init);
		if(init.hasWinner()){
			cout<<"You won!";
			return;
		}
		makeMove(init.getComp(),init);
		if(init.hasWinner()){
			cout<<"You lost!";
			return;
		}
	}
	cout<<"You tied!";
	
	return 0;

	*/
	//char user = 'X';
	//char comp = 'O';

	//Board test=Board();
	//test.addPiece('X', 0);
	//treeNode bfsTest = treeNode(test);
	//bfsTest.BFS(user);
	return 0;
}
