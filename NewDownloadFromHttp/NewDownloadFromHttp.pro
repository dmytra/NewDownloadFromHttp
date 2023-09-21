DEFINES -= QT_NO_URL_CAST_FROM_STRING

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NewDownloadFromHttp
TEMPLATE = app


SOURCES  += main.cpp\
            widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
