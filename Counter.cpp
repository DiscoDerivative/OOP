class Counter{
    private:
    int count;
    public:
    Counter() : count(0){}
    Counter& operator++(){
        count += 1;
        return *this;
    }
    int getCount() const{
        return count;
    }
};

#include <iostream>
int main(void){
    Counter c1;
    ++c1;
    std::cout << "Counter value: " << c1.getCount();
    return 0;
}
