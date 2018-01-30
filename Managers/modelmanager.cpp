#include "ModelManager.h"

ModelManager::ModelManager() :
    selectedIdx(-1)
{
    fb = ForceOut;
}

int ModelManager::getLastIdx()
{
    return (comp.getComponentsNumber() - 1);
}

void ModelManager::LoadModel(std::ifstream& stream)
{
    ModelBuilder builder;
    Model* model = builder.getModel(stream);
    comp.Add(model);

    UpdateOtherModels4All();
}

void ModelManager::UpdateOtherModels4All()
{
    ListPointer<Component*>::iterator iter_model;
    iter_model = comp.CreateComponentsIterator();
    int i = 0;
    int j = 0;
    for (; !iter_model.IsDone(); ++iter_model, i++)
    {
        j = 0;
        Composite *tmp = new Composite;
        ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
        for (; !it.IsDone(); ++it, j++)
            if ((it != iter_model) && (i != j))
                tmp->Add(*it);

        ((Model*)(*iter_model))->setOthersModels(tmp);
    }
}

Model* ModelManager::GetIModel(int idx)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (idx);
    return MODEL(it);
}

void ModelManager::DeleteModel(int index_model)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (index_model);
    if (!it.IsDone())
        comp.Remove(it);

    this->UpdateOtherModels4All();
}

void ModelManager::TransformModel(int index_model, TransformData tr)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (index_model);
    if (!it.IsDone())
        MODEL(it)->Update(tr);
}

Composite* ModelManager::getComposite()
{
    return &comp;
}

void ModelManager::calculateAll(Composite* links)
{
    double xvel = 0;
    double yvel = 0;
    double zvel = 0;
    double koef = 1;

    double dx, dy, dz;
    double l;
    int i, j;
    Point vec;
    ListPointer<Component*>::iterator itModels;
    ListPointer<Component*>::iterator it;

    // Для каждой модели вычисляем её скорости, пока что от отталкивания
    for(itModels = comp.CreateComponentsIterator(), i = 0; i < comp.getComponentsNumber() ; itModels++, i++)
    {
        xvel = 0;
        yvel = 0;
        zvel = 0;
        // Суммируем силы отталкивания от других объектов
        for(it = comp.CreateComponentsIterator(), j = 0; j < comp.getComponentsNumber(); it++, j++)
        {
            //stolkn = false;
            xvel = 0;
            yvel = 0;
            zvel = 0;
            if (i == j) continue;

            // F = (m1*m2) / (2*R^2)

            Vec3f v;
            v = Point::ToVec3f(MODEL(itModels)->getCenterPoint() - MODEL(it)->getCenterPoint()).normalize();

            vec = MODEL(itModels)->getCenterPoint() - MODEL(it)->getCenterPoint();

            // Если нет столкновения
            if ((Point::ToVec3f(vec).norm() > 1.3 * (MODEL(it)->getRadius() + MODEL(itModels)->getRadius())))
            {
                koef = (fb == ForceIn? -1 : 1) * MODEL(it)->getWeight()/MODEL(itModels)->getWeight();
                dx = vec.getX();
                dy = vec.getY();
                dz = vec.getZ();
                l = 2 * (dx * dx + dy  * dy + dz * dz);
                if ((l != 0) && (l > Point::ToVec3f(vec).norm()))
                {
                    xvel = dx * (koef) / l;
                    yvel = dy * (koef) / l;
                    zvel = dz * (koef) / l;
                }

                if (fb != NoForce)
                /// Применить новую скорость к модели
                    MODEL(itModels)->setVelocity(Vec3f(xvel, yvel, zvel));

            }
            else    // Если происходит столкновение
            if ((Point::ToVec3f(vec).norm() < (MODEL(it)->getRadius() + MODEL(itModels)->getRadius())))
            {

                koef = MODEL(it)->getWeight()/MODEL(itModels)->getWeight();
                Vec3f v = Point::ToVec3f(vec);
                float l_now = v.norm();
                v.normalize();
                dx = v.x;
                dy = v.y;
                dz = v.z;

                l = (MODEL(it)->getRadius() + MODEL(itModels)->getRadius());

                xvel = dx * (l - l_now) / 8;
                yvel = dy * (l - l_now) / 8;
                zvel = dz * (l - l_now) / 8;

                MODEL(itModels)->setVelocity(Vec3f(xvel * (koef),
                                                   yvel * (koef),
                                                   zvel * (koef)));
                MODEL(it)->setVelocity(Vec3f(-xvel / (koef),
                                             -yvel / (koef),
                                             -zvel / (koef)));
            }
        }
    }

    // вычислить силы связей
    for(it = links->CreateComponentsIterator(), j = 0; j < links->getComponentsNumber(); it++, j++)
    {
        LINK(it)->CalculateForces();
    }

    // Переместить модель
    for(itModels = comp.CreateComponentsIterator(), i = 0; i < comp.getComponentsNumber() ; itModels++, i++)
    {
       // MODEL(itModels)->getVelocity();
        MODEL(itModels)->appendVelocity();
    }

}

void ModelManager::setModelColor(int index_model, QColor color)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (index_model);
    if (!it.IsDone())
        MODEL(it)->setColor(color);
}

void ModelManager::selectIModel(int index_model)
{
    if (index_model == selectedIdx)
        return;

    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();

    if (selectedIdx != -1)
    {
        it += selectedIdx;
        MODEL(it)->setSelect(false);
    }
    it = comp.CreateComponentsIterator();

    it += (index_model);
    if (!it.IsDone())
        MODEL(it)->setSelect(true);

    selectedIdx = index_model;
}

/*!
 * \brief othersForIModel
 * Возврат композита других моделей для i-й модели
 * \param index
 * \return
 */
Composite ModelManager::othersForIModel(int index)
{
    Composite result = comp;
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += index;
    result.Remove(it);
    return result;
}
