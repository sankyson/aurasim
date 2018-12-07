#ifndef ROUNDPINENTITY_H
#define ROUNDPINENTITY_H

#include "pinentity.h"

class RoundPinEntity : public PinEntity
{
    Q_OBJECT
public:
    RoundPinEntity(QGraphicsItem* parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // ROUNDPINENTITY_H
