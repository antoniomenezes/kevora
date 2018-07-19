/********************************************************************************
** Form generated from reading UI file 'kvexportobjects.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVEXPORTOBJECTS_H
#define UI_KVEXPORTOBJECTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "kvwaitanimation.h"

QT_BEGIN_NAMESPACE

class Ui_KvExportObjects
{
public:
    QAction *actionFind_Objects;
    QAction *actionAdd_Objects_to_Selected;
    QAction *actionRemove_from_Selected;
    QAction *actionClear_Selected;
    QAction *actionExport_Objects;
    QAction *actionSet_Default_Only_One;
    QAction *actionAdd_All_Objects_to_Selected;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *stackedWidgetExportObj;
    QWidget *page1;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *currentSessionComboBox;
    KvWaitAnimation *widgetProgress;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditObjectName;
    QComboBox *comboBoxTypeNames;
    QToolButton *toolButtonFindObj;
    QToolButton *toolButtonFindObj2;
    QSpacerItem *verticalSpacer_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QTableWidget *tableWidgetFoundObj;
    QWidget *widgetRecordCount;
    QGridLayout *gridLayout;
    QLabel *labelRecordCount;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QToolButton *toolButtonNextRecords;
    QToolButton *toolButtonAllRecords;
    QToolButton *toolButtonCancelFetchAll;
    QSpacerItem *verticalSpacer_5;
    QToolButton *toolButtonAddAll;
    QToolButton *toolButtonAddObj;
    QToolButton *toolButtonRemoveObj;
    QToolButton *toolButtonClearObj;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QTableWidget *tableWidgetSelectedObj;
    QLabel *labelSelectedCount;
    QWidget *page3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEditOutputDir;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *comboBoxOutputFormat;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_7;
    QComboBox *comboBoxOutputChoice;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidgetOutputFiles;
    QWidget *page4;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *lineEditOutputDirFinal;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *labelOutputType;
    QTableWidget *tableWidgetExportedObj;
    QHBoxLayout *horizontalLayout_7;
    QProgressBar *progressExportedObjects;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonNextFinish;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *KvExportObjects)
    {
        if (KvExportObjects->objectName().isEmpty())
            KvExportObjects->setObjectName(QStringLiteral("KvExportObjects"));
        KvExportObjects->resize(773, 460);
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/png_general/cog_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        KvExportObjects->setWindowIcon(icon);
        actionFind_Objects = new QAction(KvExportObjects);
        actionFind_Objects->setObjectName(QStringLiteral("actionFind_Objects"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/png_general/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind_Objects->setIcon(icon1);
        actionAdd_Objects_to_Selected = new QAction(KvExportObjects);
        actionAdd_Objects_to_Selected->setObjectName(QStringLiteral("actionAdd_Objects_to_Selected"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/png_record/tab_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Objects_to_Selected->setIcon(icon2);
        actionRemove_from_Selected = new QAction(KvExportObjects);
        actionRemove_from_Selected->setObjectName(QStringLiteral("actionRemove_from_Selected"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/png_record/tab_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_from_Selected->setIcon(icon3);
        actionClear_Selected = new QAction(KvExportObjects);
        actionClear_Selected->setObjectName(QStringLiteral("actionClear_Selected"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/png/png_record/tab_all_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_Selected->setIcon(icon4);
        actionExport_Objects = new QAction(KvExportObjects);
        actionExport_Objects->setObjectName(QStringLiteral("actionExport_Objects"));
        actionSet_Default_Only_One = new QAction(KvExportObjects);
        actionSet_Default_Only_One->setObjectName(QStringLiteral("actionSet_Default_Only_One"));
        actionAdd_All_Objects_to_Selected = new QAction(KvExportObjects);
        actionAdd_All_Objects_to_Selected->setObjectName(QStringLiteral("actionAdd_All_Objects_to_Selected"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/png/png_record/tab_all_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_All_Objects_to_Selected->setIcon(icon5);
        verticalLayout_6 = new QVBoxLayout(KvExportObjects);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        stackedWidgetExportObj = new QStackedWidget(KvExportObjects);
        stackedWidgetExportObj->setObjectName(QStringLiteral("stackedWidgetExportObj"));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        verticalLayout_5 = new QVBoxLayout(page1);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 2, 6, 6);
        frame_3 = new QFrame(page1);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 32));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 6);
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(180, 0));
        label->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_4->addWidget(label);

        currentSessionComboBox = new QComboBox(frame_3);
        currentSessionComboBox->setObjectName(QStringLiteral("currentSessionComboBox"));
        currentSessionComboBox->setMinimumSize(QSize(250, 0));

        horizontalLayout_4->addWidget(currentSessionComboBox);

        widgetProgress = new KvWaitAnimation(frame_3);
        widgetProgress->setObjectName(QStringLiteral("widgetProgress"));
        widgetProgress->setMinimumSize(QSize(24, 24));
        widgetProgress->setMaximumSize(QSize(24, 24));

        horizontalLayout_4->addWidget(widgetProgress);

        horizontalSpacer_2 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(frame_3);

        frame_2 = new QFrame(page1);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 32));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 6, 0, 6);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setMinimumSize(QSize(180, 0));

        horizontalLayout->addWidget(label_2);

        lineEditObjectName = new QLineEdit(frame_2);
        lineEditObjectName->setObjectName(QStringLiteral("lineEditObjectName"));
        lineEditObjectName->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditObjectName->sizePolicy().hasHeightForWidth());
        lineEditObjectName->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEditObjectName);

        comboBoxTypeNames = new QComboBox(frame_2);
        comboBoxTypeNames->setObjectName(QStringLiteral("comboBoxTypeNames"));
        comboBoxTypeNames->setEnabled(false);
        comboBoxTypeNames->setMinimumSize(QSize(180, 0));

        horizontalLayout->addWidget(comboBoxTypeNames);

        toolButtonFindObj = new QToolButton(frame_2);
        toolButtonFindObj->setObjectName(QStringLiteral("toolButtonFindObj"));
        toolButtonFindObj->setEnabled(false);
        toolButtonFindObj->setIcon(icon1);

        horizontalLayout->addWidget(toolButtonFindObj);

        toolButtonFindObj2 = new QToolButton(frame_2);
        toolButtonFindObj2->setObjectName(QStringLiteral("toolButtonFindObj2"));
        toolButtonFindObj2->setMaximumSize(QSize(23, 22));

        horizontalLayout->addWidget(toolButtonFindObj2);


        verticalLayout_5->addWidget(frame_2);

        verticalSpacer_3 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);

        splitter = new QSplitter(page1);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 23));

        verticalLayout_7->addWidget(label_5);

        tableWidgetFoundObj = new QTableWidget(layoutWidget);
        if (tableWidgetFoundObj->columnCount() < 3)
            tableWidgetFoundObj->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetFoundObj->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetFoundObj->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetFoundObj->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidgetFoundObj->setObjectName(QStringLiteral("tableWidgetFoundObj"));
        tableWidgetFoundObj->setAlternatingRowColors(true);
        tableWidgetFoundObj->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetFoundObj->setSortingEnabled(true);
        tableWidgetFoundObj->setWordWrap(false);
        tableWidgetFoundObj->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_7->addWidget(tableWidgetFoundObj);

        widgetRecordCount = new QWidget(layoutWidget);
        widgetRecordCount->setObjectName(QStringLiteral("widgetRecordCount"));
        widgetRecordCount->setMinimumSize(QSize(0, 24));
        gridLayout = new QGridLayout(widgetRecordCount);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 1, 2, 2);
        labelRecordCount = new QLabel(widgetRecordCount);
        labelRecordCount->setObjectName(QStringLiteral("labelRecordCount"));
        labelRecordCount->setMinimumSize(QSize(0, 22));

        gridLayout->addWidget(labelRecordCount, 0, 0, 1, 1);


        verticalLayout_7->addWidget(widgetRecordCount);


        horizontalLayout_3->addLayout(verticalLayout_7);

        frame = new QFrame(layoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 23, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        toolButtonNextRecords = new QToolButton(frame);
        toolButtonNextRecords->setObjectName(QStringLiteral("toolButtonNextRecords"));
        toolButtonNextRecords->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/png/png_sqlwindow/resultset_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonNextRecords->setIcon(icon6);

        verticalLayout->addWidget(toolButtonNextRecords);

        toolButtonAllRecords = new QToolButton(frame);
        toolButtonAllRecords->setObjectName(QStringLiteral("toolButtonAllRecords"));
        toolButtonAllRecords->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/png/png_sqlwindow/resultset_last.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonAllRecords->setIcon(icon7);

        verticalLayout->addWidget(toolButtonAllRecords);

        toolButtonCancelFetchAll = new QToolButton(frame);
        toolButtonCancelFetchAll->setObjectName(QStringLiteral("toolButtonCancelFetchAll"));
        toolButtonCancelFetchAll->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/png/png_sqlwindow/agt_action_fail.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonCancelFetchAll->setIcon(icon8);

        verticalLayout->addWidget(toolButtonCancelFetchAll);

        verticalSpacer_5 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        toolButtonAddAll = new QToolButton(frame);
        toolButtonAddAll->setObjectName(QStringLiteral("toolButtonAddAll"));
        toolButtonAddAll->setEnabled(false);
        toolButtonAddAll->setIcon(icon5);

        verticalLayout->addWidget(toolButtonAddAll);

        toolButtonAddObj = new QToolButton(frame);
        toolButtonAddObj->setObjectName(QStringLiteral("toolButtonAddObj"));
        toolButtonAddObj->setEnabled(false);
        toolButtonAddObj->setIcon(icon2);

        verticalLayout->addWidget(toolButtonAddObj);

        toolButtonRemoveObj = new QToolButton(frame);
        toolButtonRemoveObj->setObjectName(QStringLiteral("toolButtonRemoveObj"));
        toolButtonRemoveObj->setEnabled(false);
        toolButtonRemoveObj->setIcon(icon3);

        verticalLayout->addWidget(toolButtonRemoveObj);

        toolButtonClearObj = new QToolButton(frame);
        toolButtonClearObj->setObjectName(QStringLiteral("toolButtonClearObj"));
        toolButtonClearObj->setEnabled(false);
        toolButtonClearObj->setIcon(icon4);

        verticalLayout->addWidget(toolButtonClearObj);

        verticalSpacer = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(frame);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 23));

        verticalLayout_2->addWidget(label_6);

        tableWidgetSelectedObj = new QTableWidget(layoutWidget1);
        if (tableWidgetSelectedObj->columnCount() < 3)
            tableWidgetSelectedObj->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetSelectedObj->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetSelectedObj->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetSelectedObj->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tableWidgetSelectedObj->setObjectName(QStringLiteral("tableWidgetSelectedObj"));
        tableWidgetSelectedObj->setAlternatingRowColors(true);
        tableWidgetSelectedObj->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetSelectedObj->setSortingEnabled(true);
        tableWidgetSelectedObj->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableWidgetSelectedObj);

        labelSelectedCount = new QLabel(layoutWidget1);
        labelSelectedCount->setObjectName(QStringLiteral("labelSelectedCount"));
        labelSelectedCount->setMinimumSize(QSize(0, 22));

        verticalLayout_2->addWidget(labelSelectedCount);

        splitter->addWidget(layoutWidget1);

        verticalLayout_5->addWidget(splitter);

        stackedWidgetExportObj->addWidget(page1);
        page3 = new QWidget();
        page3->setObjectName(QStringLiteral("page3"));
        verticalLayout_3 = new QVBoxLayout(page3);
        verticalLayout_3->setSpacing(9);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 2, 6, 6);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(page3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(130, 0));

        horizontalLayout_5->addWidget(label_3);

        lineEditOutputDir = new QLineEdit(page3);
        lineEditOutputDir->setObjectName(QStringLiteral("lineEditOutputDir"));

        horizontalLayout_5->addWidget(lineEditOutputDir);

        toolButton = new QToolButton(page3);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMaximumSize(QSize(23, 20));

        horizontalLayout_5->addWidget(toolButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(page3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(130, 0));

        horizontalLayout_6->addWidget(label_4);

        comboBoxOutputFormat = new QComboBox(page3);
        comboBoxOutputFormat->setObjectName(QStringLiteral("comboBoxOutputFormat"));
        comboBoxOutputFormat->setMinimumSize(QSize(160, 0));

        horizontalLayout_6->addWidget(comboBoxOutputFormat);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        label_7 = new QLabel(page3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        comboBoxOutputChoice = new QComboBox(page3);
        comboBoxOutputChoice->setObjectName(QStringLiteral("comboBoxOutputChoice"));
        comboBoxOutputChoice->setMinimumSize(QSize(250, 0));

        horizontalLayout_6->addWidget(comboBoxOutputChoice);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        tableWidgetOutputFiles = new QTableWidget(page3);
        if (tableWidgetOutputFiles->columnCount() < 2)
            tableWidgetOutputFiles->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetOutputFiles->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetOutputFiles->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        tableWidgetOutputFiles->setObjectName(QStringLiteral("tableWidgetOutputFiles"));
        tableWidgetOutputFiles->setContextMenuPolicy(Qt::ActionsContextMenu);
        tableWidgetOutputFiles->setAlternatingRowColors(true);
        tableWidgetOutputFiles->horizontalHeader()->setStretchLastSection(true);
        tableWidgetOutputFiles->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableWidgetOutputFiles);

        stackedWidgetExportObj->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QStringLiteral("page4"));
        verticalLayout_4 = new QVBoxLayout(page4);
        verticalLayout_4->setSpacing(9);
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        frame_4 = new QFrame(page4);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(0, 50));
        frame_4->setMaximumSize(QSize(16777215, 50));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Plain);
        verticalLayout_8 = new QVBoxLayout(frame_4);
#ifndef Q_OS_MAC
        verticalLayout_8->setSpacing(6);
#endif
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(130, 0));

        horizontalLayout_2->addWidget(label_8);

        lineEditOutputDirFinal = new QLineEdit(frame_4);
        lineEditOutputDirFinal->setObjectName(QStringLiteral("lineEditOutputDirFinal"));
        lineEditOutputDirFinal->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditOutputDirFinal);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(130, 0));

        horizontalLayout_8->addWidget(label_9);

        labelOutputType = new QLabel(frame_4);
        labelOutputType->setObjectName(QStringLiteral("labelOutputType"));
        labelOutputType->setMinimumSize(QSize(250, 0));

        horizontalLayout_8->addWidget(labelOutputType);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_4->addWidget(frame_4);

        tableWidgetExportedObj = new QTableWidget(page4);
        if (tableWidgetExportedObj->columnCount() < 4)
            tableWidgetExportedObj->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetExportedObj->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetExportedObj->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetExportedObj->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetExportedObj->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        tableWidgetExportedObj->setObjectName(QStringLiteral("tableWidgetExportedObj"));
        tableWidgetExportedObj->setAlternatingRowColors(true);
        tableWidgetExportedObj->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetExportedObj->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetExportedObj->setWordWrap(false);
        tableWidgetExportedObj->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(tableWidgetExportedObj);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        progressExportedObjects = new QProgressBar(page4);
        progressExportedObjects->setObjectName(QStringLiteral("progressExportedObjects"));
        progressExportedObjects->setValue(0);
        progressExportedObjects->setInvertedAppearance(false);

        horizontalLayout_7->addWidget(progressExportedObjects);


        verticalLayout_4->addLayout(horizontalLayout_7);

        stackedWidgetExportObj->addWidget(page4);

        verticalLayout_6->addWidget(stackedWidgetExportObj);

        frame_8 = new QFrame(KvExportObjects);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setFrameShape(QFrame::NoFrame);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_8);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        pushButtonBack = new QPushButton(frame_8);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));

        horizontalLayout_9->addWidget(pushButtonBack);

        pushButtonNextFinish = new QPushButton(frame_8);
        pushButtonNextFinish->setObjectName(QStringLiteral("pushButtonNextFinish"));

        horizontalLayout_9->addWidget(pushButtonNextFinish);

        pushButtonCancel = new QPushButton(frame_8);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_9->addWidget(pushButtonCancel);


        verticalLayout_6->addWidget(frame_8);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(currentSessionComboBox);
        label_2->setBuddy(lineEditObjectName);
#endif // QT_NO_SHORTCUT

        retranslateUi(KvExportObjects);

        stackedWidgetExportObj->setCurrentIndex(0);
        pushButtonNextFinish->setDefault(true);


        QMetaObject::connectSlotsByName(KvExportObjects);
    } // setupUi

    void retranslateUi(QDialog *KvExportObjects)
    {
        KvExportObjects->setWindowTitle(QApplication::translate("KvExportObjects", "Export Objects Window", Q_NULLPTR));
        actionFind_Objects->setText(QApplication::translate("KvExportObjects", "Find Objects", Q_NULLPTR));
        actionAdd_Objects_to_Selected->setText(QApplication::translate("KvExportObjects", "Add Objects to Selected", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAdd_Objects_to_Selected->setToolTip(QApplication::translate("KvExportObjects", "Add Objects to Selected List", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRemove_from_Selected->setText(QApplication::translate("KvExportObjects", "Remove from Selected", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRemove_from_Selected->setToolTip(QApplication::translate("KvExportObjects", "Remove from Selected List", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionClear_Selected->setText(QApplication::translate("KvExportObjects", "Remove All Selected", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionClear_Selected->setToolTip(QApplication::translate("KvExportObjects", "Remove All Selected from List", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExport_Objects->setText(QApplication::translate("KvExportObjects", "Export Objects", Q_NULLPTR));
        actionSet_Default_Only_One->setText(QApplication::translate("KvExportObjects", "Set Default Name for Only One Output File", Q_NULLPTR));
        actionAdd_All_Objects_to_Selected->setText(QApplication::translate("KvExportObjects", "Add All Objects to Selected", Q_NULLPTR));
        label->setText(QApplication::translate("KvExportObjects", "C&urrent Session", Q_NULLPTR));
        label_2->setText(QApplication::translate("KvExportObjects", "Find [Schema.]&Object", Q_NULLPTR));
        comboBoxTypeNames->clear();
        comboBoxTypeNames->insertItems(0, QStringList()
         << QApplication::translate("KvExportObjects", "Any Type", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        toolButtonFindObj->setToolTip(QApplication::translate("KvExportObjects", "Find Objects", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonFindObj->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
        toolButtonFindObj2->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
        label_5->setText(QApplication::translate("KvExportObjects", "Objects Found", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetFoundObj->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("KvExportObjects", "Schema", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetFoundObj->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("KvExportObjects", "Object", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetFoundObj->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("KvExportObjects", "Type", Q_NULLPTR));
        labelRecordCount->setText(QString());
        toolButtonNextRecords->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
        toolButtonAllRecords->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
        toolButtonCancelFetchAll->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
        toolButtonAddAll->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonAddObj->setToolTip(QApplication::translate("KvExportObjects", "Add Objects to Selected List", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonAddObj->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonRemoveObj->setToolTip(QApplication::translate("KvExportObjects", "Remove Objects from Selected List", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonRemoveObj->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolButtonClearObj->setToolTip(QApplication::translate("KvExportObjects", "Clear Selected List", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolButtonClearObj->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
        label_6->setText(QApplication::translate("KvExportObjects", "Objects to be Exported", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetSelectedObj->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("KvExportObjects", "Schema", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetSelectedObj->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("KvExportObjects", "Object", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetSelectedObj->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("KvExportObjects", "Type", Q_NULLPTR));
        labelSelectedCount->setText(QString());
        label_3->setText(QApplication::translate("KvExportObjects", "Output Directory", Q_NULLPTR));
        toolButton->setText(QApplication::translate("KvExportObjects", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("KvExportObjects", "Output Type", Q_NULLPTR));
        comboBoxOutputFormat->clear();
        comboBoxOutputFormat->insertItems(0, QStringList()
         << QApplication::translate("KvExportObjects", "SQL", Q_NULLPTR)
         << QApplication::translate("KvExportObjects", "Data Dictionary ( .pdf )", Q_NULLPTR)
         << QApplication::translate("KvExportObjects", "Data Dictionary ( .odt )", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("KvExportObjects", "Output Files", Q_NULLPTR));
        comboBoxOutputChoice->clear();
        comboBoxOutputChoice->insertItems(0, QStringList()
         << QApplication::translate("KvExportObjects", "Only One Output File", Q_NULLPTR)
         << QApplication::translate("KvExportObjects", "One File for each Object Type", Q_NULLPTR)
         << QApplication::translate("KvExportObjects", "One File for each Object", Q_NULLPTR)
        );
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetOutputFiles->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("KvExportObjects", "File Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetOutputFiles->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("KvExportObjects", "Description", Q_NULLPTR));
        label_8->setText(QApplication::translate("KvExportObjects", "Output Directory", Q_NULLPTR));
        label_9->setText(QApplication::translate("KvExportObjects", "Output Type", Q_NULLPTR));
        labelOutputType->setText(QString());
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetExportedObj->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("KvExportObjects", "Schema", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetExportedObj->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("KvExportObjects", "Object", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetExportedObj->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("KvExportObjects", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetExportedObj->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("KvExportObjects", "Status", Q_NULLPTR));
        pushButtonBack->setText(QApplication::translate("KvExportObjects", "< Back", Q_NULLPTR));
        pushButtonNextFinish->setText(QApplication::translate("KvExportObjects", "Next >", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("KvExportObjects", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KvExportObjects: public Ui_KvExportObjects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVEXPORTOBJECTS_H
