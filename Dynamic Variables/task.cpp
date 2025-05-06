
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
        duration = other.duration;
        category = other.category;

        //deletes task name if it is not a null pointer
        if (taskName != nullptr){
            delete [] taskName;
            taskName = nullptr;
        }
        if (personName != nullptr){
            delete [] personName;
            personName = nullptr;
        }

        if (other.taskName != nullptr){
            taskSize = other.taskSize;
            taskName = new char[taskSize];
            strcpy(taskName, other.taskName);
        }
        if (other.personName != nullptr){
            perSize = other.perSize;
            personName = new char[perSize];
            strcpy(personName, other.personName);
        }
    }
    return *this;
}

//Default constructor (Not doing anything)
Task::Task(){}

//Copy constructor
Task::Task(const Task& TaskTBC){
    day = TaskTBC.day;
    duration = TaskTBC.duration;
    category = TaskTBC.category;
    taskName = TaskTBC.taskName;
    taskSize = TaskTBC.taskSize;
    personName = TaskTBC.personName;
    perSize = TaskTBC.perSize;
}

//Destructor, deletes dynamic variables
Task::~Task(){
    if (taskName != nullptr){
        delete [] taskName;
        taskName = nullptr;
    }

    if (personName != nullptr){
        delete [] personName;
        taskName = nullptr;
    }
}

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

    cout << "Enter the person's name (50 characters or less): ";
    cin.ignore(1);
    writeSpace(personName);
    
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

    cout << endl << "Task Added!" << endl << endl;
}

void Task::setDay(int DTS){
    day = DTS;
}

void Task::setName(char* NTS){
    //Deletes task name if it is not a nullptr
    if (taskName != nullptr){
        delete [] taskName;
        taskName = nullptr;
    }
    //Gets the size of the name to set
    taskSize = getCAS(NTS);
    //cout << taskSize << endl;
    //Makes taskname a character array of size taskSize
    taskName = new char[taskSize];
    //Copies the name to set into task name
    strcpy(taskName, NTS);
}

void Task::setDuration(int DTS){
    duration = DTS;
}

void Task::setPerson(char* PTS){
    //Deletes task name if it is not a nullptr
    if (personName != nullptr){
        delete [] personName;
        personName = nullptr;
    }
    perSize = getCAS(PTS);
    personName = new char[perSize];
    strcpy(personName, PTS);
}

void Task::setCat(int CTS){
    category = CTS;
}

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

int Task::getCat(){
    return category;
}

char* Task::getTaskName(){
    return taskName;
}

char* Task::getName(){
    return personName;
}

void Task::writeFile(ofstream &is, char const DELIMITER){
    is << day << DELIMITER
    << taskName << DELIMITER
    << duration << DELIMITER
    << personName << DELIMITER
    << category;
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

int Task::getCAS(char arr[]){
    int i = 0;
    //Checks if arr is allocated
    if (arr == nullptr){
        return 0;
    }
    //Runs through the array until the array has an unset variable
    while (arr[i] != '\0'){
        i++;
    }
    i++;
    return i;
}

#endif