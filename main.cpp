#include "board.h"
#include "AIPlayer.h"
#include <iostream>
using namespace std::cin;
using namespace std::cout;

void makeMove(char Player, Board b){
	if(Player==user){
		size_t playerInput;
		cin>>playerInput;
		b.addPiece(Player,playerInput);
	} 
	else{
		size_t AI_Input= ai.makeMove();
		b.addPiece(Player,AI_Input);
	}
	cout<<init;
}

int main(){
	// initialize the board and AI
	Board init=new Board(); 
	AIPlayer ai=new AIPlayer();
	
	// playerInput is the column the player chooses to put a chip into
	while(!init.hasWinner() && !init.boardFull){
		makeMove(user,init);
		if(init.hasWinner()){
			cout<<"You won!";
			return;
		}
		makeMove(comp,init);
		if(init.hasWinner()){
			cout<<"You lost!";
			return;
		}
	}
	cout<<"You tied!";
	return 0;
}
