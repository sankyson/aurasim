#ifndef GROUNDENTITY_H
#define GROUNDENTITY_H

#include "../ecs/entity.h"

#include "../entities/roundpinentity.h"

class GroundEntity: public Entity
{
public:
    GroundEntity(QGraphicsItem* parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QImage mGroundImage;
    RoundPinEntity* mInputPin;
};

#endif // GROUNDENTITY_H
