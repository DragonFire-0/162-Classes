
#include <iostream>
#include <fstream>
#include "tasklist.h"

void Tasklist::loadTask(istream &fin){
    char const DELIMITER = ';';

    //Reads in what all the data is
    fin.getline(baseData[0], Task::MAX_CHAR, DELIMITER);
    fin.getline(baseData[1], Task::MAX_CHAR, DELIMITER);
    fin.getline(baseData[2], Task::MAX_CHAR, DELIMITER);
    fin.getline(baseData[3], Task::MAX_CHAR, DELIMITER);
    fin.getline(baseData[4], Task::MAX_CHAR);

    while(fin && !fin.peek() != EOF){
        Task tempTask; //Day 1,name a, duration 1, person a, catagory 1
        int tempInt = 0;
        char tempChar[Task::MAX_CHAR] = {0};

        // read data from file
        fin >> tempInt; //Sets the input into a temp int
        tempTask.setDay(tempInt); //Sets the day to the temp int
        fin.get(); // Remove delimiter

        fin.getline(tempChar, Task::MAX_CHAR, DELIMITER);
        tempTask.setName(tempChar);

        fin >> tempInt; //Sets the input into a temp int
        tempTask.setDuration(tempInt); //Sets the duration to the temp int
        fin.get(); // Remove delimiter
        
        fin.getline(tempChar, Task::MAX_CHAR, DELIMITER);
        tempTask.setPerson(tempChar);
        
        fin >> tempInt; //Sets the input into a temp int
        tempTask.setCat(tempInt); //Sets the catagory to the temp int
        fin.get(); // Remove delimiter

        //tempTask should now be full

        int pos = 0;

        bool next = true;
        while(next) {
            if (pos == size) {
                next = false;
            }
            //Writes alphabetically (Possibly reverse)
            else if(strcmp(tempTask.getName(), fullList[pos].getName()) > 0) {
                pos++;
            } 
            else {
                next = false;
            }
        }

        insert(tempTask, pos);
    }
}

void Tasklist::insert(Task tempTask, size_t pos) {
    for(size_t i = size + 1; i > pos; i-- ) {
        fullList[i] = fullList[i-1];
    }
    fullList[pos] = tempTask;
    size++;
}


void Tasklist::printAll(std::ostream &os){
    
    os.width(7); os << baseData[0];
    os.width(35); os << baseData[1];
    os.width(10); os << baseData[2];
    os.width(35); os << baseData[3];
    os.width(20); os << baseData[4] << endl << endl;

    for (int i = 0; i < MAX_LISTSIZE; i++){
        if(fullList[i].getDay() >= 0){
            os.width(2); os << i + 1; 
            fullList[i].printTask(os);
        }
    }
    os << endl;
}

void Tasklist::addTask(){
    Task tempTask;
    tempTask.setAll(); //Sets the wanted data to temp task

    int pos = 0;

    bool next = true;
    while(next) {
        if (pos == size) {
            next = false;
        }
        //Writes alphabetically (Possibly reverse)
        else if(strcmp(tempTask.getName(), fullList[pos].getName()) > 0) {
            pos++;
        } 
        else {
            next = false;
        }
    }

    insert(tempTask, pos);
    size++;
    //strcmp(tempTask.getName(), fullList[pos].getName()) > 0
}

void Tasklist::remTask(){
    int index = -1;
    printAll(cout);
    cout << "Enter index of task to remove: ";
    cin >> index;
    index--; //Puts index in line with the actual index
    for (int i = 0; i < size; i++){
        if (i >= index){
            fullList[i] = fullList[i+1];
        }
    }
}
