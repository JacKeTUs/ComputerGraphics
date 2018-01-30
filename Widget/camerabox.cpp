#include "CameraBox.h"

void CameraBox::mousePressEvent(QMouseEvent *event)
{
    emit mPE(event);
}
void CameraBox::mouseReleaseEvent(QMouseEvent *event)
{
    emit mRE(event);
}
void CameraBox::mouseMoveEvent(QMouseEvent *event)
{
    emit mME(event);
}
void CameraBox::wheelEvent(QWheelEvent *event)
{
    emit wE(event);
}

DrawArray* CameraBox::getScenes()
{
    return &scenes;
}

void CameraBox::selectICamera(int i)
{
    int tmpIndex = i;
    int oldIndex = curIdx;

    if ((tmpIndex >= 0) && (tmpIndex < scenes.getElementsNumber()))
        curIdx = tmpIndex;
    else
        curIdx = 0;

    if (curIdx != oldIndex)
    {
        ((qobject_cast<QLabel*>)(this->children().at(oldIndex+1)))->setFrameStyle(QFrame::Box);
        ((qobject_cast<QLabel*>)(this->children().at(curIdx+1)))->setFrameStyle(QFrame::WinPanel);
    }
}

void CameraBox::addCamera()
{
    if (!this->layout())
        this->setLayout(&grid);

    QLabel *label = new QLabel;
    label->setFrameStyle(QFrame::Box);

    if (scenes.getElementsNumber() == 1)
    {
        QLayoutItem *label1 = grid.takeAt(0);
        grid.removeItem(label1);
        grid.addItem(label1,0,0,1,2);
    }
    if (scenes.getElementsNumber() == 2)
    {
        QLayoutItem *label1 = grid.takeAt(0);
        grid.removeItem(label1);
        grid.addItem(label1,0,0,1,1);
    }
    if (scenes.getElementsNumber() == 3)
    {
        QLayoutItem *label1 = grid.takeAt(0);
        grid.removeItem(label1);
        grid.addItem(label1,1,0,1,1);
    }
    grid.addWidget(label,(scenes.getElementsNumber() % 2), (scenes.getElementsNumber() >= 2), 1, 1+(scenes.getElementsNumber()==1));

    label->show();
    Draw *someScene = new Draw;
    scenes.AddScene(someScene);
    resizeScenes();

    redrawAll();
}

void CameraBox::resizeScenes()
{
    //(qobject_cast<QLabel*>(this->children().at(0+1)))->setFrameRect(QRect());
    for (int i = 0; i < scenes.getElementsNumber(); i++)
    {
        scenes.getIScene(i)->setImage(new QImage
                                      (
                                          ((scenes.getElementsNumber() < 3) ||
                                          ((scenes.getElementsNumber() == 3) && (i == 1))) ? this->width() : this->width() / 2,

                                          (scenes.getElementsNumber() > 1) ? this->height()/2 : this->height(),
                                          QImage::Format_RGB32
                                      ));
    }
}

void CameraBox::redrawAll()
{
    for (int i = 0; i < scenes.getElementsNumber(); i++)
        (qobject_cast<QLabel*>(this->children().at(i+1)))->setPixmap(QPixmap::fromImage(*(scenes.getIScene(i)->getImage())));

}

void CameraBox::deleteCamera(int idx)
{
    scenes.DeleteScene(idx);
    QLayoutItem *label1 = grid.takeAt(idx);
    grid.removeItem(label1);
    delete label1;
    this->resizeScenes();
    this->redrawAll();
}

