#ifndef SETBGCOLORCOMMAND_H
#define SETBGCOLORCOMMAND_H

#include "Command.h"

class SetBGColorCommand : public Command
{
private:
    QColor color;

public:
    SetBGColorCommand(QColor _color): color(_color) {}

    ~SetBGColorCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.setBGColor(color);
    }
};

#endif // SETBGCOLORCOMMAND_H
