#ifndef AIPLAYER_H
#define AIPLAYER_H
#include <treeNode>
template <class Item>
class AIPlayer{
  private:
    Item data;
    treeNode* parent;
    treeNode** children;
    size_t numChildren;
    size_t capChildren;
  public:
    //get ith children
    Item getChild(size_t i){ return children[i]; }
    //get all children
    Item* getChild(){ return *children; }
    //ith children to a different state
    void setChild(size_t i); 
    void addChild(); //
    Item* generateChildren();
    size_t BFS(const Board b);
    size_t DFS(const Board b);
    size_t MiniMax(const Board b);
    size_t IterativeDeepening(const Board b);
    // main method for the AI to determine which column to place in
    size_t move(const Board b);
};
#endif
