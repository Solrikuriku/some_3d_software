#ifndef ENGINEUI_H
#define ENGINEUI_H

#include <QGraphicsScene>
#include <QWidget>

namespace Ui {
class EngineUI;
}

class EngineGraphicsView;

class EngineUI : public QWidget
{
    Q_OBJECT

private:
    enum DirectionShift
    {
        Up, Left, Right, Down
    };

public:
    explicit EngineUI(QWidget *parent = nullptr);
    ~EngineUI();

public slots:
    void MakeCube();

private:
    Ui::EngineUI *ui;
    QGraphicsScene *scene;

    float angleX = 0.0f; float angleY = 0.0f;

    void RotateCube(DirectionShift dir);

    EngineGraphicsView *engineGraphicsView = nullptr;
};

#endif // ENGINEUI_H
