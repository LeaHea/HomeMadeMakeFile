#ifndef _DepGraph_hpp
#define _DepGraph_hpp

#include<iostream>
#include<cstring>
#include<cstdlib>

#include "MakeTree.hpp"
#include "Token.hpp"
#include "Reader.hpp"


class DepGraph {
public:
  DepGraph( std::string name );
  void print();
  void parseDepGraph();
  void runMake();
  bool isCyclic();
  
private:
  Token readAndProcessDependencyPair(Reader *);
  bool isCyclic(GraphNode *);
  void runMake( GraphNode *p );

  std::string _fileToMake, _targetToMake;
  GraphNode *firstTarget;
  GraphNode *nodeInTree;

  MakeTree *_tree;

};


#endif
