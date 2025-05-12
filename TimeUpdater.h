#ifndef TIMEUPDATER_H
#define TIMEUPDATER_H

#include <QObject>
#include <QTimer>
#include <QDateTime>

class TimeUpdater : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentTime READ currentTime NOTIFY timeChanged)

public:
    explicit TimeUpdater(QObject *parent = nullptr);

    QString currentTime() const;

signals:
    void timeChanged();

private slots:
    void updateTime();

private:
    QTimer timer;
    QString m_currentTime;
};

#endif // TIMEUPDATER_H
