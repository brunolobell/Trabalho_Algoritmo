#include <iostream>
#include <vector>
#include <map>


class Node{ 
  private:
    int value;
    std::map <Node *, int> connections;
    std::map <int, Node *> Reverse_Connections;

  public:
    Node(int val = 0){ // Default value -- Inicialize in 0
      value = val;
    }

    void ShowNode();

    void setValue(); // Increment default value

    void setConnection(Node* node, int weigth); // Connections with node

    void setReverseConnection(Node* node); // Connections with node

    void RemoveLitterNode(int Node_); // Remove Vertices of Node
    
    int getSizeReverseConnection(); // Take Size of Reverse Connections

    int getSizeConnection(); // Take Size of Connections

    int getValue(); // Return Value Name 

    std::map<Node *,int> getConnections(); // Return Connections
};


class Graph{
  private:
    int Number_Edges;
    int Number_Nodes;
    int Value;
    std::vector <Node> Nodes;
    std::vector <std::vector <int>> Matrix_Adjacent;

  public:
    Graph(int Edges = 0, int Nodes = 0, int Val = 0){ // Default values -- Inicialize in 0
      Number_Edges = Edges;
      Number_Nodes = Nodes;
      Value = Val;
    }

    int getNumber_Edges(){ // Return Number Edges
      return Number_Edges;
    }

    int getNumber_Nodes(){ // Return Number Nodes
      return Number_Nodes;
    }

    void Insert_Node(int n); // Function Insert Node

    void Insert_Edge(int Node1, int choose, char yn); // Function Insert Edge

    void Remove_Node(int Node_Remove); // Function Remove Node

    void Remove_Edge(int Node1,int Node2, int choice); // Function Remove Edge

    void ShowGraph();

    void getFonts(); // Show Fonts

    void getSinks(); // Show Sinks

    void getDegreeNode(int node_); // Retunr Degree of Node

    void BFS(int Node_); // Breadth First Search

    void DFS(int v); // Depth First Search

    void DFSResolution(int Node_, bool * visited); // Recursive Function TOP-DAWN

    void primMST(); // Movimento sem Terra - Prim's Algorithm

    void kruskalMST(); // Movimento sem Terra - Kruskal's Algorithm

    void BellmanFord(int src);
};