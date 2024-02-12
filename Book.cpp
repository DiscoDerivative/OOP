#include <iostream>
#include <cstring>
class Book{
    private:
    char* title;
    public:
    Book() : title(nullptr){}
    ~Book(){
        delete [] title;
    }
    void setTitle(const char* newTitle){
        title = new char[std::strlen(newTitle) + 1];
        if(title == nullptr){
            std::cout << "Memory not allocated";
        }
        else
        {
            std::strcpy(title, newTitle);
        }
    }
    const char* getTitle(){
        return title;
    }
    operator const char*(){
        return title;
    }
};

int main(void){
    Book b1;
    b1.setTitle("Tokyo Ghoul");
    std::cout << "Title: " << b1.getTitle() << '\n';
    
    const char* TokyoGhoul = b1;
    std::cout << "Title (implicit conversion): " << TokyoGhoul << '\n';
    return 0;
}
