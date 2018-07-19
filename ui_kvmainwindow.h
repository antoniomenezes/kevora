/********************************************************************************
** Form generated from reading UI file 'kvmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVMAINWINDOW_H
#define UI_KVMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            KvMainWindow->setObjectName(QStringLiteral("KvMainWindow"));
        KvMainWindow->resize(647, 536);
        KvMainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/png_general/kevora.png"), QSize(), QIcon::Normal, QIcon::Off);
        KvMainWindow->setWindowIcon(icon);
        actionPreferences = new QAction(KvMainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/png_general/utilities.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon1);
        actionExit = new QAction(KvMainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/png_general/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionAdd_Database = new QAction(KvMainWindow);
        actionAdd_Database->setObjectName(QStringLiteral("actionAdd_Database"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/png_general/db_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Database->setIcon(icon3);
        actionDelete_Database = new QAction(KvMainWindow);
        actionDelete_Database->setObjectName(QStringLiteral("actionDelete_Database"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/png/png_general/db_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Database->setIcon(icon4);
        actionAdd_Connection = new QAction(KvMainWindow);
        actionAdd_Connection->setObjectName(QStringLiteral("actionAdd_Connection"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/png/png_general/connection_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Connection->setIcon(icon5);
        actionDelete_Connection = new QAction(KvMainWindow);
        actionDelete_Connection->setObjectName(QStringLiteral("actionDelete_Connection"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/png/png_general/connection_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Connection->setIcon(icon6);
        actionEdit = new QAction(KvMainWindow);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/png/png_general/database_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon7);
        actionConnect = new QAction(KvMainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/png/png_general/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon8);
        actionDisconnect = new QAction(KvMainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/png/png_general/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon9);
        actionConnectivity_Assistant = new QAction(KvMainWindow);
        actionConnectivity_Assistant->setObjectName(QStringLiteral("actionConnectivity_Assistant"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/png/png_assistant/wizard_small.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnectivity_Assistant->setIcon(icon10);
        actionNew_Sql = new QAction(KvMainWindow);
        actionNew_Sql->setObjectName(QStringLiteral("actionNew_Sql"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/png/png_general/project_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Sql->setIcon(icon11);
        actionNew_Diagram = new QAction(KvMainWindow);
        actionNew_Diagram->setObjectName(QStringLiteral("actionNew_Diagram"));
        actionOpen = new QAction(KvMainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/png/png_general/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon12);
        actionOpen_Recent = new QAction(KvMainWindow);
        actionOpen_Recent->setObjectName(QStringLiteral("actionOpen_Recent"));
        actionSave = new QAction(KvMainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/png/png_general/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon13);
        actionSave_As = new QAction(KvMainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/png/png_general/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon14);
        actionSave_All = new QAction(KvMainWindow);
        actionSave_All->setObjectName(QStringLiteral("actionSave_All"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/png/png_general/filesaveall.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_All->setIcon(icon15);
        actionClose = new QAction(KvMainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/png/png_general/fileclose.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon16);
        actionCut = new QAction(KvMainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/png/png_general/editcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon17);
        actionCopy = new QAction(KvMainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/png/png_general/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon18);
        actionPaste = new QAction(KvMainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/png/png_general/editpaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon19);
        actionDelete = new QAction(KvMainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/png/png_general/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon20);
        actionSelect_All = new QAction(KvMainWindow);
        actionSelect_All->setObjectName(QStringLiteral("actionSelect_All"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/png/png_general/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_All->setIcon(icon21);
        actionContents = new QAction(KvMainWindow);
        actionContents->setObjectName(QStringLiteral("actionContents"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/png/png_general/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContents->setIcon(icon22);
        actionAbout_Kevora = new QAction(KvMainWindow);
        actionAbout_Kevora->setObjectName(QStringLiteral("actionAbout_Kevora"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/png/png_general/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Kevora->setIcon(icon23);
        actionAbout_Qt = new QAction(KvMainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/png/png_general/qt-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon24);
        actionRefreshTableSchema = new QAction(KvMainWindow);
        actionRefreshTableSchema->setObjectName(QStringLiteral("actionRefreshTableSchema"));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/png/png_general/recur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefreshTableSchema->setIcon(icon25);
        actionView_TableDefinition = new QAction(KvMainWindow);
        actionView_TableDefinition->setObjectName(QStringLiteral("actionView_TableDefinition"));
        actionView_TableDefinition->setIcon(icon7);
        actionView_TableData = new QAction(KvMainWindow);
        actionView_TableData->setObjectName(QStringLiteral("actionView_TableData"));
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/png/png_general/table_lightning.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_TableData->setIcon(icon26);
        actionCascade_Windows = new QAction(KvMainWindow);
        actionCascade_Windows->setObjectName(QStringLiteral("actionCascade_Windows"));
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/png/png_general/application_cascade.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCascade_Windows->setIcon(icon27);
        actionTile_Windows = new QAction(KvMainWindow);
        actionTile_Windows->setObjectName(QStringLiteral("actionTile_Windows"));
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/png/png_general/application_tile_horizontal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTile_Windows->setIcon(icon28);
        actionClose_All_Windows = new QAction(KvMainWindow);
        actionClose_All_Windows->setObjectName(QStringLiteral("actionClose_All_Windows"));
        QIcon icon29;
        icon29.addFile(QStringLiteral(":/png/png_general/close_all_windows.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_All_Windows->setIcon(icon29);
        actionNavigator = new QAction(KvMainWindow);
        actionNavigator->setObjectName(QStringLiteral("actionNavigator"));
        actionNavigator->setCheckable(true);
        actionObjects = new QAction(KvMainWindow);
        actionObjects->setObjectName(QStringLiteral("actionObjects"));
        actionObjects->setCheckable(true);
        actionWindow_List = new QAction(KvMainWindow);
        actionWindow_List->setObjectName(QStringLiteral("actionWindow_List"));
        actionWindow_List->setCheckable(true);
        actionWork_Path = new QAction(KvMainWindow);
        actionWork_Path->setObjectName(QStringLiteral("actionWork_Path"));
        actionWork_Path->setCheckable(true);
        actionMain_Tool_Bar = new QAction(KvMainWindow);
        actionMain_Tool_Bar->setObjectName(QStringLiteral("actionMain_Tool_Bar"));
        actionMain_Tool_Bar->setCheckable(true);
        actionMain_Tool_Bar->setChecked(false);
        actionDisconnectAll = new QAction(KvMainWindow);
        actionDisconnectAll->setObjectName(QStringLiteral("actionDisconnectAll"));
        QIcon icon30;
        icon30.addFile(QStringLiteral(":/png/png_general/disconnect_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnectAll->setIcon(icon30);
        actionView_ViewData = new QAction(KvMainWindow);
        actionView_ViewData->setObjectName(QStringLiteral("actionView_ViewData"));
        actionView_ViewData->setIcon(icon26);
        actionView_ViewDefinition = new QAction(KvMainWindow);
        actionView_ViewDefinition->setObjectName(QStringLiteral("actionView_ViewDefinition"));
        actionView_ViewDefinition->setIcon(icon7);
        actionRefreshViewSchema = new QAction(KvMainWindow);
        actionRefreshViewSchema->setObjectName(QStringLiteral("actionRefreshViewSchema"));
        actionRefreshViewSchema->setIcon(icon25);
        actionRefreshProgramSchema = new QAction(KvMainWindow);
        actionRefreshProgramSchema->setObjectName(QStringLiteral("actionRefreshProgramSchema"));
        actionRefreshProgramSchema->setIcon(icon25);
        actionRefreshEtcSchema = new QAction(KvMainWindow);
        actionRefreshEtcSchema->setObjectName(QStringLiteral("actionRefreshEtcSchema"));
        actionRefreshEtcSchema->setIcon(icon25);
        actionView_DDL = new QAction(KvMainWindow);
        actionView_DDL->setObjectName(QStringLiteral("actionView_DDL"));
        actionView_DDL->setIcon(icon7);
        actionExport_Data = new QAction(KvMainWindow);
        actionExport_Data->setObjectName(QStringLiteral("actionExport_Data"));
        QIcon icon31;
        icon31.addFile(QStringLiteral(":/png/png_general/table_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_Data->setIcon(icon31);
        actionExport_Database_Objects = new QAction(KvMainWindow);
        actionExport_Database_Objects->setObjectName(QStringLiteral("actionExport_Database_Objects"));
        QIcon icon32;
        icon32.addFile(QStringLiteral(":/png/png_general/cog_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_Database_Objects->setIcon(icon32);
        actionRefresh_Schemas = new QAction(KvMainWindow);
        actionRefresh_Schemas->setObjectName(QStringLiteral("actionRefresh_Schemas"));
        actionRefresh_Schemas->setIcon(icon25);
        actionKevora_Updates = new QAction(KvMainWindow);
        actionKevora_Updates->setObjectName(QStringLiteral("actionKevora_Updates"));
        QIcon icon33;
        icon33.addFile(QStringLiteral(":/png/png_general/arrow_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKevora_Updates->setIcon(icon33);
        actionCompare_Database_objects = new QAction(KvMainWindow);
        actionCompare_Database_objects->setObjectName(QStringLiteral("actionCompare_Database_objects"));
        QIcon icon34;
        icon34.addFile(QStringLiteral(":/png/png_general/table_relationship.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompare_Database_objects->setIcon(icon34);
        centralWidget = new QWidget(KvMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mdiArea = new KvMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setAcceptDrops(true);
        mdiArea->setStyleSheet(QStringLiteral(""));
        mdiArea->setProperty("documentMode", QVariant(true));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        KvMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KvMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 22));
        menuIDE = new QMenu(menuBar);
        menuIDE->setObjectName(QStringLiteral("menuIDE"));
        menu_Connection = new QMenu(menuBar);
        menu_Connection->setObjectName(QStringLiteral("menu_Connection"));
        menu_Files = new QMenu(menuBar);
        menu_Files->setObjectName(QStringLiteral("menu_Files"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_Tools = new QMenu(menuBar);
        menu_Tools->setObjectName(QStringLiteral("menu_Tools"));
        menu_Reports = new QMenu(menuBar);
        menu_Reports->setObjectName(QStringLiteral("menu_Reports"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        KvMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KvMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KvMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KvMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KvMainWindow->setStatusBar(statusBar);
        navigatorDockWidget = new QDockWidget(KvMainWindow);
        navigatorDockWidget->setObjectName(QStringLiteral("navigatorDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 4, 2, 6);
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 4, 4, 6);
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 25));
        frame->setMaximumSize(QSize(16777215, 25));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButtonAddDb = new QToolButton(frame);
        toolButtonAddDb->setObjectName(QStringLiteral("toolButtonAddDb"));
        toolButtonAddDb->setMaximumSize(QSize(25, 25));
        toolButtonAddDb->setIcon(icon3);

        horizontalLayout->addWidget(toolButtonAddDb);

        toolButtonDelDb = new QToolButton(frame);
        toolButtonDelDb->setObjectName(QStringLiteral("toolButtonDelDb"));
        toolButtonDelDb->setMaximumSize(QSize(25, 25));
        toolButtonDelDb->setIcon(icon4);

        horizontalLayout->addWidget(toolButtonDelDb);

        toolButtonEdit = new QToolButton(frame);
        toolButtonEdit->setObjectName(QStringLiteral("toolButtonEdit"));
        toolButtonEdit->setMaximumSize(QSize(25, 25));
        toolButtonEdit->setIcon(icon7);

        horizontalLayout->addWidget(toolButtonEdit);

        toolButtonAddConn = new QToolButton(frame);
        toolButtonAddConn->setObjectName(QStringLiteral("toolButtonAddConn"));
        toolButtonAddConn->setMaximumSize(QSize(25, 25));
        toolButtonAddConn->setIcon(icon5);

        horizontalLayout->addWidget(toolButtonAddConn);

        toolButtonDelConn = new QToolButton(frame);
        toolButtonDelConn->setObjectName(QStringLiteral("toolButtonDelConn"));
        toolButtonDelConn->setMaximumSize(QSize(25, 25));
        toolButtonDelConn->setIcon(icon6);

        horizontalLayout->addWidget(toolButtonDelConn);

        toolButtonOpenConn = new QToolButton(frame);
        toolButtonOpenConn->setObjectName(QStringLiteral("toolButtonOpenConn"));
        toolButtonOpenConn->setMaximumSize(QSize(25, 25));
        toolButtonOpenConn->setIcon(icon8);

        horizontalLayout->addWidget(toolButtonOpenConn);

        toolButtonCloseConn = new QToolButton(frame);
        toolButtonCloseConn->setObjectName(QStringLiteral("toolButtonCloseConn"));
        toolButtonCloseConn->setMaximumSize(QSize(25, 25));
        toolButtonCloseConn->setIcon(icon9);

        horizontalLayout->addWidget(toolButtonCloseConn);

        toolButtonCloseAllConn = new QToolButton(frame);
        toolButtonCloseAllConn->setObjectName(QStringLiteral("toolButtonCloseAllConn"));
        toolButtonCloseAllConn->setMaximumSize(QSize(25, 25));
        toolButtonCloseAllConn->setIcon(icon30);

        horizontalLayout->addWidget(toolButtonCloseAllConn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(frame);

        dbTreeWidget = new KvTreeWidget(tab);
        dbTreeWidget->setObjectName(QStringLiteral("dbTreeWidget"));
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
        objectsDockWidget->setObjectName(QStringLiteral("objectsDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 4, 2, 0);
        activeConnObjComboBox = new QComboBox(dockWidgetContents_2);
        activeConnObjComboBox->setObjectName(QStringLiteral("activeConnObjComboBox"));

        verticalLayout->addWidget(activeConnObjComboBox);

        tabWidget_2 = new QTabWidget(dockWidgetContents_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(4, 4, 4, 6);
        tableTreeWidget = new KvTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tableTreeWidget->setHeaderItem(__qtreewidgetitem);
        tableTreeWidget->setObjectName(QStringLiteral("tableTreeWidget"));
        tableTreeWidget->setSortingEnabled(true);
        tableTreeWidget->header()->setVisible(false);

        gridLayout_2->addWidget(tableTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(4, 4, 4, 6);
        viewTreeWidget = new KvTreeWidget(tab_4);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        viewTreeWidget->setHeaderItem(__qtreewidgetitem1);
        viewTreeWidget->setObjectName(QStringLiteral("viewTreeWidget"));
        viewTreeWidget->setSortingEnabled(true);
        viewTreeWidget->header()->setVisible(false);

        gridLayout_3->addWidget(viewTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(4, 4, 4, 6);
        programTreeWidget = new KvTreeWidget(tab_5);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        programTreeWidget->setHeaderItem(__qtreewidgetitem2);
        programTreeWidget->setObjectName(QStringLiteral("programTreeWidget"));
        programTreeWidget->setSortingEnabled(true);
        programTreeWidget->header()->setVisible(false);

        gridLayout_4->addWidget(programTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_5 = new QGridLayout(tab_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(4, 4, 4, 6);
        etcTreeWidget = new KvTreeWidget(tab_6);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setText(0, QStringLiteral("1"));
        etcTreeWidget->setHeaderItem(__qtreewidgetitem3);
        etcTreeWidget->setObjectName(QStringLiteral("etcTreeWidget"));
        etcTreeWidget->setSortingEnabled(true);
        etcTreeWidget->header()->setVisible(false);

        gridLayout_5->addWidget(etcTreeWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget_2);

        objectsDockWidget->setWidget(dockWidgetContents_2);
        KvMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), objectsDockWidget);
        winListDockWidget = new QDockWidget(KvMainWindow);
        winListDockWidget->setObjectName(QStringLiteral("winListDockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 4, 2, 0);
        listWidgetWindows = new QListWidget(dockWidgetContents_3);
        listWidgetWindows->setObjectName(QStringLiteral("listWidgetWindows"));
        listWidgetWindows->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout_5->addWidget(listWidgetWindows);

        winListDockWidget->setWidget(dockWidgetContents_3);
        KvMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), winListDockWidget);
        workingDirDockWidget = new QDockWidget(KvMainWindow);
        workingDirDockWidget->setObjectName(QStringLiteral("workingDirDockWidget"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 4, 2, 0);
        fileTreeView = new QTreeView(dockWidgetContents_4);
        fileTreeView->setObjectName(QStringLiteral("fileTreeView"));
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
        KvMainWindow->setWindowTitle(QApplication::translate("KvMainWindow", "Kevora", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        KvMainWindow->setWhatsThis(QApplication::translate("KvMainWindow", "The IDE of your dreams!", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        actionPreferences->setText(QApplication::translate("KvMainWindow", "Settings", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPreferences->setToolTip(QApplication::translate("KvMainWindow", "Settings", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("KvMainWindow", "Exit", Q_NULLPTR));
        actionAdd_Database->setText(QApplication::translate("KvMainWindow", "Add Database", Q_NULLPTR));
        actionDelete_Database->setText(QApplication::translate("KvMainWindow", "Delete Database", Q_NULLPTR));
        actionAdd_Connection->setText(QApplication::translate("KvMainWindow", "Add Connection", Q_NULLPTR));
        actionDelete_Connection->setText(QApplication::translate("KvMainWindow", "Delete Connection", Q_NULLPTR));
        actionEdit->setText(QApplication::translate("KvMainWindow", "Edit", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("KvMainWindow", "Connect", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("KvMainWindow", "Disconnect", Q_NULLPTR));
        actionConnectivity_Assistant->setText(QApplication::translate("KvMainWindow", "Connectivity Assistant", Q_NULLPTR));
        actionNew_Sql->setText(QApplication::translate("KvMainWindow", "New Sql Window", Q_NULLPTR));
        actionNew_Diagram->setText(QApplication::translate("KvMainWindow", "New Diagram Window", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("KvMainWindow", "Open File", Q_NULLPTR));
        actionOpen_Recent->setText(QApplication::translate("KvMainWindow", "Open Recent...", Q_NULLPTR));
        actionSave->setText(QApplication::translate("KvMainWindow", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("KvMainWindow", "Save As...", Q_NULLPTR));
        actionSave_All->setText(QApplication::translate("KvMainWindow", "Save All", Q_NULLPTR));
        actionClose->setText(QApplication::translate("KvMainWindow", "Close", Q_NULLPTR));
        actionCut->setText(QApplication::translate("KvMainWindow", "Cut", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("KvMainWindow", "Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("KvMainWindow", "Paste", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("KvMainWindow", "Delete", Q_NULLPTR));
        actionSelect_All->setText(QApplication::translate("KvMainWindow", "Select All", Q_NULLPTR));
        actionContents->setText(QApplication::translate("KvMainWindow", "Contents", Q_NULLPTR));
        actionAbout_Kevora->setText(QApplication::translate("KvMainWindow", "About Kevora", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("KvMainWindow", "About Qt", Q_NULLPTR));
        actionRefreshTableSchema->setText(QApplication::translate("KvMainWindow", "Refresh", Q_NULLPTR));
        actionView_TableDefinition->setText(QApplication::translate("KvMainWindow", "View Definition", Q_NULLPTR));
        actionView_TableData->setText(QApplication::translate("KvMainWindow", "View Data", Q_NULLPTR));
        actionCascade_Windows->setText(QApplication::translate("KvMainWindow", "Cascade Windows", Q_NULLPTR));
        actionTile_Windows->setText(QApplication::translate("KvMainWindow", "Tile Windows", Q_NULLPTR));
        actionClose_All_Windows->setText(QApplication::translate("KvMainWindow", "Close All Windows", Q_NULLPTR));
        actionNavigator->setText(QApplication::translate("KvMainWindow", "Navigator", Q_NULLPTR));
        actionObjects->setText(QApplication::translate("KvMainWindow", "Objects", Q_NULLPTR));
        actionWindow_List->setText(QApplication::translate("KvMainWindow", "Window List", Q_NULLPTR));
        actionWork_Path->setText(QApplication::translate("KvMainWindow", "Work Path", Q_NULLPTR));
        actionMain_Tool_Bar->setText(QApplication::translate("KvMainWindow", "Main Tool Bar", Q_NULLPTR));
        actionDisconnectAll->setText(QApplication::translate("KvMainWindow", "Disconnect All", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDisconnectAll->setToolTip(QApplication::translate("KvMainWindow", "Disconnect All", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionView_ViewData->setText(QApplication::translate("KvMainWindow", "View Data", Q_NULLPTR));
        actionView_ViewDefinition->setText(QApplication::translate("KvMainWindow", "View Definition", Q_NULLPTR));
        actionRefreshViewSchema->setText(QApplication::translate("KvMainWindow", "Refresh", Q_NULLPTR));
        actionRefreshProgramSchema->setText(QApplication::translate("KvMainWindow", "Refresh", Q_NULLPTR));
        actionRefreshEtcSchema->setText(QApplication::translate("KvMainWindow", "Refresh", Q_NULLPTR));
        actionView_DDL->setText(QApplication::translate("KvMainWindow", "View DDL", Q_NULLPTR));
        actionExport_Data->setText(QApplication::translate("KvMainWindow", "Export Data", Q_NULLPTR));
        actionExport_Database_Objects->setText(QApplication::translate("KvMainWindow", "Export Database Objects", Q_NULLPTR));
        actionRefresh_Schemas->setText(QApplication::translate("KvMainWindow", "Refresh", Q_NULLPTR));
        actionKevora_Updates->setText(QApplication::translate("KvMainWindow", "Kevora Updates", Q_NULLPTR));
        actionCompare_Database_objects->setText(QApplication::translate("KvMainWindow", "Compare Database Objects", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionCompare_Database_objects->setToolTip(QApplication::translate("KvMainWindow", "Compare Database Objects", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        menuIDE->setTitle(QApplication::translate("KvMainWindow", "&IDE", Q_NULLPTR));
        menu_Connection->setTitle(QApplication::translate("KvMainWindow", "&Connections", Q_NULLPTR));
        menu_Files->setTitle(QApplication::translate("KvMainWindow", "&Files", Q_NULLPTR));
        menu_Edit->setTitle(QApplication::translate("KvMainWindow", "&Edit", Q_NULLPTR));
        menu_Tools->setTitle(QApplication::translate("KvMainWindow", "&Tools", Q_NULLPTR));
        menu_Reports->setTitle(QApplication::translate("KvMainWindow", "&Reports", Q_NULLPTR));
        menu_Help->setTitle(QApplication::translate("KvMainWindow", "&Help", Q_NULLPTR));
        menu_View->setTitle(QApplication::translate("KvMainWindow", "&View", Q_NULLPTR));
        mainToolBar->setWindowTitle(QApplication::translate("KvMainWindow", "Main Tool Bar", Q_NULLPTR));
        navigatorDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Navigator", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonAddDb->setToolTip(QApplication::translate("KvMainWindow", "Add a database item", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonAddDb->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonDelDb->setToolTip(QApplication::translate("KvMainWindow", "Remove a database item", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonDelDb->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonEdit->setToolTip(QApplication::translate("KvMainWindow", "Edit a database or connection item", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonEdit->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonAddConn->setToolTip(QApplication::translate("KvMainWindow", "Add a connection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonAddConn->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonDelConn->setToolTip(QApplication::translate("KvMainWindow", "Remove a connection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonDelConn->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonOpenConn->setToolTip(QApplication::translate("KvMainWindow", "Open a connection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonOpenConn->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonCloseConn->setToolTip(QApplication::translate("KvMainWindow", "Close a connection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonCloseConn->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonCloseAllConn->setToolTip(QApplication::translate("KvMainWindow", "Close all connections", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonCloseAllConn->setText(QApplication::translate("KvMainWindow", "...", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = dbTreeWidget->headerItem();
        ___qtreewidgetitem->setText(7, QApplication::translate("KvMainWindow", "Status", Q_NULLPTR));
        ___qtreewidgetitem->setText(6, QApplication::translate("KvMainWindow", "Comments", Q_NULLPTR));
        ___qtreewidgetitem->setText(5, QApplication::translate("KvMainWindow", "Driver", Q_NULLPTR));
        ___qtreewidgetitem->setText(4, QApplication::translate("KvMainWindow", "DbName", Q_NULLPTR));
        ___qtreewidgetitem->setText(3, QApplication::translate("KvMainWindow", "Port", Q_NULLPTR));
        ___qtreewidgetitem->setText(2, QApplication::translate("KvMainWindow", "Host", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("KvMainWindow", "Type", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("KvMainWindow", "Connection", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("KvMainWindow", "Connection List", Q_NULLPTR));
        objectsDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Objects", Q_NULLPTR));
        activeConnObjComboBox->clear();
        activeConnObjComboBox->insertItems(0, QStringList()
         << QApplication::translate("KvMainWindow", "Objects from All Active Connections", Q_NULLPTR)
        );
        QTreeWidgetItem *___qtreewidgetitem1 = tableTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("KvMainWindow", "2", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("KvMainWindow", "Tables", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = viewTreeWidget->headerItem();
        ___qtreewidgetitem2->setText(1, QApplication::translate("KvMainWindow", "2", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("KvMainWindow", "Views", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = programTreeWidget->headerItem();
        ___qtreewidgetitem3->setText(1, QApplication::translate("KvMainWindow", "2", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("KvMainWindow", "Programs", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = etcTreeWidget->headerItem();
        ___qtreewidgetitem4->setText(1, QApplication::translate("KvMainWindow", "2", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("KvMainWindow", "Etc", Q_NULLPTR));
        winListDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Window List", Q_NULLPTR));
        workingDirDockWidget->setWindowTitle(QApplication::translate("KvMainWindow", "Work Path", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KvMainWindow: public Ui_KvMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVMAINWINDOW_H
