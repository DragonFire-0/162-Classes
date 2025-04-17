
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

    //Assignment Operator Overloading
    Task& operator=(const Task& other);

    //Functions
    //Set functions
    void setAll();
    void setDay(int DTS);
    void setName(char NTS[]);
    void setDuration(int DTS);
    void setPerson(char PTS[]);
    void setCat(int CTS);
    //Print function
    void printTask(std::ostream &os);
    //Get functions
    char* getName();
    int getCat();
    //Write function
    void writeFile(std::ofstream &is, char const DELIMITER);

    //Makes the user able to write with spaces
    void writeSpace(char arr[]);
private:
    int day = -1;
    char taskName[MAX_CHAR] = {0};
    int duration = -1;
    char personName[MAX_CHAR] = {0};
    int category = -1;
};

#endif