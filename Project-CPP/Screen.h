#pragma once

#include "NewConsole.h"
#include "ChildProcess.h"

class Screen :  public NewConsole
{
public:
    Screen(std::shared_ptr<ChildProcess> process, String processName);
    void onEnabled() override;
    void process() override;
    void display() override;

private:
    void printProcessInfo() const;
    std::shared_ptr<ChildProcess> attachedProcess;
    bool refreshed = false;

};