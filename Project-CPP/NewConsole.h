#pragma once
#include <string>

class NewConsole
{
public:
    typedef std::string String;
    NewConsole(String name);
    ~NewConsole() = default;

    String getName();
    virtual void onEnabled() = 0;
    virtual void display() = 0;
    virtual void process() = 0;

    String name;
    friend class ConsoleManager;
};

