#include "link.h"
//#define DEBUG_INFO

Link::Link()
{
    color = Qt::blue;
    selected = false;
}

Link::~Link()
{

}


Link::Link(Model* a, Model* b, double t) : p1(a), p2(b), tension(t)
{
    baseLength = Model::getDistance(p1, p2)+2;
    color = Qt::blue;
    selected = false;
 //   qDebug("BASE LENGTH OF THE LINK: %f", baseLength);
   // qDebug("BASE TENSION OF THE LINK: %f", tension);
}

void Link::CalculateForces()
{
    Vec3f pr1, pr2;
    Vec3f vel1 = p1->getVelocity();
    Vec3f vel2 = p2->getVelocity();
#ifdef DEBUG_INFO
       qDebug("BEGIN LINK CALCULATE");

vouf;]
[PFOJQS]\[PE]

      qDebug("BEFORE");
      qDebug("vel1 = %f, %f, %f", vel1.x,vel1.y,vel1.z);
      qDebug("vel2 = %f, %f, %f", vel2.x,vel2.y,vel2.z);
#endif
    Point vec;

    double  koef,
            b = this->getLength(),
            F = ((b - baseLength) / (2*this->tension)), // Сила упругости (удлинение на коэффициент)
            w1w2 = p1->getWeight() / p2->getWeight(),
            w2w1 = p2->getWeight() / p1->getWeight();

#ifdef DEBUG_INFO
    qDebug("w1 / w2 = %f", w1w2);
    qDebug("w2 / w1 = %f", w2w1);
#endif

    if (b == 0)
        return;

    b += vel1.norm() + vel2.norm();
    F = ((b - baseLength) / (2*this->tension));

    /// 1. Вычисляем проекцию силы, тянущей 1 модель, на связь
    vec = (p2->getCenterPoint() - p1->getCenterPoint());
    Vec3f v = Point::ToVec3f(vec);
    v.normalize();
    vec.setX(v.x);
    vec.setY(v.y);
    vec.setZ(v.z);
    // qDebug("VEC 1->2: %f, %f, %f", vec.getX(), vec.getY(), vec.getZ());

    koef = F * w2w1 ;
    pr1.x = vec.getX() * (koef);// / p2->getWeight() ;
    pr1.y = vec.getY() * (koef);// / p2->getWeight();
    pr1.z = vec.getZ() * (koef);// / p2->getWeight() ;

    // qDebug("pr1 = %f, %f, %f", pr1.x,pr1.y,pr1.z);

    /// 2. Вычисляем проекцию силы, тянущей 2 модель, на связь
    vec = (p1->getCenterPoint() - p2->getCenterPoint());
    Vec3f v2 = Point::ToVec3f(vec);
    v2.normalize();
    vec.setX(v2.x);
    vec.setY(v2.y);
    vec.setZ(v2.z);
    //qDebug("VEC 1<-2: %f, %f, %f", vec.getX(), vec.getY(), vec.getZ());

    koef = F * w1w2;
    pr2.x = vec.getX() * (koef);// / p1->getWeight();
    pr2.y = vec.getY() * (koef);// / p1->getWeight();
    pr2.z = vec.getZ() * (koef);// / p1->getWeight();
    //  qDebug("pr2 = %f, %f, %f", pr2.x,pr2.y,pr2.z);


    /*
          p1                              p2
     vel1 o--pr2->------vec-----<-pr1--o vel2
         pr1                               pr2
    */

    p1->setTempVelocity(pr1);
    p2->setTempVelocity(pr2);

#ifdef DEBUG_INFO
    qDebug("TEMP_V");
    qDebug("vel1 = %f, %f, %f", pr1.x,pr1.y,pr1.z);
    qDebug("vel2 = %f, %f, %f", pr2.x,pr2.y,pr2.z);
#endif
}

void Link::Drawing(Component* cam, Draw* draw)
{
    draw->DrawLine(p1->getTransformCenterPoint(cam, draw),
                   p2->getTransformCenterPoint(cam, draw), (selected? color.lighter(140) : color));
}
Model* Link::getSourceModel()
{
    return p1;
}

Model* Link::getDestModel()
{
    return p2;
}

double Link::getLength()
{
    return Model::getDistance(p1,p2);
}

double Link::getBaseLength()
{
    return baseLength;
}

double Link::getTension()
{
    return tension;
}

void Link::select(bool isSelected)
{
    selected = isSelected;
}

void Link::setColor(QColor c)
{
    color = c;
}
