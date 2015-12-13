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
    addincome.cpp \
    addexpense.cpp \
    dbconn.cpp \
    viewincome.cpp \
    viewexpense.cpp \
    income.cpp \
    expense.cpp \
    transaction.cpp \
    calculator.cpp \
    calculatormodel.cpp \
    login.cpp \
    loginmodel.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    addincome.h \
    addexpense.h \
    dbconn.h \
    viewincome.h \
    viewexpense.h \
    income.h \
    expense.h \
    transaction.h \
    calculator.h \
    calculatormodel.h \
    login.h \
    loginmodel.h \
    about.h

FORMS    += mainwindow.ui \
    addincome.ui \
    addexpense.ui \
    viewincome.ui \
    viewexpense.ui \
    calculator.ui \
    login.ui \
    about.ui
