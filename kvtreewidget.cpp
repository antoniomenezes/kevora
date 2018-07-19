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

#include "kvtreewidget.h"

KvTreeWidget::KvTreeWidget(QWidget *parent): QTreeWidget(parent) {
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setSelectionBehavior(QAbstractItemView::SelectItems);
    setVisibleObjectsSession();
}

void KvTreeWidget::setDatabaseConnectionsTree() {
    databaseConnectionsTree = true;
    databaseObjectsTree = false;
    // Hide all columns, except the first and the second one
    for (int i=2; i< this->columnCount(); ++i) {
        hideColumn(i);
    }
    setContextMenuPolicy(Qt::ActionsContextMenu);
    qRegisterMetaType<QTreeWidgetItem>("QTreeWidgetItem");
    connect(this, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), this, SLOT(currentDatabaseItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)));
    connect(this, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(onItemExpanded(QTreeWidgetItem*)));
}

void KvTreeWidget::setDatabaseObjectsTree(KvTreeWidget *dbTreeWidget, KvTreeWidget::ObjTreeTypes kind) {
    if (dbTreeWidget->isDatabaseConnectionsTree()) {
        databaseConnectionsTree = false;
        databaseObjectsTree = true;
        databaseTreeWidget = dbTreeWidget;
        objTreeKind = kind;
        hideColumn( 2 );
        hideColumn( 3 );
        hideColumn( 4 );
        hideColumn( 5 );
        setContextMenuPolicy(Qt::ActionsContextMenu);
        qRegisterMetaType<QTreeWidgetItem>("QTreeWidgetItem");
        connect(this, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), this, SLOT(currentDatabaseItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)));
        connect(this, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(onItemExpanded(QTreeWidgetItem*)));
        connect(databaseTreeWidget, SIGNAL(databaseTreeConnectionOff(QString, QString)), this, SLOT(turnConnectionOff(QString, QString)));
        connect(this, SIGNAL(objectTreeConnectionOff(QString, QString)), databaseTreeWidget, SLOT(turnConnectionOff(QString, QString)));
    }
}

KvTreeWidget::ObjTreeTypes KvTreeWidget::getObjTreeType() {
    return objTreeKind;
}

bool KvTreeWidget::isDatabaseConnectionsTree() {
    return databaseConnectionsTree;
}

bool KvTreeWidget::isDatabaseObjectsTree() {
    return databaseObjectsTree;
}

void KvTreeWidget::addDatabaseItem(QString alias, QString dbType, QString host, QString port, QString dbName, QString driver, QString comments)
{
    if (databaseConnectionsTree) {
        if (this->findItems( alias, Qt::MatchExactly).count() == 0) {
            QStringList itemColumnValues;
            itemColumnValues << alias;
            itemColumnValues << dbType;
            itemColumnValues << host;
            itemColumnValues << port;
            itemColumnValues << dbName;
            itemColumnValues << driver;
            itemColumnValues << comments;
            QTreeWidgetItem *item = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
            this->addTopLevelItem ( item );
            item->setIcon( 0, QIcon(":/png/png_general/database.png") );
            resizeColumnToContents(0);
            setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
        }
    }
}

void KvTreeWidget::addConnectionItem(QString alias, QString userName, QString password, QString savePassword, QString autoLogon)
{
    if (databaseConnectionsTree) {
        if ((getDatabaseItem(alias) != NULL) && (getConnectionItem(alias, userName) == NULL)) {
            QStringList itemColumnValues;
            itemColumnValues << userName;
            itemColumnValues << "";
            itemColumnValues << password;
            itemColumnValues << savePassword;
            itemColumnValues << autoLogon;

            QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
            itemChild->setIcon( 0, QIcon(":/png/png_general/db_connection.png") );
            QTreeWidgetItem *current = getDatabaseItem(alias);
            if (current->parent() != NULL) {
                while (current->parent() != NULL) {
                    current = current->parent();
                }
            }
            if (current->parent() == NULL) {
                current->addChild( itemChild );
            }

            setCurrentItem( itemChild );
            doItemsLayout();
        }
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + getConnectionItem(alias, userName)->icon(0).actualSize(QSize(16,16)).width() );
    }
}

void KvTreeWidget::updateIcons()
{
    if (databaseConnectionsTree) {
        for(int i=0; i<this->topLevelItemCount(); i++) {
            QTreeWidgetItem *item = topLevelItem(i);
            item->setIcon(0, QIcon(":/png/png_general/database.png") );
            for(int c=0; c<item->childCount(); c++) {
                item->child(c)->setIcon(0, QIcon(":/png/png_general/db_connection.png") );
                //item->child(c)->setText(2, item->child(c)->text(2).toLocal8Bit().toHex());
            }
        }
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + topLevelItem(0)->icon(0).actualSize(QSize(16,16)).width() );
    }
}

void KvTreeWidget::addObjectConnectionItem(QString connectionName, QString userName)
{
    if (databaseObjectsTree) {
        QString objConnectionName = userName+QString("@")+connectionName;
        if (getConnectionItem(connectionName, userName) == NULL) {
            QStringList itemColumnValues;
            itemColumnValues << objConnectionName;
            QTreeWidgetItem *item = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
            this->addTopLevelItem ( item );
            item->setIcon( 0, QIcon(":/png/png_general/database_on.png") );
            resizeColumnToContents(0);
            setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
            if ((objConnectionName.compare(visibleObjectsSession) == 0) || (visibleObjectsSession.trimmed().isEmpty()))
                item->setHidden(false);
            else
                item->setHidden(true);
        }
    }
}

void KvTreeWidget::addSchemaItems(QString connectionName, QString userName, QStringList schemas)
{
    if (databaseObjectsTree) {
        if ( databaseTreeWidget->isConnectionOn(connectionName, userName) ) {
            QString objConnectionName = userName+QString("@")+connectionName;
            // if connection does not exist, please create it on
            addObjectConnectionItem(connectionName, userName);
            QTreeWidgetItem *current = getConnectionItem(connectionName, userName);
            if (current != NULL) {
                for (int i = 0; i < schemas.size(); ++i) {
                    QStringList list;
                    list << objConnectionName << schemas.at(i);
                    if (getObjectItem(list) == NULL) {
                        QStringList itemColumnValues;
                        itemColumnValues << schemas.at(i);
                        QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
                        itemChild->setToolTip(0, schemas.at(i));
                        itemChild->setIcon( 0, QIcon(":/png/png_general/folder_database.png") );
                        current->addChild( itemChild );
                        QTreeWidgetItem *emptyItem = new QTreeWidgetItem ( itemChild, QTreeWidgetItem::Type );
                    }
                }
            }
            resizeColumnToContents(0);
            setColumnWidth ( 0, columnWidth(0) + current->icon(0).actualSize(QSize(16,16)).width() );
        }
    }
}

void KvTreeWidget::removeDatabaseItem(QString alias)
{
    if (databaseConnectionsTree) {
        QList<QTreeWidgetItem *> items = this->findItems( alias, Qt::MatchExactly);
        if (items.count() > 0) {
            QMessageBox questionBox;
            questionBox.setWindowTitle( tr("Confirmation") );
            questionBox.setText( tr("Remove Database Definition")+" "+alias+" ?" );
            questionBox.setIcon( QMessageBox::Question );
            QPushButton *yesButton = questionBox.addButton( tr("Yes"), QMessageBox::YesRole );
            QPushButton *noButton = questionBox.addButton( tr("No"), QMessageBox::NoRole );
            questionBox.setDefaultButton( noButton );
            questionBox.exec();
            if (questionBox.clickedButton() == yesButton) {
                for(int i=0; i<items.count(); i++) {
                    this->removeItemWidget( items.at(i), 1);
                    delete items.at(i);
                }
                resizeColumnToContents(0);
                if (this->topLevelItemCount() > 0)
                    setColumnWidth ( 0, columnWidth(0) + topLevelItem(0)->icon(0).actualSize(QSize(16,16)).width() );
            }
        }
    }
}

void KvTreeWidget::removeConnectionItem(QString connectionName, QString userName)
{
    if (databaseConnectionsTree) {
        QTreeWidgetItem *connItem = getConnectionItem(connectionName, userName);
        if (QString::compare(connItem->text(0), userName, Qt::CaseSensitive) == 0) {
            QMessageBox questionBox;
            questionBox.setWindowTitle( tr("Confirmation") );
            questionBox.setText( tr("Remove connection for user")+" "+connItem->text(0)+" ?" );
            questionBox.setIcon( QMessageBox::Question );
            QPushButton *yesButton = questionBox.addButton( tr("Yes"), QMessageBox::YesRole );
            QPushButton *noButton = questionBox.addButton( tr("No"), QMessageBox::NoRole );
            questionBox.setDefaultButton( noButton );
            questionBox.exec();
            if (questionBox.clickedButton() == yesButton) {
                removeItemWidget( connItem, 1);
                delete connItem;
            }
            return;
        }
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + topLevelItem(0)->icon(0).actualSize(QSize(16,16)).width() );
    }
    else if (databaseObjectsTree) {
        QTreeWidgetItem *connItem = getConnectionItem(connectionName, userName);
        if (connItem != NULL) {
            delete connItem;
            emit objectTreeConnectionOff(connectionName, userName);
        }
    }
}

void KvTreeWidget::turnConnectionOff(QString connectionName, QString userName) {
    if (databaseConnectionsTree) {
        setConnectionItemOn(connectionName, userName, false);
    }
    else if (databaseObjectsTree) {
        removeConnectionItem(connectionName, userName);
    }
}

bool KvTreeWidget::isConnectionOn(QString alias, QString userName)
{
    if (databaseConnectionsTree) {
        QTreeWidgetItem *connItem = getConnectionItem(alias, userName);
        if (connItem != NULL) {
            if (connItem->text(5).contains("ON"))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    return false;
}

void KvTreeWidget::setConnectionItemOn(QString aliasOrSession, QString userName, bool connected)
{
    if (databaseConnectionsTree) {
        QTreeWidgetItem *connItem;
        QString alias = aliasOrSession;
        QString user = userName;
        if (aliasOrSession.contains("@", Qt::CaseInsensitive)) {
            QStringList list = aliasOrSession.split("@",QString::KeepEmptyParts);
            alias = list.at(1);
            user = list.at(0);
        }
        connItem = getConnectionItem(alias, user);
        if (connItem != NULL) {
            if (connected) {
                connItem->setIcon( 0, QIcon(":/png/png_general/database_on.png") );
                connItem->setText(5, "ON");
            }
            else {
                connItem->setIcon( 0, QIcon(":/png/png_general/db_connection.png") );
                connItem->setText(5, "OFF");
                emit databaseTreeConnectionOff(alias, user);
                setConnectionItemOnWorking(alias, user, false);
            }
        }
    }
}

void KvTreeWidget::setConnectionItemOnWorking(QString alias, QString userName, bool working, QString messageWorking)
{
    if (databaseConnectionsTree) {
        QTreeWidgetItem *connItem = getConnectionItem(alias, userName);
        if (connItem != NULL) {
            if (working) {
                //QProgressIndicator *animation = new QProgressIndicator();
                KvWaitAnimation *animation = new KvWaitAnimation();
                if (! messageWorking.isEmpty())
                    animation->setToolTip(messageWorking);
                //animation->setColor(Qt::red);
                //animation->setAnimationDelay(100);

                //animation->setRightAlignment(true);

                //animation->startAnimation();
                animation->start();
                //connItem->setIcon(0, QIcon());
                resizeColumnToContents(0);
                setColumnWidth ( 0, columnWidth(0) + connItem->icon(0).actualSize(QSize(16,16)).width() );
                setItemWidget(connItem, 0, animation);
            }
            else {
                KvWaitAnimation *animation = (KvWaitAnimation *) itemWidget(connItem, 1);
                //QProgressIndicator *animation = (QProgressIndicator *) itemWidget(connItem, 0);
                setItemWidget(connItem, 0, NULL);
                if (animation) {
                    animation->stop();
                    delete animation;
                }
            }
        }
    }
}

void KvTreeWidget::setObjectItemOnWorking(QStringList objectFamilyList, bool working, QString messageWorking)
{
    if (databaseObjectsTree) {
        QTreeWidgetItem *objectItem = getObjectItem(objectFamilyList);
        setObjectItemOnWorking(objectItem, working, messageWorking);
    }
}

void KvTreeWidget::setObjectItemOnWorking(QTreeWidgetItem *objectItem, bool working, QString messageWorking)
{
    if (databaseObjectsTree) {
        if (objectItem != NULL) {
            if (working) {
                KvWaitAnimation *animation = new KvWaitAnimation();
                //animation->resize(QSize(16,16));
                if (! messageWorking.isEmpty())
                    animation->setToolTip(messageWorking);
                //animation->setColor(Qt::red);
                //animation->setAnimationDelay(100);

                //animation->setRightAlignment(true);

                animation->start();
                //objectItem->setIcon(1, QIcon());
                resizeColumnToContents(0);
                setColumnWidth ( 0, columnWidth(0) + objectItem->icon(0).actualSize(QSize(16,16)).width() );
                setItemWidget(objectItem, 0, animation);
            }
            else {
                KvWaitAnimation *animation = (KvWaitAnimation *) itemWidget(objectItem, 0);
                setItemWidget(objectItem, 0, NULL);
                if (animation) {
                    animation->stop();
                    delete animation;
                }
            }
        }
    }
}

void KvTreeWidget::setConnectionMessageOnWorking(QString alias, QString userName, QString messageWorking)
{
    QTreeWidgetItem *connItem = getConnectionItem(alias, userName);
    if (itemWidget(connItem, 1) != NULL) {
        KvWaitAnimation *animation = (KvWaitAnimation *) itemWidget(connItem, 1);
        if (animation) {
            if (! messageWorking.isEmpty())
                animation->setToolTip(messageWorking);
        }
    }
}

void KvTreeWidget::setConnectionItemError(QString alias, QString userName, QString errorText)
{
    if (databaseConnectionsTree) {
        if ((errorText.isNull()) || (errorText.trimmed().isEmpty())) {
            QTreeWidgetItem *connItem = getConnectionItem(alias, userName);
            connItem->setIcon(0, QIcon(":/png/png_general/db_connection.png") );
            connItem->setToolTip(0, NULL );
            disconnect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemErrorClicked(QTreeWidgetItem*, int)));
        }
        else {
            setConnectionItemOnWorking(alias, userName, false);
            QTreeWidgetItem *connItem = getConnectionItem(alias, userName);
            connItem->setIcon(0, QIcon(":/png/png_general/error.png") );
            connItem->setToolTip(0, errorText );
            connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemErrorClicked(QTreeWidgetItem*, int)));
        }
    }
}

void KvTreeWidget::itemErrorClicked(QTreeWidgetItem *item, int column)
{
    if (! item->icon(0).isNull())
        QToolTip::showText( QCursor::pos(), item->toolTip(0), itemWidget(item, 0));
}

QTreeWidgetItem* KvTreeWidget::getDatabaseItem(QString alias)
{
    if (databaseConnectionsTree) {
        QList<QTreeWidgetItem *> items = this->findItems( alias, Qt::MatchExactly);
        if (items.count() > 0)
            return items.at(0);
        else
            return NULL;
    }
    else
        return NULL;
}

QTreeWidgetItem* KvTreeWidget::getConnectionItem(QString alias, QString userName)
{
    if (databaseConnectionsTree) {
        QTreeWidgetItem *dbItem = getDatabaseItem(alias);
        if (dbItem != NULL) {
            for (int i=0; i<dbItem->childCount(); i++) {
                QTreeWidgetItem *connItem = dbItem->child(i);
                if (QString::compare(connItem->text(0), userName, Qt::CaseSensitive) == 0) {
                    return connItem;
                }
            }
            return NULL;
        }
    }
    else if (databaseObjectsTree) {
        QString session;
        if (alias.contains("@", Qt::CaseInsensitive))
            session = alias;
        else
            session = userName+QString("@")+alias;
        QList<QTreeWidgetItem *> items = this->findItems(session, Qt::MatchExactly);
        if (items.count() > 0)
            return items.at(0);
        else
            return NULL;
    }
    else
        return NULL;
}

QTreeWidgetItem* KvTreeWidget::getChildItem(QTreeWidgetItem *parent, QString textChild) {
    QTreeWidgetItem *child = NULL;
    for (int i=0; i<parent->childCount(); ++i) {
        child = parent->child(i);
        if (QString::compare(child->text(0), textChild, Qt::CaseSensitive) == 0) {
            return child;
        }
    }
    if ((child != NULL) && (QString::compare(child->text(0), textChild, Qt::CaseSensitive) != 0)) {
        child = NULL;
    }
    return child;
}

QTreeWidgetItem* KvTreeWidget::getObjectItem(QStringList objectFamilyList)
{
    QTreeWidgetItem* current = NULL;
    if (databaseObjectsTree) {
        if (objectFamilyList.size() > 0) {
            QList<QTreeWidgetItem*> list = findItems( objectFamilyList.at(0), Qt::MatchExactly);
            if (list.size() > 0) {
                current = list.at(0);
                for (int i=1; ((i<objectFamilyList.size()) && (current != NULL)); ++i) {
                    current = getChildItem(current, objectFamilyList.at(i));
                }
            }
            else
                current = NULL;
        }
        else {
            current = NULL;
        }
    }
    else
        current = NULL;
    return current;
}

QString KvTreeWidget::getDbTypeFromDatabaseItem(QString connectionName)
{
    if (databaseConnectionsTree) {
        if (getDatabaseItem(connectionName) != NULL)
            return getDatabaseItem(connectionName)->text(1);
        else
            return QString();
    }
    else
        return QString();
}

void KvTreeWidget::addDatabaseItemAction(QAction *action)
{
    if (databaseConnectionsTree) {
        databaseItemActions.append(action);
    }
}

void KvTreeWidget::addConnectionItemAction(QAction *action)
{
    if ((databaseConnectionsTree) || (databaseObjectsTree)) {
        connectionItemActions.append(action);
    }
}

void KvTreeWidget::addSchemaItemAction(QAction *action)
{
    if (databaseObjectsTree) {
        schemaItemActions.append(action);
    }
}

void KvTreeWidget::addObjectGroupItemAction(QAction *action)
{
    if (databaseObjectsTree) {
        objectGroupItemActions.append(action);
    }
}

void KvTreeWidget::addObjectItemAction(QAction *action)
{
    if (databaseObjectsTree) {
        objectItemActions.append(action);
    }
}

void KvTreeWidget::currentDatabaseItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if (databaseConnectionsTree) {
        if (current) {
            foreach (QAction *action, actions()) {
                removeAction(action);
            }
            if (current->parent() != NULL) {
                addActions(connectionItemActions);
            }
            else {
                addActions(databaseItemActions);
            }
        }
    }
    else if (databaseObjectsTree) {
        if (current) {
            foreach (QAction *action, actions()) {
                removeAction(action);
            }
            if (current->parent() == NULL) {
                addActions(connectionItemActions);
            }
            else if (current->parent()->parent() == NULL) {
                addActions(schemaItemActions);
            }
            else if ((current->parent()->parent()->parent() == NULL) && (getObjTreeType() == KvTreeWidget::DatabaseProgramsTree || getObjTreeType() == KvTreeWidget::DatabaseEtcTree)) {
                addActions(objectGroupItemActions);
            }
            else {
                addActions(objectItemActions);
            }
        }
    }
}

int KvTreeWidget::itemLevel(QTreeWidgetItem *item)
{
    int level = 0;
    QTreeWidgetItem *itemSearch = item;
    while(itemSearch->parent()) {
        itemSearch = itemSearch->parent();
        level++;
    }
    return level;
}

void KvTreeWidget::onItemExpanded(QTreeWidgetItem *item)
{
    if (databaseConnectionsTree) {
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
        resizeColumnToContents(1);
    }
    else {
        setObjectItemOnWorking(item, true);
        if ((item->childCount() == 1) && (item->child(0)->text(0).isEmpty())) {
            delete item->child(0);
            if (databaseObjectsTree) {
                if (getObjTreeType() == KvTreeWidget::DatabaseTablesTree || getObjTreeType() == KvTreeWidget::DatabaseViewsTree) {
                    // When schema item expanded, get its table names...
                    emit getObjectsOfSchemaSignal(item, item->parent()->text(0), item->text(0));
                }
                else if (getObjTreeType() == KvTreeWidget::DatabaseProgramsTree || getObjTreeType() == KvTreeWidget::DatabaseEtcTree) {
                    if (itemLevel(item) == 1)
                        emit getGroupsOfSchemaSignal(item, item->parent()->text(0), item->text(0));
                    else if (itemLevel(item) == 2)
                        emit getGroupElementsOfSchemaSignal(item, item->parent()->parent()->text(0), item->parent()->text(0), item->text(0));
                }
            }
        }
        else {
            setObjectItemOnWorking(item, false);
        }
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
    }
}

void KvTreeWidget::gotObjectsOfSchemaSlot(QTreeWidgetItem *item, const QString &schema, QStringList objects)
{
    if (databaseObjectsTree) {
        // Clear previous children of item Schema
        QList<QTreeWidgetItem *> children = item->takeChildren();
        foreach(QTreeWidgetItem * child, children)
            delete child;

        if (getObjTreeType() == KvTreeWidget::DatabaseTablesTree) {
            for (int i = 0; i < objects.size(); ++i) {
                // If this Tree Widget Item does not have any of those tables, so continue...
                //if (getChildItem(item, objects.at(i)) == NULL) {
                    QStringList itemColumnValues;
                    itemColumnValues << objects.at(i);
                    QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
                    itemChild->setToolTip(0, objects.at(i));
                    itemChild->setIcon( 0, QIcon(":/png/png_general/table.png") );
                    item->addChild( itemChild );
                    if (i % 10 == 0) {
                        resizeColumnToContents(0);
                        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
                        qApp->processEvents();
                    }
                //}
            }
        }
        else if (getObjTreeType() == KvTreeWidget::DatabaseViewsTree) {
            for (int i = 0; i < objects.size(); ++i) {
                //if (getChildItem(item, objects.at(i)) == NULL) {
                    QStringList itemColumnValues;
                    itemColumnValues << objects.at(i);
                    QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
                    itemChild->setToolTip(0, objects.at(i));
                    itemChild->setIcon( 0, QIcon(":/png/png_general/view.png") );
                    item->addChild( itemChild );
                    if (i % 10 == 0) {
                        resizeColumnToContents(0);
                        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
                        qApp->processEvents();
                    }
                //}
            }
        }
        setObjectItemOnWorking(item, false);
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
    }
}

void KvTreeWidget::gotGroupsOfSchemaSlot(QTreeWidgetItem *item, const QString &schema, QStringList objects)
{
    if (databaseObjectsTree) {
        // Clear previous children of item Schema
        QList<QTreeWidgetItem *> children = item->takeChildren();
        foreach(QTreeWidgetItem * child, children)
            delete child;

        if (getObjTreeType() == KvTreeWidget::DatabaseProgramsTree) {
            for (int i = 0; i < objects.size(); ++i) {
                //if (getChildItem(item, objects.at(i)) == NULL) {
                    QStringList itemColumnValues;
                    itemColumnValues << objects.at(i);
                    QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
                    itemChild->setIcon( 0, QIcon(":/png/png_general/folder_page.png") );
                    itemChild->setToolTip(0, objects.at(i));
                    item->addChild( itemChild );
                    QTreeWidgetItem *emptyItem = new QTreeWidgetItem ( itemChild, QTreeWidgetItem::Type );
                //}
            }
        }
        else if (getObjTreeType() == KvTreeWidget::DatabaseEtcTree) {
            for (int i = 0; i < objects.size(); ++i) {
                //if (getChildItem(item, objects.at(i)) == NULL) {
                    QStringList itemColumnValues;
                    itemColumnValues << objects.at(i);
                    QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
                    if (((QString)objects.at(i)).compare("RECYCLE BIN", Qt::CaseInsensitive) == 0)
                        itemChild->setIcon( 0, QIcon(":/png/png_general/trash.png") );
                    else
                        itemChild->setIcon( 0, QIcon(":/png/png_general/folder_brick.png") );
                    itemChild->setToolTip(0, objects.at(i));
                    item->addChild( itemChild );
                    QTreeWidgetItem *emptyItem = new QTreeWidgetItem ( itemChild, QTreeWidgetItem::Type );
                //}
            }
        }
        setObjectItemOnWorking(item, false);
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
    }
}

void KvTreeWidget::gotGroupElementsOfSchemaSlot(QTreeWidgetItem *item, const QString &schema, const QString &type, QList< QPair<QString,QString> > objects)
{
    if (databaseObjectsTree) {
        // Clear previous children of item Schema
        QList<QTreeWidgetItem *> children = item->takeChildren();
        foreach(QTreeWidgetItem * child, children)
            delete child;

        if (getObjTreeType() == KvTreeWidget::DatabaseProgramsTree) {
            for (int i = 0; i < objects.size(); ++i) {
                QPair<QString,QString> pair = objects.at(i);
                //if (getChildItem(item, pair.first) == NULL) {
                    QStringList itemColumnValues;
                    itemColumnValues << pair.first;
                    QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
                    itemChild->setToolTip(0, pair.first);
                    if (pair.second.contains("Y"))
                        itemChild->setIcon( 0, QIcon(":/png/png_general/page.png") );
                    else if (pair.second.contains("N")) {
                        itemChild->setIcon( 0, QIcon(":/png/png_general/page_error.png") );
                        QString alertMessage = itemChild->text(0)+" "+tr("is invalid");
                        itemChild->setToolTip(0, alertMessage);
                    }
                    item->addChild( itemChild );
                    if (i % 10 == 0) {
                        resizeColumnToContents(0);
                        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
                        qApp->processEvents();
                    }
                //}
            }
        }
        else if (getObjTreeType() == KvTreeWidget::DatabaseEtcTree) {
            for (int i = 0; i < objects.size(); ++i) {
                QPair<QString,QString> pair = objects.at(i);
                //if (getChildItem(item, pair.first) == NULL) {
                    QStringList itemColumnValues;
                    itemColumnValues << pair.first;
                    QTreeWidgetItem *itemChild = new QTreeWidgetItem ( itemColumnValues, QTreeWidgetItem::Type );
                    itemChild->setToolTip(0, pair.first);
                    if (pair.second.contains("Y"))
                        itemChild->setIcon( 0, QIcon(":/png/png_general/brick.png") );
                    else if (pair.second.contains("N")) {
                        itemChild->setIcon( 0, QIcon(":/png/png_general/brick_error.png") );
                        QString alertMessage = itemChild->text(0)+" "+tr("is invalid");
                        itemChild->setToolTip(0, alertMessage);
                    }
                    item->addChild( itemChild );
                    if (i % 10 == 0) {
                        resizeColumnToContents(0);
                        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
                        qApp->processEvents();
                    }
                //}
            }
        }
        setObjectItemOnWorking(item, false);
        resizeColumnToContents(0);
        setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
    }
}

void KvTreeWidget::setVisibleObjectsSession(QString connectionNameWithUser)
{
    visibleObjectsSession = connectionNameWithUser;
    if (databaseObjectsTree) {
        if (visibleObjectsSession.trimmed().isEmpty()) {
            for (int i = 0; i < topLevelItemCount(); ++i) {
                QTreeWidgetItem *item = topLevelItem(i);
                item->setHidden( false );
                resizeColumnToContents(0);
                setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
            }
        }
        else {
            for (int i = 0; i < topLevelItemCount(); ++i) {
                QTreeWidgetItem *item = topLevelItem(i);
                if (item->text(0).compare(visibleObjectsSession) != 0) {
                    item->setHidden( true );
                }
                else {
                    item->setHidden( false );
                    resizeColumnToContents(0);
                    setColumnWidth ( 0, columnWidth(0) + item->icon(0).actualSize(QSize(16,16)).width() );
                }
            }
        }
    }
}

