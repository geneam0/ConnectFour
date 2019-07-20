#include "board.h"
#include "Node.h"
#include <iostream>
using namespace std::cin;
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
	Board init = new Board(); 
	Node AI = new Node();
	// test DFS
	init.addPiece('X',0); init.addPiece('O',0);
	init.addPiece('X',0); init.addPiece('O',0);
	init.addPiece('X',0); init.addPiece('O',0);
	init.addPiece('X',1); init.addPiece('O',1);
	init.addPiece('X',1); init.addPiece('O',1);
	init.addPiece('X',1); init.addPiece('O',1);
	init.addPiece('X',2); init.addPiece('O',2);
	init.addPiece('X',2); init.addPiece('O',2);
	init.addPiece('X',2); 
	/* Should look like dis:
	Before               After
	O O - - - - -        O O O - - - -
	X X X - - - -        X X X - - - -
	O O O - - - - _____\ O O O - - - -
	X X X - - - -      / X X X - - - -
	O O O - - - -        O O O - - - -
	X X X - - - -        X X X X - - - (wow, that glo' up)
	*/
	cout<<AI.DFS(init);
	delete init;
	
	// initialize the board again
	Board init = new Board();
	// test BFS
	
	delete init;
	
	// initalize the board again
	Board init = new Board();
	// test MiniMax
	
	delete init;
	
	// initalize the board again
	Board init = new Board();
	// test Iterative Deepening
	
	delete init;
	
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
