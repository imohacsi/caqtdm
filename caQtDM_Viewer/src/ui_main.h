/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *reloadAction;
    QAction *unconnectedAction;
    QAction *fileAction;
    QAction *aboutAction;
    QAction *directAction;
    QAction *timedAction;
    QAction *helpAction;
    QAction *emptycacheAction;
    QAction *displayUrl;
    QAction *clearAction;
    QAction *ReloadWindowAction;
    QAction *PrintWindowAction;
    QWidget *centralwidget;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuPV;
    QMenu *menuUpdateType;
    QMenu *menuHelp;
    QMenu *menuHttp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(493, 144);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        reloadAction = new QAction(MainWindow);
        reloadAction->setObjectName(QString::fromUtf8("reloadAction"));
        unconnectedAction = new QAction(MainWindow);
        unconnectedAction->setObjectName(QString::fromUtf8("unconnectedAction"));
        fileAction = new QAction(MainWindow);
        fileAction->setObjectName(QString::fromUtf8("fileAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        directAction = new QAction(MainWindow);
        directAction->setObjectName(QString::fromUtf8("directAction"));
        directAction->setCheckable(true);
        timedAction = new QAction(MainWindow);
        timedAction->setObjectName(QString::fromUtf8("timedAction"));
        timedAction->setCheckable(true);
        helpAction = new QAction(MainWindow);
        helpAction->setObjectName(QString::fromUtf8("helpAction"));
        emptycacheAction = new QAction(MainWindow);
        emptycacheAction->setObjectName(QString::fromUtf8("emptycacheAction"));
        displayUrl = new QAction(MainWindow);
        displayUrl->setObjectName(QString::fromUtf8("displayUrl"));
        clearAction = new QAction(MainWindow);
        clearAction->setObjectName(QString::fromUtf8("clearAction"));
        ReloadWindowAction = new QAction(MainWindow);
        ReloadWindowAction->setObjectName(QString::fromUtf8("ReloadWindowAction"));
        PrintWindowAction = new QAction(MainWindow);
        PrintWindowAction->setObjectName(QString::fromUtf8("PrintWindowAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 493, 24));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuPV = new QMenu(menuBar);
        menuPV->setObjectName(QString::fromUtf8("menuPV"));
        menuUpdateType = new QMenu(menuBar);
        menuUpdateType->setObjectName(QString::fromUtf8("menuUpdateType"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHttp = new QMenu(menuBar);
        menuHttp->setObjectName(QString::fromUtf8("menuHttp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuPV->menuAction());
        menuBar->addAction(menuUpdateType->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuHttp->menuAction());
        menuMenu->addAction(fileAction);
        menuMenu->addSeparator();
        menuMenu->addSeparator();
        menuMenu->addAction(reloadAction);
        menuMenu->addAction(exitAction);
        menuMenu->addSeparator();
        menuMenu->addSeparator();
        menuMenu->addSeparator();
        menuMenu->addSeparator();
        menuPV->addAction(unconnectedAction);
        menuUpdateType->addAction(directAction);
        menuUpdateType->addAction(timedAction);
        menuHelp->addAction(helpAction);
        menuHelp->addAction(aboutAction);
        menuHttp->addAction(emptycacheAction);
        menuHttp->addAction(displayUrl);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        exitAction->setText(QApplication::translate("MainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        reloadAction->setText(QApplication::translate("MainWindow", "&Reload All", 0, QApplication::UnicodeUTF8));
        reloadAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+R", 0, QApplication::UnicodeUTF8));
        unconnectedAction->setText(QApplication::translate("MainWindow", "&Unconnected", 0, QApplication::UnicodeUTF8));
        unconnectedAction->setIconText(QApplication::translate("MainWindow", "Unconnected PV's", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        unconnectedAction->setToolTip(QApplication::translate("MainWindow", "Unconnected PV's", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fileAction->setText(QApplication::translate("MainWindow", "Open &File", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        fileAction->setToolTip(QApplication::translate("MainWindow", "Open File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fileAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        aboutAction->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        aboutAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        directAction->setText(QApplication::translate("MainWindow", "Direct", 0, QApplication::UnicodeUTF8));
        timedAction->setText(QApplication::translate("MainWindow", "Timed", 0, QApplication::UnicodeUTF8));
        helpAction->setText(QApplication::translate("MainWindow", "Contents", 0, QApplication::UnicodeUTF8));
        emptycacheAction->setText(QApplication::translate("MainWindow", "Emptycache", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        emptycacheAction->setToolTip(QApplication::translate("MainWindow", "empty http download directory", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        displayUrl->setText(QApplication::translate("MainWindow", "url", 0, QApplication::UnicodeUTF8));
        clearAction->setText(QApplication::translate("MainWindow", "&Clear Messages", 0, QApplication::UnicodeUTF8));
        ReloadWindowAction->setText(QApplication::translate("MainWindow", "Reload Activ &Window", 0, QApplication::UnicodeUTF8));
        ReloadWindowAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        PrintWindowAction->setText(QApplication::translate("MainWindow", "&Print Activ Window", 0, QApplication::UnicodeUTF8));
        PrintWindowAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "&Menu", 0, QApplication::UnicodeUTF8));
        menuPV->setTitle(QApplication::translate("MainWindow", "&PV", 0, QApplication::UnicodeUTF8));
        menuUpdateType->setTitle(QApplication::translate("MainWindow", "&UpdateType", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menuHttp->setTitle(QApplication::translate("MainWindow", "Http", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
