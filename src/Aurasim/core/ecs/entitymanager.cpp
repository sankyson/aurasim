#include "entitymanager.h"

EntityManager::EntityManager(QObject *parent) : QObject(parent)
{

}

EntityManager::~EntityManager()
{
    foreach (Entity *entity, mEntities.values()) {
        delete entity;
    }
}

EntityList EntityManager::entities()
{
    return mEntities.values();
}

Entity* EntityManager::getEntity(const int &id)
{
    if(id != -1)
        return mEntities.value(id);
    else
        return nullptr;
}

void EntityManager::removeEntity(const int &id)
{
    if(id == -1)
        return;
    mEntities.remove(id);
}

void EntityManager::addEntity(Entity *entiy)
{
    int id = -1;
    for(int i = 0; i < mMaxID; i++) {
        if (mEntities.contains(i))
            continue;
        id = i;
        break;
    }
    if (id == -1) {
        id = mMaxID + 1;
    }
    entiy->setID(id);
    mMaxID = qMax(mMaxID, id);
    mEntities.insert(id, entiy);
}
