/********************************************************************************
** Form generated from reading UI file 'engineui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINEUI_H
#define UI_ENGINEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "enginegraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_EngineUI
{
public:
    EngineGraphicsView *engineGraphicsView;
    QPushButton *cubeButton;

    void setupUi(QWidget *EngineUI)
    {
        if (EngineUI->objectName().isEmpty())
            EngineUI->setObjectName("EngineUI");
        EngineUI->resize(1216, 710);
        engineGraphicsView = new EngineGraphicsView(EngineUI);
        engineGraphicsView->setObjectName("engineGraphicsView");
        engineGraphicsView->setGeometry(QRect(30, 20, 1151, 611));
        cubeButton = new QPushButton(EngineUI);
        cubeButton->setObjectName("cubeButton");
        cubeButton->setGeometry(QRect(40, 660, 90, 29));

        retranslateUi(EngineUI);

        QMetaObject::connectSlotsByName(EngineUI);
    } // setupUi

    void retranslateUi(QWidget *EngineUI)
    {
        EngineUI->setWindowTitle(QCoreApplication::translate("EngineUI", "Form", nullptr));
        cubeButton->setText(QCoreApplication::translate("EngineUI", "\320\225\320\261\320\275\321\203\321\202\321\214 \320\272\321\203\320\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EngineUI: public Ui_EngineUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEUI_H
