#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include "Stack.h"
#include "Queue.h"
#include "board.h"
#include "treeNode.h"

int main(){
	char user = 'O';
	char comp = 'X';
	
	// Depth First Search
	/*
	Board initDFS;
	Stack<treeNode*> s;
	initDFS.addPiece(comp,0); initDFS.addPiece(user,0); initDFS.addPiece(comp,0); 
	initDFS.addPiece(user,0); initDFS.addPiece(comp,0); initDFS.addPiece(user,0);
	initDFS.addPiece(comp,1); initDFS.addPiece(user,1); initDFS.addPiece(comp,1); 
	initDFS.addPiece(user,1); initDFS.addPiece(comp,1); initDFS.addPiece(user,1);
	initDFS.addPiece(comp,2); initDFS.addPiece(user,2); initDFS.addPiece(comp,2); 
	initDFS.addPiece(user,2); initDFS.addPiece(comp,2); 
	treeNode dFirst;							
	dFirst.setBoard(initDFS);
	treeNode* depth=&dFirst;
	DFS(depth,user,s); // prints the children
	cout<<initDFS; // prints the root
	*/
	/*
	Before               Mid		  		  After
	O O - - - - -        O O O - - - -	  	  O O O - - - -
	X X X - - - -        X X X - - - -	 	  X X X - - - -
	O O O - - - - _____\ O O O - - - - _____\ O O O - - - -
	X X X - - - -      / X X X - - - -      / X X X - - - -
	O O O - - - -        O O O - - - -	  	  O O O - - - -
	X X X - - - -        X X X - - - -	 	  X X X X - - - 
	*/ 

	
// BFS AND ITERATIVE DEEPENING BOARD IS CREATED HERE
	Board bfsBoard; 
	Stack<treeNode*> s;
	bfsBoard.addPiece(comp,0); // initDFS.addPiece(user,0); initDFS.addPiece(comp,0); 
	// initDFS.addPiece(user,0); initDFS.addPiece(comp,0); initDFS.addPiece(user,0);
	//initDFS.addPiece(comp,1); initDFS.addPiece(user,1); initDFS.addPiece(comp,1); 
	//initDFS.addPiece(user,1); initDFS.addPiece(comp,1); initDFS.addPiece(user,1);
	//initDFS.addPiece(comp,2); initDFS.addPiece(user,2); initDFS.addPiece(comp,2); 
	//initDFS.addPiece(user,2); initDFS.addPiece(comp,2);
	treeNode bfsnode;							
	bfsnode.setBoard(bfsBoard);
	treeNode* depth=&bfsnode;
		
// ---------UNCOMMENT FOR BFS SEARCH-----------
	//bfsnode.BFS(user);

	 		/*STATUS: as of right now, BFS >>DOES<< compile and run and return a winning board
			however it doesnt switch between X and O turns properly */

// ---------UNCOMMENT FOR ITERATIVE DEEPENING-----------
	//bfsnode.IT(user);

			/*STATUS: as of right now, IT >>WORKS<< but it does not switch between X and O
			it compiles AND runs and returns a winning board */
		
	//MiniMax (does not work)
	/*
	Board initMM;
	initMM.addPiece(user,1); initMM.addPiece(user,3); initMM.addPiece(user,5);
	initMM.addPiece(comp,2); initMM.addPiece(comp,4); initMM.addPiece(user,2);
	initMM.addPiece(comp,3); initMM.addPiece(comp,4); initMM.addPiece(user,3); 
	treeNode mini;
	mini.setBoard(initMM);
	treeNode* max=&mini;
	MiniMax(max,2,comp);
	*/
	/* 
	Should look liek dis:
	Before		     Mid		  Second Mid		Final
	- - - - - - -        - - - - - - -	  - - - - - - -        - - - - - - -
	- - - - - - -        - - - - - - -        - - - - - - -        - - - - - - -
	- - - - - - - _____\ - - - - - - - _____\ - - - - - - - _____\ - - - - - - -
	- - - O - - -      / - - X O - - -      / - - X O O - -      / - - X O O - -
	- - O X X - -        - - O X X - -        - - O X X - -        - - O X X X -
	- O X O X O -        - O X O X O -        - O X O X O -        - O X O X O -
	*/
}

#endif 
