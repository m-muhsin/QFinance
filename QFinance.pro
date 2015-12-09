#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T07:55:38
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFinance
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    income.cpp \
    expense.cpp \
    dbconn.cpp \
    viewincome.cpp \
    viewexpense.cpp

HEADERS  += mainwindow.h \
    income.h \
    expense.h \
    dbconn.h \
    viewincome.h \
    viewexpense.h

FORMS    += mainwindow.ui \
    income.ui \
    expense.ui \
    viewincome.ui \
    viewexpense.ui
