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

#ifndef KVSETTINGSDIALOG_H
#define KVSETTINGSDIALOG_H

#include <QDialog>
#include <QToolTip>
#include <QTranslator>
#include <QDir>
#include <QFileDialog>
#include <QFont>
#include <QColorDialog>
#include <QInputDialog>
#include "kvsettings.h"
#include "kvdbutil.h"
#include "kvsqlsessionfirebird.h"
#include "kvsqlsessionmysql.h"
#include "kvsqlsessionoracle.h"
#include "kvsqlsessionpostgresql.h"
#include "kvsqlsessionsqlite.h"
#include "kvsqlsessioncubrid.h"

namespace Ui {
    class KvSettingsDialog;
}

class KvSettingsDialog : public QDialog {
    Q_OBJECT
public:
    explicit KvSettingsDialog(QWidget *parent = 0);
    ~KvSettingsDialog();
    void loadLanguage();
    void loadColorSchemes();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::KvSettingsDialog *ui;
    bool m_changedConnectionsFileDir;
    QString guiStyle;
    QStringList availableDrivers;
    QString connectionsFilePath;
    QString workFilesPath;
    QString languageFilesPath;
    QString languageCode;
    QString extractLanguageCode(QString languageName);

    // general text, keyword, reserved word, type, function, single comment, multi comment, quotation fonts for Syntax Highlighting
    QList<QFont> fontsForEditorTokens;
    QList<QColor> textColorsForEditorTokens;
    QList<QColor> backgroundColorsForEditorTokens;
    QMap<QString, KvColorScheme> colorSchemes;

    void updateDriversCombos();
    void loadSettings();
    void loadStylesCombo();

private slots:
    void on_lineEditWorkPath_textChanged(QString );
    void on_lineEditConnectionsFilePath_textChanged(QString );
    void on_buttonBox_rejected();
    void on_comboBoxGuiStyle_currentIndexChanged(QString currentText);
    void on_workDirButton_clicked();
    void on_connDirButton_clicked();
    void on_lineEditLangPath_textChanged(QString text);
    void on_buttonBox_accepted();
    void on_langComboBox_activated(QString text);
    void on_langDirButton_clicked();
    void on_sqliteDrvInfoButton_clicked();
    void on_postgresqlDrvInfoButton_clicked();
    void on_oracleDrvInfoButton_clicked();
    void on_odbcDrvInfoButton_clicked();
    void on_mysqlDrvInfoButton_clicked();
    void on_firebirdDrvInfoButton_clicked();
    void on_prefDrvSqliteComboBox_currentIndexChanged(int index);
    void on_prefDrvPostgreSqlComboBox_currentIndexChanged(int index);
    void on_prefDrvOracleComboBox_currentIndexChanged(int index);
    void on_prefDrvODBCComboBox_currentIndexChanged(int index);
    void on_prefDrvMySqlComboBox_currentIndexChanged(int index);
    void on_prefDrvFirebirdComboBox_currentIndexChanged(int index);
    void setLanguage(QString langCode);
    void setNeedToSaveSettings();
    void on_tableWidget_7_activated(const QModelIndex &index);
    void on_tableWidgetColorScheme_cellActivated(int row, int column);
    void on_tableWidgetColorScheme_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);
    void on_toolButtonClearFg_clicked();
    void on_toolButtonClearBg_clicked();
    void on_checkBoxBold_toggled(bool checked);
    void on_checkBoxItalic_toggled(bool checked);
    void on_pushButtonCopyScheme_clicked();
    void on_comboBoxColorScheme_currentIndexChanged(const QString &arg1);
    void updateColorSchemeTable(QString colorSchemeName);
    void on_toolButtonFgColor_clicked();
    void on_toolButtonBgColor_clicked();
    void on_pushButtonDeleteScheme_clicked();

    void on_prefDrvCubridComboBox_currentIndexChanged(int index);

    void on_cubridDrvInfoButton_clicked();

public slots:
    void enableConnectionsFileDirAlert(bool enable = true);

signals:
    void needsToSaveSettings();
    void changedConnectionsFileDir();
    void saveConnectionsFile();
};

#endif // KVSETTINGSDIALOG_H
