//*****************************************************************************
// Author: Chancellor Field
// Assignment: Assignment 1 Classes
// Date:
// Description: 
// Sources: 
//*****************************************************************************

#include "main.h"
#include <fstream>
#include <cstring> // https://en.cppreference.com/w/cpp/header/cstring
#include "main.h"

using namespace std;

int main() {
    //Variable initilization
    char controlChar = {0};
    Tasklist fulList;

    //Welcome message
    cout << "Welcome!" << endl
    << "This program will help you manage your tasks for this Space Station." << endl;
    
    ifstream fin = ifstream("tasks.txt"); 
    fulList.loadTask(fin);

    //Main loop
    while (controlChar != 'q'){
        controlChar = mainDirec();
        
        if(controlChar == 'a'){//Add a new task
            fulList.addTask();
        }

        else if(controlChar == 'b'){//List tasks by name
            fulList.printAll(cout);
        }

        else if(controlChar == 'c'){//List tasks by Type

        }
        
        else if(controlChar == 'd'){//Search by task name

        }
        
        else if(controlChar == 'e'){//Remove tasks by index
            fulList.remTask();
        }
        
        else if(controlChar != 'q'){//Error message
            cout << "Invalid option!! Please try again!" << endl;
        }
    }
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