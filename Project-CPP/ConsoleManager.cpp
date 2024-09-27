#include "ConsoleManager.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include "MainConsole.h"
#include "MarqueeConsole.h"

typedef std::string String;

ConsoleManager* ConsoleManager::sharedInstance = nullptr;
ConsoleManager* ConsoleManager::getInstance()
{
    return sharedInstance;
}

void ConsoleManager::initialize()
{
    sharedInstance = new ConsoleManager();
}

void ConsoleManager::destroy()
{
    delete sharedInstance;
}

// TODO:

ConsoleManager::ConsoleManager()
{
    this->running = true;

    this->consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    const std::shared_ptr<MainConsole> mainConsole = std::make_shared<MainConsole>();
    const std::shared_ptr<MarqueeConsole> marqueeConsole = std::make_shared<MarqueeConsole>();

    this->consoleTable[MAIN_CONSOLE] = mainConsole;
    this->consoleTable[MARQUEE_CONSOLE] = marqueeConsole;

    this->switchConsole(MAIN_CONSOLE);
}

void ConsoleManager::switchConsole(String consoleName)
{
    if(this->consoleTable.contains(consoleName))
    {
        system("cls");
        this->previousConsole = this->curretnConsole;
        this->currentConsole = this->consoleTable[consoleName];
        this->currentConsole->onEnabled();
    }
    else
    {
        std::cerr << "Console name " << consoleName << " not initizalied." << std::endl; 
    }
}

