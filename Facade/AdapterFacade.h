#ifndef ADAPTERFACADE_H
#define ADAPTERFACADE_H

#include "Facade.h"
#include "AbstractInterface.h"
#include "Stream/CloseStream.h"
#include "Stream/OpenStream.h"

class AdapterFacade: private Facade, public AbstractInterface
{
public:
     AdapterFacade() {}
     ~AdapterFacade() {}

     /// Движение камеры
     void MoveComponent(int, double, double, double);
     void ZoomComponent(int, double, double, double);
     void RotateComponent(int, double, double, double);

     /// Движение модели
     void MoveModel(int, double, double, double);
     void RotateModel(int, double, double, double);
     void ZoomModel(int, double, double, double);
     void setVel(int, double, double, double);

     /// Изменение модели
     void SelectModel(int idx);
     int getLastIdx();
     void SetModelColor(int, QColor);
     void addModel(char*);
     void deleteModel(int);
     void setModelBehavior(ForceBehavior fb);

     /// Изменение камеры
     void addCamera();
     void deleteIdxCamera(int i);
     void DrawScene(int, Draw*, bool showLinks, bool showShadows);

     /// Связи
     void addLink(int, int, double);
     void deleteLink(int index);
     void CalculateAllForces();
     void SetLinkColor(int, QColor);
     int getLastLinkIdx();
     void selectLink(int idx);

     /// Источники света
     void addLightSource(int, int, int, int intensity = 1);
     void moveLightSource(int, int, int, int);
     int getLastLightSourceIdx();
     void SelectLightSource(int i);
     void deleteIdxLightSource(int i);
     void chgIdxIntensityCommand(int i, float c);

     void setBGColor(QColor color);
};

#endif // ADAPTERFACADE_H
