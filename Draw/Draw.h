#ifndef DRAW_H
#define DRAW_H
#include "ZBuf.h"
#include "stdint.h"
#include "float.h"

#define MAX(a, b)   ((a > b) ? (a) : (b))
#define MIN(a, b)   ((a < b) ? (a) : (b))
#define SIGN(a)     ((a > 0) ? (1) : ((a == 0) ? (0) : (-1)))
#define ROUND(a) floor(a + 0.5f)

#include "AbstractDraw.h"
#include "TransformMatrix/Matrix.h"

/*!
 * \brief rdtsc
 * Измерение тактов процессора
 * \return
 * Количество тактов процессора с момента сброса процессора
 */
extern __inline__ uint64_t rdtsc()
{
    uint64_t x;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
    return x;
}

class Draw : public AbstractDraw
{
protected:
    QImage* image;

public:
    Draw();

    Draw(const Draw& obj);

    ~Draw();

    Draw& operator = (const Draw& obj);

    void DrawPointWithZBuf(Vec3i *P, QColor color, double ity = 1);

    void DrawLine(Vec3i A, Vec3i B, QColor color, double ityA = 1, double ityB = 1);

    void DrawTriangle(Vec3i t0, Vec3i t1, Vec3i t2,
                      QColor color, double ity1 = 1, double ity2 = 1, double ity3 = 1);


    void FillCanvas(QColor fillColor);

    void setImage(QImage *img);
    QImage* getImage();

    // Проецирование изображения на экран
    Vec3i ProjectIntoScreen(Vec3f worldCoords);
};

#endif // DRAW_H
