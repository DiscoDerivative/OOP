class TrafficLight
{
    private:
    bool isGreen;
    public:
    //Sets traffic light to red by default
    TrafficLight() : isGreen(false){}
    //Equals the opposite
    void change()
    {
        isGreen = !(isGreen);
    }
    //Returns true if trafic light is green and false if its not
    operator bool () const
    {
        if(isGreen == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#include <iostream>
int main(void)
{
    TrafficLight l1;
    if(l1)
    {
        std::cout << "The traffic light is green.\n";
    }
    else
    {
        std::cout << "The traffic light is red.\n";
    }
    
    l1.change();
    
    if(l1)
    {
        std::cout << "The traffic light is green.\n";
    }
    else
    {
        std::cout << "The traffic light is red.\n";
    }
    return 0;
}
