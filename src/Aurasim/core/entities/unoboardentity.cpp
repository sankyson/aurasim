#include "unoboardentity.h"
#include <QStyleOptionGraphicsItem>

UnoBoardEntity::UnoBoardEntity(QGraphicsItem *parent): Entity (parent)
{
    setFlags(ItemIsSelectable | ItemIsMovable);

    mBoardImg = QImage(":/icons/icon_uno.png");
    mBoardImg = mBoardImg.scaled(680, mBoardImg.height() * 680 / mBoardImg.width(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    mBoardSize = mBoardImg.size();
    mDrawImg = mBoardImg;

    QList<QPointF> poses;
    poses << QPointF(292.0, - 219.5)
          << QPointF(269.0, - 219.5)
          << QPointF(246.0, - 219.5)
          << QPointF(223.0, - 219.5)
          << QPointF(200.8, - 219.5)
          << QPointF(177.6, - 219.5)
          << QPointF(154.2, - 219.5)
          << QPointF(131.5, - 219.5)
          << QPointF(94.5, - 219.5)
          << QPointF(71.3, - 219.5)
          << QPointF(47.8, - 219.5)
          << QPointF(25.0, - 219.5)
          << QPointF(2.3, - 219.5)
          << QPointF(-20.4, - 219.5)
          << QPointF(177.8, 218.6)
          << QPointF(200.9, 218.6)
          << QPointF(224.4, 218.6)
          << QPointF(246.4, 218.6)
          << QPointF(269.5, 218.6)
          << QPointF(292.6, 218.6);


    for(int i = 0; i < 20; i++) {
        QSharedPointer<PinEntity> pin(new PinEntity(this));
        pin->setPos(poses.at(i));
        mPins.append(pin);
    }

    setZValue(0);
    mArduino.start();
    startTimer(25);
}

QRectF UnoBoardEntity::boundingRect() const
{
    return QRectF(-mBoardSize.width() / 2, -mBoardSize.height() / 2, mBoardSize.width(), mBoardSize.height());
}

void UnoBoardEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor drawColor(255, 255, 255);
    QPen pen;
    pen.setColor(drawColor);
    painter->setPen(pen);
    if(option->state & QStyle::State_MouseOver) {
        painter->drawRect(boundingRect());
    }

    if(option->state & QStyle::State_Selected) {
        drawColor = QColor(255, 255, 189);
        pen.setColor(drawColor);
        painter->setPen(pen);
        painter->drawRect(boundingRect());
    }

    painter->drawImage(boundingRect(), mDrawImg);
    emit tick();
}

void UnoBoardEntity::timerEvent(QTimerEvent *event)
{

//    int i = 0;
//    foreach (const int& val, mArduino.pinVals()) {
//        mPins.at(i)->setPinVal(val);
//        i++;
//    }

//    i = 0;
//    foreach (const int& val, mArduino.pinModVals()) {
//        mPins.at(i)->setPinMode(val);
//        i++;
//    }

    const QList<int>& pinModeVals = mArduino.pinModVals();
#pragma omp parallel for num_threads(6)
    for(int i = 0; i < pinModeVals.count(); i++) {
        mPins.at(i)->setPinMode(pinModeVals[i]);
    }


    const QList<int>& pinVals = mArduino.pinVals();

#pragma omp parallel for num_threads(6)
    for(int i = 0; i < pinVals.count(); i++) {
        mPins.at(i)->setPinVal(pinVals[i]);
    }

    QObject::timerEvent(event);
}
