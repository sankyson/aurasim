#ifndef CONNECTORSYSTEM_H
#define CONNECTORSYSTEM_H

#include "../ecs/system.h"
#include <QGraphicsScene>
#include "../entities/connectorentity.h"
#include <QTimer>

class PinEntity;
class ConnectorSystem : public System
{
    Q_OBJECT
public:
    ConnectorSystem(QObject* parent = nullptr, QGraphicsScene* scene = nullptr);
    ~ConnectorSystem();
    void initConnections();

public slots:
    void onItemSelected(Entity* entity);
    void onItemDiselected(Entity* entity);
    void connectPin(PinEntity* start, PinEntity* end);

private:
    QSharedPointer<QGraphicsScene> scene;
    PinEntity* mSelectedPin;

};

#endif // CONNECTORSYSTEM_H
