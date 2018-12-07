#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QProcess>
#include <QtConcurrent>
#include <QThreadPool>

#define MAX_PIN_LENGTH 20

class Arduino : public QProcess
{
    Q_OBJECT
public:
    explicit Arduino(QObject *parent = nullptr);
     ~Arduino();
    void initConnection();
    Q_PROPERTY(QList<int> anaVals READ anaVals NOTIFY anaValsChanged)
    Q_PROPERTY(QList<int> digVals READ digVals NOTIFY digValsChanged)
    Q_PROPERTY(QList<int> pinModVals READ pinModVals NOTIFY pinModValsChanged)
    Q_PROPERTY(QList<int> pinRWVals READ pinRWVals NOTIFY pinRWValsChanged)

    QList<int> anaVals() {return mAnaVals;}
    QList<int> digVals() {return mDigVals;}
    QList<int> pinModVals() {return mPinMods;}
    QList<int> pinRWVals() {return mpinRWs;}
    QList<int> pinVals() {return mPinVals;}

protected:
    void timerEvent(QTimerEvent *event) override;

signals:
    void anaValsChanged();
    void digValsChanged();
    void pinModValsChanged();
    void pinRWValsChanged();
    void pinValsChanged();

public slots:
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();


private:
    bool isRunning;
    qint64* mPid;
    QList<int> mAnaVals;
    QList<int> mDigVals;
    QList<int> mPinMods;
    QList<int> mpinRWs;
    QList<int> mPinVals;

    void updateStatus();
    void updateAnaVals(QString datas);
    void updateDigVals(QString datas);
    void updatePinMods(QString datas);
    void updatePinRWs(QString datas);
};

#endif // ARDUINO_H
