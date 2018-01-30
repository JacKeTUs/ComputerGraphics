#ifndef CAMERA_H
#define CAMERA_H

#include "Component.h"
//#include "Model.h"
#include "Strategy/TransformInterface.h"
#include "Strategy/OffsetMatrix.h"
#include "Strategy/RotateMatrix.h"
#include "Strategy/ZoomMatrix.h"


class Camera: public Component
{
protected:
    TransformMatrix TrMatrix;

public:
    Camera() {}
    Camera(const Camera&);
    Camera& operator= (const Camera&);
    ~Camera() {}

    void Update(const TransformData &AppEnd)
    {
        Data += AppEnd;
        TrMatrix = Convert::DataToMatrix(Data);
    }
    void setTransformMatrix(TransformMatrix matr)
    {
        TrMatrix = matr;
    }

    TransformMatrix getTransformMatrix()
    {
        return TrMatrix;
    }

};

#endif // CAMERA_H
