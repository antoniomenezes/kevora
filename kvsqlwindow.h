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

#ifndef KVSQLWINDOW_H
#define KVSQLWINDOW_H

#include <QDialog>
#include <QSyntaxHighlighter>
#include <QMap>
#include <QFontMetrics>
#include <QWidget>
#include <QTimer>
//#include <QtConcurrentRun>
#include <QFuture>
#include <QPlainTextEdit>
#include <QTextCursor>
#include <QFile>
#include <QFuture>
#include <qtconcurrentrun.h>
#include "kvsqldialog.h"
#include "kvdbutil.h"
#include "kvsqldata.h"
#include "kvoraclehighlighter.h"
#include "kvsqlhighlighter.h"
#include "kvtnshighlighter.h"

namespace Ui {
    class KvSqlWindow;
}

class KvSqlWindow : public KvSqlDialog {
    Q_OBJECT
public:
    explicit KvSqlWindow(QWidget *parent = 0);
    ~KvSqlWindow();

public slots:
    void setActiveSessions(QStringList sessions);
    void addActiveSession(QString session);
    void removeActiveSession(QString session);
    void clonedSessionSlot(WId windowId, QString sessionName, QString driver, QString hostName, int port, QString databaseName, QString userName, QString password);
    void openedDbConnectionSlot(QString connectionName, QString connUser, QString connDb, QSqlError error);
    void setHighLighter(KvDbUtil::DbmsHighlightTypes h);
    void executedQuerySlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, QString sqlStatementId = "default");
    void gotSqlBlocksSlot(QStringList sqlBlocks, int fromPosition, int toPosition);
    void gotNextRecordsSlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, bool allRecords = false, QString sqlStatementId = "default");
    void updateRecordCount(int partNumber, int totalNumber);
    QString getPreparedSqlStatement();
    void updateRecordViewHeaders();
    void updateRecordView();
    void setCancelAllRecords(QString sqlId, bool value);
    void setComboSessionName(QString sessionName);
    void setSqlStatement(QString sqlStatement);
    void runSqlStatement(QString sqlStatement);
    void setDdlInfo(QString schemaName, QString objectName, QString objectType, bool showSchema = true);
    void setExportDataInfo(QString schemaName, QString tableName, bool showSchema = true);
    void getDdlFromObjectSlot(QString schema, QString objectName, QString objectType, bool showSchema = true, KvSqlSession::DdlTypes ddlType = KvSqlSession::CompleteDdl);
    void gotDdlFromObjectSlot(QString sessionName, QString schema, QString objectName, QString objectType, bool showSchema, QStringList result, KvSqlSession::DdlTypes ddlType);
    void gotDependentSqlSlot(QString sqlStatement, QStringList dependentSqlStatements);
    void gotExtractConsistentDataSqlSlot(QString sqlStatement, QStringList consistentSqlStatements);
    void getPlanSlot(QString sqlStatement, QString sqlStatementId);
    void gotPlanSlot(QString sqlStatement, QString sqlStatementId, QList< QPair<QString, QMap<QString,QString> > > result);
    void getExportedDataSlot(QString schema, QString tableName, bool showSchema, QString sqlStatementId);
    void gotExportedDataSlot(QString sessionName, QString schema, QString tableName, bool showSchema, QString resultLine, bool isTheEnd, QString sqlStatementId);
    void openFile(QString fileName);
    void saveFile();

protected:
    bool isOpening;
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::KvSqlWindow *ui;
    QSyntaxHighlighter *highlighter;
    QMap<QString, KvSqlData*> mapSqlData;
    QString lastSessionName;
    QStringList currentSqlTextLines;
    QLabel *labelRecordCount;
    QLabel *labelEditorCursorPosition;
    QLabel *labelSelection;
    QLabel *labelCurrentRecord;
    QMap<QString, bool> mapCanceledAllRecords;
    QTimer *timer;
    bool eventFilter(QObject *object, QEvent *event);    

private slots:
    //void on_plainTextEditSql_modificationChanged(bool value);    
    void on_actionTimed_Run_triggered();
    void on_actionExplainAll_triggered();
    void on_toolButtonCancelParams_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_tabWidgetData_currentChanged(int index);
    void on_actionCopy_to_Clipboard_triggered();
    void on_actionRun_All_triggered();
    void on_actionRun_Sql_triggered();
    void on_toolButtonZoomOut_clicked();
    void on_toolButtonZoomIn_clicked();
    void on_toolButtonRollback_clicked();
    void on_toolButtonCommit_clicked();
    void on_toolButtonApplyParams_clicked();
    void on_plainTextEditSql_selectionChanged();
    void on_plainTextEditSql_updateRequest(QRect rect, int dy);
    void on_currentSessionComboBox_activated(QString text);
    QStringList getSqlParameters(QString sqlText);
    void updateActiveSessionsCombo();
    QString exportResults(const QString &separator, bool exportHeader = false);
    QString exportRecord(const QString &separator, bool exportHeader = false);
    void runSql(int fromPosition = -1, int toPosition = -1);
    bool isSelectStatement(QString text);
    KvSqlData *newSqlData(QString newSqlId, QString newSqlLabel, QString newSqlText);
    void getNextRecordsSlot(QString sqlId);
    void getAllRecordsSlot(QString sqlId);
    void cancelAllRecordsFetchSlot(QString sqlId);
    void currentRecordChangedSlot(int currentRow, QString sqlId);
    void on_actionGenerate_Cascade_Operations_triggered();
    void on_actionExtract_Consistent_Sql_Data_triggered();

signals:
    void openFileSignal(QString);
};

#endif // KVSQLWINDOW_H
