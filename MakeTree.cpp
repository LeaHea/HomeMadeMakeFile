#include "MakeTree.hpp"
#include "string.h"

MakeTree::MakeTree( GraphNode *gNode ){  
  _root = new TreeNode ( gNode );

}

GraphNode *MakeTree::find( TreeNode *tNode, std::string name ){
  if ( tNode == NULL )
    return new GraphNode ( name );

  if ( strcmp( tNode->graphNode()->getName().c_str(), name.c_str() ) == 0 )
      return tNode->graphNode();

  if ( strcmp( tNode->graphNode()->getName().c_str(), name.c_str() ) > 0)
    return find ( tNode->left(), name );

  return find ( tNode->right(), name );
}

TreeNode *MakeTree::insert(TreeNode *tNode, GraphNode *nNode){  
  if( tNode == NULL)
    return new TreeNode( nNode );

  if( strcmp( tNode->graphNode()->getName().c_str(), nNode->getName().c_str() ) < 0 )
    tNode->right( insert( tNode->right(), nNode ) );
 
  else
    tNode->left( insert( tNode->left(), nNode ) );

  return tNode;

}

void MakeTree::print(TreeNode *root){
  if ( root == NULL ) return;

  print( root->left() ); 
 
  root->graphNode()->print();
  std::cout << "\n\n\n";
 
  print( root->right() );
}
