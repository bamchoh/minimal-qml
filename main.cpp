// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtCore/QUrl>
#include <QtCore/QDebug>
#include <QTimer>
#include <QObject>
#include <QDateTime>
#include <QQmlContext>

#include <QtGui/QGuiApplication>

#include <QtQml/QQmlApplicationEngine>

#include "TimeUpdater.h"
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication app(argc, argv);

    TimeUpdater timeUpdater;

    QQmlApplicationEngine appEngine;
    appEngine.rootContext()->setContextProperty("timeUpdater", &timeUpdater);
    appEngine.load(QUrl("qrc:///main.qml"));

    return app.exec();
}
