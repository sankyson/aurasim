#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include "component.h"

class Entity : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Entity(QGraphicsItem *parent = nullptr);
    ComponentList components();
    int id();
    void setID(const int& id);
    bool isValid();
    void addComponent(QSharedPointer<Component> com);
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

signals:
    void selected(Entity* entity);
    void diselected(Entity* entiy);
    void scenePosChanged();
    void tick();

public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    ComponentList mComponents;
    int mId;
};

typedef  QList<Entity*> EntityList;
typedef  QMap<int, Entity*> EntityMap;

#endif // ENTITY_H
