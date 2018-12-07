#include "connectorsystem.h"
#include "../entities/pinentity.h"
#include <QDebug>
#include <QCursor>
#include <QGraphicsView>
#include <QGraphicsItem>

ConnectorSystem::ConnectorSystem(QObject *parent, QGraphicsScene* scene): System (parent),
    scene(QSharedPointer<QGraphicsScene>(scene))
{
    initConnections();
    mSelectedPin = nullptr;
}

ConnectorSystem::~ConnectorSystem()
{
//    qDebug() << ">>>>>>>>>>>" << scene;
//    if(scene){
//        foreach (QGraphicsItem* item, scene->items()) {
//            Entity* entity = static_cast<Entity*>(item);
//            if(entity) {
//                disconnect(entity, &Entity::selected, this, &ConnectorSystem::onItemSelected);
//                disconnect(entity, &Entity::diselected, this, &ConnectorSystem::onItemDiselected);
//            }
//        }
//    }
}

void ConnectorSystem::initConnections()
{
    foreach (QGraphicsItem* item, scene->items()) {
        Entity* entity = static_cast<Entity*>(item);
        if(entity) {
            connect(entity, &Entity::selected, this, &ConnectorSystem::onItemSelected);
            connect(entity, &Entity::diselected, this, &ConnectorSystem::onItemDiselected);
        }
    }

}

void ConnectorSystem::onItemSelected(Entity *entity)
{
    if (scene->selectedItems().count() > 2)
        return;
    PinEntity* pin = qobject_cast<PinEntity*>(entity);
    if(!pin) {
        if(mSelectedPin)
            mSelectedPin = nullptr;
        return;
    }

    if(!mSelectedPin) {
        mSelectedPin = pin;
        return;
    }

    if(mSelectedPin && mSelectedPin != pin){

        // cannot connect with two same pin mode's pins
        if(mSelectedPin->pinMode() == pin->pinMode()) {
            mSelectedPin = pin;
            qDebug() << "cannot connect with two same pin mode's pins" <<  mSelectedPin << "," << pin;
            return;
        }
        connectPin(mSelectedPin, pin);
    }

}

void ConnectorSystem::onItemDiselected(Entity *entity)
{
    Q_UNUSED(entity)
}

void ConnectorSystem::connectPin(PinEntity *startPin, PinEntity *endPin)
{
    ConnectorEntity* conPin = new ConnectorEntity(nullptr, startPin, endPin);
    scene->addItem(conPin);
    startPin->setSelected(false);
    endPin->setSelected(false);
    mSelectedPin = nullptr;
}

