#include "GraphNode.hpp"


GraphNode::GraphNode( std::string name ){  
  _name = name;
  _timestamp = 0;
  _listOfDependentNodes = new std::vector <GraphNode *>;
  _onPath = _isATarget = _wasMade = false;
}

std::string GraphNode::getName(){
  return _name;

}

void GraphNode::setName( std::string name ){
  _name = name;
}

void GraphNode::setTimestamp(int ts){
  _timestamp = ts;

}

int GraphNode::getTimestamp(){
  return _timestamp;
}


void GraphNode::setCommand(std::string cmnd){
  _command = cmnd;
}

std::string GraphNode::getCommand(){
  return _command;
}

void GraphNode::runCommand(){
  executeCommand ( _command.c_str() );

}

// execute the command associated with this node.
void GraphNode::addDependentNode(GraphNode *child){
  _listOfDependentNodes->push_back(child);
  
}

bool GraphNode::onPath(){
  return _onPath;
}

void GraphNode::onPath(bool v){
  if (v == true)
    _onPath = true;
  else _onPath = false;
}

bool GraphNode::wasMade(){
  return _wasMade;
}

void GraphNode::wasMade(bool v){
  if (v == true)
    _wasMade = true;
  else _wasMade = false;

}

bool GraphNode::isATarget(){
  return _isATarget;
}

void GraphNode::isATarget(bool v){
  if (v == true)
    _isATarget = true;
  else _isATarget = false;
}

int GraphNode::numDependentNodes(){
  return _listOfDependentNodes->size();
}

void GraphNode::print(){
  
  std::cout << "Name: " << this->getName() << std::endl;
  std::cout << "Command: " << _command << std::endl;;
  std::cout << "TimeStamp: " << _timestamp << std::endl;;
  
  if (_onPath)
    std::cout << "is on path." << std::endl;
  
  if (_isATarget)
    std::cout << "is a target." << std::endl;
  
  if (_onPath)
    std::cout << "was made.\n" << std::endl;

  std::cout << "List of Dependent Nodes for " << _name << ":" << std::endl;
  for( std::vector<GraphNode *>::iterator iter = _listOfDependentNodes->begin(); iter != _listOfDependentNodes->end(); ++iter ) 
    std::cout << (*iter)->getName() << std::endl;
  std::cout << "\n\n\n";

}
