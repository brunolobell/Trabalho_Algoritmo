#include <list>
#include <queue>
#include "Functions.h"

#define iPair pair<int, int>
#define INT_MAX 2147483647


void Node::ShowNode(){ 
  std::cout << value << " --> "; // Show node value
  
  for(auto it = connections.begin(); it != connections.end(); ++it){ // Show connections node value   
    std::cout << it->first->getValue() << " --> ";
  }

  std::cout << " /" << std::endl;
}

void Node::setValue(){
  value++;
}

void Node::setConnection(Node* node, int weigth){ // Connections with node
  connections.insert(std::pair<Node *, int>(node, weigth));
}

void Node::setReverseConnection(Node* node){ // Connections with node
  Reverse_Connections.insert(std::pair<int, Node *>(value, node));
}

int Node::getValue(){ 
  return value;
}

void Node::RemoveLitterNode(int Node_){ // Remove Node of Adjacent List
  for(auto el : connections){
    if(Node_ == el.first->getValue())
      connections.erase(el.first); // Remove Node
  }
}

int Node::getSizeConnection(){ // Return Number of Connections
  return connections.size();
}

int Node::getSizeReverseConnection(){ // Return Number of Connections in Node
  return Reverse_Connections.size();
}

std::map<Node *,int> Node::getConnections(){
  return connections;
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

void Graph::Insert_Node(int n){
  for(int i = 0; i < n; i++){
    Node new_node(++Value); // Object Node 
    Nodes.push_back(new_node); // Add New Node in Vector of Nodes
    ++Number_Nodes;
    for(int i = 0; i < Number_Nodes; i++){ // Create a Adjacency List
      Matrix_Adjacent.resize(Number_Nodes); // Memory Allocation for Size of Number_Nodes 
      Matrix_Adjacent[i].resize(Number_Nodes); // Vector Allocation for Size of Number_Nodes
    }
  }

  std::cout << Nodes[Value].getValue() << std::endl;
}

void Graph::Insert_Edge(int Node1, int choose, char yn){
  int Position_Node1, Position_Node2, Node2;
  int weigth = 1;

  std::cout << "0 for Exit" << std::endl;

  while(std::cin >> Node2 && Node2 != 0){
    ++Number_Edges; //Increment Number_Edges

    for(int i = 0; i < Nodes.size(); i++){ // Find Value 'Node_Value' in Vector Nodes
      if(Node1 == Nodes[i].getValue())
        Position_Node1 = i;
      
      if(Node2 == Nodes[i].getValue())
        Position_Node2 = i;
    }

    if(yn == 'y'){
      std::cout << "Weigth: ";
      std::cin >> weigth;
    }
    
    if(Number_Nodes >= Node1 && Number_Nodes >= Node2 && choose == 1){ //If Node1 or Node2 > Number_Nodes
      Nodes[Position_Node1].setConnection(&Nodes[Position_Node2], weigth); // Add Connection Node2 on Node1 in List Adjacent
      Nodes[Position_Node2].setReverseConnection(&Nodes[Position_Node1]); // Add Reverse Connection Node1 in Node2

      Matrix_Adjacent[Position_Node1][Position_Node2] = weigth; // Add Connection Node2 on Node1 in Matrix Adjacent
    }

    if(Number_Nodes >= Node1 && Number_Nodes >= Node2 && choose == 2){ //If Node1 or Node2 > Number_Nodes
      Nodes[Position_Node1].setConnection(&Nodes[Position_Node2],weigth); // Add Connection Node2 on Node1 in List Adjacent
      Nodes[Position_Node2].setConnection(&Nodes[Position_Node1],weigth); // Add Reverse Connection Node1 in Node2
      Nodes[Position_Node2].setReverseConnection(&Nodes[Position_Node1]); // Add Reverse Connection Node1 in Node2
      Nodes[Position_Node1].setReverseConnection(&Nodes[Position_Node2]); // Add Reverse Connection Node2 in Node1

      Matrix_Adjacent[Position_Node1][Node2-1] = weigth; // Add Connection Node2 on Node1 in Matrix Adjacent
      Matrix_Adjacent[Position_Node2][Node1-1] = weigth; // Add Connection Node1 on Node2 in Matrix Adjacent
    }
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

void Graph::Remove_Edge(int Node1, int Node2, int choice){
  int Position_Node;

  for(int i = 0; i < Nodes.size(); i++) // Find Value 'Node_Value' in Vector Nodes
    if(Node1 == Nodes[i].getValue()){
      Position_Node = i;
      break;
    }

  Matrix_Adjacent[Position_Node][Node2-1] = 0; // Add 0 in Position [Node1][Node2]
  Nodes[Position_Node].RemoveLitterNode(Node2); // Remove Node Of Adjacent List

  if(choice == 2){
    for(int i = 0; i < Nodes.size(); i++) // Find Value 'Node_Value' in Vector Nodes
    if(Node2 == Nodes[i].getValue()){
      Position_Node = i;
      break;
    }

    Matrix_Adjacent[Position_Node][Node1-1] = 0;
    Nodes[Position_Node].RemoveLitterNode(Node1);
  }
}

void Graph::getFonts(){ // Return All Fonts 
  std::vector <int> Fonts;

  for(int i = 0; i < Nodes.size(); i++) // Search for Nodes That Are Sources 
    if(Nodes[i].getSizeReverseConnection() == 0 && Nodes[i].getSizeConnection() > 0)
      Fonts.push_back(Nodes[i].getValue());

  std::cout << "Fonts: ";
  for(int i = 0; i < Fonts.size(); i++){ // Show Sources 
    if(Fonts.size() > 1 && i < Fonts.size()-1)
      std::cout << Fonts[i] << " ";
    
    else
      std::cout << Fonts[i];
  }

  if(Fonts.size() > 0)
    std::cout << std::endl;
  
  else
    std::cout << "Empty" << std::endl;  
}

void Graph::getSinks(){ // Return All Sinks 
  std::vector <int> Sinks;

  for(int i = 0; i < Nodes.size(); i++) // Search for Nodes That Are Sinks
    if(Nodes[i].getSizeConnection() == 0 && Nodes[i].getSizeReverseConnection() > 0)
      Sinks.push_back(Nodes[i].getValue());

  std::cout << "Sinks: ";
  for(int i = 0; i < Sinks.size(); i++){ // Show Sinks
    if(Sinks.size() > 1 && i < Sinks.size()-1)
      std::cout << Sinks[i] << " ";
    
    else
      std::cout << Sinks[i];    
  }

  if(Sinks.size() > 0)
    std::cout << std::endl;
  
  else
    std::cout << "Empty" << std::endl;
}

void Graph::getDegreeNode(int node_){
  int Position_Node;
  
  for(int i = 0; i < Nodes.size(); i++) // Find Value 'Node_Value' in Vector Nodes
    if(node_ == Nodes[i].getValue())
      Position_Node = i;

  std::cout << "Entry Degree: " << Nodes[Position_Node].getSizeConnection() << std::endl;
  std::cout << "Output Degree: " << Nodes[Position_Node].getSizeReverseConnection() << std::endl;
}

void Graph::BFS(int Node_){ // Breadth First Search  
  std::vector <bool> visited; // Create vector Visited
  for(int i = 0; i < Number_Nodes; i++) // False all Visited
    visited.push_back(false);
  std::list <int> queue; // Queue for add Visiteds

  visited[Node_] = true; // Position Node_ Visited
  queue.push_back(Node_); // Add Node_ in queue

  while(!queue.empty()){ 
    Node_ = queue.front(); // Take the Visited
    std::cout << Node_ << " ";
    queue.pop_front(); // Queue Remove

    for(auto el : Nodes[Node_-1].getConnections()){ // el is Element in Connections
      if(!visited[el.first->getValue()]){ // Not Visited Element Value 
        visited[el.first->getValue()] = true; // Position Element Value in Visited True
        queue.push_back(el.first->getValue()); // Add Element Value in queue
      }
    }  
  }
  std::cout << std::endl;  
}

void Graph::DFS(int v){ // Detph First Search
  bool *visited = new bool[Number_Nodes];
  for(int i = 0; i < Number_Nodes; i++) // Set all postions with false
    visited[i] = false;

  DFSResolution(v, visited);
}

void Graph::DFSResolution(int Node_, bool * visited){
  visited[Node_] = true;
  std::cout << Node_ << " ";

  for(auto el : Nodes[Node_-1].getConnections()) // el is element of connections
    if(!visited[el.first->getValue()])
      DFSResolution(el.first->getValue(), visited);
}

bool isValidEdge(int u, int v, std::vector<bool> inMST) 
{ 
   if (u == v) 
       return false; 
   if (inMST[u] == false && inMST[v] == false) 
        return false; 
   else if (inMST[u] == true && inMST[v] == true) 
        return false; 
   return true; 
} 

void Graph::primMST(){
  std::vector <std::vector <int>> Matrix;
  std::vector <bool> inMST(Number_Nodes, false);
  int edge_count = 0, mincost = 0;
  int a,b, min;

  Matrix = Matrix_Adjacent;

  for(int i = 0; i < Number_Nodes; i++)
    for(int j = 0; j < Number_Nodes; j++)
      if(Matrix[i][j] == 0)
        Matrix[i][j] = INT_MAX;

  inMST[0] = true;

  while (edge_count < Number_Nodes - 1) { 
  
        // Find minimum weight valid edge.   
        min = INT_MAX;
        a = -1;
        b = -1;
        for (int i = 0; i < Number_Nodes; i++) { 
            for (int j = 0; j < Number_Nodes; j++) {                
                if (Matrix[i][j] < min) { 
                    if (isValidEdge(i, j, inMST)) { 
                        min = Matrix[i][j]; 
                        a = i; 
                        b = j; 
                    } 
                } 
            } 
        } 
        if (a != -1 && b != -1) { 
            printf("(%d, %d) cost: %d \n", a+1, b+1, min); 
            ++edge_count;
            mincost = mincost + min; 
            inMST[b] = inMST[a] = true; 
        } 
    } 
    printf("\n Minimum cost= %d \n", mincost);

}

int find(int i, int* parent){
  while (parent[i] != i) 
    i = parent[i]; 
  return i; 
}

void union1(int i, int j, int* parent) 
{ 
    int a = find(i,parent); 
    int b = find(j,parent); 
    parent[a] = b; 
} 

void Graph::kruskalMST(){ 
    int mincost = 0; // Cost of min MST. 
    int V = Number_Nodes;
    int *parent = new int[Number_Nodes];

    std::vector<std::vector<int>> cost;
    cost = Matrix_Adjacent;

    for(int i = 0; i < Number_Nodes; i++)
    for(int j = 0; j < Number_Nodes; j++)
      if(cost[i][j] == 0)
        cost[i][j] = INT_MAX;

    // Initialize sets of disjoint sets. 
    for (int i = 0; i < V; i++) 
      parent[i] = i; 
  
    // Include minimum weight edges one by one 
    int edge_count = 0; 
    while (edge_count < V - 1) { 
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (find(i,parent) != find(j, parent) && cost[i][j] < min) { 
                    min = cost[i][j]; 
                    a = i; 
                    b = j; 
                } 
            } 
        } 
  
        union1(a, b, parent); 
        printf("(%d, %d) cost:%d \n", a+1, b+1, min);
        ++edge_count;
        mincost += min; 
    } 
    printf("\n Minimum cost= %d \n", mincost); 
} 