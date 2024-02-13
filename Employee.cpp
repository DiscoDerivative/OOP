#include <iostream>
#include <cstring>

class Employee{
    private:
    char* name;
    int id;
    double salary;
    public:
    Employee() : id(0), salary(0.0), name(nullptr){}
    Employee(const char* name, int id, double salary){
        //Validating id
        if(id < 0){
            std::cout << "Invalid given id. Setting object to default...\n";
            *this = Employee();
        }
        else{
            this->id = id;
        }
        
        if(salary < 0.0){
            std::cout<< "Invalid given salary. Setting object to default...\n";
            *this = Employee();
        }
        else{
            this->salary = salary;
        }
        if (name == nullptr){
            std::cout << "Invalid given name. Setting object to default...\n";
            *this = Employee();
        }
        else{
            this->name = new char[std::strlen(name) + 1];
            if(this->name == nullptr){
                std::cout << "Memory not allocated for employee name.\n";
            }
            else{
                std::strcpy(this->name, name);
            }
        }
    }
    void init(const Employee& src){
        id = src.id;
        salary = src.salary;
        
        if(src.name == nullptr){
            name = nullptr;
        }
        else{
            std::strcpy(name, src.name);
        }
    }
    Employee(const Employee& src){
        init(src);
    }
    Employee operator=(const Employee& src){
        //check for self-assignment
        if(this == &src){
            return *this;
        }
        else{
            //deallocate prev mem
            delete [] name;
            init(src);
        }
        return *this;
    }
    void display(std::ostream& os) const{
        os << "Employee ID: " << id << '\n';
        os << "Name: " << name << '\n';
        os << "Salary: $" << salary << "\n\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const Employee& emp){
        emp.display(os);
        return os;
    }
    void setSalary(double salary){
        this->salary = salary;
    }
    
    double getSalary() const{
        return salary;
    }
};

void increaseSalary(Employee& emp){
    //Increasing the salary by a specified percentage (5%)
    emp.setSalary(emp.getSalary() * 1.05);
}

int main(void){
    Employee e1("John Howard", 1, 55000.00);
    Employee e2("Lucy Smith", 2, 49000.00);
    std::cout << e1;
    std::cout << e2;
    increaseSalary(e2);
    std::cout << e2;
}
