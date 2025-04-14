
//Needs a variable for Day, task name, duration, person name, category

#ifndef TASK_H
#define TASK_H

#include <iostream>
# include <cstddef> // for https://en.cppreference.com/w/cpp/types/size_t

class Task {   // can also use struct Activity
public:
    Task();//Default constrontor
    static const size_t MAX_CHAR = 50;
    void setAll(int DayTS, char NTS[], int DurTS, char PTS[], int CTS);
    void setDay(int DTS);
    void setName(char NTS[]);
    void setDuration(int DTS);
    void setPerson(char PTS[]);
    void setCat(int CTS);
    void printTask(std::ostream &os);
private:
    int day = -1;
    char taskName[MAX_CHAR] = {0};
    int duration = -1;
    char personName[MAX_CHAR] = {0};
    int category = -1;
};

#endif