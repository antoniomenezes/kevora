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

#ifndef KVABOUTWINDOW_H
#define KVABOUTWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTranslator>
#include "kvcreditswidget.h"

namespace Ui {
    class KvAboutWindow;
}

/**
  About Kevora Dialog:
  it will present kevora's version and the names of all who contributed to the project.
  The user interface design of this dialog is stored in kvaboutwindow.ui
*/
class KvAboutWindow : public QDialog {
    Q_OBJECT
public:
    explicit KvAboutWindow(QWidget *parent = 0);
    ~KvAboutWindow();
    void loadLanguage();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::KvAboutWindow *m_ui;
    KvCreditsWidget *credits;
};

#endif // KVABOUTWINDOW_H
