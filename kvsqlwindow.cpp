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

#include "kvsqlwindow.h"
#include "ui_kvsqlwindow.h"

using namespace QtConcurrent;

KvSqlWindow::KvSqlWindow(QWidget *parent) :
    KvSqlDialog(parent),
    ui(new Ui::KvSqlWindow)
{
    ui->setupUi(this);
    ui->frameParams->hide();
    ui->widgetProgress->hide();
    ui->tabWidgetData->hide();
    highlighter = NULL;
    setHighLighter(KvDbUtil::HtSql92);

    labelCurrentRecord = new QLabel(ui->widgetStatusBar);
    labelCurrentRecord->setAlignment(Qt::AlignLeft);
    labelCurrentRecord->setMinimumWidth(100);
    labelCurrentRecord->setMaximumWidth(200);

    labelRecordCount = new QLabel(ui->widgetStatusBar);
    labelRecordCount->setAlignment(Qt::AlignLeft);
    labelRecordCount->setMinimumWidth(200);
    labelRecordCount->setMaximumWidth(250);
    //labelRecordCount->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    //labelRecordCount->hide();
    labelEditorCursorPosition = new QLabel(ui->widgetStatusBar);
    labelEditorCursorPosition->setMinimumWidth(200);
    labelEditorCursorPosition->setMaximumWidth(200);
    labelEditorCursorPosition->setAlignment(Qt::AlignRight);
    //labelEditorCursorPosition->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    labelSelection = new QLabel(ui->widgetStatusBar);
    //labelSelection->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    labelSelection->setMinimumWidth(200);
    labelSelection->setMaximumWidth(200);
    labelSelection->setAlignment(Qt::AlignCenter);
    //labelSelection->hide();

    ui->widgetStatusBar->addPermanentWidget(labelCurrentRecord);
    ui->widgetStatusBar->addPermanentWidget(labelRecordCount);
    ui->widgetStatusBar->addPermanentWidget(new QLabel(ui->widgetStatusBar), 300);
    ui->widgetStatusBar->addPermanentWidget(labelSelection);
    ui->widgetStatusBar->addPermanentWidget(labelEditorCursorPosition);

    //ui->widgetData->setCancelAllRecordsEnabled(false);

    connect(ui->toolButtonExecSql, SIGNAL(clicked()), ui->actionRun_Sql, SLOT(trigger()));
    connect(ui->toolButtonExecAllSql, SIGNAL(clicked()), ui->actionRun_All, SLOT(trigger()));
    connect(ui->toolButtonExplainPlan, SIGNAL(clicked()), ui->actionExplainAll, SLOT(trigger()));
    connect(ui->toolButtonTimedExec, SIGNAL(toggled(bool)), ui->actionTimed_Run, SLOT(trigger()));

    connect(ui->plainTextEditSql, SIGNAL(openFileSignal(QString)), this, SIGNAL(openFileSignal(QString)));

    //ui->widgetData->tableWidgetResults()->addAction(ui->actionCopy_to_Clipboard);
    //ui->widgetData->tableWidgetRecord()->addAction(ui->actionCopy_to_Clipboard);
    ui->plainTextEditSql->document()->setModified(false);
    setWindowModified(false);

    ui->plainTextEditSql->installEventFilter(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), ui->actionRun_All, SLOT(trigger()));
    isOpening = false;

    KvColorScheme colorScheme = KvSettings::getCurrentColorScheme();
    QColor fgColor = colorScheme.textColors.at(0);
    QColor bgColor = colorScheme.backgroundColors.at(0);
    QString fgStyleSheet = "color: rgba("+QString::number(fgColor.red())+","+QString::number(fgColor.green())+","+QString::number(fgColor.blue())+","+QString::number(fgColor.alpha())+"); ";
    QString bgStyleSheet = "background: rgba("+QString::number(bgColor.red())+","+QString::number(bgColor.green())+","+QString::number(bgColor.blue())+","+QString::number(bgColor.alpha())+"); ";
    ui->plainTextEditSql->setStyleSheet("QPlainTextEdit { "+fgStyleSheet+bgStyleSheet+" }");
    ui->plainTextEditSql->setFont(KvSettings::getEditorFont());

    ui->plainTextEditSql->setAcceptDrops(true);
    currentFileName = QString();
}

KvSqlWindow::~KvSqlWindow()
{
    isClosing = true;

    while(isOpening) {
        qApp->processEvents();
        //qDebug() << "qApp->processEvents() em ~KvSqlWindow()";
    }
    delete labelRecordCount;
    delete ui;
}

qint64 partialRead(QString fileName, QPlainTextEdit *textEdit, int linesToRead, qint64 start = 0)
{
    qint64 result;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  //  | QIODevice::Text))
        return -2;

    QTextStream in(&file);

    if (start != 0)
        in.seek(start);

    int lineNumber = 1;

    while (!in.atEnd() && (lineNumber <= linesToRead)) {
        if (textEdit) {
            QString line = in.readLine();
            textEdit->appendPlainText(line);
            lineNumber++;
        }
    }

    /*while (!file.atEnd() && (lineNumber <= linesToRead)) {
        QByteArray line = file.readLine();
        textEdit->appendPlainText(line);
        lineNumber++;
    }*/
    //qDebug() << file.pos();
    if (in.atEnd())
        result = -1;
    else
        result = in.pos();
    file.close();
    return result;
}

void KvSqlWindow::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QStringList KvSqlWindow::getSqlParameters(QString sqlText)
{
    QStringList paramList;
    if (sqlText.indexOf("&") > -1) {
        QString sqlStatement = sqlText;
        QRegExp rx("\\&[a-z|A-Z][a-z|A-Z|\\_||0-9]*");
        rx.setPatternSyntax(QRegExp::RegExp2);
        int pos = 0;
        while ((pos = rx.indexIn(sqlStatement, pos)) != -1) {
            paramList << rx.cap(0).remove("&", Qt::CaseInsensitive);
            pos += rx.matchedLength();
        }
    }
    return paramList.toSet().toList();
}

void KvSqlWindow::setActiveSessions(QStringList sessions)
{
    KvSqlDialog::setActiveSessions(sessions);
    updateActiveSessionsCombo();
}

void KvSqlWindow::addActiveSession(QString session)
{
    KvSqlDialog::addActiveSession(session);
    updateActiveSessionsCombo();
}

void KvSqlWindow::removeActiveSession(QString session)
{
    KvSqlDialog::removeActiveSession(session);
    updateActiveSessionsCombo();
}

void KvSqlWindow::updateActiveSessionsCombo()
{
    QString currentSession = ui->currentSessionComboBox->currentText();
    QStringList comboSessions = activeSessions;
    comboSessions.sort();
    ui->currentSessionComboBox->clear();
    ui->currentSessionComboBox->addItem("");
    ui->currentSessionComboBox->addItems(comboSessions);
    ui->currentSessionComboBox->setCurrentIndex(ui->currentSessionComboBox->findText(currentSession, Qt::MatchExactly));
    if (ui->currentSessionComboBox->currentText().isEmpty())
        on_currentSessionComboBox_activated(ui->currentSessionComboBox->currentText());
    update();
}

void KvSqlWindow::clonedSessionSlot(WId windowId, QString sessionName, QString driver, QString hostName, int port, QString databaseName, QString userName, QString password)
{
    if (windowId == winId()) {
        KvSqlDialog::clonedSessionSlot(windowId, sessionName, driver, hostName, port, databaseName, userName, password);
    }
}

void KvSqlWindow::openedDbConnectionSlot(QString connectionName, QString connUser, QString connDb, QSqlError error)
{
    ui->widgetProgress->stop();
    ui->widgetProgress->hide();
    KvSqlDialog::openedDbConnectionSlot(connectionName, connUser, connDb, error);
    ui->toolButtonExecSql->setEnabled( ! ui->currentSessionComboBox->currentText().isEmpty() );
    ui->toolButtonExecAllSql->setEnabled( ! ui->currentSessionComboBox->currentText().isEmpty() );
    // The openConnectionAndExecute variable is used when you want to create a new Sql Window and already calling a SQL statement execution
    if (openConnectionAndExecute) {
        ui->toolButtonExecSql->click();
        openConnectionAndExecute = false;
    }
    else if (openConnectionAndExecuteDdl) {
        getDdlFromObjectSlot(ddlSchemaName, ddlObjectName, ddlObjectType, ddlShowSchema, KvSqlSession::CompleteDdl);
    }
    else if (openConnectionAndExportData) {
        getExportedDataSlot(ddlSchemaName, ddlObjectName, ddlShowSchema, QString::number((int)this->winId())+":0");
    }

    if (error.type() == QSqlError::NoError) {
        ui->plainTextEditSql->addAction(ui->actionGenerate_Cascade_Operations);
        ui->plainTextEditSql->addAction(ui->actionExtract_Consistent_Sql_Data);
    }
}

void KvSqlWindow::on_currentSessionComboBox_activated(QString text)
{
    ui->toolButtonExecSql->setEnabled( false );
    ui->toolButtonExecAllSql->setEnabled( false );
    ui->plainTextEditSql->removeAction(ui->actionGenerate_Cascade_Operations);
    setComboSessionName(text);
}

void KvSqlWindow::setHighLighter(KvDbUtil::DbmsHighlightTypes h)
{
    if (highlighter != NULL) {
        QSyntaxHighlighter *lastHighlighter = highlighter;
        highlighter = NULL;
        delete lastHighlighter;
    }
    if (h == KvDbUtil::HtOracle)
        highlighter = new KvOracleHighlighter(ui->plainTextEditSql->document());
    else
        if (h == KvDbUtil::HtTnsNames)
            highlighter = new KvTnsHighlighter(ui->plainTextEditSql->document());
        else
            if (h == KvDbUtil::HtSql92)
                highlighter = new KvSqlHighlighter(ui->plainTextEditSql->document());
            else
                highlighter = new KvSqlHighlighter(ui->plainTextEditSql->document());
}

void KvSqlWindow::executedQuerySlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, QString sqlStatementId)
{
    ui->widgetProgress->hide();
    ui->widgetProgress->stop();
    ui->tabWidgetData->show();
    QCoreApplication::processEvents();

    if (!ui->currentSessionComboBox->currentText().isEmpty()) {
        if (error.type() == QSqlError::NoError) {
            // Clear Previous Error Messages
            // ui->textEditMessages->clear();

            if (isSelectStatement(sqlStatement)) {
                setCancelAllRecords(sqlStatementId, true);
                // Redefine size
                QList<int> sizesV = ui->splitterV->sizes();
                int splitterVHeight = 0;
                foreach(int h, sizesV)
                    splitterVHeight += h;

                QFontMetrics fm(ui->plainTextEditSql->font());
                int textHeightInPixels = fm.height();
                int totalTextHeightInPixels = (ui->plainTextEditSql->document()->lineCount() + 5) * textHeightInPixels;

                if ( totalTextHeightInPixels <= (int) splitterVHeight/2 ) {
                    sizesV.replace(0, totalTextHeightInPixels);
                    sizesV.replace(1, splitterVHeight-totalTextHeightInPixels);
                    ui->splitterV->setSizes(sizesV);
                }

                int row = 0;
                KvSqlData *currentSqlData = NULL;
                if (mapSqlData.count() > 0)
                    currentSqlData = mapSqlData.value(sqlStatementId);

                ui->tabWidgetData->setCurrentWidget(currentSqlData);

                if ((records.count()>0) && (records.at(0).count()>0)) {
                    currentSqlData->setTableWidgetResultsSize(records.count()-1, records.at(0).count());
                    for (int col = 0; col < records.at(0).count(); col++) {
                        QTableWidgetItem *item = new QTableWidgetItem;
                        item->setText(records.at(0).fieldName(col));
                        currentSqlData->setTableWidgetResultsHHeaderItem(col, item);
                    }
                    foreach(QSqlRecord rec, records) {
                        for (int col = 0; col < rec.count(); col++) {
                            QTableWidgetItem *item = new QTableWidgetItem;
                            if (rec.value(col).isNull()) {
                                item->setBackgroundColor(QColor(200, 200, 200, 60));
                                item->setForeground(QColor(170, 170, 170, 255));
                                item->setText("null");
                            }
                            else
                                item->setData(Qt::DisplayRole, rec.value(col));
                            currentSqlData->setTableWidgetResultsItem(row, col, item);
                        }
                        ++row;
                    }
                }
                currentSqlData->tableWidgetResults()->resizeColumnsToContents();
                currentSqlData->tableWidgetResults()->resizeRowsToContents();

                currentSqlData->updateRecordCount(currentSqlData->tableWidgetResults()->rowCount(), recordCount);
                updateRecordCount(currentSqlData->tableWidgetResults()->rowCount(), recordCount);
                currentSqlData->tableWidgetResults()->selectRow(0);
                //updateRecordViewHeaders();
                //updateRecordView();
                update();

            }
            ui->textEditMessages->append(sqlStatement.trimmed());
            //ui->textEditMessages->append(tr("Statement executed."));
            ui->textEditMessages->append("");
        }
        else {
            // Show error description
            ui->tabWidgetData->setCurrentWidget(ui->tabOutput);
            ui->textEditMessages->append(sqlStatement.trimmed());
            ui->textEditMessages->append(error.text());
            ui->textEditMessages->append("");
        }
    }
    else {
        ui->widgetProgress->hide();
        ui->widgetProgress->stop();
    }
    update();
}

void KvSqlWindow::gotSqlBlocksSlot(QStringList sqlBlocks, int fromPosition, int toPosition)
{
    int sqlTextId = 1;
    mapSqlData.clear();
    while(ui->tabWidgetData->count() > 1)
        ui->tabWidgetData->removeTab(ui->tabWidgetData->count()-1);

    if (sqlBlocks.size() == 0) {
        ui->widgetProgress->stop();
        ui->widgetProgress->hide();
        ui->toolButtonCommit->setDisabled(true);
        ui->toolButtonRollback->setDisabled(true);
        mapSqlData.clear();
        while(ui->tabWidgetData->count() > 1)
            ui->tabWidgetData->removeTab(ui->tabWidgetData->count()-1);
    }

    foreach(QString sqlText, sqlBlocks) {
        if (sqlText.simplified().trimmed().length() > 0) {
            QString sqlTabId;
            // create a new results tab according to sqlText
            if (isSelectStatement(sqlText)) {
                sqlTabId = QString::number((int)this->winId())+":"+QString::number(sqlTextId);
                mapSqlData.insert(sqlTabId, newSqlData(sqlTabId, tr("Sql Data")+" ("+QString::number(sqlTextId)+")", sqlText));
            }
            else
                sqlTabId = "default";

            ui->widgetProgress->show();
            ui->widgetProgress->start();
            //ui->tabWidgetData->setCurrentWidget(ui->tabData);
            emit executeQuerySignal(sqlText, sqlTabId);
            ui->toolButtonCommit->setEnabled(true);
            ui->toolButtonRollback->setEnabled(true);
        }
        sqlTextId += 1;
    }
    ui->toolButtonCommit->setEnabled(true);
    ui->toolButtonRollback->setEnabled(true);
}

void KvSqlWindow::gotNextRecordsSlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, bool allRecords, QString sqlStatementId)
{
    if (! allRecords) {
        ui->widgetProgress->hide();
        ui->widgetProgress->stop();
    }

    if (!ui->currentSessionComboBox->currentText().isEmpty()) {
        if (error.type() == QSqlError::NoError) {
            KvSqlData *currentSqlData;
            if (mapSqlData.count() > 0) {
                currentSqlData = mapSqlData.value(sqlStatementId);

                int row = currentSqlData->tableWidgetResults()->rowCount();
                //currentSqlData->tableWidgetResults()->setRowCount(currentSqlData->tableWidgetResults()->rowCount() + records.count());
                foreach(QSqlRecord rec, records) {
                    for (int col = 0; col < rec.count(); col++) {
                        QTableWidgetItem *item = new QTableWidgetItem;
                        if (rec.value(col).isNull()) {
                            item->setBackgroundColor(QColor(200, 200, 200, 60));
                            item->setForeground(QColor(170, 170, 170, 255));
                            item->setText("null");
                        }
                        else
                            item->setData(Qt::DisplayRole, rec.value(col));
                        currentSqlData->tableWidgetResults()->setRowCount(row + 1);
                        currentSqlData->tableWidgetResults()->setItem(row, col, item);
                    }
                    row++;
                }
                currentSqlData->tableWidgetResults()->resizeColumnsToContents();
                currentSqlData->tableWidgetResults()->resizeRowsToContents();

                currentSqlData->updateRecordCount(currentSqlData->tableWidgetResults()->rowCount(), recordCount);
                if (ui->tabWidgetData->currentWidget() == currentSqlData)
                    updateRecordCount(currentSqlData->tableWidgetResults()->rowCount(), recordCount);
                ui->widgetProgress->setValue(ui->widgetProgress->value() - KvDbUtil::recordCountForFetch());
                update();

                if ((!mapCanceledAllRecords.value(sqlStatementId)) && (allRecords) && (currentSqlData->tableWidgetResults()->rowCount() != recordCount) &&
                        (!ui->currentSessionComboBox->currentText().isEmpty()))
                    emit getNextRecordsSignal(sqlStatement, currentSqlData->tableWidgetResults()->rowCount(), true, sqlStatementId);
                else {
                    ui->widgetProgress->hide();
                    ui->widgetProgress->stop();
                    setCancelAllRecords(sqlStatementId, true);
                }
            }
            else {
                ui->widgetProgress->hide();
                ui->widgetProgress->stop();
                setCancelAllRecords(sqlStatementId, true);
            }
        }
        else {
            // Show error description
            ui->textEditMessages->append(error.text());
        }
    }
    else {
        ui->widgetProgress->hide();
        ui->widgetProgress->stop();
    }
}

void KvSqlWindow::getNextRecordsSlot(QString sqlId)
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    KvSqlData *currentData = mapSqlData.value(sqlId);

    emit getNextRecordsSignal(currentData->getSqlStatement(), currentData->tableWidgetResults()->rowCount(), false, sqlId);
}

void KvSqlWindow::getAllRecordsSlot(QString sqlId)
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    setCancelAllRecords(sqlId, false);
    KvSqlData *currentData = mapSqlData.value(sqlId);
    emit getNextRecordsSignal(currentData->getSqlStatement(), currentData->tableWidgetResults()->rowCount(), true, sqlId);
}

void KvSqlWindow::cancelAllRecordsFetchSlot(QString sqlId)
{
    setCancelAllRecords(sqlId, true);
}

void KvSqlWindow::updateRecordCount(int partNumber, int totalNumber)
{
    QString recordSuffixText;
    if (totalNumber > 1)
        recordSuffixText = tr("records");
    else
        recordSuffixText = tr("record");

    if (labelRecordCount->isHidden())
        labelRecordCount->show();
    labelRecordCount->setText(tr("Retrieved")+" "+QString::number(partNumber)+" "+tr("of")+" "+QString::number(totalNumber)+" "+recordSuffixText);
    KvSqlData *current = (KvSqlData *) ui->tabWidgetData->currentWidget();
    labelRecordCount->setText(current->getRecordCountStatus());
}

void KvSqlWindow::on_plainTextEditSql_updateRequest(QRect rect, int dy)
{
    int y = ui->plainTextEditSql->document()->findBlock(ui->plainTextEditSql->textCursor().position()).blockNumber() + 1;
    int x = ui->plainTextEditSql->textCursor().columnNumber() + 1;
    labelEditorCursorPosition->setText(tr("Lin")+": "+QString::number(y)+", "+tr("Col")+": "+QString::number(x));
}

void KvSqlWindow::on_plainTextEditSql_selectionChanged()
{
    if (ui->plainTextEditSql->textCursor().selectedText().isEmpty()) {
        labelSelection->clear();
    }
    else {
        labelSelection->setText(tr("Selected")+": "+QString::number(ui->plainTextEditSql->textCursor().selectedText().count()));
    }
}

QString KvSqlWindow::getPreparedSqlStatement()
{
    QString statement = currentSqlTextLines.join("");
    for(int i=0; i<ui->tableWidgetParams->rowCount(); i++) {
        // Replace all &parameters with values from tableWidgetParams
        statement = statement.replace("&"+ui->tableWidgetParams->verticalHeaderItem(i)->text(), ui->tableWidgetParams->item(i, 0)->text(), Qt::CaseSensitive);
    }
    return statement;
}

// Apply parameters of statements for query processing
void KvSqlWindow::on_toolButtonApplyParams_clicked()
{
    if (!currentSqlTextLines.join("").trimmed().simplified().isEmpty()) {
        // Check if there is an empty value
        bool thereIsAnEmptyValue = false;
        ui->textEditMessages->append(tr("Data for Parameterized Query:"));
        for(int i=0; i<ui->tableWidgetParams->rowCount(); ++i) {
            ui->textEditMessages->append(tr("Parameter")+" &"+
                                         ui->tableWidgetParams->verticalHeaderItem(i)->text()+" = "+
                                         ui->tableWidgetParams->item(i, 0)->text());

            if (!thereIsAnEmptyValue) {
                // Check if is null to avoid exception when calling isEmpty()
                if (ui->tableWidgetParams->item(i, 0) == NULL)
                    thereIsAnEmptyValue = (ui->tableWidgetParams->item(i, 0) == NULL);
                else
                    if (ui->tableWidgetParams->item(i, 0)->text().isEmpty())
                        thereIsAnEmptyValue = ui->tableWidgetParams->item(i, 0)->text().isEmpty();
            }
        }
        ui->textEditMessages->append("");

        if (!thereIsAnEmptyValue) {
            // Fill the parameters of original Sql Staments
            currentSqlTextLines = getPreparedSqlStatement().split(QRegExp("\\n"));

            for(int i=0; i<currentSqlTextLines.size()-1; i++)
                currentSqlTextLines.replace(i, currentSqlTextLines.at(i)+'\n');

            ui->widgetProgress->show();
            ui->widgetProgress->start();
            runSql();
            ui->toolButtonCommit->setEnabled(true);
            ui->toolButtonRollback->setEnabled(true);
        }
        else
            QMessageBox::warning(0, windowTitle()+" "+tr("Parameters"), tr("There is an empty parameter value"));
    }
    ui->frameParams->hide();
}

void KvSqlWindow::updateRecordViewHeaders()
{
    //ui->widgetData->updateRecordViewHeaders();
}

void KvSqlWindow::updateRecordView()
{
    //ui->widgetData->updateRecordView();
}

void KvSqlWindow::currentRecordChangedSlot(int currentRow, QString sqlId)
{
    labelCurrentRecord->setText(tr("Record")+" "+QString::number(currentRow+1));
}

void KvSqlWindow::on_toolButtonCommit_clicked()
{
    // Commiting transaction...
    ui->toolButtonCommit->setEnabled(false);
    ui->toolButtonRollback->setEnabled(false);
    emit commitTransactionSignal();
}

void KvSqlWindow::on_toolButtonRollback_clicked()
{
    //Rolling Back transaction...
    ui->toolButtonCommit->setEnabled(false);
    ui->toolButtonRollback->setEnabled(false);
    emit rollbackTransactionSignal();
}

void KvSqlWindow::setCancelAllRecords(QString sqlId, bool value)
{
    if (mapCanceledAllRecords.contains(sqlId)) {
        mapCanceledAllRecords.remove(sqlId);
    }
    mapCanceledAllRecords.insert(sqlId, value);
    //ui->widgetData->setCancelAllRecordsEnabled(!value);
}

// Export data from Results Grid
QString KvSqlWindow::exportResults(const QString &separator, bool exportHeader) {
    KvSqlData *current = (KvSqlData *) ui->tabWidgetData->currentWidget();
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
QString KvSqlWindow::exportRecord(const QString &separator, bool exportHeader) {
    KvSqlData *current = (KvSqlData *) ui->tabWidgetData->currentWidget();
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

void KvSqlWindow::keyPressEvent(QKeyEvent *event) {
    // if ( _ev->modifiers() & ( Qt::AltModifier | Qt::ControlModifier ) )
    if ((ui->tabWidgetData->hasFocus()) && (ui->tabWidgetData->currentIndex() > 0)) {
        KvSqlData *current = (KvSqlData *) ui->tabWidgetData->currentWidget();
        if ((current->tableWidgetResults()->hasFocus()) && (event->key() == Qt::Key_C) && (event->modifiers() == Qt::ControlModifier)) {
            if (current->tableWidgetResults()->selectionModel()->selectedIndexes().count() > 1) {
                QString str = exportResults("\t", true);
                QApplication::clipboard()->setText(str);
            }

        }
        else if ((current->tableWidgetRecord()->hasFocus()) && (event->key() == Qt::Key_C) && (event->modifiers() == Qt::ControlModifier)) {
            if (current->tableWidgetRecord()->selectionModel()->selectedIndexes().count() > 1) {
                QString str = exportRecord("\t");
                QApplication::clipboard()->setText(str);
            }
        }
    }
    if (event->key() != Qt::Key_Escape) {
        QDialog::keyPressEvent(event);
    }
}

void KvSqlWindow::setComboSessionName(QString sessionName)
{
    if (sessionName.compare(lastSessionName, Qt::CaseInsensitive) != 0) {
        // Clear Sql Data Tabs
        mapSqlData.clear();
        while(ui->tabWidgetData->count() > 1)
            ui->tabWidgetData->removeTab(ui->tabWidgetData->count()-1);

        ui->tabWidget->setCurrentIndex(0);
        if (ui->currentSessionComboBox->count() > 1) {
            setCurrentSession(sessionName);
            ui->currentSessionComboBox->setCurrentIndex(ui->currentSessionComboBox->findText(sessionName, Qt::MatchExactly));
        }

        lastSessionName = sessionName;

        if (!sessionName.isEmpty()) {
            ui->widgetProgress->show();
            ui->widgetProgress->start();
        }


        // Enable Buttons to Execute Sql Statement when ComboBox has an active session
        if (sessionName.isEmpty()) {
            ui->toolButtonExecSql->setEnabled( !sessionName.trimmed().isEmpty() );
            ui->toolButtonExecAllSql->setEnabled( !sessionName.trimmed().isEmpty() );
        }
        ui->toolButtonTimedExec->setEnabled( !sessionName.trimmed().isEmpty() );
        ui->toolButtonExplainPlan->setEnabled( !sessionName.trimmed().isEmpty() );


        //ui->widgetData->setGetNextRecordsEnabled( !sessionName.trimmed().isEmpty() );
        //ui->widgetData->setGetAllRecordsEnabled( !sessionName.trimmed().isEmpty() );
        //ui->widgetData->setCancelAllRecordsEnabled( !sessionName.trimmed().isEmpty() );
        ui->frameParams->hide();
    }
}

void KvSqlWindow::setSqlStatement(QString sqlStatement)
{
    ui->plainTextEditSql->setPlainText(sqlStatement);
}

void KvSqlWindow::runSqlStatement(QString sqlStatement)
{
    openConnectionAndExecute = true;
    setSqlStatement(sqlStatement);
}


void KvSqlWindow::setDdlInfo(QString schemaName, QString objectName, QString objectType, bool showSchema)
{
    openConnectionAndExecuteDdl = true;
    ddlSchemaName = schemaName;
    ddlObjectName = objectName;
    ddlObjectType = objectType;
    ddlShowSchema = showSchema;
}

void KvSqlWindow::setExportDataInfo(QString schemaName, QString tableName, bool showSchema)
{
    openConnectionAndExportData = true;
    ddlSchemaName = schemaName;
    ddlObjectName = tableName;
    ddlShowSchema = showSchema;
}


void KvSqlWindow::on_toolButtonZoomIn_clicked()
{
    QFont sqlTextFont = ui->plainTextEditSql->font();
    sqlTextFont.setPointSize(sqlTextFont.pointSize() + 1);
    ui->plainTextEditSql->setFont(sqlTextFont);
    ui->plainTextEditSql->update();
}

void KvSqlWindow::on_toolButtonZoomOut_clicked()
{
    if (ui->plainTextEditSql->font().pointSize() >= 7) {
        QFont sqlTextFont = ui->plainTextEditSql->font();
        sqlTextFont.setPointSize(sqlTextFont.pointSize() - 1);
        ui->plainTextEditSql->setFont(sqlTextFont);
        ui->plainTextEditSql->update();
    }
}

void KvSqlWindow::getDdlFromObjectSlot(QString schema, QString objectName, QString objectType, bool showSchema, KvSqlSession::DdlTypes ddlType)
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    ui->plainTextEditSql->setReadOnly(true);
    ui->toolButtonExecSql->setDisabled(true);
    ui->toolButtonExecAllSql->setDisabled(true);
    KvSqlDialog::getDdlFromObjectSlot(schema, objectName, objectType, showSchema, ddlType);
}

void KvSqlWindow::gotDdlFromObjectSlot(QString sessionName, QString schema, QString objectName, QString objectType, bool showSchema, QStringList result, KvSqlSession::DdlTypes ddlType)
{
    foreach(QString textLine, result) {
        ui->plainTextEditSql->appendPlainText(textLine.remove('\n'));
    }
    openConnectionAndExecuteDdl = false;
    ui->plainTextEditSql->setReadOnly(false);
    ui->toolButtonExecSql->setEnabled(true);
    ui->toolButtonExecAllSql->setEnabled(true);
    ui->plainTextEditSql->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
    ui->widgetProgress->hide();
    ui->widgetProgress->stop();
}

void KvSqlWindow::getPlanSlot(QString sqlStatement, QString sqlStatementId)
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    //ui->plainTextEditSql->setReadOnly(true);
    //ui->toolButtonExecSql->setDisabled(true);
    //ui->toolButtonExecAllSql->setDisabled(true);
    KvSqlDialog::getPlanSlot(sqlStatement, sqlStatementId);
}

void KvSqlWindow::gotPlanSlot(QString sqlStatement, QString sqlStatementId, QList< QPair<QString, QMap<QString,QString> > > result)
{
    mapSqlData.value(sqlStatementId)->treeWidgetPlan()->setFocus(Qt::TabFocusReason);
    //mapSqlData.value(sqlStatementId)->treeWidgetPlan()->hideColumn(2);
    if (!result.isEmpty()) {
        KvSqlData *sqlData = mapSqlData.value(sqlStatementId);
        QTreeWidget *treeWidget = sqlData->treeWidgetPlan();
        for(int i=0; i<result.count(); i++)
        {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0, result.at(i).second.value("OPERATION")+" "+result.at(i).second.value("OPTIONS").trimmed());
            item->setText(1, result.at(i).second.value("COST").trimmed());
            item->setText(2, result.at(i).second.value("ID").trimmed());
            QString parentId = result.at(i).second.value("PARENT_ID").trimmed();
            if (treeWidget->topLevelItem(0) == 0)
                treeWidget->insertTopLevelItem(0, item);
            else {
                QList<QTreeWidgetItem *> parentList = treeWidget->findItems(parentId, Qt::MatchRecursive|Qt::MatchExactly, 2);
                if (parentList.count() > 0) {
                    parentList.at(0)->addChild(item);
                }
            }
        }
        treeWidget->expandAll();
        treeWidget->resizeColumnToContents(0);
        treeWidget->resizeColumnToContents(1);
    }
    ui->widgetProgress->stop();
    ui->widgetProgress->hide();
}

void KvSqlWindow::getExportedDataSlot(QString schema, QString tableName, bool showSchema, QString sqlStatementId)
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    ui->plainTextEditSql->setReadOnly(true);
    ui->toolButtonExecSql->setDisabled(true);
    ui->toolButtonExecAllSql->setDisabled(true);
    KvSqlDialog::getExportedDataSlot(schema, tableName, showSchema, sqlStatementId);
}

void KvSqlWindow::gotExportedDataSlot(QString sessionName, QString schema, QString tableName, bool showSchema, QString resultLine, bool isTheEnd, QString sqlStatementId)
{
    ui->plainTextEditSql->appendPlainText(resultLine);
    openConnectionAndExportData = false;
    if (isTheEnd) {
        ui->plainTextEditSql->setReadOnly(false);
        ui->toolButtonExecSql->setEnabled(true);
        ui->toolButtonExecAllSql->setEnabled(true);
        ui->plainTextEditSql->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
        ui->widgetProgress->hide();
        ui->widgetProgress->stop();
    }
}

void KvSqlWindow::on_actionRun_Sql_triggered()
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    // Clear Previous Error Messages
    ui->textEditMessages->clear();
    //setCancelAllRecords(true);

    if (ui->plainTextEditSql->textCursor().hasSelection()) {
        currentSqlTextLines = ui->plainTextEditSql->textCursor().selection().toPlainText().split(QRegExp("\\n"));
        for(int i=0; i<currentSqlTextLines.size()-1; i++)
            currentSqlTextLines.replace(i, currentSqlTextLines.at(i)+'\n');
        runSql();
    }
    else {
        int currentPosition = ui->plainTextEditSql->textCursor().block().position();
        currentSqlTextLines = ui->plainTextEditSql->toPlainText().split(QRegExp("\\n"));
        for(int i=0; i<currentSqlTextLines.size()-1; i++)
            currentSqlTextLines.replace(i, currentSqlTextLines.at(i)+'\n');
        runSql(currentPosition, currentPosition);
    }

    /*
    else {
        // Set Sql Statement to execute
        // Get the position of the first character of current cursor line
        int currentPosition = ui->plainTextEditSql->textCursor().block().position();
        if (ui->plainTextEditSql->toPlainText().indexOf(QRegExp(";(?![.*\\*\\/|.*\\'])"),currentPosition) > 0) {
            int nextSemicolonPosition = ui->plainTextEditSql->toPlainText().indexOf(QRegExp(";(?![.*\\*\\/|.*\\'])"),currentPosition);
            int priorSemicolonPosition = ui->plainTextEditSql->toPlainText().left(currentPosition).lastIndexOf(QRegExp(";(?![.*\\*\\/|.*\\'])"))+1;
            currentSqlText = ui->plainTextEditSql->toPlainText().mid(priorSemicolonPosition, (nextSemicolonPosition-priorSemicolonPosition)+1);
        }
        else {
            int nextSemicolonPosition = ui->plainTextEditSql->toPlainText().length();
            int priorSemicolonPosition = ui->plainTextEditSql->toPlainText().left(currentPosition).lastIndexOf(QRegExp(";(?![.*\\*\\/|.*\\'])"))+1;
            currentSqlText = ui->plainTextEditSql->toPlainText().mid(priorSemicolonPosition, (nextSemicolonPosition-priorSemicolonPosition)+1);
        }
    }*/

}

void KvSqlWindow::on_actionRun_All_triggered()
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    // Clear Previous Error Messages
    ui->textEditMessages->clear();
    //setCancelAllRecords(true);
    // Set Sql Statement to execute
    if (ui->plainTextEditSql->textCursor().hasSelection())
        currentSqlTextLines = ui->plainTextEditSql->textCursor().selectedText().split(QRegExp("\\n"));
    else {
        currentSqlTextLines = ui->plainTextEditSql->toPlainText().split(QRegExp("\\n"));
    }
    for(int i=0; i<currentSqlTextLines.size()-1; i++)
        currentSqlTextLines.replace(i, currentSqlTextLines.at(i)+'\n');

    runSql();
}

bool KvSqlWindow::isSelectStatement(QString text)
{
    bool result = false;
    QString textWithNoComments = text.remove(QRegExp("\\/\\*.*\\*\\/"));
    QRegExp minimalRegExp = QRegExp("--.*(?=\\n)");
    minimalRegExp.setMinimal(true);
    textWithNoComments = textWithNoComments.remove(minimalRegExp);
    QStringList words = textWithNoComments.split(QRegExp("\\s"), QString::SkipEmptyParts);
    if (words.count() > 0) {
        QString firstWord = (QString)words.at(0);
        if ((firstWord.simplified().compare("SELECT", Qt::CaseInsensitive) == 0) ||
                (firstWord.simplified().compare("PRAGMA", Qt::CaseInsensitive) == 0)) {
            result = true;
        }
    }
    return result;
}

// The main routine to execute Sql Statements
void KvSqlWindow::runSql(int fromPosition, int toPosition) {
    if (!currentSqlTextLines.join("").trimmed().simplified().isEmpty()) {
        // Get Parameters from Sql Text
        QStringList paramList = getSqlParameters(currentSqlTextLines.join(""));
        if (paramList.count() > 0) {
            ui->tableWidgetParams->clear();
            ui->tableWidgetParams->setRowCount(paramList.count());
            ui->tableWidgetParams->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Value")));
            for(int i=0; i<paramList.count(); ++i) {
                QTableWidgetItem *item = new QTableWidgetItem(paramList.at(i));
                ui->tableWidgetParams->setVerticalHeaderItem(i, item);
            }
            ui->frameParams->show();
            ui->tableWidgetParams->setFocus(Qt::ActiveWindowFocusReason);
            ui->tableWidgetParams->setCurrentItem(ui->tableWidgetParams->item(0,0));
        }
        else {
            emit getSqlBlocksSignal(currentSqlTextLines, fromPosition, toPosition);
            /*
            // Get all Sql Statements, separated by ;
            QStringList sqlStatements = currentSqlText.split(QRegExp(";(?![.*\\*\\/|.*\\'])"), QString::SkipEmptyParts);

            // Calculating Tab Width, according to number of sqlStatements
            QFontMetrics fm(ui->tabWidgetData->font());
            int tabWidth = fm.width(QString(tr("Sql Data"))+" ("+QString::number(sqlStatements.count())+")");
            ui->tabWidgetData->setStyleSheet("QTabBar::tab { min-width: "+QString::number(tabWidth)+"px; }");

            int sqlTextId = 1;
            mapSqlData.clear();

            while(ui->tabWidgetData->count() > 1)
                ui->tabWidgetData->removeTab(ui->tabWidgetData->count()-1);

            QString sqlBlockText = QString();
            foreach(QString sqlText, sqlStatements) {
                // if sqlText contains BEGIN, grouping will be started
                if ((sqlText.count("BEGIN", Qt::CaseInsensitive) > 0)) {
                    if (sqlBlockText.isEmpty()) {
                        sqlBlockText = sqlText+";";
                    }
                }

                if (!sqlBlockText.isEmpty()) {
                    if (QString::compare(sqlBlockText, sqlText+";") != 0) {
                        sqlBlockText += sqlText+";";
                        QString sqlBlockTextNoSpace = sqlBlockText;
                        sqlBlockTextNoSpace = sqlBlockTextNoSpace.remove(QRegExp("(\\/)(\\*).*(\\*)(\\/)"));
                        sqlBlockTextNoSpace = sqlBlockTextNoSpace.remove(QRegExp("--([\\s|\\S]*)\\n"));
                        sqlBlockTextNoSpace = sqlBlockTextNoSpace.simplified();
                        sqlBlockTextNoSpace.replace(" ","");
                        if (sqlBlockTextNoSpace.count("BEGIN", Qt::CaseInsensitive) == sqlBlockTextNoSpace.count("END", Qt::CaseInsensitive)
                            - (sqlBlockTextNoSpace.count("ENDIF", Qt::CaseInsensitive) + sqlBlockTextNoSpace.count("ENDLOOP", Qt::CaseInsensitive))) {
                            sqlText = sqlBlockText;
                            sqlBlockText = QString();
                        }
                    }
                }

                if (sqlBlockText.isEmpty()) {
                    if (sqlText.simplified().trimmed().length() > 0) {
                        QString sqlTabId;
                        // create a new results tab according to sqlText
                        if (isSelectStatement(sqlText)) {
                            sqlTabId = QString::number((int)this->winId())+":"+QString::number(sqlTextId);
                            mapSqlData.insert(sqlTabId, newSqlData(sqlTabId, tr("Sql Data")+" ("+QString::number(sqlTextId)+")", sqlText));
                        }
                        else
                            sqlTabId = "default";

                        ui->widgetProgress->show();
                        ui->widgetProgress->start();
                        //ui->tabWidgetData->setCurrentWidget(ui->tabData);
                        emit executeQuerySignal(sqlText, sqlTabId);
                        ui->toolButtonCommit->setEnabled(true);
                        ui->toolButtonRollback->setEnabled(true);
                    }
                    sqlTextId += 1;
                }

            }*/
            ui->toolButtonCommit->setEnabled(true);
            ui->toolButtonRollback->setEnabled(true);
        }
    }
}

KvSqlData *KvSqlWindow::newSqlData(QString newSqlId, QString newSqlLabel, QString newSqlText)
{
    KvSqlData *newSqlData = new KvSqlData(ui->tabWidgetData);
    newSqlData->setSqlStatement(newSqlId, newSqlText);
    connect(newSqlData, SIGNAL(getNextRecordsSignal(QString)), this, SLOT(getNextRecordsSlot(QString)));
    connect(newSqlData, SIGNAL(getAllRecordsSignal(QString)), this, SLOT(getAllRecordsSlot(QString)));
    connect(newSqlData, SIGNAL(cancelAllRecordsFetchSignal(QString)), this, SLOT(cancelAllRecordsFetchSlot(QString)));
    connect(newSqlData, SIGNAL(currentRecordChangedSignal(int,QString)), this, SLOT(currentRecordChangedSlot(int,QString)));

    ui->tabWidgetData->addTab(newSqlData, newSqlLabel);
    ui->tabWidgetData->setTabToolTip(ui->tabWidgetData->count()-1, newSqlLabel);
    return newSqlData;
}

void KvSqlWindow::on_actionCopy_to_Clipboard_triggered()
{

}

void KvSqlWindow::on_tabWidgetData_currentChanged(int index)
{
    if (index > 0) {
        if (labelRecordCount->isHidden())
            labelRecordCount->show();

        KvSqlData *current = (KvSqlData *) ui->tabWidgetData->widget(index);
        labelRecordCount->setText(current->getRecordCountStatus());
        labelCurrentRecord->setText(tr("Record")+" "+QString::number(current->tableWidgetResults()->currentRow()+1));
    }
    else {
        labelRecordCount->setText("");
        labelRecordCount->hide();
        labelCurrentRecord->setText("");
    }
}


void KvSqlWindow::on_tabWidget_currentChanged(int index)
{
    if (ui->tabWidget->widget(index) == ui->tabSessionInfo) {
        while (ui->tableWidgetSessionInfo->rowCount() > 0)
            ui->tableWidgetSessionInfo->removeRow(0);
        ui->tableWidgetSessionInfo->clearContents();
        ui->tableWidgetSessionInfo->setRowCount(mapSessionInfo.count());
        for(int i=0; i<mapSessionInfo.keys().count(); ++i) {
            QString infoName = mapSessionInfo.keys().at(i);
            QTableWidgetItem *itemInfo = new QTableWidgetItem(infoName);
            ui->tableWidgetSessionInfo->setItem(i, 0, itemInfo);
            QTableWidgetItem *itemValue = new QTableWidgetItem(mapSessionInfo.value(infoName));
            ui->tableWidgetSessionInfo->setItem(i, 1, itemValue);
        }
        ui->tableWidgetSessionInfo->resizeColumnToContents(0);
    }
}

void KvSqlWindow::on_toolButtonCancelParams_clicked()
{
    ui->frameParams->hide();
    ui->textEditMessages->append(tr("Parameterized Query Canceled."));
    ui->textEditMessages->append("");

}

void KvSqlWindow::on_actionExplainAll_triggered()
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    // Explain All Sql Statements
    ui->textEditMessages->clear();

    if (ui->plainTextEditSql->textCursor().hasSelection())
        currentSqlTextLines = ui->plainTextEditSql->textCursor().selectedText().split(QRegExp("\\n"));
    else {
        currentSqlTextLines = ui->plainTextEditSql->toPlainText().split(QRegExp("\\n"));
    }
    for(int i=0; i<currentSqlTextLines.size()-1; i++)
        currentSqlTextLines.replace(i, currentSqlTextLines.at(i)+'\n');

    if (!currentSqlTextLines.join("").trimmed().simplified().isEmpty()) {
        // Get Parameters from Sql Text
        QStringList paramList = getSqlParameters(currentSqlTextLines.join(""));
        if (paramList.count() > 0) {
            ui->tableWidgetParams->clear();
            ui->tableWidgetParams->setRowCount(paramList.count());
            ui->tableWidgetParams->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Value")));
            for(int i=0; i<paramList.count(); ++i) {
                QTableWidgetItem *item = new QTableWidgetItem(paramList.at(i));
                ui->tableWidgetParams->setVerticalHeaderItem(i, item);
            }
            ui->frameParams->show();
            ui->tableWidgetParams->setFocus(Qt::ActiveWindowFocusReason);
            ui->tableWidgetParams->setCurrentItem(ui->tableWidgetParams->item(0,0));
        }
        else {
            ui->widgetProgress->show();
            ui->widgetProgress->start();

            QStringList newCurrentSqlTextLines = QStringList();

            QRegExp minimalRegExp = QRegExp("--.*\\n");
            minimalRegExp.setMinimal(true);

            foreach(QString sqlLine, currentSqlTextLines) {
                if (sqlLine.indexOf(minimalRegExp) != 0) {
                    if (! sqlLine.trimmed().simplified().isEmpty() )
                        newCurrentSqlTextLines.append(sqlLine);
                }
            }

            if (newCurrentSqlTextLines.size() == 0) {
                // TODO: Display no SQL select command to explain
                ui->widgetProgress->stop();
                ui->widgetProgress->hide();
            }

            // Get all Sql Statements, separated by ;
            QStringList sqlStatements = newCurrentSqlTextLines.join("").split(QRegExp(";(?![.*\\*\\/)|.*\\']"), QString::SkipEmptyParts);

            // Calculating Tab Width, according to number of sqlStatements
            QFontMetrics fm(ui->tabWidgetData->font());
            int tabWidth = fm.width(QString(tr("Sql Plan"))+" ("+QString::number(sqlStatements.count())+")");
            ui->tabWidgetData->setStyleSheet("QTabBar::tab { min-width: "+QString::number(tabWidth)+"px; }");

            int sqlTextId = 1;
            mapSqlData.clear();

            while(ui->tabWidgetData->count() > 1)
                ui->tabWidgetData->removeTab(ui->tabWidgetData->count()-1);

            foreach(QString sqlText, newCurrentSqlTextLines) {
                if (sqlText.simplified().trimmed().length() > 0) {
                    QString sqlTabId;
                    // create a new results tab according to sqlText
                    if (isSelectStatement(sqlText)) {
                        sqlTabId = QString::number((int)this->winId())+":"+QString::number(sqlTextId);
                        KvSqlData *sqlData = newSqlData(sqlTabId, tr("Sql Plan")+" ("+QString::number(sqlTextId)+")", sqlText);
                        sqlData->setCurrentStackedWidget(2);
                        mapSqlData.insert(sqlTabId, sqlData);
                        ui->widgetProgress->show();
                        ui->widgetProgress->start();
                        getPlanSlot(sqlText, sqlTabId);
                    }
                    else
                        sqlTabId = "default";
                }
                sqlTextId += 1;
            }
            ui->toolButtonCommit->setEnabled(false);
            ui->toolButtonRollback->setEnabled(false);
            ui->tabWidgetData->setVisible(true);
            if (ui->tabWidgetData->count() > 1)
                ui->tabWidgetData->setCurrentIndex(1);
        }
    }
}

bool KvSqlWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if (object == ui->plainTextEditSql)
        {
            ui->toolButtonZoomIn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus));
            ui->toolButtonZoomOut->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus));
            for (int i=0; i<ui->tabWidgetData->count(); i++) {
                QWidget *widget = ui->tabWidgetData->widget(i);
                if (widget->inherits("KvSqlData")) {
                    ((KvSqlData *) widget)->enableShortCuts(false);
                }
            }
        }
    }
    else if (event->type() == QEvent::FocusOut)
    {
        if (object == ui->plainTextEditSql)
        {
            ui->toolButtonZoomIn->setShortcut(QKeySequence());
            ui->toolButtonZoomOut->setShortcut(QKeySequence());
            for (int i=0; i<ui->tabWidgetData->count(); i++) {
                QWidget *widget = ui->tabWidgetData->widget(i);
                if (widget->inherits("KvSqlData")) {
                    ((KvSqlData *) widget)->enableShortCuts(true);
                }
            }
        }
    }
    return false;
}

/*
void KvSqlWindow::on_plainTextEditSql_modificationChanged(bool value)
{
    setWindowModified(value);
}
*/


void KvSqlWindow::on_actionTimed_Run_triggered()
{
    if (timer->isActive()) {
        timer->stop();
    }
    else {
        ui->actionRun_All->trigger();
        timer->start(10000);
    }
}

void KvSqlWindow::openFile(QString fileName)
{
    // Disabling widgets that can disturb the openning operation
    ui->toolButtonClearSql->setEnabled(false);
    ui->currentSessionComboBox->setEnabled(false);

    // Starting animation
    ui->widgetProgress->show();
    ui->widgetProgress->start();

    isOpening = true;
    ui->plainTextEditSql->setCenterOnScroll(true);


    qRegisterMetaType<QTextCursor>("QTextCursor");
    qRegisterMetaType<QTextBlock>("QTextBlock");
    int increment = 10;
    int count = 0;

    ui->plainTextEditSql->clear();
    ui->plainTextEditSql->setReadOnly(true);
    ui->plainTextEditSql->setUndoRedoEnabled(false);

    qint64 position = 0;
    while(!isClosing && position >= 0) {
        QFuture<qint64> lastPosition = run(partialRead, fileName, ui->plainTextEditSql, increment, position);
        lastPosition.waitForFinished();
        qApp->processEvents();
        position = lastPosition;
    }

    ui->toolButtonClearSql->setEnabled(true);
    ui->currentSessionComboBox->setEnabled(true);
    ui->widgetProgress->stop();
    ui->widgetProgress->hide();
    ui->plainTextEditSql->setReadOnly(false);
    ui->plainTextEditSql->setUndoRedoEnabled(true);
    ui->plainTextEditSql->setCenterOnScroll(false);
    isOpening = false;

    currentFileName = fileName;
}

void KvSqlWindow::saveFile()
{
    // Disabling widgets that can disturb the openning operation
    ui->toolButtonClearSql->setEnabled(false);
    ui->currentSessionComboBox->setEnabled(false);

    // Starting animation
    ui->widgetProgress->show();
    ui->widgetProgress->start();

    ui->plainTextEditSql->setCenterOnScroll(true);
    ui->plainTextEditSql->setReadOnly(true);
    ui->plainTextEditSql->setUndoRedoEnabled(false);

    QFile file(currentFileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(currentFileName)
                             .arg(file.errorString()));
    }
    else {
         QTextStream out(&file);
         QApplication::setOverrideCursor(Qt::WaitCursor);
         out << ui->plainTextEditSql->toPlainText();
         QApplication::restoreOverrideCursor();
    }

    ui->toolButtonClearSql->setEnabled(true);
    ui->currentSessionComboBox->setEnabled(true);
    ui->widgetProgress->stop();
    ui->widgetProgress->hide();
    ui->plainTextEditSql->setReadOnly(false);
    ui->plainTextEditSql->setUndoRedoEnabled(true);
    ui->plainTextEditSql->setCenterOnScroll(false);
    isOpening = false;
}


void KvSqlWindow::on_actionGenerate_Cascade_Operations_triggered()
{
    QStringList statements;
    QString firstSqlStatement;
    if (ui->plainTextEditSql->textCursor().hasSelection()) {
        ui->widgetProgress->show();
        ui->widgetProgress->start();

        statements = ui->plainTextEditSql->textCursor().selection().toPlainText().split(QRegExp(";"), QString::SkipEmptyParts);

        if (statements.count() > 0) {
            firstSqlStatement = statements.at(0);

            if (statements.count() > 1)
                QMessageBox::warning(this, tr("Cascade Operations Warning"), tr("Only first statement will be processed."));
            emit getDependentSqlSignal(firstSqlStatement);
        }
    }
}

void KvSqlWindow::gotDependentSqlSlot(QString sqlStatement, QStringList dependentSqlStatements)
{
    QTextCursor textCursor = ui->plainTextEditSql->textCursor();
    textCursor.clearSelection();
    ui->plainTextEditSql->setTextCursor( textCursor );
    //ui->plainTextEditSql->textCursor().clearSelection();
    ui->plainTextEditSql->appendPlainText("");
    ui->plainTextEditSql->textCursor().movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor);
    foreach(QString statement, dependentSqlStatements)
        ui->plainTextEditSql->appendPlainText(statement);

    ui->plainTextEditSql->textCursor().movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor);
    ui->widgetProgress->stop();
    ui->widgetProgress->hide();

}

void KvSqlWindow::on_actionExtract_Consistent_Sql_Data_triggered()
{
    QStringList statements;
    QString firstSqlStatement;
    if (ui->plainTextEditSql->textCursor().hasSelection()) {
        ui->widgetProgress->show();
        ui->widgetProgress->start();

        statements = ui->plainTextEditSql->textCursor().selection().toPlainText().split(QRegExp(";"), QString::SkipEmptyParts);

        if (statements.count() > 0) {
            firstSqlStatement = statements.at(0);

            if (statements.count() > 1)
                QMessageBox::warning(this, tr("Extract Data Warning"), tr("Only first statement will be processed."));
            emit getExtractConsistentDataSqlSignal(firstSqlStatement);
        }
    }
}

void KvSqlWindow::gotExtractConsistentDataSqlSlot(QString sqlStatement, QStringList consistentSqlStatements)
{
    QTextCursor textCursor = ui->plainTextEditSql->textCursor();
    textCursor.clearSelection();
    ui->plainTextEditSql->setTextCursor( textCursor );
    //ui->plainTextEditSql->textCursor().clearSelection();
    ui->plainTextEditSql->appendPlainText("");
    ui->plainTextEditSql->textCursor().movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor);
    foreach(QString statement, consistentSqlStatements)
        ui->plainTextEditSql->appendPlainText(statement);

    ui->plainTextEditSql->textCursor().movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor);
    ui->widgetProgress->stop();
    ui->widgetProgress->hide();

}
