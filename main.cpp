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

#include <QApplication>
#include <QTranslator>
#include "kvmainwindow.h"
#include "kvsettings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString guiStyle = KvSettings::getDefaultGUIStyle();
    if (!guiStyle.isEmpty())
        a.setStyle(guiStyle);
    else
        KvSettings::setDefaultGUIStyle(a.style()->objectName());

    a.setFont(KvSettings::getGUIFont());
    //QApplication::setStyle("Oxygen");
    //QApplication::setStyle(new QGtkStyle);
    //QApplication::setStyle(new QPlastiqueStyle);
    QTranslator qtTranslator, kvTranslator;
    QString qmPath = KvSettings::getDefaultTranslationsPath();
    QStringList languageFiles = KvSettings::getDefaultLanguageFiles();
    kvTranslator.load(languageFiles.at(0), qmPath);
    qtTranslator.load(languageFiles.at(1), qmPath);
    a.installTranslator(&kvTranslator);
    a.installTranslator(&qtTranslator);
    foreach (QString path, a.libraryPaths())
        qDebug() << path;

    KvMainWindow w;
    w.show();
    return a.exec();
}
