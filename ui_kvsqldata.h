/********************************************************************************
** Form generated from reading UI file 'kvsqldata.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVSQLDATA_H
#define UI_KVSQLDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KvSqlData
{
public:
    QAction *actionCopy_to_Clipboard;
    QAction *actionExport_as_Select_Statements_Clipboard;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidgetData;
    QWidget *pageData;
    QVBoxLayout *verticalLayout;
    QWidget *widgetDataToolBar;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButtonGetNextRec;
    QToolButton *toolButtonGetAllRec;
    QToolButton *toolButtonCancelAllRecords;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButtonRecView;
    QToolButton *toolButtonResultZoomIn;
    QToolButton *toolButtonResultZoomOut;
    QTableWidget *tableWidgetResults;
    QWidget *pageRecordData;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetRecordToolBar;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *toolButtonFirstRec;
    QToolButton *toolButtonPrevRec;
    QToolButton *toolButtonNextRec;
    QToolButton *toolButtonLastRec;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolButtonGridView;
    QToolButton *toolButtonRecZoomIn;
    QToolButton *toolButtonRecZoomOut;
    QTableWidget *tableWidgetRecord;
    QWidget *pagePlan;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButtonPlanZoomIn;
    QToolButton *toolButtonPlanZoomOut;
    QTreeWidget *treeWidgetPlan;

    void setupUi(QWidget *KvSqlData)
    {
        if (KvSqlData->objectName().isEmpty())
            KvSqlData->setObjectName(QStringLiteral("KvSqlData"));
        KvSqlData->resize(407, 216);
        actionCopy_to_Clipboard = new QAction(KvSqlData);
        actionCopy_to_Clipboard->setObjectName(QStringLiteral("actionCopy_to_Clipboard"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/png_general/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy_to_Clipboard->setIcon(icon);
        actionExport_as_Select_Statements_Clipboard = new QAction(KvSqlData);
        actionExport_as_Select_Statements_Clipboard->setObjectName(QStringLiteral("actionExport_as_Select_Statements_Clipboard"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/png_general/script.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_as_Select_Statements_Clipboard->setIcon(icon1);
        gridLayout = new QGridLayout(KvSqlData);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidgetData = new QStackedWidget(KvSqlData);
        stackedWidgetData->setObjectName(QStringLiteral("stackedWidgetData"));
        pageData = new QWidget();
        pageData->setObjectName(QStringLiteral("pageData"));
        verticalLayout = new QVBoxLayout(pageData);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetDataToolBar = new QWidget(pageData);
        widgetDataToolBar->setObjectName(QStringLiteral("widgetDataToolBar"));
        horizontalLayout_7 = new QHBoxLayout(widgetDataToolBar);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        toolButtonGetNextRec = new QToolButton(widgetDataToolBar);
        toolButtonGetNextRec->setObjectName(QStringLiteral("toolButtonGetNextRec"));
        toolButtonGetNextRec->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/png_sqlwindow/resultset_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonGetNextRec->setIcon(icon2);

        horizontalLayout_7->addWidget(toolButtonGetNextRec);

        toolButtonGetAllRec = new QToolButton(widgetDataToolBar);
        toolButtonGetAllRec->setObjectName(QStringLiteral("toolButtonGetAllRec"));
        toolButtonGetAllRec->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/png_sqlwindow/resultset_last.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonGetAllRec->setIcon(icon3);

        horizontalLayout_7->addWidget(toolButtonGetAllRec);

        toolButtonCancelAllRecords = new QToolButton(widgetDataToolBar);
        toolButtonCancelAllRecords->setObjectName(QStringLiteral("toolButtonCancelAllRecords"));
        toolButtonCancelAllRecords->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/png/png_general/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonCancelAllRecords->setIcon(icon4);

        horizontalLayout_7->addWidget(toolButtonCancelAllRecords);

        horizontalSpacer_6 = new QSpacerItem(537, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        toolButtonRecView = new QToolButton(widgetDataToolBar);
        toolButtonRecView->setObjectName(QStringLiteral("toolButtonRecView"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/png/png_sqlwindow/application_side_list.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRecView->setIcon(icon5);

        horizontalLayout_7->addWidget(toolButtonRecView);

        toolButtonResultZoomIn = new QToolButton(widgetDataToolBar);
        toolButtonResultZoomIn->setObjectName(QStringLiteral("toolButtonResultZoomIn"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/png/png_general/viewmag+.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonResultZoomIn->setIcon(icon6);
        toolButtonResultZoomIn->setAutoRepeat(true);
        toolButtonResultZoomIn->setAutoRepeatDelay(100);

        horizontalLayout_7->addWidget(toolButtonResultZoomIn);

        toolButtonResultZoomOut = new QToolButton(widgetDataToolBar);
        toolButtonResultZoomOut->setObjectName(QStringLiteral("toolButtonResultZoomOut"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/png/png_general/viewmag-.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonResultZoomOut->setIcon(icon7);
        toolButtonResultZoomOut->setShortcut(QStringLiteral(""));
        toolButtonResultZoomOut->setAutoRepeat(true);
        toolButtonResultZoomOut->setAutoRepeatDelay(100);

        horizontalLayout_7->addWidget(toolButtonResultZoomOut);


        verticalLayout->addWidget(widgetDataToolBar);

        tableWidgetResults = new QTableWidget(pageData);
        tableWidgetResults->setObjectName(QStringLiteral("tableWidgetResults"));
        tableWidgetResults->setContextMenuPolicy(Qt::ActionsContextMenu);
        tableWidgetResults->setInputMethodHints(Qt::ImhPreferNumbers);
        tableWidgetResults->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetResults->setAlternatingRowColors(true);
        tableWidgetResults->setSortingEnabled(true);
        tableWidgetResults->setWordWrap(false);

        verticalLayout->addWidget(tableWidgetResults);

        stackedWidgetData->addWidget(pageData);
        pageRecordData = new QWidget();
        pageRecordData->setObjectName(QStringLiteral("pageRecordData"));
        verticalLayout_2 = new QVBoxLayout(pageRecordData);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widgetRecordToolBar = new QWidget(pageRecordData);
        widgetRecordToolBar->setObjectName(QStringLiteral("widgetRecordToolBar"));
        horizontalLayout_8 = new QHBoxLayout(widgetRecordToolBar);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        toolButtonFirstRec = new QToolButton(widgetRecordToolBar);
        toolButtonFirstRec->setObjectName(QStringLiteral("toolButtonFirstRec"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/png/png_record/tab_first.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonFirstRec->setIcon(icon8);

        horizontalLayout_8->addWidget(toolButtonFirstRec);

        toolButtonPrevRec = new QToolButton(widgetRecordToolBar);
        toolButtonPrevRec->setObjectName(QStringLiteral("toolButtonPrevRec"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/png/png_record/tab_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonPrevRec->setIcon(icon9);
        toolButtonPrevRec->setAutoRepeat(true);

        horizontalLayout_8->addWidget(toolButtonPrevRec);

        toolButtonNextRec = new QToolButton(widgetRecordToolBar);
        toolButtonNextRec->setObjectName(QStringLiteral("toolButtonNextRec"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/png/png_record/tab_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonNextRec->setIcon(icon10);
        toolButtonNextRec->setAutoRepeat(true);

        horizontalLayout_8->addWidget(toolButtonNextRec);

        toolButtonLastRec = new QToolButton(widgetRecordToolBar);
        toolButtonLastRec->setObjectName(QStringLiteral("toolButtonLastRec"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/png/png_record/tab_last.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonLastRec->setIcon(icon11);

        horizontalLayout_8->addWidget(toolButtonLastRec);

        horizontalSpacer_7 = new QSpacerItem(479, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        toolButtonGridView = new QToolButton(widgetRecordToolBar);
        toolButtonGridView->setObjectName(QStringLiteral("toolButtonGridView"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/png/png_sqlwindow/application_view_columns.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonGridView->setIcon(icon12);

        horizontalLayout_8->addWidget(toolButtonGridView);

        toolButtonRecZoomIn = new QToolButton(widgetRecordToolBar);
        toolButtonRecZoomIn->setObjectName(QStringLiteral("toolButtonRecZoomIn"));
        toolButtonRecZoomIn->setIcon(icon6);
        toolButtonRecZoomIn->setShortcut(QStringLiteral(""));
        toolButtonRecZoomIn->setAutoRepeat(true);
        toolButtonRecZoomIn->setAutoRepeatDelay(100);

        horizontalLayout_8->addWidget(toolButtonRecZoomIn);

        toolButtonRecZoomOut = new QToolButton(widgetRecordToolBar);
        toolButtonRecZoomOut->setObjectName(QStringLiteral("toolButtonRecZoomOut"));
        toolButtonRecZoomOut->setIcon(icon7);
        toolButtonRecZoomOut->setShortcut(QStringLiteral(""));
        toolButtonRecZoomOut->setAutoRepeat(true);
        toolButtonRecZoomOut->setAutoRepeatDelay(100);

        horizontalLayout_8->addWidget(toolButtonRecZoomOut);


        verticalLayout_2->addWidget(widgetRecordToolBar);

        tableWidgetRecord = new QTableWidget(pageRecordData);
        tableWidgetRecord->setObjectName(QStringLiteral("tableWidgetRecord"));
        tableWidgetRecord->setContextMenuPolicy(Qt::ActionsContextMenu);
        tableWidgetRecord->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetRecord->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetRecord->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(tableWidgetRecord);

        stackedWidgetData->addWidget(pageRecordData);
        pagePlan = new QWidget();
        pagePlan->setObjectName(QStringLiteral("pagePlan"));
        verticalLayout_3 = new QVBoxLayout(pagePlan);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButtonPlanZoomIn = new QToolButton(pagePlan);
        toolButtonPlanZoomIn->setObjectName(QStringLiteral("toolButtonPlanZoomIn"));
        toolButtonPlanZoomIn->setIcon(icon6);
        toolButtonPlanZoomIn->setShortcut(QStringLiteral(""));
        toolButtonPlanZoomIn->setAutoRepeat(true);
        toolButtonPlanZoomIn->setAutoRepeatDelay(100);

        horizontalLayout->addWidget(toolButtonPlanZoomIn);

        toolButtonPlanZoomOut = new QToolButton(pagePlan);
        toolButtonPlanZoomOut->setObjectName(QStringLiteral("toolButtonPlanZoomOut"));
        toolButtonPlanZoomOut->setIcon(icon7);
        toolButtonPlanZoomOut->setShortcut(QStringLiteral(""));
        toolButtonPlanZoomOut->setAutoRepeat(true);
        toolButtonPlanZoomOut->setAutoRepeatDelay(100);

        horizontalLayout->addWidget(toolButtonPlanZoomOut);


        verticalLayout_3->addLayout(horizontalLayout);

        treeWidgetPlan = new QTreeWidget(pagePlan);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(2, QStringLiteral("ID"));
        treeWidgetPlan->setHeaderItem(__qtreewidgetitem);
        treeWidgetPlan->setObjectName(QStringLiteral("treeWidgetPlan"));

        verticalLayout_3->addWidget(treeWidgetPlan);

        stackedWidgetData->addWidget(pagePlan);

        gridLayout->addWidget(stackedWidgetData, 0, 0, 1, 1);


        retranslateUi(KvSqlData);

        stackedWidgetData->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(KvSqlData);
    } // setupUi

    void retranslateUi(QWidget *KvSqlData)
    {
        KvSqlData->setWindowTitle(QApplication::translate("KvSqlData", "Form", Q_NULLPTR));
        actionCopy_to_Clipboard->setText(QApplication::translate("KvSqlData", "Copy to Clipboard", Q_NULLPTR));
        actionExport_as_Select_Statements_Clipboard->setText(QApplication::translate("KvSqlData", "Export as Select Statements to Clipboard", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExport_as_Select_Statements_Clipboard->setToolTip(QApplication::translate("KvSqlData", "Export as Select Statements to Clipboard", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        toolButtonGetNextRec->setToolTip(QApplication::translate("KvSqlData", "Get next records...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonGetNextRec->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonGetAllRec->setToolTip(QApplication::translate("KvSqlData", "Get all records", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonGetAllRec->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonCancelAllRecords->setToolTip(QApplication::translate("KvSqlData", "Cancel All Records Retrieval", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonCancelAllRecords->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonRecView->setToolTip(QApplication::translate("KvSqlData", "Show Record View", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonRecView->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
        toolButtonResultZoomIn->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
        toolButtonResultZoomOut->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonFirstRec->setToolTip(QApplication::translate("KvSqlData", "First Record", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonFirstRec->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonPrevRec->setToolTip(QApplication::translate("KvSqlData", "Previous Record", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonPrevRec->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonNextRec->setToolTip(QApplication::translate("KvSqlData", "Next Record", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonNextRec->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonLastRec->setToolTip(QApplication::translate("KvSqlData", "Last Record", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonLastRec->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonGridView->setToolTip(QApplication::translate("KvSqlData", "Show Results Grid", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonGridView->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
        toolButtonRecZoomIn->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
        toolButtonRecZoomOut->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
        toolButtonPlanZoomIn->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
        toolButtonPlanZoomOut->setText(QApplication::translate("KvSqlData", "...", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetPlan->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("KvSqlData", "Cost", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("KvSqlData", "Operation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KvSqlData: public Ui_KvSqlData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVSQLDATA_H
