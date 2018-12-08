#ifndef AURASIM_H
#define AURASIM_H

#include <QObject>

class Aurasim : public QObject
{
    Q_OBJECT
public:
    explicit Aurasim(QObject *parent = nullptr);

signals:

public slots:
};

#endif // AURASIM_H