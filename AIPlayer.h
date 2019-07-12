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
};
#endif
