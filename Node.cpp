#ifndef __NODE_CPP__
#define __NODE_CPP__

#include "node.h";

treeNode::treeNode() {

}

treeNode::treeNode(nodeDatatype *&source) {

}
treeNode treeNode::getChild(size_t i) {
} // get ith child

treeNode treeNode::getChildren() {
} //get all children


void treeNode::addChild(treeNode* newChildPtr, size_t i) {
  children[i] = newChildPtr;
}

treeNode treeNode::operator=(treeNode source) {

}

void treeNode::generateChildren(char turn) {
  for(int i = 0; i < 7; i++) {
    treeNode *childPtr;
    childPtr = new treeNode;
    childPtr->setData(possibleBoard);
    if(!childPtr->getData().fullColumn(i)) {
      childPtr->getData().addPiece(turn, i);
      addChild(childPtr, i);
    } else {
      addChild(nullptr, i);         // when reading children, have to check whether its null pointer first because youll get an error accessing a null ptr
    }
  }
}


Board Node::DFS(const Board b){
  // Base Case: returns the winning board or tied board if no other solution possible
  if(b.hasWinner()||(b.boardFull()&&childrenStack.empty())) return b;
  /*
   * If the board isn't full, DFS will push in the child nodes into the childrenStack and the parent nodes into the 
   * parentStack. Then it will perform DFS on the most leftest child node. If the board is full, it will use the 
   * childrenStack to find the next node to perform DFS on.
   */
  else if(!b.boardFull()){
    parentStack.push(b);
    //!!!! IMPLEMENT GENERATE CHILDREN
    childrenStack.push(generateChildren(b));
  } 
  Board onTop=childrenStack.top();
  childrenStack.pop();
  DFS(onTop);
}

Board Node::Minimax(const Board b, size_t level){
  if(level>4) return;
  
}

#endif
