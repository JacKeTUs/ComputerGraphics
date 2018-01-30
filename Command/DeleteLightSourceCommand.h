#ifndef DELETELIGHTSOURCECOMMAND_H
#define DELETELIGHTSOURCECOMMAND_H

#include "Command.h"

class DeleteLightSourceCommand : public Command
{
private:
    int index;

public:
    DeleteLightSourceCommand(int i) : index(i) {}

    void execute(AdapterFacade &facade)
    {
        facade.deleteIdxLightSource(index);
    }
};

#endif // DELETELIGHTSOURCECOMMAND_H
