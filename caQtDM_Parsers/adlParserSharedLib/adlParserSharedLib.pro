CAQTDM_TOP = ../..
TARGET_PRODUCT = "ADL converter library for Display Manager"
TARGET_FILENAME = "adlParser.dll"

include($$CAQTDM_TOP/caQtDM_BuildingFactory/caQtDM_BuildControl_Version.pri)
CONFIG += caQtDM_xdl2ui
include($$CAQTDM_TOP/caQtDM.pri)

contains(QT_VER_MAJ, 5) {
  QT       += widgets
  DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
}

TEMPLATE = lib
CONFIG	+= shared plugin

INCLUDEPATH += .
INCLUDEPATH += ../adlParserSrc

MOC_DIR = moc
VPATH += ../adlParserSrc

RC_FILE = $$CAQTDM_TOP/caQtDM_Viewer/src/caQtDM.rc

HEADERS += XmlWriter.h \
    adlParserMain.h \
    QtProperties.h \
    dmsearchfile.h

SOURCES += XmlWriter.cpp parser.c \
    adlParserMain.cpp \
    QtProperties.c \
    dmsearchfile.cpp


TARGET = adlParser

OTHER_FILES += \
    stylesheet.qss


