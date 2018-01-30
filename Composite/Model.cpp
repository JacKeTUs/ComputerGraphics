#include "Model.h"
/*
#include "./Strategy/projectmatrix.h"
#include "./Strategy/viewportmatrix.h"
*/

float PlaneDistance ( Vec3f vNormal, Vec3f vPoint )
{
    return - ( ( vNormal.x * vPoint.x ) + ( vNormal.y * vPoint.y ) + ( vNormal.z * vPoint.z ) );
}

bool IntersectedPlane(Vec3f Poly[], Vec3f line1, Vec3f line2, Vec3f &vNormal, float &originDistance)
{
    float   distance1 = 0,
            distance2 = 0;
    // Вектор нормали к полигону
    vNormal = ((Poly[2] - Poly[0]) ^ (Poly[1] - Poly[0]));

    originDistance = PlaneDistance(vNormal, Poly[0]);

    distance1 = ((vNormal.x * line1.x) + (vNormal.y * line1.y) +
                   (vNormal.z * line1.z)) + originDistance;
    distance2 = ((vNormal.x * line2.x) + (vNormal.y * line2.y) +
                   (vNormal.z * line2.z)) + originDistance;

    if (distance1 * distance2 > 0)
        return false;
    return true;
}

Vec3f IntersectionPoint(Vec3f vNormal, Vec3f line1, Vec3f line2, double distance)
{
    Vec3f vPoint, vLineDir;
    double Numerator = 0.0, Denominator = 0.0, dist = 0.0;

    vLineDir = (line2 - line1).normalize();

    Numerator = - (vNormal.x * line1.x + vNormal.y * line1.y +
           vNormal.z * line1.z + distance);
    Denominator = vNormal * vLineDir;

    if (Denominator == 0.0)
      return line1;

    dist = Numerator / Denominator;

    vPoint.x = (float)(line1.x + (vLineDir.x * dist));
    vPoint.y = (float)(line1.y + (vLineDir.y * dist));
    vPoint.z = (float)(line1.z + (vLineDir.z * dist));

    return vPoint;
}

double AngleBetweenVectors(Vec3f vA, Vec3f vB)
{
    double s = vA * vB;
    return acos(s / (vA.norm() * vB.norm()));
}

bool InsidePolygon(Vec3f vIntersection, Vec3f Poly[], int elNum)
{
    const double MATCH_FACTOR = 0.7;
    double Angle = 0.0;  Vec3f vA, vB;

    for (int i = 0; i < elNum; i++)
    {
        vA = Poly[i] - vIntersection;
        vB = Poly[(i + 1) % elNum] - vIntersection;
        Angle += AngleBetweenVectors(vA, vB);
    }
    if (Angle >= (MATCH_FACTOR * (2.0 * M_PI)) )
        return true;

    return false;
}

/// true - пересечение есть
/// false - нету
bool IntersectedPolygon(Vec3f *Poly, Vec3f line1, Vec3f line2, int elNum)
{
    Vec3f vNormal;
    float originDistance = 0;

    if (!IntersectedPlane(Poly, line1, line2, vNormal, originDistance))
        return false;

    Vec3f vIntersection = IntersectionPoint(vNormal, line1, line2, originDistance);
    if(InsidePolygon(vIntersection, Poly, elNum))
        return true;

    return false;
}

Model::Model()
{
    velocity.x = 0;
    velocity.y = 0;
    velocity.z = 0;
    tempVelocity = velocity;
    selected = false;
    shadows = false;
    radius = 0;
    weight = 1;
}

Model::Model(int kol_koords, int kol_connects, int kol_normales)
{
    setKoords(kol_koords);
    setConnects(kol_connects);
    setNormales(kol_normales);
    selected = false;
    shadows = false;
    radius = 0;
    weight = 1;

}

Model::Model(const Model & obj)
{
    if (obj.polygons.IsEmpty() && obj.koordinates.IsEmpty() && obj.normales.IsEmpty())
    {
        polygons.Delete();
        koordinates.Delete();
        normales.Delete();
    }
    else
    {
        int kol_koords = obj.koordinates.getElementsNumber();
        int kol_normales = obj.normales.getElementsNumber();
        int kol_connects = obj.polygons.getElementsNumber();
        setKoords(kol_koords);
        setConnects(kol_connects);
        setNormales(kol_normales);
        int i = 0;
        for (i = 0; i < kol_koords; i++)
            koordinates.setIPoint(i, obj.koordinates.getIPoint(i));
        for (i = 0; i < kol_normales; i++)
            normales.setIPoint(i, obj.normales.getIPoint(i));
        for (i = 0; i < kol_connects; i++)
            polygons.setIPolygon(i, obj.polygons.getIPolygon(i));
    }
    selected = obj.selected;
    shadows = obj.shadows;
    radius = obj.radius;
    weight = obj.weight;
}

Model& Model::operator= (const Model& obj)
{
    if(&obj == this)
        return *this;
    if (!koordinates.IsEmpty() && !polygons.IsEmpty() && !normales.IsEmpty())
        Delete();
    if (obj.polygons.IsEmpty() || obj.koordinates.IsEmpty() || obj.normales.IsEmpty())
        return *this;

    int kol_koords = obj.koordinates.getElementsNumber();
    int kol_normales = obj.normales.getElementsNumber();
    int kol_connects = obj.polygons.getElementsNumber();

    setKoords(kol_koords);
    setConnects(kol_connects);
    setNormales(kol_normales);
    int i = 0;
    for (i = 0; i < kol_koords; i++)
        koordinates.setIPoint(i, obj.koordinates.getIPoint(i));
    for (i = 0; i < kol_normales; i++)
        normales.setIPoint(i, obj.normales.getIPoint(i));
    for (i = 0; i < kol_connects; i++)
        polygons.setIPolygon(i, obj.polygons.getIPolygon(i));
    selected = obj.selected;
    shadows = obj.shadows;
    radius = obj.radius;
    weight = obj.weight;
    return *this;
}

Model::~Model()
{
    if (!koordinates.IsEmpty() && !polygons.IsEmpty() && !normales.IsEmpty())
        Delete();
}

int Model::getConnectsNumber() const
{
    return polygons.getElementsNumber();
}
int Model::getNormalesNumber() const
{
    return normales.getElementsNumber();
}
int Model::getKoordsNumber() const
{
    return koordinates.getElementsNumber();
}

Point Model::getIKoord(int i) const
{
    return koordinates.getIPoint(i);
}

Polygon *Model::getIPolygon(int i) const
{
    return polygons.getIPolygon(i);
}
Point Model::getINormal(int i) const
{
    return normales.getIPoint(i);
}

std::vector<int> Model::face(int idx)
{
    std::vector<int> face;
    for (int i = 0; i < (int)this->polygons[idx].size(); i++)
        face.push_back(this->polygons[idx][i][0]);
    return face;
}

void Model::setIKoord(int i, Point point)
{
    koordinates.setIPoint(i, point);
}
void Model::setINorm(int i, Point point)
{
    normales.setIPoint(i, point);
}
void Model::setIPolygon(int i, Polygon *line)
{
    polygons.setIPolygon(i, line);
}

void Model::setKoords(const PointsArray& arr)
{
    koordinates = arr;
}

void Model::setPolygons(const PolygonsArray& arr)
{
    polygons = arr;
}

void Model::setNormales(const PointsArray& arr)
{
    normales = arr;
}

PointsArray* Model::verts()
{
    return &koordinates;
}

PointsArray* Model::norms()
{
    return &normales;
}

PolygonsArray* Model::faces()
{
    return &polygons;
}

void Model::setKoords(int kol_koords)
{
    if (kol_koords > 0)
        koordinates.set(kol_koords);
}

void Model::setNormales(int kol_normales)
{
    if (kol_normales > 0)
        normales.set(kol_normales);
}

void Model::setConnects(int kol_connects)
{
    if (kol_connects > 0)
        polygons.set(kol_connects);
}

void Model::Delete()
{
    koordinates.Delete();
    normales.Delete();
    polygons.Delete();
}

Memento* Model::CreateMemento() const
{
    Memento* mem = new Memento(&koordinates, &polygons, &normales);
    return mem;
}

void Model::setMemento(const Memento* obj)
{
    koordinates = (obj->memento_koords);
    polygons = (obj->memento_connects);
    normales = (obj->memento_normales);
}

Point Model::getCenterPoint()
{
    return this->verts()->getIPoint(this->verts()->getElementsNumber()-1);
}

void Model::Update(TransformData trData)
{
 //   UpdateRadius();
    Memento *mem = CreateMemento();
    //bool almostZero = false;

    koordinates.Transform(Convert::DataToMatrix(trData), 0);
    UpdateRadius();
    normales.Transform(Convert::DataToMatrix(trData), 1);


    if ((weight * trData.getZoom().get_kx()) > 0.02)
    {
        //almostZero = true;
        weight *= trData.getZoom().get_kx();
    }
    delete mem;
}

void Model::setColor(QColor color)
{
    this->color = color;
}

void Model::setSelect(bool s)
{
    selected = s;
}

void Model::setVelocity(Vec3f vel)
{
    velocity = (velocity + vel);//vel;
}

void Model::setTempVelocity(Vec3f vel)
{
    tempVelocity = (tempVelocity + vel);//vel;//
}

Vec3f Model::getVelocity()
{
    return velocity;
}

void Model::appendVelocity()
{
     TransformData data;
     data.setOffset(Offset((velocity.x+tempVelocity.x),
                           (velocity.y+tempVelocity.y),
                           (velocity.z+tempVelocity.z)));

    // qDebug("Cur velocity: %f %f %f", data.getOffset().get_dx(), data.getOffset().get_dy(), data.getOffset().get_dz());
     this->Update(data);

     tempVelocity.x = 0;
     tempVelocity.y = 0;
     tempVelocity.z = 0;
     velocity.x = 0;
     velocity.y = 0;
     velocity.z = 0;
}

bool Model::IsEmpty() const
{
    return ((!koordinates.getElementsNumber() && !polygons.getElementsNumber()) ? true: false);
}

/*!
 * \brief Model::getCenterPoint
 * Получение центральной точки модели с трансформацией от камеры
 * \return
 * Центральная точка
 */
Vec3i Model::getTransformCenterPoint(Component* cam, Draw* draw)
{
    //Memento* mem_model = CreateMemento();

    // Получаем матрицу преобразований из Iтой камеры
    TransformMatrix matrix = ((Camera*)cam)->getTransformMatrix();
    //koordinates.Transform(matrix);
    Point CP = PointsArray::TransformPoint(this->getCenterPoint(), matrix);
    //setMemento(mem_model);
    //delete mem_model;
    Vec3i resultI;

    resultI = draw->ProjectIntoScreen(Point::ToVec3f(CP));

    return resultI;
}

void Model::Drawing(Component *cam, Draw* draw)
{
    // Получаем матрицу преобразований из камеры
    TransformMatrix matrix = ((Camera*)cam)->getTransformMatrix();// (*it)->getTransformMatrix();

    Vec3f light_dir;// = (Point::ToVec3f(cp) - Point::ToVec3f(light_p)).normalize();

    int i = 0, j = 0;
    int polygon_power;

    QColor curColor = color;

    ListPointer<Component*>::iterator itOm;
    for (i = 0; i < polygons.getElementsNumber(); i++)
    {
        // РИСОВАНИЕ i-го ПОЛИГОНА
        polygon_power = polygons.getIPolygon(i)->getElementsNumber();
        std::vector<int> face = this->face(i);

        Vec3i screen_coords[polygon_power];
        Vec3f world_coords[polygon_power];
        double intensity[polygon_power];

        for (j = 0; j < polygon_power; j++)
        {
            Point vP = koordinates.getIPoint(face[j]);
            Vec3f vV = Point::ToVec3f(vP);

            world_coords[j] = vV;

            screen_coords[j] = draw->ProjectIntoScreen(Point::ToVec3f(vP.Transform(matrix)));
            intensity[j] = 0;
        }

        // Проверка на пересечение луча света с другими моделями (крч тень)
        if ((shadows) && (otherModels->getComponentsNumber() > 0))
        {
            // Для каждого источника света
            ListPointer<Component*>::iterator lightIterator = (*lightSources).CreateComponentsIterator();
            for(; !lightIterator.IsDone(); ++lightIterator)
            {
                Point loc = ((LightSource*)(*lightIterator))->getLocation();
                float intensityLS = ((LightSource*)(*lightIterator))->getIntensity();
                float curLSIntensity[polygon_power];
                for (j = 0; j < polygon_power; j++)
                {
                    light_dir = (world_coords[j] - Point::ToVec3f(loc)).normalize(intensityLS);
                    curLSIntensity[j] = -(norm(i, j)*light_dir);

                    if (curLSIntensity[j] > 1) curLSIntensity[j] = 1;
                    else if (curLSIntensity[j] < 0) curLSIntensity[j] = 0;

                }

                itOm = otherModels->CreateComponentsIterator();
                // Для каждой модельки
                int oM, k, p;
                for (oM = 0; oM < otherModels->getComponentsNumber(); ++itOm, oM++)
                {
                    // Для каждого полигона другой модельки
                    for (k = 0; k < ((Model*)(*itOm))->faces()->getElementsNumber(); k++)
                    {
                        int polygonOm_power = ((Model*)(*itOm))->getIPolygon(k)->getElementsNumber();
                        std::vector<int> faceOm = ((Model*)(*itOm))->face(k);
                        Vec3f Poly[polygonOm_power];
                        // Для каждой точки полигона модельки
                        for (p = 0; p < polygonOm_power; p++)
                            Poly[p] = Point::ToVec3f(((Model*)(*itOm))->verts()->getIPoint(faceOm[p]));

                        // Теперь есть Poly
                        // Надо проверять пересечения лучей

                        for (j = 0; j < polygon_power; j++)
                            if (curLSIntensity[j] != 0)
                                if (IntersectedPolygon(Poly, world_coords[j], Point::ToVec3f(loc),  polygonOm_power))
                                    curLSIntensity[j] = 0;

                    }
                }

                for (j = 0; j < polygon_power; j++)
                    intensity[j] += curLSIntensity[j];


                if (intensity[j] > 1)
                    intensity[j] = 1;
                else
                if (intensity[j] < 0)
                    intensity[j] = 0;
            }
        }
        else // Если нет теней
        {
            for (j = 0; j < polygon_power; j++)
            {
                intensity[j] = 0;
                ListPointer<Component*>::iterator itLS = (*lightSources).CreateComponentsIterator();
                for(; !itLS.IsDone(); ++itLS)
                {
                    LightSource *ls = ((LightSource*)(*itLS));
                    light_dir = (world_coords[j] - Point::ToVec3f(ls->getLocation())).normalize(ls->getIntensity());
                    float tmpIntensity = -(norm(i, j)*light_dir);

                    if (tmpIntensity > 1)
                        tmpIntensity = 1;
                    else
                        if (tmpIntensity < 0)
                            tmpIntensity = 0;

                    intensity[j] += tmpIntensity;
                }
                if (intensity[j] > 1)
                    intensity[j] = 1;
                else
                if (intensity[j] < 0)
                    intensity[j] = 0;

            }
        }

        for (j = 0; j < polygon_power; j++)
        {
            intensity[j] = 0.3 + 0.7 * intensity[j];


            if (intensity[j] > 1)
                intensity[j] = 1;
            else
            if (intensity[j] < 0)
                intensity[j] = 0;
        }

        curColor = color;
        if (selected)
            curColor = curColor.lighter(140);
        // Триангуляция!!!

        draw->DrawTriangle(screen_coords[0], screen_coords[1], screen_coords[2], curColor,
                intensity[0], intensity[1], intensity[2]);
        if (polygons.getIPolygon(i)->getElementsNumber() > 3)
            draw->DrawTriangle(screen_coords[0], screen_coords[2], screen_coords[3], curColor,
                intensity[0], intensity[2], intensity[3]);
    }
}

double Model::getDistance(Model* a, Model *b)
{
    Point res = a->getCenterPoint() - b->getCenterPoint();
    double result = 0;
    result = sqrt(res.getX() * res.getX() +
                  res.getY() * res.getY() +
                  res.getZ() * res.getZ());
    return result;
}

Vec3f Model::norm(int iface, int nvert)
{
    int idx = polygons.getIPolygon(iface)->getIVec(nvert)[2];
    return Point::ToVec3f(normales.getIPoint(idx)).normalize();
}

double Model::getWeight()
{
    return weight;
}


