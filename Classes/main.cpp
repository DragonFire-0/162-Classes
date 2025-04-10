//*****************************************************************************
// Author: Chancellor Field
// Assignment: Assignment 1 Classes
// Date:
// Description: 
// Sources: 
//*****************************************************************************

#include <iostream> //May not be needed
#include "main.h"
#include "tasklist.cpp"

using namespace std;

int main() {
    //Variable initilization
    char controlChar = '';

    //Welcome message
    cout << "Welcome!" << endl
    << "This program will help you manage your tasks for this Space Station." << endl;
    

    //Main loop
    while (controlChar != 'q'){
        controlChar = mainDirec();

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
    
    char controlChar = '';
    cin >> controlChar;
    cout << endl;
    return controlChar
}