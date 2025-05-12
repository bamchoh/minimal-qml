# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(minimal-qml LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/wayland/minimal-qml")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml WaylandCompositor)

# ソースファイルとヘッダーファイルを指定
set(SOURCES
    main.cpp
    TimeUpdater.cpp # TimeUpdaterクラスの実装ファイル
)

set(HEADERS
    TimeUpdater.h # TimeUpdaterクラスのヘッダーファイル
)

# Meta-Object Compiler (moc) を有効化
qt6_wrap_cpp(MOC_SOURCES ${HEADERS})

# 実行可能ファイルを作成
add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SOURCES})

set_target_properties(minimal-qml PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(minimal-qml PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt6::Quick
    Qt6::WaylandCompositor
)

# Resources:
set(minimal-qml_resource_files
    "main.qml"
    "bgimage.jpeg"
)

qt6_add_resources(minimal-qml "minimal-qml"
    PREFIX
        "/"
    FILES
        ${minimal-qml_resource_files}
)

install(TARGETS minimal-qml
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
