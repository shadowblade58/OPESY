#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_SCREENS 10 // Limit to the number of screens

typedef struct {
    char name[20];
    int id;
    int current_instruction_line;
    SYSTEMTIME timestamp;
} Screen;

Screen screens[MAX_SCREENS];
int screen_count = 0;
int active_screen = -1; // No active screen initially

// COLORS FOR PRINTING
void white() { printf("\033[0;37m"); }
void green() { printf("\033[0;32m"); }
void yellow() { printf("\033[0;33m"); }

// TIME AND DATE
void showTimestamp(SYSTEMTIME st) {
    const char *ampm = (st.wHour >= 12) ? "PM" : "AM";
    int hour = st.wHour % 12;
    if (hour == 0) hour = 12;
    printf("(%02d/%02d/%04d, %02d:%02d:%02d %s)", st.wMonth, st.wDay, st.wYear, hour, st.wMinute, st.wSecond, ampm);
}

// ASCII ART
void asciiart() {
    printf("  _____  _____  ____  _____  ______  _______     __ \n");
    printf(" / ____|/ ____|/ __  |  __  |  ____|/ ____      / / \n");
    printf("| |    | (___ | |  | | |__) | |__  | (___     _/ /  \n");
    printf("| |      ___  | |  | |  ___/|  __|   ___        /   \n");
    printf("| |____ ____) | |__| | |    | |____ ____) |  | |    \n");
    printf("  _____|_____/  ____/|_|    |______|_____/   |_|    \n");
}

// HEADER PRINTING FOR MAIN MENU
void header() {
    green();
    printf("Hello, Welcome to CSOPESY commandline!\n");
    yellow();
    printf("Type 'exit' to quit, 'clear' to clear the screen\n");
}

// Create a new screen and add to the list
void createScreen(char* name) {
    if (screen_count >= MAX_SCREENS) {
        printf("Maximum number of screens reached.\n");
        return;
    }

    // Initialize the new screen
    Screen new_screen;
    strcpy(new_screen.name, name);
    new_screen.id = screen_count;
    new_screen.current_instruction_line = 0;
    GetLocalTime(&new_screen.timestamp);

    // Add to the list of screens
    screens[screen_count++] = new_screen;
    active_screen = new_screen.id; // Automatically attach to the new screen

    // Clear the console and display screen details
    system("cls");
    printf("Process: %s\n", new_screen.name);
    printf("ID: %d\n", new_screen.id);
    printf("Current instruction line: %d / 50\n", new_screen.current_instruction_line);
    printf("Timestamp: ");
    showTimestamp(new_screen.timestamp);
    printf("\n");
}

// Print screen details
void displayScreen(Screen* scr) {
    printf("Process: %s\n", scr->name);
    printf("ID: %d\n", scr->id);
    printf("Current instruction line: %d / 50\n", scr->current_instruction_line);
    printf("Timestamp: ");
    showTimestamp(scr->timestamp);
    printf("\n");
}

// Switch to an existing screen
void attachScreen(char* name) {
    for (int i = 0; i < screen_count; i++) {
        if (strcmp(screens[i].name, name) == 0) {
            active_screen = screens[i].id;
            // Clear the console and display screen details
            system("cls");
            displayScreen(&screens[i]);
            return;
        }
    }
    printf("Error: Screen '%s' not found.\n", name);  // Error message for non-existent screen
}

// Detach from the current screen
void detachScreen() {
    if (active_screen != -1) {
        printf("Detached from screen '%s'\n", screens[active_screen].name);
        active_screen = -1;
    } else {
        printf("No screen is currently attached.\n");
    }
}

// List all screens
void listScreens() {
    if (screen_count == 0) {
        printf("No screens available.\n");  // Inform user if no screens are present
    } else {
        printf("Available screens:\n");
        for (int i = 0; i < screen_count; i++) {
            printf("ID: %d, Process: %s\n", screens[i].id, screens[i].name);
        }
    }
}

// Input handler for screens
void screenHandler(Screen* scr) {
    char command[20];

    while (1) {
        white();
        printf("\nroot:\\> ", scr->name, scr->id);
        scanf(" %[^\n]", command);

        if (strcmp(command, "exit") == 0) {
            detachScreen();
            return; // Return to the main menu
        } else {
            scr->current_instruction_line++;
            printf("Processing command '%s' (line %d)\n", command, scr->current_instruction_line);
        }

        if (scr->current_instruction_line >= 50) {
            printf("Instruction limit reached on this screen.\n");
            detachScreen();
            return;
        }
    }
}

int main() {
    char command[30], param1[20], param2[20];
    while (1) {
        if (active_screen == -1) {
            system("cls"); // Clear console before displaying main menu
            asciiart();
            header();  // Show ASCII art and header in the main menu
            white();
            printf("Enter a command: ");
            scanf(" %[^\n]", command);

            if (sscanf(command, "screen -s %s", param1) == 1) {
                createScreen(param1);
                screenHandler(&screens[active_screen]); // Handle input for the screen
            } else if (sscanf(command, "screen -r %s", param1) == 1) {
                attachScreen(param1);
                if (active_screen != -1) {
                    screenHandler(&screens[active_screen]);
                }
            } else if (sscanf(command, "screen %s", param1) == 1) {
                listScreens();
            } else if (strcmp(command, "exit") == 0) {
                printf("Exiting program.\n");
                break;
            } else {
                printf("Invalid command.\n");
            }
        }
    }

    return 0;
}


