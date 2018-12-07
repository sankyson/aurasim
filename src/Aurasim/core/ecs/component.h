#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

class Component : public QObject
{
    Q_OBJECT
public:
    explicit Component(QObject *parent = nullptr);

signals:

public slots:
};

typedef  QList<QSharedPointer<Component>> ComponentList;

#endif // COMPONENT_H
