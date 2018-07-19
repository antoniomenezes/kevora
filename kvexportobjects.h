#ifndef KVEXPORTOBJECTS_H
#define KVEXPORTOBJECTS_H

#include <QDialog>
#include <QWizard>
#include <QTextDocument>
#include <QPrinter>
#include <QInputDialog>
#include "kvsqlobject.h"
#include "kvsqldialog.h"
#include "kvsolver.h"
#include "kvsettings.h"

namespace Ui {
    class KvExportObjects;
}

class KvExportObjects : public KvSqlDialog
{
    Q_OBJECT

public:
    explicit KvExportObjects(QWidget *parent = 0);
    ~KvExportObjects();
    void setActiveSessions(QStringList sessions);
    void setDataDictionaryOption(bool value);

protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::KvExportObjects *ui;
    KvSolver *solver;
    QString lastSessionName;
    QString searchSqlStatement;
    QStringList databaseTypeNames;
    int totalSelectCount;
    bool cancelAllRecords;
    void setCancelAllRecords(bool value);
    QMap<QString, QStringList> mapExportedTableObjectsDdl;
    QMap<QString, QStringList> mapExportedOtherObjectsDdl;
    QMap<QString, QStringList> mapExportedTablesReferentialDdl;
    QMap<QString, QStringList> mapExportedAllPrivilegesDdl;

    QMap<QString, KvTableInfo> mapExportedTablesInfo;
    QMap<QString, QList<KvColumnInfo> > mapExportedColumnsInfo;
    QMap<QString, QList<KvTableConstraintInfo> > mapExportedConstraintsInfo;

    int ddlSignalsCount;
    int tableColumnsSignalsCount;
    int generatedRows;
    QTextDocument *outputDocument;
    QTextCursor *textCursor;

public slots:
    void gotDatabaseObjectTypesSlot(QStringList objTypeNames, QStringList objTypeOrder);
    void gotTableAndColumnsInfoSlot(QString objSchema, QString objTable, KvTableInfo tableInfo, QList<KvColumnInfo> columns, QList<KvTableConstraintInfo> constraints);

private slots:
    void gotDdlFromObjectSlot(QString sessionName, QString schema, QString objectName, QString objectType, bool showSchema, QStringList result, KvSqlSession::DdlTypes ddlType);
    void saveObjects();
    void exportObjects();
    void enableSearchWidgets(bool value);
    void on_comboBoxOutputChoice_currentIndexChanged(int index);
    void on_actionAdd_All_Objects_to_Selected_triggered();
    void on_actionSet_Default_Only_One_triggered();
    void on_actionExport_Objects_triggered();
    void on_pushButtonCancel_clicked();
    void copySelectedToExportedWidget();
    void on_stackedWidgetExportObj_currentChanged(int index);
    void on_actionClear_Selected_triggered();
    void on_actionRemove_from_Selected_triggered();
    void on_actionAdd_Objects_to_Selected_triggered();
    void on_toolButtonCancelFetchAll_clicked();
    void on_toolButtonAllRecords_clicked();
    void on_toolButtonNextRecords_clicked();
    void on_actionFind_Objects_triggered();
    void on_currentSessionComboBox_activated(QString text);
    void on_pushButtonBack_clicked();
    void on_pushButtonNextFinish_clicked();    
    void addActiveSession(QString session);
    void removeActiveSession(QString session);
    void updateActiveSessionsCombo();
    void setComboSessionName(QString sessionName);
    void gotFindObjectStatementSlot(QString fullObjectName, QString statement);
    void executedQuerySlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, QString sqlStatementId = "default");
    void gotNextRecordsSlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, bool allRecords = false, QString sqlStatementId = "default");
    void updateRecordCount(int partNumber, int totalNumber);
    void updateSelectedCount();
    void generateOutputFileNames(int index);
    void setOutputOptions();
    void on_comboBoxOutputFormat_activated(int index);
};

#endif // KVEXPORTOBJECTS_H
