CAQTDM_TOP=../../..
include($$CAQTDM_TOP/caQtDM_BuildControl_Version/caQtDM_BuildControl_Version.pri)
QT += core gui network
contains(QT_VER_MAJ, 5) {
    QT     += widgets concurrent
}

CONFIG += warn_on
CONFIG += environment_Plugin
include ($$CAQTDM_TOP/caQtDM.pri)

TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += .
INCLUDEPATH    += ../
INCLUDEPATH    += ../../src

HEADERS         = environment_plugin.h ../controlsinterface.h

SOURCES         = environment_plugin.cpp

TARGET          = environment_plugin

android {
   INCLUDEPATH += $(ANDROIDFUNCTIONSINCLUDE)
}
