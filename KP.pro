#-------------------------------------------------
#
# Project created by QtCreator 2014-04-22T16:49:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Composite/PointsArray.cpp \
    Composite/point.cpp \
    Composite/Model.cpp \
    Composite/LinesArray.cpp \
    Composite/Camera.cpp \
    TransformData/Zoom.cpp \
    TransformData/TransformData.cpp \
    TransformData/Rotate.cpp \
    TransformData/Offset.cpp \
    TransformMatrix/TransformMatrix.cpp \
    Facade/AdapterFacade.cpp \
    Builder/ModelBuilder.cpp \
    Composite/Composite.cpp \
    TransformData/convert.cpp \
    Widget/colorpickwidget.cpp \
    Managers/cameramanager.cpp \
    Managers/scenemanager.cpp \
    Managers/linkmanager.cpp \
    Managers/modelmanager.cpp \
    Managers/basemanager.cpp \
    Facade/facade.cpp \
    Composite/link.cpp \
    Draw/abstractdraw.cpp \
    Draw/draw.cpp \
    Draw/zbuf.cpp \
    Memento/memento.cpp \
    Draw/drawarray.cpp \
    Widget/camerabox.cpp \
    Strategy/projectmatrix.cpp \
    Strategy/viewportmatrix.cpp \
    Composite/lightsource.cpp

HEADERS  += mainwindow.h \
    Command/ZoomCommand.h \
    Command/RotateCommand.h \
    Command/MoveCommand.h \
    Command/MacroCommand.h \
    Command/Command.h \
    Composite/PointsArray.h \
    Composite/Model.h \
    Composite/Composite.h \
    Composite/Component.h \
    Composite/Camera.h \
    Composite/AbstractArray.h \
    List/ListPointer.h \
    List/ElemPointer.h \
    Strategy/ZoomMatrix.h \
    Strategy/TransformInterface.h \
    Strategy/StrategyTransformMatrix.h \
    Strategy/RotateMatrix.h \
    Strategy/OffsetMatrix.h \
    TransformData/Zoom.h \
    TransformData/TransformData.h \
    TransformData/Rotate.h \
    TransformData/Offset.h \
    TransformMatrix/WrongSize.h \
    TransformMatrix/TransformMatrix.h \
    TransformMatrix/NullObject.h \
    TransformMatrix/NoReverseMatrix.h \
    TransformMatrix/Matrix.h \
    TransformMatrix/InOutMatrix.h \
    TransformMatrix/ErrorPow.h \
    TransformMatrix/ErrorIndex.h \
    TransformMatrix/ErrorAlloc.h \
    TransformMatrix/DividingByZero.h \
    TransformMatrix/AbstractMatrix.h \
    TransformMatrix/AbstractError.h \
    Facade/Facade.h \
    Facade/AdapterFacade.h \
    Facade/AbstractInterface.h \
    Stream/OpenStream.h \
    Stream/CloseStream.h \
    Builder/AbstractBuilder.h \
    Builder/ModelBuilder.h \
    Draw/AbstractDraw.h \
    Draw/Draw.h \
    Memento/Memento.h \
    Command/DrawCommand.h \
    Command/AddModelCommand.h \
    Command/AddCameraCommand.h \
    Command/MoveModelCommand.h \
    Command/AddLinkCommand.h \
    Command/DeleteCommand.h \
    Composite/Link.h \
    Composite/Line.h \
    Composite/Point.h \
    Composite/Polygon.h \
    Composite/Polygonsarray.h \
    Command/CalculateForcesCommand.h \
    Command/DeleteLinkCommand.h \
    Command/SetVelCommand.h \
    Command/SetColorCommand.h \
    Command/SelectModelCommand.h \
    Command/MoveLightSourceCommand.h \
    Command/SelectLightSourceCommand.h \
    Command/SelectLinkCommand.h \
    Command/SetBGColorCommand.h \
    Command/SetForceBehaviorCommand.h \
    Command/ZoomModelCommand.h \
    Command/SetLinkColorCommand.h \
    Command/DeleteICameraCommand.h \
    Command/DeleteLightSourceCommand.h \
    Command/AddLightSourceCommand.h \
    Composite/LightSource.h \
    Draw/DrawArray.h \
    Draw/ZBuf.h \
    Managers/BaseManager.h \
    Managers/CameraManager.h \
    Managers/LightSourceManager.h \
    Managers/LinkManager.h \
    Managers/ModelManager.h \
    Managers/SceneManager.h \
    TransformData/Convert.h \
    Widget/CameraBox.h \
    Widget/ColorPickWidget.h \
    Command/ChgIdxIntensityCommand.h

FORMS    += mainwindow.ui
