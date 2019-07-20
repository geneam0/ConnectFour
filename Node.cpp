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



#endif
