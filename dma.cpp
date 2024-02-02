//This code file is an overview of using dynamic memory allocation

#include <iostream>
#include <cstring>

int main(void)
{
  //Using a constant pointer to represent a string literal for my name
  const char* myName = "Margaret";

  //This size will be used instead of a hard coded value when allocating memory for the pointer to my name
  const int size = std::strlen(myName) + 1;
  
  //This dynamic char array is better than static
  char* nameBuffer = new char[size];

  //Error handling for failed memory allocation
  if(nameBuffer == nullptr)
  {
    std::cout << "Memory is not allocated for the name." << std::endl;
  }
  else
  {
    //I want the pointer to my name to hold the value of my name
      std::strcpy(nameBuffer, myName);

    //Tests to see if my name is correctly printed out
      std::cout << "My name is: " << nameBuffer << std::endl;
  }
  //Deallocating memory
  delete [] nameBuffer;

  //If this program works, it will return a 0.
  return 0;
}
