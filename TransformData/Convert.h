#ifndef CONVERT_H
#define CONVERT_H

#include "TransformData/TransformData.h"
#include "TransformMatrix/TransformMatrix.h"
#include "Strategy/TransformInterface.h"
#include "Strategy/OffsetMatrix.h"
#include "Strategy/RotateMatrix.h"
#include "Strategy/ZoomMatrix.h"
#include "Strategy/ProjectMatrix.h"

class Convert
{
public:
    Convert();
    static TransformMatrix DataToMatrix(const TransformData& obj)
    {
        //TransformInterface transform_interface;
        TransformMatrix matr;

        OffsetMatrix    *om = new OffsetMatrix;
        RotateMatrix    *rm = new RotateMatrix;
        ZoomMatrix      *zm = new ZoomMatrix;
      //  ProjectMatrix   *pm = new ProjectMatrix;
//
        /*
        transform_interface.setPointer(om);
        matr = transform_interface.getTransformMatrix(obj);

        transform_interface.setPointer(rm);
        matr = matr * transform_interface.getTransformMatrix(obj);

        transform_interface.setPointer(zm);
        matr = matr * transform_interface.getTransformMatrix(obj);
        */
        matr = om->getTransformMatrix(obj);
        delete om;
        matr = matr * rm->getTransformMatrix(obj);
        delete rm;
        matr = matr * zm->getTransformMatrix(obj);
        delete zm;
        //matr = matr * pm->getMatrix();

        //delete om;
        //delete rm;
        //delete zm;
        return matr;
    }
};

#endif // CONVERT_H
