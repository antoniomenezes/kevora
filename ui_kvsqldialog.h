/********************************************************************************
** Form generated from reading UI file 'kvsqldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVSQLDIALOG_H
#define UI_KVSQLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_KvSqlDialog
{
public:

    void setupUi(QDialog *KvSqlDialog)
    {
        if (KvSqlDialog->objectName().isEmpty())
            KvSqlDialog->setObjectName(QString::fromUtf8("KvSqlDialog"));
        KvSqlDialog->resize(640, 480);

        retranslateUi(KvSqlDialog);

        QMetaObject::connectSlotsByName(KvSqlDialog);
    } // setupUi

    void retranslateUi(QDialog *KvSqlDialog)
    {
        KvSqlDialog->setWindowTitle(QApplication::translate("KvSqlDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KvSqlDialog: public Ui_KvSqlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVSQLDIALOG_H
