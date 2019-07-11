#include "board.h"
#include <iostream>
using namespace std::cin;
using namespace std::cout;

int main(){
	Board init; 
	// playerInput is the column the player chooses to put a chip into
	size_t playerInput;
	while(!init.hasWinner()){
		cin>>playerInput;
		cout<<init;
	}
	return 0;
}
