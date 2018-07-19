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

#ifndef KVSETTINGS_H
#define KVSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QTranslator>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <QDockWidget>
#include <QSplitter>
#include <QApplication>
#include <QCoreApplication>
#include <QStyleFactory>
#include <QStyle>
#include <QDir>

typedef struct {
    QList<QFont> fonts;
    QList<QColor> textColors;
    QList<QColor> backgroundColors;
} KvColorScheme;

typedef struct {
    QFont font;
    QColor color;
} KvForegroundFontColor;

/**
  Settings:
  This class will handle all Kevora's settings.
  The settings are related to the user preferred language,
  the window states, settings about database connections etc.
*/
class KvSettings : public QObject
{
public:
    static QString getDefaultGUIStyle();
    static void setDefaultGUIStyle(QString style);
    static QStringList getDefaultLanguageFiles();
    static QStringList getDefaultKevoraUpdateLanguageFiles();
    static QString getDefaultLanguageCode();
    static void setDefaultLanguageCode(QString languageCode);
    static QString getDefaultTranslationsPath();
    static void setDefaultTranslationsPath(QString path = QCoreApplication::applicationDirPath()+"/translations");
    static QString getDefaultWorkPath();
    static void setDefaultWorkPath(QString path = QCoreApplication::applicationDirPath());
    static QString getDefaultConnectionsPath();
    static void setDefaultConnectionsPath(QString path = QCoreApplication::applicationDirPath());
    static void setVisibleDbAssistant(bool enabled = false);
    static bool visibleDbAssistant();
    static QStringList getTnsNames(const QString &fileName);
    static QStringList splitTnsEntry(const QString &entry);
    //static void translateSystemMenu(QMenu *menu);
    static void saveWidgetGeometry(QWidget *widget);
    static void saveWidgetGeometry(QSplitter *splitter);
    static void restoreWidgetGeometry(QWidget *widget);
    static void restoreWidgetGeometry(QSplitter *splitter);
    static void saveMainWindowSettings(QMainWindow *mainWindow);
    static void restoreMainWindowSettings(QMainWindow *mainWindow);
    static void saveColorSchemes(QMap<QString, KvColorScheme> colorSchemes, QString currentColorScheme);
    static QString getCurrentColorSchemeName();
    static KvColorScheme getCurrentColorScheme();
    static void removeColorScheme(QString colorSchemeName);
    static QPair<KvForegroundFontColor, QColor> getDefaultColors(int fgNumber, int bgNumber);
    static QMap<QString, KvColorScheme> restoreColorSchemes();
    static QFont getGUIFont();
    static QFont getEditorFont();
    static void setGUIFonts(QFont guiFont, QFont editorFont);
};

#endif // KVSETTINGS_H
