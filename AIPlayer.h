#ifndef AIPLAYER_H
#define AIPLAYER_H
class AIPlayer{
  private:
    Item data;
    treeNode* parent;
    treeNode** children;
    size_t numChildren;
    size_t capChildren;
  public:
    getChild //get ith children
    getChild //get all children
    setChild //ith children to a different state
    addChild //
    generateChildren //
};
#endif
