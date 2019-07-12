#include "Board.h"
#include "Node.h"
#include "PriorityQueue.h"

size_t DFS(const Board b){
  Item* root=new Item(b);
  size_t level=0;
  while(level<=depth){
    root.nextChild(0);
    calculateDFSCost();
  }
}
