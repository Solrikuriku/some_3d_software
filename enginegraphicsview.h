#ifndef ENGINEGRAPHICSVIEW_H
#define ENGINEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWheelEvent>
#include "sceneviewport.h"

class EngineGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit EngineGraphicsView(QWidget *parent = nullptr);
    ~EngineGraphicsView();

    void LoadCube(const float& size);
    void RotateCube(const float& aX, const float& aY, const float& aZ);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void keyPressEvent(QKeyEvent* event);

private:
    SceneViewport loadViewport = SceneViewport();

    //а если объектов несколько?
    struct ObjLines
    {
        QVector<QGraphicsLineItem*> lines;
    };

    void UpdateScene();

    QVector<ObjLines> linesOnScene;

    float zoomScene = 0.0f;
};

#endif // ENGINEGRAPHICSVIEW_H
