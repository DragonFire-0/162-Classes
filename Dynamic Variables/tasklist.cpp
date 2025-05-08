
#include <iostream>
#include <fstream>
#include <cstring>
#include "tasklist.h"

Tasklist::Tasklist(){}

Tasklist::Tasklist(istream &fin){
    //Declares fullPtrList as a task that is 'size' which should be 0
    fullPtrList = new Task[size];
    
    
    
    char const DELIMITER = ';';
    static const size_t MAX_CHAR = 50;
    //Reads in what all the data types are
    fin.getline(baseData[0], MAX_CHAR, DELIMITER);  //Day
    fin.getline(baseData[1], MAX_CHAR, DELIMITER);  //Task name
    fin.getline(baseData[2], MAX_CHAR, DELIMITER);  //Duration
    fin.getline(baseData[3], MAX_CHAR, DELIMITER);  //Person name
    fin.getline(baseData[4], MAX_CHAR);             //Category


    while(fin && !fin.peek() != EOF){
        //Makes a temp task pointer
        Task* ptrTempTask = new Task;
        //Temporary int and char array
        int tempInt = 0;
        char tempChar[MAX_CHAR] = {0};

        // read data from file
        fin >> tempInt; //Sets the input into a temp int
        ptrTempTask->setDay(tempInt); //Sets the day to the temp int
        fin.get(); // Remove delimiter

        fin.getline(tempChar, MAX_CHAR, DELIMITER);
        ptrTempTask->setName(tempChar);
        
        fin >> tempInt; //Sets the input into a temp int
        ptrTempTask->setDuration(tempInt); //Sets the duration to the temp int
        fin.get(); // Remove delimiter
        
        fin.getline(tempChar, MAX_CHAR, DELIMITER);
        ptrTempTask->setPerson(tempChar);
        
        fin >> tempInt; //Sets the input into a temp int
        ptrTempTask->setCat(tempInt); //Sets the catagory to the temp int
        fin.get(); // Remove delimiter

        //ptrTempTask should now be full

        int pos = 0;

        bool next = true;
        while(next) {
            if (pos >= size) {
                next = false;
            }
            //Writes alphabetically (Not working and not needed?)
            else if(strcmp(ptrTempTask->getName(), fullPtrList[pos].getName()) > 0) {
                pos++;
            } 
            else {
                next = false;
            }
        }

        insert(ptrTempTask, pos);
        
        delete ptrTempTask;
    }
}

void Tasklist::exportToFile(ofstream &is){
    char const DELIMITER = ';';
    
    //Day;task name;duration;person name;category
    is << baseData[0] << DELIMITER
    << baseData[1] << DELIMITER
    << baseData[2] << DELIMITER
    << baseData[3] << DELIMITER
    << baseData[4] << endl;

    for (int i = 0; i < size; i++){
      fullList[i].writeFile(is, DELIMITER);
      //If it is not the last activity make a new line
      if (i < size-1){
        is << endl;
      }
    }
  
}

Tasklist::~Tasklist(){
    if (fullPtrList != nullptr){
        delete [] fullPtrList;
        fullPtrList = nullptr;
    }
}

void Tasklist::insert(Task* tempTask, size_t pos) {
    //Currently fullList is one less than what we want
    size++;
    //Makes a temp pointer that is one bigger than the current
    Task* tempPtr = new Task[size];
    
    for (int i = 0; i < size; i++){
        if (i < pos){
            tempPtr[i] = fullPtrList[i];
        }
        else if (i > pos){
            tempPtr[i] = fullPtrList[i-1];
        }
    }

    //Sets the task to the correct position
    tempPtr[pos] = *tempTask;
    
    //Deletes the current held list in the full list
    if (fullPtrList != nullptr){
        delete [] fullPtrList;
    }
    fullPtrList = new Task[size];
    //Sets the full list to the tempPtr list.
    for (int i = 0; i < size; i++){
        fullPtrList[i] = tempPtr[i];
    }
    //Deletes the temp list
    delete[] tempPtr;
}

void Tasklist::printAll(std::ostream &os){
    
    printGuide(os);

    for (int i = 0; i < size; i++){
        if(fullPtrList[i].getCat() >= 0){
            os.width(2); os << i + 1; 
            fullPtrList[i].printTask(os);
        }
    }
    os << endl;
}

void Tasklist::printGuide(std::ostream &os){
    os.width(7); os << baseData[0];
    os.width(35); os << baseData[1];
    os.width(10); os << baseData[2];
    os.width(35); os << baseData[3];
    os.width(20); os << baseData[4] << endl << endl;
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
        //Writes alphabetically
        
        //else if(strcmp(tempTask.getName(), fullList[pos].getName()) > 0) {
        //    pos++;
        //} 
        
        else {
            next = false;
        }
    }

    //insert(tempTask, pos);
    size++;
    
    printAll(cout);

}

void Tasklist::listType(){
    int type = -1;
    cout << "Enter Type number(0-Operations, 1-Maintenance, 2-Inventory, 3-Communications, and 4-Others): ";
    cin >> type;

    cout << endl;
    printGuide(cout);

    for (int i = 0; i < size; i++){
        if (fullList[i].getCat() == type){
            fullList[i].printTask(cout);
        }
    }
}

void Tasklist::searchName(){
    
    char searchTerm[Task::MAX_CHAR];

    cout << "Enter task name: ";
    cin.ignore(1);
    fullList[0].writeSpace(searchTerm);
    printGuide(cout);

    char* pch = NULL; //Char pointer
    bool found = false;

    for (int i = 0; i < size; i++){
        //Sets pch to first occurence of searchTerm in the name
        pch = strstr (fullList[i].getTaskName(), searchTerm); 
        if (pch != NULL){ //If pch is not null
        cout << i + 1;
            fullList[i].printTask(cout);
            found = true;
        }
    }
    if (!found){
        cout << "No task match found" << endl;
    }
    cout << endl;
    delete[] pch;
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
    cout << endl << "Task Removed" << endl;
}
