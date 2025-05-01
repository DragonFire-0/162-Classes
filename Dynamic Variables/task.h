
//Needs a variable for Day, task name, duration, person name, category

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <cstddef> // for https://en.cppreference.com/w/cpp/types/size_t
#include <cstring> // https://en.cppreference.com/w/cpp/header/cstring

#include <fstream>



class Task {   // can also use struct Activity
public:
    static const size_t MAX_CHAR = 50;
    //Default constructor 
    //Not needed?
    //Task();
    
    //Destructor
    ~Task();

    //Assignment Operator Overloading
    Task& operator=(const Task& other);

    //Functions
    
    //To Set functions
    void setAll();
    void setDay(int DTS);
    void setName(char* NTS);
    void setDuration(int DTS);
    void setPerson(char* PTS);
    void setCat(int CTS);
    
    //Print function
    void printTask(std::ostream &os);
    
    //Get functions
    char* getTaskName();
    char* getName();
    int getCat();
    
    //Write function
    void writeFile(std::ofstream &is, char const DELIMITER);

    //Makes the user able to write with spaces
    void writeSpace(char arr[]);
    //Get character array size
    int getCAS(char arr[]);
private:
    int day = -1;
    int duration = -1;
    int category = -1;

    char *taskName = nullptr;
    int taskSize = 0; //Size of the taskName array
    //char taskName[MAX_CHAR] = {0};
    
    char *personName = nullptr;
    int perSize = 0; //Size of the personName array
    //char personName[MAX_CHAR] = {0};
};

#endif