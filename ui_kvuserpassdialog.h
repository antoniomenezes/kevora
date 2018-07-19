/********************************************************************************
** Form generated from reading UI file 'kvuserpassdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVUSERPASSDIALOG_H
#define UI_KVUSERPASSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KvUserPassDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxSavePassword;
    QCheckBox *checkBoxAutoLogon;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *KvUserPassDialog)
    {
        if (KvUserPassDialog->objectName().isEmpty())
            KvUserPassDialog->setObjectName(QStringLiteral("KvUserPassDialog"));
        KvUserPassDialog->resize(312, 156);
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/png_general/db_connection.png"), QSize(), QIcon::Normal, QIcon::Off);
        KvUserPassDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(KvUserPassDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(KvUserPassDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        lineEditUsername = new QLineEdit(KvUserPassDialog);
        lineEditUsername->setObjectName(QStringLiteral("lineEditUsername"));

        horizontalLayout->addWidget(lineEditUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(KvUserPassDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_2);

        lineEditPassword = new QLineEdit(KvUserPassDialog);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(110, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        checkBoxSavePassword = new QCheckBox(KvUserPassDialog);
        checkBoxSavePassword->setObjectName(QStringLiteral("checkBoxSavePassword"));
        checkBoxSavePassword->setEnabled(false);
        checkBoxSavePassword->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(checkBoxSavePassword);

        checkBoxAutoLogon = new QCheckBox(KvUserPassDialog);
        checkBoxAutoLogon->setObjectName(QStringLiteral("checkBoxAutoLogon"));
        checkBoxAutoLogon->setEnabled(false);
        checkBoxAutoLogon->setMinimumSize(QSize(70, 0));

        horizontalLayout_3->addWidget(checkBoxAutoLogon);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(KvUserPassDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEditUsername);
        label_2->setBuddy(lineEditPassword);
#endif // QT_NO_SHORTCUT

        retranslateUi(KvUserPassDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), KvUserPassDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), KvUserPassDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(KvUserPassDialog);
    } // setupUi

    void retranslateUi(QDialog *KvUserPassDialog)
    {
        KvUserPassDialog->setWindowTitle(QApplication::translate("KvUserPassDialog", "User and Password", Q_NULLPTR));
        label->setText(QApplication::translate("KvUserPassDialog", "User Name", Q_NULLPTR));
        label_2->setText(QApplication::translate("KvUserPassDialog", "Password", Q_NULLPTR));
        checkBoxSavePassword->setText(QApplication::translate("KvUserPassDialog", "Save Password", Q_NULLPTR));
        checkBoxAutoLogon->setText(QApplication::translate("KvUserPassDialog", "Auto Logon", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KvUserPassDialog: public Ui_KvUserPassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVUSERPASSDIALOG_H
