//*****************************************************************************
// Author: Chancellor Field
// Assignment: Assignment 2 Dynamice Memory
// Date:
// Description: 
// Sources: 
//*****************************************************************************

//To do
//Fix search function (strstr functon needs to be used)
//Make strings dynamically allocated (cstring)
//You are required to use a dynamic array of Task to implement TaskList.
//Use destructor to deallocate the dynamic memory for the object.
//Make sure no memory leaks; valgrind --tool=memcheck --leak-check=full executable-file. 


#include "main.h"
#include <fstream>
#include <cstring> // https://en.cppreference.com/w/cpp/header/cstring
#include "main.h"

using namespace std;

int main() {
    //Variable initilization
    char controlChar = {0};

    ifstream fin = ifstream("tasks.txt"); 
    Tasklist fulList(fin);
    
    //Welcome message
    cout << "Welcome!" << endl
    << "This program will help you manage your tasks for this Space Station." << endl;
    

    //Main loop
    while (controlChar != 'q'){
        controlChar = mainDirec();
        
        if(controlChar == 'a'){//Add a new task
            fulList.addTask();
        }

        else if(controlChar == 'b'){//List tasks by name
            fulList.printAll(cout);
        }

        else if(controlChar == 'c'){//List tasks for a Type
            fulList.listType();
        }
        
        else if(controlChar == 'd'){//Search by task name
            fulList.searchName();
        }
        
        else if(controlChar == 'e'){//Remove tasks by index
            fulList.remTask();
        }
        
        else if(controlChar != 'q'){//Error message
            cout << "Invalid option!! Please try again!" << endl;
        }
    }

    //File writing
    ofstream fout = ofstream("task.txt"); 
    fulList.exportToFile(fout);
}

char mainDirec(){ 
    cout << "Pick an option form below:" << endl << endl 
    << "(a)Add a new task" << endl
    << "(b)List tasks by name" << endl
    << "(c)List tasks by Type" << endl
    << "(d)Search by task name" << endl
    << "(e)Remove tasks by index" << endl
    << "(q)Quit" << endl;
    
    char controlChar = {0};
    cin >> controlChar;
    cout << endl;
    return controlChar;
}