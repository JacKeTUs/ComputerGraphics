#ifndef CALCULATEFORCESCOMMAND_H
#define CALCULATEFORCESCOMMAND_H
#include "Command.h"

class CalculateForcesCommand: public Command
{
public:
    CalculateForcesCommand() {}
    ~CalculateForcesCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.CalculateAllForces();
    }
};

#endif // CALCULATEFORCESCOMMAND_H
