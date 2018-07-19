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

#ifndef KVWAITANIMATION_H
#define KVWAITANIMATION_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QCoreApplication>
#include <math.h>

/**
  Wait Animation Widget:
  it will present all the contributor's names of kevora.
  This widget will behave like a movie's final credits screen.
*/
class KvWaitAnimation : public QWidget
{
    Q_OBJECT

    double minValue() {
        return minVal;
    }
    double maxValue() {
        return maxVal;
    }
    QColor firstColor() {
        return fColor;
    }
    QColor secondColor() {
        return sColor;
    }
    
public:
    explicit KvWaitAnimation(QWidget *parent = 0);
    ~KvWaitAnimation();
    void start();
    void stop();

signals:
    void valueChanged(double);

public slots:

    double value() {
        return curVal;
    }
    void setValue(double);
    void setMaxValue(double);
    void setMinValue(double);
    void setFirstColor(QColor);
    void setSecondColor(QColor);
    void refresh();

protected:

    void paintEvent(QPaintEvent *);
    void init();

private:

    double minVal;
    double maxVal;
    double curVal;
    QColor fColor;
    QColor sColor;
    QTimer *timer;

};

#endif // KVWAITANIMATION_H
