#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"

class MoveCommand: public Command
{
private:
    int index;
    double dx;
    double dy;
    double dz;
public:
    MoveCommand(int i, double x, double y, double z): index(i), dx(x), dy(y), dz(z) {}
    ~MoveCommand() {}
    void execute(AdapterFacade& facade)
    {
        facade.MoveComponent(index,dx,dy,dz);
    }
};

#endif // MOVECOMMAND_H
