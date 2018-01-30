#ifndef LIGHTSOURCEMANAGER_H
#define LIGHTSOURCEMANAGER_H

#include "BaseManager.h"
#include "./Composite/LightSource.h"
#include "Composite/Composite.h"

#define LIGHTSOURCE(a) ((LightSource*)(*a))

class LightSourceManager : public BaseManager
{
private:
    // Список источников
    Composite sources;

    int selectedIdx;

public:
    LightSourceManager() {selectedIdx = -1;}

    void addNewSource(Point loc, float intensity = 1)
    {
        LightSource *s = new LightSource;
        s->setLocation(loc);
        s->setIntensity(intensity);
        sources.Add(s);
    }

    void selectILightSource(int idx)
    {
        ListPointer<Component*>::iterator it = sources.CreateComponentsIterator();
        it += (selectedIdx);
        if (!it.IsDone())
            ((LightSource*)(*it))->select(0);
        it = sources.CreateComponentsIterator();
        it += (idx);
        if (!it.IsDone())
        {
            ((LightSource*)(*it))->select(1);
            selectedIdx = idx;
        }
    }

    LightSource* getISource(int idx)
    {
        ListPointer<Component*>::iterator it = sources.CreateComponentsIterator();
        it += (idx);
        if (!it.IsDone())
            return LIGHTSOURCE(it);
        return NULL;
    }

    void updateISource(int idx, const TransformData& data)
    {
        ListPointer<Component*>::iterator it = sources.CreateComponentsIterator();
        it += (idx);
        if (!it.IsDone())
            LIGHTSOURCE(it)->Update(data);
    }

    Composite* getComposite()
    {
        return &sources;
    }

    void deleteISource(int i)
    {
        ListPointer<Component*>::iterator it = sources.CreateComponentsIterator();
        it += (i);
        if (!it.IsDone())
            sources.Remove(it);
    }

};

#endif // LIGHTSOURCEMANAGER_H
