#include "Functions.h"


void Node::ShowNode(){ 
  std::cout << value << " --> "; // Show node value
  for(int i = 0; i < connections.size(); i++){ // Show connections node value   
    if(i < connections.size() - 1)
      std::cout << connections[i]->value << " --> ";
    else
      std::cout << connections[i]->value << " --> /";        
  }
  if(connections.size() < 1)  // None Node
    std::cout << " /";
  std::cout << std::endl;
}

void Node::setValue(){
  value++;
}

void Node::setConnection(Node* node){ // Connections with node
  connections.push_back(node);
}

int Node::getValue(){ 
  return value;
}

void Node::RemoveLitterNode(int Node_){ // Remove Node of Adjacent List
  int position = 0;
  for(int i = 0; connections[i]->getValue() != Node_ && i < connections.size(); i++) // Take Posion Node
    ++position; 

  connections.erase(connections.begin()+position); // Remove Node
}

int Node::getSizeConnection(){ // Return Number of Connections
  return connections.size();
}

int Node::getSizeReverseConnection(){ // Return Number of Connections in Node
  return Reverse_Connections.size();
}

void Graph::ShowGraph(){
  std::cout << "List of Adjacent" << std::endl;
  for(int i = 0; i < Number_Nodes; i++) // Take all nodes and show
    Nodes[i].ShowNode();
  std::cout << std::endl;

  std::cout << "Matrix of Adjacent" << std::endl;
  for(int i = 0; i < Number_Nodes; i++){ // Show Matrix of Adjacent
    for(int j = 0; j < Number_Nodes; j++)
      std::cout << Matrix_Adjacent[i][j] << "\t";
    std::cout << std::endl;
  }
}

void Graph::Insert_Node(){
  Node new_node(++Value); // Object Node 
  Nodes.push_back(new_node); // Add New Node in Vector of Nodes
  ++Number_Nodes;
  for(int i = 0; i < Number_Nodes; i++){ // Create a Adjacency List
    Matrix_Adjacent.resize(Number_Nodes); // Memory Allocation for Size of Number_Nodes 
    Matrix_Adjacent[i].resize(Number_Nodes); // Vector Allocation for Size of Number_Nodes
  }
}

void Graph::Insert_Edge(int Node1, int Node2){
  ++Number_Edges; //Increment Number_Edges
  if(Number_Nodes >= Node1 && Number_Nodes >= Node2){ //If Node1 or Node2 > Number_Nodes
    Nodes[Node1-1].setConnection(&Nodes[Node2-1]); // Add Connection Node2 on Node1 in List Adjacent
    Matrix_Adjacent[Node1-1][Node2-1] = 1; // Add Connection Node2 on Node1 in Matrix Adjacent
    //Nodes[Node2-1].setReverseConnection(Node1-1); // Add Reverse Connection Node1 in Node2
  }
}

void Graph::Remove_Node(int Node_Remove){
  int Position_Node_Remove;

  for(int i = 0; i < Nodes.size(); i++) // Find Value 'Node_Value' in Vector Nodes
    if(Node_Remove == Nodes[i].getValue())
      Position_Node_Remove = i;

  --Number_Nodes; //Reduces Number_Nodes
  Nodes.erase(Nodes.begin()+Position_Node_Remove); //Remove Node in position Node_Remove
  
  Matrix_Adjacent.erase(Matrix_Adjacent.begin()+Position_Node_Remove); //Remove Line Number Node_Remove 
  for(int i = 0; i < Number_Nodes; i++){ //Remove Column Number Node_Remove
    Matrix_Adjacent[i].erase(Matrix_Adjacent[i].begin()+Position_Node_Remove);
  }
}

void Graph::Remove_Edge(int Node1, int Node2){
  int Position_Node;

  for(int i = 0; i < Nodes.size(); i++) // Find Value 'Node_Value' in Vector Nodes
    if(Node1 == Nodes[i].getValue()){
      Position_Node = i;
      break;
    }

  Matrix_Adjacent[Position_Node][Node2-1] = 0; // Add 0 in Position [Node1][Node2]

  Nodes[Position_Node].RemoveLitterNode(Node2); // Remove Node Of Adjacent List
}

void Graph::getFonts(){
  std::vector <int> Fonts;

  for(int i = 0; i < Nodes.size(); i++)
    if(Nodes[i].getSizeReverseConnection() == 0 && Nodes[i].getSizeConnection() > 0)
      Fonts.push_back(i);

  for(int i = 0; i < Fonts.size(); i++)
    std::cout << Fonts[i] << "\t";
}

void Graph::getSinks(){
  std::vector <int> Sinks;

  for(int i = 0; i < Nodes.size(); i++)
    if(Nodes[i].getSizeConnection() == 0 && Nodes[i].getSizeReverseConnection() > 0)
      Sinks.push_back(i);

  for(int i = 0; i < Sinks.size(); i++)
    std::cout << Sinks[i] << "\t";
}