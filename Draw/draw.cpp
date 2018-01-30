#include "Draw.h"
#include "Strategy/ProjectMatrix.h"

Draw::Draw() : AbstractDraw()
{
    image = new QImage();
}

Draw::Draw(const Draw& obj)
    : AbstractDraw()
{
    height = obj.height;
    width = obj.width;
}

Draw& Draw::operator = (const Draw& obj)
{
    height = obj.height;
    width = obj.width;
    image = obj.image;
    zBuffer = obj.zBuffer;
    //delete image;

    return *this;
}

Draw::~Draw()
{
    delete image;
}

void Draw::DrawPointWithZBuf(Vec3i *P, QColor color, double ity)
{
    color.setRed(color.red() * ity);
    color.setGreen(color.green() * ity);
    color.setBlue(color.blue() * ity);

    P->y = image->height() - P->y;
    if (P->z > zBuffer->getZ(P->x, P->y))
    {
        zBuffer->setZ(P->z, P->x, P->y);
        if (!(P->x >= image->width() || P->y >= image->height() || P->x < 0 || P->y < 0))
            image->setPixel(P->x, P->y, color.rgba());
    }
}

void Draw::DrawLine(Vec3i A, Vec3i B, QColor color, double ityA, double ityB)
{
    ///******ЦДА***********

    Vec3f P, dfPoint;
    Vec3i diPoint;
    int     i, l;
    double   dx = B.x - A.x,
            dy = B.y - A.y,
            dz = B.z - A.z,
            dP = ityB - ityA,
            ityP = ityA;

    // 4 Найдём l
    l = MAX(fabsf(dx), fabsf(dy));

    // 5.
    dx = (double) dx / l;
    dy = (double) dy / l;
    dz = (double) dz / l;
    dP = (double) dP / l;

    dfPoint = Vec3f(dx,dy,dz);
    P = Vec3f(A.x, A.y, A.z);
    for (i = 0; i < l+1; i++)
    {
        diPoint = Vec3i(ROUND(P.x), ROUND(P.y), ROUND(P.z));
        DrawPointWithZBuf(&diPoint, color, ityP);
        // P = P + Vec3f(dx, dy, dz);

        P.x += dx;
        P.y += dy;
        P.z += dz;
        ityP += dP;
    }
}

void Draw::DrawTriangle(Vec3i t0, Vec3i t1, Vec3i t2,
                  QColor color, double ity1, double ity2, double ity3)
{
    if ( (((t0.x < 0) || (t0.x >= this->width))
         &&
         ((t0.y < 0) || (t0.y >= this->height)))

         &&
         (((t1.x < 0) || (t1.x >= this->width))
         &&
         ((t1.y < 0) || (t1.y >= this->height)))
         &&
         (((t2.x < 0) || (t2.x >= this->width))
         &&
         ((t2.y < 0) || (t2.y >= this->height)))
         )
        return;

    uint64_t t;
    int     y,
            x1, y1, z1,
            x2, y2, z2,
            x3, y3, z3;

    if (t0.y == t1.y && t0.y == t2.y)
        return;

    t = rdtsc();

    x1 = t0.x;
    y1 = t0.y;
    z1 = t0.z;

    x2 = t1.x;
    y2 = t1.y;
    z2 = t1.z;

    x3 = t2.x;
    y3 = t2.y;
    z3 = t2.z;

    // растеризация треугольника
    // Упорядочиваем точки p1(x1, y1), p2(x2, y2), p3(x3, y3)
    if (y2 < y1)
    {
        std::swap(y1, y2);
        std::swap(x1, x2);
        std::swap(z1, z2);

        std::swap(ity1, ity2);
    }
    // точки p1, p2 упорядочены
    if (y3 < y1)
    {
        std::swap(y1, y3);
        std::swap(x1, x3);
        std::swap(z1, z3);

        std::swap(ity1, ity3);
    }
    // точки p1, p3 упорядочены
    // теперь p1 самая верхняя
    // осталось упорядочить p2 и p3
    if (y2 > y3)
    {
        std::swap(y2, y3);
        std::swap(x2, x3);
        std::swap(z2, z3);

        std::swap(ity2, ity3);
    }

    // приращения по оси x для трёх сторон
    // треугольника
    double dx13 = 0, dx12 = 0, dx23 = 0,
          dz13 = 0, dz12 = 0, dz23 = 0,
          dp13 = 0, dp12 = 0, dp23 = 0;

    // вычисляем приращения
    // в случае, если ординаты двух точек
    // совпадают, приращения
    // полагаются равными нулю
    if (y3 != y1)
    {
        dx13 = x3 - x1;
        dx13 /= y3 - y1;

        dz13 = z3 - z1;
        dz13 /= y3 - y1;

        dp13 = ity3 - ity1;
        dp13 /= y3 - y1;
    }
    if (y2 != y1)
    {
        dx12 = x2 - x1;
        dx12 /= (y2 - y1);

        dz12 = z2 - z1;
        dz12 /= y2 - y1;

        dp12 = ity2 - ity1;
        dp12 /= y2 - y1;
    }
    if (y3 != y2)
    {
        dx23 = x3 - x2;
        dx23 /= (y3 - y2);

        dz23 = z3 - z2;
        dz23 /= y3 - y2;

        dp23 = ity3 - ity2;
        dp23 /= y3 - y2;
    }

    // "рабочие точки"
    // изначально они находятся в верхней точке
    double wx1 = x1,
          wx2 = wx1,
          wz1 = z1,
          wz2 = wz1,

          wp1 = ity1,
          wp2 = wp1;

    // растеризуем верхний полутреугольник
    for (y = y1; y < y2; y++, wx1 += dx13, wx2 += dx12, wz1 += dz13, wz2 += dz12, wp1 += dp13, wp2 += dp12)
    {
        // рисуем горизонтальную линию между рабочими точками
       // painter->drawLine(QPoint(wx1, y),QPoint(wx2, y));
        DrawLine(Vec3i(wx1, y, wz1), Vec3i(wx2, y, wz2), color, wp1, wp2);
    }

    // вырожденный случай, когда верхнего полутреугольника нет
    // надо разнести рабочие точки по оси x,
    // т.к. изначально они совпадают
    if (y1 == y2)
    {
        wx1 = x1;
        wx2 = x2;
        wz1 = z1;
        wz2 = z2;

        wp1 = ity1;
        wp2 = ity2;
    }
    // растеризуем нижний полутреугольник
    for (y = y2; y <= y3; y++, wx1 += dx13, wx2 += dx23, wz1 += dz13, wz2 += dz23, wp1 += dp13, wp2 += dp23)
    {
        // рисуем горизонтальную линию между рабочими точками
        //painter->drawLine(QPoint(wx1, y),QPoint(wx2, y));
        DrawLine(Vec3i(wx1, y, wz1), Vec3i(wx2, y, wz2), color, wp1, wp2);
    }
    t = rdtsc() - t;
    //qDebug("%llu", t);
}

Vec3i Draw::ProjectIntoScreen(Vec3f worldCoords)
{
    Vec3i resultI;
    int dx = this->width/2;
    int dy = this->height/2;
    int dScreen = MIN(dx, dy);

    resultI.x = ROUND((worldCoords.x * dScreen / 2) + dx);
    resultI.y = ROUND((worldCoords.y * dScreen / 2) + dy);
    resultI.z = ROUND((worldCoords.z * 250));

    return resultI;
}

void Draw::FillCanvas(QColor fillColor)
{
    zBuffer->initZBuf(INT_MIN);
    image->fill(fillColor.rgb());
}

void Draw::setImage(QImage *img)
{
    if (image)
        delete image;
    image = img;
    setSizeZBuf(image->width(), image->height());
}

QImage* Draw::getImage()
{
    return image;
}
