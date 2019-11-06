#include <iostream>
#include <vector>


class Node{ 
  private:
    int value;
    std::vector <Node> connections;
  
  public:
    Node(int value = 0){ // Default value -- Inicialize in 0
      value = 0;
    }

    void ShowNode(){
      std::cout << value << "-->"; // Show node value
      for(int i = 0; i < connections.size(); i++){ // Show connections node value   
        if(i < connections.size())
          std::cout << connections[i].value << "-->";
        else
          std::cout << connections[i].value;        
      }
      std::cout << std::endl;
    }

    void setValue(){ // Increment default value
      value++;
    }

    void setConnection(Node node){ // Connections with node
      connections.push_back(node);
    } 
};

class Graph{
  private:
    int Number_Edges;
    int Number_Nodes;
    std::vector <Node> Nodes;

  public:
    Graph(int Number_Edges, int Number_Nodes){ // Default values -- Inicialize in 0
      Number_Edges = 0;
      Number_Nodes = 0;
    }

    void ShowGraph(){ 
      for(int i = 0; i < Nodes.size(); i++) // Take all nodes and show
        Nodes[i].ShowNode();
    }

    void setEdges(){  // Increment Number of Edges
      Number_Edges++;
    }

    void setNodes(){ // Increment Number of Nodes
      Number_Nodes++;
    }
};


void Insert_Node();

void Insert_Edge(int Node1, int Node2);

int Remove_Node(int Node_Remove);

void Remove_Edge(int Node_Remove);

void Show_Graph();