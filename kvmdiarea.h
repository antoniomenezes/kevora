#ifndef KVMDIAREA_H
#define KVMDIAREA_H

#include <QMdiArea>
#include <QDropEvent>
#include <QUrl>
#include <QDebug>
#include <QFile>
#include <QMimeData>

class KvMdiArea : public QMdiArea
{
    Q_OBJECT
public:
    explicit KvMdiArea(QWidget *parent = 0);
protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
    void dropEvent(QDropEvent * event);

signals:
    void openFileSignal(QString);

public slots:

};

#endif // KVMDIAREA_H
