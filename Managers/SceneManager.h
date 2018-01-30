#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "BaseManager.h"
#include "Composite/Composite.h"
#include "./Composite/Camera.h"
#include "./Composite/LightSource.h"

class SceneManager : public BaseManager
{
private:
    QColor BGColor;

public:
    SceneManager();
    void DrawingScene(Composite *models,                        /*! < Модели */
                      Camera *cam,                              /*! < Камера */
                      Draw* draw,                               /*! < Сцена */
                      Composite *links                          /*! < Связи */,
                      Composite *lightSources,                  /*! < Источники света */
                      bool showLinks = true                     /*! < Показывать ли связи? */,
                      bool showShadows = false                  /*! < Показывать ли тени? */ );
    void setBGColor(QColor c);
};

#endif // SCENEMANAGER_H
