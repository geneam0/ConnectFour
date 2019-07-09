#ifndef __TREENODE__
#define __TREENODE__
class treeNode{
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
