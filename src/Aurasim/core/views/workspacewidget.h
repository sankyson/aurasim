#ifndef WORKSPACEWIDGET_H
#define WORKSPACEWIDGET_H

#include <QFrame>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QMouseEvent>

#include "../ecs/entitymanager.h"
#include "../ecs/systemmanager.h"
#include "../global/defines.h"

class RenderView;
class WorkspaceWidget : public QFrame
{
    Q_OBJECT
public:
    explicit WorkspaceWidget(QWidget *parent = nullptr);
    void initUI();
    void initConnections();
    void initSystems();

signals:

public slots:
    void setupMatrix();

private:
    QSharedPointer<RenderView> mRenderView;
    QSharedPointer<QGraphicsScene> mScene;
    QSharedPointer<EntityManager> mEntityManager;
    QSharedPointer<SystemManager> mSystemManager;
    int mMinZoomFactor;
    int mMaxZoomFactor;
    int mZoomFactor;
    int mZoomBase;
};

class RenderView: public QGraphicsView{
    Q_OBJECT
public:
    explicit RenderView(QWidget* parent = nullptr);
signals:
    void reqeustZoomIn();
    void requestZoomOut();

protected:
    void wheelEvent(QWheelEvent* event) override;
    void mouseMoveEvent(QMouseEvent* e) override;
    void mousePressEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
private:
};

#endif // WORKSPACEWIDGET_H
