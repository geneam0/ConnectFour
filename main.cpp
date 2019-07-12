#include "board.h"
#include "AIPlayer.h"
#include <iostream>
using namespace std::cin;
using namespace std::cout;

int main(){
	Board init=new Board(); 
	AIPlayer ai=new AIPlayer();
	
	// playerInput is the column the player chooses to put a chip into
	size_t playerInput;
	
	while(!init.hasWinner() && ){
		cin>>playerInput;
		init.updateBoard(playerInput);
		cout<<init;
	}
	return 0;
}
