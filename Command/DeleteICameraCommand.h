#ifndef DELETEICAMERACOMMAND_H
#define DELETEICAMERACOMMAND_H

#include "Command.h"

class DeleteICameraCommand : public Command
{
private:
    int index;

public:
    DeleteICameraCommand(int i) : index(i) {}

    void execute(AdapterFacade &facade)
    {
        facade.deleteIdxCamera(index);
    }
};

#endif // DELETEICAMERACOMMAND_H
