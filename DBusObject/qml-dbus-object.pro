TEMPLATE = lib
INCLUDEPATH += .
QT += qml dbus
CONFIG += debug

TARGET = DBusObjectPlugin

HEADERS = plugin.h dbusobject.h
SOURCES = plugin.cpp dbusobject.cpp
