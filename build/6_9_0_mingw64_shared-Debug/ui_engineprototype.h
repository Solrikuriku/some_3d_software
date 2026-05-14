/********************************************************************************
** Form generated from reading UI file 'engineprototype.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINEPROTOTYPE_H
#define UI_ENGINEPROTOTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnginePrototype
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EnginePrototype)
    {
        if (EnginePrototype->objectName().isEmpty())
            EnginePrototype->setObjectName("EnginePrototype");
        EnginePrototype->resize(800, 600);
        centralwidget = new QWidget(EnginePrototype);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 781, 531));
        EnginePrototype->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EnginePrototype);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        EnginePrototype->setMenuBar(menubar);
        statusbar = new QStatusBar(EnginePrototype);
        statusbar->setObjectName("statusbar");
        EnginePrototype->setStatusBar(statusbar);

        retranslateUi(EnginePrototype);

        QMetaObject::connectSlotsByName(EnginePrototype);
    } // setupUi

    void retranslateUi(QMainWindow *EnginePrototype)
    {
        EnginePrototype->setWindowTitle(QCoreApplication::translate("EnginePrototype", "EnginePrototype", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnginePrototype: public Ui_EnginePrototype {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEPROTOTYPE_H
