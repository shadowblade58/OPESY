#ifndef NEWSCREEN
#define NEWSCREEN

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::string;


class NewScreen {
private:
    string process_name;
    int current_instruction;
    int total_instructions;
    string timestamp;  // In MM/DD/YYYY HH:MM:SS AM/PM format
    //mutex screen_mutex;

    // Function to get the current timestamp in the required format
    string get_timestamp() {
        time_t t = time(nullptr);
        tm* local_time = localtime(&t);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%m/%d/%Y %I:%M:%S %p", local_time);
        return string(buffer);
    }

public:
    // Constructor
    NewScreen();

    // Destructor
    ~NewScreen();

    // Public methods
    void myMethod();


};

#endif // NEWSCREEN