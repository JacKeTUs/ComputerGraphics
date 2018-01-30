#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "Command.h"
#include "Draw/Draw.h"

class DrawCommand : public Command
{
private:
    int index;
    Draw *draw;
    bool showLinks;
    bool showShadows;

public:
    DrawCommand(int i, Draw* obj, bool b, bool s) {index = i; draw = obj; showLinks = b; showShadows = s;}
    ~DrawCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.DrawScene(index, draw, showLinks, showShadows);
    }
};

#endif // DRAWCOMMAND_H
