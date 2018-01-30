#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include "DeleteCommand.h"
#include "AddCameraCommand.h"
#include "AddModelCommand.h"
#include "AddLinkCommand.h"
#include "DrawCommand.h"
#include "MoveCommand.h"
#include "ZoomCommand.h"
#include "RotateCommand.h"
#include "MoveModelCommand.h"
#include "CalculateForcesCommand.h"
#include "DeleteLinkCommand.h"
#include "SetVelCommand.h"
#include "SetColorCommand.h"
#include "SelectModelCommand.h"
#include "ZoomModelCommand.h"
#include "AddLightSourceCommand.h"
#include "MoveLightSourceCommand.h"
#include "SelectLightSourceCommand.h"
#include "SetForceBehaviorCommand.h"
#include "SelectLinkCommand.h"
#include "SetBGColorCommand.h"
#include "SetColorCommand.h"
#include "SetLinkColorCommand.h"
#include "DeleteICameraCommand.h"
#include "DeleteLightSourceCommand.h"
#include "ChgIdxIntensityCommand.h"

class MacroCommand: public Command
{
private:
    ListPointer<Command*> cmd;

public:
    MacroCommand() {}
    ~MacroCommand() {cmd.clean();}

    void addCommand(Command* command) {cmd.push_back(command);}
    void cleanCommandList() {cmd.clean();}

    void execute(AdapterFacade &facade)
    {
        ListPointer<Command*>::iterator it = cmd.begin();
        for (; !it.IsDone(); ++it)
            (*it)->execute(facade);
    }

};

#endif // MACROCOMMAND_H
