#ifndef SPOTENTITY_H
#define SPOTENTITY_H

#include "../ecs/entity.h"
#include "../global/defines.h"

class SpotEntity: public Entity
{
public:
    SpotEntity(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    qreal raduis();
    void setRadius(const qreal& radius);

private:
    qreal mRadius;

};

#endif // SPOTENTITY_H
