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

#include "kvcreditswidget.h"
#include <QApplication>
#include <QPainter>
#include <QPainterPath>
#include <iostream>


KvCreditsWidget::KvCreditsWidget(QWidget *parent)
    : QWidget(parent)
{
    //x = height() - 180;
    // One timer will trigger another timer. The second moves up the text
    // The first timer will show the initial credits
    x = height() - 440;

    creditsItems.append(tr("Kevora is an Open Source IDE for"));
    creditsItems.append(tr("database designers and"));
    creditsItems.append(tr("developers."));
    creditsItems.append("");
    creditsItems.append(tr("Original design by"));
    creditsItems.append("Antonio Marcio A. Menezes.");
    creditsItems.append("");
    creditsItems.append("");
    creditsItems.append(tr("Website design by"));
    creditsItems.append("Antonio Marcio A. Menezes");
    creditsItems.append("Paul Coiffier Laviolette");
    creditsItems.append("");
    creditsItems.append(tr("Translators"));
    creditsItems.append("");
    creditsItems.append(tr("Brazilian Portuguese translation"));
    creditsItems.append("Antonio Marcio A. Menezes");
    creditsItems.append("");
    creditsItems.append(tr("European Portuguese translation"));
    creditsItems.append("Andrei Gindea");
    creditsItems.append("");
    creditsItems.append(tr("French translation"));
    creditsItems.append("Paul Coiffier Laviolette");
    creditsItems.append("");
    creditsItems.append(tr("German translation"));
    creditsItems.append("Maik Fedtke");
    creditsItems.append("");
    creditsItems.append(tr("Italian translation"));
    creditsItems.append("Oreste Rizello");
    creditsItems.append("Stefano Cereda");
    creditsItems.append("");
    creditsItems.append(tr("Japanese translation"));
    creditsItems.append("Jia Lu");
    creditsItems.append("");
    creditsItems.append(tr("Spanish translation"));
    creditsItems.append("Alexis Medina");
    creditsItems.append("Daniel Gualdron");
    creditsItems.append("Pablo Matamoros");
    creditsItems.append("");
    creditsItems.append("");
    creditsItems.append(tr("Thanks to All Contributors"));
    creditsItems.append("Achilleas Kaskamanidis");
    creditsItems.append("Alexis Medina");
    creditsItems.append("Alexander Marinov");
    creditsItems.append("Andrei Gindea");
    creditsItems.append("Antonio Marcio A. Menezes");
    creditsItems.append("Babatunde Oni");
    creditsItems.append("CLoOVeR");
    creditsItems.append("Daniel Gualdron");
    creditsItems.append("Enio Marconcini");
    creditsItems.append("Fabio Pasini");
    creditsItems.append("Gleyve Rafael P. Barros");
    creditsItems.append("Jerlego");
    creditsItems.append("Jia Lu");
    creditsItems.append("Kiran Ivaturi");
    creditsItems.append("Luca Benini");
    creditsItems.append("Maik Fedtke");
    creditsItems.append("Marcin Kiernek");
    creditsItems.append("Murat A. Genc");
    creditsItems.append("Nathan Filbert");
    creditsItems.append("Omar Lawand Dalatieh");
    creditsItems.append("Oreste Rizello");
    creditsItems.append("Pablo Matamoros");
    creditsItems.append("Paul Coiffier Laviolette");
    creditsItems.append("Stefano Cereda");
    creditsItems.append("Theo Franco");
    creditsItems.append("Vyacheslav Avramenko");
    creditsItems.append("");
    creditsItems.append(tr("Special Greetings"));
    creditsItems.append("Andrew White (QOpenOCCI)");
    creditsItems.append("Everaldo Coelho (Crystal Icons)");
    creditsItems.append("Fabio Pasini");
    creditsItems.append("Gerson Tessler");
    creditsItems.append("Mark James (FamFamFam Icons)");
    creditsItems.append("Roges Grandi");
    creditsItems.append("Vincent Rogier (OCILIB)");
    creditsItems.append("");
    creditsItems.append("SourceForge.net");
    creditsItems.append(tr("Qt Team"));
    creditsItems.append("Nokia");

    //repaint();

    QTimer::singleShot(5000, this, SLOT(startSecondTimer()));
}

void KvCreditsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::white, 1));
    //painter.setPen(QPen(QBrush("#575555"), 1));

    QFont font("Bitstream Vera Sans", 8, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(creditsItems.at(0));
    int textHeight = fm.height();

    painter.setFont(font);


    if (x + ((creditsItems.size()-1)*20) <= -20 ) {
        x = height() + 10;
    }

    /* if (opacity <= 0) {
    killTimer(timer);
    std::cout << "timer stopped" << std::endl;
  } */

    int h = height();
    int w = width();

    for (int l=0; l<=creditsItems.size()-1; ++l) {
        //painter.drawText((w/2) - (textWidth/2), ((h/2) - x) + (l*5), creditsItems.at(l));
        //painter.drawText(0, x + (l*20), w, 20, Qt::AlignHCenter | Qt::AlignVCenter, creditsItems.at(l));
        //painter.drawText(0, x + (l*20), creditsItems.at(l));
        painter.drawText (0, x + (l*20), this->width(), 20, Qt::AlignHCenter, creditsItems.at(l));
    }

}

void KvCreditsWidget::startSecondTimer()
{
    timer = startTimer(30);
}

void KvCreditsWidget::timerEvent(QTimerEvent *event)
{
    x -= 1;
    repaint();
}
