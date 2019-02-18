/********************************************************************************
** Form generated from reading UI file 'kvaboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVABOUTWINDOW_H
#define UI_KVABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KvAboutWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *logoWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QFrame *frameCredits;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *KvAboutWindow)
    {
        if (KvAboutWindow->objectName().isEmpty())
            KvAboutWindow->setObjectName(QString::fromUtf8("KvAboutWindow"));
        KvAboutWindow->setWindowModality(Qt::ApplicationModal);
        KvAboutWindow->resize(360, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(KvAboutWindow->sizePolicy().hasHeightForWidth());
        KvAboutWindow->setSizePolicy(sizePolicy);
        KvAboutWindow->setMinimumSize(QSize(360, 450));
        KvAboutWindow->setMaximumSize(QSize(360, 450));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/png_general/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        KvAboutWindow->setWindowIcon(icon);
        KvAboutWindow->setStyleSheet(QString::fromUtf8("QDialog { \n"
"background: qlineargradient(spread:pad, x1:0.293333, y1:0, x2:1, y2:1, stop:0 rgba(67, 67, 67, 255), stop:0.84 rgba(1, 1, 1, 255));\n"
"}"));
        KvAboutWindow->setSizeGripEnabled(false);
        KvAboutWindow->setModal(true);
        verticalLayout_2 = new QVBoxLayout(KvAboutWindow);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 25, 10, 16);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(150, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        logoWidget = new QWidget(KvAboutWindow);
        logoWidget->setObjectName(QString::fromUtf8("logoWidget"));
        logoWidget->setMinimumSize(QSize(120, 140));
        logoWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background: transparent;\n"
"background-image: url(:/png/png_general/kevoraBig.png);\n"
"background-origin: content;\n"
"background-repeat: none;\n"
"}"));

        horizontalLayout->addWidget(logoWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(KvAboutWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 0));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: white;\n"
"font: bold 28px;"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout->addWidget(label);

        label_3 = new QLabel(KvAboutWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: white;\n"
"font: bold 14px;"));
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        frameCredits = new QFrame(KvAboutWindow);
        frameCredits->setObjectName(QString::fromUtf8("frameCredits"));
        frameCredits->setMinimumSize(QSize(0, 180));
        frameCredits->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"alignment: hcenter;"));
        frameCredits->setFrameShape(QFrame::NoFrame);
        frameCredits->setFrameShadow(QFrame::Plain);

        verticalLayout_2->addWidget(frameCredits);

        buttonBox = new QDialogButtonBox(KvAboutWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMinimumSize(QSize(0, 50));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(KvAboutWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), KvAboutWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), KvAboutWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(KvAboutWindow);
    } // setupUi

    void retranslateUi(QDialog *KvAboutWindow)
    {
        KvAboutWindow->setWindowTitle(QApplication::translate("KvAboutWindow", "About Kevora", nullptr));
        label->setText(QApplication::translate("KvAboutWindow", "Kevora", nullptr));
        label_3->setText(QApplication::translate("KvAboutWindow", "Version 1.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KvAboutWindow: public Ui_KvAboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVABOUTWINDOW_H
