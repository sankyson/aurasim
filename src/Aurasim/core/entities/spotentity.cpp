#include "spotentity.h"

SpotEntity::SpotEntity(QGraphicsItem *parent):Entity (parent),
    mRadius(10)
{

}

QRectF SpotEntity::boundingRect() const
{
    return QRectF(-mRadius, -mRadius, mRadius * 2, mRadius * 2);
}

void SpotEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidth(0);
    pen.setColor(QColor(60,60,60));
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addEllipse(this->boundingRect());
    painter->fillPath(path, Qt::red);
    painter->drawEllipse(boundingRect());
}

qreal SpotEntity::raduis()
{
    return mRadius;
}

void SpotEntity::setRadius(const qreal &radius)
{
    mRadius = radius;
}
