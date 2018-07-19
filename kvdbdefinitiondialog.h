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

#ifndef KVDBDEFINITIONDIALOG_H
#define KVDBDEFINITIONDIALOG_H

#include <QDialog>
#include <QSize>
#include <QFileDialog>
#include "kvdbutil.h"
#include "kvsettings.h"

namespace Ui {
    class KvDbDefinitionDialog;
}

class KvDbDefinitionDialog : public QDialog {
    Q_OBJECT
public:
    explicit KvDbDefinitionDialog(QWidget *parent = 0);
    ~KvDbDefinitionDialog();
    void setValues(QString alias, QString dbmsType, QString host, QString port, QString dbName, QString driver, QString comments);
    QStringList getValues();

public slots:
    void show();
    int exec();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::KvDbDefinitionDialog *ui;
    QValidator *portValidator;
    void setSpecialValues(QString dbmsType, QString host, QString port, QString dbName);

private slots:
    void on_toolButtonSqliteSetFile_clicked();
    void on_toolButtonFirebirdSetFile_clicked();
    void on_comboBoxDBMSType_currentIndexChanged(QString value);
    void on_pushButtonShowMore_clicked();
    void on_dockWidget_visibilityChanged(bool visible);
    void updateDriversCombo(QString value);
};

#endif // KVDBDEFINITIONDIALOG_H
