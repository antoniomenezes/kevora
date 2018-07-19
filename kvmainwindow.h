/****************************************************************************
**
** Author: Antonio Marcio A Menezes.
**
** This file is part of the Kevora IDE.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef KVMAINWINDOW_H
#define KVMAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMap>
#include <QSqlError>
#include <QTranslator>
#include <QTabBar>
#include <QMdiArea>
#include <QFileSystemModel>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QMdiSubWindow>
#include "kvaboutwindow.h"
#include "kvsettings.h"
#include "kvtreewidget.h"
#include "kvthread.h"
#include "kvdbutil.h"
#include "kvxml.h"
#include "kvdbdefinitiondialog.h"
#include "kvuserpassdialog.h"
#include "kvsqlwindow.h"
#include "kvexportobjects.h"

namespace Ui
{
    class KvMainWindow;
}

/**
  Kevora Main Window:
  It is a MDI window with docked widgets which acts as panels.
  The subwindows are Sql Windows, Diagram Windows etc.
*/
class KvMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KvMainWindow(QWidget *parent = 0);
    ~KvMainWindow();

public slots:
    bool createDbThread(QString session);
    void startedThreadSlot(QString session);
    void openedDbConnectionSlot(QString connectionName, QString connUser, QString connDb, QSqlError error);
    void closedDbConnectionSlot(QString connectionName);
    void gotSchemasWithTablesSlot(QString sessionName, QString userName, QStringList items);
    void gotSchemasWithViewsSlot(QString sessionName, QString userName, QStringList items);
    void gotSchemasWithProgramsSlot(QString sessionName, QString userName, QStringList items);
    void gotSchemasWithEtcSlot(QString sessionName, QString userName, QStringList items);
    bool isActiveConnection(QString alias, QString userName = QString());
    void execAutoLogon();
    void updateWindowList();
    void exitSlot();

private:
    Ui::KvMainWindow *ui;
    QLinearGradient bgGradient;
    QMap<QString, KvThread*> dbThreadMap;
    QMap<QString, KvThread*> dbThreadMapTemp;
    int windowCounter;
    int getWindowCounter();
    void setupDatabaseTreeActions();
    void setDbConnectionCompleted(QString connectionName, QString userName);
    void updateActiveConnectionObjectsCombo();
    QFileSystemModel *fileModel;
    QString workPath;
    QMap<QMdiSubWindow *, QListWidgetItem *> mdiWindowList;
    KvXml *kevoraXml;

private slots:
    void on_actionOpen_triggered();
    void on_actionRefresh_Schemas_triggered();
    void on_actionExport_Database_Objects_triggered();
    void on_actionExport_Data_triggered();
    void on_actionView_DDL_triggered();
    void on_actionRefreshEtcSchema_triggered();
    void on_actionRefreshProgramSchema_triggered();
    void on_actionRefreshViewSchema_triggered();
    void on_actionRefreshTableSchema_triggered();
    void on_actionView_ViewData_triggered();
    void on_actionView_TableData_triggered();
    void on_actionDisconnectAll_triggered();
    void on_actionMain_Tool_Bar_triggered();
    void on_actionClose_triggered();
    void on_actionClose_All_Windows_triggered();
    void on_actionTile_Windows_triggered();
    void on_actionCascade_Windows_triggered();
    void on_listWidgetWindows_itemSelectionChanged();
    void on_actionNew_Sql_triggered();
    void on_mdiArea_subWindowActivated(QMdiSubWindow *window);
    void on_actionWork_Path_triggered();
    void on_actionWindow_List_triggered();
    void on_actionObjects_triggered();
    void on_actionNavigator_triggered();
    void on_dbTreeWidget_doubleClicked(QModelIndex index);
    void on_actionDelete_Connection_triggered();
    void on_actionAdd_Connection_triggered();
    void on_actionDelete_Database_triggered();
    void on_actionEdit_triggered();
    void on_fileTreeView_expanded(QModelIndex index);
    void on_activeConnObjComboBox_currentIndexChanged(QString text);
    void on_actionPreferences_triggered();
    void on_actionDisconnect_triggered();
    void on_actionConnect_triggered();
    void on_actionAdd_Database_triggered();
    void on_actionAbout_Qt_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_Kevora_triggered();
    void updateViewMenu();
    void closeTab(int i);
    void deleteTempThreadSlot();
    void openFile(QString fileName);
    void saveFile(KvSqlWindow *window, QString fileName);
    KvSqlWindow *newSqlWindow(QString sessionName = "", QString sqlStatement = "", bool toBeExecuted = false, QString windowTitle = "");
    void newDdlWindow(QString sessionName, QString schemaName, QString objectName, QString objectType, bool showSchema = true);
    void newExportDataWindow(QString sessionName, QString schemaName, QString tableName, bool showSchema = true);
    void newExportObjectsWindow();
    void loadXml();
    void saveXml();
    void copyXml();
    bool runKevoraUpdate();
    void on_actionKevora_Updates_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();

    void on_actionCompare_Database_objects_triggered();

signals:
    void openDbConnectionSignal(QString, QString, QString, QString, QString, QString, QString, int);
    void openedDbConnectionSignal(QString connectionName, QString connUser, QString connDb, QSqlError error);
    void closeDbConnectionSignal(QString);
    void closedDbConnectionSignal(QString connectionName);
    void cloneSessionSignal(WId, QString);
    // clonedSession: session, driver, hostname, port, database, username, password
    void clonedSessionSignal(WId, QString, QString, QString, int, QString, QString, QString);
    void getSchemasWithTablesSignal(QString);
    void getSchemasWithViewsSignal(QString);
    void getSchemasWithProgramsSignal(QString);
    void getSchemasWithEtcSignal(QString);
};

#endif // KVMAINWINDOW_H
