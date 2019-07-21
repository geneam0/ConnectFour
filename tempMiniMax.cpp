void MiniMax(const treeNode* b, size_t level, char turn){
  // When level reaches 0 or when neither player can make a move, we have to evaluate each child node
  if(level==0||*b==nullptr){
    evaluateUp(); //!!!!
    return;
  }
  // Otherwise, the MiniMax function continues to generate child nodes
  b->generateChildren(turn);
  level--;
  // for each level, the minimax function will recursively call upon itself to create more children nodes
  else if (level>1){
    for(size_t i=0; i<7;i++){
      if(children[i] == nullptr) { continue; }
      else{
        if(turn=='O') turn='X';
        else turn='O';
        MiniMax(b->getChild(i),level,turn);
      }
    }
  }
  // if level is 1, we have to generate child nodes and also their score
  else{
    for(size_t i=0; i<7;i++){
      if(children[i] == nullptr) { continue; }
      else{
        generateScore for children; /!!!!!
      }
    }
  }
}
