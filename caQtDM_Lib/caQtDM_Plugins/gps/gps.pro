CAQTDM_TOP=../../..
include($$CAQTDM_TOP/caQtDM_BuildingFactory/caQtDM_BuildControl_Version.pri)
contains(QT_VER_MAJ, 5) {
    QT     +=  core gui widgets positioning
}
CONFIG += warn_on
CONFIG += release
CONFIG += gps_plugin
include ($$CAQTDM_TOP/caQtDM.pri)

MOC_DIR = ./moc
VPATH += ./src

TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += .
INCLUDEPATH    += ../
INCLUDEPATH    += ../../src
HEADERS         = gps_plugin.h ../controlsinterface.h
SOURCES         = gps_plugin.cpp
TARGET          = gps_plugin
android {
   INCLUDEPATH += $(ANDROIDFUNCTIONSINCLUDE)
}
