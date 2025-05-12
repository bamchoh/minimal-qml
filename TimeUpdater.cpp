#include "TimeUpdater.h"

TimeUpdater::TimeUpdater(QObject *parent) : QObject(parent) {
    connect(&timer, &QTimer::timeout, this, &TimeUpdater::updateTime);
    timer.start(1000); // 1秒ごとに更新
}

QString TimeUpdater::currentTime() const {
    return m_currentTime;
}

void TimeUpdater::updateTime() {
    m_currentTime = QDateTime::currentDateTime().toString("hh:mm:ss");
    emit timeChanged();
}
