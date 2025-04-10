#ifndef TASK_H
#define TASK_H

#include <iostream>
#include "task.h"

//Default constructor
Task::Task(){
    Day = -1;
    [MAX_CHAR] taskName = {0};
    duration = -1;
    [MAX_CHAR] personName = {0};
    category = -1;
}

//Calls all individual functions
void setAll(int DayTS, char[] NTS, int DurTS, char[] PTS, int CTS){
    setDay(DayTS);
    setName(NTS);
    setDuration(DurTS);
    setPerson(PTS);
    setCat(CTS)
}

void setDay(int DTS){
    day = DTS;
}

void setName(char[] NTS){
    taskName = NTS;
}

void setDuration(int DTS){
    duration = DTS;
}

void setPerson(char[] PTS){
    personName = PTS;
}

void setCat(int CTS){
    category = CTS;
}

//28;Replace ventilation filters;2;Carlos Johnston;Maintenance
void printTask(){
    os.width(5); os << day;
    os.width(25); os << taksName;
    os.width(10); os << duration;
    os.width(25); os << personName;
    
    //0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others
    char[MAX_CHAR] cat = {0};
    if (category == 0){
        cat = "Operations";
    }
    else if (category == 1){
        cat = "Maintenance";
    }
    else if (category == 2){
        cat = "Inventory";
    }
    else if (category == 3){
        cat = "Communications";
    }
    else if (category == 4){
        cat = "Others";
    }
    else {
        cat = "No category"
    }
    
    os.width(20); os << cat << endl;
}

#endif