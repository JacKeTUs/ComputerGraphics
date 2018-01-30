#ifndef SETIDXINTENSITYCOMMAND_H
#define SETIDXINTENSITYCOMMAND_H

#include "Command.h"

class ChgIdxIntensityCommand : public Command
{
private:
    int index;
    float change;

public:
    ChgIdxIntensityCommand(int i, float _change): index(i), change(_change) {}
    ~ChgIdxIntensityCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.chgIdxIntensityCommand(index, change);
    }
};

#endif // SETIDXINTENSITYCOMMAND_H
