#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "ConsoleManager.h"
#include "InputManager.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//COLORS FOR PRINTING
void black(){
    cout << "\033[0;30m";
}
void red(){
    cout << "\033[0;31m";
}
void green(){
    cout << "\033[0;32m";
}
void yellow(){
    cout << "\033[0;33m";
}
void blue(){
    cout << "\033[0;34m";
}
void purple(){
    cout << "\033[0;35m";
}
void cyan(){
    cout << "\033[0;36m";
}
void white(){
    cout << "\033[0;37m";
}

//ASCIIART
void asciiart(){
    printf("  _____  _____  ____  _____  ______  _______     __ \n");
    printf(" / ____|/ ____|/ __  |  __  |  ____|/ ____      / / \n");
    printf("| |    | (___ | |  | | |__) | |__  | (___     _/ /  \n");
    printf("| |      ___  | |  | |  ___/|  __|   ___        /   \n");
    printf("| |____ ____) | |__| | |    | |____ ____) |  | |    \n");
    printf("  _____|_____/  ____/|_|    |______|_____/   |_|    \n");
}

//HEADER PRINTING
void header(){
    green();
    printf("Hello, Welcome to CSOPESY commandline!\n");
    yellow();
    printf("Type 'exit' to quit, 'clear' to clear the screen\n");
}

//CLEAR COMMAND
void clear(){
    system("cls");
    header();
}
//INITIALIZE COMMAND
void initialize(){
    printf("Initialize command recognized. Doing something...\n"); 
}

//SCHEDULER TEST COMMAND
void schedulertest(){
    printf("Scheduler-test command recognized. Doing something...\n");  
}
//SCHEDULER STOP COMMAND
void schedulerstop(){
    printf("Scheduler-stop command recognized. Doing something...\n");  
}
//REPORT UTIL COMMAND
void reportutil(){
    printf("Report-util command recognized. Doing something...\n");  
}


//TIME AND DATE
void showTimestamp(){
    SYSTEMTIME st;
    GetLocalTime(&st);

    // Determine AM or PM
    const char *ampm = (st.wHour >= 12) ? "PM" : "AM";
    
    // Convert 24-hour format to 12-hour format
    int hour = st.wHour % 12;
    if (hour == 0) {
        hour = 12;  // Handle midnight and noon cases
    }

    // Output in MM/DD/YYYY, HH:MM:SS AM/PM format
    printf("(%02d/%02d/%04d, %02d:%02d:%02d %s)", 
        st.wMonth, 
        st.wDay, 
        st.wYear, 
        hour, 
        st.wMinute, 
        st.wSecond, 
        ampm);
}

// ! =========================== MAIN =====================================

int main(){
    asciiart();
    header();

    ConsoleManager::initialize();

    bool running = true;
    while(running)
    {
        ConsoleManager::getInstance()->process();
        ConsoleManager::getInstance()->drawConsole();

        running = ConsoleManager::getInstance()->isRunning();
    }

    string response = "";

        if (response == "clear") {
            clear();
        } else if (response == "exit") {
            return 0;
        } else if (response == "initialize") {
            initialize();
        } else if (response == "scheduler-test") {
            schedulertest();
        } else if (response == "scheduler-stop") {
            schedulerstop();
        } else if (response == "report-util") {
            reportutil();
        } else {
            cout << "Invalid command..." << endl;
        }

    ConsoleManager::destroy();

    return 0;
}
