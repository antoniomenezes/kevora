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

#ifndef KVTREEWIDGET_H
#define KVTREEWIDGET_H

#include <QTreeWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QAction>
#include <QToolTip>
#include <QColor>
//#include "thirdparty/QProgressIndicator.h"
#include "kvwaitanimation.h"

/**
  Kevora TreeWidget:
  It is a special kind of tree only for Kevora's TreeWigets.
  This is not a general type of QTreeWidget.
*/
class KvTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    enum ObjTreeTypes { DatabaseTablesTree, DatabaseViewsTree, DatabaseProgramsTree, DatabaseEtcTree };

    explicit KvTreeWidget(QWidget *parent = 0);
    void setDatabaseConnectionsTree();
    void setDatabaseObjectsTree(KvTreeWidget *dbTreeWidget, KvTreeWidget::ObjTreeTypes kind);
    KvTreeWidget::ObjTreeTypes getObjTreeType();
    bool isDatabaseConnectionsTree();
    bool isDatabaseObjectsTree();
    int  itemLevel(QTreeWidgetItem *item);
    void addDatabaseItem(QString alias, QString dbType, QString host, QString port, QString dbName, QString driver, QString comments);
    void addConnectionItem(QString alias, QString userName, QString password, QString savePassword, QString autoLogon);
    void updateIcons();
    void addObjectConnectionItem(QString connectionName, QString userName);
    void addSchemaItems(QString connectionName, QString userName, QStringList schemas);
    void removeDatabaseItem(QString alias);
    void removeConnectionItem(QString connectionName, QString userName);
    QTreeWidgetItem* getDatabaseItem(QString alias);
    QTreeWidgetItem* getConnectionItem(QString alias, QString userName);
    QTreeWidgetItem* getChildItem(QTreeWidgetItem *parent, QString textChild);
    QTreeWidgetItem* getObjectItem(QStringList objectFamilyList);
    QString getDbTypeFromDatabaseItem(QString connectionName);
    void setConnectionItemOn(QString aliasOrSession, QString userName, bool connected);
    void setConnectionItemOnWorking(QString alias, QString userName, bool working, QString messageWorking = "");
    bool isConnectionOn(QString alias, QString userName);
    void setObjectItemOnWorking(QStringList objectFamilyList, bool working, QString messageWorking = "");
    void setObjectItemOnWorking(QTreeWidgetItem *objectItem, bool working, QString messageWorking = "");
    void setConnectionMessageOnWorking(QString alias, QString userName, QString messageWorking);
    void setConnectionItemError(QString alias, QString userName, QString errorText = NULL);
    void addDatabaseItemAction(QAction *action);
    void addConnectionItemAction(QAction *action);
    void addSchemaItemAction(QAction *action);
    void addObjectGroupItemAction(QAction *action);
    void addObjectItemAction(QAction *action);
    void setVisibleObjectsSession(QString connectionNameWithUser = "");
public slots:
    void currentDatabaseItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void onItemExpanded(QTreeWidgetItem *item);
    void itemErrorClicked(QTreeWidgetItem *item, int column);
    void turnConnectionOff(QString connectionName, QString userName);
    void gotObjectsOfSchemaSlot(QTreeWidgetItem *item, const QString &schema, QStringList objects);
    void gotGroupsOfSchemaSlot(QTreeWidgetItem *item, const QString &schema, QStringList objects);
    void gotGroupElementsOfSchemaSlot(QTreeWidgetItem *item, const QString &schema, const QString &type, QList< QPair<QString,QString> > objects);
private:
    QList<QAction *> databaseItemActions;
    QList<QAction *> connectionItemActions;
    QList<QAction *> schemaItemActions;
    QList<QAction *> objectGroupItemActions;
    QList<QAction *> objectItemActions;
    bool databaseConnectionsTree;
    bool databaseObjectsTree;
    KvTreeWidget *databaseTreeWidget;
    KvTreeWidget::ObjTreeTypes objTreeKind;
    QString visibleObjectsSession;
signals:
    void databaseTreeConnectionOff(const QString &connectionName, const QString &userName);
    void objectTreeConnectionOff(const QString &connectionName, const QString &userName);
    void getObjectsOfSchemaSignal(QTreeWidgetItem *item, const QString &connectionName, const QString &schema);
    void getGroupsOfSchemaSignal(QTreeWidgetItem *item, const QString &connectionName, const QString &schema);
    void getGroupElementsOfSchemaSignal(QTreeWidgetItem *item, const QString &connectionName, const QString &schema, const QString &type);
};

#endif // KVTREEWIDGET_H
