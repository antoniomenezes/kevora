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

#ifndef KVCREDITSWIDGET_H
#define KVCREDITSWIDGET_H

#include <QWidget>
#include <QTimer>

/**
  Credits Widget:
  it will present all the contributor's names of kevora.
  This widget will behave like a movie's final credits screen.
*/
class KvCreditsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KvCreditsWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    int x;
    int timer;
    QStringList creditsItems; /** This will store the text to be presented */

private slots:
    void startSecondTimer();

};


#endif // KVCREDITSWIDGET_H
