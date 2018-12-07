#ifndef WHITELEDENTITY_H
#define WHITELEDENTITY_H

#include "../ecs/entity.h"
#include "roundpinentity.h"
#include <QDebug>

class WhiteLedEntity: public Entity
{
    Q_OBJECT
public:
    WhiteLedEntity(QGraphicsItem* parent = nullptr);
    void initConnections();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    const int& value(){return mValue;}

public slots:
    void setValue(const int& val){mValue = val; update();}

private:
    int mValue;
    QColor mPadColor;
    QColor mLightColor;
    QSharedPointer<RoundPinEntity> mInputPin;
    QSharedPointer<RoundPinEntity> mOutputPin;
};

#endif // WHITELEDENTITY_H
