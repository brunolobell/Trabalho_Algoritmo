#include "Functions.h"


void Node::ShowNode(){ 
  std::cout << value << "-->"; // Show node value
  for(int i = 0; i < connections.size(); i++){ // Show connections node value   
    if(i < connections.size() - 1)
      std::cout << connections[i].value << " --> ";
    else
      std::cout << connections[i].value << " /";        
  }
  std::cout << std::endl;
}

void Node::setValue(){
  value++;
}

void Node::setConnection(Node node){ // Connections with node
  connections.push_back(node);
}

void Graph::ShowGraph(){
  std::cout << "List of Adjacent" << std::endl;
  for(int i = 0; i < Number_Nodes; i++) // Take all nodes and show
    Nodes[i].ShowNode();
  std::cout << std::endl;

  std::cout << "Matrix of Adjacent" << std::endl;
  for(int i = 0; i < Number_Nodes; i++){
    for(int j = 0; j < Number_Nodes; i++)
      std::cout << Matrix_Adjacent[i][j] << "\t";
    std::cout << std::endl;
  }
}

void Graph::Insert_Node(){
  Node new_node; // Object Node 
  Number_Nodes++; // Add Number Nodes
  Nodes.push_back(new_node); // Add New Node in Vector of Nodes
  for(int i = 0; i < Number_Nodes; i++)
    for(int j = 0; j < Number_Nodes; j++){
      Matrix_Adjacent.resize(Number_Nodes);
      Matrix_Adjacent[i].resize(Number_Nodes); // Insert 0 in Matrix positions
    }
}

void Graph::Insert_Edge(int Node1, int Node2){
  Number_Edges++;
  if(Number_Nodes >= Node1 && Number_Nodes >= Node2){
    Nodes[Node1].setConnection(Nodes[Node2]);
    Matrix_Adjacent[Node1][Node2] = 1;
  }
}

int Graph::Remove_Node(int Node_Remove){

}

void Graph::Remove_Edge(int Node_Remove){

}