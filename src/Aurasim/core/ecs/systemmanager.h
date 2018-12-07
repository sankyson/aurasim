#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <QObject>
#include "system.h"

class SystemManager : public QObject
{
    Q_OBJECT
public:
    explicit SystemManager(QObject *parent = nullptr);
    ~SystemManager();

    void addSystem(System* sys);
    System* getSystem(const int& id);
    void removeSystem(const int& id);

signals:

public slots:

private:
    SystemMap mSysMap;
    int mMaxID = -1;
};

#endif // SYSTEMMANAGER_H
