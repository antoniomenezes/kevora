/****************************************************************************
 **
 ** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** Commercial Usage
 ** Licensees holding valid Qt Commercial licenses may use this file in
 ** accordance with the Qt Commercial License Agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and Nokia.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 2.1 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU Lesser General Public License version 2.1 requirements
 ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** In addition, as a special exception, Nokia gives you certain additional
 ** rights.  These rights are described in the Nokia Qt LGPL Exception
 ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
 **
 ** GNU General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU
 ** General Public License version 3.0 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU General Public License version 3.0 requirements will be
 ** met: http://www.gnu.org/copyleft/gpl.html.
 **
 ** If you have questions regarding the use of this file, please contact
 ** Nokia at qt-info@nokia.com.
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#include <QtGui>
#include "kvcodeeditor.h"


KvCodeEditor::KvCodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new KvLineNumberArea(this);
    lineNumberArea->setForegroundRole(QPalette::WindowText);
    lineNumberArea->setBackgroundRole(QPalette::Light);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(const QRect &, int)), this, SLOT(updateLineNumberArea(const QRect &, int)));
    //connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    updateLineNumberAreaWidth(0);
    //highlightCurrentLine();
}


void KvCodeEditor::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = createStandardContextMenu();
    if ((actions().count() > 0) && (textCursor().hasSelection())){
        menu->addSeparator();
        menu->addActions(this->actions());
    }
    menu->exec(event->globalPos());
    delete menu;
}

void KvCodeEditor::dropEvent(QDropEvent * event)
{
    qDebug()<<"KvMdiArea::dropEvent";
    if (event->mimeData()->hasUrls()) {
        foreach(QUrl url, event->mimeData()->urls()) {
            QString fileName = url.path(QUrl::FullyEncoded); // .encodedPath();

#ifdef Q_OS_WIN
            if (fileName.at(0) == '/')
                fileName = fileName.right(fileName.length()-1);
#endif
            qDebug() << fileName;
            if (QFile::exists(fileName)) {
                emit openFileSignal(fileName);
                event->acceptProposedAction();
            }
        }
    }
    else if (event->mimeData()->hasText()) {
        QString fileName = event->mimeData()->text();

#ifdef Q_OS_WIN
        if (fileName.at(0) == '/')
            fileName = fileName.right(fileName.length()-1);
#endif

        qDebug() << fileName;
        if (QFile::exists(fileName)) {
            emit openFileSignal(fileName);
            event->acceptProposedAction();
        }
    }

}

void KvCodeEditor::dragEnterEvent(QDragEnterEvent* event)
{
         event->acceptProposedAction();
}


void KvCodeEditor::dragMoveEvent(QDragMoveEvent* event)
{
        event->accept();
}



int KvCodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space+10;
}



void KvCodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}



void KvCodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}



void KvCodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}


void KvCodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);

    //painter.fillRect(event->rect(), QColor(240,240,240));


    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            //painter.setPen(Qt::black);
            painter.setFont(this->font());
            painter.drawText(0, top, lineNumberArea->width()-3, fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
