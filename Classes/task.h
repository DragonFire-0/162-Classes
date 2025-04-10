
//Needs a variable for Day, task name, duration, person name, category


#ifndef TASK_H
#define TASK_H

#include <iostream>
# include <cstddef> // for https://en.cppreference.com/w/cpp/types/size_t

class Task {   // can also use struct Activity
public:
    int MAX_CHAR = 30;
    void setAll(int DayTS, char[] NTS, int DurTS, char[] PTS, int CTS);
    void setDay(int DTS);
    void setName(char[] NTS);
    void setDuration(int DTS);
    void setPerson(char[] PTS);
    void setCat(int CTS);
    void printTask();
private:
    int day;
    char[MAX_CHAR] taskName;
    int duration;
    char[MAX_CHAR] personName;
    int category;
};

#endif