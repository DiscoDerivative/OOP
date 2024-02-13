//Test.h

#ifndef TEST_H
#define TEST_H

#include <iostream>

class Test{
  private:
  int num;
  public:
  Test();
  Test(int num);
  void setNum(int num);
  int getNum();
  friend std::ostream& operator<<(std::ostream& os, const Test& t);
};

#endif

//Test.cpp
  #include "Test.h"

  Test::Test() : num(0){}

  Test::Test(int num){
    //No validation necessary
      this->num = num;
  }

  void Test::setNum(int num){
    this->num = num;
  }

  int Test::getNum(){
    return num;
  }
  
  std::ostream& operator<<(std::ostream& os, const Test& t){
    os << "Value of the number: " << t.num << "\n\n";
    return os;
  }

//main.cpp

#include "Test.h"

int main(void){
  Test t1(3), t2(29), t3(458), t4(-1);
  std::cout << t1 << t2 << t3 << t4;
}
