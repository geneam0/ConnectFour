
void MiniMax(const treeNode* b, size_t level, char turn){
  // When level reaches 0 or when neither player can make a move, we have to evaluate each child node
  if(level==0||b.possibleBoard.hasWinner()||(b.possibleBoard.boardFull()&&childrenStack.empty())){
    cout<<b.possibleBoard;
    while(b->getParent()!=NULL){
      cout<<b->getParent().possibleBoard;
      b=b->getParent();
    }
  }
  // Otherwise, the MiniMax function continues to generate child nodes
  else{
    b->generateChildren(turn);
    level--;
    for(size_t i=0; i<7;i++){
      if(children[i] == nullptr) { continue; }
      else{
        if(turn=='O') turn='X';
        else turn='O';
        MiniMax(b->getChild(i),level,turn);
      }
    }
  }
}
