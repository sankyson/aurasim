#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <QObject>
#include "entity.h"

class EntityManager : public QObject
{
    Q_OBJECT

public:
    explicit EntityManager(QObject *parent = nullptr);
    ~EntityManager();
    EntityList entities();
    Entity *getEntity(const int& id = -1);
    void removeEntity(const int& id = -1);
    void addEntity(Entity* entiy);

signals:

public slots:

private:
    EntityMap mEntities;
    int mMaxID = -1;
};

#endif // ENTITYMANAGER_H
