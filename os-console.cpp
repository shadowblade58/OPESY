/*
CSOPESY S11 / S12
Group 1: Ching, Donato, Harder, Javier
*/

#include <iostream>
#include <cstring>
using namespace std;

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

void asciiart(){
    cout << "  _____  _____  ____  _____  ______  _______     __ \n";
    cout << " / ____|/ ____|/ __  |  __  |  ____|/ ____      / / \n";
    cout << "| |    | (___ | |  | | |__) | |__  | (___     _/ /  \n";
    cout << "| |      ___  | |  | |  ___/|  __|   ___        /   \n";
    cout << "| |____ ____) | |__| | |    | |____ ____) |  | |    \n";
    cout << "  _____|_____/  ____/|_|    |______|_____/   |_|    \n";
}

//HEADER PRINTING
void header(){
    green();
    cout << "Hello, Welcome to CSOPESY commandline!\n";
    yellow();
    cout << "Type 'exit' to quit, 'clear' to clear the screen\n";
}

//CLEAR COMMAND
void clear(){
    system("cls");
    asciiart();
    header();
}

//INITIALIZE COMMAND
void initialize(){
    cout << "Initialize command recognized. Doing something...\n"; 
}

//SCREEN COMMAND
void screen(){
    cout << "Screen command recognized. Doing something...\n";  
}

//SCHEDULER TEST COMMAND
void schedulertest(){
    cout << "Scheduler-test command recognized. Doing something...\n";  
}

//SCHEDULER STOP COMMAND
void schedulerstop(){
    cout << "Scheduler-stop command recognized. Doing something...\n";  
}

//REPORT UTIL COMMAND
void reportutil(){
    cout << "Report-util command recognized. Doing something...\n";  
}

int main(){
    asciiart();
    header();
    char response[20];
    while(strcmp(response, "exit") != 0){   
        white();
        printf("Enter a command: ");
        scanf("%s", response);
        if (strcmp(response, "clear") == 0){
            clear();
            }
        else if(strcmp(response, "exit") == 0){
            break;
            }
        else if(strcmp(response, "initialize") == 0){
            initialize();
            }
        else if(strcmp(response, "screen") == 0){
            screen();
            }
        else if(strcmp(response, "scheduler-test") == 0){
            schedulertest();
            }
        else if(strcmp(response, "scheduler-stop") == 0){
            schedulerstop();
            }
        else if(strcmp(response, "report-util") == 0){
            reportutil();
            }
        else
            printf("Invalid command... \n");
        }


    return 0;
}