#include <cstring>
#include <iostream>

class Task{
    private:
    char* description;
    int priorityLevel;
    bool completionStatus;
    public:
    Task() : priorityLevel(0), completionStatus(false){
        description = nullptr;
    }
    ~Task(){
        delete [] description;
    }
    
    void setDescription(const char* desc){
        description = new char[std::strlen(desc) + 1];
        if(description == nullptr)
        {
            std::cout << "Memory was not allocated.\n";
        }
        else
        {
            std::strcpy(description, desc);
        }
    }
    void setPriorityLevel(int priority)
    {
        priorityLevel = priority;
    }
    void setCompletionStatus(bool status)
    {
        completionStatus = status;
    }
    operator bool() const{
        if (completionStatus == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(void)
{
    Task waterPlants;
    //Setting up data for task 1
    waterPlants.setDescription("Water plants today.");
    waterPlants.setPriorityLevel(1);
    waterPlants.setCompletionStatus(false);
    
    if(waterPlants){
        std::cout << "You watered your plants today!.\n";
    }
    else
    {
        std::cout << "You did not water your plants.\n";
    }
    
    waterPlants.setCompletionStatus(true);
    
    if(waterPlants)
    {
        std::cout << "You watered your plants today!.\n";
    }
    else
    {
        std::cout << "You did not water your plants.\n";
    }
}
