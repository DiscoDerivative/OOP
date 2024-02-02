//This code file is creating a struct called Vehicle
#include <iostream>
#include <cstring>
using namespace std;

struct Vehicle{
    char* bufferName;
    char* bufferModel;
};

int main(void){

//Allocating memory to a single structure
Vehicle* myCar = new Vehicle;

//Defining the car name and car model
const char* CAR_NAME = "2018 Toyota Camry";
const char* CAR_MODEL = "LE";

//Defining the car name size to be used in allocating the buffer
const int carNameSize = std::strlen(CAR_NAME) + 1;
const int carModelSize = std::strlen(CAR_MODEL) + 1;

//Allocating memory to the buffers
myCar->bufferName = new char[carNameSize];
myCar->bufferModel = new char[carModelSize];

//Copying name and model into the buffers
std::strcpy(myCar->bufferName, CAR_NAME);
std::strcpy(myCar->bufferModel, CAR_MODEL);

//Printing out the name and model
std::cout << "Car name: " << myCar->bufferName << '\n';
std::cout << "Car model: " << myCar->bufferModel << '\n';

//Deallocating memory to the buffers
delete[] myCar->bufferName;
delete[] myCar->bufferModel;
}
