#include "board.h"
#include "treeNode.h"
#include <iostream>
using namespace std::cout;

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
	// initialize the board and AI
	Board initDFS = new Board(); 
	treeNode AI = new treeNode();
	treeNode depth = new treeNode(init);
	// test DFS
	initDFS.addPiece('X',0); initDFS.addPiece('O',0);
	initDFS.addPiece('X',0); initDFS.addPiece('O',0);
	initDFS.addPiece('X',0); initDFS.addPiece('O',0);
	initDFS.addPiece('X',1); initDFS.addPiece('O',1);
	initDFS.addPiece('X',1); initDFS.addPiece('O',1);
	initDFS.addPiece('X',1); initDFS.addPiece('O',1);
	initDFS.addPiece('X',2); initDFS.addPiece('O',2);
	initDFS.addPiece('X',2); initDFS.addPiece('O',2);
	initDFS.addPiece('X',2); 
	/* Should look like dis:
	Before               Mid		  After
	O O - - - - -        O O O - - - -	  O O O - - - -
	X X X - - - -        X X X - - - -	  X X X - - - -
	O O O - - - - _____\ O O O - - - - _____\ O O O - - - -
	X X X - - - -      / X X X - - - -      / X X X - - - -
	O O O - - - -        O O O - - - -	  O O O - - - -
	X X X - - - -        X X X - - - -	  X X X X - - - (wow, that glo' up tho)
	*/
	AI.DFS(depth,'O'); 
	delete initDFS;
	
	// initialize the board again
	Board initBFS = new Board();
	// test BFS
	
	delete initBFS;
	
	// initalize the board again
	Board initMM = new Board();
	// test MiniMax
	init.addPiece('O',1); init.addPiece('O',3); init.addPiece('O',5);
	init.addPiece('X',2); init.addPiece('X',3); init.addPiece('X',4);
	init.addPiece('O',2); init.addPiece('O',3); init.addPiece('X',4);
	/* Should look liek dis:
	Before		     Mid		  Second Mid		Final
	- - - - - - -        - - - - - - -	  - - - - - - -        - - - - - - -
	- - - - - - -        - - - - - - -        - - - - - - -        - - - - - - -
	- - - - - - - _____\ - - - - - - - _____\ - - - - - - - _____\ - - - - - - -
	- - - O - - -      / - - X O - - -      / - - X O O - -      / - - X O O - -
	- - O X X - -        - - O X X - -        - - O X X - -        - - O X X X -
	- O X O X O -        - O X O X O -        - O X O X O -        - O X O X O -
	highkey not sure if this will work tho
	*/
	AI.MiniMax(init,4,'X');
	delete initMM;
	
	// initalize the board again
	Board initID = new Board();
	// test Iterative Deepening
	
	delete initID;
	
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
	*/
	return 0;
}
