#ifndef SELECTMODELCOMMAND_H
#define SELECTMODELCOMMAND_H

#include "Command.h"

class SelectModelCommand : public Command
{
private:
    int index;

public:
    SelectModelCommand(int i): index(i) {}
    ~SelectModelCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.SelectModel(index);
    }
};

#endif // SELECTMODELCOMMAND_H
