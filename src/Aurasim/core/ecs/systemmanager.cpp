#include "systemmanager.h"
#include <QDebug>

SystemManager::SystemManager(QObject *parent) : QObject(parent)
{

}

SystemManager::~SystemManager()
{
    foreach (System* sys, mSysMap.values()) {
        sys->deleteLater();
    }

}

void SystemManager::addSystem(System *sys)
{
    int id = -1;
    for(int i = 0; i < mMaxID; i++) {
        if (mSysMap.contains(i))
            continue;
        id = i;
        break;
    }
    if (id == -1) {
        id = mMaxID + 1;
    }
    sys->setID(id);
    mMaxID = qMax(mMaxID, id);
    mSysMap.insert(id, sys);
}

System *SystemManager::getSystem(const int &id)
{
    if(id == -1 || !mSysMap.contains(id))
        return nullptr;
    return mSysMap.value(id);
}

void SystemManager::removeSystem(const int &id)
{
    if(id == -1 || !mSysMap.contains(id))
        return;
    mSysMap.remove(id);
}
