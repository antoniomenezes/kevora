/********************************************************************************
** Form generated from reading UI file 'kvdbdefinitiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVDBDEFINITIONDIALOG_H
#define UI_KVDBDEFINITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KvDbDefinitionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAlias;
    QLineEdit *lineEditAlias;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelDBMSType;
    QComboBox *comboBoxDBMSType;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *pageCubrid;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_22;
    QLineEdit *lineEditCubridHost;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_23;
    QLineEdit *lineEditCubridPort;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_21;
    QLineEdit *lineEditCubridDBName;
    QWidget *pageFirebird;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelHostName;
    QLineEdit *lineEditFirebirdHost;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPort;
    QLineEdit *lineEditFirebirdPort;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelDBName;
    QLineEdit *lineEditFirebirdDBName;
    QToolButton *toolButtonFirebirdSetFile;
    QWidget *pageMySql;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEditMySqlHost;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEditMySqlPort;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEditMySqlDBName;
    QWidget *pageOracle;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEditOracleHost;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *lineEditOraclePort;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *lineEditOracleSID;
    QWidget *pagePostgreSql;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLineEdit *lineEditPostgHost;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLineEdit *lineEditPostgPort;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLineEdit *lineEditPostgDBName;
    QWidget *pageSqlite;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QLineEdit *lineEditSqliteHost;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_16;
    QLineEdit *lineEditSqlitePort;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_17;
    QLineEdit *lineEditSqliteDBName;
    QToolButton *toolButtonSqliteSetFile;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_18;
    QLabel *labelDriver;
    QComboBox *comboBoxDriver;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelComments;
    QPlainTextEdit *plainTextEditComments;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButtonShowMore;
    QSpacerItem *horizontalSpacer_7;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *KvDbDefinitionDialog)
    {
        if (KvDbDefinitionDialog->objectName().isEmpty())
            KvDbDefinitionDialog->setObjectName(QString::fromUtf8("KvDbDefinitionDialog"));
        KvDbDefinitionDialog->setWindowModality(Qt::ApplicationModal);
        KvDbDefinitionDialog->resize(466, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(KvDbDefinitionDialog->sizePolicy().hasHeightForWidth());
        KvDbDefinitionDialog->setSizePolicy(sizePolicy);
        KvDbDefinitionDialog->setMinimumSize(QSize(466, 400));
        KvDbDefinitionDialog->setMaximumSize(QSize(466, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/png_general/database.png"), QSize(), QIcon::Normal, QIcon::Off);
        KvDbDefinitionDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(KvDbDefinitionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelAlias = new QLabel(KvDbDefinitionDialog);
        labelAlias->setObjectName(QString::fromUtf8("labelAlias"));
        labelAlias->setMinimumSize(QSize(130, 0));

        horizontalLayout->addWidget(labelAlias);

        lineEditAlias = new QLineEdit(KvDbDefinitionDialog);
        lineEditAlias->setObjectName(QString::fromUtf8("lineEditAlias"));
        lineEditAlias->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(lineEditAlias);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelDBMSType = new QLabel(KvDbDefinitionDialog);
        labelDBMSType->setObjectName(QString::fromUtf8("labelDBMSType"));
        labelDBMSType->setMinimumSize(QSize(130, 0));

        horizontalLayout_2->addWidget(labelDBMSType);

        comboBoxDBMSType = new QComboBox(KvDbDefinitionDialog);
        comboBoxDBMSType->addItem(QString());
        comboBoxDBMSType->addItem(QString::fromUtf8("Firebird / Interbase"));
        comboBoxDBMSType->addItem(QString::fromUtf8("MySql"));
        comboBoxDBMSType->addItem(QString::fromUtf8("Oracle"));
        comboBoxDBMSType->addItem(QString::fromUtf8("PostgreSql"));
        comboBoxDBMSType->addItem(QString::fromUtf8("Sqlite"));
        comboBoxDBMSType->setObjectName(QString::fromUtf8("comboBoxDBMSType"));
        comboBoxDBMSType->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(comboBoxDBMSType);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(KvDbDefinitionDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 130));
        stackedWidget->setMaximumSize(QSize(16777215, 130));
        pageCubrid = new QWidget();
        pageCubrid->setObjectName(QString::fromUtf8("pageCubrid"));
        verticalLayout_10 = new QVBoxLayout(pageCubrid);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_22 = new QLabel(pageCubrid);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(130, 0));

        horizontalLayout_24->addWidget(label_22);

        lineEditCubridHost = new QLineEdit(pageCubrid);
        lineEditCubridHost->setObjectName(QString::fromUtf8("lineEditCubridHost"));
        lineEditCubridHost->setMinimumSize(QSize(200, 0));

        horizontalLayout_24->addWidget(lineEditCubridHost);


        verticalLayout_10->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_23 = new QLabel(pageCubrid);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(130, 0));

        horizontalLayout_25->addWidget(label_23);

        lineEditCubridPort = new QLineEdit(pageCubrid);
        lineEditCubridPort->setObjectName(QString::fromUtf8("lineEditCubridPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditCubridPort->sizePolicy().hasHeightForWidth());
        lineEditCubridPort->setSizePolicy(sizePolicy1);
        lineEditCubridPort->setMinimumSize(QSize(40, 0));
        lineEditCubridPort->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditCubridPort->setText(QString::fromUtf8("30000"));

        horizontalLayout_25->addWidget(lineEditCubridPort);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_10);


        verticalLayout_10->addLayout(horizontalLayout_25);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_21 = new QLabel(pageCubrid);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(130, 0));

        horizontalLayout_23->addWidget(label_21);

        lineEditCubridDBName = new QLineEdit(pageCubrid);
        lineEditCubridDBName->setObjectName(QString::fromUtf8("lineEditCubridDBName"));
        lineEditCubridDBName->setMinimumSize(QSize(280, 0));

        horizontalLayout_23->addWidget(lineEditCubridDBName);


        verticalLayout_10->addLayout(horizontalLayout_23);

        stackedWidget->addWidget(pageCubrid);
        pageFirebird = new QWidget();
        pageFirebird->setObjectName(QString::fromUtf8("pageFirebird"));
        verticalLayout_2 = new QVBoxLayout(pageFirebird);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelHostName = new QLabel(pageFirebird);
        labelHostName->setObjectName(QString::fromUtf8("labelHostName"));
        labelHostName->setMinimumSize(QSize(130, 0));

        horizontalLayout_3->addWidget(labelHostName);

        lineEditFirebirdHost = new QLineEdit(pageFirebird);
        lineEditFirebirdHost->setObjectName(QString::fromUtf8("lineEditFirebirdHost"));
        lineEditFirebirdHost->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(lineEditFirebirdHost);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelPort = new QLabel(pageFirebird);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setMinimumSize(QSize(130, 0));

        horizontalLayout_4->addWidget(labelPort);

        lineEditFirebirdPort = new QLineEdit(pageFirebird);
        lineEditFirebirdPort->setObjectName(QString::fromUtf8("lineEditFirebirdPort"));
        sizePolicy1.setHeightForWidth(lineEditFirebirdPort->sizePolicy().hasHeightForWidth());
        lineEditFirebirdPort->setSizePolicy(sizePolicy1);
        lineEditFirebirdPort->setMinimumSize(QSize(40, 0));
        lineEditFirebirdPort->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditFirebirdPort->setText(QString::fromUtf8("3050"));

        horizontalLayout_4->addWidget(lineEditFirebirdPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelDBName = new QLabel(pageFirebird);
        labelDBName->setObjectName(QString::fromUtf8("labelDBName"));
        labelDBName->setMinimumSize(QSize(130, 0));

        horizontalLayout_5->addWidget(labelDBName);

        lineEditFirebirdDBName = new QLineEdit(pageFirebird);
        lineEditFirebirdDBName->setObjectName(QString::fromUtf8("lineEditFirebirdDBName"));
        lineEditFirebirdDBName->setMinimumSize(QSize(280, 0));

        horizontalLayout_5->addWidget(lineEditFirebirdDBName);

        toolButtonFirebirdSetFile = new QToolButton(pageFirebird);
        toolButtonFirebirdSetFile->setObjectName(QString::fromUtf8("toolButtonFirebirdSetFile"));
        toolButtonFirebirdSetFile->setText(QString::fromUtf8("..."));

        horizontalLayout_5->addWidget(toolButtonFirebirdSetFile);


        verticalLayout_2->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(pageFirebird);
        pageMySql = new QWidget();
        pageMySql->setObjectName(QString::fromUtf8("pageMySql"));
        verticalLayout_3 = new QVBoxLayout(pageMySql);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(pageMySql);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(130, 0));

        horizontalLayout_6->addWidget(label_6);

        lineEditMySqlHost = new QLineEdit(pageMySql);
        lineEditMySqlHost->setObjectName(QString::fromUtf8("lineEditMySqlHost"));
        lineEditMySqlHost->setMinimumSize(QSize(200, 0));

        horizontalLayout_6->addWidget(lineEditMySqlHost);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(pageMySql);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(130, 0));

        horizontalLayout_7->addWidget(label_7);

        lineEditMySqlPort = new QLineEdit(pageMySql);
        lineEditMySqlPort->setObjectName(QString::fromUtf8("lineEditMySqlPort"));
        sizePolicy1.setHeightForWidth(lineEditMySqlPort->sizePolicy().hasHeightForWidth());
        lineEditMySqlPort->setSizePolicy(sizePolicy1);
        lineEditMySqlPort->setMinimumSize(QSize(40, 0));
        lineEditMySqlPort->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditMySqlPort->setText(QString::fromUtf8("3306"));

        horizontalLayout_7->addWidget(lineEditMySqlPort);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(pageMySql);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(130, 0));

        horizontalLayout_8->addWidget(label_8);

        lineEditMySqlDBName = new QLineEdit(pageMySql);
        lineEditMySqlDBName->setObjectName(QString::fromUtf8("lineEditMySqlDBName"));
        lineEditMySqlDBName->setMinimumSize(QSize(280, 0));

        horizontalLayout_8->addWidget(lineEditMySqlDBName);


        verticalLayout_3->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(pageMySql);
        pageOracle = new QWidget();
        pageOracle->setObjectName(QString::fromUtf8("pageOracle"));
        verticalLayout_4 = new QVBoxLayout(pageOracle);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(pageOracle);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(130, 0));

        horizontalLayout_9->addWidget(label_9);

        lineEditOracleHost = new QLineEdit(pageOracle);
        lineEditOracleHost->setObjectName(QString::fromUtf8("lineEditOracleHost"));
        lineEditOracleHost->setMinimumSize(QSize(200, 0));

        horizontalLayout_9->addWidget(lineEditOracleHost);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(pageOracle);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(130, 0));

        horizontalLayout_10->addWidget(label_10);

        lineEditOraclePort = new QLineEdit(pageOracle);
        lineEditOraclePort->setObjectName(QString::fromUtf8("lineEditOraclePort"));
        sizePolicy1.setHeightForWidth(lineEditOraclePort->sizePolicy().hasHeightForWidth());
        lineEditOraclePort->setSizePolicy(sizePolicy1);
        lineEditOraclePort->setMinimumSize(QSize(40, 0));
        lineEditOraclePort->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditOraclePort->setText(QString::fromUtf8("1521"));

        horizontalLayout_10->addWidget(lineEditOraclePort);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_11 = new QLabel(pageOracle);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(130, 0));
        label_11->setText(QString::fromUtf8("SID"));

        horizontalLayout_11->addWidget(label_11);

        lineEditOracleSID = new QLineEdit(pageOracle);
        lineEditOracleSID->setObjectName(QString::fromUtf8("lineEditOracleSID"));
        lineEditOracleSID->setMinimumSize(QSize(280, 0));

        horizontalLayout_11->addWidget(lineEditOracleSID);


        verticalLayout_4->addLayout(horizontalLayout_11);

        stackedWidget->addWidget(pageOracle);
        pagePostgreSql = new QWidget();
        pagePostgreSql->setObjectName(QString::fromUtf8("pagePostgreSql"));
        verticalLayout_5 = new QVBoxLayout(pagePostgreSql);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_12 = new QLabel(pagePostgreSql);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(130, 0));

        horizontalLayout_12->addWidget(label_12);

        lineEditPostgHost = new QLineEdit(pagePostgreSql);
        lineEditPostgHost->setObjectName(QString::fromUtf8("lineEditPostgHost"));
        lineEditPostgHost->setMinimumSize(QSize(200, 0));

        horizontalLayout_12->addWidget(lineEditPostgHost);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_13 = new QLabel(pagePostgreSql);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(130, 0));

        horizontalLayout_13->addWidget(label_13);

        lineEditPostgPort = new QLineEdit(pagePostgreSql);
        lineEditPostgPort->setObjectName(QString::fromUtf8("lineEditPostgPort"));
        sizePolicy1.setHeightForWidth(lineEditPostgPort->sizePolicy().hasHeightForWidth());
        lineEditPostgPort->setSizePolicy(sizePolicy1);
        lineEditPostgPort->setMinimumSize(QSize(40, 0));
        lineEditPostgPort->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditPostgPort->setText(QString::fromUtf8("5432"));

        horizontalLayout_13->addWidget(lineEditPostgPort);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_14 = new QLabel(pagePostgreSql);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(130, 0));

        horizontalLayout_14->addWidget(label_14);

        lineEditPostgDBName = new QLineEdit(pagePostgreSql);
        lineEditPostgDBName->setObjectName(QString::fromUtf8("lineEditPostgDBName"));
        lineEditPostgDBName->setMinimumSize(QSize(280, 0));

        horizontalLayout_14->addWidget(lineEditPostgDBName);


        verticalLayout_5->addLayout(horizontalLayout_14);

        stackedWidget->addWidget(pagePostgreSql);
        pageSqlite = new QWidget();
        pageSqlite->setObjectName(QString::fromUtf8("pageSqlite"));
        verticalLayout_6 = new QVBoxLayout(pageSqlite);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_15 = new QLabel(pageSqlite);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(130, 0));

        horizontalLayout_15->addWidget(label_15);

        lineEditSqliteHost = new QLineEdit(pageSqlite);
        lineEditSqliteHost->setObjectName(QString::fromUtf8("lineEditSqliteHost"));
        lineEditSqliteHost->setMinimumSize(QSize(200, 0));

        horizontalLayout_15->addWidget(lineEditSqliteHost);


        verticalLayout_6->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_16 = new QLabel(pageSqlite);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(130, 0));

        horizontalLayout_16->addWidget(label_16);

        lineEditSqlitePort = new QLineEdit(pageSqlite);
        lineEditSqlitePort->setObjectName(QString::fromUtf8("lineEditSqlitePort"));
        lineEditSqlitePort->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEditSqlitePort->sizePolicy().hasHeightForWidth());
        lineEditSqlitePort->setSizePolicy(sizePolicy1);
        lineEditSqlitePort->setMinimumSize(QSize(40, 0));
        lineEditSqlitePort->setText(QString::fromUtf8(""));

        horizontalLayout_16->addWidget(lineEditSqlitePort);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_17 = new QLabel(pageSqlite);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(130, 0));

        horizontalLayout_17->addWidget(label_17);

        lineEditSqliteDBName = new QLineEdit(pageSqlite);
        lineEditSqliteDBName->setObjectName(QString::fromUtf8("lineEditSqliteDBName"));
        lineEditSqliteDBName->setMinimumSize(QSize(280, 0));

        horizontalLayout_17->addWidget(lineEditSqliteDBName);

        toolButtonSqliteSetFile = new QToolButton(pageSqlite);
        toolButtonSqliteSetFile->setObjectName(QString::fromUtf8("toolButtonSqliteSetFile"));
        toolButtonSqliteSetFile->setText(QString::fromUtf8("..."));

        horizontalLayout_17->addWidget(toolButtonSqliteSetFile);


        verticalLayout_6->addLayout(horizontalLayout_17);

        stackedWidget->addWidget(pageSqlite);

        verticalLayout->addWidget(stackedWidget);

        dockWidget = new QDockWidget(KvDbDefinitionDialog);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMaximumSize(QSize(448, 159));
        dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_7 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_7->setSpacing(4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 6, 0, 4);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        labelDriver = new QLabel(dockWidgetContents);
        labelDriver->setObjectName(QString::fromUtf8("labelDriver"));
        labelDriver->setMinimumSize(QSize(130, 0));
        labelDriver->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_18->addWidget(labelDriver);

        comboBoxDriver = new QComboBox(dockWidgetContents);
        comboBoxDriver->addItem(QString());
        comboBoxDriver->addItem(QString::fromUtf8("QIBASE"));
        comboBoxDriver->addItem(QString::fromUtf8("QMYSQL"));
        comboBoxDriver->addItem(QString::fromUtf8("QOCI"));
        comboBoxDriver->addItem(QString::fromUtf8("QOpenOCCI"));
        comboBoxDriver->addItem(QString::fromUtf8("QPSQL"));
        comboBoxDriver->addItem(QString::fromUtf8("QSQLITE"));
        comboBoxDriver->setObjectName(QString::fromUtf8("comboBoxDriver"));
        comboBoxDriver->setMinimumSize(QSize(200, 0));
        comboBoxDriver->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_18->addWidget(comboBoxDriver);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_8);


        verticalLayout_7->addLayout(horizontalLayout_18);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        labelComments = new QLabel(dockWidgetContents);
        labelComments->setObjectName(QString::fromUtf8("labelComments"));

        verticalLayout_8->addWidget(labelComments);

        plainTextEditComments = new QPlainTextEdit(dockWidgetContents);
        plainTextEditComments->setObjectName(QString::fromUtf8("plainTextEditComments"));

        verticalLayout_8->addWidget(plainTextEditComments);


        verticalLayout_7->addLayout(verticalLayout_8);

        dockWidget->setWidget(dockWidgetContents);

        verticalLayout->addWidget(dockWidget);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButtonShowMore = new QPushButton(KvDbDefinitionDialog);
        pushButtonShowMore->setObjectName(QString::fromUtf8("pushButtonShowMore"));

        horizontalLayout_19->addWidget(pushButtonShowMore);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_7);

        buttonBox = new QDialogButtonBox(KvDbDefinitionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        horizontalLayout_19->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_19);

#ifndef QT_NO_SHORTCUT
        labelAlias->setBuddy(lineEditAlias);
        labelDBMSType->setBuddy(comboBoxDBMSType);
        label_22->setBuddy(lineEditPostgHost);
        label_23->setBuddy(lineEditPostgPort);
        label_21->setBuddy(lineEditPostgDBName);
        labelHostName->setBuddy(lineEditFirebirdHost);
        labelPort->setBuddy(lineEditFirebirdPort);
        labelDBName->setBuddy(lineEditFirebirdDBName);
        label_6->setBuddy(lineEditMySqlHost);
        label_7->setBuddy(lineEditMySqlPort);
        label_8->setBuddy(lineEditMySqlDBName);
        label_9->setBuddy(lineEditOracleHost);
        label_10->setBuddy(lineEditOraclePort);
        label_11->setBuddy(lineEditOracleSID);
        label_12->setBuddy(lineEditPostgHost);
        label_13->setBuddy(lineEditPostgPort);
        label_14->setBuddy(lineEditPostgDBName);
        label_15->setBuddy(lineEditSqliteHost);
        label_16->setBuddy(lineEditSqlitePort);
        label_17->setBuddy(lineEditSqliteDBName);
        labelDriver->setBuddy(comboBoxDBMSType);
#endif // QT_NO_SHORTCUT

        retranslateUi(KvDbDefinitionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), KvDbDefinitionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), KvDbDefinitionDialog, SLOT(reject()));
        QObject::connect(comboBoxDBMSType, SIGNAL(currentIndexChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(stackedWidget, SIGNAL(currentChanged(int)), comboBoxDBMSType, SLOT(setCurrentIndex(int)));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(KvDbDefinitionDialog);
    } // setupUi

    void retranslateUi(QDialog *KvDbDefinitionDialog)
    {
        KvDbDefinitionDialog->setWindowTitle(QApplication::translate("KvDbDefinitionDialog", "Database Definition", nullptr));
#ifndef QT_NO_TOOLTIP
        labelAlias->setToolTip(QApplication::translate("KvDbDefinitionDialog", "An user defined alias for the database server", nullptr));
#endif // QT_NO_TOOLTIP
        labelAlias->setText(QApplication::translate("KvDbDefinitionDialog", "Alias", nullptr));
#ifndef QT_NO_TOOLTIP
        labelDBMSType->setToolTip(QApplication::translate("KvDbDefinitionDialog", "The type of database server", nullptr));
#endif // QT_NO_TOOLTIP
        labelDBMSType->setText(QApplication::translate("KvDbDefinitionDialog", "DBMS Type", nullptr));
        comboBoxDBMSType->setItemText(0, QApplication::translate("KvDbDefinitionDialog", "Cubrid", nullptr));

        label_22->setText(QApplication::translate("KvDbDefinitionDialog", "Host Name or IP", nullptr));
        label_23->setText(QApplication::translate("KvDbDefinitionDialog", "Port", nullptr));
        label_21->setText(QApplication::translate("KvDbDefinitionDialog", "Database Name", nullptr));
#ifndef QT_NO_TOOLTIP
        labelHostName->setToolTip(QApplication::translate("KvDbDefinitionDialog", "The server IP or host name", nullptr));
#endif // QT_NO_TOOLTIP
        labelHostName->setText(QApplication::translate("KvDbDefinitionDialog", "Host Name or IP", nullptr));
#ifndef QT_NO_TOOLTIP
        labelPort->setToolTip(QApplication::translate("KvDbDefinitionDialog", "The port used to connect to this server", nullptr));
#endif // QT_NO_TOOLTIP
        labelPort->setText(QApplication::translate("KvDbDefinitionDialog", "Port", nullptr));
#ifndef QT_NO_TOOLTIP
        labelDBName->setToolTip(QApplication::translate("KvDbDefinitionDialog", "The database name or file name", nullptr));
#endif // QT_NO_TOOLTIP
        labelDBName->setText(QApplication::translate("KvDbDefinitionDialog", "Database Name", nullptr));
        label_6->setText(QApplication::translate("KvDbDefinitionDialog", "Host Name or IP", nullptr));
        label_7->setText(QApplication::translate("KvDbDefinitionDialog", "Port", nullptr));
        label_8->setText(QApplication::translate("KvDbDefinitionDialog", "Database Name", nullptr));
        label_9->setText(QApplication::translate("KvDbDefinitionDialog", "Host Name or IP", nullptr));
        label_10->setText(QApplication::translate("KvDbDefinitionDialog", "Port", nullptr));
        label_12->setText(QApplication::translate("KvDbDefinitionDialog", "Host Name or IP", nullptr));
        label_13->setText(QApplication::translate("KvDbDefinitionDialog", "Port", nullptr));
        label_14->setText(QApplication::translate("KvDbDefinitionDialog", "Database Name", nullptr));
        label_15->setText(QApplication::translate("KvDbDefinitionDialog", "Host Name or IP", nullptr));
        label_16->setText(QApplication::translate("KvDbDefinitionDialog", "Port", nullptr));
        label_17->setText(QApplication::translate("KvDbDefinitionDialog", "Database Name", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("KvDbDefinitionDialog", "More Options", nullptr));
#ifndef QT_NO_TOOLTIP
        labelDriver->setToolTip(QApplication::translate("KvDbDefinitionDialog", "The Qt Plugin used for this database", nullptr));
#endif // QT_NO_TOOLTIP
        labelDriver->setText(QApplication::translate("KvDbDefinitionDialog", "Driver", nullptr));
        comboBoxDriver->setItemText(0, QApplication::translate("KvDbDefinitionDialog", "QCUBRID", nullptr));

        labelComments->setText(QApplication::translate("KvDbDefinitionDialog", "Comments", nullptr));
        pushButtonShowMore->setText(QApplication::translate("KvDbDefinitionDialog", "Show More Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KvDbDefinitionDialog: public Ui_KvDbDefinitionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVDBDEFINITIONDIALOG_H
