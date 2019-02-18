/********************************************************************************
** Form generated from reading UI file 'kvsqldata.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVSQLDATA_H
#define UI_KVSQLDATA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
            KvSqlData->setObjectName(QString::fromUtf8("KvSqlData"));
        KvSqlData->resize(407, 216);
        actionCopy_to_Clipboard = new QAction(KvSqlData);
        actionCopy_to_Clipboard->setObjectName(QString::fromUtf8("actionCopy_to_Clipboard"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/png_general/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy_to_Clipboard->setIcon(icon);
        actionExport_as_Select_Statements_Clipboard = new QAction(KvSqlData);
        actionExport_as_Select_Statements_Clipboard->setObjectName(QString::fromUtf8("actionExport_as_Select_Statements_Clipboard"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/png/png_general/script.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_as_Select_Statements_Clipboard->setIcon(icon1);
        gridLayout = new QGridLayout(KvSqlData);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidgetData = new QStackedWidget(KvSqlData);
        stackedWidgetData->setObjectName(QString::fromUtf8("stackedWidgetData"));
        pageData = new QWidget();
        pageData->setObjectName(QString::fromUtf8("pageData"));
        verticalLayout = new QVBoxLayout(pageData);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetDataToolBar = new QWidget(pageData);
        widgetDataToolBar->setObjectName(QString::fromUtf8("widgetDataToolBar"));
        horizontalLayout_7 = new QHBoxLayout(widgetDataToolBar);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        toolButtonGetNextRec = new QToolButton(widgetDataToolBar);
        toolButtonGetNextRec->setObjectName(QString::fromUtf8("toolButtonGetNextRec"));
        toolButtonGetNextRec->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/png_sqlwindow/resultset_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonGetNextRec->setIcon(icon2);

        horizontalLayout_7->addWidget(toolButtonGetNextRec);

        toolButtonGetAllRec = new QToolButton(widgetDataToolBar);
        toolButtonGetAllRec->setObjectName(QString::fromUtf8("toolButtonGetAllRec"));
        toolButtonGetAllRec->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/png_sqlwindow/resultset_last.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonGetAllRec->setIcon(icon3);

        horizontalLayout_7->addWidget(toolButtonGetAllRec);

        toolButtonCancelAllRecords = new QToolButton(widgetDataToolBar);
        toolButtonCancelAllRecords->setObjectName(QString::fromUtf8("toolButtonCancelAllRecords"));
        toolButtonCancelAllRecords->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/png/png_general/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonCancelAllRecords->setIcon(icon4);

        horizontalLayout_7->addWidget(toolButtonCancelAllRecords);

        horizontalSpacer_6 = new QSpacerItem(537, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        toolButtonRecView = new QToolButton(widgetDataToolBar);
        toolButtonRecView->setObjectName(QString::fromUtf8("toolButtonRecView"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/png/png_sqlwindow/application_side_list.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRecView->setIcon(icon5);

        horizontalLayout_7->addWidget(toolButtonRecView);

        toolButtonResultZoomIn = new QToolButton(widgetDataToolBar);
        toolButtonResultZoomIn->setObjectName(QString::fromUtf8("toolButtonResultZoomIn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png/png_general/viewmag+.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonResultZoomIn->setIcon(icon6);
        toolButtonResultZoomIn->setAutoRepeat(true);
        toolButtonResultZoomIn->setAutoRepeatDelay(100);

        horizontalLayout_7->addWidget(toolButtonResultZoomIn);

        toolButtonResultZoomOut = new QToolButton(widgetDataToolBar);
        toolButtonResultZoomOut->setObjectName(QString::fromUtf8("toolButtonResultZoomOut"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png/png_general/viewmag-.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonResultZoomOut->setIcon(icon7);
#ifndef QT_NO_SHORTCUT
        toolButtonResultZoomOut->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        toolButtonResultZoomOut->setAutoRepeat(true);
        toolButtonResultZoomOut->setAutoRepeatDelay(100);

        horizontalLayout_7->addWidget(toolButtonResultZoomOut);


        verticalLayout->addWidget(widgetDataToolBar);

        tableWidgetResults = new QTableWidget(pageData);
        tableWidgetResults->setObjectName(QString::fromUtf8("tableWidgetResults"));
        tableWidgetResults->setContextMenuPolicy(Qt::ActionsContextMenu);
        tableWidgetResults->setInputMethodHints(Qt::ImhPreferNumbers);
        tableWidgetResults->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetResults->setAlternatingRowColors(true);
        tableWidgetResults->setSortingEnabled(true);
        tableWidgetResults->setWordWrap(false);

        verticalLayout->addWidget(tableWidgetResults);

        stackedWidgetData->addWidget(pageData);
        pageRecordData = new QWidget();
        pageRecordData->setObjectName(QString::fromUtf8("pageRecordData"));
        verticalLayout_2 = new QVBoxLayout(pageRecordData);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widgetRecordToolBar = new QWidget(pageRecordData);
        widgetRecordToolBar->setObjectName(QString::fromUtf8("widgetRecordToolBar"));
        horizontalLayout_8 = new QHBoxLayout(widgetRecordToolBar);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        toolButtonFirstRec = new QToolButton(widgetRecordToolBar);
        toolButtonFirstRec->setObjectName(QString::fromUtf8("toolButtonFirstRec"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/png/png_record/tab_first.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonFirstRec->setIcon(icon8);

        horizontalLayout_8->addWidget(toolButtonFirstRec);

        toolButtonPrevRec = new QToolButton(widgetRecordToolBar);
        toolButtonPrevRec->setObjectName(QString::fromUtf8("toolButtonPrevRec"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/png/png_record/tab_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonPrevRec->setIcon(icon9);
        toolButtonPrevRec->setAutoRepeat(true);

        horizontalLayout_8->addWidget(toolButtonPrevRec);

        toolButtonNextRec = new QToolButton(widgetRecordToolBar);
        toolButtonNextRec->setObjectName(QString::fromUtf8("toolButtonNextRec"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/png/png_record/tab_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonNextRec->setIcon(icon10);
        toolButtonNextRec->setAutoRepeat(true);

        horizontalLayout_8->addWidget(toolButtonNextRec);

        toolButtonLastRec = new QToolButton(widgetRecordToolBar);
        toolButtonLastRec->setObjectName(QString::fromUtf8("toolButtonLastRec"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/png/png_record/tab_last.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonLastRec->setIcon(icon11);

        horizontalLayout_8->addWidget(toolButtonLastRec);

        horizontalSpacer_7 = new QSpacerItem(479, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        toolButtonGridView = new QToolButton(widgetRecordToolBar);
        toolButtonGridView->setObjectName(QString::fromUtf8("toolButtonGridView"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/png/png_sqlwindow/application_view_columns.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonGridView->setIcon(icon12);

        horizontalLayout_8->addWidget(toolButtonGridView);

        toolButtonRecZoomIn = new QToolButton(widgetRecordToolBar);
        toolButtonRecZoomIn->setObjectName(QString::fromUtf8("toolButtonRecZoomIn"));
        toolButtonRecZoomIn->setIcon(icon6);
#ifndef QT_NO_SHORTCUT
        toolButtonRecZoomIn->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        toolButtonRecZoomIn->setAutoRepeat(true);
        toolButtonRecZoomIn->setAutoRepeatDelay(100);

        horizontalLayout_8->addWidget(toolButtonRecZoomIn);

        toolButtonRecZoomOut = new QToolButton(widgetRecordToolBar);
        toolButtonRecZoomOut->setObjectName(QString::fromUtf8("toolButtonRecZoomOut"));
        toolButtonRecZoomOut->setIcon(icon7);
#ifndef QT_NO_SHORTCUT
        toolButtonRecZoomOut->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        toolButtonRecZoomOut->setAutoRepeat(true);
        toolButtonRecZoomOut->setAutoRepeatDelay(100);

        horizontalLayout_8->addWidget(toolButtonRecZoomOut);


        verticalLayout_2->addWidget(widgetRecordToolBar);

        tableWidgetRecord = new QTableWidget(pageRecordData);
        tableWidgetRecord->setObjectName(QString::fromUtf8("tableWidgetRecord"));
        tableWidgetRecord->setContextMenuPolicy(Qt::ActionsContextMenu);
        tableWidgetRecord->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetRecord->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetRecord->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(tableWidgetRecord);

        stackedWidgetData->addWidget(pageRecordData);
        pagePlan = new QWidget();
        pagePlan->setObjectName(QString::fromUtf8("pagePlan"));
        verticalLayout_3 = new QVBoxLayout(pagePlan);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButtonPlanZoomIn = new QToolButton(pagePlan);
        toolButtonPlanZoomIn->setObjectName(QString::fromUtf8("toolButtonPlanZoomIn"));
        toolButtonPlanZoomIn->setIcon(icon6);
#ifndef QT_NO_SHORTCUT
        toolButtonPlanZoomIn->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        toolButtonPlanZoomIn->setAutoRepeat(true);
        toolButtonPlanZoomIn->setAutoRepeatDelay(100);

        horizontalLayout->addWidget(toolButtonPlanZoomIn);

        toolButtonPlanZoomOut = new QToolButton(pagePlan);
        toolButtonPlanZoomOut->setObjectName(QString::fromUtf8("toolButtonPlanZoomOut"));
        toolButtonPlanZoomOut->setIcon(icon7);
#ifndef QT_NO_SHORTCUT
        toolButtonPlanZoomOut->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        toolButtonPlanZoomOut->setAutoRepeat(true);
        toolButtonPlanZoomOut->setAutoRepeatDelay(100);

        horizontalLayout->addWidget(toolButtonPlanZoomOut);


        verticalLayout_3->addLayout(horizontalLayout);

        treeWidgetPlan = new QTreeWidget(pagePlan);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(2, QString::fromUtf8("ID"));
        treeWidgetPlan->setHeaderItem(__qtreewidgetitem);
        treeWidgetPlan->setObjectName(QString::fromUtf8("treeWidgetPlan"));

        verticalLayout_3->addWidget(treeWidgetPlan);

        stackedWidgetData->addWidget(pagePlan);

        gridLayout->addWidget(stackedWidgetData, 0, 0, 1, 1);


        retranslateUi(KvSqlData);

        stackedWidgetData->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(KvSqlData);
    } // setupUi

    void retranslateUi(QWidget *KvSqlData)
    {
        KvSqlData->setWindowTitle(QApplication::translate("KvSqlData", "Form", nullptr));
        actionCopy_to_Clipboard->setText(QApplication::translate("KvSqlData", "Copy to Clipboard", nullptr));
        actionExport_as_Select_Statements_Clipboard->setText(QApplication::translate("KvSqlData", "Export as Select Statements to Clipboard", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExport_as_Select_Statements_Clipboard->setToolTip(QApplication::translate("KvSqlData", "Export as Select Statements to Clipboard", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        toolButtonGetNextRec->setToolTip(QApplication::translate("KvSqlData", "Get next records...", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonGetNextRec->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonGetAllRec->setToolTip(QApplication::translate("KvSqlData", "Get all records", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonGetAllRec->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonCancelAllRecords->setToolTip(QApplication::translate("KvSqlData", "Cancel All Records Retrieval", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonCancelAllRecords->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonRecView->setToolTip(QApplication::translate("KvSqlData", "Show Record View", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonRecView->setText(QApplication::translate("KvSqlData", "...", nullptr));
        toolButtonResultZoomIn->setText(QApplication::translate("KvSqlData", "...", nullptr));
        toolButtonResultZoomOut->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonFirstRec->setToolTip(QApplication::translate("KvSqlData", "First Record", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonFirstRec->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonPrevRec->setToolTip(QApplication::translate("KvSqlData", "Previous Record", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonPrevRec->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonNextRec->setToolTip(QApplication::translate("KvSqlData", "Next Record", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonNextRec->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonLastRec->setToolTip(QApplication::translate("KvSqlData", "Last Record", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonLastRec->setText(QApplication::translate("KvSqlData", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonGridView->setToolTip(QApplication::translate("KvSqlData", "Show Results Grid", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonGridView->setText(QApplication::translate("KvSqlData", "...", nullptr));
        toolButtonRecZoomIn->setText(QApplication::translate("KvSqlData", "...", nullptr));
        toolButtonRecZoomOut->setText(QApplication::translate("KvSqlData", "...", nullptr));
        toolButtonPlanZoomIn->setText(QApplication::translate("KvSqlData", "...", nullptr));
        toolButtonPlanZoomOut->setText(QApplication::translate("KvSqlData", "...", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetPlan->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("KvSqlData", "Cost", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("KvSqlData", "Operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KvSqlData: public Ui_KvSqlData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVSQLDATA_H
