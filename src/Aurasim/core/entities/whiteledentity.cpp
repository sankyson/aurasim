#include "whiteledentity.h"
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>

WhiteLedEntity::WhiteLedEntity(QGraphicsItem *parent): Entity (parent),
    mValue(0),
    mPadColor(QColor(88, 56, 89)),
    mInputPin(new RoundPinEntity(this)),
    mOutputPin(new RoundPinEntity(this))
{
    mInputPin->setPos(QPointF(-50 + 8.0, 0.0));
    mOutputPin->setPos(QPointF(50 - 8, 0));
    mOutputPin->setPinMode(1);
    initConnections();
}

void WhiteLedEntity::initConnections()
{
    connect(mInputPin.data(), &PinEntity::pinValChanged, this, &WhiteLedEntity::setValue);
}

void WhiteLedEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)
    qreal lVal = (mValue / 255.0) * 200;
    int light = int(55 + lVal);
    mLightColor = QColor(light, light, light);

    // draw pad
    QRectF rect = boundingRect();
    rect.setSize(rect.size() - QSizeF(4.0, 4.0));
    rect.moveCenter(boundingRect().center());
    painter->fillRect(rect, mPadColor);
    if(option->state & QStyle::State_MouseOver){
        painter->fillRect(rect, mPadColor.lighter(120));
    }

    if(option->state & QStyle::State_Selected) {
        QPen pen;
        pen.setWidth(2);
        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawRect(boundingRect());
    }

    // draw linght
    QPainterPath path;
    path.addEllipse(- 15, - 15, 30, 30);
    painter->fillPath(path, mLightColor);
}

QRectF WhiteLedEntity::boundingRect() const
{
    int w = 100;
    int h = 40;
    return QRectF(-w / 2, -h / 2, w, h);
}
