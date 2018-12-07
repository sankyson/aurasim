#include "groundentity.h"
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QStyleOptionGraphicsItem>

GroundEntity::GroundEntity(QGraphicsItem *parent):
    Entity (parent),
    mGroundImage(QImage(":/icons/icon_ground.png")),
    mInputPin(new RoundPinEntity(this))
{
    mInputPin->setPos(0, -mGroundImage.size().height() / 2 + 12);
    mInputPin->setPinMode(2);
}

QRectF GroundEntity::boundingRect() const
{
    QSizeF imgSize = QSizeF(mGroundImage.size().width(), mGroundImage.size().height());
    return QRectF(-imgSize.width() / 2, -imgSize.height() / 2, imgSize.width(), imgSize.height());
}

void GroundEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)

    painter->drawImage(boundingRect(), mGroundImage);

    QPen pen;
    pen.setWidth(2);

    if(option->state & QStyle::State_MouseOver) {
        pen.setColor(QColor(128, 233, 255));
        painter->setPen(pen);
        painter->drawRect(boundingRect());
    }

    if(option->state & QStyle::State_Selected) {
        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawRect(boundingRect());
    }
}
