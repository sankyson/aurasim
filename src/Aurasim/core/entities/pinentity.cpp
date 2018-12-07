#include "pinentity.h"
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>
#include <QDebug>

PinEntity::PinEntity(QGraphicsItem *parent) : Entity (parent),
    mPinMode(0),
    mPinVal(0),
    mPinInColor(QColor(100, 234, 187)),
    mPinOutColor(QColor(100, 187, 234)),
    mPinGroundColor(QColor(100, 100, 80))
{
    setFlags(ItemIsSelectable);
}

QRectF PinEntity::boundingRect() const
{
    return QRectF(-8, -8, 16, 16);
}

void PinEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    painter->fillRect(rect, pinColor);
    painter->drawRect(rect);

    if(option->state & QStyle::State_MouseOver || option->state & QStyle::State_Selected) {
        painter->fillRect(rect, pinColor.lighter(120));
        pen.setColor(QColor(255, 255, 255));
        painter->setPen(pen);
        painter->drawRect(rect);
    }

    if(option->state & QStyle::State_Selected) {
        painter->fillRect(rect, pinColor.lighter(120));
        pen.setColor(QColor(100, 255, 255));
        pen.setWidth(1);
        painter->setPen(pen);
        painter->drawRect(boundingRect());
    }

    emit tick();
}

void PinEntity::setPinMode(const int &mode)
{
    mPinMode = mode;
    update();
    emit pinModeChanged(mode);
}

void PinEntity::setPinVal(const int &val)
{
    mPinVal = val;
    update();
    emit pinValChanged(val);
}

void PinEntity::resetState()
{
    update();
}
