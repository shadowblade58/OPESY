#pragma once

#include "NewConsole.h"
#include "Screen.h"

#include <memory>
#include <unordered_map>
#include <Windows.h>
#include <string>

typedef std::string String;

const String MAIN_CONSOLE = "MAIN_CONSOLE";
const String MARQUEE_CONSOLE = "MARQUEE_CONSOLE";

class ConsoleManager
{

public:
    typedef std::unordered_map<String, std::shared_ptr<NewConsole>> ConsoleTable;
    
    static ConsoleManager* getInstance();
    static void initialize();
    static void destroy();

    void drawConsole() const;
    void process() const;
    void switchConsole(String consoleName);

    void registerScreen(std::shared_ptr<Screen> screenRef);
    void switchToScreen(String screenName);
    void unregisterScreen(String screenName);

    void returnToPreviousConsole();
    void exitConsole();

    HANDLE getConsoleHanlde() const;

    void setCursorPosition(int posX, int posY) const;

private:
    ConsoleManager();
    ~ConsoleManager() = default;
    ConsoleManager(ConsoleManager const&) {};
    ConsoleManager& operator=(ConsoleManager const&) {};
    static ConsoleManager* sharedInstance;

    ConsoleTable consoleTable;
    std::shared_ptr<NewConsole> currentConsole;
    std::shared_ptr<NewConsole> previouseConsole;
    
    HANDLE consoleHandle;
    bool running = true;
};


ConsoleManager::ConsoleManager(/* args */)
{
}

ConsoleManager::~ConsoleManager()
{
} 