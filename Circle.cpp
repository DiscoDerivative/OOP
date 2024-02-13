#include <iostream>
class Circle{
    private:
    int radius;
    public:
    Circle() : radius(0){}
    void setRadius(int radius){
        if(radius <= 0){
            std::cout << "Invalid radius: Radius needs to be greater than 0\n";
            *this = Circle();
        }
        else{
           this->radius = radius;         
        }
    }
    int getRadius(){
        return radius;
    }
};

double getArea(Circle& obj){
    return 3.14 * (obj.getRadius() * obj.getRadius());
}

int main(void){
    Circle c1;
    c1.setRadius(4);
    std::cout << "Area: " << getArea(c1);
    return 0;
}
