QT += quick concurrent core widgets opengl
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -fopenmp
LIBS += -lgomp -lpthread

SOURCES += \
        main.cpp \
    core/ecs/entity.cpp \
    core/ecs/component.cpp \
    core/ecs/system.cpp \
    core/ecs/entitymanager.cpp \
    core/views/mainwindow.cpp \
    core/widgets/playground.cpp \
    core/entities/spotentity.cpp \
    core/ecs/systemmanager.cpp \
    core/entities/unoboardentity.cpp \
    core/entities/pinentity.cpp \
    core/entities/connectorentity.cpp \
    core/systems/connectorsystem.cpp \
    core/entities/roundpinentity.cpp \
    core/entities/whiteledentity.cpp \
    core/entities/groundentity.cpp \
    core/chips/arduino.cpp \
    core/systems/circuitsimsystem.cpp

RESOURCES += qml.qrc \
    res.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    core/ecs/entity.h \
    core/ecs/component.h \
    core/ecs/system.h \
    core/ecs/entitymanager.h \
    core/views/mainwindow.h \
    core/widgets/playground.h \
    core/global/defines.h \
    core/entities/spotentity.h \
    core/ecs/systemmanager.h \
    core/entities/unoboardentity.h \
    core/entities/pinentity.h \
    core/entities/connectorentity.h \
    core/systems/connectorsystem.h \
    core/entities/roundpinentity.h \
    core/entities/whiteledentity.h \
    core/entities/groundentity.h \
    core/chips/arduino.h \
    core/systems/circuitsimsystem.h

DISTFILES +=

DESTDIR = $$PWD/../../build
