#ifndef PINENTITY_H
#define PINENTITY_H

#include "../ecs/entity.h"

class PinEntity : public Entity
{
    Q_OBJECT
public:
    PinEntity(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    const int& pinMode(){return mPinMode;}
    const int& pinVal(){return mPinVal;}
    void resetState();
    const QColor& pinInColor(){return mPinInColor;}
    void setPinInColor(const QColor& color){mPinInColor = color;}
    const QColor& pinOutColor(){return mPinOutColor;}
    void setPinOutColor(const QColor& color){mPinOutColor = color;}
    const QColor& pinGroundColor(){return mPinGroundColor;}
    void setPinGroundColor(const QColor& color){mPinGroundColor = color; update();}

public slots:
    void setPinVal(const int& val);
    void setPinMode(const int& mode);


signals:
    void pinValChanged(const int& val);
    void pinModeChanged(const int& mode);

protected:

private:
    int mPinMode; // 0: INPUT, 1: OUTPUT, 2: GROUND
    int mPinVal;
    QColor mPinInColor;
    QColor mPinOutColor;
    QColor mPinGroundColor;
};

#endif // PINENTITY_H
