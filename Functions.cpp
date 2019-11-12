#include "Functions.h"


void Node::ShowNode(){ 
  std::cout << value << " --> "; // Show node value
  for(int i = 0; i < connections.size(); i++){ // Show connections node value   
    if(i < connections.size() - 1)
      std::cout << connections[i].value << " --> ";
    else
      std::cout << connections[i].value << " --> /";        
  }
  if(connections.size() < 1)
    std::cout << " /";
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
  for(int i = 0; i < Number_Nodes; i++){ // Create a Matrix of Adjacent
    Matrix_Adjacent.resize(Number_Nodes); // Memory Allocation for Size of Number_Nodes 
    Matrix_Adjacent[i].resize(Number_Nodes); // Vector Allocation for Size of Number_Nodes
  }
}

void Graph::Insert_Edge(int Node1, int Node2){
  ++Number_Edges; //Increment Number_Edges
  if(Number_Nodes >= Node1 && Number_Nodes >= Node2){ //If Node1 or Node2 > Number_Nodes
    Nodes[Node1-1].setConnection(Nodes[Node2-1]); // Add Connection Node2 on Node1 in List Adjacent
    Matrix_Adjacent[Node1-1][Node2-1] = 1; // Add Connection Node2 on Node1 in Matrix Adjacent
  }
}

int Graph::Remove_Node(int Node_Remove){
  --Number_Nodes; //Reduces Number_Nodes
  Nodes.erase(Nodes.begin()+Node_Remove-1); //Remove Node in position Node_Remove
  Matrix_Adjacent.erase(Matrix_Adjacent.begin()+Node_Remove-1); //Remove Line Number Node_Remove 
  for(int i = 0; i < Number_Nodes; i++) //Remove Column Number Node_Remove
    Matrix_Adjacent[i].erase(Matrix_Adjacent[i].begin()+Node_Remove-1);
}

void Graph::Remove_Edge(int Edge_Remove){

}