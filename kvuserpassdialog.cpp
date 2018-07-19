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

#include "kvuserpassdialog.h"
#include "ui_kvuserpassdialog.h"

KvUserPassDialog::KvUserPassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KvUserPassDialog)
{
    ui->setupUi(this);
}

KvUserPassDialog::~KvUserPassDialog()
{
    delete ui;
}

void KvUserPassDialog::changeEvent(QEvent *e)
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

void KvUserPassDialog::on_lineEditPassword_textChanged(QString )
{
    ui->checkBoxSavePassword->setEnabled(!ui->lineEditPassword->text().isEmpty());
    ui->checkBoxAutoLogon->setEnabled(!ui->lineEditPassword->text().isEmpty());
}

void KvUserPassDialog::setValues(QString username, QString password, QString savePassword, QString autoLogon)
{
    ui->lineEditUsername->setText(username);

    if (savePassword.compare("yes", Qt::CaseInsensitive) == 0)
        ui->checkBoxSavePassword->setChecked(true);
    else
        ui->checkBoxSavePassword->setChecked(false);

    if (ui->checkBoxSavePassword->isChecked()) {
        ui->lineEditPassword->setText(password);
    }
    else {
        ui->lineEditPassword->clear();
    }

    if (autoLogon.compare("yes", Qt::CaseInsensitive) == 0)
        ui->checkBoxAutoLogon->setChecked(true);
    else
        ui->checkBoxAutoLogon->setChecked(false);
}

QStringList KvUserPassDialog::getValues()
{
    QStringList values;
    values << ui->lineEditUsername->text();
    values << ui->lineEditPassword->text();
    if (ui->checkBoxSavePassword->isChecked())
        values << "yes";
    else
        values << "no";
    if (ui->checkBoxAutoLogon->isChecked())
        values << "yes";
    else
        values << "no";
    return values;
}

void KvUserPassDialog::on_checkBoxAutoLogon_toggled(bool checked)
{
    if (checked)
        ui->checkBoxSavePassword->setChecked(true);
}

void KvUserPassDialog::on_checkBoxSavePassword_toggled(bool checked)
{
    if (! checked) {
        ui->lineEditPassword->clear();
        ui->checkBoxAutoLogon->setChecked(false);
    }
}


