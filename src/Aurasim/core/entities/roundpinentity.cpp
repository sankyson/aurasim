#include "roundpinentity.h"
#include <QPen>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPainterPath>

RoundPinEntity::RoundPinEntity(QGraphicsItem *parent): PinEntity (parent)
{

}

void RoundPinEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)

    QColor pinColor = pinMode() == 0 ? pinInColor() : (pinMode() == 1 ? pinOutColor() : pinGroundColor());
    QPen pen;
    pen.setWidth(2);
    QColor drawColor(40, 40, 40);
    pen.setColor(drawColor);
    painter->setPen(pen);
    QSizeF size = boundingRect().size() * 0.8;
    QRectF rect = boundingRect();
    rect.setSize(size);
    rect.moveCenter(boundingRect().center());
    QPainterPath rectPath;
    rectPath.addEllipse(rect);
    painter->fillPath(rectPath, pinColor);
    painter->drawPath(rectPath);

    if(option->state & QStyle::State_MouseOver || option->state & QStyle::State_Selected) {
        painter->fillPath(rectPath, pinColor.lighter(120));
        pen.setColor(QColor(255, 255, 255));
        painter->setPen(pen);
        painter->drawPath(rectPath);
    }

    if(option->state & QStyle::State_Selected) {
        painter->fillPath(rectPath, pinColor.lighter(120));
        pen.setColor(QColor(100, 255, 255));
        pen.setWidth(1);
        painter->setPen(pen);
        painter->drawEllipse(boundingRect());
    }

    emit tick();
}
