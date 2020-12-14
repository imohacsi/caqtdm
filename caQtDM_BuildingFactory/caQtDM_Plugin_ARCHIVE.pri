#==========================================================================================================
archive_plugin {
        CONFIG += Define_Build_objDirs Define_Build_caQtDM_Lib Define_Build_caQtDM_QtControls

        unix:!macx:!ios:!android {
                message("archive_plugin configuration unix:!macx:!ios:!android")
                LIBS += -L$(QTBASE) -Wl,-rpath,$(QTDM_RPATH) -lcaQtDM_Lib
                CONFIG += release
        }

        macx {
                message("archive_plugin configuration macx")
                LIBS += $(CAQTDM_COLLECT)/libcaQtDM_Lib.dylib
                LIBS += $(CAQTDM_COLLECT)/libqtcontrols.dylib
                CONFIG += release
        }

        ios | android {
                message("archive_plugin configuration : ios or android")
                message( $$OUT_PWD )
                CONFIG += staticlib
                LIBS += $$OUT_PWD/../../../caQtDM_Lib/libcaQtDM_Lib.a
                LIBS += $$OUT_PWD/../../../caQtDM_QtControls/libqtcontrols.a
        }

        win32 {
                message("archive_plugin configuration win32")
                win32-msvc* || msvc{
                        CONFIG +=  Define_Symbols
                }

                win32-g++ {
                        EPICS_LIBS=$$(EPICS_BASE)/lib/win32-x86-mingw
                        LIBS += ../caQtDM_Lib/release/libcaQtDM_Lib.a
                }
        }
}
#==========================================================================================================