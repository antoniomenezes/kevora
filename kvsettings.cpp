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

#include "kvsettings.h"

QString KvSettings::getDefaultGUIStyle() {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    QString currentGUIStyle = settings.value("GUIStyle", QApplication::style()->objectName()).toString();
    settings.endGroup();
    return currentGUIStyle;
}

void KvSettings::setDefaultGUIStyle(QString style) {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    settings.setValue("GUIStyle", style);
    settings.endGroup();
}

QStringList KvSettings::getDefaultLanguageFiles() {
    QString langCode = KvSettings::getDefaultLanguageCode();
    QStringList langFiles;
    langFiles << "kevora_"+langCode+".qm" << "qt_"+langCode+".qm";
    return langFiles;
}

QStringList KvSettings::getDefaultKevoraUpdateLanguageFiles() {
    QString langCode = KvSettings::getDefaultLanguageCode();
    QStringList langFiles;
    langFiles << "kevora-update_"+langCode+".qm" << "qt_"+langCode+".qm";
    return langFiles;
}

QString KvSettings::getDefaultLanguageCode() {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    QString currentCode = settings.value("languageCode", "en").toString();
    settings.endGroup();
    return currentCode;
}

void KvSettings::setDefaultLanguageCode(QString languageCode) {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    settings.setValue("languageCode", languageCode);
    settings.endGroup();
}

QString KvSettings::getDefaultTranslationsPath() {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    QString currentTranslationPath = settings.value("translationsPath", QCoreApplication::applicationDirPath()+"/translations").toString();
    settings.endGroup();
    return currentTranslationPath;
}

void KvSettings::setDefaultTranslationsPath(QString path) {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    settings.setValue("translationsPath", path);
    settings.endGroup();
}

QString KvSettings::getDefaultWorkPath() {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    QString currentDir = settings.value("workPath", QDir::homePath()).toString();
    settings.endGroup();
    return currentDir;
}

void KvSettings::setDefaultWorkPath(QString path) {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    settings.setValue("workPath", path);
    settings.endGroup();
}

QString KvSettings::getDefaultConnectionsPath() {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    QString currentDir = settings.value("connectionsPath", QDir::homePath()).toString();
    settings.endGroup();
    return currentDir;
}

void KvSettings::setDefaultConnectionsPath(QString path) {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    settings.setValue("connectionsPath", path);
    settings.endGroup();
}

void KvSettings::setVisibleDbAssistant(bool enabled)
{
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    settings.setValue("showDbAssistant", enabled);
    settings.endGroup();
}

bool KvSettings::visibleDbAssistant()
{
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    bool result = (settings.value("showDbAssistant", true)).toBool();
    settings.endGroup();
    return result;
}

// function to mount a QString list with TNSNAMES entries
QStringList KvSettings::getTnsNames(const QString &fileName) {
    QFile tnsnamesFile(fileName);
    if (! tnsnamesFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, fileName, QObject::tr("Cannot read file %1:\n%2.").arg(fileName).arg(tnsnamesFile.errorString()));
    }
    QTextStream stream( &tnsnamesFile );

    // Reading all text at once. This could be improved
    QString lines = stream.readAll();

    // Regular Expression to find TNSNAMES descriptions
    QRegExp rx(QString("[\\n][\\s]*[^\\(#][a-zA-Z0-9_.]+[\\s]*=[\\s]*\\([\\s]*"));
    rx.setPatternSyntax(QRegExp::RegExp2);

    // A QMap used but just a QList would be enough to store positions
    QMap<int, QString> map;

    int pos = 0;
    int lastIndex = 0;
    while ((pos = rx.indexIn(lines, pos)) != -1) {
        QStringList listCap = rx.capturedTexts();
        QStringList::iterator it = listCap.begin();
        while (it != listCap.end()) {
            if (! QString(*it).trimmed().isEmpty()) {
                lastIndex = lines.indexOf(QString(*it).trimmed(), lastIndex);
                map.insert(lastIndex, QString(*it).trimmed());
            }
            ++it;
        }
        pos += rx.matchedLength();
    }
    map.insert(lines.count()-1, "");

    // Until this position, all positions of strings like 'AAAA = (' are stored at map variable
    // Now, it will be necessary to form the complete TNS entries,
    // limited by position i and position i+s+1 (from i to s there will be a complete TNS entry)

    // Each element of this list will contain a complete TNSNAMES description
    QStringList list;

    QMapIterator<int, QString> iEntries(map);
    lastIndex = -1;
    while (iEntries.hasNext()) {
        iEntries.next();
        if (lastIndex > 0) {
            QString tnsEntry = lines.mid(lastIndex, (iEntries.key()-lastIndex)).trimmed();
            //tnsEntry = tnsEntry.left(tnsEntry.indexOf("#")-1);
            tnsEntry = tnsEntry.remove("\n",Qt::CaseInsensitive).remove("\t",Qt::CaseInsensitive);
            while(tnsEntry.indexOf("  ",0,Qt::CaseInsensitive) >= 0)
                tnsEntry = tnsEntry.replace("  "," ",Qt::CaseInsensitive);
            list.append(tnsEntry);
            lastIndex = iEntries.key();
        }
        else
            lastIndex = iEntries.key();
    }
    if (list.size() > 0) {
        QString tnsEntry = lines.mid(lastIndex, (iEntries.key()-lastIndex)).trimmed();
        //tnsEntry = tnsEntry.left(tnsEntry.indexOf("#")-1);
        tnsEntry = tnsEntry.remove("\n",Qt::CaseInsensitive).remove("\t",Qt::CaseInsensitive);
        while(tnsEntry.indexOf("  ",0,Qt::CaseInsensitive) >= 0)
            tnsEntry = tnsEntry.replace("  "," ",Qt::CaseInsensitive);
        if (! tnsEntry.trimmed().isEmpty())
            list.append(tnsEntry);
    }

    return list;
}

// This routine will identify each important part from a tnsnames entry
QStringList KvSettings::splitTnsEntry(const QString &entry) {
    QStringList result;
    QRegExp rxAlias(QString("^[A-Za-z_]+([A-Za-z_0-9]*)"));
    rxAlias.setPatternSyntax(QRegExp::RegExp2);
    rxAlias.indexIn(entry, 0);
    QString aliasEntry = rxAlias.capturedTexts().at(0);

    QRegExp rxIP(QString("[Hh][Oo][Ss][Tt]\\s*=\\s*[0-9]*.[0-9]*.[0-9]*.[0-9]*"));
    rxIP.setPatternSyntax(QRegExp::RegExp2);
    rxIP.indexIn(entry, 0);
    QString IPEntry = rxIP.capturedTexts().at(0);
    IPEntry = IPEntry.right((IPEntry.length()-IPEntry.indexOf("="))-1);
    IPEntry = IPEntry.remove("=").trimmed();

    QRegExp rxPort(QString("[Pp][Oo][Rr][Tt]\\s*=\\s*[0-9]*"));
    rxPort.setPatternSyntax(QRegExp::RegExp2);
    rxPort.indexIn(entry, 0);
    QString PortEntry = rxPort.capturedTexts().at(0);
    PortEntry = PortEntry.right((PortEntry.length()-PortEntry.indexOf("="))-1);
    PortEntry = PortEntry.remove("=").trimmed();

    QRegExp rxSid(QString("[Ss][Ii][Dd]\\s*=\\s*[A-Za-z_0-9]*"));
    rxSid.setPatternSyntax(QRegExp::RegExp2);
    rxSid.indexIn(entry, 0);
    QString SidEntry = rxSid.capturedTexts().at(0);
    SidEntry = SidEntry.right((SidEntry.length()-SidEntry.indexOf("="))-1);
    SidEntry = SidEntry.remove("=").trimmed();

    result.append(aliasEntry);
    result.append(IPEntry);
    result.append(PortEntry);
    result.append(SidEntry);
    return result;
}

void KvSettings::saveWidgetGeometry(QWidget *widget)
{
    QSettings settings("kevora", "All Users");
    QString groupName;
    if (widget->parent() != NULL)
        groupName = widget->parent()->objectName()+"."+widget->objectName();
    else
        groupName = widget->objectName();

    settings.beginGroup(groupName);
    settings.setValue("geometry", widget->geometry());
    settings.setValue("size", widget->size());
    settings.setValue("pos", widget->pos());
    settings.setValue("isMaximized", widget->isMaximized());

    if (widget->inherits("QDockWidget")) {
        QDockWidget *dockWidget = qobject_cast<QDockWidget *>(widget);
        settings.setValue("isFloating", dockWidget->isFloating());
        settings.setValue("isHidden", dockWidget->isHidden());
        QMainWindow *mainWindow = qobject_cast<QMainWindow *>(widget->parent());
        settings.setValue("dockWidgetArea", mainWindow->dockWidgetArea(dockWidget));
    }
    settings.endGroup();
}

void KvSettings::restoreWidgetGeometry(QWidget *widget)
{
    QSettings settings("kevora", "All Users");
    QString groupName;
    if (widget->parent() != NULL)
        groupName = widget->parent()->objectName()+"."+widget->objectName();
    else
        groupName = widget->objectName();
    settings.beginGroup(groupName);
    if (settings.contains("geometry"))
        widget->restoreGeometry(settings.value("geometry").toByteArray());
    if (settings.contains("size"))
        widget->resize(settings.value("size").toSize());
    if (settings.contains("pos"))
        widget->move(settings.value("pos").toPoint());
    if (settings.contains("isMaximized"))
        if ((settings.value("isMaximized")).toBool()) {
            widget->setWindowState(widget->windowState() ^ Qt::WindowMaximized);
        }
    if (widget->inherits("QDockWidget")) {
        QDockWidget *dockWidget = qobject_cast<QDockWidget *>(widget);
        dockWidget->setFloating((settings.value("isFloating")).toBool());
        dockWidget->setHidden((settings.value("isHidden")).toBool());
        QMainWindow *mainWindow = qobject_cast<QMainWindow *>(widget->parent());
        mainWindow->addDockWidget(Qt::DockWidgetArea(settings.value("dockWidgetArea").toInt()), dockWidget);
    }
    settings.endGroup();
}

void KvSettings::saveWidgetGeometry(QSplitter *splitter)
{
    QSettings settings("kevora", "All Users");
    QString groupName;
    if (splitter->parent() != NULL)
        groupName = splitter->parent()->objectName()+"."+splitter->objectName();
    else
        groupName = splitter->objectName();
    settings.beginGroup(groupName);
    settings.setValue("splitterState", splitter->saveState());
    settings.endGroup();
}

void KvSettings::restoreWidgetGeometry(QSplitter *splitter)
{
    QSettings settings("kevora", "All Users");
    QString groupName;
    if (splitter->parent() != NULL)
        groupName = splitter->parent()->objectName()+"."+splitter->objectName();
    else
        groupName = splitter->objectName();
    settings.beginGroup(groupName);
    splitter->restoreState(settings.value("splitterState").toByteArray());
    settings.endGroup();
}

void KvSettings::saveMainWindowSettings(QMainWindow *mainWindow)
{
    QSettings settings("kevora", "All Users");
    settings.beginGroup("MainWindow");
    settings.setValue("size", mainWindow->size());
    settings.setValue("pos", mainWindow->pos());
    //settings.setValue("isMaximized", mainWindow->isMaximized());
    settings.setValue("state", mainWindow->saveState());
    //settings.setValue("treeDB.orderColumn", treeDB->sortColumn());
    //settings.setValue("splitterMdiSize", splitterMdi->saveState());
    //settings.setValue("splitterObjSize", splitterObj->saveState());
    //settings.setValue("languageFile", currentTranslationFile);
    settings.endGroup();

    //saveConnListAsXML();
}

void KvSettings::restoreMainWindowSettings(QMainWindow *mainWindow)
{
    QSettings settings("kevora", "All Users");

    settings.beginGroup("MainWindow");
    mainWindow->resize(settings.value("size", QSize(800, 600)).toSize());
    mainWindow->move(settings.value("pos", QPoint(1, 1)).toPoint());
    mainWindow->restoreState(settings.value("state").toByteArray());
    /*if ((settings.value("isMaximized", true)).toBool()) {
        mainWindow->setWindowState(mainWindow->windowState() ^ Qt::WindowMaximized);
    }*/
    //treeDB->sortItems((settings.value("treeDB.orderColumn", 0)).toInt(), Qt::AscendingOrder);
    //splitterMdi->restoreState(settings.value("splitterMdiSize").toByteArray());
    //splitterObj->restoreState(settings.value("splitterObjSize").toByteArray());
    //currentTranslationFile = settings.value("languageFile", "").toString();
    settings.endGroup();

    //openConnListAsXML();
    //treeDB->resizeColumnToContents(0);
}

void KvSettings::saveColorSchemes(QMap<QString, KvColorScheme> colorSchemes, QString currentColorScheme)
{
    QSettings settings("kevora", "All Users");
    settings.beginGroup("ColorSchemes");
    QStringList colorSchemeNames = colorSchemes.keys();
    KvColorScheme firstColorScheme = colorSchemes.values().at(0);
    int itemCount = firstColorScheme.textColors.size();
    settings.setValue("ColorSchemeNames", colorSchemeNames);
    settings.setValue("CurrentColorSchemeName", currentColorScheme);
    settings.setValue("ColorSchemeColorCount", itemCount);
    foreach(QString colorSchemeName, colorSchemes.keys()) {
        KvColorScheme colorScheme = colorSchemes.value(colorSchemeName);
        for(int i=0; i<itemCount; i++) {
            QFont editorFont = getEditorFont();
            QFont currentItemFont = colorScheme.fonts.at(i);
            currentItemFont.setFamily(editorFont.family());
            currentItemFont.setPointSize(editorFont.pointSize());
            settings.setValue("ColorSchemes/"+colorSchemeName+"/font-"+QString::number(i), currentItemFont);
            settings.setValue("ColorSchemes/"+colorSchemeName+"/textColor-"+QString::number(i), colorScheme.textColors.at(i));
            settings.setValue("ColorSchemes/"+colorSchemeName+"/backgroundColor-"+QString::number(i), colorScheme.backgroundColors.at(i));
        }
    }
    settings.endGroup();
}

QString KvSettings::getCurrentColorSchemeName()
{
    QSettings settings("kevora", "All Users");
    settings.beginGroup("ColorSchemes");
    QString colorSchemaName = settings.value("CurrentColorSchemeName", "Kevora").value<QString>();
    settings.endGroup();
    return colorSchemaName;
}

KvColorScheme KvSettings::getCurrentColorScheme()
{
    QMap<QString, KvColorScheme> colorSchemes = KvSettings::restoreColorSchemes();
    QString currentColorScheme = getCurrentColorSchemeName();
    return colorSchemes.value(currentColorScheme);
}

void KvSettings::removeColorScheme(QString colorSchemeName)
{
    QSettings settings("kevora", "All Users");
    settings.beginGroup("ColorSchemes");
    int itemCount = settings.value("ColorSchemeColorCount", 8).value<int>();
    for(int i=0; i<itemCount; i++) {
        settings.remove("ColorSchemes/"+colorSchemeName+"/font-"+QString::number(i));
        settings.remove("ColorSchemes/"+colorSchemeName+"/textColor-"+QString::number(i));
        settings.remove("ColorSchemes/"+colorSchemeName+"/backgroundColor-"+QString::number(i));
    }
    QStringList colorSchemeNames = settings.value("ColorSchemeNames", QStringList("Kevora")).value<QStringList>();
    colorSchemeNames.removeAll(colorSchemeName);
    settings.setValue("ColorSchemeNames", colorSchemeNames);
    settings.endGroup();
}

QPair<KvForegroundFontColor, QColor> KvSettings::getDefaultColors(int fgNumber, int bgNumber)
{
    QPair<KvForegroundFontColor, QColor> result;
    QColor bgColor = Qt::white;
    bgColor.setAlpha(0);
    KvForegroundFontColor fgFontColor;
    fgFontColor.font = QFont();

    switch(fgNumber) {
    case 1:
        fgFontColor.color = Qt::black;
        fgFontColor.font.setBold(true);
        break;
    case 2:
        fgFontColor.color = Qt::black;
        fgFontColor.font.setBold(true);
        break;
    case 3:
        fgFontColor.color = Qt::blue;
        break;
    case 4:
        fgFontColor.color = Qt::darkGreen;
        break;
    case 5:
        fgFontColor.color = Qt::gray;
        fgFontColor.font.setItalic(true);
    case 6:
        fgFontColor.color = Qt::gray;
        fgFontColor.font.setItalic(true);
    case 7:
        fgFontColor.color = Qt::darkRed;
    }
    result.first = fgFontColor;
    result.second = bgColor;
    return result;
}

QMap<QString, KvColorScheme> KvSettings::restoreColorSchemes()
{
    QMap<QString, KvColorScheme> colorSchemes;
    QSettings settings("kevora", "All Users");
    settings.beginGroup("ColorSchemes");
    QStringList colorSchemeNames = settings.value("ColorSchemeNames", QStringList("Kevora")).value<QStringList>();
    // Current 8 fonts for each color scheme
    int itemCount = settings.value("ColorSchemeColorCount", 8).value<int>();
    foreach(QString colorSchemeName, colorSchemeNames) {
        KvColorScheme colorScheme;
        QList<QFont> fonts = QList<QFont>();
        QList<QColor> textColors = QList<QColor>();
        QList<QColor> backgroundColors = QList<QColor>();
        for(int i=0; i<itemCount; i++) {
            QPair<KvForegroundFontColor, QColor> defaultColors = getDefaultColors(i, i);
            fonts.append(settings.value("ColorSchemes/"+colorSchemeName+"/font-"+QString::number(i), defaultColors.first.font).value<QFont>());
            textColors.append(settings.value("ColorSchemes/"+colorSchemeName+"/textColor-"+QString::number(i), defaultColors.first.color).value<QColor>());
            backgroundColors.append(settings.value("ColorSchemes/"+colorSchemeName+"/backgroundColor-"+QString::number(i), defaultColors.second).value<QColor>());
        }
        colorScheme.fonts = fonts;
        colorScheme.textColors = textColors;
        colorScheme.backgroundColors = backgroundColors;
        colorSchemes.insert(colorSchemeName, colorScheme);
    }
    settings.endGroup();
    return colorSchemes;
}

QFont KvSettings::getGUIFont() {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("Fonts");
    QFont font = settings.value("GUIFont", QFont()).value<QFont>();
    settings.endGroup();
    return font;
}

QFont KvSettings::getEditorFont() {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("Fonts");
    QFont font = settings.value("EditorFont", QFont()).value<QFont>();
    settings.endGroup();
    return font;
}

void KvSettings::setGUIFonts(QFont guiFont, QFont editorFont) {
    QSettings settings("kevora", "All Users");
    settings.beginGroup("Fonts");
    settings.setValue("GUIFont", guiFont);
    settings.setValue("EditorFont", editorFont);
    settings.endGroup();
}

/*
bool QWidget::restoreGeometry ( const QByteArray & geometry )

Restores the geometry and state top-level widgets stored in the byte array geometry. Returns true on success; otherwise returns false.

If the restored geometry is off-screen, it will be modified to be inside the the available screen geometry.

To restore geometry saved using QSettings, you can use code like this:

 QSettings settings("MyCompany", "MyApp");
 myWidget->restoreGeometry(settings.value("myWidget/geometry").toByteArray());
See the Window Geometry documentation for an overview of geometry issues with windows.

Use QMainWindow::restoreState() to restore the geometry and the state of toolbars and dock widgets.

This function was introduced in Qt 4.2.

See also saveGeometry(), QSettings, QMainWindow::saveState(), and QMainWindow::restoreState().

QByteArray QWidget::saveGeometry () const

Saves the current geometry and state for top-level widgets.

To save the geometry when the window closes, you can implement a close event like this:

 void MyWidget::closeEvent(QCloseEvent *event)
 {
     QSettings settings("MyCompany", "MyApp");
     settings.setValue("geometry", saveGeometry());
     QWidget::closeEvent(event);
 }
 */

