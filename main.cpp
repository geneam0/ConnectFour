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
	Board initDFS; 
	Stack<treeNode*> s;
	initDFS.addPiece(comp,0); // initDFS.addPiece(user,0); initDFS.addPiece(comp,0); 
	// initDFS.addPiece(user,0); initDFS.addPiece(comp,0); initDFS.addPiece(user,0);
	//initDFS.addPiece(comp,1); initDFS.addPiece(user,1); initDFS.addPiece(comp,1); 
	//initDFS.addPiece(user,1); initDFS.addPiece(comp,1); initDFS.addPiece(user,1);
	//initDFS.addPiece(comp,2); initDFS.addPiece(user,2); initDFS.addPiece(comp,2); 
	//initDFS.addPiece(user,2); initDFS.addPiece(comp,2);
	treeNode dFirst;							
	dFirst.setBoard(initDFS);
	treeNode* depth=&dFirst;
	cout << "pointer defined" << endl;
	// DFS(depth,user,s);		// DFS PRINTS IFINITELY
	dFirst.BFS(user);
	//dFirst.IT(comp);
	cout << "IT was called" << endl;

	// DFS(depth,user,s);		
	// dFirst.BFS(user);
	/*
	Before               Mid		  		  After
	O O - - - - -        O O O - - - -	  	  O O O - - - -
	X X X - - - -        X X X - - - -	 	  X X X - - - -
	O O O - - - - _____\ O O O - - - - _____\ O O O - - - -
	X X X - - - -      / X X X - - - -      / X X X - - - -
	O O O - - - -        O O O - - - -	  	  O O O - - - -
	X X X - - - -        X X X - - - -	 	  X X X X - - - 
	*/ 
	
	/* 
	Board initMM;
	initMM.addPiece(user,1); initMM.addPiece(user,3); initMM.addPiece(user,5);
	initMM.addPiece(comp,2); initMM.addPiece(comp,4); initMM.addPiece(user,2);
	initMM.addPiece(comp,3); initMM.addPiece(comp,4); initMM.addPiece(user,3); 
	treeNode mini(initMM);
	treeNode* max=&mini;
	MiniMax(max,4,comp);
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
}

#endif 
