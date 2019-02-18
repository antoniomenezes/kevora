/********************************************************************************
** Form generated from reading UI file 'kvmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVMAINWINDOW_H
#define UI_KVMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <kvtreewidget.h>
#include "kvmdiarea.h"

QT_BEGIN_NAMESPACE

class Ui_KvMainWindow
{
public:
    QAction *actionPreferences;
    QAction *actionExit;
    QAction *actionAdd_Database;
    QAction *actionDelete_Database;
    QAction *actionAdd_Connection;
    QAction *actionDelete_Connection;
    QAction *actionEdit;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConnectivity_Assistant;
    QAction *actionNew_Sql;
    QAction *actionNew_Diagram;
    QAction *actionOpen;
    QAction *actionOpen_Recent;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionSave_All;
    QAction *actionClose;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelect_All;
    QAction *actionContents;
    QAction *actionAbout_Kevora;
    QAction *actionAbout_Qt;
    QAction *actionRefreshTableSchema;
    QAction *actionView_TableDefinition;
    QAction *actionView_TableData;
    QAction *actionCascade_Windows;
    QAction *actionTile_Windows;
    QAction *actionClose_All_Windows;
    QAction *actionNavigator;
    QAction *actionObjects;
    QAction *actionWindow_List;
    QAction *actionWork_Path;
    QAction *actionMain_Tool_Bar;
    QAction *actionDisconnectAll;
    QAction *actionView_ViewData;
    QAction *actionView_ViewDefinition;
    QAction *actionRefreshViewSchema;
    QAction *actionRefreshProgramSchema;
    QAction *actionRefreshEtcSchema;
    QAction *actionView_DDL;
    QAction *actionExport_Data;
    QAction *actionExport_Database_Objects;
    QAction *actionRefresh_Schemas;
    QAction *actionKevora_Updates;
    QAction *actionCompare_Database_objects;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    KvMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuIDE;
    QMenu *menu_Connection;
    QMenu *menu_Files;
    QMenu *menu_Edit;
    QMenu *menu_Tools;
    QMenu *menu_Reports;
    QMenu *menu_Help;
    QMenu *menu_View;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *navigatorDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonAddDb;
    QToolButton *toolButtonDelDb;
    QToolButton *toolButtonEdit;
    QToolButton *toolButtonAddConn;
    QToolButton *toolButtonDelConn;
    QToolButton *toolButtonOpenConn;
    QToolButton *toolButtonCloseConn;
    QToolButton *toolButtonCloseAllConn;
    QSpacerItem *horizontalSpacer;
    KvTreeWidget *dbTreeWidget;
    QDockWidget *objectsDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QComboBox *activeConnObjComboBox;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    KvTreeWidget *tableTreeWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    KvTreeWidget *viewTreeWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    KvTreeWidget *programTreeWidget;
    QWidget *tab_6;
    QGridLayout *gridLayout_5;
    KvTreeWidget *etcTreeWidget;
    QDockWidget *winListDockWidget;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_5;
    QListWidget *listWidgetWindows;
    QDockWidget *workingDirDockWidget;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_4;
    QTreeView *fileTreeView;

    void setupUi(QMainWindow *KvMainWindow)
    {
        if (KvMainWindow->objectName().isEmpty())
            KvMainWindow->setObjectName(QString::fromUtf8("KvMainWindow"));
        KvMainWindow->resize(647, 536);
        KvMainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/png_general/kevora.png"), QSize(), QIcon::Normal, QIcon::Off);
        KvMainWindow->setWindowIcon(icon);
        actionPreferences = new QAction(KvMainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/png/png_general/utilities.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon1);
        actionExit = new QAction(KvMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/png_general/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionAdd_Database = new QAction(KvMainWindow);
        actionAdd_Database->setObjectName(QString::fromUtf8("actionAdd_Database"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/png_general/db_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Database->setIcon(icon3);
        actionDelete_Database = new QAction(KvMainWindow);
        actionDelete_Database->setObjectName(QString::fromUtf8("actionDelete_Database"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/png/png_general/db_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Database->setIcon(icon4);
        actionAdd_Connection = new QAction(KvMainWindow);
        actionAdd_Connection->setObjectName(QString::fromUtf8("actionAdd_Connection"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/png/png_general/connection_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Connection->setIcon(icon5);
        actionDelete_Connection = new QAction(KvMainWindow);
        actionDelete_Connection->setObjectName(QString::fromUtf8("actionDelete_Connection"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png/png_general/connection_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Connection->setIcon(icon6);
        actionEdit = new QAction(KvMainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png/png_general/database_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon7);
        actionConnect = new QAction(KvMainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/png/png_general/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon8);
        actionDisconnect = new QAction(KvMainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/png/png_general/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon9);
        actionConnectivity_Assistant = new QAction(KvMainWindow);
        actionConnectivity_Assistant->setObjectName(QString::fromUtf8("actionConnectivity_Assistant"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/png/png_assistant/wizard_small.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnectivity_Assistant->setIcon(icon10);
        actionNew_Sql = new QAction(KvMainWindow);
        actionNew_Sql->setObjectName(QString::fromUtf8("actionNew_Sql"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/png/png_general/project_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Sql->setIcon(icon11);
        actionNew_Diagram = new QAction(KvMainWindow);
        actionNew_Diagram->setObjectName(QString::fromUtf8("actionNew_Diagram"));
        actionOpen = new QAction(KvMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/png/png_general/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon12);
        actionOpen_Recent = new QAction(KvMainWindow);
        actionOpen_Recent->setObjectName(QString::fromUtf8("actionOpen_Recent"));
        actionSave = new QAction(KvMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/png/png_general/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon13);
        actionSave_As = new QAction(KvMainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/png/png_general/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon14);
        actionSave_All = new QAction(KvMainWindow);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/png/png_general/filesaveall.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_All->setIcon(icon15);
        actionClose = new QAction(KvMainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/png/png_general/fileclose.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon16);
        actionCut = new QAction(KvMainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/png/png_general/editcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon17);
        actionCopy = new QAction(KvMainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/png/png_general/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon18);
        actionPaste = new QAction(KvMainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/png/png_general/editpaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon19);
        actionDelete = new QAction(KvMainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/png/png_general/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon20);
        actionSelect_All = new QAction(KvMainWindow);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/png/png_general/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_All->setIcon(icon21);
        actionContents = new QAction(KvMainWindow);
        actionContents->setObjectName(QString::fromUtf8("actionContents"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/png/png_general/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContents->setIcon(icon22);
        actionAbout_Kevora = new QAction(KvMainWindow);
        actionAbout_Kevora->setObjectName(QString::fromUtf8("actionAbout_Kevora"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/png/png_general/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Kevora->setIcon(icon23);
        actionAbout_Qt = new QAction(KvMainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/png/png_general/qt-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon24);
        actionRefreshTableSchema = new QAction(KvMainWindow);
        actionRefreshTableSchema->setObjectName(QString::fromUtf8("actionRefreshTableSchema"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/png/png_general/recur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefreshTableSchema->setIcon(icon25);
        actionView_TableDefinition = new QAction(KvMainWindow);
        actionView_TableDefinition->setObjectName(QString::fromUtf8("actionView_TableDefinition"));
        actionView_TableDefinition->setIcon(icon7);
        actionView_TableData = new QAction(KvMainWindow);
        actionView_TableData->setObjectName(QString::fromUtf8("actionView_TableData"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/png/png_general/table_lightning.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_TableData->setIcon(icon26);
        actionCascade_Windows = new QAction(KvMainWindow);
        actionCascade_Windows->setObjectName(QString::fromUtf8("actionCascade_Windows"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/png/png_general/application_cascade.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCascade_Windows->setIcon(icon27);
        actionTile_Windows = new QAction(KvMainWindow);
        actionTile_Windows->setObjectName(QString::fromUtf8("actionTile_Windows"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/png/png_general/application_tile_horizontal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTile_Windows->setIcon(icon28);
        actionClose_All_Windows = new QAction(KvMainWindow);
        actionClose_All_Windows->setObjectName(QString::fromUtf8("actionClose_All_Windows"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/png/png_general/close_all_windows.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_All_Windows->setIcon(icon29);
        actionNavigator = new QAction(KvMainWindow);
        actionNavigator->setObjectName(QString::fromUtf8("actionNavigator"));
        actionNavigator->setCheckable(true);
        actionObjects = new QAction(KvMainWindow);
        actionObjects->setObjectName(QString::fromUtf8("actionObjects"));
        actionObjects->setCheckable(true);
        actionWindow_List = new QAction(KvMainWindow);
        actionWindow_List->setObjectName(QString::fromUtf8("actionWindow_List"));
        actionWindow_List->setCheckable(true);
        actionWork_Path = new QAction(KvMainWindow);
        actionWork_Path->setObjectName(QString::fromUtf8("actionWork_Path"));
        actionWork_Path->setCheckable(true);
        actionMain_Tool_Bar = new QAction(KvMainWindow);
        actionMain_Tool_Bar->setObjectName(QString::fromUtf8("actionMain_Tool_Bar"));
        actionMain_Tool_Bar->setCheckable(true);
        actionMain_Tool_Bar->setChecked(false);
        actionDisconnectAll = new QAction(KvMainWindow);
        actionDisconnectAll->setObjectName(QString::fromUtf8("actionDisconnectAll"));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/png/png_general/disconnect_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnectAll->setIcon(icon30);
        actionView_ViewData = new QAction(KvMainWindow);
        actionView_ViewData->setObjectName(QString::fromUtf8("actionView_ViewData"));
        actionView_ViewData->setIcon(icon26);
        actionView_ViewDefinition = new QAction(KvMainWindow);
        actionView_ViewDefinition->setObjectName(QString::fromUtf8("actionView_ViewDefinition"));
        actionView_ViewDefinition->setIcon(icon7);
        actionRefreshViewSchema = new QAction(KvMainWindow);
        actionRefreshViewSchema->setObjectName(QString::fromUtf8("actionRefreshViewSchema"));
        actionRefreshViewSchema->setIcon(icon25);
        actionRefreshProgramSchema = new QAction(KvMainWindow);
        actionRefreshProgramSchema->setObjectName(QString::fromUtf8("actionRefreshProgramSchema"));
        actionRefreshProgramSchema->setIcon(icon25);
        actionRefreshEtcSchema = new QAction(KvMainWindow);
        actionRefreshEtcSchema->setObjectName(QString::fromUtf8("actionRefreshEtcSchema"));
        actionRefreshEtcSchema->setIcon(icon25);
        actionView_DDL = new QAction(KvMainWindow);
        actionView_DDL->setObjectName(QString::fromUtf8("actionView_DDL"));
        actionView_DDL->setIcon(icon7);
        actionExport_Data = new QAction(KvMainWindow);
        actionExport_Data->setObjectName(QString::fromUtf8("actionExport_Data"));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/png/png_general/table_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_Data->setIcon(icon31);
        actionExport_Database_Objects = new QAction(KvMainWindow);
        actionExport_Database_Objects->setObjectName(QString::fromUtf8("actionExport_Database_Objects"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/png/png_general/cog_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_Database_Objects->setIcon(icon32);
        actionRefresh_Schemas = new QAction(KvMainWindow);
        actionRefresh_Schemas->setObjectName(QString::fromUtf8("actionRefresh_Schemas"));
        actionRefresh_Schemas->setIcon(icon25);
        actionKevora_Updates = new QAction(KvMainWindow);
        actionKevora_Updates->setObjectName(QString::fromUtf8("actionKevora_Updates"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/png/png_general/arrow_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKevora_Updates->setIcon(icon33);
        actionCompare_Database_objects = new QAction(KvMainWindow);
        actionCompare_Database_objects->setObjectName(QString::fromUtf8("actionCompare_Database_objects"));
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/png/png_general/table_relationship.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompare_Database_objects->setIcon(icon34);
        centralWidget = new QWidget(KvMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new KvMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setAcceptDrops(true);
        mdiArea->setStyleSheet(QString::fromUtf8(""));
        mdiArea->setProperty("documentMode", QVariant(true));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        KvMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KvMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 22));
        menuIDE = new QMenu(menuBar);
        menuIDE->setObjectName(QString::fromUtf8("menuIDE"));
        menu_Connection = new QMenu(menuBar);
        menu_Connection->setObjectName(QString::fromUtf8("menu_Connection"));
        menu_Files = new QMenu(menuBar);
        menu_Files->setObjectName(QString::fromUtf8("menu_Files"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_Tools = new QMenu(menuBar);
        menu_Tools->setObjectName(QString::fromUtf8("menu_Tools"));
        menu_Reports = new QMenu(menuBar);
        menu_Reports->setObjectName(QString::fromUtf8("menu_Reports"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        KvMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KvMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        KvMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KvMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        KvMainWindow->setStatusBar(statusBar);
        navigatorDockWidget = new QDockWidget(KvMainWindow);
        navigatorDockWidget->setObjectName(QString::fromUtf8("navigatorDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 4, 2, 6);
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 4, 4, 6);
        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 25));
        frame->setMaximumSize(QSize(16777215, 25));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButtonAddDb = new QToolButton(frame);
        toolButtonAddDb->setObjectName(QString::fromUtf8("toolButtonAddDb"));
        toolButtonAddDb->setMaximumSize(QSize(25, 25));
        toolButtonAddDb->setIcon(icon3);

        horizontalLayout->addWidget(toolButtonAddDb);

        toolButtonDelDb = new QToolButton(frame);
        toolButtonDelDb->setObjectName(QString::fromUtf8("toolButtonDelDb"));
        toolButtonDelDb->setMaximumSize(QSize(25, 25));
        toolButtonDelDb->setIcon(icon4);

        horizontalLayout->addWidget(toolButtonDelDb);

        toolButtonEdit = new QToolButton(frame);
        toolButtonEdit->setObjectName(QString::fromUtf8("toolButtonEdit"));
        toolButtonEdit->setMaximumSize(QSize(25, 25));
        toolButtonEdit->setIcon(icon7);

        horizontalLayout->addWidget(toolButtonEdit);

        toolButtonAddConn = new QToolButton(frame);
        toolButtonAddConn->setObjectName(QString::fromUtf8("toolButtonAddConn"));
        toolButtonAddConn->setMaximumSize(QSize(25, 25));
        toolButtonAddConn->setIcon(icon5);

        horizontalLayout->addWidget(toolButtonAddConn);

        toolButtonDelConn = new QToolButton(frame);
        toolButtonDelConn->setObjectName(QString::fromUtf8("toolButtonDelConn"));
        toolButtonDelConn->setMaximumSize(QSize(25, 25));
        toolButtonDelConn->setIcon(icon6);

        horizontalLayout->addWidget(toolButtonDelConn);

        toolButtonOpenConn = new QToolButton(frame);
        toolButtonOpenConn->setObjectName(QString::fromUtf8("toolButtonOpenConn"));
        toolButtonOpenConn->setMaximumSize(QSize(25, 25));
        toolButtonOpenConn->setIcon(icon8);

        horizontalLayout->addWidget(toolButtonOpenConn);

        toolButtonCloseConn = new QToolButton(frame);
        toolButtonCloseConn->setObjectName(QString::fromUtf8("toolButtonCloseConn"));
        toolButtonCloseConn->setMaximumSize(QSize(25, 25));
        toolButtonCloseConn->setIcon(icon9);

        horizontalLayout->addWidget(toolButtonCloseConn);

        toolButtonCloseAllConn = new QToolButton(frame);
        toolButtonCloseAllConn->setObjectName(QString::fromUtf8("toolButtonCloseAllConn"));
        toolButtonCloseAllConn->setMaximumSize(QSize(25, 25));
        toolButtonCloseAllConn->setIcon(icon30);

        horizontalLayout->addWidget(toolButtonCloseAllConn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(frame);

        dbTreeWidget = new KvTreeWidget(tab);
        dbTreeWidget->setObjectName(QString::fromUtf8("dbTreeWidget"));
        dbTreeWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        dbTreeWidget->setIndentation(10);
        dbTreeWidget->setSortingEnabled(true);
        dbTreeWidget->setAnimated(false);

        verticalLayout_3->addWidget(dbTreeWidget);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        navigatorDockWidget->setWidget(dockWidgetContents);
        KvMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), navigatorDockWidget);
        objectsDockWidget = new QDockWidget(KvMainWindow);
        objectsDockWidget->setObjectName(QString::fromUtf8("objectsDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 4, 2, 0);
        activeConnObjComboBox = new QComboBox(dockWidgetContents_2);
        activeConnObjComboBox->addItem(QString());
        activeConnObjComboBox->setObjectName(QString::fromUtf8("activeConnObjComboBox"));

        verticalLayout->addWidget(activeConnObjComboBox);

        tabWidget_2 = new QTabWidget(dockWidgetContents_2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(4, 4, 4, 6);
        tableTreeWidget = new KvTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tableTreeWidget->setHeaderItem(__qtreewidgetitem);
        tableTreeWidget->setObjectName(QString::fromUtf8("tableTreeWidget"));
        tableTreeWidget->setSortingEnabled(true);
        tableTreeWidget->header()->setVisible(false);

        gridLayout_2->addWidget(tableTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(4, 4, 4, 6);
        viewTreeWidget = new KvTreeWidget(tab_4);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        viewTreeWidget->setHeaderItem(__qtreewidgetitem1);
        viewTreeWidget->setObjectName(QString::fromUtf8("viewTreeWidget"));
        viewTreeWidget->setSortingEnabled(true);
        viewTreeWidget->header()->setVisible(false);

        gridLayout_3->addWidget(viewTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(4, 4, 4, 6);
        programTreeWidget = new KvTreeWidget(tab_5);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QString::fromUtf8("1"));
        programTreeWidget->setHeaderItem(__qtreewidgetitem2);
        programTreeWidget->setObjectName(QString::fromUtf8("programTreeWidget"));
        programTreeWidget->setSortingEnabled(true);
        programTreeWidget->header()->setVisible(false);

        gridLayout_4->addWidget(programTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_5 = new QGridLayout(tab_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(4, 4, 4, 6);
        etcTreeWidget = new KvTreeWidget(tab_6);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setText(0, QString::fromUtf8("1"));
        etcTreeWidget->setHeaderItem(__qtreewidgetitem3);
        etcTreeWidget->setObjectName(QString::fromUtf8("etcTreeWidget"));
        etcTreeWidget->setSortingEnabled(true);
        etcTreeWidget->header()->setVisible(false);

        gridLayout_5->addWidget(etcTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget_2);

        objectsDockWidget->setWidget(dockWidgetContents_2);
        KvMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), objectsDockWidget);
        winListDockWidget = new QDockWidget(KvMainWindow);
        winListDockWidget->setObjectName(QString::fromUtf8("winListDockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 4, 2, 0);
        listWidgetWindows = new QListWidget(dockWidgetContents_3);
        listWidgetWindows->setObjectName(QString::fromUtf8("listWidgetWindows"));
        listWidgetWindows->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout_5->addWidget(listWidgetWindows);

        winListDockWidget->setWidget(dockWidgetContents_3);
        KvMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), winListDockWidget);
        workingDirDockWidget = new QDockWidget(KvMainWindow);
        workingDirDockWidget->setObjectName(QString::fromUtf8("workingDirDockWidget"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 4, 2, 0);
        fileTreeView = new QTreeView(dockWidgetContents_4);
        fileTreeView->setObjectName(QString::fromUtf8("fileTreeView"));
        fileTreeView->setDragEnabled(true);
        fileTreeView->setDragDropMode(QAbstractItemView::DragOnly);
        fileTreeView->setAlternatingRowColors(true);
        fileTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        fileTreeView->setSortingEnabled(true);
        fileTreeView->header()->setMinimumSectionSize(50);

        verticalLayout_4->addWidget(fileTreeView);

        workingDirDockWidget->setWidget(dockWidgetContents_4);
        KvMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), workingDirDockWidget);

        menuBar->addAction(menuIDE->menuAction());
        menuBar->addAction(menu_Connection->menuAction());
        menuBar->addAction(menu_Files->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Tools->menuAction());
        menuBar->addAction(menu_Reports->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuIDE->addAction(actionPreferences);
        menuIDE->addSeparator();
        menuIDE->addAction(actionExit);
        menu_Connection->addAction(actionAdd_Database);
        menu_Connection->addAction(actionDelete_Database);
        menu_Connection->addAction(actionAdd_Connection);
        menu_Connection->addAction(actionDelete_Connection);
        menu_Connection->addSeparator();
        menu_Connection->addAction(actionEdit);
        menu_Connection->addAction(actionConnect);
        menu_Connection->addAction(actionDisconnect);
        menu_Connection->addAction(actionDisconnectAll);
        menu_Connection->addSeparator();
        menu_Files->addAction(actionNew_Sql);
        menu_Files->addAction(actionNew_Diagram);
        menu_Files->addAction(actionOpen);
        menu_Files->addAction(actionOpen_Recent);
        menu_Files->addAction(actionSave);
        menu_Files->addAction(actionSave_As);
        menu_Files->addAction(actionSave_All);
        menu_Files->addSeparator();
        menu_Files->addAction(actionClose);
        menu_Edit->addAction(actionCut);
        menu_Edit->addAction(actionCopy);
        menu_Edit->addAction(actionPaste);
        menu_Edit->addAction(actionDelete);
        menu_Edit->addAction(actionSelect_All);
        menu_Tools->addAction(actionExport_Database_Objects);
        menu_Tools->addAction(actionCompare_Database_objects);
        menu_Help->addAction(actionContents);
        menu_Help->addAction(actionAbout_Kevora);
        menu_Help->addAction(actionAbout_Qt);
        menu_Help->addSeparator();
        menu_Help->addAction(actionKevora_Updates);
        menu_View->addAction(actionMain_Tool_Bar);
        menu_View->addSeparator();
        menu_View->addAction(actionNavigator);
        menu_View->addAction(actionObjects);
        menu_View->addAction(actionWindow_List);
        menu_View->addAction(actionWork_Path);
        mainToolBar->addAction(actionExit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNew_Sql);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionClose);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCascade_Windows);
        mainToolBar->addAction(actionTile_Windows);
        mainToolBar->addAction(actionClose_All_Windows);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExport_Database_Objects);

        retranslateUi(KvMainWindow);
        QObject::connect(navigatorDockWidget, SIGNAL(visibilityChanged(bool)), KvMainWindow, SLOT(updateViewMenu()));
        QObject::connect(objectsDockWidget, SIGNAL(visibilityChanged(bool)), KvMainWindow, SLOT(updateViewMenu()));
        QObject::connect(winListDockWidget, SIGNAL(visibilityChanged(bool)), KvMainWindow, SLOT(updateViewMenu()));
        QObject::connect(workingDirDockWidget, SIGNAL(visibilityChanged(bool)), KvMainWindow, SLOT(updateViewMenu()));

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(KvMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *KvMainWindow)
    {
        KvMainWindow->setWindowTitle(QApplication::translate("KvMainWindow", "Kevora", nullptr));
#ifndef QT_NO_WHATSTHIS
        KvMainWindow->setWhatsThis(QApplication::translate("KvMainWindow", "The IDE of your dreams!", nullptr));
#endif // QT_NO_WHATSTHIS
        actionPreferences->setText(QApplication::translate("KvMainWindow", "Settings", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPreferences->setToolTip(QApplication::translate("KvMainWindow", "Settings", nullptr));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("KvMainWindow", "Exit", nullptr));
        actionAdd_Database->setText(QApplication::translate("KvMainWindow", "Add Database", nullptr));
        actionDelete_Database->setText(QApplication::translate("KvMainWindow", "Delete Database", nullptr));
        actionAdd_Connection->setText(QApplication::translate("KvMainWindow", "Add Connection", nullptr));
        actionDelete_Connection->setText(QApplication::translate("KvMainWindow", "Delete Connection", nullptr));
        actionEdit->setText(QApplication::translate("KvMainWindow", "Edit", nullptr));
        actionConnect->setText(QApplication::translate("KvMainWindow", "Connect", nullptr));
        actionDisconnect->setText(QApplication::translate("KvMainWindow", "Disconnect", nullptr));
        actionConnectivity_Assistant->setText(QApplication::translate("KvMainWindow", "Connectivity Assistant", nullptr));
        actionNew_Sql->setText(QApplication::translate("KvMainWindow", "New Sql Window", nullptr));
        actionNew_Diagram->setText(QApplication::translate("KvMainWindow", "New Diagram Window", nullptr));
        actionOpen->setText(QApplication::translate("KvMainWindow", "Open File", nullptr));
        actionOpen_Recent->setText(QApplication::translate("KvMainWindow", "Open Recent...", nullptr));
        actionSave->setText(QApplication::translate("KvMainWindow", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("KvMainWindow", "Save As...", nullptr));
        actionSave_All->setText(QApplication::translate("KvMainWindow", "Save All", nullptr));
        actionClose->setText(QApplication::translate("KvMainWindow", "Close", nullptr));
        actionCut->setText(QApplication::translate("KvMainWindow", "Cut", nullptr));
        actionCopy->setText(QApplication::translate("KvMainWindow", "Copy", nullptr));
        actionPaste->setText(QApplication::translate("KvMainWindow", "Paste", nullptr));
        actionDelete->setText(QApplication::translate("KvMainWindow", "Delete", nullptr));
        actionSelect_All->setText(QApplication::translate("KvMainWindow", "Select All", nullptr));
        actionContents->setText(QApplication::translate("KvMainWindow", "Contents", nullptr));
        actionAbout_Kevora->setText(QApplication::translate("KvMainWindow", "About Kevora", nullptr));
        actionAbout_Qt->setText(QApplication::translate("KvMainWindow", "About Qt", nullptr));
        actionRefreshTableSchema->setText(QApplication::translate("KvMainWindow", "Refresh", nullptr));
        actionView_TableDefinition->setText(QApplication::translate("KvMainWindow", "View Definition", nullptr));
        actionView_TableData->setText(QApplication::translate("KvMainWindow", "View Data", nullptr));
        actionCascade_Windows->setText(QApplication::translate("KvMainWindow", "Cascade Windows", nullptr));
        actionTile_Windows->setText(QApplication::translate("KvMainWindow", "Tile Windows", nullptr));
        actionClose_All_Windows->setText(QApplication::translate("KvMainWindow", "Close All Windows", nullptr));
        actionNavigator->setText(QApplication::translate("KvMainWindow", "Navigator", nullptr));
        actionObjects->setText(QApplication::translate("KvMainWindow", "Objects", nullptr));
        actionWindow_List->setText(QApplication::translate("KvMainWindow", "Window List", nullptr));
        actionWork_Path->setText(QApplication::translate("KvMainWindow", "Work Path", nullptr));
        actionMain_Tool_Bar->setText(QApplication::translate("KvMainWindow", "Main Tool Bar", nullptr));
        actionDisconnectAll->setText(QApplication::translate("KvMainWindow", "Disconnect All", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisconnectAll->setToolTip(QApplication::translate("KvMainWindow", "Disconnect All", nullptr));
#endif // QT_NO_TOOLTIP
        actionView_ViewData->setText(QApplication::translate("KvMainWindow", "View Data", nullptr));
        actionView_ViewDefinition->setText(QApplication::translate("KvMainWindow", "View Definition", nullptr));
        actionRefreshViewSchema->setText(QApplication::translate("KvMainWindow", "Refresh", nullptr));
        actionRefreshProgramSchema->setText(QApplication::translate("KvMainWindow", "Refresh", nullptr));
        actionRefreshEtcSchema->setText(QApplication::translate("KvMainWindow", "Refresh", nullptr));
        actionView_DDL->setText(QApplication::translate("KvMainWindow", "View DDL", nullptr));
        actionExport_Data->setText(QApplication::translate("KvMainWindow", "Export Data", nullptr));
        actionExport_Database_Objects->setText(QApplication::translate("KvMainWindow", "Export Database Objects", nullptr));
        actionRefresh_Schemas->setText(QApplication::translate("KvMainWindow", "Refresh", nullptr));
        actionKevora_Updates->setText(QApplication::translate("KvMainWindow", "Kevora Updates", nullptr));
        actionCompare_Database_objects->setText(QApplication::translate("KvMainWindow", "Compare Database Objects", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCompare_Database_objects->setToolTip(QApplication::translate("KvMainWindow", "Compare Database Objects", nullptr));
#endif // QT_NO_TOOLTIP
        menuIDE->setTitle(QApplication::translate("KvMainWindow", "&IDE", nullptr));
        menu_Connection->setTitle(QApplication::translate("KvMainWindow", "&Connections", nullptr));
        menu_Files->setTitle(QApplication::translate("KvMainWindow", "&Files", nullptr));
        menu_Edit->setTitle(QApplication::translate("KvMainWindow", "&Edit", nullptr));
        menu_Tools->setTitle(QApplication::translate("KvMainWindow", "&Tools", nullptr));
        menu_Reports->setTitle(QApplication::translate("KvMainWindow", "&Reports", nullptr));
        menu_Help->setTitle(QApplication::translate("KvMainWindow", "&Help", nullptr));
        menu_View->setTitle(QApplication::translate("KvMainWindow", "&View", nullptr));
        mainToolBar->setWindowTitle(QApplication::translate("KvMainWindow", "Main Tool Bar", nullptr));
        navigatorDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Navigator", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonAddDb->setToolTip(QApplication::translate("KvMainWindow", "Add a database item", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonAddDb->setText(QApplication::translate("KvMainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonDelDb->setToolTip(QApplication::translate("KvMainWindow", "Remove a database item", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonDelDb->setText(QApplication::translate("KvMainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonEdit->setToolTip(QApplication::translate("KvMainWindow", "Edit a database or connection item", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonEdit->setText(QApplication::translate("KvMainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonAddConn->setToolTip(QApplication::translate("KvMainWindow", "Add a connection", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonAddConn->setText(QApplication::translate("KvMainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonDelConn->setToolTip(QApplication::translate("KvMainWindow", "Remove a connection", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonDelConn->setText(QApplication::translate("KvMainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonOpenConn->setToolTip(QApplication::translate("KvMainWindow", "Open a connection", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonOpenConn->setText(QApplication::translate("KvMainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonCloseConn->setToolTip(QApplication::translate("KvMainWindow", "Close a connection", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonCloseConn->setText(QApplication::translate("KvMainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonCloseAllConn->setToolTip(QApplication::translate("KvMainWindow", "Close all connections", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonCloseAllConn->setText(QApplication::translate("KvMainWindow", "...", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = dbTreeWidget->headerItem();
        ___qtreewidgetitem->setText(7, QApplication::translate("KvMainWindow", "Status", nullptr));
        ___qtreewidgetitem->setText(6, QApplication::translate("KvMainWindow", "Comments", nullptr));
        ___qtreewidgetitem->setText(5, QApplication::translate("KvMainWindow", "Driver", nullptr));
        ___qtreewidgetitem->setText(4, QApplication::translate("KvMainWindow", "DbName", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("KvMainWindow", "Port", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("KvMainWindow", "Host", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("KvMainWindow", "Type", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("KvMainWindow", "Connection", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("KvMainWindow", "Connection List", nullptr));
        objectsDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Objects", nullptr));
        activeConnObjComboBox->setItemText(0, QApplication::translate("KvMainWindow", "Objects from All Active Connections", nullptr));

        QTreeWidgetItem *___qtreewidgetitem1 = tableTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("KvMainWindow", "2", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("KvMainWindow", "Tables", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = viewTreeWidget->headerItem();
        ___qtreewidgetitem2->setText(1, QApplication::translate("KvMainWindow", "2", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("KvMainWindow", "Views", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = programTreeWidget->headerItem();
        ___qtreewidgetitem3->setText(1, QApplication::translate("KvMainWindow", "2", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("KvMainWindow", "Programs", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = etcTreeWidget->headerItem();
        ___qtreewidgetitem4->setText(1, QApplication::translate("KvMainWindow", "2", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("KvMainWindow", "Etc", nullptr));
        winListDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Window List", nullptr));
        workingDirDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Work Path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KvMainWindow: public Ui_KvMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVMAINWINDOW_H
