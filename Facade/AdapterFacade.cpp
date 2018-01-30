#include "AdapterFacade.h"

void AdapterFacade::deleteModel(int index)
{
    deleteIdxModel(index);
}

void AdapterFacade::MoveComponent(int index, double x, double y, double z)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();

    if(index <= camera_mgr.getCameras()->Size()-1)
    {
        it += index;
        Offset offset(x, y, z);
        TransformData data;
        data.setOffset(offset);

        UpdateCamera(it, data);
    }
}

void AdapterFacade::MoveModel(int index, double x, double y, double z)
{
    if ((!camera_mgr.getCameras()->Size()))
        return;

    Offset offset(x, y, z);
    TransformData data;
    data.setOffset(offset);

    UpdateModel(index, data);
}

void AdapterFacade::RotateModel(int index, double x, double y, double z)
{
    if ((!camera_mgr.getCameras()->Size()))
        return;

    Point cp = model_mgr.GetIModel(index)->getCenterPoint();
    Rotate rotate(x, y, z, cp.getX(), cp.getY(), cp.getZ());
    TransformData data;
    data.setRotate(rotate);

    UpdateModel(index, data);
}

void AdapterFacade::ZoomModel(int index, double x, double y, double z)
{
    if ((!camera_mgr.getCameras()->Size()))
        return;

    Point cp = model_mgr.GetIModel(index)->getCenterPoint();
    Zoom zoom(x, y, z, cp.getX(), cp.getY(), cp.getZ());
    TransformData data;
    data.setZoom(zoom);

    UpdateModel(index, data);
}

void AdapterFacade::ZoomComponent(int index, double x, double y, double z)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();

    if(index <= camera_mgr.getCameras()->Size()-1)
    {
        it += index;
        Zoom zoom(x, y, z);
        TransformData data;
        data.setZoom(zoom);

        UpdateCamera(it, data);
    }
}

void AdapterFacade::RotateComponent(int index, double x, double y, double z)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();

    if(index <= camera_mgr.getCameras()->Size()-1)
    {
        it += index;
        Rotate rotate(x, y, z);
        TransformData data;
        data.setRotate(rotate);

        UpdateCamera(it, data);
    }
}

void AdapterFacade::setVel(int idx, double a, double b, double c)
{
    if (!model_mgr.getComposite()->getComponentsNumber())
        return;
    if (idx > model_mgr.getComposite()->getComponentsNumber()-1)
        return;

    setVelocity(idx, a,b,c);
}

void AdapterFacade::addModel(char* file_name)
{
    OpenStream stream;
    std::ifstream fin;
    stream.getStream(fin, file_name);
    LoadModel(fin);
    CloseStream close_stream;
    close_stream.Close(fin);
}

void AdapterFacade::addCamera()
{
    AddNewCamera();
}

void AdapterFacade::deleteIdxCamera(int i)
{
    camera_mgr.DeleteCamera(i);
}

void AdapterFacade::DrawScene(int camera_index, Draw* draw, bool showLinks, bool showShadows)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    // Начало списка камер
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();

    if(camera_index <= camera_mgr.getCameras()->Size()-1)
    {
        // Переходим на нужную камеру
        it += camera_index;
        // Получаем нужную камеру
        Camera *tmp = (Camera*)(*it);

        // Рисуем то, что видит нужная камера
        DrawingScene(tmp, draw, showLinks, showShadows);
    }
}

void AdapterFacade::addLink(int m1, int m2, double tension)
{
    AddLink(model_mgr.GetIModel(m1), model_mgr.GetIModel(m2), tension);
}

void AdapterFacade::deleteLink(int index)
{   
    if (!link_mgr.getComposite()->getComponentsNumber())
        return;

    DeleteLink(index);
}

void AdapterFacade::CalculateAllForces()
{
    CalculateAll();
}

void AdapterFacade::SetModelColor(int index, QColor color)
{
    if ((!camera_mgr.getCameras()->Size()))
        return;

   SetColor(index, color);
}

void AdapterFacade::SetLinkColor(int index, QColor color)
{
    if ((!camera_mgr.getCameras()->Size()))
        return;

   link_mgr.setIColor(index, color);
}


void AdapterFacade::addLightSource(int x, int y, int z, int intensity)
{
    lightSource_mgr.addNewSource(Point(x, y, z), intensity);
}

void AdapterFacade::moveLightSource(int idx, int dx, int dy, int dz)
{
    TransformData data;
    Offset o;
    o.set_dx(dx);
    o.set_dy(dy);
    o.set_dz(dz);
    data.setOffset(o);
    UpdateLightSource(idx, data);
}

void AdapterFacade::SelectModel(int idx)
{
    setSelectModel(idx);
}

int AdapterFacade::getLastIdx()
{
    return model_mgr.getComposite()->getComponentsNumber()-1;
}

void AdapterFacade::setModelBehavior(ForceBehavior fb)
{
    model_mgr.setForceBehavior(fb);
}

int AdapterFacade::getLastLinkIdx()
{
    return link_mgr.getComposite()->getComponentsNumber()-1;
}

int AdapterFacade::getLastLightSourceIdx()
{
    return lightSource_mgr.getComposite()->getComponentsNumber()-1;
}

void AdapterFacade::SelectLightSource(int i)
{
    lightSource_mgr.selectILightSource(i);
}

void AdapterFacade::selectLink(int idx)
{
    link_mgr.SelectILink(idx);
}

void AdapterFacade::setBGColor(QColor color)
{
    scene_mgr.setBGColor(color);
}

void AdapterFacade::deleteIdxLightSource(int i)
{
    lightSource_mgr.deleteISource(i);
}

void AdapterFacade::chgIdxIntensityCommand(int i, float c)
{
    (lightSource_mgr.getISource(i))->setIntensity((lightSource_mgr.getISource(i))->getIntensity() + c);
}
