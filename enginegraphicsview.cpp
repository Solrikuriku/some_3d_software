#include "enginegraphicsview.h"

EngineGraphicsView::EngineGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setMouseTracking(true);
}

EngineGraphicsView::~EngineGraphicsView()
{

}

void EngineGraphicsView::LoadCube(const float &size)
{
    loadViewport.AddCube(size);

    //отдельный метод
    auto loadEdges = loadViewport.GetEdges();

    auto lines = ObjLines();

    for (const auto& e : loadEdges)
    {
        auto edgePtr = new QGraphicsLineItem(e);
        scene()->addItem(edgePtr);
        lines.lines.append(edgePtr);
    }

    linesOnScene.append(lines);
}

void EngineGraphicsView::RotateCube(const float &aX, const float &aY, const float &aZ)
{
    loadViewport.RotateCube(aX, aY, aZ);
    UpdateScene();
}

void EngineGraphicsView::mousePressEvent(QMouseEvent *event)
{
    //LoadCube();

    QGraphicsView::mousePressEvent(event);
}

void EngineGraphicsView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_C)
    {
        loadViewport.ResetToOriginal();
        UpdateScene();
    }

    QGraphicsView::keyPressEvent(event);
}

void EngineGraphicsView::wheelEvent(QWheelEvent *event)
{
    loadViewport.OnZoomChanged(event->angleDelta().y() * 0.1f);
    UpdateScene();
}

void EngineGraphicsView::UpdateScene()
{
    auto loadEdges = loadViewport.GetEdges();

    for (const auto& l : linesOnScene)
    {
        for (qsizetype i = 0; i < l.lines.size(); i++)
        {
            l.lines[i]->setLine(loadEdges[i]);
        }
    }
}
