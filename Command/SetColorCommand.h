#ifndef SETCOLORCOMMAND_H
#define SETCOLORCOMMAND_H

#include "Command.h"

class SetColorCommand : public Command
{    
private:
    int index;
    QColor color;

public:
    SetColorCommand(int _i, QColor _color): index(_i), color(_color) {}

    ~SetColorCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.SetModelColor(index, color);
    }
};

#endif // SETCOLORCOMMAND_H
