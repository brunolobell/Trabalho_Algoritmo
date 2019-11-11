#include <iostream>
#include <vector>


class Node{ 
  private:
    int value;
    std::vector <Node> connections;
  
  public:
    Node(int val = 0){ // Default value -- Inicialize in 0
      value = val;
    }

    void ShowNode();

    void setValue(); // Increment default value

    void setConnection(Node node); // Connections with node 
};

class Graph{
  private:
    int Number_Edges;
    int Number_Nodes;
    std::vector <Node> Nodes;
    std::vector <std::vector <int>> Matrix_Adjacent;

  public:
    Graph(int Edges = 0, int Nodes = 0){ // Default values -- Inicialize in 0
      Number_Edges = Edges;
      Number_Nodes = Nodes;
    }

    int getNumber_Edges(){ // Return Number Edges
      return Number_Edges;
    }

    int getNumber_Nodes(){ // Return Number Nodes
      return Number_Nodes;
    }

    void Insert_Node(); // Function Insert Node

    void Insert_Edge(int Node1, int Node2); // Function Insert Edge

    int Remove_Node(int Node_Remove); // Function Remove Node

    void Remove_Edge(int Node_Remove); // Function Remove Edge

    void ShowGraph();    
};