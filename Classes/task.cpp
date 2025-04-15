
#ifndef TASK_CPP
#define TASK_CPP

#include <iostream>
#include "task.h"

using namespace std;

//Makes class able to be equal to another class
Task& Task::operator=(const Task& other) {
    //If the task to be copied is not the same as this task
    if (this != &other) { 
        day = other.day;
        strcpy(taskName, other.taskName);
        duration = other.duration;
        strcpy(personName, other.personName);
        category = other.category;
    }
    return *this;
}

//Gets user input to set the task
/*Enter the day of the task (whole numbers between 1 and 30): 78
Invalid day! Must be between 1 and 30 inclusive!
Enter the day of the task (whole numbers between 1 and 30): 8
Enter the task name (50 characters or less): Surface static discharge
Enter the person’s name (50 characters or less): Steph Kalias
Enter the number of hours (whole numbers between 1 and 10): 3
Enter the task type 0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): 0
*/
void Task::setAll(){
    bool valid = false;
    while (!valid){
        cout << "Enter the day of the task (whole numbers between 1 and 30): ";
        cin >> day;
        if (day > 30 || day < 0){
            cout << "Invalid day! Must be between 1 and 30 inclusive!" << endl;
        }
        else{
            valid = true;
        } 
    }
    valid = false;
    
    cout << "Enter the task name (50 characters or less): ";
    cin.ignore(1);
    writeSpace(taskName);

    while (!valid){
        cout << "Enter the number of hours (whole numbers between 1 and 10): ";
        cin >> duration;
        if (duration > 10 || duration < 1){
            cout << "Invalid duration! Must be between 1 and 10 inclusive!" << endl;
        }
        else{
            valid = true;
        } 
    }
    valid = false;

    cout << "Enter the person's name (50 characters or less): ";
    cin.ignore(1);
    writeSpace(personName);
    
    while (!valid){
        cout << "Enter the task type 0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): ";
        cin >> category;
        if (category > 4 || category < 0){
            cout << "Invalid type! Must be between 0 and 4 inclusive!" << endl;
        }
        else{
            valid = true;
        } 
    }
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
    os.width(35); os << taskName;
    os.width(10); os << duration;
    os.width(35); os << personName;
    
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

int Task::getDay(){
    return day;
}

char* Task::getName(){
    return taskName;
}

//Insert a character array and it will write to it
void Task::writeSpace(char arr[]){
    char ch; 
    int cNum = 0; //Character num
    
    //Writes until newline
    while (cin.get(ch) && ch != '\n') {
      arr[cNum] = ch;
      cNum++;
    }
}

#endif