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

#ifndef KVUSERPASSDIALOG_H
#define KVUSERPASSDIALOG_H

#include <QDialog>

namespace Ui {
    class KvUserPassDialog;
}

class KvUserPassDialog : public QDialog {
    Q_OBJECT
public:
    explicit KvUserPassDialog(QWidget *parent = 0);
    ~KvUserPassDialog();
    void setValues(QString username, QString password, QString savePassword, QString autoLogon);
    QStringList getValues();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::KvUserPassDialog *ui;

private slots:
    void on_checkBoxSavePassword_toggled(bool checked);
    void on_checkBoxAutoLogon_toggled(bool checked);
    void on_lineEditPassword_textChanged(QString );
};

#endif // KVUSERPASSDIALOG_H
