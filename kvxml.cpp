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

#include "kvxml.h"

KvXml::KvXml()
{
}

bool KvXml::writeXml(const QString &fileName, QTreeWidget *treeWidget) {
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(0, "Kevora Xml", QObject::tr("Error: Can't write file")+" "+fileName+". "+file.errorString());
        return false;
    }
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    if (treeWidget->topLevelItemCount() > 0) {
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("kvxml");

        for (int i=0; i < treeWidget->topLevelItemCount(); ++i)
            writeEntry(&xmlWriter, treeWidget->topLevelItem(i), 0);

        xmlWriter.writeEndDocument();
    }
    file.close();
    if (file.error()) {
        QMessageBox::critical(0, "Kevora Xml", QObject::tr("Error: Can't write file")+" "+fileName+". "+file.errorString());
        return false;
    }
    return true;
}

void KvXml::writeEntry(QXmlStreamWriter *xmlWriter, QTreeWidgetItem *item, int level) {
    xmlWriter->writeStartElement(tagLevelArray.value(level));
    int itemColumnCount = item->columnCount();
    for (int c=0; c<itemColumnCount; ++c) {
        QString tagForColumn = tagArray.value(level).value(c);
        if (!tagForColumn.isEmpty())
            xmlWriter->writeAttribute(tagForColumn, item->text(c));
    }
    for (int i=0; i<item->childCount(); ++i) {
        writeEntry(xmlWriter, item->child(i), level+1);
    }
    xmlWriter->writeEndElement();
}

void KvXml::setTag(int level, int column, QString value) {
    if (tagArray.contains(level)) {
        if (tagArray.value(level).contains(column)) {
            QMap<int, QString> map;
            map = tagArray.value(level);
            map.remove(column);
            map.insert(column, value);
            tagArray.insert(level, map);
        }
        else {
            QMap<int, QString> map = tagArray.value(level);
            map.insert(column, value);
            tagArray.insert(level, map);
        }
    }
    else {
        QMap<int, QString> map;
        map.insert(column, value);
        tagArray.insert(level, map);
    }
}

void KvXml::setTagLevel(int level, QString value) {
    if (tagLevelArray.contains(level)) {
        tagLevelArray.remove(level);
    }
    tagLevelArray.insert(level, value);
}

bool KvXml::readXml(const QString &fileName, QTreeWidget *treeWidget) {
    bool result;
    streamReader = new KvXmlStreamReader(treeWidget, tagLevelArray, tagArray);
    result = streamReader->readXml(fileName);
    delete streamReader;
    return result;
}

KvXmlStreamReader::KvXmlStreamReader(QTreeWidget *tree, QMap<int, QString> levels, QMap<int, QMap<int, QString> > tags ) {
    treeWidget = tree;
    tagLevelArray = levels;
    tagArray = tags;
}

bool KvXmlStreamReader::readXml(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(0, "Kevora Xml", QObject::tr("Error: Can't read file")+" "+fileName+". "+file.errorString());
        return false;
    }
    if (QFileInfo(file).size() > 0) {
        reader.setDevice(&file);
        reader.readNext();
        while (!reader.atEnd()) {
            if (reader.isStartElement()) {
                if (reader.name() == "kvxml") {
                    readKvXmlElement();
                }
                else {
                    reader.raiseError(QObject::tr("Not a Kevora XML file"));
                }
            }
            else {
                reader.readNext();
            }
        }
        file.close();
        if (reader.hasError()) {
            QMessageBox::critical(0, "Kevora Xml", QObject::tr("Error: Failed to parse file")+" "+fileName+". "+file.errorString());
            return false;
        }
        else if (file.error() != QFile::NoError) {
            QMessageBox::critical(0, "Kevora Xml", QObject::tr("Error: Can't read file")+" "+fileName+". "+file.errorString());
            return false;
        }
        return true;
    }
    else {
        return false;
    }
}

void KvXmlStreamReader::readKvXmlElement() {
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }
        if (reader.isStartElement()) {
            if (reader.name() == tagLevelArray.value(0)) {
                readEntryElement(treeWidget->invisibleRootItem(), 0);
            }
            else {
                skipUnknownElement();
            }
        }
        else {
            reader.readNext();
        }
    }
}

void KvXmlStreamReader::readEntryElement(QTreeWidgetItem *parent, int level) {
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);

    int itemColumnCount = item->treeWidget()->columnCount();
    for (int c=0; c<itemColumnCount; ++c) {
        QString tagForColumn = tagArray.value(level).value(c);
        if (!tagForColumn.isEmpty())
            item->setText(c, reader.attributes().value(tagForColumn).toString());
    }

    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }
        if (reader.isStartElement()) {
            if (reader.name() == tagLevelArray.value(level+1)) {
                readEntryElement(item, level+1);
            }
            else {
                skipUnknownElement();
            }
        }
        else {
            reader.readNext();
        }
    }
}

void KvXmlStreamReader::skipUnknownElement() {
    reader.readNext();
    while(!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }
        if (reader.isStartElement()) {
            skipUnknownElement();
        }
        else {
            reader.readNext();
        }
    }
}
