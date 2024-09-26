/*
CSOPESY S11 / S12
Group 1: Ching, Donato, Harder, Javier
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//COLORS FOR PRINTING
void black(){
    printf("\033[0;30m");
}
void red(){
    printf("\033[0;31m");
}
void green(){
    printf("\033[0;32m");
}
void yellow(){
    printf("\033[0;33m");
}
void blue(){
    printf("\033[0;34m");
}
void purple(){
    printf("\033[0;35m");
}
void cyan(){
    printf("\033[0;36m");
}
void white(){
    printf("\033[0;37m");
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
//SCREEN COMMAND
void screen(char* type, char* name){
    
    //printf("Screen command recognized. Doing something...\n");
    clear();
    white();
    if(strcmp(type, "-s") == 0){
        printf("There is a screen on:\n\t%s\t", name);
        showTimestamp();
        printf("\t (Attached)\n");
    }
    else if(strcmp (type, "-r") == 0){
        printf("displaying type r \n");
        printf("There is a screen on:\n\t%s\t", name);
        showTimestamp();
        printf("\t (Attached)\n");
    }
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

int main(){
    asciiart();
    header();
    char response[20] = "";
    
    while(strcmp(response, "exit") != 0){   
        white();
        char initial[30];
        char first[20] = "";
        char second[20] = "";
        char third[20] = "";
        printf("Enter a command: ");
        scanf(" %[^\n]", initial);
        //Extract words
        int i = 0;
        int wordIndex = 0;
        while (initial[i] != '\0' && wordIndex < 3) {
        // Skip leading spaces
        while (initial[i] == ' ') {
            i++;
        }

        // If we are at a word boundary
        if (initial[i] != '\0') {
            // Extract the word based on the current word index
            if (wordIndex == 0) {
                // First word
                int j = 0;
                while (initial[i] != ' ' && initial[i] != '\0') {
                    first[j++] = initial[i++];
                }
                first[j] = '\0'; // Null-terminate the first word
            } else if (wordIndex == 1) {
                // Second word
                int j = 0;
                while (initial[i] != ' ' && initial[i] != '\0') {
                    second[j++] = initial[i++];
                }
                second[j] = '\0'; // Null-terminate the second word
            } else if (wordIndex == 2) {
                // Third word
                int j = 0;
                while (initial[i] != ' ' && initial[i] != '\0') {
                    third[j++] = initial[i++];
                }
                third[j] = '\0'; // Null-terminate the third word
            }
            wordIndex++;
        }
    }
        strcpy(response, first);
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
            screen(second, third);
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
