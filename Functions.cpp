#include "Functions.h"


void Node::ShowNode(){
  std::cout << value << "-->"; // Show node value
  for(int i = 0; i < connections.size(); i++){ // Show connections node value   
    if(i < connections.size())
      std::cout << connections[i].value << "-->";
    else
      std::cout << connections[i].value;        
  }
  std::cout << std::endl;
}

void Graph::ShowGraph(){
  for(int i = 0; i < Nodes.size(); i++) // Take all nodes and show
    Nodes[i].ShowNode();
}

void Graph::setEdges(){
  Number_Edges++;
}

void Graph::setNodes(Node New_Node){
  Number_Nodes++;
  Nodes.push_back(New_Node);
}

void Graph::Insert_Node(){
  Node new_node;
  setNodes(new_node);
}

void Graph::Insert_Edge(int Node1, int Node2){

}

int Graph::Remove_Node(int Node_Remove){

}

void Graph::Remove_Edge(int Node_Remove){

}