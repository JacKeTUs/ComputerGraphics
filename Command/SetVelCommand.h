#ifndef SETVELCOMMAND_H
#define SETVELCOMMAND_H

#include "Command.h"

class SetVelCommand : public Command
{
private:
    int index;
    double dx;
    double dy;
    double dz;
public:
    SetVelCommand(int i, double x, double y, double z): index(i), dx(x), dy(y), dz(z) {}
    ~SetVelCommand() {}
    void execute(AdapterFacade& facade)
    {
        facade.setVel(index, dx, dy, dz);
    }
};

#endif // SETVELCOMMAND_H
