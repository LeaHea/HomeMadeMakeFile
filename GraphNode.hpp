#ifndef _GRAPHNODE
#define _GRAPHNODE

#include<iostream>
#include<string>
#include<vector>

#include "systemInterface.hpp" 

class GraphNode {
public:
  GraphNode( std::string name );
  std::string getName();
  void setName( std::string name );
  void setTimestamp(int ts);
  int getTimestamp();

  std::vector<GraphNode *> *dependentNodes() { return (std::vector<GraphNode *> *) _listOfDependentNodes; };

  void setCommand(std::string cmnd);
  std::string getCommand();

  void runCommand();  // execute the command associated with this node.
  void addDependentNode(GraphNode *child);

  bool onPath();
  void onPath(bool v);

  bool wasMade();
  void wasMade(bool v);

  bool isATarget();
  void isATarget(bool v);

  int numDependentNodes();
  void print();

private:
  std::string _name, _command;
  int _timestamp;
  std::vector<GraphNode *> *_listOfDependentNodes;

  bool _onPath, _isATarget, _wasMade;
};

#endif
