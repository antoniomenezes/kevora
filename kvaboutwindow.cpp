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

#include "kvaboutwindow.h"
#include "ui_kvaboutwindow.h"

KvAboutWindow::KvAboutWindow(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::KvAboutWindow)
{
    m_ui->setupUi(this);
    // KvCreditsWidget is just a kind of animation, see the class definition and implementation
    credits = new KvCreditsWidget();
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(credits);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    m_ui->frameCredits->setLayout(layout);
}

KvAboutWindow::~KvAboutWindow()
{
    delete credits;
    delete m_ui;
}

void KvAboutWindow::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void KvAboutWindow::loadLanguage()
{
    QTranslator qtTranslator, kvTranslator;
    QString qmPath = qApp->applicationDirPath() + "/translations";
    kvTranslator.load("kevora_pt_BR.qm", qmPath);
    qtTranslator.load("qt_pt_BR.qm", qmPath);
    QApplication::installTranslator(&kvTranslator);
    QApplication::installTranslator(&qtTranslator);
    m_ui->retranslateUi(this);
}
