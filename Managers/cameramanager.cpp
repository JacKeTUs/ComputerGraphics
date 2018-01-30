#include "CameraManager.h"

CameraManager::CameraManager()
{

}

void CameraManager::UpdateCamera(ListPointer<Component *>::iterator it, const TransformData &data)
{
    if (!cameras.Size())
        return;
    (*it)->Update(data);
}

void CameraManager::AddNewCamera()
{
    Camera* camera = new Camera;
    cameras.push_back(camera);
}

void CameraManager::DeleteCamera(int i)
{
    ListPointer<Component*>::iterator it = cameras.begin();
    it += (i);
    cameras.erase(it);
}

ListPointer<Component*>* CameraManager::getCameras()
{
    return &cameras;
}
