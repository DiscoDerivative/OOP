#include <iostream>
#include <cstring>

class Task{
    private:
    char* description;
    char* deadline;
    int priority;
    bool completionStatus;
    public:
    Task() : description(nullptr), deadline(nullptr), priority(0), completionStatus(false){}
    
    Task(const char* description, const char* deadline, int priority, bool completionStatus){
        
    }
    //Setters
    void setDescription(const char* description){
        if(description == nullptr){
            std::cout << "Invalid description\n";
        }
        else{
            std::strcpy(this->description, description);
        }
    }
    void setDeadline(const char* deadline){
        if(deadline == nullptr){
            std::cout << "Invalid deadline\n";
        }
        else{
            std::strcpy(this->deadline, deadline);
        }
    }
    void setPriority(int priority){
        if(priority < 1 || priority > 3){
            std::cout << "Invalid priorty\n";
        }
        else{
            this->priority = priority;
        }
    }
    void setCompletionStatus(bool completionStatus){
        this->completionStatus = completionStatus;
    }
    //Getters
    const char* getDescription(){
        return description;
    }
    const char* getDeadline(){
        return deadline;
    }
    
    int getPriority(){
        return priority;
    }
    bool getCompletionStatus(){
        return completionStatus;
    }
};

const int MAX_SIZE = 3;

class TaskManager{
    private:
    Task t[MAX_SIZE];
    int taskSize;
    public:
        void addTask(Task& newTask){
            t[taskSize++] = newTask;
            taskSize += 1;
        }
        
    void display(std::ostream& os){
        for(int i = 0; i < taskSize; i++){
            os << "Task Description: " << t[i].getDescription() << '\n';
            os << "Deadline: " << t[i].getDeadline() << '\n';
            os << "Priority level: " << t[i].getPriority() << '\n';
            os << "Completion Status: ";
            if(t[i].getCompletionStatus()){
                os << "Completed" << '\n';
            }
            else{
                os << "Did not complete " << '\n';
            }
        }
    }
  
  Task& init(const Task& src){
        //Handling priority
        if(priority < 1 || priority > 3){
            std::cout << "Invalid priority: Must be between 1 and 3 (inclusive)\n";
        }
        else{
            this->priority = priority;
        }
        
        //Handling completion status
        this->completionStatus = completionStatus;
        
        //Handling description
        if(description == nullptr){
            std::cout << "Invalid description\n";
            *this = Task();
        }
        else{
            this->description = new char[std::strlen(description) + 1];
            std::strcpy(this->description, description);
        }
        
        //Handling deadline
        if(deadline == nullptr){
            std::cout << "Invalid deadline given.\n";
        }
        else{
            this->deadline = new char[std::strlen(deadline) + 1];
            std::strcpy(this->deadline, deadline);
        }
    }
    
    Task(const Task& src){
        init(src);
    }
    
    Task& operator=(const Task& src){
        if(this != &src){
            delete [] description;
            delete [] deadline;
            init(src);
        }
        else{
            return *this;
        }
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Task& temp){
        for(int i = 0; i < 3; i++)
        {
            temp[i].display(os);
        }
        return os;
    }
};
