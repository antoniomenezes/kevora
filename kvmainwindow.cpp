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

#include "kvmainwindow.h"
#include "ui_kvmainwindow.h"
#include "kvsettingsdialog.h"

KvMainWindow::KvMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::KvMainWindow)
{
    ui->setupUi(this);
    connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(exitSlot()));

    KvSettings::restoreMainWindowSettings(this);
    KvSettings::restoreWidgetGeometry(this);
    workPath = KvSettings::getDefaultWorkPath();
    //ui->retranslateUi();

    // A Gradient decoration for mdiArea
    bgGradient = QLinearGradient( 0, 0, this->width(), this->height());
    QColor darkBg = ui->mdiArea->background().color();
    int redDarkBg = 0;
    int greenDarkBg = 0;
    int blueDarkBg = 0;
    if (darkBg.red()-100 > 0)
        redDarkBg = darkBg.red()-100;
    if (darkBg.red()-100 > 0)
        greenDarkBg = darkBg.green()-100;
    if (darkBg.blue()-100 > 0)
        blueDarkBg = darkBg.blue()-100;

    darkBg.setRgb(redDarkBg, greenDarkBg, blueDarkBg);
    bgGradient.setColorAt(0, ui->mdiArea->background().color()); // Qt::lightGray);
    bgGradient.setColorAt(1, darkBg); //QColor(109, 109, 112));
    //bgGradient.setColorAt(1, Qt::darkGray);
    bgGradient.setStart(0, 0);
    bgGradient.setFinalStop(0, this->height());
    ui->mdiArea->setBackground(bgGradient);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(workPath);

    ui->fileTreeView->setModel(fileModel);
    ui->fileTreeView->setCurrentIndex(fileModel->index(workPath));
    ui->fileTreeView->hideColumn(1);
    ui->fileTreeView->hideColumn(2);
    ui->fileTreeView->hideColumn(3);
    ui->fileTreeView->expand(ui->fileTreeView->currentIndex());
    ui->fileTreeView->sortByColumn(0, Qt::AscendingOrder);
    ui->fileTreeView->resizeColumnToContents(0);

    ui->dbTreeWidget->setDatabaseConnectionsTree();
    ui->tableTreeWidget->setDatabaseObjectsTree(ui->dbTreeWidget, KvTreeWidget::DatabaseTablesTree);
    ui->viewTreeWidget->setDatabaseObjectsTree(ui->dbTreeWidget, KvTreeWidget::DatabaseViewsTree);
    ui->programTreeWidget->setDatabaseObjectsTree(ui->dbTreeWidget, KvTreeWidget::DatabaseProgramsTree);
    ui->etcTreeWidget->setDatabaseObjectsTree(ui->dbTreeWidget, KvTreeWidget::DatabaseEtcTree);
    setupDatabaseTreeActions();

    kevoraXml = new KvXml;
    // tags for database definitions
    kevoraXml->setTagLevel(0, "entry");
    kevoraXml->setTagLevel(1, "connection");

    kevoraXml->setTag(0, 0, "alias");
    kevoraXml->setTag(0, 1, "type");
    kevoraXml->setTag(0, 2, "host");
    kevoraXml->setTag(0, 3, "port");
    kevoraXml->setTag(0, 4, "dbname");
    kevoraXml->setTag(0, 5, "driver");
    kevoraXml->setTag(0, 6, "comments");
    // tags for user connections
    kevoraXml->setTag(1, 0, "user");
    kevoraXml->setTag(1, 2, "passwd");
    kevoraXml->setTag(1, 3, "stored");
    kevoraXml->setTag(1, 4, "autoopen");

    loadXml();

    // Object Trees will be sorted by first column
    ui->tableTreeWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->viewTreeWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->programTreeWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->etcTreeWidget->sortByColumn(0, Qt::AscendingOrder);

    // Connect signals from tool buttons above db tree to already defined actions
    connect(ui->toolButtonAddDb, SIGNAL(clicked()), ui->actionAdd_Database, SLOT(trigger()));
    connect(ui->toolButtonDelDb, SIGNAL(clicked()), ui->actionDelete_Database, SLOT(trigger()));
    connect(ui->toolButtonEdit, SIGNAL(clicked()), ui->actionEdit, SLOT(trigger()));
    connect(ui->toolButtonAddConn, SIGNAL(clicked()), ui->actionAdd_Connection, SLOT(trigger()));
    connect(ui->toolButtonDelConn, SIGNAL(clicked()), ui->actionDelete_Connection, SLOT(trigger()));
    connect(ui->toolButtonOpenConn, SIGNAL(clicked()), ui->actionConnect, SLOT(trigger()));
    connect(ui->toolButtonCloseConn, SIGNAL(clicked()), ui->actionDisconnect, SLOT(trigger()));
    connect(ui->toolButtonCloseAllConn, SIGNAL(clicked()), ui->actionDisconnectAll, SLOT(trigger()));

    connect(ui->mdiArea, SIGNAL(openFileSignal(QString)), this, SLOT(openFile(QString)));

    QList<QDockWidget *> tabifiedList = tabifiedDockWidgets(ui->navigatorDockWidget);
    if (tabifiedList.count() > 0)
        ui->navigatorDockWidget->raise();
    ui->listWidgetWindows->addAction(ui->actionClose);
    windowCounter = ui->mdiArea->subWindowList().count();

    updateViewMenu();

    // Start auto-logon connections
    execAutoLogon();

    setAcceptDrops(false);
    ui->centralWidget->setAcceptDrops(false);
    ui->mdiArea->setAcceptDrops(true);

    ui->mdiArea->setViewMode(QMdiArea::TabbedView);

    QList<QTabBar*> tabs = ui->mdiArea->findChildren<QTabBar*>();
    Q_FOREACH (QTabBar* tab, tabs) {
        if (tab->parent() == ui->mdiArea) {
            tab->setTabsClosable(true);
            connect(tab, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
        }
    }

}

void KvMainWindow::exitSlot()
{
    ui->actionClose_All_Windows->trigger();
    /*
    while(ui->mdiArea->subWindowList().size() > 0) {
        ui->actionClose_All_Windows->trigger();
    }*/
    close();
}

void KvMainWindow::setupDatabaseTreeActions()
{
    ui->dbTreeWidget->addDatabaseItemAction(ui->actionAdd_Database);
    ui->dbTreeWidget->addDatabaseItemAction(ui->actionAdd_Connection);
    ui->dbTreeWidget->addDatabaseItemAction(ui->actionEdit);
    ui->dbTreeWidget->addDatabaseItemAction(ui->actionDelete_Database);

    ui->dbTreeWidget->addConnectionItemAction(ui->actionConnect);
    ui->dbTreeWidget->addConnectionItemAction(ui->actionDisconnect);
    ui->dbTreeWidget->addConnectionItemAction(ui->actionEdit);
    ui->dbTreeWidget->addConnectionItemAction(ui->actionDelete_Connection);

    ui->tableTreeWidget->addConnectionItemAction(ui->actionDisconnect);
    ui->tableTreeWidget->addConnectionItemAction(ui->actionRefresh_Schemas);
    ui->tableTreeWidget->addSchemaItemAction(ui->actionRefreshTableSchema);
    ui->tableTreeWidget->addObjectItemAction(ui->actionView_TableData);
    ui->tableTreeWidget->addObjectItemAction(ui->actionView_DDL);
    ui->tableTreeWidget->addObjectItemAction(ui->actionExport_Data);
    //ui->tableTreeWidget->addObjectItemAction(ui->actionView_TableDefinition);

    ui->viewTreeWidget->addConnectionItemAction(ui->actionDisconnect);
    ui->viewTreeWidget->addConnectionItemAction(ui->actionRefresh_Schemas);
    ui->viewTreeWidget->addSchemaItemAction(ui->actionRefreshViewSchema);
    ui->viewTreeWidget->addObjectItemAction(ui->actionView_ViewData);
    ui->viewTreeWidget->addObjectItemAction(ui->actionView_DDL);
    //ui->viewTreeWidget->addObjectItemAction(ui->actionView_ViewDefinition);

    ui->programTreeWidget->addConnectionItemAction(ui->actionDisconnect);
    ui->programTreeWidget->addConnectionItemAction(ui->actionRefresh_Schemas);
    ui->programTreeWidget->addSchemaItemAction(ui->actionRefreshProgramSchema);
    ui->programTreeWidget->addObjectGroupItemAction(ui->actionRefreshProgramSchema);
    ui->programTreeWidget->addObjectItemAction(ui->actionView_DDL);

    ui->etcTreeWidget->addConnectionItemAction(ui->actionDisconnect);
    ui->etcTreeWidget->addConnectionItemAction(ui->actionRefresh_Schemas);
    ui->etcTreeWidget->addSchemaItemAction(ui->actionRefreshEtcSchema);
    ui->etcTreeWidget->addObjectGroupItemAction(ui->actionRefreshEtcSchema);
    ui->etcTreeWidget->addObjectItemAction(ui->actionView_DDL);
}

KvMainWindow::~KvMainWindow()
{
    ui->actionClose_All_Windows->trigger();
    ui->actionDisconnectAll->trigger();
    saveXml();
    KvSettings::saveMainWindowSettings(this);
    KvSettings::saveWidgetGeometry(this);

    /*while(ui->mdiArea->subWindowList().size() > 0) {
        ui->actionClose_All_Windows->trigger();
    }*/

    /*
#ifdef Q_OS_LINUX
    while (dbThreadMap.count() > 0) {
        foreach(KvThread *sessionThread, dbThreadMap.values()) {
            if (sessionThread) {
                sessionThread->quit();
                sessionThread->wait();
                while(sessionThread->isRunning()) {
                    // wait
                }
                delete sessionThread;
            }
        }
    }
#endif
    */

    delete kevoraXml;
    delete ui;
}

void KvMainWindow::updateViewMenu()
{
    ui->actionNavigator->setChecked(false);
    ui->actionObjects->setChecked(false);
    ui->actionWindow_List->setChecked(false);
    ui->actionWork_Path->setChecked(false);

    if (ui->navigatorDockWidget->isVisible())
        ui->actionNavigator->setChecked(true);
    if (ui->objectsDockWidget->isVisible())
        ui->actionObjects->setChecked(true);
    if (ui->winListDockWidget->isVisible())
        ui->actionWindow_List->setChecked(true);
    if (ui->workingDirDockWidget->isVisible())
        ui->actionWork_Path->setChecked(true);
    if (ui->mainToolBar->isVisible())
        ui->actionMain_Tool_Bar->setChecked(true);
}

void KvMainWindow::loadXml()
{
    if (dbThreadMap.count() == 0) {
        if (QFile::exists(KvSettings::getDefaultConnectionsPath()+"/kevora.xml")) {
            ui->dbTreeWidget->clear();
            QString fileName = KvSettings::getDefaultConnectionsPath()+"/kevora.xml";
            if (QFile::exists(fileName)) {
                if (kevoraXml->readXml(fileName, ui->dbTreeWidget)) {
                    ui->dbTreeWidget->updateIcons();
                }
            }
            ui->dbTreeWidget->sortItems(0, Qt::AscendingOrder);

            for(int t=0; t<ui->dbTreeWidget->topLevelItemCount(); ++t) {
                for(int c=0; c<ui->dbTreeWidget->topLevelItem(t)->childCount(); ++c) {
                    if(!ui->dbTreeWidget->topLevelItem(t)->child(c)->text(2).isEmpty())
                        ui->dbTreeWidget->topLevelItem(t)->child(c)->setText(2, QByteArray::fromHex(ui->dbTreeWidget->topLevelItem(t)->child(c)->text(2).toLocal8Bit()));
                }
            }
        }
    }
    else {
        QMessageBox::warning(this, tr("Loading Connections Alert"), tr("All sessions must be closed to load a Connections File."));
    }
}

void KvMainWindow::saveXml()
{
    // Clear temporary passwords, before saving Xml...
    for(int t=0; t<ui->dbTreeWidget->topLevelItemCount(); ++t) {
        for(int c=0; c<ui->dbTreeWidget->topLevelItem(t)->childCount(); ++c) {
            if(!ui->dbTreeWidget->topLevelItem(t)->child(c)->text(2).isEmpty())
                ui->dbTreeWidget->topLevelItem(t)->child(c)->setText(2, ui->dbTreeWidget->topLevelItem(t)->child(c)->text(2).toLocal8Bit().toHex());

            if(!ui->dbTreeWidget->topLevelItem(t)->child(c)->text(2).isEmpty() &&
                    (ui->dbTreeWidget->topLevelItem(t)->child(c)->text(3).compare("no", Qt::CaseInsensitive) == 0))
                ui->dbTreeWidget->topLevelItem(t)->child(c)->setText(2, "");
        }
    }
    QString fileName = KvSettings::getDefaultConnectionsPath()+"/kevora.xml";
    kevoraXml->writeXml(fileName, ui->dbTreeWidget);
}

void KvMainWindow::copyXml()
{
    saveXml();
    loadXml();
}

void KvMainWindow::execAutoLogon()
{
    for(int t=0; t<ui->dbTreeWidget->topLevelItemCount(); ++t) {
        for(int c=0; c<ui->dbTreeWidget->topLevelItem(t)->childCount(); ++c) {
            // For each auto-logon connection start its database thread, so starting its connection to a database
            if (ui->dbTreeWidget->topLevelItem(t)->child(c)->text(4).compare("yes", Qt::CaseInsensitive) == 0) {
                if (! ui->dbTreeWidget->topLevelItem(t)->child(c)->text(2).isEmpty()) {
                    ui->dbTreeWidget->topLevelItem(t)->setExpanded(true);
                    //ui->dbTreeWidget->topLevelItem(t)->child(c)->setSelected(true);
                    //on_actionConnect_triggered();
                    createDbThread(ui->dbTreeWidget->topLevelItem(t)->child(c)->text(0)+"@"+ui->dbTreeWidget->topLevelItem(t)->text(0));
                }
            }
        }
    }
}

void KvMainWindow::on_actionAbout_Kevora_triggered()
{
    KvAboutWindow *about = new KvAboutWindow();
    if (about->exec() == QDialog::Accepted) {
        about->close();
        delete about;
    }
}

void KvMainWindow::on_actionExit_triggered()
{
    close();
}

void KvMainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, tr("About Qt"));
}

bool KvMainWindow::isActiveConnection(QString alias, QString userName)
{
    bool result = false;
    if (userName.isEmpty()) {
        foreach (QString connection, dbThreadMap.keys()) {
            if (! result) {
                if (connection.contains("@"+alias))
                    result = dbThreadMap.value(connection)->hasOpenConnection();
            }
        }
    }
    else {
        if (dbThreadMap.contains(userName+"@"+alias))
            result = dbThreadMap.value(userName+"@"+alias)->hasOpenConnection();
    }
    return result;
}

void KvMainWindow::on_actionAdd_Database_triggered()
{
    //ui->dbTreeWidget->addDatabaseItem("DB","Oracle","localhost","1521","DB");
    QStringList values;
    KvDbDefinitionDialog *dbDefDialog = new KvDbDefinitionDialog;
    if (dbDefDialog->exec() == QDialog::Accepted) {
        values = dbDefDialog->getValues();
        ui->dbTreeWidget->addDatabaseItem(values.at(0), values.at(1), values.at(2), values.at(3), values.at(4), values.at(5), values.at(6));
    }
    delete dbDefDialog;
}

void KvMainWindow::on_actionConnect_triggered()
{
    if ((ui->dbTreeWidget->selectedItems().count() > 0) && (ui->dbTreeWidget->itemLevel(ui->dbTreeWidget->currentItem()) == 1)) {
        QString alias = ui->dbTreeWidget->currentItem()->parent()->text(0);
        QString userName = ui->dbTreeWidget->currentItem()->text(0);
        QString savePassword = ui->dbTreeWidget->currentItem()->text(3);
        QString password;

        if (! isActiveConnection(alias, userName)) {
            if (savePassword.compare("no", Qt::CaseInsensitive) == 0) {
                QInputDialog inputDialog;
                inputDialog.setWindowIcon(QIcon(":/png/png_general/db_connection.png"));
                inputDialog.setInputMode(QInputDialog::TextInput);
                inputDialog.setTextEchoMode(QLineEdit::Password);
                int charWidth = inputDialog.fontMetrics().width(tr("Logon")+" "+"("+userName+"@"+alias+")");
                //ui->statusBar->showMessage ( QString::number(charWidth) );
                inputDialog.setFixedSize(255+charWidth, 200);
                inputDialog.setWindowTitle(tr("Logon")+" "+"("+userName+"@"+alias+")");
                inputDialog.setLabelText(tr("Password"));
                if (inputDialog.exec() == QDialog::Accepted) {
                    password = inputDialog.textValue();
                    if (!password.isEmpty()) {
                        ui->dbTreeWidget->currentItem()->setText(2, password);
                        createDbThread(userName+"@"+alias);
                    }
                }
                /*
            if (ok && !password.isEmpty()) {
                ui->dbTreeWidget->currentItem()->setText(2, password);
                createDbThread(userName+"@"+alias);
            }*/
            }
            else {
                createDbThread(userName+"@"+alias);
            }
        }
    }
    else
        QMessageBox::warning(this, tr("Open Connection"), tr("Please, select the connection item you wish to open!"));
}

bool KvMainWindow::createDbThread(QString session)
{
    if (! dbThreadMap.contains(session)) {
        dbThreadMap.insert(session, new KvThread(this));
        KvThread *thread = dbThreadMap[session];
        thread->setSessionName(session);

        connect(thread, SIGNAL(startedThreadSignal(QString)), this, SLOT(startedThreadSlot(QString)));

        connect(this, SIGNAL(openDbConnectionSignal(QString,QString,QString,QString,QString,QString,QString,int)),
                thread, SLOT(openDbConnectionSlot(QString,QString,QString,QString,QString,QString,QString,int)));

        qRegisterMetaType<QSqlError>("QSqlError");
        qRegisterMetaType< QList< QPair<QString,QString> > >("QList< QPair<QString,QString> >");
        qRegisterMetaType<WId>("WId");

        connect(thread, SIGNAL(openedDbConnectionSignal(QString,QString,QString,QSqlError)),
                this, SLOT(openedDbConnectionSlot(QString,QString,QString,QSqlError)));

        connect(this, SIGNAL(closeDbConnectionSignal(QString)), thread, SLOT(closeDbConnectionSlot(QString)));
        connect(thread, SIGNAL(closedDbConnectionSignal(QString)), this, SLOT(closedDbConnectionSlot(QString)));

        connect(this, SIGNAL(cloneSessionSignal(WId, QString)), thread, SLOT(cloneSessionSlot(WId, QString)));
        connect(thread, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)),
                this, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)));

        connect(this, SIGNAL(getSchemasWithTablesSignal(QString)), thread, SLOT(getSchemasWithTablesSlot(QString)));
        connect(thread, SIGNAL(gotSchemasWithTablesSignal(QString,QString,QStringList)), this, SLOT(gotSchemasWithTablesSlot(QString,QString,QStringList)));

        connect(this, SIGNAL(getSchemasWithViewsSignal(QString)), thread, SLOT(getSchemasWithViewsSlot(QString)));
        connect(thread, SIGNAL(gotSchemasWithViewsSignal(QString,QString,QStringList)), this, SLOT(gotSchemasWithViewsSlot(QString,QString,QStringList)));

        connect(this, SIGNAL(getSchemasWithProgramsSignal(QString)), thread, SLOT(getSchemasWithProgramsSlot(QString)));
        connect(thread, SIGNAL(gotSchemasWithProgramsSignal(QString,QString,QStringList)), this, SLOT(gotSchemasWithProgramsSlot(QString,QString,QStringList)));

        connect(this, SIGNAL(getSchemasWithEtcSignal(QString)), thread, SLOT(getSchemasWithEtcSlot(QString)));
        connect(thread, SIGNAL(gotSchemasWithEtcSignal(QString,QString,QStringList)), this, SLOT(gotSchemasWithEtcSlot(QString,QString,QStringList)));

        connect(ui->tableTreeWidget, SIGNAL(getObjectsOfSchemaSignal(QTreeWidgetItem*,QString,QString)), thread, SLOT(getTablesOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
        connect(thread, SIGNAL(gotTablesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)),
                ui->tableTreeWidget, SLOT(gotObjectsOfSchemaSlot(QTreeWidgetItem*,QString,QStringList)));

        connect(ui->viewTreeWidget, SIGNAL(getObjectsOfSchemaSignal(QTreeWidgetItem*,QString,QString)), thread, SLOT(getViewsOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
        connect(thread, SIGNAL(gotViewsOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)),
                ui->viewTreeWidget, SLOT(gotObjectsOfSchemaSlot(QTreeWidgetItem*,QString,QStringList)));

        connect(ui->programTreeWidget, SIGNAL(getGroupsOfSchemaSignal(QTreeWidgetItem*,QString,QString)), thread, SLOT(getProgramTypesOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
        connect(thread, SIGNAL(gotProgramTypesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)),
                ui->programTreeWidget, SLOT(gotGroupsOfSchemaSlot(QTreeWidgetItem*,QString,QStringList)));

        connect(ui->programTreeWidget, SIGNAL(getGroupElementsOfSchemaSignal(QTreeWidgetItem*,QString,QString,QString)), thread, SLOT(getProgramsOfSchemaSlot(QTreeWidgetItem*,QString,QString,QString)));
        connect(thread, SIGNAL(gotProgramsOfSchemaSignal(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)),
                ui->programTreeWidget, SLOT(gotGroupElementsOfSchemaSlot(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)));

        connect(ui->etcTreeWidget, SIGNAL(getGroupsOfSchemaSignal(QTreeWidgetItem*,QString,QString)), thread, SLOT(getEtcTypesOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
        connect(thread, SIGNAL(gotEtcTypesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)),
                ui->etcTreeWidget, SLOT(gotGroupsOfSchemaSlot(QTreeWidgetItem*,QString,QStringList)));

        connect(ui->etcTreeWidget, SIGNAL(getGroupElementsOfSchemaSignal(QTreeWidgetItem*,QString,QString,QString)), thread, SLOT(getEtcOfSchemaSlot(QTreeWidgetItem*,QString,QString,QString)));
        connect(thread, SIGNAL(gotEtcOfSchemaSignal(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)),
                ui->etcTreeWidget, SLOT(gotGroupElementsOfSchemaSlot(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)));

        thread->start(QThread::HighestPriority); //QThread::HighPriority);
        return true;
    }
    else
        return false;
}

void KvMainWindow::startedThreadSlot(QString session)
{
    if (dbThreadMap.contains(session)) {
        int pos = session.indexOf("@", 0, Qt::CaseSensitive);
        QString userName = session.mid(0, pos);
        QString alias = session.mid(pos+1, (session.length() - (pos+1)));

        //QMessageBox::information(0, "userName", userName);
        //QMessageBox::information(0, "connectionName", connectionName);

        QString driverName = KvDbUtil::driverForDatabase(ui->dbTreeWidget->getDbTypeFromDatabaseItem(alias));
        QString dbName = ui->dbTreeWidget->getDatabaseItem(alias)->text(4);
        QString hostName = ui->dbTreeWidget->getDatabaseItem(alias)->text(2);
        int port = ui->dbTreeWidget->getDatabaseItem(alias)->text(3).toInt();

        ui->dbTreeWidget->setConnectionItemOnWorking(alias, userName, true);
        ui->dbTreeWidget->setConnectionMessageOnWorking(alias, userName, tr("Trying to Connect..."));

        emit openDbConnectionSignal(session, alias, driverName, dbName, hostName, userName, ui->dbTreeWidget->getConnectionItem(alias, userName)->text(2), port);
        //emit openDbConnectionSignal(connectionNameWithUser, connectionName, driverName, dbName, hostName, userName, ui->dbTreeWidget->currentItem()->text(2), port);
    }
}

void KvMainWindow::setDbConnectionCompleted(QString alias, QString userName)
{
    QString session = userName+"@"+alias;
    if ((ui->tableTreeWidget->findItems(session, Qt::MatchExactly).size() > 0) &&
            (ui->viewTreeWidget->findItems(session, Qt::MatchExactly).size() > 0) &&
            (ui->programTreeWidget->findItems(session, Qt::MatchExactly).size() > 0) &&
            (ui->etcTreeWidget->findItems(session, Qt::MatchExactly).size() > 0))
    {
        ui->dbTreeWidget->setConnectionItemOnWorking(alias, userName, false);
        ui->dbTreeWidget->setConnectionMessageOnWorking(alias, userName, "");
    }
}

void KvMainWindow::openedDbConnectionSlot(QString session, QString connUser, QString connDb, QSqlError error)
{
    if (error.type() == QSqlError::NoError) {
        QString alias = session.remove(connUser+"@", Qt::CaseSensitive);
        ui->dbTreeWidget->setConnectionItemOn(alias, connUser, true);
        //ui->dbTreeWidget->setConnectionItemOnWorking(connName, connUser, true);
        ui->dbTreeWidget->setConnectionMessageOnWorking(alias, connUser, tr("Retrieving Schema Names"));
        // Get Schemas
        updateActiveConnectionObjectsCombo();
        emit openedDbConnectionSignal(connUser+"@"+alias, connUser, connDb, error);
        emit getSchemasWithTablesSignal(connUser+"@"+alias);
    }
    else {
        emit closeDbConnectionSignal(session);
        QString alias = session.remove(connUser+"@", Qt::CaseSensitive);
        ui->dbTreeWidget->setConnectionItemOn(alias, connUser, false);
        ui->dbTreeWidget->setConnectionItemOnWorking(alias, connUser, false);
        ui->dbTreeWidget->setConnectionItemError(alias, connUser, error.text());

    }
}

void KvMainWindow::gotSchemasWithTablesSlot(QString sessionName, QString userName, QStringList items)
{
    QString alias = sessionName;
    if (sessionName.contains("@",Qt::CaseInsensitive))
        alias = sessionName.remove(userName+"@", Qt::CaseSensitive);
    if (ui->dbTreeWidget->isConnectionOn(alias, userName)) {
        ui->tableTreeWidget->addSchemaItems(alias, userName, items);
        emit getSchemasWithViewsSignal(userName+"@"+alias);
        setDbConnectionCompleted(alias, userName);
    }
}

void KvMainWindow::gotSchemasWithViewsSlot(QString sessionName, QString userName, QStringList items)
{
    QString alias = sessionName;
    if (sessionName.contains("@",Qt::CaseInsensitive))
        alias = sessionName.remove(userName+"@", Qt::CaseSensitive);
    if (ui->dbTreeWidget->isConnectionOn(alias, userName)) {
        ui->viewTreeWidget->addSchemaItems(alias, userName, items);
        emit getSchemasWithProgramsSignal(userName+"@"+alias);
        setDbConnectionCompleted(alias, userName);
    }
}

void KvMainWindow::gotSchemasWithProgramsSlot(QString sessionName, QString userName, QStringList items)
{
    QString alias = sessionName;
    if (sessionName.contains("@",Qt::CaseInsensitive))
        alias = sessionName.remove(userName+"@", Qt::CaseSensitive);
    if (ui->dbTreeWidget->isConnectionOn(alias, userName)) {
        ui->programTreeWidget->addSchemaItems(alias, userName, items);
        emit getSchemasWithEtcSignal(userName+"@"+alias);
        setDbConnectionCompleted(alias, userName);
    }
}

void KvMainWindow::gotSchemasWithEtcSlot(QString sessionName, QString userName, QStringList items)
{
    QString alias = sessionName;
    if (sessionName.contains("@",Qt::CaseInsensitive))
        alias = sessionName.remove(userName+"@", Qt::CaseSensitive);
    if (ui->dbTreeWidget->isConnectionOn(alias, userName)) {
        ui->etcTreeWidget->addSchemaItems(alias, userName, items);
        setDbConnectionCompleted(alias, userName);
    }
}

void KvMainWindow::on_actionDisconnect_triggered()
{

    QString session;
    if (ui->dbTreeWidget->hasFocus()) {
        if ((ui->dbTreeWidget->selectedItems().count() > 0) && (ui->dbTreeWidget->itemLevel(ui->dbTreeWidget->currentItem()) == 1)) {
            QString connectionName = ui->dbTreeWidget->currentItem()->parent()->text(0);
            QString userName = ui->dbTreeWidget->currentItem()->text(0);
            ui->dbTreeWidget->setConnectionItemOn(connectionName, userName, false);
            ui->dbTreeWidget->setConnectionItemOnWorking(connectionName, userName, false);
            ui->dbTreeWidget->setConnectionItemError(connectionName, userName, NULL);
            //delete ui->tableTreeWidget->getConnectionItem(connectionName, userName);
            //delete ui->viewTreeWidget->getConnectionItem(connectionName, userName);
            //delete ui->programTreeWidget->getConnectionItem(connectionName, userName);
            //delete ui->etcTreeWidget->getConnectionItem(connectionName, userName);
            session = userName+"@"+connectionName;
            emit closeDbConnectionSignal(session);
        }
        else
            QMessageBox::warning(this, tr("Close Connection"), tr("Please, select the connection item you wish to close!"));
    }
    else if (ui->tableTreeWidget->hasFocus()) {
        if ((ui->tableTreeWidget->selectedItems().count() > 0) && (ui->tableTreeWidget->itemLevel(ui->tableTreeWidget->currentItem()) == 0)) {
            QString connectionName = ui->tableTreeWidget->currentItem()->text(0);
            ui->tableTreeWidget->removeConnectionItem(connectionName, NULL);
            session = connectionName;
            emit closeDbConnectionSignal(session);
        }
        else
            QMessageBox::warning(this, tr("Close Connection"), tr("Please, select the connection item you wish to close!"));
    }
    else if (ui->viewTreeWidget->hasFocus()) {
        if ((ui->viewTreeWidget->selectedItems().count() > 0) && (ui->viewTreeWidget->itemLevel(ui->viewTreeWidget->currentItem()) == 0)) {
            QString connectionName = ui->viewTreeWidget->currentItem()->text(0);
            ui->viewTreeWidget->removeConnectionItem(connectionName, NULL);
            session = connectionName;
            emit closeDbConnectionSignal(session);
        }
        else
            QMessageBox::warning(this, tr("Close Connection"), tr("Please, select the connection item you wish to close!"));
    }
    else if (ui->programTreeWidget->hasFocus()) {
        if ((ui->programTreeWidget->selectedItems().count() > 0) && (ui->programTreeWidget->itemLevel(ui->programTreeWidget->currentItem()) == 0)) {
            QString connectionName = ui->programTreeWidget->currentItem()->text(0);
            ui->programTreeWidget->removeConnectionItem(connectionName, NULL);
            session = connectionName;
            emit closeDbConnectionSignal(session);
        }
        else
            QMessageBox::warning(this, tr("Close Connection"), tr("Please, select the connection item you wish to close!"));
    }
    else if (ui->etcTreeWidget->hasFocus()) {
        if ((ui->etcTreeWidget->selectedItems().count() > 0) && (ui->etcTreeWidget->itemLevel(ui->etcTreeWidget->currentItem()) == 0)) {
            QString connectionName = ui->etcTreeWidget->currentItem()->text(0);
            ui->etcTreeWidget->removeConnectionItem(connectionName, NULL);
            session = connectionName;
            emit closeDbConnectionSignal(session);
        }
        else
            QMessageBox::warning(this, tr("Close Connection"), tr("Please, select the connection item you wish to close!"));
    }
}

void KvMainWindow::closedDbConnectionSlot(QString connectionName)
{
    if (dbThreadMap.contains(connectionName)) {
        KvThread *tempThread = dbThreadMap.take(connectionName);
        dbThreadMapTemp.insert(tempThread->getSessionName(), tempThread);
        connect(tempThread, SIGNAL(finished()), this, SLOT(deleteTempThreadSlot()));
        tempThread->quit();
        tempThread->wait();
    }
    updateActiveConnectionObjectsCombo();
    emit closedDbConnectionSignal(connectionName);
}

void KvMainWindow::on_actionPreferences_triggered()
{
    KvSettingsDialog *dialog = new KvSettingsDialog(this);
    if (dbThreadMap.count() > 0)
        dialog->enableConnectionsFileDirAlert(true);
    else
        dialog->enableConnectionsFileDirAlert(false);

    connect(dialog, SIGNAL(changedConnectionsFileDir()), this, SLOT(loadXml()));
    connect(dialog, SIGNAL(saveConnectionsFile()), this, SLOT(copyXml()));
    dialog->show();
}

/** Updates the Active Connections Combo to show only the objects from the selected active connection. */
void KvMainWindow::updateActiveConnectionObjectsCombo()
{
    QString activeConnectionSelected = ui->activeConnObjComboBox->currentText();
    ui->activeConnObjComboBox->clear();
    ui->activeConnObjComboBox->addItem(tr("Objects from All Active Connections"));
    QStringList sessionNames = dbThreadMap.keys();
    for(int i=0; i<sessionNames.size(); i++)
        if (dbThreadMap.value(sessionNames.at(i))->hasOpenConnection())
            ui->activeConnObjComboBox->addItem(tr("Objects from :")+" "+sessionNames.at(i));
    int lastIndex = ui->activeConnObjComboBox->findText(activeConnectionSelected);
    if (lastIndex > 0)
        ui->activeConnObjComboBox->setCurrentIndex(lastIndex);
    else
        ui->activeConnObjComboBox->setCurrentIndex(0);
}


void KvMainWindow::on_activeConnObjComboBox_currentIndexChanged(QString text)
{
    QString allObjects = tr("Objects from All Active Connections");
    if (text.compare(allObjects) == 0) {
        ui->tableTreeWidget->setVisibleObjectsSession();
        ui->viewTreeWidget->setVisibleObjectsSession();
        ui->programTreeWidget->setVisibleObjectsSession();
        ui->etcTreeWidget->setVisibleObjectsSession();
    }
    else {
        int pos = text.indexOf(":", 0, Qt::CaseInsensitive);
        QString connection = text.right((text.length() - pos) - 2).trimmed();
        ui->tableTreeWidget->setVisibleObjectsSession(connection);
        ui->viewTreeWidget->setVisibleObjectsSession(connection);
        ui->programTreeWidget->setVisibleObjectsSession(connection);
        ui->etcTreeWidget->setVisibleObjectsSession(connection);
    }
}

void KvMainWindow::on_fileTreeView_expanded(QModelIndex index)
{
    ui->fileTreeView->resizeColumnToContents(0);
    ui->fileTreeView->resizeColumnToContents(1);
    ui->fileTreeView->resizeColumnToContents(2);
}

void KvMainWindow::on_actionEdit_triggered()
{
    if (ui->dbTreeWidget->selectedItems().count() > 0) {
        QTreeWidgetItem *item = ui->dbTreeWidget->currentItem();
        if (ui->dbTreeWidget->itemLevel(item) == 0) {
            // If there is no active connection, you can edit the database definition
            if (!isActiveConnection(item->text(0))) {
                KvDbDefinitionDialog *dbDefDialog = new KvDbDefinitionDialog;
                dbDefDialog->setValues(item->text(0), item->text(1), item->text(2), item->text(3), item->text(4), item->text(5), item->text(6));
                //dbDefDialog->show();
                if (dbDefDialog->exec() == QDialog::Accepted) {
                    QStringList values = dbDefDialog->getValues();
                    for(int i=0; i<values.count(); ++i)
                        ui->dbTreeWidget->currentItem()->setText(i, values.at(i));
                }
                delete dbDefDialog;
                ui->dbTreeWidget->resizeColumnToContents(0);
                ui->dbTreeWidget->setColumnWidth ( 0, ui->dbTreeWidget->columnWidth(0) + ui->dbTreeWidget->currentItem()->icon(0).actualSize(QSize(16,16)).width() );
            }
            else
                QMessageBox::warning(this, tr("Active Connection"), tr("You can not edit a database with an active connection!"));
        }
        else if (ui->dbTreeWidget->itemLevel(item) == 1) {
            // If this connection is not active, you can edit its definition
            if (!isActiveConnection(item->parent()->text(0), item->text(0))) {
                KvUserPassDialog *userpassDialog = new KvUserPassDialog;
                userpassDialog->setValues(item->text(0), item->text(2), item->text(3), item->text(4));
                if (userpassDialog->exec() == QDialog::Accepted) {
                    QStringList values = userpassDialog->getValues();
                    ui->dbTreeWidget->currentItem()->setText(0, values.at(0));
                    for(int i=1; i<values.count(); ++i)
                        ui->dbTreeWidget->currentItem()->setText(i+1, values.at(i));
                }
                delete userpassDialog;
                ui->dbTreeWidget->resizeColumnToContents(0);
            }
            else
                QMessageBox::warning(this, tr("Active Connection"), tr("You can not edit an active connection!"));
        }
    }
    else
        QMessageBox::warning(this, tr("Edit Database or Connection"), tr("Please, select the database or connection item you wish to edit!"));
}

void KvMainWindow::on_actionDelete_Database_triggered()
{
    if ((ui->dbTreeWidget->selectedItems().count() > 0) && (ui->dbTreeWidget->itemLevel(ui->dbTreeWidget->currentItem()) == 0)) {
        if (!isActiveConnection(ui->dbTreeWidget->currentItem()->text(0))) {
            QTreeWidgetItem *item = ui->dbTreeWidget->currentItem();
            ui->dbTreeWidget->removeDatabaseItem(item->text(0));
        }
        else
            QMessageBox::warning(this, tr("Active Connection"), tr("You can not remove a database with an active connection!"));
    }
    else
        QMessageBox::warning(this, tr("Remove Database"), tr("Please, select the database item you wish to remove!"));
}

void KvMainWindow::on_actionAdd_Connection_triggered()
{
    if ((ui->dbTreeWidget->selectedItems().count() > 0) && (ui->dbTreeWidget->itemLevel(ui->dbTreeWidget->currentItem()) == 0)) {
        QTreeWidgetItem *item = ui->dbTreeWidget->currentItem();
        KvUserPassDialog *userpassDialog = new KvUserPassDialog;
        if (userpassDialog->exec() == QDialog::Accepted) {
            QStringList values = userpassDialog->getValues();
            ui->dbTreeWidget->addConnectionItem(item->text(0), values.at(0), values.at(1), values.at(2), values.at(3));
        }
        delete userpassDialog;
        ui->dbTreeWidget->resizeColumnToContents(0);
    }
    else
        QMessageBox::warning(this, tr("Add Connection"), tr("Please, select a database item to add a connection definiton!"));
}

void KvMainWindow::on_actionDelete_Connection_triggered()
{
    if ((ui->dbTreeWidget->selectedItems().count() > 0) && (ui->dbTreeWidget->itemLevel(ui->dbTreeWidget->currentItem()) == 1)) {
        if (!isActiveConnection(ui->dbTreeWidget->currentItem()->parent()->text(0), ui->dbTreeWidget->currentItem()->text(0))) {
            QTreeWidgetItem *item = ui->dbTreeWidget->currentItem();
            ui->dbTreeWidget->removeConnectionItem(item->parent()->text(0), item->text(0));
        }
        else
            QMessageBox::warning(this, tr("Active Connection"), tr("You can not remove an active connection!"));
    }
    else
        QMessageBox::warning(this, tr("Remove Connection"), tr("Please, select the connection item you wish to remove!"));

}

void KvMainWindow::on_dbTreeWidget_doubleClicked(QModelIndex index)
{
    if (ui->dbTreeWidget->itemLevel(ui->dbTreeWidget->currentItem()) != 0)
        on_actionConnect_triggered();
}

void KvMainWindow::on_actionNavigator_triggered()
{
    if (ui->navigatorDockWidget->isVisible())
        ui->navigatorDockWidget->hide();
    else {
        ui->navigatorDockWidget->show();
        ui->navigatorDockWidget->raise();
    }
}

void KvMainWindow::on_actionObjects_triggered()
{
    if (ui->objectsDockWidget->isVisible())
        ui->objectsDockWidget->hide();
    else {
        ui->objectsDockWidget->show();
        ui->objectsDockWidget->raise();
    }
}

void KvMainWindow::on_actionWindow_List_triggered()
{
    if (ui->winListDockWidget->isVisible())
        ui->winListDockWidget->hide();
    else {
        ui->winListDockWidget->show();
        ui->winListDockWidget->raise();
    }
}

void KvMainWindow::on_actionWork_Path_triggered()
{
    workPath = KvSettings::getDefaultWorkPath();
    fileModel->setRootPath(workPath);
    ui->fileTreeView->setCurrentIndex(fileModel->index(workPath));
    ui->fileTreeView->expand(ui->fileTreeView->currentIndex());
    ui->fileTreeView->sortByColumn(0, Qt::AscendingOrder);
    ui->fileTreeView->resizeColumnToContents(0);

    if (ui->workingDirDockWidget->isVisible())
        ui->workingDirDockWidget->hide();
    else {
        ui->workingDirDockWidget->show();
        ui->workingDirDockWidget->raise();
    }
}

void KvMainWindow::on_mdiArea_subWindowActivated(QMdiSubWindow *window)
{
    if (ui->mdiArea->subWindowList().count() > 0)
        ui->listWidgetWindows->setCurrentItem( mdiWindowList.value(window) );
}

int KvMainWindow::getWindowCounter() {
    if (ui->mdiArea->subWindowList().count() == 0)
        windowCounter = 1;
    else
        windowCounter++;
    return windowCounter;
}

void KvMainWindow::openFile(QString fileName)
{
    KvSqlWindow *window = newSqlWindow("", "", false, QFileInfo(fileName).completeBaseName()+"."+QFileInfo(fileName).completeSuffix());
    window->openFile(fileName);
}

void KvMainWindow::saveFile(KvSqlWindow *window, QString fileName)
{
    window->setFileName(fileName);
    window->saveFile();
}

KvSqlWindow *KvMainWindow::newSqlWindow(QString sessionName, QString sqlStatement, bool toBeExecuted, QString windowTitle)
{
    int windowNumber = getWindowCounter();
    KvSqlWindow *widget = new KvSqlWindow(ui->mdiArea);
    widget->setActiveSessions(dbThreadMap.keys());

    connect(this, SIGNAL(openedDbConnectionSignal(QString,QString,QString,QSqlError)), widget, SLOT(addActiveSession(QString)));
    connect(this, SIGNAL(closedDbConnectionSignal(QString)), widget, SLOT(removeActiveSession(QString)));
    connect(widget, SIGNAL(cloneSessionSignal(WId, QString)), this, SIGNAL(cloneSessionSignal(WId, QString)));
    connect(this, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)),
            widget, SLOT(clonedSessionSlot(WId, QString,QString,QString,int,QString,QString,QString)));

    connect(widget, SIGNAL(openFileSignal(QString)), this, SLOT(openFile(QString)));
    //connect(widget, SIGNAL(openFileSignal(QString)), this, SLOT(openFile(QString)));

    QMdiSubWindow *subWindow = ui->mdiArea->addSubWindow(widget, Qt::SubWindow);
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    subWindow->setWindowIcon(widget->windowIcon());

    QString newWindowTitle = QString();
    if (windowTitle.isEmpty()) {
        newWindowTitle = widget->windowTitle()+" "+QString::number(windowNumber)+QString(" [*]");
    }
    else {
        newWindowTitle = windowTitle+QString(" [*]");
    }
    subWindow->setWindowTitle(newWindowTitle);
    connect(subWindow, SIGNAL(destroyed()), this, SLOT(updateWindowList()));

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(subWindow->windowTitle());
    mdiWindowList.insert(subWindow, item);
    ui->listWidgetWindows->addItem(item);

    widget->show();
    subWindow->activateWindow();
    widget->setFocus();
    if (!sessionName.isEmpty()) {
        widget->setComboSessionName(sessionName);
        if (toBeExecuted)
            widget->runSqlStatement(sqlStatement);
        else
            widget->setSqlStatement(sqlStatement);
    }

#if QT_VERSION < 0x040800
    // Those lines below were included to prevent a QMdiArea bug painting
    ui->mdiArea->activatePreviousSubWindow();
    ui->mdiArea->activatePreviousSubWindow();
#endif

    return widget;
}

void KvMainWindow::newDdlWindow(QString sessionName, QString schemaName, QString objectName, QString objectType, bool showSchema)
{
    int windowNumber = getWindowCounter();
    KvSqlWindow *widget = new KvSqlWindow(ui->mdiArea);
    widget->setActiveSessions(dbThreadMap.keys());

    connect(this, SIGNAL(openedDbConnectionSignal(QString,QString,QString,QSqlError)), widget, SLOT(addActiveSession(QString)));
    connect(this, SIGNAL(closedDbConnectionSignal(QString)), widget, SLOT(removeActiveSession(QString)));
    connect(widget, SIGNAL(cloneSessionSignal(WId, QString)), this, SIGNAL(cloneSessionSignal(WId, QString)));
    connect(this, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)),
            widget, SLOT(clonedSessionSlot(WId, QString,QString,QString,int,QString,QString,QString)));

    QMdiSubWindow *subWindow = ui->mdiArea->addSubWindow(widget, Qt::SubWindow);
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    subWindow->setWindowIcon(widget->windowIcon());
    subWindow->setWindowTitle(objectType+" "+schemaName+"."+objectName+QString(" [*]"));
    //subWindow->setWindowTitle(widget->windowTitle()+" "+QString::number(windowNumber));
    connect(subWindow, SIGNAL(destroyed()), this, SLOT(updateWindowList()));

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(subWindow->windowTitle());
    mdiWindowList.insert(subWindow, item);
    ui->listWidgetWindows->addItem(item);

    widget->show();
    subWindow->activateWindow();
    widget->setFocus();
    if (!sessionName.isEmpty()) {
        widget->setDdlInfo(schemaName, objectName, objectType, showSchema);
        widget->setComboSessionName(sessionName);
    }
    // Those lines below were included to prevent a QMdiArea bug painting


#if QT_VERSION < 0x040800
    // Those lines below were included to prevent a QMdiArea bug painting
    ui->mdiArea->activatePreviousSubWindow();
    ui->mdiArea->activatePreviousSubWindow();
#endif
}

void KvMainWindow::newExportDataWindow(QString sessionName, QString schemaName, QString tableName, bool showSchema)
{
    int windowNumber = getWindowCounter();
    KvSqlWindow *widget = new KvSqlWindow(ui->mdiArea);
    widget->setActiveSessions(dbThreadMap.keys());

    connect(this, SIGNAL(openedDbConnectionSignal(QString,QString,QString,QSqlError)), widget, SLOT(addActiveSession(QString)));
    connect(this, SIGNAL(closedDbConnectionSignal(QString)), widget, SLOT(removeActiveSession(QString)));
    connect(widget, SIGNAL(cloneSessionSignal(WId, QString)), this, SIGNAL(cloneSessionSignal(WId, QString)));
    connect(this, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)),
            widget, SLOT(clonedSessionSlot(WId, QString,QString,QString,int,QString,QString,QString)));

    QMdiSubWindow *subWindow = ui->mdiArea->addSubWindow(widget, Qt::SubWindow);
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    subWindow->setWindowIcon(widget->windowIcon());
    subWindow->setWindowTitle(tr("Export Data")+" - "+schemaName+"."+tableName+QString(" [*]"));
    connect(subWindow, SIGNAL(destroyed()), this, SLOT(updateWindowList()));

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(subWindow->windowTitle());
    mdiWindowList.insert(subWindow, item);
    ui->listWidgetWindows->addItem(item);

    widget->show();
    subWindow->activateWindow();
    widget->setFocus();
    if (!sessionName.isEmpty()) {
        widget->setExportDataInfo(schemaName, tableName, showSchema);
        widget->setComboSessionName(sessionName);
    }
#if QT_VERSION < 0x040800
    // Those lines below were included to prevent a QMdiArea bug painting
    ui->mdiArea->activatePreviousSubWindow();
    ui->mdiArea->activatePreviousSubWindow();
#endif
}

void KvMainWindow::newExportObjectsWindow()
{
    int windowNumber = getWindowCounter();
    KvExportObjects *widget = new KvExportObjects(ui->mdiArea);
    widget->setActiveSessions(dbThreadMap.keys());

    connect(this, SIGNAL(openedDbConnectionSignal(QString,QString,QString,QSqlError)), widget, SLOT(addActiveSession(QString)));
    connect(this, SIGNAL(closedDbConnectionSignal(QString)), widget, SLOT(removeActiveSession(QString)));
    connect(widget, SIGNAL(cloneSessionSignal(WId, QString)), this, SIGNAL(cloneSessionSignal(WId, QString)));
    connect(this, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)),
            widget, SLOT(clonedSessionSlot(WId, QString,QString,QString,int,QString,QString,QString)));

    QMdiSubWindow *subWindow = ui->mdiArea->addSubWindow(widget, Qt::SubWindow);

    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    subWindow->setWindowIcon(widget->windowIcon());
    subWindow->setWindowTitle(widget->windowTitle()+" "+QString::number(windowNumber)+QString(" [*]"));
    connect(subWindow, SIGNAL(destroyed()), this, SLOT(updateWindowList()));

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(subWindow->windowTitle());
    mdiWindowList.insert(subWindow, item);
    ui->listWidgetWindows->addItem(item);

    widget->show();
    subWindow->activateWindow();
    widget->setFocus();
#if QT_VERSION < 0x040800
    // Those lines below were included to prevent a QMdiArea bug painting
    ui->mdiArea->activatePreviousSubWindow();
    ui->mdiArea->activatePreviousSubWindow();
#endif
}

void KvMainWindow::on_actionNew_Sql_triggered()
{
    newSqlWindow();
}

void KvMainWindow::closeTab(int i) {
    // Compile the next code if Qt's version is less than 4.8
#if QT_VERSION < 0x040800
    if ((ui->mdiArea->subWindowList().count() > 0) && (i <= ui->mdiArea->subWindowList().count()-1 )) {
        QMdiSubWindow *sub = ui->mdiArea->subWindowList()[i];
        QWidget *win = sub->widget();
        win->close();
        ui->mdiArea->setActiveSubWindow(sub);
        ui->mdiArea->closeActiveSubWindow();
    }
#endif
}

void KvMainWindow::updateWindowList()
{
    ui->listWidgetWindows->clear();
    mdiWindowList.clear();
    if (ui->mdiArea->subWindowList().count() > 0) {
        foreach(QMdiSubWindow *subWindow, ui->mdiArea->subWindowList()) {
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(subWindow->windowTitle());
            //item->setData(Qt::UserRole, QString::number((int) subWindow->winId()));
            mdiWindowList.insert(subWindow, item);
            ui->listWidgetWindows->addItem(item);
        }
        QMdiSubWindow *currentSubWindow = ui->mdiArea->activeSubWindow();
        ui->listWidgetWindows->setCurrentItem( mdiWindowList.value(currentSubWindow) );
    }
}

void KvMainWindow::on_listWidgetWindows_itemSelectionChanged()
{
    if (ui->mdiArea->subWindowList().count() > 0)
        ui->mdiArea->setActiveSubWindow( mdiWindowList.key(ui->listWidgetWindows->currentItem()) );
}

void KvMainWindow::on_actionCascade_Windows_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

void KvMainWindow::on_actionTile_Windows_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void KvMainWindow::on_actionClose_All_Windows_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

void KvMainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}


void KvMainWindow::on_actionMain_Tool_Bar_triggered()
{
    if (ui->mainToolBar->isVisible())
        ui->mainToolBar->hide();
    else {
        ui->mainToolBar->show();
        ui->mainToolBar->raise();
    }
}

void KvMainWindow::on_actionDisconnectAll_triggered()
{
    foreach(QString sessionName, dbThreadMap.keys()) {
        ui->tableTreeWidget->removeConnectionItem(sessionName, NULL);
        emit closeDbConnectionSignal(sessionName);
    }
}

void KvMainWindow::deleteTempThreadSlot()
{
    foreach(KvThread *tempThread, dbThreadMapTemp.values()) {
        while ((tempThread != NULL) && (tempThread->isRunning())) {
            // nothing
        }
        if (tempThread->isFinished()) {
            KvThread *threadToBeFree = dbThreadMapTemp.take(tempThread->getSessionName());
            delete threadToBeFree;
        }
    }
}

void KvMainWindow::on_actionView_TableData_triggered()
{
    QTreeWidgetItem *item = ui->tableTreeWidget->selectedItems().at(0);
    QString sessionName = item->parent()->parent()->text(0);
    QString alias = sessionName.mid(sessionName.indexOf("@")+1, sessionName.length() - sessionName.indexOf("@"));
    QString schemaName = item->parent()->text(0);
    QString tableName = item->text(0);
    QString sqlStatement;
    if ((ui->dbTreeWidget->getDatabaseItem(alias)->text(1).contains("Sqlite")) ||
            (ui->dbTreeWidget->getDatabaseItem(alias)->text(1).contains("Firebird")))
        sqlStatement = "SELECT * FROM "+tableName+";";
    else
        sqlStatement = "SELECT * FROM "+schemaName+"."+tableName+";";
    newSqlWindow(sessionName, sqlStatement, true);
}

void KvMainWindow::on_actionView_ViewData_triggered()
{
    QTreeWidgetItem *item = ui->viewTreeWidget->selectedItems().at(0);
    QString sessionName = item->parent()->parent()->text(0);
    QString alias = sessionName.mid(sessionName.indexOf("@")+1, sessionName.length() - sessionName.indexOf("@"));
    QString schemaName = item->parent()->text(0);
    QString tableName = item->text(0);
    QString sqlStatement;
    if ((ui->dbTreeWidget->getDatabaseItem(alias)->text(1).contains("Sqlite")) ||
            (ui->dbTreeWidget->getDatabaseItem(alias)->text(1).contains("Firebird")))
        sqlStatement = "SELECT * FROM "+tableName+";";
    else
        sqlStatement = "SELECT * FROM "+schemaName+"."+tableName+";";
    newSqlWindow(sessionName, sqlStatement, true);
}

void KvMainWindow::on_actionRefreshTableSchema_triggered()
{
    QTreeWidgetItem *item = ui->tableTreeWidget->selectedItems().at(0);
    item->setExpanded(false);
    while(item->childCount() > 0)
        item->removeChild(item->child(0));
    QTreeWidgetItem *emptyItem = new QTreeWidgetItem ( item, QTreeWidgetItem::Type );
    item->setExpanded(true);
}

void KvMainWindow::on_actionRefreshViewSchema_triggered()
{
    QTreeWidgetItem *item = ui->viewTreeWidget->selectedItems().at(0);
    item->setExpanded(false);
    while(item->childCount() > 0)
        item->removeChild(item->child(0));
    QTreeWidgetItem *emptyItem = new QTreeWidgetItem ( item, QTreeWidgetItem::Type );
    item->setExpanded(true);
}

void KvMainWindow::on_actionRefreshProgramSchema_triggered()
{
    QTreeWidgetItem *item = ui->programTreeWidget->selectedItems().at(0);
    item->setExpanded(false);
    while(item->childCount() > 0)
        item->removeChild(item->child(0));
    QTreeWidgetItem *emptyItem = new QTreeWidgetItem ( item, QTreeWidgetItem::Type );
    item->setExpanded(true);
}

void KvMainWindow::on_actionRefreshEtcSchema_triggered()
{
    QTreeWidgetItem *item = ui->etcTreeWidget->selectedItems().at(0);
    item->setExpanded(false);
    while(item->childCount() > 0)
        item->removeChild(item->child(0));
    QTreeWidgetItem *emptyItem = new QTreeWidgetItem ( item, QTreeWidgetItem::Type );
    item->setExpanded(true);
}

void KvMainWindow::on_actionView_DDL_triggered()
{
    if (ui->tableTreeWidget->hasFocus()) {
        QTreeWidgetItem *item = ui->tableTreeWidget->selectedItems().at(0);
        QString objectName = item->text(0);
        QString objectType = "TABLE";
        QString schemaName = item->parent()->text(0);
        QString sessionName = item->parent()->parent()->text(0);
        newDdlWindow(sessionName, schemaName, objectName, objectType, true);
    }
    else if (ui->viewTreeWidget->hasFocus()) {
        QTreeWidgetItem *item = ui->viewTreeWidget->selectedItems().at(0);
        QString objectName = item->text(0);
        QString objectType = "VIEW";
        QString schemaName = item->parent()->text(0);
        QString sessionName = item->parent()->parent()->text(0);
        newDdlWindow(sessionName, schemaName, objectName, objectType, true);
    }
    else if (ui->programTreeWidget->hasFocus()) {
        QTreeWidgetItem *item = ui->programTreeWidget->selectedItems().at(0);
        QString objectName = item->text(0);
        QString objectType = item->parent()->text(0);
        QString schemaName = item->parent()->parent()->text(0);
        QString sessionName = item->parent()->parent()->parent()->text(0);
        newDdlWindow(sessionName, schemaName, objectName, objectType, true);
    }
    else if (ui->etcTreeWidget->hasFocus()) {
        QTreeWidgetItem *item = ui->etcTreeWidget->selectedItems().at(0);
        QString objectName = item->text(0);
        QString objectType = item->parent()->text(0);
        QString schemaName = item->parent()->parent()->text(0);
        QString sessionName = item->parent()->parent()->parent()->text(0);
        newDdlWindow(sessionName, schemaName, objectName, objectType, true);
    }
}

void KvMainWindow::on_actionExport_Data_triggered()
{
    if (ui->tableTreeWidget->hasFocus()) {
        QTreeWidgetItem *item = ui->tableTreeWidget->selectedItems().at(0);
        QString tableName = item->text(0);
        QString schemaName = item->parent()->text(0);
        QString sessionName = item->parent()->parent()->text(0);
        newExportDataWindow(sessionName, schemaName, tableName, true);
    }
}

void KvMainWindow::on_actionExport_Database_Objects_triggered()
{
    newExportObjectsWindow();
}

void KvMainWindow::on_actionRefresh_Schemas_triggered()
{
    // Refreshing schemas visible to a session
    QString sessionName = QString();
    QTreeWidgetItem *selectedItem;
    if (ui->tableTreeWidget->hasFocus()) {
        selectedItem = ui->tableTreeWidget->selectedItems().at(0);
    }
    else if (ui->viewTreeWidget->hasFocus()) {
        selectedItem = ui->viewTreeWidget->selectedItems().at(0);
    }
    else if (ui->programTreeWidget->hasFocus()) {
        selectedItem = ui->programTreeWidget->selectedItems().at(0);
    }
    else if (ui->etcTreeWidget->hasFocus()) {
        selectedItem = ui->etcTreeWidget->selectedItems().at(0);
    }
    sessionName = selectedItem->text(0);

    if (ui->tableTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).count() > 0) {
        selectedItem = ui->tableTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).at(0);
        while(selectedItem->childCount() > 0)
            selectedItem->removeChild(selectedItem->child(0));
    }
    if (ui->viewTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).count() > 0) {
        selectedItem = ui->viewTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).at(0);
        while(selectedItem->childCount() > 0)
            selectedItem->removeChild(selectedItem->child(0));
    }
    if (ui->programTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).count() > 0) {
        selectedItem = ui->programTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).at(0);
        while(selectedItem->childCount() > 0)
            selectedItem->removeChild(selectedItem->child(0));
    }
    if (ui->etcTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).count() > 0) {
        selectedItem = ui->etcTreeWidget->findItems(sessionName, Qt::MatchExactly, 0).at(0);
        while(selectedItem->childCount() > 0)
            selectedItem->removeChild(selectedItem->child(0));
    }

    emit getSchemasWithTablesSignal(sessionName);
}

void KvMainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("Open File"), KvSettings::getDefaultWorkPath(), tr("SQL Files (*.sql);;All Files (*.*)"));
    if (!fileName.isEmpty())
        openFile(fileName);
}

bool KvMainWindow::runKevoraUpdate()
{
    QProcess kevoraUp;
    QDir kevoraUpPath = QDir(QApplication::applicationDirPath());
    kevoraUpPath.cd("kevora-update");
    QString kevoraUpDir = kevoraUpPath.path();
    QString kevoraUpFileName;


#ifdef Q_OS_LINUX
    kevoraUpFileName = kevoraUpDir+"/kevora_up.sh";
#endif
#ifdef Q_OS_WIN32
    kevoraUpFileName = kevoraUpDir+"/kevora_up.exe";
#endif

    kevoraUp.startDetached(kevoraUpFileName, QStringList());
    return true;
}

void KvMainWindow::on_actionKevora_Updates_triggered()
{
    QMessageBox closeMsgBox;
    closeMsgBox.setText("To complete this operation, Kevora will be terminated.");
    closeMsgBox.setInformativeText("Do you want to continue?");
    closeMsgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    closeMsgBox.setDefaultButton(QMessageBox::No);
    int answer = closeMsgBox.exec();
    if (answer == QMessageBox::Yes) {
        runKevoraUpdate();
        close();
    }

}

void KvMainWindow::on_actionSave_triggered()
{
    if (ui->mdiArea->subWindowList().size() > 0) {
        QMdiSubWindow *currentSubWindow = ui->mdiArea->activeSubWindow();


        if (currentSubWindow->widget()->inherits("KvSqlWindow")) {
            KvSqlWindow *window = (KvSqlWindow *) currentSubWindow->widget();

            QString fileName = window->getFileName();

            if (fileName.isEmpty()) {
                on_actionSave_As_triggered();
            }
            else {
                saveFile(window, fileName);
            }
        }
    }
}

void KvMainWindow::on_actionSave_As_triggered()
{
    if (ui->mdiArea->subWindowList().size() > 0) {
        QMdiSubWindow *currentSubWindow = ui->mdiArea->activeSubWindow();
        if (currentSubWindow->widget()->inherits("KvSqlWindow")) {
            KvSqlWindow *window = (KvSqlWindow *) currentSubWindow->widget();

            QString fileName = QFileDialog::getSaveFileName(
                        this, tr("Save File"), KvSettings::getDefaultWorkPath(), tr("SQL Files (*.sql);;All Files (*.*)"));
            if (!fileName.isEmpty()) {
                window->setFileName(fileName);
            }
            window->saveFile();
            window->setWindowTitle(QFileInfo(fileName).completeBaseName()+"."+QFileInfo(fileName).completeSuffix());
            currentSubWindow->setWindowTitle(window->windowTitle());
            updateWindowList();
        }
    }
}


void KvMainWindow::on_actionCompare_Database_objects_triggered()
{

}
