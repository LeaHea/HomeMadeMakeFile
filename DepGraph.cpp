#include "DepGraph.hpp"

DepGraph::DepGraph( std::string name ){
  _fileToMake = name;
  
}

void DepGraph::print(){
  
}

void DepGraph::parseDepGraph(){
 
  std::cout << "Using makefile, " << _fileToMake << ".\n";

  Reader *reader = new Reader (_fileToMake);

  while( true ) {
    Token token = readAndProcessDependencyPair ( reader );
    
    if( token.isEOF() )
      return;
  } 
}

void DepGraph::runMake(){
  runMake( firstTarget );
}

bool DepGraph::isCyclic(){
  return isCyclic( firstTarget );
  
}

bool DepGraph::isCyclic(GraphNode *graphNode){
  long numSecondsSinceJan1st1997;

  timestamp ( graphNode->getName().c_str(), &numSecondsSinceJan1st1997 );
  graphNode->setTimestamp( numSecondsSinceJan1st1997 );

  if( graphNode->onPath() ){
    return true;
  }

  graphNode->onPath(true);
  for (std::vector<GraphNode*>::iterator iter = graphNode->dependentNodes()->begin(); iter != graphNode->dependentNodes()->end(); ++iter ){ 
    if (isCyclic (*iter ))
      return true;

    isCyclic (( *iter ));
  }
  return false;
}

void DepGraph::runMake( GraphNode *graphNode ){
  for (std::vector<GraphNode*>::iterator iter = graphNode->dependentNodes()->begin(); iter != graphNode->dependentNodes()->end(); ++iter ){
    runMake (( *iter ));
 
    if ( graphNode->getTimestamp() < (*iter)->getTimestamp()){

       std::cout << "Executing command...\n";
       std::cout << (graphNode)->getCommand() << std::endl;
       executeCommand( (graphNode)->getCommand().c_str());   
   
    }    
  }
}	

Token DepGraph::readAndProcessDependencyPair( Reader *reader){
  Token target = reader->getToken();  
  
  if( target.isEOF() )
    return target;
  
  if( ! target.isName() ) {
    std::cout << "The first token of a dependency line should be a name-token.\n";
    exit(1);
    
  }

  GraphNode *gNode = new GraphNode( target.getName() ); 
  
  if (_tree == NULL){
    _tree = new MakeTree ( gNode );
    firstTarget = gNode;
  }     
  
  for (std::vector<GraphNode*>::iterator iter = firstTarget->dependentNodes()->begin(); iter != firstTarget->dependentNodes()->end(); ++iter )
    if ( gNode->getName() == ( *iter )-> getName() )
      gNode = (*iter);
	 
  Token colon = reader->getToken();
    
  if( ! colon.isColon() ) {
    std::cout << "Missing colon character on the dependency line.\n";
    exit(1);
  }
  
  // std::cout << "The following file-names depend on the above target.\n";
  Token token;
  
  do {
    token = reader->getToken();
    
    if( token.isName() ){   
    
      GraphNode *gNodeD = new GraphNode( token.getName() );
      
      gNodeD = _tree->find( _tree->getRoot(), gNodeD->getName() );
      //    std::cout << gNodeD->getName() << std::endl;
     
      gNode->addDependentNode( gNodeD );
    
    }  
  } while( token.isName() ) ;
  
  if( ! token.isEOL() ) {
      std::cout << "Dependency line contains a non-name token.\n";
    exit(1);
  }

  token = reader->getToken();
  
  if( ! token.isCommand() ) {
    std::cout << "No command found after dependency line.\n";
    exit(1);
  }
  
  gNode->setCommand( token.getCommand() );

  if( firstTarget != gNode )
    _tree->insert( gNode );

  return token;

}

