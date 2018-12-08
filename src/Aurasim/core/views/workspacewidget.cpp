#include "workspacewidget.h"
#include <QVBoxLayout>
#include <QGLWidget>

#include "../entities/unoboardentity.h"
#include "../systems/connectorsystem.h"
#include "../entities/whiteledentity.h"
#include "../entities/groundentity.h"

WorkspaceWidget::WorkspaceWidget(QWidget *parent) :
    QFrame(parent),
    mRenderView(QSharedPointer<RenderView>(new RenderView(this))),
    mScene(QSharedPointer<QGraphicsScene>(new QGraphicsScene(this))),
    mEntityManager(QSharedPointer<EntityManager>(new EntityManager)),
    mSystemManager(QSharedPointer<SystemManager>(new SystemManager)),
    mMinZoomFactor(5),
    mMaxZoomFactor(10000),
    mZoomFactor(250),
    mZoomBase(250)
{
    initUI();
    initConnections();
    initSystems();
}

void WorkspaceWidget::initUI()
{
    setFrameStyle(Sunken | StyledPanel);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mRenderView->setBackgroundBrush(QColor(23, 29, 36));
    mainLayout->addWidget(mRenderView.data());
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);

    mRenderView->setScene(mScene.data());

    // test
    UnoBoardEntity* unoBoard = new UnoBoardEntity();
    mEntityManager->addEntity(unoBoard);
    mScene->addItem(unoBoard);

    for(int i = 0; i < 12; i++) {
        WhiteLedEntity* whiteLed = new WhiteLedEntity;
        mEntityManager->addEntity(whiteLed);
        whiteLed->setPos(i * 120 - 400, -500);
        mScene->addItem(whiteLed);
    }

    GroundEntity* ground = new GroundEntity;
    mEntityManager->addEntity(ground);
    mScene->addItem(ground);

    // enable opengl
    mRenderView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
}

void WorkspaceWidget::initConnections()
{
    connect(mRenderView.data(), &RenderView::reqeustZoomIn, [=]{
        mZoomFactor += 1;
        if(mZoomFactor > mMaxZoomFactor)
            mZoomFactor = mMaxZoomFactor;
        setupMatrix();
    });
    connect(mRenderView.data(), &RenderView::requestZoomOut, [=]{
        mZoomFactor -= 1;
        if(mZoomFactor < mMinZoomFactor)
            mZoomFactor = mMinZoomFactor;
        setupMatrix();
    });
}

void WorkspaceWidget::initSystems()
{
    ConnectorSystem* connectorSys = new ConnectorSystem(nullptr, mScene.data());
    mSystemManager->addSystem(connectorSys);
}

void WorkspaceWidget::setupMatrix()
{
    QMatrix matrix;
    qreal scale = qPow(2, (mZoomFactor - mZoomBase) / qreal(10));
    matrix.scale(scale, scale);
    mRenderView->setMatrix(matrix);
}

RenderView::RenderView(QWidget *parent): QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing, true);
    setDragMode(QGraphicsView::RubberBandDrag);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
//    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setMouseTracking(true);
//    setRubberBandSelectionMode(Qt::IntersectsItemShape);
}

void RenderView::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier){
        if(event->angleDelta().y() > 0) {
            emit reqeustZoomIn();
        }
        if(event->angleDelta().y() < 0) {
            emit requestZoomOut();
        }
    }
    QGraphicsView::wheelEvent(event);
}

void RenderView::mouseMoveEvent(QMouseEvent *e)
{
    QGraphicsView::mouseMoveEvent(e);
}

void RenderView::mousePressEvent(QMouseEvent *e)
{
    if(e->modifiers() & Qt::ControlModifier){
        setDragMode(QGraphicsView::ScrollHandDrag);
    } else {
        setDragMode(QGraphicsView::RubberBandDrag);
    }
    QGraphicsView::mousePressEvent(e);
}

void RenderView::mouseReleaseEvent(QMouseEvent *e)
{
    setDragMode(QGraphicsView::RubberBandDrag);
    QGraphicsView::mouseReleaseEvent(e);
}
