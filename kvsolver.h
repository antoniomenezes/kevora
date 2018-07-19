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

#ifndef KVSOLVER_H
#define KVSOLVER_H

#include <QStringList>
#include <QObject>
#include <QMap>
#include <QPair>
#include "kvsqlobject.h"

typedef KvSqlObject<QString, QString, QString, bool> KvDbObject;

class KvSolver : public QObject
{
    Q_OBJECT
public:
    explicit KvSolver(QObject *parent = 0);

signals:
    void creationOrderOfObjectSignal(QList<KvDbObject> objectList, KvDbObject object, int oldPosition, int newPosition, bool completeCreation = true);

public slots:
    QPair< QList<KvDbObject>, QList<KvDbObject> > creationOrderOfObjects(const QList<KvDbObject> objectList, const QMap<KvDbObject, QList< QPair<KvDbObject, KvDbObject> > > objectParents, bool emitSignals = false);
};

#endif // KVSOLVER_H
