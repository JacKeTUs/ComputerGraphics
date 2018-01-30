#ifndef ZBUF_H
#define ZBUF_H
#include "stdlib.h"
#include "qDebug"

class ZBuf
{
private:
    int width;
    int height;
    int **data;

public:
    ZBuf(int width, int height);

    void initZBuf(int value);

    ~ZBuf();

    int getWidth();

    int getHeight();

    int getZ(int x, int y);

    void setZ(int z, int x, int y);
};


#endif // ZBUF_H
