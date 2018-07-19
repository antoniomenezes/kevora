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

#include "kvwaitanimation.h"

KvWaitAnimation::KvWaitAnimation(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    init();
}

KvWaitAnimation::~KvWaitAnimation()
{
    stop();
    delete timer;
}

void KvWaitAnimation::init()
{
    minVal = 0;
    maxVal = 360;
    curVal = 360;
    fColor = Qt::black; //QColor(255, 112, 0);
    sColor = Qt::white; //Qt::yellow;
    //fColor = Qt::blue;
    //sColor = Qt::cyan;
}



void KvWaitAnimation::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int size;
    if (height() < width())
        size = height();
    else
        size = width();
    //painter.setWindow(0, 0, size, size);
    painter.setPen(Qt::gray);
    painter.setRenderHint(QPainter::Antialiasing);

    QRectF border0(3, 3, size-5, size-5);
    qreal ellipseWidth = border0.width();
    qreal ellipseHeight = border0.height();
    QRectF border;
    border.setTopLeft(QPointF(2 + width() - size, 2 + height() - size));
    border.setWidth(ellipseWidth);
    border.setHeight(ellipseHeight);

    painter.setPen(Qt::darkGray);
    painter.setBrush(sColor);
    painter.drawEllipse(border);

    int startAngle = (90+value()) * 16;
    int spanAngle = 90 * 16;
    int startAngle2 = (270+value()) * 16;
    int spanAngle2 = 90 * 16;
    painter.setPen(Qt::darkGray);
    painter.setBrush(fColor);

    painter.drawPie(border, startAngle, spanAngle);
    painter.drawPie(border, startAngle2, spanAngle2);

    painter.setPen(Qt::darkGray);
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(border);

    /*

    QConicalGradient coniGrad(border.center(), value());
    coniGrad.setCenter(border.center());
    coniGrad.setColorAt(0, sColor);
    coniGrad.setColorAt(1, fColor);
    coniGrad.setSpread(QGradient::PadSpread);
    painter.setBrush(coniGrad);*/


    /*QPointF pt = border.center();
    if (true) {
        pt.setX(rect().right() - (20));
    }
    painter.translate(pt);*/

    //painter.drawEllipse(border);
}

void KvWaitAnimation::setValue(double value)
{
    if (value > maxVal)
    {
        curVal = maxVal;
        update();
        return;
    }
    if (value < minVal)
    {
        curVal = minVal;
        update();
        return;
    }
    curVal = value;
    update();
}

void KvWaitAnimation::setMinValue(double min)
{
    if (min > maxVal)
    {
        minVal = maxVal;
        maxVal = min;
        curVal = minVal;
        update();
        return;
    }
    minVal = min;
    update();
}

void KvWaitAnimation::setMaxValue(double max)
{
    if (max < minVal)
    {
        maxVal = minVal;
        minVal = max;
        curVal = minVal;
        update();
        return;
    }
    maxVal = max;
    update();
}

void KvWaitAnimation::setFirstColor(QColor color)
{
    fColor = color;
    update();
}

void KvWaitAnimation::setSecondColor(QColor color)
{
    sColor = color;
    update();
}


void KvWaitAnimation::start() {
    timer->start(5);
}

void KvWaitAnimation::stop() {
    timer->stop();
}

void KvWaitAnimation::refresh() {
    double currentValue = value();
    if (currentValue == 0)
        currentValue = 360;
    else
        currentValue--;
    setValue(currentValue);
    repaint();
}

