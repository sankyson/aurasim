#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QMap>

class System : public QObject
{
    Q_OBJECT
public:
    explicit System(QObject *parent = nullptr);
    const int& id(){return mID;}
    void setID(const int& id){mID = id;}

signals:

public slots:

private:
    int mID;
};

typedef  QMap<int, System*> SystemMap;
typedef  QList<System*> SystemList;

#endif // SYSTEM_H
