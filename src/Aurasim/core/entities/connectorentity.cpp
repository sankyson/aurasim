#include "connectorentity.h"
#include <QPen>
#include <QPainter>
#include <QDebug>


ConnectorEntity::ConnectorEntity(QGraphicsItem *parent, PinEntity* start, PinEntity* end): Entity (parent)
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
    QPointF gap = mOutputPin->pos() - mInputPin->pos();
    qreal w, h;
    w = qAbs(gap.x()) + 6;
    h = qAbs(gap.y()) + 6;

    return QRectF( -w / 2 - 3, -h / 2 - 3, w, h);
}


void ConnectorEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)

    QPen pen;
    pen.setWidth(2);
    QColor drawColor(40, 255, 20);
    pen.setColor(drawColor);
    painter->setPen(pen);
    painter->drawLine(mInputPin->scenePos() - this->pos(), mOutputPin->scenePos() - this->pos());
}

void ConnectorEntity::timerEvent(QTimerEvent *event)
{
    mInputPin->setPinVal(mOutputPin->pinVal());
    QObject::timerEvent(event);
}
