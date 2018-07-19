#ifndef KVSQLDATA_H
#define KVSQLDATA_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QKeyEvent>
#include <QClipboard>
#include <QDateTime>
#include <QDebug>

namespace Ui {
    class KvSqlData;
}

class KvSqlData : public QWidget {
    Q_OBJECT
public:
    explicit KvSqlData(QWidget *parent = 0);
    ~KvSqlData();
    QTableWidget * tableWidgetResults();
    QTableWidget * tableWidgetRecord();
    QTreeWidget * treeWidgetPlan();
    void setSqlStatement(QString id, QString sqlText);
    void setGetNextRecordsEnabled(bool value);
    void setGetAllRecordsEnabled(bool value);
    void setCancelAllRecordsEnabled(bool value);
    void setTableWidgetResultsSize(int rows, int columns);
    void setTableWidgetResultsItem(int row, int column, QTableWidgetItem *item);
    void setTableWidgetResultsHHeaderItem(int column, QTableWidgetItem *item);
    void updateRecordViewHeaders();
    void updateRecordView();
    bool isRecordViewVisible();
    void updateRecordCount(int partialNumber, int totalNumber);
    QString getRecordCountStatus();
    QString getSqlStatement();
    void setCurrentStackedWidget(int index);
    void enableShortCuts(bool enabled);

protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::KvSqlData *ui;
    QString sqlStatement;
    QString sqlId;
    int totalSelectCount;
    int partialSelectCount;

private slots:
    void on_actionExport_as_Select_Statements_Clipboard_triggered();
    void on_actionCopy_to_Clipboard_triggered();
    void on_toolButtonLastRec_clicked();
    void on_toolButtonNextRec_clicked();
    void on_toolButtonPrevRec_clicked();
    void on_toolButtonFirstRec_clicked();
    void on_tableWidgetResults_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);
    void on_toolButtonCancelAllRecords_clicked();
    void on_toolButtonGetAllRec_clicked();
    void on_toolButtonGetNextRec_clicked();
    void on_toolButtonRecZoomOut_clicked();
    void on_toolButtonRecZoomIn_clicked();
    void on_toolButtonGridView_clicked();
    void on_toolButtonRecView_clicked();
    void on_toolButtonResultZoomOut_clicked();
    void on_toolButtonResultZoomIn_clicked();
    QString exportResults(const QString &separator, bool exportHeader = false);
    QString exportRecord(const QString &separator, bool exportHeader = false);
    QStringList exportResultsAsSql();

signals:
    void getNextRecordsSignal(QString);
    void getAllRecordsSignal(QString);
    void cancelAllRecordsFetchSignal(QString);
    void currentRecordChangedSignal(int, QString);
};

#endif // KVSQLDATA_H
