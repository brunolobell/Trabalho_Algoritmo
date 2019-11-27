#include <iostream>
#include <vector>
#include "Functions.h"


int main(int argc, char const *argv[])
{
  Graph Graph_;
  int x,y, case_ = 1, choice, weight;
  char yn;

  std::cout << "Weight? y/n ";
  std::cin >> yn;

  std::cout << "1 - Directed Graph \t 2 - Undirected Graph\n";
  std::cin >> choice;

  while(case_ != 0){
    std::cout << "Choose: (1 - Insert Node, 2 - Insert Edge, 3 - Remove Node, 4 - Remove Edge, 5 - Show Graph, 6 - Return Fonts, 7 - Return Sinks, 8 - Calculate Degrees, 9 - BFS, 10 - DFS, 11 - Prim, 12 - Kruskal, 0 - Exit)" << std::endl;
    std::cin >> case_;
    switch (case_)
    {
      case 1:
        std::cout << "Number of Nodes: ";
        std::cin >> x;
        Graph_.Insert_Node(x); 
        break;

      case 2:
        std::cout << "Choice Node For Connections: "; 
        std::cin >> x;
        Graph_.Insert_Edge(x, choice,yn);
        break;

      case 3:
        std::cin >> x;
        Graph_.Remove_Node(x);
        break;
      
      case 4:
        std::cin >> x >> y;
        Graph_.Remove_Edge(x,y,choice);
        break;
      
      case 5:
        Graph_.ShowGraph();  
        break;

      case 6:
        Graph_.getFonts();
        break;
      
      case 7:
        Graph_.getSinks();
        break;

      case 8:
        std::cout << "Node: ";
        std::cin >> x;
        Graph_.getDegreeNode(x);
        break;

      case 9:
        std::cout << "Start Node :";
        std::cin >> x;
        Graph_.BFS(x);
        break;

      case 10:
        std::cout << "Start Node :";
        std::cin >> x;
        Graph_.DFS(x);
        break;

      case 11:
        Graph_.primMST();
        break;

      case 12:
        Graph_.kruskalMST();
        break;

      default:
        break;
    }
  }
  return 0;
}