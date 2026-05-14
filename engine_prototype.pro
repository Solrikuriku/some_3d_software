QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:/Users/1657434/Documents/MeshObjects
LIBS += -LC:/Users/1657434/Documents/MeshObjects/build/6_9_0_mingw64_shared-Debug/debug -lMeshObjects

INCLUDEPATH += C:/Users/1657434/Documents/EngineMath
LIBS += -LC:/Users/1657434/Documents/EngineMath/build/6_9_0_mingw64_shared-Debug/debug -lEngineMath

INCLUDEPATH += C:/Users/1657434/Documents/Scene
LIBS += -LC:/Users/1657434/Documents/Scene/build/6_9_0_mingw64_shared-Debug/debug -lScene

SOURCES += \
    enginegraphicsview.cpp \
    engineui.cpp \
    main.cpp

HEADERS += \
    enginegraphicsview.h \
    engineui.h

FORMS += \
    engineui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
