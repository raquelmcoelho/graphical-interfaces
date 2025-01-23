#
# Qt Project file
#
# @author Sebastien Fourey
# @brief  Sample application -- Ensicaen, 2cd year -- GUI programming
#

TEMPLATE  = app
CONFIG  += warn_on
CONFIG  += c++11
QT += core gui widgets
INCLUDEPATH += ./include
DEPENDPATH += ./include

TARGET  = main

SOURCES  = src/main.cpp \
           src/ColorWidget.cpp \
           src/MainWidget.cpp

HEADERS  = include/ColorWidget.h \
           include/MainWidget.h

MOC_DIR  = moc
OBJECTS_DIR  = obj

# File readed by Vinicius and Raquel (1.2.2)
