#ifndef ROTATEMODELCOMMAND_H
#define ROTATEMODELCOMMAND_H

#include "Command.h"

class RotateModelCommand : public Command
{
private:
    int index;
    double dx;
    double dy;
    double dz;
public:
    RotateModelCommand(int i, double x, double y, double z): index(i), dx(x), dy(y), dz(z) {}
    ~RotateModelCommand() {}
    void execute(AdapterFacade& facade)
    {
        facade.RotateModel(index, dx, dy, dz);
    }
};

#endif // ROTATEMODELCOMMAND_H
