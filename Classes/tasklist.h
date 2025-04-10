
//Needs to keep an array of tasks

#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <cstddef> // for https://en.cppreference.com/w/cpp/types/size_t
#include "task.cpp"

class Tasklist { 
public:
    int MAX_LISTSIZE = 30;
private:
    task[MAX_LISTSIZE] tasklist;
};

#endif
