/********************************************************************************
** Form generated from reading UI file 'kvsqlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVSQLWINDOW_H
#define UI_KVSQLWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "kvcodeeditor.h"
#include "kvsqldialog.h"
#include "kvwaitanimation.h"

QT_BEGIN_NAMESPACE

class Ui_KvSqlWindow
{
public:
    QAction *actionRun_Sql;
    QAction *actionTimed_Run;
    QAction *actionRun_All;
    QAction *actionCopy_to_Clipboard;
    QAction *actionExplainAll;
    QAction *actionGenerate_Cascade_Operations;
    QAction *actionExtract_Consistent_Sql_Data;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonExecSql;
    QToolButton *toolButtonExecAllSql;
    QToolButton *toolButtonTimedExec;
    QToolButton *toolButtonExplainPlan;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonCommit;
    QToolButton *toolButtonRollback;
    QToolButton *toolButtonClearSql;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *currentSessionComboBox;
    KvWaitAnimation *widgetProgress;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButtonZoomIn;
    QToolButton *toolButtonZoomOut;
    QSplitter *splitterV;
    QTabWidget *tabWidget;
    QWidget *tabSqlStatements;
    QGridLayout *gridLayout_5;
    QSplitter *splitterH;
    KvCodeEditor *plainTextEditSql;
    QFrame *frameParams;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetParams;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *toolButtonApplyParams;
    QToolButton *toolButtonCancelParams;
    QToolButton *toolButtonClearParams;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tabSessionInfo;
    QGridLayout *gridLayout;
    QTableWidget *tableWidgetSessionInfo;
    QWidget *tabSqlHistory;
    QTabWidget *tabWidgetData;
    QWidget *tabOutput;
    QGridLayout *gridLayout_4;
    QTextEdit *textEditMessages;
    QStatusBar *widgetStatusBar;

    void setupUi(KvSqlDialog *KvSqlWindow)
    {
        if (KvSqlWindow->objectName().isEmpty())
            KvSqlWindow->setObjectName(QString::fromUtf8("KvSqlWindow"));
        KvSqlWindow->resize(677, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/png_sqlwindow/sql.png"), QSize(), QIcon::Normal, QIcon::Off);
        KvSqlWindow->setWindowIcon(icon);
        actionRun_Sql = new QAction(KvSqlWindow);
        actionRun_Sql->setObjectName(QString::fromUtf8("actionRun_Sql"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/png/png_sqlwindow/1rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_Sql->setIcon(icon1);
        actionTimed_Run = new QAction(KvSqlWindow);
        actionTimed_Run->setObjectName(QString::fromUtf8("actionTimed_Run"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/png_sqlwindow/k_alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTimed_Run->setIcon(icon2);
        actionRun_All = new QAction(KvSqlWindow);
        actionRun_All->setObjectName(QString::fromUtf8("actionRun_All"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/png_sqlwindow/exec_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_All->setIcon(icon3);
        actionCopy_to_Clipboard = new QAction(KvSqlWindow);
        actionCopy_to_Clipboard->setObjectName(QString::fromUtf8("actionCopy_to_Clipboard"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/png/png_general/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy_to_Clipboard->setIcon(icon4);
        actionExplainAll = new QAction(KvSqlWindow);
        actionExplainAll->setObjectName(QString::fromUtf8("actionExplainAll"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/png/png_sqlwindow/enumList.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExplainAll->setIcon(icon5);
        actionGenerate_Cascade_Operations = new QAction(KvSqlWindow);
        actionGenerate_Cascade_Operations->setObjectName(QString::fromUtf8("actionGenerate_Cascade_Operations"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png/png_general/arrow_down_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGenerate_Cascade_Operations->setIcon(icon6);
        actionExtract_Consistent_Sql_Data = new QAction(KvSqlWindow);
        actionExtract_Consistent_Sql_Data->setObjectName(QString::fromUtf8("actionExtract_Consistent_Sql_Data"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png/png_general/table_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExtract_Consistent_Sql_Data->setIcon(icon7);
        verticalLayout_3 = new QVBoxLayout(KvSqlWindow);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(-1, 5, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        toolButtonExecSql = new QToolButton(KvSqlWindow);
        toolButtonExecSql->setObjectName(QString::fromUtf8("toolButtonExecSql"));
        toolButtonExecSql->setEnabled(false);
        toolButtonExecSql->setMaximumSize(QSize(25, 25));
        toolButtonExecSql->setIcon(icon1);

        horizontalLayout->addWidget(toolButtonExecSql);

        toolButtonExecAllSql = new QToolButton(KvSqlWindow);
        toolButtonExecAllSql->setObjectName(QString::fromUtf8("toolButtonExecAllSql"));
        toolButtonExecAllSql->setEnabled(false);
        toolButtonExecAllSql->setMaximumSize(QSize(25, 25));
        toolButtonExecAllSql->setIcon(icon3);

        horizontalLayout->addWidget(toolButtonExecAllSql);

        toolButtonTimedExec = new QToolButton(KvSqlWindow);
        toolButtonTimedExec->setObjectName(QString::fromUtf8("toolButtonTimedExec"));
        toolButtonTimedExec->setEnabled(false);
        toolButtonTimedExec->setMaximumSize(QSize(25, 25));
        toolButtonTimedExec->setIcon(icon2);
        toolButtonTimedExec->setCheckable(true);
        toolButtonTimedExec->setAutoExclusive(true);

        horizontalLayout->addWidget(toolButtonTimedExec);

        toolButtonExplainPlan = new QToolButton(KvSqlWindow);
        toolButtonExplainPlan->setObjectName(QString::fromUtf8("toolButtonExplainPlan"));
        toolButtonExplainPlan->setEnabled(false);
        toolButtonExplainPlan->setMaximumSize(QSize(25, 25));
        toolButtonExplainPlan->setIcon(icon5);

        horizontalLayout->addWidget(toolButtonExplainPlan);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        toolButtonCommit = new QToolButton(KvSqlWindow);
        toolButtonCommit->setObjectName(QString::fromUtf8("toolButtonCommit"));
        toolButtonCommit->setEnabled(false);
        toolButtonCommit->setMaximumSize(QSize(25, 25));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/png/png_sqlwindow/agt_action_success.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonCommit->setIcon(icon8);

        horizontalLayout_2->addWidget(toolButtonCommit);

        toolButtonRollback = new QToolButton(KvSqlWindow);
        toolButtonRollback->setObjectName(QString::fromUtf8("toolButtonRollback"));
        toolButtonRollback->setEnabled(false);
        toolButtonRollback->setMaximumSize(QSize(25, 25));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/png/png_sqlwindow/rollback.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRollback->setIcon(icon9);

        horizontalLayout_2->addWidget(toolButtonRollback);

        toolButtonClearSql = new QToolButton(KvSqlWindow);
        toolButtonClearSql->setObjectName(QString::fromUtf8("toolButtonClearSql"));
        toolButtonClearSql->setMaximumSize(QSize(25, 25));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/png/png_sqlwindow/editclear.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonClearSql->setIcon(icon10);

        horizontalLayout_2->addWidget(toolButtonClearSql);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(KvSqlWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        horizontalLayout_3->addWidget(label);

        currentSessionComboBox = new QComboBox(KvSqlWindow);
        currentSessionComboBox->setObjectName(QString::fromUtf8("currentSessionComboBox"));
        currentSessionComboBox->setMinimumSize(QSize(250, 0));
        currentSessionComboBox->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_3->addWidget(currentSessionComboBox);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        widgetProgress = new KvWaitAnimation(KvSqlWindow);
        widgetProgress->setObjectName(QString::fromUtf8("widgetProgress"));
        widgetProgress->setMinimumSize(QSize(22, 22));

        horizontalLayout_5->addWidget(widgetProgress);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        toolButtonZoomIn = new QToolButton(KvSqlWindow);
        toolButtonZoomIn->setObjectName(QString::fromUtf8("toolButtonZoomIn"));
        toolButtonZoomIn->setMaximumSize(QSize(25, 25));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/png/png_general/viewmag+.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonZoomIn->setIcon(icon11);
#ifndef QT_NO_SHORTCUT
        toolButtonZoomIn->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        toolButtonZoomIn->setAutoRepeat(true);
        toolButtonZoomIn->setAutoRepeatDelay(100);

        horizontalLayout_4->addWidget(toolButtonZoomIn);

        toolButtonZoomOut = new QToolButton(KvSqlWindow);
        toolButtonZoomOut->setObjectName(QString::fromUtf8("toolButtonZoomOut"));
        toolButtonZoomOut->setMaximumSize(QSize(25, 25));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/png/png_general/viewmag-.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonZoomOut->setIcon(icon12);
#ifndef QT_NO_SHORTCUT
        toolButtonZoomOut->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        toolButtonZoomOut->setAutoRepeat(true);
        toolButtonZoomOut->setAutoRepeatDelay(100);

        horizontalLayout_4->addWidget(toolButtonZoomOut);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_5);

        splitterV = new QSplitter(KvSqlWindow);
        splitterV->setObjectName(QString::fromUtf8("splitterV"));
        splitterV->setOrientation(Qt::Vertical);
        splitterV->setOpaqueResize(false);
        tabWidget = new QTabWidget(splitterV);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabSqlStatements = new QWidget();
        tabSqlStatements->setObjectName(QString::fromUtf8("tabSqlStatements"));
        gridLayout_5 = new QGridLayout(tabSqlStatements);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitterH = new QSplitter(tabSqlStatements);
        splitterH->setObjectName(QString::fromUtf8("splitterH"));
        splitterH->setOrientation(Qt::Horizontal);
        splitterH->setOpaqueResize(false);
        plainTextEditSql = new KvCodeEditor(splitterH);
        plainTextEditSql->setObjectName(QString::fromUtf8("plainTextEditSql"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        plainTextEditSql->setFont(font);
        plainTextEditSql->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEditSql->setPlainText(QString::fromUtf8(""));
        splitterH->addWidget(plainTextEditSql);
        frameParams = new QFrame(splitterH);
        frameParams->setObjectName(QString::fromUtf8("frameParams"));
        frameParams->setFrameShape(QFrame::Box);
        frameParams->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frameParams);
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(6);
#endif
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidgetParams = new QTableWidget(frameParams);
        if (tableWidgetParams->columnCount() < 1)
            tableWidgetParams->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetParams->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetParams->setObjectName(QString::fromUtf8("tableWidgetParams"));
        tableWidgetParams->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tableWidgetParams->setAlternatingRowColors(true);
        tableWidgetParams->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableWidgetParams);

        widget = new QWidget(frameParams);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 4);
        toolButtonApplyParams = new QToolButton(widget);
        toolButtonApplyParams->setObjectName(QString::fromUtf8("toolButtonApplyParams"));
        toolButtonApplyParams->setIcon(icon8);

        horizontalLayout_6->addWidget(toolButtonApplyParams);

        toolButtonCancelParams = new QToolButton(widget);
        toolButtonCancelParams->setObjectName(QString::fromUtf8("toolButtonCancelParams"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/png/png_sqlwindow/agt_action_fail.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonCancelParams->setIcon(icon13);

        horizontalLayout_6->addWidget(toolButtonCancelParams);

        toolButtonClearParams = new QToolButton(widget);
        toolButtonClearParams->setObjectName(QString::fromUtf8("toolButtonClearParams"));
        toolButtonClearParams->setIcon(icon10);

        horizontalLayout_6->addWidget(toolButtonClearParams);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget);

        splitterH->addWidget(frameParams);

        gridLayout_5->addWidget(splitterH, 0, 0, 1, 1);

        tabWidget->addTab(tabSqlStatements, QString());
        tabSessionInfo = new QWidget();
        tabSessionInfo->setObjectName(QString::fromUtf8("tabSessionInfo"));
        gridLayout = new QGridLayout(tabSessionInfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidgetSessionInfo = new QTableWidget(tabSessionInfo);
        if (tableWidgetSessionInfo->columnCount() < 2)
            tableWidgetSessionInfo->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetSessionInfo->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetSessionInfo->setHorizontalHeaderItem(1, __qtablewidgetitem2);
        tableWidgetSessionInfo->setObjectName(QString::fromUtf8("tableWidgetSessionInfo"));
        tableWidgetSessionInfo->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableWidgetSessionInfo, 0, 0, 1, 1);

        tabWidget->addTab(tabSessionInfo, QString());
        tabSqlHistory = new QWidget();
        tabSqlHistory->setObjectName(QString::fromUtf8("tabSqlHistory"));
        tabWidget->addTab(tabSqlHistory, QString());
        splitterV->addWidget(tabWidget);
        tabWidgetData = new QTabWidget(splitterV);
        tabWidgetData->setObjectName(QString::fromUtf8("tabWidgetData"));
        tabWidgetData->setMinimumSize(QSize(0, 150));
        tabWidgetData->setStyleSheet(QString::fromUtf8(""));
        tabWidgetData->setElideMode(Qt::ElideRight);
        tabWidgetData->setMovable(false);
        tabOutput = new QWidget();
        tabOutput->setObjectName(QString::fromUtf8("tabOutput"));
        gridLayout_4 = new QGridLayout(tabOutput);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textEditMessages = new QTextEdit(tabOutput);
        textEditMessages->setObjectName(QString::fromUtf8("textEditMessages"));
        textEditMessages->setLineWrapMode(QTextEdit::NoWrap);
        textEditMessages->setReadOnly(true);
        textEditMessages->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_4->addWidget(textEditMessages, 0, 0, 1, 1);

        tabWidgetData->addTab(tabOutput, QString());
        splitterV->addWidget(tabWidgetData);

        verticalLayout_3->addWidget(splitterV);

        widgetStatusBar = new QStatusBar(KvSqlWindow);
        widgetStatusBar->setObjectName(QString::fromUtf8("widgetStatusBar"));

        verticalLayout_3->addWidget(widgetStatusBar);

        QWidget::setTabOrder(plainTextEditSql, tabWidgetData);
        QWidget::setTabOrder(tabWidgetData, toolButtonExecSql);
        QWidget::setTabOrder(toolButtonExecSql, toolButtonExecAllSql);
        QWidget::setTabOrder(toolButtonExecAllSql, toolButtonTimedExec);
        QWidget::setTabOrder(toolButtonTimedExec, toolButtonExplainPlan);
        QWidget::setTabOrder(toolButtonExplainPlan, toolButtonCommit);
        QWidget::setTabOrder(toolButtonCommit, toolButtonRollback);
        QWidget::setTabOrder(toolButtonRollback, toolButtonClearSql);
        QWidget::setTabOrder(toolButtonClearSql, currentSessionComboBox);
        QWidget::setTabOrder(currentSessionComboBox, toolButtonZoomIn);
        QWidget::setTabOrder(toolButtonZoomIn, toolButtonZoomOut);
        QWidget::setTabOrder(toolButtonZoomOut, tabWidget);
        QWidget::setTabOrder(tabWidget, tableWidgetParams);
        QWidget::setTabOrder(tableWidgetParams, toolButtonApplyParams);
        QWidget::setTabOrder(toolButtonApplyParams, toolButtonCancelParams);
        QWidget::setTabOrder(toolButtonCancelParams, toolButtonClearParams);
        QWidget::setTabOrder(toolButtonClearParams, tableWidgetSessionInfo);
        QWidget::setTabOrder(tableWidgetSessionInfo, textEditMessages);

        retranslateUi(KvSqlWindow);
        QObject::connect(toolButtonClearParams, SIGNAL(clicked()), tableWidgetParams, SLOT(clearContents()));
        QObject::connect(toolButtonClearSql, SIGNAL(clicked()), plainTextEditSql, SLOT(clear()));

        tabWidget->setCurrentIndex(0);
        tabWidgetData->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(KvSqlWindow);
    } // setupUi

    void retranslateUi(KvSqlDialog *KvSqlWindow)
    {
        KvSqlWindow->setWindowTitle(QApplication::translate("KvSqlWindow", "Sql Window", nullptr));
        actionRun_Sql->setText(QApplication::translate("KvSqlWindow", "Run Sql", nullptr));
        actionTimed_Run->setText(QApplication::translate("KvSqlWindow", "Timed Run", nullptr));
        actionRun_All->setText(QApplication::translate("KvSqlWindow", "Run All", nullptr));
        actionCopy_to_Clipboard->setText(QApplication::translate("KvSqlWindow", "Copy to Clipboard", nullptr));
        actionExplainAll->setText(QApplication::translate("KvSqlWindow", "Explain All", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExplainAll->setToolTip(QApplication::translate("KvSqlWindow", "Explain All Sql Statements", nullptr));
#endif // QT_NO_TOOLTIP
        actionGenerate_Cascade_Operations->setText(QApplication::translate("KvSqlWindow", "Generate Cascade Operations", nullptr));
        actionExtract_Consistent_Sql_Data->setText(QApplication::translate("KvSqlWindow", "Extract Consistent Sql Data", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonExecSql->setToolTip(QApplication::translate("KvSqlWindow", "Execute Sql", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonExecSql->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        toolButtonExecSql->setShortcut(QApplication::translate("KvSqlWindow", "F8", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        toolButtonExecAllSql->setToolTip(QApplication::translate("KvSqlWindow", "Execute All", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonExecAllSql->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_SHORTCUT
        toolButtonExecAllSql->setShortcut(QApplication::translate("KvSqlWindow", "F9", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        toolButtonTimedExec->setToolTip(QApplication::translate("KvSqlWindow", "Timed Execution", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonTimedExec->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonExplainPlan->setToolTip(QApplication::translate("KvSqlWindow", "Generate Execution Plan", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonExplainPlan->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonCommit->setToolTip(QApplication::translate("KvSqlWindow", "Commit Transaction", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonCommit->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonRollback->setToolTip(QApplication::translate("KvSqlWindow", "Rollback Transaction", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonRollback->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonClearSql->setToolTip(QApplication::translate("KvSqlWindow", "Clear Sql", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonClearSql->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
        label->setText(QApplication::translate("KvSqlWindow", "Current Session", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonZoomIn->setToolTip(QApplication::translate("KvSqlWindow", "Zoom In", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonZoomIn->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonZoomOut->setToolTip(QApplication::translate("KvSqlWindow", "Zoom Out", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonZoomOut->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetParams->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("KvSqlWindow", "Value", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonApplyParams->setToolTip(QApplication::translate("KvSqlWindow", "Apply Parameters and Run Sql", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonApplyParams->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonCancelParams->setToolTip(QApplication::translate("KvSqlWindow", "Cancel Parameters", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonCancelParams->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonClearParams->setToolTip(QApplication::translate("KvSqlWindow", "Clear All Values", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonClearParams->setText(QApplication::translate("KvSqlWindow", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSqlStatements), QApplication::translate("KvSqlWindow", "Sql Statements", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetSessionInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("KvSqlWindow", "Information", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetSessionInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("KvSqlWindow", "Value", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSessionInfo), QApplication::translate("KvSqlWindow", "Session Info", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSqlHistory), QApplication::translate("KvSqlWindow", "Sql History", nullptr));
        tabWidgetData->setTabText(tabWidgetData->indexOf(tabOutput), QApplication::translate("KvSqlWindow", "Messages/Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KvSqlWindow: public Ui_KvSqlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVSQLWINDOW_H
