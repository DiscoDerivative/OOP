#include <iostream>

class Counter{
  private:
  int counter;
  public:
  //Intializing counter to 0
  Counter() : counter(0) {};

  //Pre-fix operator overloading
  void operator++()
  {
    ++counter;
  }

  void operator--()
  {
    --counter;
  }

  //Post-fix operator overloading
  void operator++(int)
  {
    counter++;
  }

  void operator--(int)
  {
    counter--;
  }

  int getCounter()
  {
    return counter;
  }
};


//Main function
int main(void)
{
  Counter c1, c2, c3, c4;
  
  //Prefix
  ++c1;
  std::cout << "C1: " << c1.getCounter() << '\n';

  ++c2;
  --c2;
  std::cout << "C2: " << c2.getCounter() << '\n';

  c3++;
  std::cout << "C3: " << c3.getCounter() << '\n';
  
  c4++;
  c4--;
  std::cout << "C4: " << c4.getCounter() << '\n';
  
  return 0;
}
