#ifndef FACADE_H
#define FACADE_H

///#include "Composite/Composite.h"
#include "Composite/Camera.h"
#include "Builder/ModelBuilder.h"
#include "Managers/ModelManager.h"
#include "Managers/CameraManager.h"
#include "Managers/SceneManager.h"
#include "Managers/LinkManager.h"
#include "Managers/LightSourceManager.h"

class Facade
{
protected:
    ModelManager model_mgr;
    CameraManager camera_mgr;
    SceneManager scene_mgr;
    LinkManager link_mgr;
    LightSourceManager lightSource_mgr;

public:
    Facade();
    ~Facade();

    ///****ModelManager*******************
    void LoadModel(std::ifstream& stream);

    void deleteIdxModel(int index_model);

    void UpdateModel(int idx, TransformData data);

    void CalculateAll();

    void SetColor(int index, QColor color);

    int getLastModelIdx();

    void setSelectModel(int index);

    ///****CameraManager*******************
    void UpdateCamera(ListPointer<Component*>::iterator it, const TransformData& data);

    void AddNewCamera();

    ///****SceneManager********************
    void DrawingScene(Camera *cam, Draw* draw, bool showLinks, bool showShadows);


    ///****LinkManager*********************
    void AddLink(Model* m1, Model* m2, double tension);

    void DeleteLink(int index);

    void setVelocity(int idx, double x, double y, double z);

    ///****LightSourceManager**************
    void UpdateLightSource(int idx, const TransformData& data);
};

#endif // FACADE_H
