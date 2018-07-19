#include "kvsqldata.h"
#include "ui_kvsqldata.h"

KvSqlData::KvSqlData(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::KvSqlData)
{
    ui->setupUi(this);
    ui->tableWidgetResults->addAction(ui->actionCopy_to_Clipboard);
    ui->tableWidgetResults->addAction(ui->actionExport_as_Select_Statements_Clipboard);
    ui->tableWidgetRecord->addAction(ui->actionCopy_to_Clipboard);
    ui->treeWidgetPlan->hideColumn(ui->treeWidgetPlan->columnCount() - 1);

}

KvSqlData::~KvSqlData()
{
    while (ui->tableWidgetResults->rowCount() > 0)
        ui->tableWidgetResults->removeRow(0);

    while (ui->tableWidgetRecord->rowCount() > 0)
        ui->tableWidgetRecord->removeRow(0);

    delete ui;
}

void KvSqlData::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void KvSqlData::setSqlStatement(QString id, QString sqlText)
{
    sqlId = id;
    sqlStatement = sqlText;
}

void KvSqlData::setGetNextRecordsEnabled(bool value)
{
    ui->toolButtonGetNextRec->setEnabled(value);
}

void KvSqlData::setGetAllRecordsEnabled(bool value)
{
    ui->toolButtonGetAllRec->setEnabled(value);
}

void KvSqlData::setCancelAllRecordsEnabled(bool value)
{
    ui->toolButtonCancelAllRecords->setEnabled(value);
}

void KvSqlData::setTableWidgetResultsSize(int rows, int columns)
{
    ui->tableWidgetResults->setColumnCount(columns);
    ui->tableWidgetResults->setRowCount(rows);
}

void KvSqlData::setTableWidgetResultsItem(int row, int column, QTableWidgetItem *item)
{
    ui->tableWidgetResults->setItem(row, column, item);
}

void KvSqlData::setTableWidgetResultsHHeaderItem(int column, QTableWidgetItem *item)
{
    //item->setTextAlignment(Qt::AlignLeft);
    ui->tableWidgetResults->setHorizontalHeaderItem(column, item);    
    ui->tableWidgetResults->horizontalHeaderItem(column)->setTextAlignment(Qt::AlignLeft);
}

QTableWidget * KvSqlData::tableWidgetResults()
{
    return ui->tableWidgetResults;
}

QTableWidget * KvSqlData::tableWidgetRecord()
{
    return ui->tableWidgetRecord;
}

QTreeWidget * KvSqlData::treeWidgetPlan()
{
    return ui->treeWidgetPlan;
}

void KvSqlData::updateRecordViewHeaders()
{
    ui->tableWidgetRecord->clear();
    if (ui->tableWidgetResults->rowCount() > 0) {

        ui->tableWidgetRecord->setRowCount(ui->tableWidgetResults->columnCount());
        ui->tableWidgetRecord->setColumnCount(3);

        QTableWidgetItem *nameHorizontalHeaderItem = new QTableWidgetItem(tr("Column"));
        QTableWidgetItem *valueHorizontalHeaderItem = new QTableWidgetItem(tr("Value"));
        ui->tableWidgetRecord->setHorizontalHeaderItem(0, nameHorizontalHeaderItem);
        ui->tableWidgetRecord->setHorizontalHeaderItem(1, valueHorizontalHeaderItem);
        ui->tableWidgetRecord->setHorizontalHeaderItem(2, new QTableWidgetItem(""));
        ui->tableWidgetRecord->setColumnWidth(2, 1);
    }
}

void KvSqlData::updateRecordView()
{
    while (ui->tableWidgetRecord->rowCount() > 0)
        ui->tableWidgetRecord->removeRow(0);
    ui->tableWidgetRecord->clearContents();
    if (ui->tableWidgetResults->rowCount() > 0) {
        ui->tableWidgetRecord->setRowCount(ui->tableWidgetResults->columnCount());
        for (int col = 0; col < ui->tableWidgetResults->columnCount(); col++) {
            QTableWidgetItem *verticalHeaderItem = new QTableWidgetItem;
            verticalHeaderItem->setText(ui->tableWidgetResults->horizontalHeaderItem(col)->text());
            //ui->tableWidgetRecord->setItem(col, verticalHeaderItem);

            QTableWidgetItem *item = new QTableWidgetItem;
            // Select all items of row to avoid null pointer exception on line "item->setData"...
            ui->tableWidgetResults->selectRow( ui->tableWidgetResults->selectedItems().at(0)->row() );
            item->setData(Qt::DisplayRole, ui->tableWidgetResults->selectedItems().at(col)->data(Qt::DisplayRole));
            ui->tableWidgetRecord->setItem(col, 0, verticalHeaderItem);
            ui->tableWidgetRecord->setItem(col, 1, item);
        }
        ui->tableWidgetRecord->resizeColumnsToContents();
        //ui->tableWidgetRecord->setColumnWidth(0, ui->tableWidgetRecord->width() - (ui->tableWidgetRecord->verticalHeader()->width()));
        ui->tableWidgetRecord->setColumnWidth(2, 1);
        ui->tableWidgetRecord->resizeRowsToContents();
    }
}

bool KvSqlData::isRecordViewVisible()
{
    return (ui->stackedWidgetData->currentIndex() == 1);
}

void KvSqlData::on_toolButtonResultZoomIn_clicked()
{
    QFont sqlTextFont = ui->tableWidgetResults->font();
    sqlTextFont.setPointSize(sqlTextFont.pointSize() + 1);
    ui->tableWidgetResults->setFont(sqlTextFont);
    ui->tableWidgetResults->horizontalHeader()->setFont(sqlTextFont);
    ui->tableWidgetResults->verticalHeader()->setFont(sqlTextFont);
    ui->tableWidgetResults->resizeColumnsToContents();
    ui->tableWidgetResults->resizeRowsToContents();
}

void KvSqlData::on_toolButtonResultZoomOut_clicked()
{
    if (ui->tableWidgetResults->font().pointSize() >= 7) {
        QFont sqlTextFont = ui->tableWidgetResults->font();
        sqlTextFont.setPointSize(sqlTextFont.pointSize() - 1);
        ui->tableWidgetResults->setFont(sqlTextFont);
        ui->tableWidgetResults->horizontalHeader()->setFont(sqlTextFont);
        ui->tableWidgetResults->verticalHeader()->setFont(sqlTextFont);
        ui->tableWidgetResults->resizeColumnsToContents();
        ui->tableWidgetResults->resizeRowsToContents();
    }
}

void KvSqlData::on_toolButtonRecView_clicked()
{
    ui->stackedWidgetData->setCurrentIndex(1);
    updateRecordViewHeaders();
    updateRecordView();
}

void KvSqlData::on_toolButtonGridView_clicked()
{
    ui->stackedWidgetData->setCurrentIndex(0);
}

void KvSqlData::on_toolButtonRecZoomIn_clicked()
{
    QFont sqlTextFont = ui->tableWidgetRecord->font();
    sqlTextFont.setPointSize(sqlTextFont.pointSize() + 1);
    ui->tableWidgetRecord->setFont(sqlTextFont);
    ui->tableWidgetRecord->horizontalHeader()->setFont(sqlTextFont);
    ui->tableWidgetRecord->verticalHeader()->setFont(sqlTextFont);
    //ui->tableWidgetRecord->resizeColumnsToContents();
    //ui->tableWidgetRecord->setColumnWidth(0, ui->tableWidgetRecord->width() - (2*ui->tableWidgetRecord->verticalHeader()->width()));
    ui->tableWidgetRecord->resizeColumnsToContents();
    ui->tableWidgetRecord->setColumnWidth(2, 1);
    ui->tableWidgetRecord->resizeRowsToContents();
}

void KvSqlData::on_toolButtonRecZoomOut_clicked()
{
    if (ui->tableWidgetRecord->font().pointSize() >= 7) {
        QFont sqlTextFont = ui->tableWidgetRecord->font();
        sqlTextFont.setPointSize(sqlTextFont.pointSize() - 1);
        ui->tableWidgetRecord->setFont(sqlTextFont);
        ui->tableWidgetRecord->horizontalHeader()->setFont(sqlTextFont);
        ui->tableWidgetRecord->verticalHeader()->setFont(sqlTextFont);
        //ui->tableWidgetRecord->resizeColumnsToContents();
        //ui->tableWidgetRecord->setColumnWidth(0, ui->tableWidgetRecord->width() - (2*ui->tableWidgetRecord->verticalHeader()->width()));
        ui->tableWidgetRecord->resizeColumnsToContents();
        ui->tableWidgetRecord->setColumnWidth(2, 1);
        ui->tableWidgetRecord->resizeRowsToContents();
    }
}

void KvSqlData::on_toolButtonGetNextRec_clicked()
{
    emit getNextRecordsSignal(sqlId);
}

void KvSqlData::on_toolButtonGetAllRec_clicked()
{
    emit getAllRecordsSignal(sqlId);
    ui->toolButtonCancelAllRecords->setEnabled(true);
}

void KvSqlData::on_toolButtonCancelAllRecords_clicked()
{
    emit cancelAllRecordsFetchSignal(sqlId);
    ui->toolButtonCancelAllRecords->setEnabled(false);
}

QString KvSqlData::getRecordCountStatus() {
    QString recordSuffixText;
    if (totalSelectCount > 1)
        recordSuffixText = tr("records");
    else
        recordSuffixText = tr("record");

    return tr("Retrieved")+" "+QString::number(partialSelectCount)+" "+tr("of")+" "+QString::number(totalSelectCount)+" "+recordSuffixText;
}

void KvSqlData::updateRecordCount(int partialNumber, int totalNumber)
{
    partialSelectCount = partialNumber;
    totalSelectCount = totalNumber;
}

void KvSqlData::on_tableWidgetResults_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    emit currentRecordChangedSignal(currentRow, sqlId);
}

QString KvSqlData::getSqlStatement()
{
    return sqlStatement;
}

void KvSqlData::on_toolButtonFirstRec_clicked()
{
    ui->tableWidgetResults->selectRow(0);
    updateRecordView();
}

void KvSqlData::on_toolButtonPrevRec_clicked()
{
    ui->tableWidgetResults->selectRow(ui->tableWidgetResults->selectedItems().at(0)->row()-1);
    updateRecordView();
}

void KvSqlData::on_toolButtonNextRec_clicked()
{
    ui->tableWidgetResults->selectRow(ui->tableWidgetResults->selectedItems().at(0)->row()+1);
    updateRecordView();
}

void KvSqlData::on_toolButtonLastRec_clicked()
{
    ui->tableWidgetResults->selectRow(ui->tableWidgetResults->rowCount()-1);
    updateRecordView();
}

// Export data from Results Grid
QString KvSqlData::exportResults(const QString &separator, bool exportHeader) {
    KvSqlData *current = this;
    QString str;
    if (current->tableWidgetResults()->selectionModel()->selectedIndexes().count() > 0) {
        int minColumn = -1;
        int maxColumn = -1;
        int minRow = -1;
        int maxRow = -1;
        QModelIndexList selectionList = current->tableWidgetResults()->selectionModel()->selectedIndexes();
        if (selectionList.size() > 0) {
            for (int k=0; k<selectionList.size(); ++k) {
                if ((minColumn >= selectionList[k].column()) || (minColumn == -1))
                    minColumn =  selectionList[k].column();
                if ((maxColumn <= selectionList[k].column()) || (maxColumn == -1))
                    maxColumn = selectionList[k].column();
                if ((minRow >= selectionList[k].row()) || (minRow == -1))
                    minRow = selectionList[k].row();
                if ((maxRow <= selectionList[k].row()) || (maxRow == -1))
                    maxRow = selectionList[k].row();
            }
        }
        QString tableColumns[(maxColumn-minColumn)+1];
        QString tableItems[(maxColumn-minColumn)+1][(maxRow-minRow)+1];

        if (selectionList.size() > 0) {
            for (int i=0; i<selectionList.size(); ++i) {
                if (exportHeader)
                    tableColumns[selectionList[i].column()-minColumn] = current->tableWidgetResults()->model()->headerData(selectionList[i].column(), Qt::Horizontal).toString();
                tableItems[selectionList[i].column()-minColumn][selectionList[i].row()-minRow] = current->tableWidgetResults()->selectionModel()->model()->index(selectionList[i].row(),selectionList[i].column(),QModelIndex()).data().toString();
            }
            if (exportHeader) {
                for (int j=0; j<=maxColumn-minColumn; ++j) {
                    str+=tableColumns[j];
                    if (selectionList.size() > 1)
                        str+=separator;
                }
                if (selectionList.size() > 1)
                    str=str.left(str.length()-separator.length());
                str+="\n";
            }
            for (int l=0; l<=maxRow-minRow; ++l) {
                for (int c=0; c<=maxColumn-minColumn; ++c) {
                    str+=tableItems[c][l];
                    if (selectionList.size() > 1)
                        str+=separator;
                }
                if (selectionList.size() > 1) {
                    str=str.left(str.length()-separator.length());
                    str+="\n";
                }
            }
        }
    }
    return str;
}

// Export data from Record Grid
QString KvSqlData::exportRecord(const QString &separator, bool exportHeader) {
    KvSqlData *current = this;
    QString str;
    if (current->tableWidgetRecord()->selectionModel()->selectedIndexes().count() > 0) {
        int minColumn = -1;
        int maxColumn = -1;
        int minRow = -1;
        int maxRow = -1;
        QModelIndexList selectionList = current->tableWidgetRecord()->selectionModel()->selectedIndexes();
        if (selectionList.size() > 0) {
            for (int k=0; k<selectionList.size(); ++k) {
                if ((minColumn >= selectionList[k].column()) || (minColumn == -1))
                    minColumn =  selectionList[k].column();
                if ((maxColumn <= selectionList[k].column()) || (maxColumn == -1))
                    maxColumn = selectionList[k].column();
                if ((minRow >= selectionList[k].row()) || (minRow == -1))
                    minRow = selectionList[k].row();
                if ((maxRow <= selectionList[k].row()) || (maxRow == -1))
                    maxRow = selectionList[k].row();
            }
        }
        QString tableColumns[(maxColumn-minColumn)+1];
        QString tableItems[(maxColumn-minColumn)+1][(maxRow-minRow)+1];

        if (selectionList.size() > 0) {
            for (int i=0; i<selectionList.size(); ++i) {
                if (exportHeader)
                    tableColumns[selectionList[i].column()-minColumn] = current->tableWidgetRecord()->model()->headerData(selectionList[i].column(), Qt::Horizontal).toString();
                tableItems[selectionList[i].column()-minColumn][selectionList[i].row()-minRow] = current->tableWidgetRecord()->selectionModel()->model()->index(selectionList[i].row(),selectionList[i].column(),QModelIndex()).data().toString();
            }
            if (exportHeader) {
                for (int j=0; j<=maxColumn-minColumn; ++j) {
                    str+=tableColumns[j];
                    str+=separator;
                }
                str=str.left(str.length()-separator.length());
                str+="\n";
            }
            for (int l=0; l<=maxRow-minRow; ++l) {
                for (int c=0; c<=maxColumn-minColumn; ++c) {
                    str+=tableItems[c][l];
                    str+=separator;
                }
                str=str.left(str.length()-separator.length());
                str+="\n";
            }
        }
    }
    return str;
}

QStringList KvSqlData::exportResultsAsSql() {
    QStringList result;
    QString insertColumns;
    QString insertValues;
    KvSqlData *current = this;

    QString resultTableName = sqlStatement.mid(sqlStatement.indexOf("FROM", 0, Qt::CaseInsensitive)+4, sqlStatement.length() - sqlStatement.indexOf("FROM", 0, Qt::CaseInsensitive)).trimmed();
    resultTableName = resultTableName.split(" ", QString::SkipEmptyParts).at(0);

    QString str;
    if (current->tableWidgetResults()->selectionModel()->selectedIndexes().count() > 0) {
        int minColumn = -1;
        int maxColumn = -1;
        int minRow = -1;
        int maxRow = -1;
        QModelIndexList selectionList = current->tableWidgetResults()->selectionModel()->selectedIndexes();
        if (selectionList.size() > 0) {
            for (int k=0; k<selectionList.size(); ++k) {
                if ((minColumn >= selectionList[k].column()) || (minColumn == -1))
                    minColumn =  selectionList[k].column();
                if ((maxColumn <= selectionList[k].column()) || (maxColumn == -1))
                    maxColumn = selectionList[k].column();
                if ((minRow >= selectionList[k].row()) || (minRow == -1))
                    minRow = selectionList[k].row();
                if ((maxRow <= selectionList[k].row()) || (maxRow == -1))
                    maxRow = selectionList[k].row();
            }
        }
        QString tableColumns[(maxColumn-minColumn)+1];
        QString tableItems[(maxColumn-minColumn)+1][(maxRow-minRow)+1];

        if (selectionList.size() > 0) {
            for (int i=0; i<selectionList.size(); ++i) {
                tableColumns[selectionList[i].column()-minColumn] = current->tableWidgetResults()->model()->headerData(selectionList[i].column(), Qt::Horizontal).toString();
                QVariant::Type type = current->tableWidgetResults()->selectionModel()->model()->index(selectionList[i].row(),selectionList[i].column(),QModelIndex()).data().type();
                if (type == QVariant::String)
                    tableItems[selectionList[i].column()-minColumn][selectionList[i].row()-minRow] = "'"+current->tableWidgetResults()->selectionModel()->model()->index(selectionList[i].row(),selectionList[i].column(),QModelIndex()).data().toString()+"'";
                else if (type == QVariant::DateTime) {
                    QDateTime dateTimeValue = current->tableWidgetResults()->selectionModel()->model()->index(selectionList[i].row(),selectionList[i].column(),QModelIndex()).data().toDateTime();
                    tableItems[selectionList[i].column()-minColumn][selectionList[i].row()-minRow] = "'"+dateTimeValue.toString("dd/MM/yyyy hh:mm:ss")+"'";
                }
                else
                    tableItems[selectionList[i].column()-minColumn][selectionList[i].row()-minRow] = current->tableWidgetResults()->selectionModel()->model()->index(selectionList[i].row(),selectionList[i].column(),QModelIndex()).data().toString();
            }
            for (int j=0; j<=maxColumn-minColumn; ++j) {
                insertColumns+=tableColumns[j]+",";
            }
            // Preparing each insert statement line...
            insertColumns = insertColumns.left(insertColumns.length()-1);
            for (int l=0; l<=maxRow-minRow; ++l) {
                insertValues = "";
                for (int c=0; c<=maxColumn-minColumn; ++c) {
                    insertValues+=tableItems[c][l]+",";
                }
                insertValues = insertValues.left(insertValues.length()-1);
                result << "SELECT "+insertValues+" FROM DUAL UNION ALL";
            }
            QString lastSelect = result.last();
            lastSelect.replace("UNION ALL", ";");
            result.removeLast();
            result << lastSelect;
        }
    }
    return result;
}

void KvSqlData::keyPressEvent(QKeyEvent *event) {
    if ((this->tableWidgetResults()->hasFocus()) && (event->key() == Qt::Key_C) && (event->modifiers() == Qt::ControlModifier)) {
        if (this->tableWidgetResults()->selectionModel()->selectedIndexes().count() > 0) {
            QString str = exportResults("\t");
            QApplication::clipboard()->setText(str);
        }

    }
    else if ((this->tableWidgetRecord()->hasFocus()) && (event->key() == Qt::Key_C) && (event->modifiers() == Qt::ControlModifier)) {
        if (this->tableWidgetRecord()->selectionModel()->selectedIndexes().count() > 0) {
            QString str = exportRecord("\t");
            QApplication::clipboard()->setText(str);
        }
    }
}

void KvSqlData::on_actionCopy_to_Clipboard_triggered()
{
    if (ui->tableWidgetResults->hasFocus()) {
        if (ui->tableWidgetResults->selectionModel()->selectedIndexes().count() > 0) {
            QString str = exportResults("\t", true);
            QApplication::clipboard()->setText(str);
        }

    }
    else if (ui->tableWidgetRecord->hasFocus()) {
        if (ui->tableWidgetRecord->selectionModel()->selectedIndexes().count() > 0) {
            QString str = exportRecord("\t");
            QApplication::clipboard()->setText(str);
        }
    }
}

void KvSqlData::on_actionExport_as_Select_Statements_Clipboard_triggered()
{
    QString longText;
    foreach(QString text, exportResultsAsSql())
        longText += text + "\n";
    QApplication::clipboard()->setText(longText);
}

void KvSqlData::setCurrentStackedWidget(int index)
{
    ui->stackedWidgetData->setCurrentIndex(index);
}

void KvSqlData::enableShortCuts(bool enabled)
{
    if (enabled) {
        ui->toolButtonResultZoomIn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus));
        ui->toolButtonResultZoomOut->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus));
        ui->toolButtonRecZoomIn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus));
        ui->toolButtonRecZoomOut->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus));
        ui->toolButtonPlanZoomIn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus));
        ui->toolButtonPlanZoomOut->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus));
    }
    else {
        ui->toolButtonResultZoomIn->setShortcut(QKeySequence());
        ui->toolButtonResultZoomOut->setShortcut(QKeySequence());
        ui->toolButtonRecZoomIn->setShortcut(QKeySequence());
        ui->toolButtonRecZoomOut->setShortcut(QKeySequence());
        ui->toolButtonPlanZoomIn->setShortcut(QKeySequence());
        ui->toolButtonPlanZoomOut->setShortcut(QKeySequence());
    }
}


