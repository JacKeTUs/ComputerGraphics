#ifndef COMPONENT_H
#define COMPONENT_H

#include "TransformData/TransformData.h"
#include "List/ListPointer.h"
#include "Draw/Draw.h"
#include "TransformData/Convert.h"

class Component
{
protected:
    TransformData Data;

public: 
    virtual ~Component() {}
    virtual void Update(const TransformData& AppEnd){Data += AppEnd;}
    virtual bool Add(Component*) {return false;}    
    virtual bool Remove(ListPointer<Component*>::iterator) {return false;}
    virtual void Drawing(Component*, Draw*) {}
    virtual ListPointer<Component*>::iterator* CreateIterator() {return NULL;}
    virtual TransformMatrix getTransformMatrix() {return TransformMatrix();}
};

#endif // COMPONENT_H
