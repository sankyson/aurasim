#ifndef UNOBOARDENTITY_H
#define UNOBOARDENTITY_H

#include "../ecs/entity.h"
#include "../global/defines.h"
#include <QGraphicsSceneMouseEvent>
#include "pinentity.h"
#include "../chips/arduino.h"

class UnoBoardEntity: public Entity
{
    Q_OBJECT

public:
    UnoBoardEntity(QGraphicsItem* parent= nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    void timerEvent(QTimerEvent *event) override;

signals:

private:
    QImage mBoardImg;
    QImage mDrawImg;
    QSize mBoardSize;
    QList<QSharedPointer<PinEntity>> mPins;
    Arduino mArduino;
}; 

#endif // UNOBOARDENTITY_H
