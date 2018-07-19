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

#include "kvdbdefinitiondialog.h"
#include "ui_kvdbdefinitiondialog.h"

KvDbDefinitionDialog::KvDbDefinitionDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::KvDbDefinitionDialog)
{
    ui->setupUi(this);
    //ui->dockWidget->hide();
    //int x = this->window()->geometry().x();
    //int y = this->window()->geometry().y() - ui->dockWidget->size().height();
    //int w = this->window()->geometry().width();
    //int h = this->window()->geometry().height();
    //this->window()->setGeometry(x, y, w, h);
    updateDriversCombo(ui->comboBoxDBMSType->currentText());
    portValidator = new QIntValidator(this);
    ui->lineEditFirebirdPort->setValidator(portValidator);
    ui->lineEditMySqlPort->setValidator(portValidator);
    ui->lineEditOraclePort->setValidator(portValidator);
    ui->lineEditPostgPort->setValidator(portValidator);
}

KvDbDefinitionDialog::~KvDbDefinitionDialog()
{
    delete ui;
}

void KvDbDefinitionDialog::show() {
    QDialog::show();
    ui->dockWidget->hide();
}

int KvDbDefinitionDialog::exec() {
    ui->dockWidget->hide();
    return QDialog::exec();
}

void KvDbDefinitionDialog::changeEvent(QEvent *e)
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

void KvDbDefinitionDialog::on_dockWidget_visibilityChanged(bool visible)
{
    if (!visible) {
        ui->pushButtonShowMore->setText(tr("Show More Options"));
    }
    else {
        ui->pushButtonShowMore->setText(tr("Hide More Options"));
    }
}

void KvDbDefinitionDialog::on_pushButtonShowMore_clicked()
{
    if(ui->dockWidget->isVisible()) {
        QSize s = this->window()->size();
        //this->window()->resize( s.width(), 397 - (ui->dockWidget->size().height() ) );
        ui->dockWidget->close();
    }
    else {
        QSize s = this->window()->size();
        //this->window()->resize( s.width(), 397 );
        ui->dockWidget->show();
    }
}

void KvDbDefinitionDialog::updateDriversCombo(QString value) {
    QStringList drivers = KvDbUtil::driversForDatabase(value);
    ui->comboBoxDriver->clear();
    ui->comboBoxDriver->addItems(drivers);
}

void KvDbDefinitionDialog::on_comboBoxDBMSType_currentIndexChanged(QString value)
{
    updateDriversCombo(value);
}

void KvDbDefinitionDialog::setSpecialValues(QString dbmsType, QString host, QString port, QString dbName)
{
    if (dbmsType.compare("Cubrid", Qt::CaseInsensitive) == 0) {
        ui->lineEditCubridHost->setText(host);
        ui->lineEditCubridPort->setText(port);
        ui->lineEditCubridDBName->setText(dbName);
    }
    else if (dbmsType.compare("Firebird / Interbase", Qt::CaseInsensitive) == 0) {
        ui->lineEditFirebirdHost->setText(host);
        ui->lineEditFirebirdPort->setText(port);
        ui->lineEditFirebirdDBName->setText(dbName);
    }
    else if (dbmsType.compare("MySql", Qt::CaseInsensitive) == 0) {
        ui->lineEditMySqlHost->setText(host);
        ui->lineEditMySqlPort->setText(port);
        ui->lineEditMySqlDBName->setText(dbName);
    }
    else if (dbmsType.compare("Oracle", Qt::CaseInsensitive) == 0) {
        ui->lineEditOracleHost->setText(host);
        ui->lineEditOraclePort->setText(port);
        ui->lineEditOracleSID->setText(dbName);
    }
    else if (dbmsType.compare("PostgreSql", Qt::CaseInsensitive) == 0) {
        ui->lineEditPostgHost->setText(host);
        ui->lineEditPostgPort->setText(port);
        ui->lineEditPostgDBName->setText(dbName);
    }
    else if (dbmsType.compare("Sqlite", Qt::CaseInsensitive) == 0) {
        ui->lineEditSqliteHost->setText(host);
        ui->lineEditSqlitePort->setText(port);
        ui->lineEditSqliteDBName->setText(dbName);
    }
}

void KvDbDefinitionDialog::setValues(QString alias, QString dbmsType, QString host, QString port, QString dbName, QString driver, QString comments)
{
    ui->lineEditAlias->setText(alias);
    ui->comboBoxDBMSType->setCurrentIndex(ui->comboBoxDBMSType->findText(dbmsType));
    setSpecialValues(dbmsType, host, port, dbName);
    ui->comboBoxDriver->setCurrentIndex(ui->comboBoxDriver->findText(driver));
    ui->plainTextEditComments->setPlainText(comments);
}

QStringList KvDbDefinitionDialog::getValues()
{
    QStringList values;
    QString dbmsType = ui->comboBoxDBMSType->currentText();
    values.insert(0, ui->lineEditAlias->text());
    values.insert(1, dbmsType);
    if (dbmsType.compare("Cubrid", Qt::CaseInsensitive) == 0) {
        values.insert(2, ui->lineEditCubridHost->text());
        values.insert(3, ui->lineEditCubridPort->text());
        values.insert(4, ui->lineEditCubridDBName->text());
    }
    else if (dbmsType.compare("Firebird / Interbase", Qt::CaseInsensitive) == 0) {
        values.insert(2, ui->lineEditFirebirdHost->text());
        values.insert(3, ui->lineEditFirebirdPort->text());
        values.insert(4, ui->lineEditFirebirdDBName->text());
    }
    else if (dbmsType.compare("MySql", Qt::CaseInsensitive) == 0) {
        values.insert(2, ui->lineEditMySqlHost->text());
        values.insert(3, ui->lineEditMySqlPort->text());
        values.insert(4, ui->lineEditMySqlDBName->text());
    }
    else if (dbmsType.compare("Oracle", Qt::CaseInsensitive) == 0) {
        values.insert(2, ui->lineEditOracleHost->text());
        values.insert(3, ui->lineEditOraclePort->text());
        values.insert(4, ui->lineEditOracleSID->text());
    }
    else if (dbmsType.compare("PostgreSql", Qt::CaseInsensitive) == 0) {
        values.insert(2, ui->lineEditPostgHost->text());
        values.insert(3, ui->lineEditPostgPort->text());
        values.insert(4, ui->lineEditPostgDBName->text());
    }
    else if (dbmsType.compare("Sqlite", Qt::CaseInsensitive) == 0) {
        values.insert(2, ui->lineEditSqliteHost->text());
        values.insert(3, ui->lineEditSqlitePort->text());
        values.insert(4, ui->lineEditSqliteDBName->text());
    }
    values.insert(5, ui->comboBoxDriver->currentText());
    values.insert(6, ui->plainTextEditComments->toPlainText());
    return values;
}

void KvDbDefinitionDialog::on_toolButtonFirebirdSetFile_clicked()
{
    QString lastFileName;
    if (!ui->lineEditFirebirdDBName->text().isEmpty())
        lastFileName = ui->lineEditFirebirdDBName->text();
    else
        lastFileName = KvSettings::getDefaultWorkPath();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Firebird/Interbase Database File"),
                                                    lastFileName,
                                                    tr("All Files (*.*)"));
    if (!fileName.isEmpty())
        ui->lineEditFirebirdDBName->setText(fileName);
}

void KvDbDefinitionDialog::on_toolButtonSqliteSetFile_clicked()
{
    QString lastFileName;
    if (!ui->lineEditSqliteDBName->text().isEmpty())
        lastFileName = ui->lineEditSqliteDBName->text();
    else
        lastFileName = KvSettings::getDefaultWorkPath();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Sqlite Database File"),
                                                    lastFileName,
                                                    tr("All Files (*.*)"));
    if (!fileName.isEmpty())
        ui->lineEditSqliteDBName->setText(fileName);
}
