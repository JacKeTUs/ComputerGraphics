#ifndef ADAPTERTRANSFORM_H
#define ADAPTERTRANSFORM_H

#include "Matrix.h"

class TransformMatrix: public Matrix<double>
{
public:
    TransformMatrix();
    TransformMatrix(const TransformMatrix&);
    ~TransformMatrix();

    using Matrix<double>::operator *;
    using Matrix<double>::operator =;

    void createRotateXMatrix(double);
    void createRotateYMatrix(double);
    void createRotateZMatrix(double);
    void createMoveMatrix(double,double,double);
    void createZoomMatrix(double,double,double);
    void createLookAtMatrix(Vec3f eye, Vec3f center, Vec3f up);
};

#endif // ADAPTERTRANSFORM_H
