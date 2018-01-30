/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "Widget\camerabox.h"
#include "Widget\colorpickwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *LoadModel;
    QAction *actionHelp;
    QAction *action;
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_16;
    QComboBox *comboBox;
    QPushButton *pushButton;
    colorPickWidget *color_w;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_4;
    QPushButton *pushButton_17;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QSpinBox *mdl_idx_1;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *mdl_idx_2;
    QLabel *label_4;
    QPushButton *adding_link;
    QPushButton *pushButton_15;
    QSpinBox *spinBox_5;
    colorPickWidget *link_color;
    QDoubleSpinBox *tension_box;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QLabel *label_11;
    QPushButton *pushButton_21;
    QPushButton *pushButton_20;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_22;
    QSpinBox *spinBox;
    QPushButton *pushButton_29;
    QPushButton *pushButton_23;
    QPushButton *pushButton_28;
    QPushButton *pushButton_30;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_24;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QSpinBox *mdl_move_idx;
    QPushButton *pushButton_25;
    QPushButton *pushButton_2;
    QPushButton *pushButton_27;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QRadioButton *force_out_rb;
    QRadioButton *force_in_rb;
    QRadioButton *no_force_rb;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QLabel *label_12;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_8;
    QPushButton *sim_start;
    colorPickWidget *bg_color;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QPushButton *pushButton_14;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QSpinBox *cam_move_idx;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_9;
    CameraBox *cameras;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1028, 643);
        LoadModel = new QAction(MainWindow);
        LoadModel->setObjectName(QStringLiteral("LoadModel"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(201, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_16 = new QPushButton(groupBox_2);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout_4->addWidget(pushButton_16, 0, 0, 1, 2);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_4->addWidget(comboBox, 1, 0, 1, 2);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_4->addWidget(pushButton, 2, 0, 1, 1);

        color_w = new colorPickWidget(groupBox_2);
        color_w->setObjectName(QStringLiteral("color_w"));

        gridLayout_4->addWidget(color_w, 2, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(181, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label = new QLabel(groupBox_6);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(-99);
        doubleSpinBox->setSingleStep(1);

        gridLayout_5->addWidget(doubleSpinBox, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 1, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMinimum(-99);
        doubleSpinBox_2->setSingleStep(1);

        gridLayout_5->addWidget(doubleSpinBox_2, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMinimum(-99);
        doubleSpinBox_3->setSingleStep(1);

        gridLayout_5->addWidget(doubleSpinBox_3, 2, 1, 1, 1);

        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 3, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox_6);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMinimum(1);
        doubleSpinBox_4->setMaximum(5);
        doubleSpinBox_4->setSingleStep(1);

        gridLayout_5->addWidget(doubleSpinBox_4, 3, 1, 1, 1);

        pushButton_17 = new QPushButton(groupBox_6);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        gridLayout_5->addWidget(pushButton_17, 4, 0, 1, 2);


        gridLayout_9->addWidget(groupBox_6, 0, 2, 2, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(201, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        mdl_idx_1 = new QSpinBox(groupBox_3);
        mdl_idx_1->setObjectName(QStringLiteral("mdl_idx_1"));

        gridLayout_3->addWidget(mdl_idx_1, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        mdl_idx_2 = new QSpinBox(groupBox_3);
        mdl_idx_2->setObjectName(QStringLiteral("mdl_idx_2"));

        gridLayout_3->addWidget(mdl_idx_2, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        adding_link = new QPushButton(groupBox_3);
        adding_link->setObjectName(QStringLiteral("adding_link"));

        gridLayout_3->addWidget(adding_link, 3, 0, 1, 1);

        pushButton_15 = new QPushButton(groupBox_3);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout_3->addWidget(pushButton_15, 4, 0, 1, 1);

        spinBox_5 = new QSpinBox(groupBox_3);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));

        gridLayout_3->addWidget(spinBox_5, 4, 2, 1, 1);

        link_color = new colorPickWidget(groupBox_3);
        link_color->setObjectName(QStringLiteral("link_color"));

        gridLayout_3->addWidget(link_color, 3, 2, 1, 1);

        tension_box = new QDoubleSpinBox(groupBox_3);
        tension_box->setObjectName(QStringLiteral("tension_box"));
        tension_box->setMinimum(1);

        gridLayout_3->addWidget(tension_box, 2, 2, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 1, 0, 2, 1);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMaximumSize(QSize(181, 16777215));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_11 = new QLabel(groupBox_7);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_7->addWidget(label_11, 0, 0, 1, 3);

        pushButton_21 = new QPushButton(groupBox_7);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setMaximumSize(QSize(31, 23));

        gridLayout_7->addWidget(pushButton_21, 1, 0, 1, 1);

        pushButton_20 = new QPushButton(groupBox_7);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setMaximumSize(QSize(31, 23));

        gridLayout_7->addWidget(pushButton_20, 1, 2, 1, 1);

        pushButton_18 = new QPushButton(groupBox_7);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setMaximumSize(QSize(31, 23));

        gridLayout_7->addWidget(pushButton_18, 2, 0, 1, 1);

        pushButton_19 = new QPushButton(groupBox_7);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setMaximumSize(QSize(31, 23));

        gridLayout_7->addWidget(pushButton_19, 2, 1, 1, 1);

        pushButton_22 = new QPushButton(groupBox_7);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setMaximumSize(QSize(31, 23));

        gridLayout_7->addWidget(pushButton_22, 2, 2, 1, 1);

        spinBox = new QSpinBox(groupBox_7);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout_7->addWidget(spinBox, 0, 3, 1, 1);

        pushButton_29 = new QPushButton(groupBox_7);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));

        gridLayout_7->addWidget(pushButton_29, 2, 3, 1, 1);

        pushButton_23 = new QPushButton(groupBox_7);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setMaximumSize(QSize(31, 23));

        gridLayout_7->addWidget(pushButton_23, 1, 1, 1, 1);

        pushButton_28 = new QPushButton(groupBox_7);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));

        gridLayout_7->addWidget(pushButton_28, 1, 3, 1, 1);

        pushButton_30 = new QPushButton(groupBox_7);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));

        gridLayout_7->addWidget(pushButton_30, 3, 0, 1, 4);


        gridLayout_9->addWidget(groupBox_7, 2, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(201, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 3);

        pushButton_24 = new QPushButton(groupBox);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        gridLayout->addWidget(pushButton_24, 1, 3, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        mdl_move_idx = new QSpinBox(groupBox);
        mdl_move_idx->setObjectName(QStringLiteral("mdl_move_idx"));

        gridLayout->addWidget(mdl_move_idx, 0, 3, 1, 1);

        pushButton_25 = new QPushButton(groupBox);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));

        gridLayout->addWidget(pushButton_25, 2, 3, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_27 = new QPushButton(groupBox);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));

        gridLayout->addWidget(pushButton_27, 3, 0, 1, 4);

        pushButton_2->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_5->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        label_2->raise();
        pushButton_24->raise();
        mdl_move_idx->raise();
        pushButton_25->raise();
        pushButton_27->raise();

        gridLayout_9->addWidget(groupBox, 3, 0, 2, 1);

        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setMaximumSize(QSize(181, 16777215));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        force_out_rb = new QRadioButton(groupBox_8);
        force_out_rb->setObjectName(QStringLiteral("force_out_rb"));
        force_out_rb->setChecked(true);

        gridLayout_8->addWidget(force_out_rb, 0, 0, 1, 1);

        force_in_rb = new QRadioButton(groupBox_8);
        force_in_rb->setObjectName(QStringLiteral("force_in_rb"));

        gridLayout_8->addWidget(force_in_rb, 1, 0, 1, 1);

        no_force_rb = new QRadioButton(groupBox_8);
        no_force_rb->setObjectName(QStringLiteral("no_force_rb"));

        gridLayout_8->addWidget(no_force_rb, 2, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_8, 3, 2, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(181, 16777215));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_6->addWidget(label_12, 0, 0, 1, 1);

        checkBox = new QCheckBox(groupBox_5);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_6->addWidget(checkBox, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_5);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_6->addWidget(checkBox_2, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(groupBox_5);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_6->addWidget(pushButton_8, 3, 0, 1, 2);

        sim_start = new QPushButton(groupBox_5);
        sim_start->setObjectName(QStringLiteral("sim_start"));

        gridLayout_6->addWidget(sim_start, 2, 0, 1, 2);

        bg_color = new colorPickWidget(groupBox_5);
        bg_color->setObjectName(QStringLiteral("bg_color"));

        gridLayout_6->addWidget(bg_color, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 4, 0, 1, 2);

        horizontalSlider = new QSlider(groupBox_5);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSliderPosition(15);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(horizontalSlider, 5, 0, 1, 2);


        gridLayout_9->addWidget(groupBox_5, 4, 2, 2, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(201, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 2);

        pushButton_14 = new QPushButton(groupBox_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout_2->addWidget(pushButton_14, 1, 0, 1, 1);

        pushButton_10 = new QPushButton(groupBox_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_2->addWidget(pushButton_10, 1, 2, 1, 1);

        pushButton_12 = new QPushButton(groupBox_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout_2->addWidget(pushButton_12, 2, 2, 1, 1);

        cam_move_idx = new QSpinBox(groupBox_4);
        cam_move_idx->setObjectName(QStringLiteral("cam_move_idx"));

        gridLayout_2->addWidget(cam_move_idx, 0, 2, 1, 1);

        pushButton_11 = new QPushButton(groupBox_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout_2->addWidget(pushButton_11, 2, 0, 1, 1);

        pushButton_13 = new QPushButton(groupBox_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout_2->addWidget(pushButton_13, 1, 1, 1, 1);

        pushButton_9 = new QPushButton(groupBox_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_2->addWidget(pushButton_9, 2, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_4, 5, 0, 1, 1);

        cameras = new CameraBox(centralWidget);
        cameras->setObjectName(QStringLiteral("cameras"));
        cameras->setEnabled(true);
        cameras->setMinimumSize(QSize(616, 578));
        cameras->setMaximumSize(QSize(616, 604));
        cameras->setMouseTracking(true);

        gridLayout_9->addWidget(cameras, 0, 1, 6, 1);

        MainWindow->setCentralWidget(centralWidget);
        cameras->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox->raise();
        groupBox_4->raise();
        groupBox_6->raise();
        groupBox_7->raise();
        groupBox_8->raise();
        groupBox_5->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1028, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(LoadModel);
        menu->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\320\276\321\207\320\273\320\265\320\275\321\221\320\275\320\275\321\213\321\205 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", 0));
        LoadModel->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        action->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\265\321\202\320\272\321\203 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\232\321\203\320\261", 0)
         << QApplication::translate("MainWindow", "\320\237\320\270\321\200\320\260\320\274\320\270\320\264\320\272\320\260", 0)
         << QApplication::translate("MainWindow", "\320\230\320\272\320\276\321\201\320\260\321\215\320\264\321\200", 0)
         << QApplication::translate("MainWindow", "\320\241\321\204\320\265\321\200\320\260", 0)
        );
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\276\320\262 \321\201\320\262\320\265\321\202\320\260", 0));
        label->setText(QApplication::translate("MainWindow", "X", 0));
        label_8->setText(QApplication::translate("MainWindow", "Y", 0));
        label_9->setText(QApplication::translate("MainWindow", "Z", 0));
        label_10->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214\n"
"\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\262\321\217\320\267\321\217\320\274\320\270", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201 1-\320\263\320\276 \320\276\320\261\321\212\320\265\320\272\321\202\320\260:", 0));
        label_6->setText(QApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201 2-\320\263\320\276 \320\276\320\261\321\212\320\265\320\272\321\202\320\260:", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\n"
"\321\203\320\277\321\200\321\203\320\263\320\276\321\201\321\202\320\270", 0));
        adding_link->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\262\321\217\320\267\321\214", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\320\262\321\217\320\267\321\214", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260\320\274\320\270 \321\201\320\262\320\265\321\202\320\260", 0));
        label_11->setText(QApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260", 0));
        pushButton_21->setText(QApplication::translate("MainWindow", "Z-", 0));
        pushButton_20->setText(QApplication::translate("MainWindow", "Z+", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "X-", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "Y-", 0));
        pushButton_22->setText(QApplication::translate("MainWindow", "X+", 0));
        pushButton_29->setText(QApplication::translate("MainWindow", "I-", 0));
        pushButton_23->setText(QApplication::translate("MainWindow", "Y+", 0));
        pushButton_28->setText(QApplication::translate("MainWindow", "I+", 0));
        pushButton_30->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Z-", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "X+", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201 \320\276\320\261\321\212\320\265\320\272\321\202\320\260:", 0));
        pushButton_24->setText(QApplication::translate("MainWindow", "M+", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "X-", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Z+", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Y-", 0));
        pushButton_25->setText(QApplication::translate("MainWindow", "M-", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Y+", 0));
        pushButton_27->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\320\264\320\265\320\275\320\270\320\265 \320\274\320\276\320\264\320\265\320\273\320\265\320\271", 0));
        force_out_rb->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\202\320\260\320\273\320\272\320\270\320\262\320\260\320\275\320\270\320\265", 0));
        force_in_rb->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\321\202\321\217\320\266\320\265\320\275\320\270\320\265", 0));
        no_force_rb->setText(QApplication::translate("MainWindow", "\320\235\320\265\321\202 \320\262\320\267\320\260\320\270\320\274\320\276\320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0));
        label_12->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", 0));
        checkBox->setText(QApplication::translate("MainWindow", "\320\241\320\262\321\217\320\267\320\270", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\275\320\270", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\321\216", 0));
        sim_start->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\201\320\270\320\274\321\203\320\273\321\217\321\206\320\270\321\216", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\247\321\203\320\262\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\274\321\213\321\210\320\270", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", 0));
        label_7->setText(QApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201 \320\272\320\260\320\274\320\265\321\200\321\213:", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "Z-", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "Z+", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "X+", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "X-", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "Y+", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Y-", 0));
        cameras->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
