#include "kvexportobjects.h"
#include "ui_kvexportobjects.h"

KvExportObjects::KvExportObjects(QWidget *parent) :
    KvSqlDialog(parent),
    ui(new Ui::KvExportObjects)
{
    ui->setupUi(this);
    solver = new KvSolver(this);
    databaseTypeNames = QStringList();

    ui->widgetProgress->stop();
    ui->widgetProgress->hide();

    QWizard wizard;
    ui->pushButtonBack->setEnabled(false);
    ui->pushButtonBack->setText(wizard.button(QWizard::BackButton)->text());
    ui->pushButtonNextFinish->setText(wizard.button(QWizard::NextButton)->text());
    ui->pushButtonCancel->setText(wizard.button(QWizard::CancelButton)->text());

    ui->toolButtonFindObj2->resize(ui->toolButtonFindObj->size());

    connect(ui->toolButtonFindObj, SIGNAL(clicked()), ui->actionFind_Objects, SLOT(trigger()));
    connect(ui->toolButtonAddObj, SIGNAL(clicked()), ui->actionAdd_Objects_to_Selected, SLOT(trigger()));
    connect(ui->toolButtonRemoveObj, SIGNAL(clicked()), ui->actionRemove_from_Selected, SLOT(trigger()));
    connect(ui->toolButtonClearObj, SIGNAL(clicked()), ui->actionClear_Selected, SLOT(trigger()));
    connect(ui->toolButtonAddAll, SIGNAL(clicked()), ui->actionAdd_All_Objects_to_Selected, SLOT(trigger()));
    //connect(ui->pushButtonExportNow, SIGNAL(clicked()), ui->actionExport_Objects, SLOT(trigger()));

    ui->lineEditOutputDir->setText(KvSettings::getDefaultWorkPath());

    ui->tableWidgetOutputFiles->addAction(ui->actionSet_Default_Only_One);
    setOutputOptions();

    outputDocument = new QTextDocument(this);
    textCursor = new QTextCursor(outputDocument);

    mapExportedTablesInfo = QMap<QString, KvTableInfo>();
    mapExportedColumnsInfo = QMap<QString, QList<KvColumnInfo> >();
    mapExportedConstraintsInfo = QMap<QString, QList<KvTableConstraintInfo> >();

}

KvExportObjects::~KvExportObjects()
{
    delete solver;
    delete ui;
}

void KvExportObjects::changeEvent(QEvent *e)
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

void KvExportObjects::keyPressEvent(QKeyEvent *event) {
    if (event->key() != Qt::Key_Escape) {
        QDialog::keyPressEvent(event);
    }
}

void KvExportObjects::setActiveSessions(QStringList sessions)
{
    KvSqlDialog::setActiveSessions(sessions);
    updateActiveSessionsCombo();
}

void KvExportObjects::setDataDictionaryOption(bool value)
{
    setWindowTitle(tr("Build Data Dictionary"));
}

void KvExportObjects::addActiveSession(QString session)
{
    KvSqlDialog::addActiveSession(session);
    updateActiveSessionsCombo();
}

void KvExportObjects::removeActiveSession(QString session)
{
    KvSqlDialog::removeActiveSession(session);
    updateActiveSessionsCombo();
}

void KvExportObjects::updateActiveSessionsCombo()
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

void KvExportObjects::enableSearchWidgets(bool value)
{
    ui->lineEditObjectName->setEnabled(value);
    ui->comboBoxTypeNames->setEnabled(value);
    ui->toolButtonFindObj->setEnabled(value);
    ui->toolButtonNextRecords->setEnabled(value);
    ui->toolButtonAllRecords->setEnabled(value);
    ui->toolButtonCancelFetchAll->setEnabled(value);
    ui->toolButtonAddObj->setEnabled(value);
    ui->toolButtonRemoveObj->setEnabled(value);
    ui->toolButtonAddAll->setEnabled(value);
    ui->toolButtonClearObj->setEnabled(value);
}

void KvExportObjects::setComboSessionName(QString sessionName)
{
    if (sessionName.compare(lastSessionName, Qt::CaseInsensitive) != 0) {
        if (ui->currentSessionComboBox->count() > 1) {
            setCurrentSession(sessionName);
            ui->currentSessionComboBox->setCurrentIndex(ui->currentSessionComboBox->findText(sessionName, Qt::MatchExactly));
        }
        lastSessionName = sessionName;

        if (sessionName.isEmpty()) {
            enableSearchWidgets( false );
            while(ui->tableWidgetSelectedObj->rowCount() > 0)
                ui->tableWidgetSelectedObj->removeRow(0);
            ui->tableWidgetSelectedObj->clearContents();
            ui->widgetProgress->stop();
            ui->widgetProgress->hide();
        }
        // Clear object types combobox for searching objects...
        ui->comboBoxTypeNames->clear();
        ui->comboBoxTypeNames->addItem(tr("Any Type"));
        if (!sessionName.isEmpty()) {
            ui->widgetProgress->start();
            ui->widgetProgress->show();
        }
    }
}

void KvExportObjects::on_pushButtonNextFinish_clicked()
{
    if ( ui->stackedWidgetExportObj->currentIndex() == ui->stackedWidgetExportObj->count() - 1 ) {
        //parentWidget()->close();
        ui->actionExport_Objects->trigger();
        ui->pushButtonCancel->setText(tr("Close"));
    }
    else {
        ui->stackedWidgetExportObj->setCurrentIndex(ui->stackedWidgetExportObj->currentIndex() + 1);
        if ( ui->stackedWidgetExportObj->currentIndex() == ui->stackedWidgetExportObj->count() - 1 ) {
            ui->pushButtonNextFinish->setText(tr("Export"));
            ui->pushButtonNextFinish->setIcon(QIcon(":/png/png_general/cog_go.png"));
            setOutputOptions();
        }
    }

    ui->pushButtonBack->setDisabled( ui->stackedWidgetExportObj->currentIndex() == 0 );
}

void KvExportObjects::on_pushButtonBack_clicked()
{
    if ( ui->stackedWidgetExportObj->currentIndex() > 0 ) {
        if ( ui->stackedWidgetExportObj->currentIndex() == ui->stackedWidgetExportObj->count() - 1 ) {
            QWizard wizard;
            ui->pushButtonNextFinish->setText(wizard.button(QWizard::NextButton)->text());
            ui->pushButtonNextFinish->setIcon(QIcon());
        }

        ui->stackedWidgetExportObj->setCurrentIndex(ui->stackedWidgetExportObj->currentIndex() - 1);
    }

    ui->pushButtonBack->setDisabled( ui->stackedWidgetExportObj->currentIndex() == 0 );
}

void KvExportObjects::on_currentSessionComboBox_activated(QString text)
{
    setComboSessionName(text);
}

void KvExportObjects::setCancelAllRecords(bool value)
{
    cancelAllRecords = value;
}

void KvExportObjects::executedQuerySlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, QString sqlStatementId)
{
    ui->widgetProgress->hide();
    ui->widgetProgress->stop();
    QCoreApplication::processEvents();

    if (!ui->currentSessionComboBox->currentText().isEmpty()) {
        if (error.type() == QSqlError::NoError) {
            // Clear Previous Error Messages
            // ui->textEditMessages->clear();

            setCancelAllRecords(true);
            int row = 0;
            if ((records.count()>0) && (records.at(0).count()>0)) {
                ui->tableWidgetFoundObj->setRowCount(records.count()-1);
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
                        ui->tableWidgetFoundObj->setItem(row, col, item);
                    }
                    ++row;
                }
            }
            ui->tableWidgetFoundObj->resizeColumnToContents(0);
            ui->tableWidgetFoundObj->resizeColumnToContents(1);
            ui->tableWidgetFoundObj->resizeRowsToContents();

            updateRecordCount(ui->tableWidgetFoundObj->rowCount(), recordCount);
            ui->tableWidgetFoundObj->selectRow(0);
            update();
        }
    }
    else {
        ui->widgetProgress->hide();
        ui->widgetProgress->stop();
    }
    update();
}

void KvExportObjects::gotNextRecordsSlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, bool allRecords, QString sqlStatementId)
{
    if (! allRecords) {
        ui->widgetProgress->hide();
        ui->widgetProgress->stop();
    }

    if (!ui->currentSessionComboBox->currentText().isEmpty()) {
        if (error.type() == QSqlError::NoError) {
            int row = ui->tableWidgetFoundObj->rowCount();
            //ui->tableWidgetFoundObj->setRowCount(row + records.count());
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

                    ui->tableWidgetFoundObj->setRowCount(row + 1);
                    ui->tableWidgetFoundObj->setItem(row, col, item);
                }
                row++;
            }
            ui->tableWidgetFoundObj->resizeColumnToContents(0);
            ui->tableWidgetFoundObj->resizeColumnToContents(1);
            ui->tableWidgetFoundObj->resizeRowsToContents();

            updateRecordCount(ui->tableWidgetFoundObj->rowCount(), recordCount);

            ui->widgetProgress->setValue(ui->widgetProgress->value() - KvDbUtil::recordCountForFetch());
            update();

            if ((!cancelAllRecords) && (allRecords) && (ui->tableWidgetFoundObj->rowCount() != recordCount) &&
                    (!ui->currentSessionComboBox->currentText().isEmpty()))
                emit getNextRecordsSignal(sqlStatement, ui->tableWidgetFoundObj->rowCount(), true);
            else {
                ui->widgetProgress->hide();
                ui->widgetProgress->stop();
                setCancelAllRecords(true);
            }
        }
        else {
            ui->widgetProgress->hide();
            ui->widgetProgress->stop();
            setCancelAllRecords(true);
        }
    }
}

void KvExportObjects::updateRecordCount(int partNumber, int totalNumber)
{
    QString recordSuffixText;
    if (totalNumber > 1)
        recordSuffixText = tr("records");
    else
        recordSuffixText = tr("record");

    ui->labelRecordCount->setText(tr("Retrieved")+" "+QString::number(partNumber)+" "+tr("of")+" "+QString::number(totalNumber)+" "+recordSuffixText);
}

void KvExportObjects::gotFindObjectStatementSlot(QString fullObjectName, QString statement)
{
    searchSqlStatement = statement;
    emit executeQuerySignal(searchSqlStatement);
}

void KvExportObjects::on_actionFind_Objects_triggered()
{
    ui->widgetProgress->start();
    ui->widgetProgress->show();

    while (ui->tableWidgetFoundObj->rowCount() > 0)
        ui->tableWidgetFoundObj->removeRow(0);
    ui->tableWidgetFoundObj->clearContents();
    //ui->tableWidgetFoundObj->clear();
    ui->tableWidgetFoundObj->setRowCount(0);
    ui->labelRecordCount->clear();

    // Full object name (Schema.Object)
    QString objectName = ui->lineEditObjectName->text();
    if (objectName.trimmed().isEmpty()) {
        objectName = "*.*";
    }

    // Before executing this query, we should emit a signal to find the correct syntax according to the current database session
    if (ui->comboBoxTypeNames->currentIndex() == 0)
        emit getFindObjectStatementSignal(objectName);
    else
        emit getFindObjectStatementSignal(objectName, ui->comboBoxTypeNames->currentText());
    // emit executeQuerySignal(searchSqlStatement);
}

void KvExportObjects::on_toolButtonNextRecords_clicked()
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    emit getNextRecordsSignal(searchSqlStatement, ui->tableWidgetFoundObj->rowCount(), false);
}

void KvExportObjects::on_toolButtonAllRecords_clicked()
{
    ui->widgetProgress->show();
    ui->widgetProgress->start();
    setCancelAllRecords(false);
    emit getNextRecordsSignal(searchSqlStatement, ui->tableWidgetFoundObj->rowCount(), true);
}

void KvExportObjects::on_toolButtonCancelFetchAll_clicked()
{
    setCancelAllRecords(true);
}

void KvExportObjects::on_actionAdd_Objects_to_Selected_triggered()
{
    QSet<int> rowSet = QSet<int>();
    foreach(QTableWidgetItem *item, ui->tableWidgetFoundObj->selectedItems())
        rowSet.insert(item->row());

    int rows = rowSet.count();
    int selectedObjRows = ui->tableWidgetSelectedObj->rowCount();
    ui->tableWidgetSelectedObj->setRowCount(ui->tableWidgetSelectedObj->rowCount() + rows);

    QList<int> rowList = rowSet.toList();
    for(int i=0; i<rowList.count(); i++) {
        int rowToCopy = rowList.at(i);
        QTableWidgetItem *itemSchema = ui->tableWidgetFoundObj->item(rowToCopy, 0)->clone();
        QTableWidgetItem *itemObject = ui->tableWidgetFoundObj->item(rowToCopy, 1)->clone();
        QTableWidgetItem *itemType = ui->tableWidgetFoundObj->item(rowToCopy, 2)->clone();

        ui->tableWidgetSelectedObj->setItem(selectedObjRows+i, 0, itemSchema);
        ui->tableWidgetSelectedObj->setItem(selectedObjRows+i, 1, itemObject);
        ui->tableWidgetSelectedObj->setItem(selectedObjRows+i, 2, itemType);
    }

    ui->tableWidgetSelectedObj->resizeColumnToContents(0);
    ui->tableWidgetSelectedObj->resizeColumnToContents(1);
    ui->tableWidgetSelectedObj->resizeRowsToContents();
    updateSelectedCount();
}

void KvExportObjects::on_actionRemove_from_Selected_triggered()
{
    QMap<int, int> selectedRowsMap;
    for(int i=0; i<ui->tableWidgetSelectedObj->selectedItems().count(); i++) {
        selectedRowsMap.insert(ui->tableWidgetSelectedObj->selectedItems().at(i)->row(), ui->tableWidgetSelectedObj->selectedItems().at(i)->row());
    }

    QList<int> selectedRowsOrderedList = selectedRowsMap.keys();
    for(int i=selectedRowsOrderedList.count()-1; i>=0; i--) {
        ui->tableWidgetSelectedObj->removeRow(selectedRowsOrderedList.at(i));
    }
    updateSelectedCount();
}

void KvExportObjects::on_actionClear_Selected_triggered()
{
    while(ui->tableWidgetSelectedObj->rowCount() > 0)
        ui->tableWidgetSelectedObj->removeRow(0);
    ui->tableWidgetSelectedObj->clearContents();
    updateSelectedCount();
}

void KvExportObjects::copySelectedToExportedWidget()
{
    while(ui->tableWidgetExportedObj->rowCount() > 0)
        ui->tableWidgetExportedObj->removeRow(0);
    ui->tableWidgetExportedObj->clearContents();

    int rows = ui->tableWidgetSelectedObj->rowCount();
    ui->tableWidgetExportedObj->setRowCount(rows);

    for(int r=0; r<rows; r++) {
        for(int c=0; c<ui->tableWidgetSelectedObj->columnCount(); c++) {
            QTableWidgetItem *selectedItem = ui->tableWidgetSelectedObj->item(r,c);
            QTableWidgetItem *item = selectedItem->clone();
            ui->tableWidgetExportedObj->setItem(r, c, item);
        }
    }

    ui->tableWidgetExportedObj->resizeColumnToContents(0);
    ui->tableWidgetExportedObj->resizeColumnToContents(1);
    ui->tableWidgetExportedObj->resizeRowsToContents();
}

void KvExportObjects::on_stackedWidgetExportObj_currentChanged(int index)
{
    if (index == 1) {
        generateOutputFileNames(ui->comboBoxOutputChoice->currentIndex());
    }
    else if (index == 2) {
        copySelectedToExportedWidget();
    }
}

void KvExportObjects::on_pushButtonCancel_clicked()
{
    parentWidget()->close();
}

void KvExportObjects::gotDdlFromObjectSlot(QString sessionName, QString schema, QString objectName, QString objectType, bool showSchema, QStringList result, KvSqlSession::DdlTypes ddlType)
{
    /*KvSqlObject sqlObj;
    sqlObj.schema = schema;
    sqlObj.object = objectName;
    sqlObj.type = objectType;*/

    int objectsToExportCount = ui->tableWidgetExportedObj->rowCount();
    QString itemType = QString();

    if ((ddlType == KvSqlSession::CompleteDdl) || (ddlType == KvSqlSession::PartialDdl)) {
        if (objectType == "TABLE")
            mapExportedTableObjectsDdl.insert(schema+"."+objectName+"."+objectType, result);
        else
            mapExportedOtherObjectsDdl.insert(schema+"."+objectName+"."+objectType, result);
    }
    else if (ddlType == KvSqlSession::ReferentialDdl) {
        mapExportedTablesReferentialDdl.insert(schema+"."+objectName+"."+objectType, result);
        itemType = "("+tr("Referential Constraints")+")";
    }
    else if (ddlType == KvSqlSession::PrivilegesDdl) {
        mapExportedAllPrivilegesDdl.insert(schema+"."+objectName+"."+objectType, result);
        itemType = "("+tr("Privileges")+")";
    }

    QList<QTableWidgetItem *> items = ui->tableWidgetExportedObj->findItems(objectName, Qt::MatchExactly);
    foreach(QTableWidgetItem *item, items) {
        int row = item->row();
        int rowCount = ui->tableWidgetExportedObj->rowCount();

        if ((ui->tableWidgetExportedObj->item(row, 0)->text() == schema) &&
                (ui->tableWidgetExportedObj->item(row, 1)->text() == objectName) &&
                (ui->tableWidgetExportedObj->item(row, 2)->text() == objectType)) {

            ui->tableWidgetExportedObj->selectRow(row);
            QString itemStatus = QString();
            if (ui->tableWidgetExportedObj->item(row, 3)->text().contains(tr("Generating DDL")))
                itemStatus = tr("DDL Generated");
            else {
                itemStatus = ui->tableWidgetExportedObj->item(row, 3)->text() + " " + itemType;
            }
            generatedRows++;
            ui->tableWidgetExportedObj->item(row, 3)->setText(itemStatus);
            ui->progressExportedObjects->setValue( (int)(90*(row+1))/rowCount );
            QCoreApplication::processEvents();
            ui->progressExportedObjects->update();
        }
    }

    ddlSignalsCount--;

    if ((ddlSignalsCount == 0) && (!isClosing)) {
        ui->progressExportedObjects->setValue(91);
        ui->progressExportedObjects->update();
        saveObjects();
        ui->pushButtonNextFinish->setText(tr("Export"));
        ui->pushButtonNextFinish->setEnabled(true);
        ui->pushButtonNextFinish->update();
    }
}

void KvExportObjects::saveObjects()
{
    if (ui->comboBoxOutputFormat->currentIndex() == 0) {
        int objectCount = 0;
        int oldValue = ui->progressExportedObjects->value();
        QString fileName = QString();
        // Save to only one file
        if (ui->tableWidgetOutputFiles->rowCount() == 1) {
            fileName = ui->lineEditOutputDir->text()+"/"+ui->tableWidgetOutputFiles->item(0,0)->text();
            QFile file(fileName);
            file.remove();
            if (file.open(QIODevice::ReadWrite | QIODevice::Text))  {
                QTextStream out(&file);
                // Partial Table DDL and Other Objects
                foreach(QString key, mapExportedTableObjectsDdl.keys()) {
                    QStringList values = mapExportedTableObjectsDdl.value(key);
                    foreach(QString value, values) {
                        out << value.remove('\n')+'\n';
                    }
                    out << '\n';
                    objectCount++;
                }
                ui->progressExportedObjects->setValue(93);
                ui->progressExportedObjects->update();

                // Table Referential Constraints DDL
                foreach(QString key, mapExportedTablesReferentialDdl.keys()) {
                    QStringList values = mapExportedTablesReferentialDdl.value(key);
                    foreach(QString value, values) {
                        out << value.remove('\n')+'\n';
                    }
                    out << '\n';
                }
                ui->progressExportedObjects->setValue(96);
                ui->progressExportedObjects->update();

                foreach(QString key, mapExportedOtherObjectsDdl.keys()) {
                    QStringList values = mapExportedOtherObjectsDdl.value(key);
                    foreach(QString value, values) {
                        out << value.remove('\n')+'\n';
                    }
                    out << '\n';
                    objectCount++;
                }
                ui->progressExportedObjects->setValue(99);
                ui->progressExportedObjects->update();

                // All Privileges DDL
                foreach(QString key, mapExportedAllPrivilegesDdl.keys()) {
                    QStringList values = mapExportedAllPrivilegesDdl.value(key);
                    foreach(QString value, values) {
                        out << value.remove('\n')+'\n';
                    }
                    out << '\n';
                }
                ui->progressExportedObjects->setValue(100);
                ui->progressExportedObjects->update();

                file.close();
            }
        }
    }
    else {
        QPrinter printer;
        QString fileName = QString();
        fileName = ui->lineEditOutputDir->text()+"/"+ui->tableWidgetOutputFiles->item(0,0)->text();
        //TODO: Put stuff to print in your 'document'

        outputDocument->clear();
        QTextFrameFormat frameFormat;
        frameFormat.setPageBreakPolicy(QTextFormat::PageBreak_AlwaysAfter);
        textCursor->currentFrame()->setFrameFormat(frameFormat);

        QFont font = QFont();
        font.setPixelSize(8);
        font.setFamily("Helvetica [Cronyx]");
        outputDocument->setDefaultFont(font);
        textCursor->movePosition(QTextCursor::NextWord, QTextCursor::MoveAnchor);

        font.setPixelSize(16);
        font.setBold(true);
        font.setFamily("Helvetica [Cronyx]");
        QTextCharFormat textCharFormat;
        textCharFormat.setFont(font);
        outputDocument->setDefaultFont(font);
        textCursor->insertText(tr("Data Dictionary"), textCharFormat);
        textCursor->insertText("\n\n");

        font.setBold(false);
        font.setPixelSize(8);
        font.setFamily("Helvetica [Cronyx]");
        outputDocument->setDefaultFont(font);

        /*QTextBlockFormat blockFormat;
        blockFormat.setPageBreakPolicy(QTextFormat::PageBreak_AlwaysAfter);
        textCursor->insertBlock(blockFormat);*/

        foreach(QString tableFullName, mapExportedTablesInfo.keys()) {
            KvTableInfo tableInfo = mapExportedTablesInfo.value(tableFullName);
            QList<KvColumnInfo> columnInfoList;
            QList<KvTableConstraintInfo> constraintInfoList;
            columnInfoList = mapExportedColumnsInfo.value(tableInfo.tableSchema+"."+tableInfo.tableName);
            constraintInfoList = mapExportedConstraintsInfo.value(tableInfo.tableSchema+"."+tableInfo.tableName);
            textCursor->movePosition(QTextCursor::NextBlock);

            QTextTableFormat tableFormat;

            tableFormat.setBorder(1);
            tableFormat.setCellPadding(2);
            tableFormat.setCellSpacing(0);
            tableFormat.setHeaderRowCount(3);
            tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
            tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));
            QVector<QTextLength> constraintVector = QVector<QTextLength>();
            constraintVector.append(QTextLength(QTextLength::VariableLength, 50));
            constraintVector.append(QTextLength(QTextLength::PercentageLength, 12));
            constraintVector.append(QTextLength(QTextLength::PercentageLength, 5));
            constraintVector.append(QTextLength(QTextLength::VariableLength, 50));
            tableFormat.setColumnWidthConstraints(constraintVector);

            QTextTable *textTable = textCursor->insertTable( columnInfoList.count() + 3, 5);
            textTable->setFormat(tableFormat);
            textTable->mergeCells ( 0, 0, 1, 5 );
            textTable->mergeCells ( 1, 0, 1, 5 );

            font.setBold(true);
            font.setPixelSize(8);
            QTextCharFormat textCharFormat;
            textCharFormat.setFont(font);

            textCursor->insertText(tr("TABLE")+": "+tableInfo.tableSchema+"."+tableInfo.tableName, textCharFormat);
            textCursor->movePosition(QTextCursor::NextCell);
            textCursor->insertText(tableInfo.tableComments);

            textCursor->movePosition(QTextCursor::NextCell);
            textCursor->insertText(tr("COLUMN"), textCharFormat);
            textCursor->movePosition(QTextCursor::NextCell);
            textCursor->insertText(tr("DATA TYPE"), textCharFormat);
            textCursor->movePosition(QTextCursor::NextCell);
            textCursor->insertText(tr("SIZE"), textCharFormat);
            textCursor->movePosition(QTextCursor::NextCell);
            textCursor->insertText(tr("OPTIONAL"), textCharFormat);
            textCursor->movePosition(QTextCursor::NextCell);
            textCursor->insertText(tr("COMMENTS"), textCharFormat);

            foreach(KvColumnInfo columnInfo, columnInfoList) {
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(columnInfo.columnName);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(columnInfo.columnType);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(columnInfo.columnSize);
                textCursor->movePosition(QTextCursor::NextCell);
                if (columnInfo.columnNullable)
                    textCursor->insertText("(*)");
                else
                    textCursor->insertText("");
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(columnInfo.columnComments);
            }

            textCursor->insertText("\n\n");
            textCursor->movePosition(QTextCursor::NextBlock);

            if (!constraintInfoList.isEmpty()) {

                QVector<QTextLength> constraintVector2 = QVector<QTextLength>();
                constraintVector2.append(QTextLength(QTextLength::PercentageLength, 10));
                constraintVector2.append(QTextLength(QTextLength::VariableLength, 10));
                constraintVector2.append(QTextLength(QTextLength::PercentageLength, 20));
                constraintVector2.append(QTextLength(QTextLength::PercentageLength, 20));
                constraintVector2.append(QTextLength(QTextLength::PercentageLength, 20));
                tableFormat.setColumnWidthConstraints(constraintVector2);

                QTextTable *textConstraintTable = textCursor->insertTable( constraintInfoList.count() + 3, 5);
                textConstraintTable->setFormat(tableFormat);
                textConstraintTable->mergeCells ( 0, 0, 1, 6 );
                textConstraintTable->mergeCells ( 1, 0, 2, 1 );
                textConstraintTable->mergeCells ( 1, 1, 2, 1 );
                textConstraintTable->mergeCells ( 1, 2, 2, 1 );
                textConstraintTable->mergeCells ( 1, 3, 1, 2 );

                textCursor->insertText(tr("KEYS OF")+" "+tableInfo.tableSchema+"."+tableInfo.tableName, textCharFormat);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(tr("KEY"), textCharFormat);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(tr("NAME"), textCharFormat);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(tr("COLUMNS"), textCharFormat);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(tr("REFERENCES"), textCharFormat);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(tr("TABLE"), textCharFormat);
                textCursor->movePosition(QTextCursor::NextCell);
                textCursor->insertText(tr("COLUMNS"), textCharFormat);

                font.setBold(false);
                font.setPixelSize(7);
                textCharFormat.setFont(font);

                // Write Constraints Information
                foreach(KvTableConstraintInfo constraintInfo, constraintInfoList) {
                    textCursor->movePosition(QTextCursor::NextCell);
                    QString constraintType = QString();
                    if (constraintInfo.constraintType.at(0)=='P')
                        constraintType = tr("PK");
                    else if (constraintInfo.constraintType.at(0)=='U')
                        constraintType = tr("UK");
                    else if (constraintInfo.constraintType.at(0)=='R')
                        constraintType = tr("FK");

                    textCursor->insertText(constraintType, textCharFormat);
                    textCursor->movePosition(QTextCursor::NextCell);
                    textCursor->insertText(constraintInfo.constraintName, textCharFormat);

                    textCursor->movePosition(QTextCursor::NextCell);
                    //qDebug() << constraintInfo.constraintColumns;
                    textCursor->insertText(constraintInfo.constraintColumns.join(", "), textCharFormat);

                    textCursor->movePosition(QTextCursor::NextCell);

                    if (! constraintInfo.constraintRefTable.isEmpty()) {
                        textCursor->insertText(constraintInfo.constraintRefOwner+"."+constraintInfo.constraintRefTable, textCharFormat);
                        textCursor->movePosition(QTextCursor::NextCell);
                        textCursor->insertText(constraintInfo.constraintRefColumns.join(", "), textCharFormat);
                    }
                    else {
                        textCursor->insertText("");
                        textCursor->movePosition(QTextCursor::NextCell);
                        textCursor->insertText("");
                    }
                }
            }

            textCursor->movePosition(QTextCursor::NextBlock);
            textCursor->insertText("\n\n");

//            QTextBlockFormat blockFormat;
//            blockFormat.setPageBreakPolicy(QTextFormat::PageBreak_AlwaysAfter);
//            textCursor->insertBlock(blockFormat);
        }

        if (ui->comboBoxOutputFormat->currentIndex() == 1) {
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);
            outputDocument->print( &printer );
        }
        else {
            QTextDocumentWriter writer(fileName);
            writer.setFormat("odf");
            writer.write(outputDocument);
        }

        ui->progressExportedObjects->setValue(100);
        ui->progressExportedObjects->update();
    }
}

void KvExportObjects::exportObjects()
{
    if (hasOpenConnection) {
        mapExportedTableObjectsDdl.clear();
        mapExportedOtherObjectsDdl.clear();
        mapExportedTablesReferentialDdl.clear();
        mapExportedAllPrivilegesDdl.clear();

        ddlSignalsCount = -1;
        tableColumnsSignalsCount = -1;
        generatedRows = 0;
        foreach(QString objType, databaseObjTypeOrder) {
            if ((ddlSignalsCount != 0) && (!isClosing)) {
                for(int r = 0; r < ui->tableWidgetExportedObj->rowCount(); r++) {
                    if (ui->tableWidgetExportedObj->item(r, 2)->text() == objType) {
                        QString objSchema = ui->tableWidgetExportedObj->item(r, 0)->text();
                        QString objName = ui->tableWidgetExportedObj->item(r, 1)->text();
                        QString objType = ui->tableWidgetExportedObj->item(r, 2)->text();
                        QTableWidgetItem *statusItem;

                        if (ui->comboBoxOutputFormat->currentIndex() == 0)
                            statusItem = new QTableWidgetItem(tr("Generating DDL")+"...");
                        else
                            statusItem = new QTableWidgetItem(tr("Collecting Information")+"...");

                        ui->tableWidgetExportedObj->setItem(r, 3, statusItem);

                        if (ui->comboBoxOutputFormat->currentIndex() == 0) {
                            if (objType.compare("TABLE", Qt::CaseInsensitive)==0) {
                                emit getDdlFromObjectSignal(objSchema, objName, objType, true, KvSqlSession::PartialDdl);
                                emit getDdlFromObjectSignal(objSchema, objName, objType, true, KvSqlSession::ReferentialDdl);
                                emit getDdlFromObjectSignal(objSchema, objName, objType, true, KvSqlSession::PrivilegesDdl);

                                if (ddlSignalsCount < 0)
                                    ddlSignalsCount = 3;
                                else
                                    ddlSignalsCount+=3;
                            }

                            else {
                                emit getDdlFromObjectSignal(objSchema, objName, objType, true, KvSqlSession::CompleteDdl);

                                if (ddlSignalsCount < 0)
                                    ddlSignalsCount = 1;
                                else
                                    ddlSignalsCount++;
                            }
                        }
                        else {
                            if (objType.compare("TABLE", Qt::CaseInsensitive)==0) {
                                // TODO: emit signals to get Table and Columns definitions...
                                emit getTableAndColumnsInfoSignal(objSchema, objName);

                            }
                        }
                    }
                }
            }
            else
                break;
        }
    }
}

void KvExportObjects::on_actionExport_Objects_triggered()
{
    QString originalText = ui->pushButtonNextFinish->text();
    ui->pushButtonNextFinish->setText(tr("Exporting..."));
    ui->pushButtonNextFinish->setEnabled(false);
    ui->pushButtonNextFinish->update();

    exportObjects();

    /*for(int i=0; i<=100; i++) {
        ui->progressExportedObjects->setValue(i);
    }*/
}

void KvExportObjects::on_actionSet_Default_Only_One_triggered()
{
    bool inputAccepted;
    QString defaultFileName = QInputDialog::getText(this, tr("Default name for only one file output"),
                                                    tr("File name")+":", QLineEdit::Normal, "", &inputAccepted);
    if (inputAccepted && !defaultFileName.isEmpty()) {

    }
}


void KvExportObjects::on_actionAdd_All_Objects_to_Selected_triggered()
{
    ui->tableWidgetFoundObj->selectAll();
    ui->actionAdd_Objects_to_Selected->trigger();
}

void KvExportObjects::updateSelectedCount()
{
    if (ui->tableWidgetSelectedObj->rowCount() > 1)
        ui->labelSelectedCount->setText(QString::number(ui->tableWidgetSelectedObj->rowCount())+" "+tr("Selected Objects"));
    else
        ui->labelSelectedCount->setText(QString::number(ui->tableWidgetSelectedObj->rowCount())+" "+tr("Selected Object"));
}

void KvExportObjects::generateOutputFileNames(int index)
{
    QString fileExtension;
    if (ui->comboBoxOutputFormat->currentIndex() == 0)
        fileExtension = ".sql";
    else if (ui->comboBoxOutputFormat->currentIndex() == 1)
        fileExtension = ".pdf";
    else if (ui->comboBoxOutputFormat->currentIndex() == 2)
        fileExtension = ".odt";

    while(ui->tableWidgetOutputFiles->rowCount() > 0)
        ui->tableWidgetOutputFiles->removeRow(0);
    ui->tableWidgetOutputFiles->clearContents();
    if (index == 0) {
        // Output to only one file
        ui->tableWidgetOutputFiles->setRowCount(1);
        QTableWidgetItem *oneFilenameItem = new QTableWidgetItem(QString("export_script"+fileExtension));
        ui->tableWidgetOutputFiles->setItem(0, 0, oneFilenameItem);
        QTableWidgetItem *oneDescriptionItem = new QTableWidgetItem(tr("Only One Export Objects Script File"));
        ui->tableWidgetOutputFiles->setItem(0, 1, oneDescriptionItem);
    }
    else if (index == 1) {
        // Output to some files for each object type
        QSet<QString> objectTypes = QSet<QString>();
        int insertedRows = 0;
        for(int r=0; r<ui->tableWidgetSelectedObj->rowCount(); r++) {
            QTableWidgetItem *selectedSchemaItem = ui->tableWidgetSelectedObj->item(r,0);
            QTableWidgetItem *selectedObjectItem = ui->tableWidgetSelectedObj->item(r,1);
            QTableWidgetItem *selectedTypeItem = ui->tableWidgetSelectedObj->item(r,2);

            if (selectedTypeItem->text().compare("TABLE", Qt::CaseInsensitive) == 0) {
                if (!objectTypes.contains(selectedTypeItem->text())) {
                    objectTypes.insert(selectedTypeItem->text());
                    ui->tableWidgetOutputFiles->insertRow(insertedRows);
                    insertedRows++;
                    // A filename for Table Initial DDL
                    QTableWidgetItem *filenameItem = new QTableWidgetItem("export_table"+fileExtension);
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameItem);
                    QTableWidgetItem *descriptionItem = new QTableWidgetItem(tr("Objects")+" "+"TABLE");
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionItem);

                    ui->tableWidgetOutputFiles->insertRow(insertedRows);
                    insertedRows++;
                    // A filename for Table Constraints DDL
                    QTableWidgetItem *filenameConstraintsItem = new QTableWidgetItem("export_constraint"+fileExtension);
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameConstraintsItem);
                    QTableWidgetItem *descriptionConstraintsItem = new QTableWidgetItem(tr("Objects")+" "+"CONSTRAINT");
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionConstraintsItem);

                    ui->tableWidgetOutputFiles->insertRow(insertedRows);
                    insertedRows++;
                    // A filename for Table Indexes DDL
                    QTableWidgetItem *filenameIndexesItem = new QTableWidgetItem("export_index"+fileExtension);
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameIndexesItem);
                    QTableWidgetItem *descriptionIndexesItem = new QTableWidgetItem(tr("Objects")+" "+"INDEX");
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionIndexesItem);
                }
            }
            else {
                if (!objectTypes.contains(selectedTypeItem->text())) {
                    objectTypes.insert(selectedTypeItem->text());
                    ui->tableWidgetOutputFiles->insertRow(insertedRows);
                    insertedRows++;
                    // A filename for Object DDL
                    QTableWidgetItem *filenameItem = new QTableWidgetItem("export_"+selectedTypeItem->text().toLower().replace(" ","_")+fileExtension);
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameItem);
                    QTableWidgetItem *descriptionItem = new QTableWidgetItem(tr("Objects")+" "+selectedTypeItem->text());
                    ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionItem);
                }
            }
        }
        if (ui->tableWidgetSelectedObj->rowCount() > 0) {
            ui->tableWidgetOutputFiles->insertRow(insertedRows);
            insertedRows++;
            // A filename for Table Indexes DDL
            QTableWidgetItem *filenameIndexesItem = new QTableWidgetItem("export_privilege"+fileExtension);
            ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameIndexesItem);
            QTableWidgetItem *descriptionIndexesItem = new QTableWidgetItem(tr("Objects")+" "+"PRIVILEGE");
            ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionIndexesItem);

            insertedRows = ui->tableWidgetOutputFiles->rowCount();
            ui->tableWidgetOutputFiles->insertRow(insertedRows);
            int lastIndex = insertedRows;
            QTableWidgetItem *lastFilenameItem = new QTableWidgetItem(QString("export_script"+fileExtension));
            ui->tableWidgetOutputFiles->setItem(lastIndex, 0, lastFilenameItem);
            QTableWidgetItem *lastDescriptionItem = new QTableWidgetItem(tr("File which calls all other files"));
            ui->tableWidgetOutputFiles->setItem(lastIndex, 1, lastDescriptionItem);
        }
    }
    else if (index == 2) {
        // Output to some files for each object
        int insertedRows = 0;
        for(int r=0; r<ui->tableWidgetSelectedObj->rowCount(); r++) {
            QTableWidgetItem *selectedSchemaItem = ui->tableWidgetSelectedObj->item(r,0);
            QTableWidgetItem *selectedObjectItem = ui->tableWidgetSelectedObj->item(r,1);
            QTableWidgetItem *selectedTypeItem = ui->tableWidgetSelectedObj->item(r,2);
            // Naming the file for the selected object

            if (selectedTypeItem->text().compare("TABLE", Qt::CaseInsensitive) == 0) {
                ui->tableWidgetOutputFiles->insertRow(insertedRows);
                insertedRows++;
                // A filename for Table Initial DDL
                QTableWidgetItem *filenameItem = new QTableWidgetItem(selectedSchemaItem->text()+"_"+selectedObjectItem->text()+"."+selectedTypeItem->text().toLower()+fileExtension);
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameItem);
                QTableWidgetItem *descriptionItem = new QTableWidgetItem(tr("Object")+" "+selectedSchemaItem->text()+"."+selectedObjectItem->text()+" ("+selectedTypeItem->text()+")");
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionItem);

                ui->tableWidgetOutputFiles->insertRow(insertedRows);
                insertedRows++;
                // A filename for Table Constraints DDL
                QTableWidgetItem *filenameConstraintsItem = new QTableWidgetItem(selectedSchemaItem->text()+"_"+selectedObjectItem->text()+"."+selectedTypeItem->text().toLower()+"_cnstr"+fileExtension);
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameConstraintsItem);
                QTableWidgetItem *descriptionConstraintsItem = new QTableWidgetItem(tr("Object")+" "+selectedSchemaItem->text()+"."+selectedObjectItem->text()+" ("+selectedTypeItem->text()+" CONSTRAINTS)");
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionConstraintsItem);

                ui->tableWidgetOutputFiles->insertRow(insertedRows);
                insertedRows++;
                // A filename for Table Indexes DDL
                QTableWidgetItem *filenameIndexesItem = new QTableWidgetItem(selectedSchemaItem->text()+"_"+selectedObjectItem->text()+"."+selectedTypeItem->text().toLower()+"_indx"+fileExtension);
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameIndexesItem);
                QTableWidgetItem *descriptionIndexesItem = new QTableWidgetItem(tr("Object")+" "+selectedSchemaItem->text()+"."+selectedObjectItem->text()+" ("+selectedTypeItem->text()+" INDEXES)");
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionIndexesItem);

                ui->tableWidgetOutputFiles->insertRow(insertedRows);
                insertedRows++;
                // A filename for Table Privileges DDL
                QTableWidgetItem *filenamePrivilegesItem = new QTableWidgetItem(selectedSchemaItem->text()+"_"+selectedObjectItem->text()+"."+selectedTypeItem->text().toLower()+"_prv"+fileExtension);
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenamePrivilegesItem);
                QTableWidgetItem *descriptionPrivilegesItem = new QTableWidgetItem(tr("Object")+" "+selectedSchemaItem->text()+"."+selectedObjectItem->text()+" ("+selectedTypeItem->text()+" PRIVILEGES)");
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionPrivilegesItem);

            }
            else {
                ui->tableWidgetOutputFiles->insertRow(insertedRows);
                insertedRows = ui->tableWidgetOutputFiles->rowCount();
                // A filename for Object DDL
                QTableWidgetItem *filenameItem = new QTableWidgetItem(selectedSchemaItem->text()+"_"+selectedObjectItem->text()+"."+selectedTypeItem->text().toLower().replace(" ","_")+fileExtension);
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 0, filenameItem);
                QTableWidgetItem *descriptionItem = new QTableWidgetItem(tr("Object")+" "+selectedSchemaItem->text()+"."+selectedObjectItem->text()+" ("+selectedTypeItem->text()+")");
                ui->tableWidgetOutputFiles->setItem(insertedRows-1, 1, descriptionItem);
            }
        }
        insertedRows = ui->tableWidgetOutputFiles->rowCount();
        ui->tableWidgetOutputFiles->insertRow(insertedRows);
        int lastIndex = insertedRows;
        QTableWidgetItem *lastFilenameItem = new QTableWidgetItem(QString("export_script"+fileExtension));
        ui->tableWidgetOutputFiles->setItem(lastIndex, 0, lastFilenameItem);
        QTableWidgetItem *lastDescriptionItem = new QTableWidgetItem(tr("File which calls all other files"));
        ui->tableWidgetOutputFiles->setItem(lastIndex, 1, lastDescriptionItem);
    }
    ui->tableWidgetOutputFiles->resizeColumnToContents(0);
    ui->tableWidgetOutputFiles->resizeRowsToContents();
}

void KvExportObjects::on_comboBoxOutputChoice_currentIndexChanged(int index)
{
    generateOutputFileNames(index);
}

void KvExportObjects::gotDatabaseObjectTypesSlot(QStringList objTypeNames, QStringList objTypeOrder)
{
    KvSqlDialog::gotDatabaseObjectTypesSlot(objTypeNames, objTypeOrder);
    ui->comboBoxTypeNames->addItems(databaseObjTypeNames);
    enableSearchWidgets( true );
    ui->widgetProgress->stop();
    ui->widgetProgress->hide();
}

void KvExportObjects::setOutputOptions()
{
    QString outputType = ui->comboBoxOutputChoice->currentText();
    QString outputFormat = ui->comboBoxOutputFormat->currentText();
    ui->lineEditOutputDirFinal->setText(ui->lineEditOutputDir->text());
    ui->labelOutputType->setText(outputType+" ( "+tr("Output Format")+" "+outputFormat+" )");
}


void KvExportObjects::on_comboBoxOutputFormat_activated(int index)
{
    if (index == 0) {
        ui->comboBoxOutputChoice->clear();
        ui->comboBoxOutputChoice->addItem(tr("Only One Output File"));
        ui->comboBoxOutputChoice->addItem(tr("One File for each Object Type"));
        ui->comboBoxOutputChoice->addItem(tr("One File for each Object"));
    }
    else if ((index == 1)||(index == 2)) {
        ui->comboBoxOutputChoice->clear();
        ui->comboBoxOutputChoice->addItem(tr("Only One Output File"));
    }
}

void KvExportObjects::gotTableAndColumnsInfoSlot(QString objSchema, QString objTable, KvTableInfo tableInfo, QList<KvColumnInfo> columns, QList<KvTableConstraintInfo> constraints)
{
    //QTextTable *textTable = textCursor->insertTable(5, 4);
    if (tableColumnsSignalsCount < 0)
        tableColumnsSignalsCount = 1;
    else
        tableColumnsSignalsCount++;

    mapExportedTablesInfo.insert(tableInfo.tableSchema+"."+tableInfo.tableName, tableInfo);
    mapExportedColumnsInfo.insert(tableInfo.tableSchema+"."+tableInfo.tableName, columns);
    mapExportedConstraintsInfo.insert(tableInfo.tableSchema+"."+tableInfo.tableName, constraints);

    int rowCount = ui->tableWidgetExportedObj->rowCount();

    QList<QTableWidgetItem *> tableWidgetItems = ui->tableWidgetExportedObj->findItems(objTable, Qt::MatchExactly);
    foreach (QTableWidgetItem *item, tableWidgetItems) {
        if (ui->tableWidgetExportedObj->item(item->row(), 0)->text() == objSchema)
            ui->tableWidgetExportedObj->item(item->row(), 3)->setText(tr("Collected"));

        ui->progressExportedObjects->setValue( (int)(90*(item->row()+1))/rowCount );
        ui->progressExportedObjects->update();
    }

    if ((tableColumnsSignalsCount >= ui->tableWidgetExportedObj->rowCount()) && (!isClosing)) {
        saveObjects();
        ui->progressExportedObjects->setValue(100);
        ui->progressExportedObjects->update();
        ui->pushButtonNextFinish->setText(tr("Export"));
        ui->pushButtonNextFinish->setEnabled(true);
        ui->pushButtonNextFinish->update();
    }
}
