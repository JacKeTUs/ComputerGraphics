#ifndef POINT_H
#define POINT_H

//#include "TransformMatrix/Matrix.h"
#include "TransformMatrix/TransformMatrix.h"

class Point
{
private:
    double x;
    double y;
    double z;
public:
    Point(): x(0.0),y(0.0),z(0.0) {}
    Point(double x_val, double y_val, double z_val) {x = x_val; y = y_val; z = z_val;}
    void setPoint(double x_val, double y_val, double z_val) {x = x_val; y = y_val; z = z_val;}

    Point& operator=(Point);
    Point operator-(Point a)
    {
        Point result;
        result.setX(this->getX() - a.getX());
        result.setY(this->getY() - a.getY());
        result.setZ(this->getZ() - a.getZ());
        return result;
    }

    Point getPoint() {return *this;}
    void setX(double value) {x = value;}
    void setY(double value) {y = value;}
    void setZ(double value) {z = value;}
    double getX() const {return x;}
    double getY() const {return y;}
    double getZ() const {return z;}

    double& operator[] (int idx) {
        switch (idx)
        {
            case 0:
              return x;
            break;
            case 1:
              return y;
            break;
            case 2:
              return z;
            break;
            default:
                break;
        }
        return x;
    }

    static Vec3f ToVec3f(Point pnt)
    {
        Vec3f result;
        int i = 0;
        for (i = 0; i < 3; i++)
            result[i] = pnt[i];
        return result;
    }

    static Vec3i ToVec3i(Point pnt)
    {
        Vec3i result;
        int i = 0;
        for (i = 0; i < 3; i++)
            result[i] = roundf(pnt[i]);
        return result;
    }

    Point Transform(const TransformMatrix tr_matrix)
    {
        Point point;
        Point tmp = (*this);
        point.setX(tmp.getX() * tr_matrix.getVal(0, 0) +
                   tmp.getY() * tr_matrix.getVal(1, 0) +
                   tmp.getZ() * tr_matrix.getVal(2, 0) + tr_matrix.getVal(3,0));

        point.setY(tmp.getX() * tr_matrix.getVal(0, 1) +
                   tmp.getY() * tr_matrix.getVal(1, 1) +
                   tmp.getZ() * tr_matrix.getVal(2, 1) + tr_matrix.getVal(3, 1));

        point.setZ(tmp.getX() * tr_matrix.getVal(0, 2) +
                   tmp.getY() * tr_matrix.getVal(1, 2) +
                   tmp.getZ() * tr_matrix.getVal(2, 2) + tr_matrix.getVal(3, 2));
        return point;
    }
    Point TransformRev(const TransformMatrix tr_matrix)
    {
        Point point;
        Point tmp = (*this);
        point.setX(tmp.getX() * tr_matrix.getVal(0, 0) +
                   tmp.getY() * tr_matrix.getVal(0, 1) +
                   tmp.getZ() * tr_matrix.getVal(0, 2) + tr_matrix.getVal(0, 3));

        point.setY(tmp.getX() * tr_matrix.getVal(1, 0) +
                   tmp.getY() * tr_matrix.getVal(1, 1) +
                   tmp.getZ() * tr_matrix.getVal(1, 2) + tr_matrix.getVal(1, 3));

        point.setZ(tmp.getX() * tr_matrix.getVal(2, 0) +
                   tmp.getY() * tr_matrix.getVal(2, 1) +
                   tmp.getZ() * tr_matrix.getVal(2, 2) + tr_matrix.getVal(2, 3));
        return point;
    }
};

#endif // POINT_H
