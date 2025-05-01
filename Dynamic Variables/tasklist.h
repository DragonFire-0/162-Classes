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
    void exportToFile(ofstream &is);//Not Done
    void insert(Task* tempAct, size_t pos);//Done
    void printAll(std::ostream &os);//Done
    void addTask();//Done
    void listType();//Done
    void searchName();//Somewhat working
    void remTask();//Done
    
private:
    //Functions
    void printGuide(std::ostream &os);
    //Variable
    char baseData[5][50] = {}; //Array for the inital input
    Task fullList[MAX_LISTSIZE]; //List of tasks
    size_t size = 0; //Size of the list
};

#endif
