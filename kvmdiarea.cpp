#include "kvmdiarea.h"

KvMdiArea::KvMdiArea(QWidget *parent) : QMdiArea(parent)
{
}

void KvMdiArea::dropEvent(QDropEvent * event)
{
    qDebug()<<"KvMdiArea::dropEvent";
    if (event->mimeData()->hasUrls()) {
        foreach(QUrl url, event->mimeData()->urls()) {
            QString fileName = url.path(QUrl::FullyEncoded); // encodedPath();

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

void KvMdiArea::dragEnterEvent(QDragEnterEvent* event)
{
    qDebug()<<"mainWND::dragEnterEvent";
    //if (event->mimeData()->hasFormat("text/uri-list"))
    event->acceptProposedAction();
}


void KvMdiArea::dragMoveEvent(QDragMoveEvent* event)
{
    qDebug()<<"mainWND::dragMoveEvent";
    event->accept();
}
