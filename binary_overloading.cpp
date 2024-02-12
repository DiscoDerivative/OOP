#include <iostream>
class Point{
    private:
    int x;
    int y;
    public:
    Point() : x(0), y(0){}
    Point operator+(int constant){
        x += constant;
        y += constant;
        return *this;
    }
    Point operator-(int constant){
        x -= constant;
        y -= constant;
        return *this;
    }
    
    //Prints out coordinates
    void print() const{
        std::cout << "Point " << '(' << x << ',' << y << ')' << '\n';
    }
};

int main(void)
{
    Point obj;
    obj.print();
    obj + 5;
    obj.print();
    obj - 2;
    obj.print();
    return 0;
}
