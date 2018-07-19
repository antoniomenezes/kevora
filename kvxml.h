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

#ifndef KVXML_H
#define KVXML_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QXmlStreamWriter>
#include <QFileInfo>
#include <QMessageBox>
#include <QFile>
#include <QObject>
#include <QList>
#include <QStringList>

class KvXmlStreamReader;

class KvXml
{
public:
    KvXml();
    bool writeXml(const QString &fileName, QTreeWidget *treeWidget);
    bool readXml(const QString &fileName, QTreeWidget *treeWidget);
    void setTag(int level, int column, QString value);
    void setTagLevel(int level, QString value);
private:
    void writeEntry(QXmlStreamWriter *xmlWriter, QTreeWidgetItem *item, int level);
    //QVector < QVector<QString> > tagArray;
    QMap<int, QMap<int, QString> > tagArray;
    QMap<int, QString> tagLevelArray;
    KvXmlStreamReader *streamReader;
};

class KvXmlStreamReader
{
public:
    KvXmlStreamReader(QTreeWidget *tree, QMap<int, QString> levels, QMap<int, QMap<int, QString> > tags);
    bool readXml(const QString &fileName);
private:
    void readKvXmlElement();
    void readEntryElement(QTreeWidgetItem *parent, int level);
    void skipUnknownElement();

    QTreeWidget *treeWidget;
    QXmlStreamReader reader;
    QMap<int, QMap<int, QString> > tagArray;
    QMap<int, QString> tagLevelArray;
};

#endif // KVXML_H
