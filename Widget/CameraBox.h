#ifndef CAMERABOX_H
#define CAMERABOX_H

#include <QGroupBox>
#include <QLayout>
#include <QLabel>
#include "QResizeEvent"

#include "./Draw/DrawArray.h"

class CameraBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit CameraBox(QWidget *parent = 0): QGroupBox(parent)
    {
        curIdx = 0;
        maxCam = 4;
    }

    void selectICamera(int i);
    DrawArray* getScenes();
    void addCamera();
    void deleteCamera(int idx);
    void redrawAll();
    int maxCameras()
    {
        return maxCam;
    }


protected:
    void mousePressEvent( QMouseEvent * event );
    void mouseMoveEvent( QMouseEvent * event );
    void mouseReleaseEvent( QMouseEvent * event );
    void wheelEvent(QWheelEvent *event);

    void resizeScenes();

private:
    int maxCam;
    int curIdx;
    QGridLayout grid;
    DrawArray scenes;

signals:
    mPE(QMouseEvent *event);
    mME(QMouseEvent *event);
    mRE(QMouseEvent *event);
    wE(QWheelEvent *event);

};

#endif // CAMERABOX_H
