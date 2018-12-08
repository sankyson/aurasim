#include "connectorentity.h"
#include <QPen>
#include <QPainter>
#include <QDebug>
#include <QPolygonF>
#include <QtMath>
#include <QStyleOptionGraphicsItem>


ConnectorEntity::ConnectorEntity(QGraphicsItem *parent, PinEntity* start, PinEntity* end):
    Entity (parent),
    mLineWidth(10)
{
    if(start->pinMode() == 0){
        mInputPin = start;
        mOutputPin = end;
    }

    if(end->pinMode() == 0) {
        mInputPin = end;
        mOutputPin = start;
    }

    if(start->pinMode() == 2) {
        mInputPin = start;
        mOutputPin = end;
    }

    if(end->pinMode() == 2) {
        mInputPin = end;
        mOutputPin = start;
    }

    setFlags(ItemIsSelectable);
    startTimer(25, Qt::CoarseTimer);
//    setZValue(1);
}

QRectF ConnectorEntity::boundingRect() const
{
    return shape().boundingRect();
}

void ConnectorEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)
    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mLineWidth / 2);
    QColor drawColor(180, 180, 180);
    if(option->state & QStyle::State_MouseOver || option->state & QStyle::State_Selected)
        drawColor.setRgb(255, 255, 255);

    pen.setColor(drawColor);
    painter->setPen(pen);

    painter->drawLine(mOutputPin->scenePos() - this->scenePos(), mInputPin->scenePos() - this->scenePos());

//    painter->fillPath(shape(), drawColor);
}

QPainterPath ConnectorEntity::shape() const
{
    QPainterPath path;

    qreal k = (mOutputPin->scenePos().y() - mInputPin->scenePos().y()) / (mOutputPin->scenePos().x() - mInputPin->scenePos().x());
    qreal dk = - 1.0 / k;
    qreal r = mLineWidth  / 2;
    qreal dx = qSqrt(qAbs(((r * r) / (1 + dk * dk))));

    QPointF p1 = mOutputPin->scenePos() - this->scenePos() + QPointF(dx, dk * dx);
    QPointF p2 = mOutputPin->scenePos() - this->scenePos() + QPointF(-dx, dk * -dx);
    QPointF p3 = mInputPin->scenePos() - this->scenePos() + QPointF(dx, dk * dx);
    QPointF p4 = mInputPin->scenePos() - this->scenePos() + QPointF(-dx, dk * -dx);

    QPolygonF polygon;
    polygon << p1 << p2 << p4 << p3;
    path.addPolygon(polygon);
    return path;
}

void ConnectorEntity::timerEvent(QTimerEvent *event)
{
    QPointF pos = mInputPin->scenePos() + (mOutputPin->scenePos() - mInputPin->scenePos()) / 2;
    setPos(pos);
//    prepareGeometryChange();
    mInputPin->setPinVal(mOutputPin->pinVal());
    QObject::timerEvent(event);
}
