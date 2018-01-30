#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "Component.h"

class Composite: public Component
{
private:   
    ListPointer<Component*> components;
    ListPointer<Component*>::iterator iter_model;

public:
    Composite();
    ~Composite();

    int getComponentsNumber();
    bool Add(Component* comp);

    bool Remove(ListPointer<Component*>::iterator it);

    ListPointer<Component*>::iterator CreateComponentsIterator();

    void Drawing(Component *cam, Draw *);
};

#endif // COMPOSITE_H
