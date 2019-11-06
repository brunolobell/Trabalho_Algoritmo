#include <iostream>
#include <vector>
#include "Functions.h"


int main(int argc, char const *argv[])
{
  Graph Graph_;
  int case_,Count = 0;
  for(;;){
    std::cout << "Escolha um seu merda: " << std::endl;
    std::cin >> case_;
    switch (case_)
    {
      case 1:
        Graph_.Insert_Node(); 
        break;

      case 2:
          
        break;

      case 3:
          
        break;
      
      case 4:
          
        break;
      
      case 5:
        Graph_.ShowGraph();  
        break;

      default:
        break;
    }
  }
  return 0;
}