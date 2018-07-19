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

#include "kvsettingsdialog.h"
#include "ui_kvsettingsdialog.h"


KvSettingsDialog::KvSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KvSettingsDialog)
{
    ui->setupUi(this);    
    ui->retranslateUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->settingsListWidget->setCurrentRow(0);
    availableDrivers.append(KvDbUtil::getActiveDrivers());
    updateDriversCombos();
    connect(this, SIGNAL(needsToSaveSettings()), this, SLOT(setNeedToSaveSettings()));
    loadStylesCombo();
    fontsForEditorTokens = QList<QFont>();
    textColorsForEditorTokens = QList<QColor>();
    backgroundColorsForEditorTokens = QList<QColor>();
    colorSchemes = QMap<QString, KvColorScheme>();

    loadSettings();
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setDisabled(true);
    ui->settingsListWidget->item(0)->setSelected(true);

}

KvSettingsDialog::~KvSettingsDialog()
{
    delete ui;
}

void KvSettingsDialog::loadSettings()
{
    guiStyle = KvSettings::getDefaultGUIStyle();
    connectionsFilePath = KvSettings::getDefaultConnectionsPath();
    ui->lineEditConnectionsFilePath->setText(connectionsFilePath);
    m_changedConnectionsFileDir = false;
    languageFilesPath = KvSettings::getDefaultTranslationsPath();
    ui->lineEditLangPath->setText(languageFilesPath);
    languageCode = KvSettings::getDefaultLanguageCode();
    int langIndex = ui->langComboBox->findText("("+languageCode+")", Qt::MatchContains);
    if (langIndex < 0)
        langIndex = ui->langComboBox->findText("(en)");
    ui->langComboBox->setCurrentIndex(langIndex);
    workFilesPath = KvSettings::getDefaultWorkPath();
    ui->lineEditWorkPath->setText(workFilesPath);

    QFont guiFont = KvSettings::getGUIFont();
    QFont editorFont = KvSettings::getEditorFont();
    ui->fontComboBoxGeneral->setCurrentFont(guiFont);
    ui->spinBoxSizeGeneral->setValue(guiFont.pointSize());
    ui->checkBoxAntialiasGeneral->setChecked(guiFont.styleStrategy() == QFont::PreferAntialias);
    ui->fontComboBoxEditor->setCurrentFont(editorFont);
    ui->spinBoxSizeEditor->setValue(editorFont.pointSize());
    ui->checkBoxAntialiasEditor->setChecked(editorFont.styleStrategy() == QFont::PreferAntialias);


    loadColorSchemes();
    ui->comboBoxColorScheme->clear();
    ui->comboBoxColorScheme->addItems(colorSchemes.keys());
    ui->comboBoxColorScheme->setCurrentIndex(ui->comboBoxColorScheme->findText(KvSettings::getCurrentColorSchemeName()));

    KvColorScheme currentColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
    for(int i=0; i<currentColorScheme.fonts.size(); i++) {
        ui->tableWidgetColorScheme->item(i,0)->setFont(currentColorScheme.fonts.at(i));
        ui->tableWidgetColorScheme->item(i,0)->setForeground(currentColorScheme.textColors.at(i));
        ui->tableWidgetColorScheme->item(i,0)->setBackground(currentColorScheme.backgroundColors.at(i));
    }
}

void KvSettingsDialog::loadStylesCombo() {    
    QStringList stylesList;
    foreach(QString key, QStyleFactory::keys())
        stylesList << key;
    stylesList.sort();
    ui->comboBoxGuiStyle->insertItems(0, stylesList);
    guiStyle = KvSettings::getDefaultGUIStyle();
    ui->comboBoxGuiStyle->setCurrentIndex( stylesList.indexOf( QRegExp( guiStyle, Qt::CaseInsensitive) ) );
    ui->treeWidgetConnSample->expandAll();
    ui->treeWidgetConnSample->resizeColumnToContents(0);
}

void KvSettingsDialog::enableConnectionsFileDirAlert(bool enable)
{
    ui->lineEditConnectionsFilePath->setEnabled(!enable);
    ui->connDirButton->setEnabled(!enable);
    if (enable) {
        ui->widgetConnFileAlert->setStyleSheet("QWidget { background: url(:/png/png_general/error.png); background-repeat: no; background-attachment: fixed; }");
        ui->widgetConnFileAlert->setToolTip(tr("You must close all sessions before changing this directory.")+'\n'+tr("Current connections file is in use."));
        ui->widgetConnFileAlert->setFocus();
    }
    else {
        ui->widgetConnFileAlert->setStyleSheet("");
        ui->widgetConnFileAlert->setToolTip("");
    }
}

void KvSettingsDialog::setNeedToSaveSettings()
{
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(true);
}

QString KvSettingsDialog::extractLanguageCode(QString languageName)
{
    QString langCode = languageName.mid(languageName.indexOf("(")+1, (languageName.indexOf(")")-languageName.indexOf("("))-1);
    return langCode;
}

void KvSettingsDialog::loadLanguage()
{
    QTranslator qtTranslator, kvTranslator;
    QString qmPath = qApp->applicationDirPath() + "/translations";
    kvTranslator.load("kevora_pt_BR.qm", qmPath);
    qtTranslator.load("qt_pt_BR.qm", qmPath);
    QApplication::installTranslator(&kvTranslator);
    QApplication::installTranslator(&qtTranslator);
    ui->retranslateUi(this);
}

void KvSettingsDialog::loadColorSchemes()
{
    colorSchemes = KvSettings::restoreColorSchemes();
}

void KvSettingsDialog::changeEvent(QEvent *e)
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

void KvSettingsDialog::updateDriversCombos()
{
    QStringList firebirdDrivers = KvDbUtil::driversForDatabase("Firebird");
    for (int d=0; d<firebirdDrivers.size(); d++) {
        if (availableDrivers.contains(firebirdDrivers.at(d))) {
            ui->prefDrvFirebirdComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_success.png"), firebirdDrivers.at(d), tr("Available"));
            ui->prefDrvFirebirdComboBox->setToolTip(tr("Available Driver"));
        }
        else {
            ui->prefDrvFirebirdComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_fail.png"), firebirdDrivers.at(d), tr("Not Available"));
            ui->prefDrvFirebirdComboBox->setToolTip(tr("Not Available Driver"));
        }
    }
    QStringList mysqlDrivers = KvDbUtil::driversForDatabase("MySql");
    for (int d=0; d<mysqlDrivers.size(); d++) {
        if (availableDrivers.contains(mysqlDrivers.at(d))) {
            ui->prefDrvMySqlComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_success.png"), mysqlDrivers.at(d), tr("Available"));
            ui->prefDrvMySqlComboBox->setToolTip(tr("Available Driver"));
        }
        else {
            ui->prefDrvMySqlComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_fail.png"), mysqlDrivers.at(d), tr("Not Available"));
            ui->prefDrvMySqlComboBox->setToolTip(tr("Not Available Driver"));
        }
    }
    QStringList odbcDrivers = KvDbUtil::driversForDatabase("ODBC");
    for (int d=0; d<odbcDrivers.size(); d++) {
        if (availableDrivers.contains(odbcDrivers.at(d))) {
            ui->prefDrvODBCComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_success.png"), odbcDrivers.at(d), tr("Available"));
            ui->prefDrvODBCComboBox->setToolTip(tr("Available Driver"));
        }
        else {
            ui->prefDrvODBCComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_fail.png"), odbcDrivers.at(d), tr("Not Available"));
            ui->prefDrvODBCComboBox->setToolTip(tr("Not Available Driver"));
        }
    }
    QStringList oracleDrivers = KvDbUtil::driversForDatabase("Oracle");
    for (int d=0; d<oracleDrivers.size(); d++) {
        if (availableDrivers.contains(oracleDrivers.at(d))) {
            ui->prefDrvOracleComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_success.png"), oracleDrivers.at(d), tr("Available"));
            ui->prefDrvOracleComboBox->setToolTip(tr("Available Driver"));
        }
        else {
            ui->prefDrvOracleComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_fail.png"), oracleDrivers.at(d), tr("Not Available"));
            ui->prefDrvOracleComboBox->setToolTip(tr("Not Available Driver"));
        }
    }
    QStringList postgresqlDrivers = KvDbUtil::driversForDatabase("PostgreSql");
    for (int d=0; d<postgresqlDrivers.size(); d++) {
        if (availableDrivers.contains(postgresqlDrivers.at(d))) {
            ui->prefDrvPostgreSqlComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_success.png"), postgresqlDrivers.at(d), tr("Available"));
            ui->prefDrvPostgreSqlComboBox->setToolTip(tr("Available Driver"));
        }
        else {
            ui->prefDrvPostgreSqlComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_fail.png"), postgresqlDrivers.at(d), tr("Not Available"));
            ui->prefDrvPostgreSqlComboBox->setToolTip(tr("Not Available Driver"));
        }
    }
    QStringList sqliteDrivers = KvDbUtil::driversForDatabase("Sqlite");
    for (int d=0; d<sqliteDrivers.size(); d++) {
        if (availableDrivers.contains(sqliteDrivers.at(d))) {
            ui->prefDrvSqliteComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_success.png"), sqliteDrivers.at(d), tr("Available"));
            ui->prefDrvSqliteComboBox->setToolTip(tr("Available Driver"));
        }
        else {
            ui->prefDrvSqliteComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_fail.png"), sqliteDrivers.at(d), tr("Not Available"));
            ui->prefDrvSqliteComboBox->setToolTip(tr("Not Available Driver"));
        }
    }
    QStringList cubridDrivers = KvDbUtil::driversForDatabase("Cubrid");
    for (int d=0; d<cubridDrivers.size(); d++) {
        if (availableDrivers.contains(cubridDrivers.at(d))) {
            ui->prefDrvCubridComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_success.png"), cubridDrivers.at(d), tr("Available"));
            ui->prefDrvCubridComboBox->setToolTip(tr("Available Driver"));
        }
        else {
            ui->prefDrvCubridComboBox->addItem(QIcon(":/png/png_sqlwindow/agt_action_fail.png"), cubridDrivers.at(d), tr("Not Available"));
            ui->prefDrvCubridComboBox->setToolTip(tr("Not Available Driver"));
        }
    }
}

void KvSettingsDialog::on_prefDrvFirebirdComboBox_currentIndexChanged(int index)
{
    ui->prefDrvFirebirdComboBox->setToolTip(ui->prefDrvFirebirdComboBox->itemData(index).toString());
}

void KvSettingsDialog::on_prefDrvMySqlComboBox_currentIndexChanged(int index)
{
    //ui->mysqlDrvStatusLabel->setText(ui->prefDrvMySqlComboBox->itemData(index).toString());
    ui->prefDrvMySqlComboBox->setToolTip(ui->prefDrvMySqlComboBox->itemData(index).toString());
}

void KvSettingsDialog::on_prefDrvODBCComboBox_currentIndexChanged(int index)
{
    //ui->odbcDrvStatusLabel->setText(ui->prefDrvODBCComboBox->itemData(index).toString());
    ui->prefDrvODBCComboBox->setToolTip(ui->prefDrvODBCComboBox->itemData(index).toString());
}

void KvSettingsDialog::on_prefDrvOracleComboBox_currentIndexChanged(int index)
{
    //ui->oracleDrvStatusLabel->setText(ui->prefDrvOracleComboBox->itemData(index).toString());
    ui->prefDrvOracleComboBox->setToolTip(ui->prefDrvOracleComboBox->itemData(index).toString());
}

void KvSettingsDialog::on_prefDrvPostgreSqlComboBox_currentIndexChanged(int index)
{
    //ui->postgresqlDrvStatusLabel->setText(ui->prefDrvPostgreSqlComboBox->itemData(index).toString());
    ui->prefDrvPostgreSqlComboBox->setToolTip(ui->prefDrvPostgreSqlComboBox->itemData(index).toString());
}

void KvSettingsDialog::on_prefDrvSqliteComboBox_currentIndexChanged(int index)
{
    ui->prefDrvSqliteComboBox->setToolTip(ui->prefDrvSqliteComboBox->itemData(index).toString());
}

void KvSettingsDialog::on_prefDrvCubridComboBox_currentIndexChanged(int index)
{
    ui->prefDrvCubridComboBox->setToolTip(ui->prefDrvCubridComboBox->itemData(index).toString());
}

void KvSettingsDialog::on_firebirdDrvInfoButton_clicked()
{
    QString driverStatus = ui->prefDrvFirebirdComboBox->itemData(ui->prefDrvFirebirdComboBox->currentIndex()).toString();
    QMessageBox::information(this, tr("Driver Details")+" "+"("+driverStatus+")",
                             KvSqlSessionFirebird::getDriverComments(ui->prefDrvFirebirdComboBox->currentText()));
}

void KvSettingsDialog::on_mysqlDrvInfoButton_clicked()
{
    QString driverStatus = ui->prefDrvMySqlComboBox->itemData(ui->prefDrvMySqlComboBox->currentIndex()).toString();
    QMessageBox::information(this, tr("Driver Details")+" "+"("+driverStatus+")",
                             KvSqlSessionMySql::getDriverComments(ui->prefDrvMySqlComboBox->currentText()));
}

void KvSettingsDialog::on_odbcDrvInfoButton_clicked()
{
    /*QString driverStatus = ui->prefDrvODBCComboBox->itemData(ui->prefDrvODBCComboBox->currentIndex()).toString();
    QMessageBox::information(this, tr("Driver Details")+" "+"("+driverStatus+")",
                             KvSqlSessionODB::getDriverComments(ui->prefDrvODBCComboBox->currentText())); */
}

void KvSettingsDialog::on_oracleDrvInfoButton_clicked()
{
    QString driverStatus = ui->prefDrvOracleComboBox->itemData(ui->prefDrvOracleComboBox->currentIndex()).toString();
    QMessageBox::information(this, tr("Driver Details")+" "+"("+driverStatus+")",
                             KvSqlSessionOracle::getDriverComments(ui->prefDrvOracleComboBox->currentText()));
}

void KvSettingsDialog::on_postgresqlDrvInfoButton_clicked()
{
    QString driverStatus = ui->prefDrvPostgreSqlComboBox->itemData(ui->prefDrvPostgreSqlComboBox->currentIndex()).toString();
    QMessageBox::information(this, tr("Driver Details")+" "+"("+driverStatus+")",
                             KvSqlSessionPostgreSql::getDriverComments(ui->prefDrvPostgreSqlComboBox->currentText()));
}

void KvSettingsDialog::on_sqliteDrvInfoButton_clicked()
{
    QString driverStatus = ui->prefDrvSqliteComboBox->itemData(ui->prefDrvSqliteComboBox->currentIndex()).toString();
    QMessageBox::information(this, tr("Driver Details")+" "+"("+driverStatus+")",
                             KvSqlSessionSqlite::getDriverComments(ui->prefDrvSqliteComboBox->currentText()));
}

void KvSettingsDialog::on_cubridDrvInfoButton_clicked()
{
    QString driverStatus = ui->prefDrvCubridComboBox->itemData(ui->prefDrvCubridComboBox->currentIndex()).toString();
    QMessageBox::information(this, tr("Driver Details")+" "+"("+driverStatus+")",
                             KvSqlSessionCubrid::getDriverComments(ui->prefDrvCubridComboBox->currentText()));
}

void KvSettingsDialog::setLanguage(QString langCode)
{
    if ( (! langCode.isEmpty() ) && (! langCode.compare(languageCode) == 0) ) {
        emit needsToSaveSettings();
        QMessageBox::information(this, tr("Language Update"), tr("Kevora will be translated next time you start it."));
    }
}

void KvSettingsDialog::on_langDirButton_clicked()
{
    if (languageFilesPath.isEmpty())
        languageFilesPath = QCoreApplication::applicationDirPath()+"/translations";

    languageFilesPath = QFileDialog::getExistingDirectory(this, tr("Select Language Files Directory"), languageFilesPath, QFileDialog::ShowDirsOnly|QFileDialog::DontUseNativeDialog);

    if (! languageFilesPath.isEmpty())
        ui->lineEditLangPath->setText(languageFilesPath);
}

void KvSettingsDialog::on_langComboBox_activated(QString text)
{
    QString langCode = text.mid(text.indexOf("(") + 1, text.indexOf(")") - text.indexOf("(") - 1);
    setLanguage(langCode);
}

void KvSettingsDialog::on_lineEditLangPath_textChanged(QString text)
{
    QDir langDir(text);
    if ((! text.isEmpty()) && (langDir.exists()))
        ui->langComboBox->setEnabled(true);
    else
        ui->langComboBox->setEnabled(false);

    emit needsToSaveSettings();
}

void KvSettingsDialog::on_connDirButton_clicked()
{
    if (connectionsFilePath.isEmpty())
        connectionsFilePath = QCoreApplication::applicationDirPath();

    QString oldConnectionsFilePath = connectionsFilePath;
    connectionsFilePath = QFileDialog::getExistingDirectory(this, tr("Select Connections File Directory"), connectionsFilePath, QFileDialog::ShowDirsOnly|QFileDialog::DontUseNativeDialog);

    if (connectionsFilePath.trimmed().simplified().isEmpty())
        connectionsFilePath = oldConnectionsFilePath;

    ui->lineEditConnectionsFilePath->setText(connectionsFilePath);

    if (oldConnectionsFilePath.compare(connectionsFilePath, Qt::CaseSensitive) == 0)
        m_changedConnectionsFileDir = false;
    else
        m_changedConnectionsFileDir = true;
}

void KvSettingsDialog::on_workDirButton_clicked()
{
    if (workFilesPath.isEmpty())
        workFilesPath = QCoreApplication::applicationDirPath();

    QString oldWorkFilesPath = workFilesPath;
    workFilesPath = QFileDialog::getExistingDirectory(this, tr("Select Work Files Directory"), workFilesPath, QFileDialog::ShowDirsOnly|QFileDialog::DontUseNativeDialog);

    if (workFilesPath.trimmed().simplified().isEmpty())
        workFilesPath = oldWorkFilesPath;

    ui->lineEditWorkPath->setText(workFilesPath);
}

void KvSettingsDialog::on_comboBoxGuiStyle_currentIndexChanged(QString currentText)
{
    guiStyle = currentText;
    ui->treeWidgetConnSample->setStyle(QStyleFactory::create(guiStyle));
    ui->tabWidgetMdiSample->setStyle(QStyleFactory::create(guiStyle));
    ui->tabWidgetSqlWinSample->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonExec->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonExecAll->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonTimer->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonExplain->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonCommit->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonRollback->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonClear->setStyle(QStyleFactory::create(guiStyle));
    ui->comboBoxConn->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonZoomIn->setStyle(QStyleFactory::create(guiStyle));
    ui->toolButtonZoomOut->setStyle(QStyleFactory::create(guiStyle));
    ui->textEditSql->setStyle(QStyleFactory::create(guiStyle));
    ui->tableWidgetResults->setStyle(QStyleFactory::create(guiStyle));
}

void KvSettingsDialog::on_buttonBox_accepted()
{
    KvSettings::setDefaultConnectionsPath(ui->lineEditConnectionsFilePath->text());
    KvSettings::setDefaultTranslationsPath(ui->lineEditLangPath->text());
    KvSettings::setDefaultLanguageCode(extractLanguageCode(ui->langComboBox->currentText()));
    KvSettings::setDefaultWorkPath(ui->lineEditWorkPath->text());
    KvSettings::setDefaultGUIStyle(guiStyle);

    QFont guiFont = ui->fontComboBoxGeneral->currentFont();
    guiFont.setPointSize(ui->spinBoxSizeGeneral->value());
    if (ui->checkBoxAntialiasGeneral->isChecked())
        guiFont.setStyleStrategy(QFont::PreferAntialias);
    else
        guiFont.setStyleStrategy(QFont::NoAntialias);

    QFont editorFont = ui->fontComboBoxEditor->currentFont();
    editorFont.setPointSize(ui->spinBoxSizeEditor->value());
    if (ui->checkBoxAntialiasEditor->isChecked())
        editorFont.setStyleStrategy(QFont::PreferAntialias);
    else
        editorFont.setStyleStrategy(QFont::NoAntialias);

    KvSettings::setGUIFonts(guiFont, editorFont);
    KvSettings::saveColorSchemes(colorSchemes, ui->comboBoxColorScheme->currentText());
    QApplication::setStyle(guiStyle);
    if (m_changedConnectionsFileDir) {
        if (! QFile::exists(KvSettings::getDefaultConnectionsPath()+"/kevora.xml")) {
            emit saveConnectionsFile();
        }
        else
            emit changedConnectionsFileDir();
    }
    close();
}

void KvSettingsDialog::on_buttonBox_rejected()
{
    QApplication::setStyle(KvSettings::getDefaultGUIStyle());
    loadSettings();
}

void KvSettingsDialog::on_lineEditConnectionsFilePath_textChanged(QString )
{

}

void KvSettingsDialog::on_lineEditWorkPath_textChanged(QString )
{

}

void KvSettingsDialog::on_tableWidget_7_activated(const QModelIndex &index)
{

}

void KvSettingsDialog::on_tableWidgetColorScheme_cellActivated(int row, int column)
{

}

void KvSettingsDialog::on_tableWidgetColorScheme_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    QColor fgColor = ui->tableWidgetColorScheme->item(currentRow, currentColumn)->foreground().color();
    QColor bgColor = ui->tableWidgetColorScheme->item(currentRow, currentColumn)->backgroundColor();
    QFont font = ui->tableWidgetColorScheme->item(currentRow, currentColumn)->font();
    QString fgStyleSheet = QString();
    QString bgStyleSheet = QString();

    if (fgColor.alpha() > 0) {
        fgStyleSheet = "background: rgba("+QString::number(fgColor.red())+","+QString::number(fgColor.green())+","+QString::number(fgColor.blue())+","+QString::number(fgColor.alpha())+"); ";
        fgStyleSheet += "border: 2px solid; border-radius: 4px; ";
    }
    else {
        fgStyleSheet = "background: transparent;";
        fgStyleSheet += "border: 2px dashed; border-radius: 4px; ";
    }

    if (bgColor.alpha() > 0) {
        bgStyleSheet = "background: rgba("+QString::number(bgColor.red())+","+QString::number(bgColor.green())+","+QString::number(bgColor.blue())+","+QString::number(bgColor.alpha())+"); ";
        bgStyleSheet += "border: 2px solid; border-radius: 4px; ";
    }
    else {
        bgStyleSheet = "background: transparent;";
        bgStyleSheet += "border: 2px dashed; border-radius: 4px; ";
    }

    ui->toolButtonFgColor->setStyleSheet(fgStyleSheet);
    ui->toolButtonBgColor->setStyleSheet(bgStyleSheet);

    if (font.bold())
        ui->checkBoxBold->setChecked(true);
    else
        ui->checkBoxBold->setChecked(false);

    if (font.italic())
        ui->checkBoxItalic->setChecked(true);
    else
        ui->checkBoxItalic->setChecked(false);

}

void KvSettingsDialog::on_toolButtonClearFg_clicked()
{
    QString fgStyleSheet = "background: transparent;";
    fgStyleSheet += "border: 2px dashed; border-radius: 4px; ";
    ui->toolButtonFgColor->setStyleSheet(fgStyleSheet);
    ui->tableWidgetColorScheme->currentItem()->setForeground(Qt::transparent);
    int currentRow = ui->tableWidgetColorScheme->currentRow();
    KvColorScheme tempColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
    tempColorScheme.textColors.replace(currentRow, Qt::transparent);
    colorSchemes.remove(ui->comboBoxColorScheme->currentText());
    colorSchemes.insert(ui->comboBoxColorScheme->currentText(), tempColorScheme);
}

void KvSettingsDialog::on_toolButtonClearBg_clicked()
{
    QString bgStyleSheet = "background: transparent;";
    bgStyleSheet += "border: 2px dashed; border-radius: 4px; ";
    ui->toolButtonBgColor->setStyleSheet(bgStyleSheet);
    ui->tableWidgetColorScheme->currentItem()->setBackground(Qt::transparent);
    int currentRow = ui->tableWidgetColorScheme->currentRow();
    KvColorScheme tempColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
    tempColorScheme.backgroundColors.replace(currentRow, Qt::transparent);
    colorSchemes.remove(ui->comboBoxColorScheme->currentText());
    colorSchemes.insert(ui->comboBoxColorScheme->currentText(), tempColorScheme);
}

void KvSettingsDialog::on_checkBoxBold_toggled(bool checked)
{
    QFont currentFont = ui->tableWidgetColorScheme->currentItem()->font();
    currentFont.setBold(checked);
    ui->tableWidgetColorScheme->currentItem()->setFont(currentFont);
    int currentRow = ui->tableWidgetColorScheme->currentRow();
    KvColorScheme tempColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
    tempColorScheme.fonts.replace(currentRow, currentFont);
    colorSchemes.remove(ui->comboBoxColorScheme->currentText());
    colorSchemes.insert(ui->comboBoxColorScheme->currentText(), tempColorScheme);
}

void KvSettingsDialog::on_checkBoxItalic_toggled(bool checked)
{
    QFont currentFont = ui->tableWidgetColorScheme->currentItem()->font();
    currentFont.setItalic(checked);
    ui->tableWidgetColorScheme->currentItem()->setFont(currentFont);
    int currentRow = ui->tableWidgetColorScheme->currentRow();
    KvColorScheme tempColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
    tempColorScheme.fonts.replace(currentRow, currentFont);
    colorSchemes.remove(ui->comboBoxColorScheme->currentText());
    colorSchemes.insert(ui->comboBoxColorScheme->currentText(), tempColorScheme);
}

void KvSettingsDialog::on_pushButtonCopyScheme_clicked()
{
    bool ok;
    QString copyName = QInputDialog::getText(this, tr("Copy This Color Scheme As"),
                                               tr("Name:"), QLineEdit::Normal,
                                               tr("Copy of")+" "+ui->comboBoxColorScheme->currentText(),
                                               &ok);
    if (ok && !copyName.isEmpty()) {
      KvColorScheme newColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
      colorSchemes.insert(copyName, newColorScheme);
      ui->comboBoxColorScheme->addItem(copyName);
      ui->comboBoxColorScheme->setCurrentIndex(ui->comboBoxColorScheme->findText(copyName));
    }
}

void KvSettingsDialog::on_comboBoxColorScheme_currentIndexChanged(const QString &arg1)
{
    updateColorSchemeTable(arg1);
}

void KvSettingsDialog::updateColorSchemeTable(QString colorSchemeName)
{
    KvColorScheme colorScheme = colorSchemes.value(colorSchemeName);
    for(int i=0; i<colorScheme.fonts.size(); i++) {
        ui->tableWidgetColorScheme->item(i,0)->setFont(colorScheme.fonts.at(i));
        ui->tableWidgetColorScheme->item(i,0)->setForeground(colorScheme.textColors.at(i));
        ui->tableWidgetColorScheme->item(i,0)->setBackground(colorScheme.backgroundColors.at(i));
    }
    if (colorSchemeName.compare("Kevora") == 0) {
        ui->checkBoxBold->setEnabled(false);
        ui->checkBoxItalic->setEnabled(false);
        ui->toolButtonFgColor->setEnabled(false);
        ui->toolButtonBgColor->setEnabled(false);
        ui->toolButtonClearFg->setEnabled(false);
        ui->toolButtonClearBg->setEnabled(false);
        ui->pushButtonDeleteScheme->setEnabled(false);
    }
    else {
        ui->checkBoxBold->setEnabled(true);
        ui->checkBoxItalic->setEnabled(true);
        ui->toolButtonFgColor->setEnabled(true);
        ui->toolButtonBgColor->setEnabled(true);
        ui->toolButtonClearFg->setEnabled(true);
        ui->toolButtonClearBg->setEnabled(true);
        ui->pushButtonDeleteScheme->setEnabled(true);
    }
}

void KvSettingsDialog::on_toolButtonFgColor_clicked()
{
    QColorDialog colorDialog;
    QColor newColor = colorDialog.getColor();
    QString fgStyleSheet = "background: rgba("+QString::number(newColor.red())+","+QString::number(newColor.green())+","+QString::number(newColor.blue())+","+QString::number(newColor.alpha())+"); ";
    fgStyleSheet += "border: 2px solid; border-radius: 4px; ";
    ui->toolButtonFgColor->setStyleSheet(fgStyleSheet);
    ui->tableWidgetColorScheme->currentItem()->setForeground(newColor);
    int currentRow = ui->tableWidgetColorScheme->currentRow();
    KvColorScheme tempColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
    tempColorScheme.textColors.replace(currentRow, newColor);
    colorSchemes.remove(ui->comboBoxColorScheme->currentText());
    colorSchemes.insert(ui->comboBoxColorScheme->currentText(), tempColorScheme);
}

void KvSettingsDialog::on_toolButtonBgColor_clicked()
{
    QColorDialog colorDialog;
    QColor newColor = colorDialog.getColor();
    QString bgStyleSheet = "background: rgba("+QString::number(newColor.red())+","+QString::number(newColor.green())+","+QString::number(newColor.blue())+","+QString::number(newColor.alpha())+"); ";
    bgStyleSheet += "border: 2px solid; border-radius: 4px; ";
    ui->toolButtonBgColor->setStyleSheet(bgStyleSheet);
    ui->tableWidgetColorScheme->currentItem()->setBackgroundColor(newColor);
    int currentRow = ui->tableWidgetColorScheme->currentRow();
    KvColorScheme tempColorScheme = colorSchemes.value(ui->comboBoxColorScheme->currentText());
    tempColorScheme.backgroundColors.replace(currentRow, newColor);
    colorSchemes.remove(ui->comboBoxColorScheme->currentText());
    colorSchemes.insert(ui->comboBoxColorScheme->currentText(), tempColorScheme);
}

void KvSettingsDialog::on_pushButtonDeleteScheme_clicked()
{
    if (ui->comboBoxColorScheme->currentText().compare("Kevora") != 0) {
        QString colorSchemeToRemove = ui->comboBoxColorScheme->currentText();
        ui->comboBoxColorScheme->removeItem(ui->comboBoxColorScheme->currentIndex());
        colorSchemes.remove(colorSchemeToRemove);
        KvSettings::removeColorScheme(colorSchemeToRemove);
    }
}





