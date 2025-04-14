
#include <iostream>
#include "task.h"

using namespace std;

//Default constructor

//Calls all individual functions
void Task::setAll(int DayTS, char NTS[], int DurTS, char PTS[], int CTS){
    setDay(DayTS);
    setName(NTS);
    setDuration(DurTS);
    setPerson(PTS);
    setCat(CTS);
}

void Task::setDay(int DTS){
    day = DTS;
}

void Task::setName(char NTS[]){
    for (int i = 0; i < MAX_CHAR; i++){
        taskName[i] = NTS[i];
    }
}

void Task::setDuration(int DTS){
    duration = DTS;
}

void Task::setPerson(char PTS[]){
    for (int i = 0; i < MAX_CHAR; i++){
        personName[i] = PTS[i];
    }
}

void Task::setCat(int CTS){
    category = CTS;
}

//28;Replace ventilation filters;2;Carlos Johnston;Maintenance
void Task::printTask(std::ostream &os){
    os.width(5); os << day;
    os.width(25); os << taskName;
    os.width(10); os << duration;
    os.width(25); os << personName;
    
    //0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others
    char cat[MAX_CHAR] = {0};
    if (category == 0){
        os.width(20); os << "Operations" << endl;
    }
    else if (category == 1){
        os.width(20); os << "Maintenance" << endl;
    }
    else if (category == 2){
        os.width(20); os << "Inventory" << endl;
    }
    else if (category == 3){
        os.width(20); os << "Communications" << endl;
    }
    else if (category == 4){
        os.width(20); os << "Others" << endl;
    }
    else {
        os.width(20); os << "No category" << endl;
    }
    
    
}
