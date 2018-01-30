#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H
#include "BaseManager.h"
#include "Composite/Camera.h"

class CameraManager : public BaseManager
{
protected:
    // Список камер
    ListPointer<Component*> cameras;

public:
    CameraManager();

    void DeleteCamera(int i);
    void UpdateCamera(ListPointer<Component*>::iterator it, const TransformData& data);
    void AddNewCamera();
    ListPointer<Component*>* getCameras();
};

#endif // CAMERAMANAGER_H
