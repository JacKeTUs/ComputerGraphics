#ifndef SELECTLIGHTSOURCECOMMAND_H
#define SELECTLIGHTSOURCECOMMAND_H

#include "Command.h"

class SelectLightSourceCommand : public Command
{
private:
    int index;

public:
    SelectLightSourceCommand(int i): index(i) {}
    ~SelectLightSourceCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.SelectLightSource(index);
    }
};

#endif // SELECTLIGHTSOURCECOMMAND_H
