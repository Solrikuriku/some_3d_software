#include "engineui.h"
#include "ui_engineui.h"
#include "EngineGraphicsView.h"

#include <QPushButton>
#include <QShortcut>

EngineUI::EngineUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EngineUI)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    connect(ui->cubeButton, &QPushButton::clicked, this, &EngineUI::MakeCube);

    engineGraphicsView = qobject_cast<EngineGraphicsView*>(ui->engineGraphicsView);

    QShortcut* shiftUp = new QShortcut(QKeySequence(Qt::Key_Up), this);
    connect(shiftUp, &QShortcut::activated, [this](){ RotateCube(DirectionShift::Up); });

    QShortcut* shiftDown = new QShortcut(QKeySequence(Qt::Key_Down), this);
    connect(shiftDown, &QShortcut::activated, [this](){ RotateCube(DirectionShift::Down); });

    QShortcut* shiftLeft = new QShortcut(QKeySequence(Qt::Key_Left), this);
    connect(shiftLeft, &QShortcut::activated, [this](){ RotateCube(DirectionShift::Left); });

    QShortcut* shiftRight = new QShortcut(QKeySequence(Qt::Key_Right), this);
    connect(shiftRight, &QShortcut::activated, [this](){ RotateCube(DirectionShift::Right); });

    if (engineGraphicsView)
    {
        engineGraphicsView->setScene(scene);
        scene->setSceneRect(0,0, engineGraphicsView->viewport()->width(), engineGraphicsView->viewport()->height());
        engineGraphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
        engineGraphicsView->setRenderHint(QPainter::Antialiasing);
        engineGraphicsView->setCacheMode(QGraphicsView::CacheBackground);
        engineGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    }
}

EngineUI::~EngineUI()
{
    delete ui;
}

void EngineUI::MakeCube()
{
    ui->engineGraphicsView->LoadCube(10.0f);
}

void EngineUI::RotateCube(DirectionShift dir)
{
    switch (dir)
    {
    case DirectionShift::Up:
        angleX -= 5.0f;
        break;
    case DirectionShift::Down:
        angleX += 5.0f;
        break;
    case DirectionShift::Left:
        angleY -= 5.0f;
        break;
    case DirectionShift::Right:
        angleY += 5.0f;
        break;
    }

    ui->engineGraphicsView->RotateCube(angleX, angleY, 0.0f);
}
