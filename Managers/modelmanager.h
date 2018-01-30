#ifndef MODELMANAGER_H
#define MODELMANAGER_H
#include "BaseManager.h"
#include "Builder/ModelBuilder.h"
#include <Composite/Composite.h>
#include "Composite/Link.h"

#define MODEL(a) ((Model*)(*a))
#define LINK(a)  ((Link*)(*a))

enum ForceBehavior
{
    ForceIn,
    ForceOut,
    NoForce
};

class ModelManager : public BaseManager
{
private:
    int selectedIdx;
    ForceBehavior fb;

protected:
    // Композит моделей
    Composite comp;

    // Список композитов для "других" моделей
    ListPointer<Composite*> others;

public:
    ModelManager();

    int getLastIdx();

    void LoadModel(std::ifstream& stream);

    Model* GetIModel(int idx);

    void DeleteModel(int index_model);

    void TransformModel(int index_model, TransformData tr);

    Composite* getComposite();

    void calculateAll(Composite* links);

    void setModelColor(int index_model, QColor color);

    void selectIModel(int index_model);

    Composite othersForIModel(int index);

    void UpdateOtherModels4All();

    void setForceBehavior(ForceBehavior f)
    {
        fb = f;
    }
};

#endif // MODELMANAGER_H
