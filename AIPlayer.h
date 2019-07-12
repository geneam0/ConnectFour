#ifndef AIPLAYER_H
#define AIPLAYER_H
template <class Item>
class AIPlayer{
  private:
    Item data;
    treeNode* parent;
    treeNode** children;
    size_t numChildren;
    size_t capChildren;
  public:
    getChild(size_t i); //get ith children
    getChild(); //get all children
    setChild(size_t i); //ith children to a different state
    addChild(); //
    generateChildren //
    // main method for the AI to determine which column to place in
    size_t move(const Board b){
      // return BFS(b);
      // return DFS(b);
      // return MiniMax(b);
      // return IterativeDeepening(b);
    }
};
#endif
