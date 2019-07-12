#include "board.h"
#include "AIPlayer.h"
#include <iostream>
using namespace std::cin;
using namespace std::cout;

void makeMove(char Player, Board b){
	if(Player==init.getUser()){
		size_t playerInput;
		cin>>playerInput;
		b.addPiece(Player,playerInput);
	} 
	else{
		size_t AI_Input=ai.move();
		b.addPiece(Player,AI_Input);
	}
	cout<<init;
}

int main(){
	// initialize the board and AI
	Board init=new Board(); 
	AIPlayer ai=new AIPlayer();
	
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
}
