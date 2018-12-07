#ifndef CONNECTORENTITY_H
#define CONNECTORENTITY_H

#include "../ecs/entity.h"
#include "pinentity.h"

class ConnectorEntity : public Entity
{
    Q_OBJECT
public:
    ConnectorEntity(QGraphicsItem* parent = nullptr, PinEntity* start = nullptr, PinEntity* end = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

public slots:

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    PinEntity* mInputPin;
    PinEntity* mOutputPin;
};

#endif // CONNECTORENTITY_H
