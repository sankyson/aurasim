#ifndef CIRCUITSIMSYSTEM_H
#define CIRCUITSIMSYSTEM_H

#include "../ecs/system.h"
#include <QGraphicsScene>

class CircuitSimSystem: public System
{
public:
    CircuitSimSystem(QObject* parent = nullptr);
    void initConnection();

private:
    QSharedPointer<QGraphicsScene> scene;
};

#endif // CIRCUITSIMSYSTEM_H
