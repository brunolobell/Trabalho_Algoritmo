#include <iostream>
#include <vector>
#include "Functions.h"


int main(int argc, char const *argv[])
{
  Graph Graph_;
  int x,y, case_,Count = 0;
  while(case_ != 0){
    std::cout << "Escolha: (1 - Insert Node, 2 - Insert Edge, 3 - Remove Node, 4 - Remove Edge, 5 - Show Graph, 0 - Exit)" << std::endl;
    std::cin >> case_;
    switch (case_)
    {
      case 1:
        Graph_.Insert_Node(); 
        break;

      case 2:
        std::cin >> x >> y;
        Graph_.Insert_Edge(x, y);
        break;

      case 3:
        std::cin >> x;
        Graph_.Remove_Node(x);
        break;
      
      case 4:
        std::cin >> x >> y;
        Graph_.Remove_Edge(x,y);
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

      default:
        break;
    }
  }
  return 0;
}