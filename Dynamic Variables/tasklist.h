//Keeps an array of tasks

#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <fstream>
#include <cstddef> // for https://en.cppreference.com/w/cpp/types/size_t
#include "task.h"
using namespace std;

class Tasklist { 
public:
    static const size_t MAX_LISTSIZE = 30;
    Tasklist(); //Default constructor
    Tasklist(istream &fin); //Constructor using fin
    ~Tasklist(); //Deconstructor
    void exportToFile(ofstream &is);
    void insert(Task* tempAct, size_t pos);

    void printAll(std::ostream &os);    //Done
    void addTask();                     //Needs Done
    void listType();                    //Done
    void searchName();                  //Needs Done
    void remTask();                     //Needs Done
    
private:
    //Functions
    void printGuide(std::ostream &os);
    //Variable
    static const size_t MAX_CHAR = 50; //Maximum input length for input
    char baseData[5][50] = {}; //Array for the inital input
    size_t size = 0; //Size of the list
    Task fullList[MAX_LISTSIZE]; //List of tasks
    
    Task* fullPtrList = nullptr;
};

#endif
