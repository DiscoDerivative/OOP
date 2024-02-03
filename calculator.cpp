// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    int option = 0;
    int done = 0;
    int x = 0;
    int y = 0;
    
    std::cout << "Calculator Program\n";
    std::cout << "------------------\n\n";
    
    while((option != 5) && (done != 1)){
      std::cout << "Menu\n";
      std::cout << "1. Add\n";
      std::cout << "2. Subtract\n";
      std::cout << "3. Multiply\n";
      std::cout << "4. Divide\n";
      std::cout << "5. Quit\n\n";
      std::cout << "Please enter your option: ";
      std::cin >> option;
      
      if(option > 5 || option < 1){
             std::cout << "ERROR: Invalid option";
             return 1;
         }
      
      if(option == 5){
          done = 1;
          std::cout << "Quitting.";
          return 2;
      }
      
      std::cout << "Enter first number: ";
      std::cin >> x;
      std::cout << "Enter second number: ";
      std::cin >> y;
      std::cout << "Result: ";
      
      if(option == 1){
        std::cout << x + y;
      }
      else if(option == 2){
        std::cout << x - y;
      }
      else if(option == 3){
        std::cout << x * y;
      }
      else if(option == 4){
        std::cout << x / y;
      }
      std::cout << "\n\n";
    }
    return 0;
}
