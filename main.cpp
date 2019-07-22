#include "board.h"
#include "treeNode.h"
#include "Stack.h"
#include <iostream>
using std::cout;

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
	// initialize the board and stack
	Board initDFS; 
	Stack<treeNode> s;
	char user = 'O';
	char comp = 'X';
	// test DFS
	initDFS.addPiece(user,0); 
	/* Should look like dis:
	Before               Mid		  After
	O O - - - - -        O O O - - - -	  O O O - - - -
	X X X - - - -        X X X - - - -	  X X X - - - -
	O O O - - - - _____\ O O O - - - - _____\ O O O - - - -
	X X X - - - -      / X X X - - - -      / X X X - - - -
	O O O - - - -        O O O - - - -	  O O O - - - -
	X X X - - - -        X X X - - - -	  X X X X - - - (wow, that glo' up tho)
	*/
	treeNode depth(initDFS);
	DFS(*depth,'O',s); 
	/*
	// initialize the board again
	Board initBFS = new Board();
	// test BFS
	
	delete initBFS;
	*/
	// initalize the board again
	Board initMM = new Board();
	// test MiniMax
	init.addPiece(user,1); 
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
	treeNode mini = new treeNode(initMM);
	MiniMax(init,4,'X');
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
	*/
	return 0;
}
