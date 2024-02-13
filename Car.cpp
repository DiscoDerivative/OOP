#include <iostream>
#include <cstring>

class Car{
    private:
    char* make;
    char* model;
    int year;
    public:
    Car() : year(2024), make(nullptr), model(nullptr){}
    Car(const char* make, const char* model, int year)
    {
        //Validating year
        if(year < 1885 || year > 2024)
        {
            *this = Car();
        }
        else
        {
            this->year = year;
        }
        
        //Validating model
        if(model == nullptr || std::strcmp(model, "") == 0)
        {
            std::cout << "Invalid given model\n";
        }
        else
        {
            this->model = new char[std::strlen(model) + 1];
            if(this->model == nullptr)
            {
                std::cout << "Memory not allocated for model.\n";
            }
            else
            {
                std::strcpy(this->model, model);
            }
        }
        
        //Validating make of car
        if(make == nullptr || std::strcmp(make, "") == 0)
        {
            std::cout << "Invalid given make\n";
        }
        else
        {
            this->make = new char[std::strlen(make) + 1];
            if(this->make == nullptr)
            {
                std::cout << "Memory not allocated for make.\n";
            }
            else
            {
                std::strcpy(this->make, make);
            }
        }
    }
    Car(const Car& src){
        year = src.year;
        
        if(src.make != nullptr)
        {
            make = new char[std::strlen(src.make) + 1];
            std::strcpy(make, src.make);
        }
        else
        {
            make = nullptr;
        }
        
        if(src.model != nullptr)
        {
            model = new char[std::strlen(src.model) + 1];
            std::strcpy(model, src.model);
        }
        else
        {
            model = nullptr;
        }
    }
    Car& operator=(const Car& src){
        // check for self-assignment
        if (this != &src)
        {
            // shallow copy non-resource variables
            year = src.year;
            // deallocate previously allocated dynamic memory
            delete [] model;
            delete [] make;
            // allocate new dynamic memory, if needed
            if(src.model != nullptr)
            {
                // copy the resource data
                model = new char[std::strlen(model) + 1];
                std::strcpy(model, src.model);
                
                make = new char[std::strlen(model) + 1];
                std::strcpy(make, src.make);
            }
        }
        else
        {
            model = nullptr;
            make = nullptr;
        }
        return *this;
    }
    ~Car(){
        delete [] make;
        delete [] model;
    }
    void displayDetails()
    {
        std::cout << year << ' ' << make << ' ' << model << '\n';
    }
};

int main(void)
{
    //Copy constructor usage
    Car c1("Toyota", "Camry", 2016);
    std::cout << "Value of car 1: ";
    c1.displayDetails();
    std::cout << "Copying car 1 into car 2: ";
    Car c2 = c1;
    c2.displayDetails();
    
    //Copy assignment operator usage
    Car c3("Audi", "A4", 2018);
    std::cout << "Original value of car 3: ";
    c3.displayDetails();
    std::cout << "Car 1 being copied into car 3: ";
    c3 = c1;
    c3.displayDetails();
    
    return 0;
}
