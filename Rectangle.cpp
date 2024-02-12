#include <iostream>
class Rectangle{
    private:
    int length;
    int width;
    public:
    Rectangle() : length(0), width(0){}
    Rectangle(int length, int width){
        if(length <= 0 || width <= 0){
            //Assigns the default values to the current object
            *this = Rectangle();
        }
        else{
            this->length = length;
            this->width = width;          
        }
    }
    //Returns the area of the dimensions specified
    int calculateArea(){
        return length * width;
    }
    //Displays area of valid rectangle dimensions
    void displayArea(){
        if (length <= 0 || width <= 0)
        {
            std::cout << "Invalid dimensions: length and width must be greater than 0.\n";
        }
        else
        {
                        std::cout << "Area: " << this->calculateArea() << '\n';
        }
    }
};

int main(void){
    //Creating four objects to test out the validation
    Rectangle r1(5, 3), r2(0, 0), r3(0, 3), r4(4, 0);
    r1.displayArea();
    r2.displayArea();
    r3.displayArea();
    r4.displayArea();
    return 0;
}
