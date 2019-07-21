#include <math.h>       /* pow */

// computerTurn = 'X; userTurn = 'O'
void generateScore(treeNode* b, size_t level, char turn){
  // initalize the board and score
  Board in=b.possibleBoard;
  int score=0; level++; size_t consecutive=0; int tempScore=0;
  // adds score based on how many consecutives each board has
	for(size_t i=0; i<rows-3; i++){
		for(size_t j=0; j<columns; j++){
		  if(turn==arr[i][j]==arr[i+1][j]==arr[i+2][j]==arr[i+3][j]){ consecutive=4; }
      else if (turn==arr[i][j]==arr[i+1][j]==arr[i+2][j]){ consecutive=3; }
      else if (turn==arr[i][j]==arr[i+1][j]){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
	for(size_t i=0; i<rows; i++){
		for(size_t j=0; j<columns-3; j++){
			if(turn==arr[i][j]==arr[i][j+1]==arr[i+2][j+2]==arr[i][j+3]){ consecutive=4; }
      else if (turn==arr[i][j]==arr[i][j+1]==arr[i+2][j+2]){ consecutive=3; }
      else if (turn==arr[i][j]==arr[i][j+1]){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
	for(size_t i=0; i<rows-3; i++){
		for(size_t j=0; j<columns-3;j++){
      if(turn==arr[i][j]==arr[i+1][j+1]==arr[i+2][j+2]==arr[i+3][j+3]){ consecutive=4; }
      else if (turn==arr[i][j]==arr[i+1][j+1]==arr[i+2][j+2]){ consecutive=3; }
      else if (turn==arr[i][j]==arr[i+1][j+1]){ consecutive=2; }
      score+=pow(level,consecutive);
		}
	}
  // sets the board score based on whether the turn is from the computer or user
  if(turn=='O'){ score*-1; }
  in.setScore(score);
}

void evaluateUp(treeNode* b, char turn){
	while(b->getParent()!= NULL){
		b=b->getParent(); 
		if(b->getChild(0)!=NULL && b->getChild(1)!=NULL && b->getChild(2)!=NULL && b->getChild(3)!=NULL
			 && b->getChild(4)!=NULL && b->getChild(5)!=NULL && b->getChild(6)!=NULL){
			int minMax; 
			if(turn=='O') { minMax=100000000; }	
			else { minMax=-100000000; }
			for(size_t i=0; i<7; i++){
				int temp=b->getChild(i).possibleBoard->getScore();
				if(turn=='O' && temp<minMax){ minMax=temp; } 
				else if (temp>minMax) { minMax=temp; }
			}
			b->setScore(minMax);
		}
		else { return; }
	}
	while(b->getChildren()!=NULL){
		for(size_t i=0; i<7;i++){
    	if(b->getChild(i)==NULL) { continue; }
			if(b->getChild(i)==minMax){
				b=b->getChild(i);
				cout<<b;
			}
		}
	}
}

/*
 * Precondition: A root containing board b that can still be filled
 * Postcondition: A tree from that board b with 4 levels of possible board choices. Each node has 7 children.
 * 		When the program finishes, each leaf score is calculated with generateScore. At the end,  
 *		evaluateUp takes each leaf score and "miniMaxes" it upward.
 */
void MiniMax(const treeNode* b, size_t level, char turn){
  // If the node is null, we generate the score for the parent and stop generating null children
  if(*b==NULL){
    if(turn=='O') turn='X';
    else turn='O';
    level++;
    generateScore(b->getParent(),level, turn);
    return;
  }
  if(level==0){
    evaluateUp(*b, turn); 
    return;
  }
  // Otherwise, the MiniMax function continues to generate child nodes
  b->generateChildren(turn);
  for(size_t i=0; i<7;i++){
    if(b->getChild(i)==NULL) { continue; }
    if(turn=='O') { turn='X'; }
    else { turn='O'; }
    // for each level, the minimax function will recursively call upon itself to create more children nodes
    if(level>1) {   level--; MiniMax(b->getChild(i),level,turn); }
    // if level is 1, we have to generate child nodes and also their score
    else { level--; generateScore(b->getChild(i),level,turn); }
  }
}
