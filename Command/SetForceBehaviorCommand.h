#ifndef SETFORCEBEHAVIORCOMMAND_H
#define SETFORCEBEHAVIORCOMMAND_H

#include "Command.h"

class SetForceBehaviorCommand : public Command
{
private:
    ForceBehavior f;

public:
    SetForceBehaviorCommand(ForceBehavior _f) : f(_f) {}
    ~SetForceBehaviorCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.setModelBehavior(f);
    }
};

#endif // SETFORCEBEHAVIORCOMMAND_H
