#include "TreeNode.hpp"

TreeNode::TreeNode( GraphNode *nNode ){

  makeNode = nNode;
  leftSubtree = rightSubtree = NULL;

}

TreeNode *TreeNode::left(){
  return leftSubtree;

}

void TreeNode::left( TreeNode *leftPtr ){
  this->leftSubtree = leftPtr;

}

TreeNode *TreeNode::right(){
  return rightSubtree;

}

void TreeNode::right( TreeNode *rightPtr ){
  this->rightSubtree = rightPtr;

}
  
void TreeNode::print(){
  makeNode->print();

}

GraphNode *TreeNode::graphNode(){
  return makeNode;
}
