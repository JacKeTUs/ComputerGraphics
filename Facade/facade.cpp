#include "Facade.h"

Facade::Facade()
{

}

Facade::~Facade()
{

}

///****ModelManager*******************
void Facade::LoadModel(std::ifstream& stream)
{
    model_mgr.LoadModel(stream);
}

void Facade::deleteIdxModel(int index_model)
{
    Model *m; ///< Удаляемая модель
    int i = 0;
    m = model_mgr.GetIModel(index_model);

    // Удаляем связи к модели
    while(i < link_mgr.getComposite()->getComponentsNumber())
    {
        if ((link_mgr.getILink(i)->getSourceModel() == m) ||
           (link_mgr.getILink(i)->getDestModel() == m))
        {
            link_mgr.DeleteLink(i); ///< Удалить связь
            i = -1;
        }
        i++;
    }



    model_mgr.DeleteModel(index_model);
}

void Facade::UpdateModel(int idx, TransformData data)
{
    model_mgr.TransformModel(idx, data);
}

void Facade::CalculateAll()
{
    model_mgr.calculateAll(link_mgr.getComposite());
}

void Facade::SetColor(int index, QColor color)
{
    model_mgr.setModelColor(index, color);
}

int Facade::getLastModelIdx()
{
    return model_mgr.getLastIdx();
}

void Facade::setSelectModel(int index)
{
    model_mgr.selectIModel(index);
}

///****CameraManager*******************
void Facade::UpdateCamera(ListPointer<Component*>::iterator it, const TransformData& data)
{
    camera_mgr.UpdateCamera(it, data);
}

void Facade::AddNewCamera()
{
    camera_mgr.AddNewCamera();
}

///****SceneManager********************
void Facade::DrawingScene(Camera* cam, Draw* draw, bool showLinks, bool showShadows)
{
    scene_mgr.DrawingScene(model_mgr.getComposite(), cam, draw, link_mgr.getComposite(), lightSource_mgr.getComposite(), showLinks, showShadows);
}

///****LinkManager*********************
void Facade::AddLink(Model* m1, Model* m2, double tension)
{
    link_mgr.AddLink(m1,m2,tension);
}

void Facade::DeleteLink(int index)
{
    link_mgr.DeleteLink(index);
}

void Facade::setVelocity(int idx, double x, double y, double z)
{
    model_mgr.GetIModel(idx)->setVelocity(Vec3f(x,y,z));
    model_mgr.GetIModel(idx)->appendVelocity();
}

void Facade::UpdateLightSource(int idx, const TransformData& data)
{
    lightSource_mgr.updateISource(idx, data);
}
