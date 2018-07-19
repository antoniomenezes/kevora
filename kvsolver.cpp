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

#include "kvsolver.h"

KvSolver::KvSolver(QObject *parent):QObject(parent)
{

}

QPair< QList<KvDbObject>, QList<KvDbObject> > KvSolver::creationOrderOfObjects(const QList<KvDbObject> objectList, const QMap<KvDbObject, QList< QPair<KvDbObject, KvDbObject> > > objectParents, bool emitSignals)
{
    QPair< QList<KvDbObject>, QList<KvDbObject> > resultPair;
    QList<KvDbObject> resultList = QList<KvDbObject>();
    QList<KvDbObject> incompleteList = QList<KvDbObject>();
    QList<KvDbObject> notProcessedList = objectList;


    if (objectParents.count() > 0) {
        // Include all non dependent objects into result list
        foreach(KvDbObject obj, objectList) {
            if (objectParents.values(obj).count() == 0) {
                resultList.append(obj);
                notProcessedList.removeAll(obj);

                if (emitSignals) {
                    int oldPosition = objectList.indexOf(obj);
                    int newPosition = resultList.indexOf(obj);
                    emit creationOrderOfObjectSignal(objectList, obj, oldPosition, newPosition);
                }
            }
        }

        int i = 0;
        int notProcessedListCount = notProcessedList.count();
        // main loop
        while(notProcessedList.count() > 0) {

            KvDbObject objChild = notProcessedList.at(i);
            QList< QPair<KvDbObject, KvDbObject> > childParents = objectParents.value(objChild);
            bool allParentsOut = true;
            for(int p=0; p<childParents.count(); p++) {
                QPair<KvDbObject, KvDbObject> pairParent = childParents.at(p);
                // all parents are outside of not Processsed List
                allParentsOut = (allParentsOut && (!notProcessedList.contains(pairParent.first)));
            }
            if (allParentsOut) {
                resultList.append(objChild);
                notProcessedList.removeAll(objChild);

                if (emitSignals) {
                    int oldPosition = objectList.indexOf(objChild);
                    int newPosition = resultList.indexOf(objChild);
                    emit creationOrderOfObjectSignal(objectList, objChild, oldPosition, newPosition);
                }
            }
            else {
                i++;
            }

            if (i == notProcessedList.count()-1) {
                i = 0;
                // if the not processed list has decreased, update notProcessedListCount
                if (notProcessedListCount > notProcessedList.count()) {
                    notProcessedListCount = notProcessedList.count();
                }
                else {
                    // it's time to choose an object with optional parent relationships and promote this object as processed!
                    int j = 0;
                    bool allParentsInAreOptional = false;
                    bool allChosenParentsAreOptional;

                    while((!allParentsInAreOptional) && (j < notProcessedList.count())) {

                        KvDbObject chosenObj = notProcessedList.at(j);

                        QList< QPair<KvDbObject, KvDbObject> > chosenParents = objectParents.value(chosenObj);

                        for(int p=0; p<chosenParents.count(); p++) {
                            allChosenParentsAreOptional = true;
                            // A pair of parent object and child the foreign key constraint (also represented as an object)
                            QPair<KvDbObject, KvDbObject> pairParent = chosenParents.at(p);
                            // verify if all parents are processsed, except its optional parents
                            if (notProcessedList.contains(pairParent.first)) {
                                // qualifier is true if db object is considered as an optional relationship
                                if (pairParent.second.qualifier)
                                    allChosenParentsAreOptional = (allChosenParentsAreOptional && (pairParent.second.qualifier));
                            }
                        }
                        allParentsInAreOptional = allChosenParentsAreOptional;

                        if (allParentsInAreOptional) {
                            resultList.append(chosenObj);
                            incompleteList.append(chosenObj);
                            notProcessedList.removeAll(chosenObj);

                            if (emitSignals) {
                                int oldPosition = objectList.indexOf(chosenObj);
                                int newPosition = resultList.indexOf(chosenObj);
                                emit creationOrderOfObjectSignal(objectList, chosenObj, oldPosition, newPosition, false);
                            }
                        }
                        else {
                            j++;
                        }
                    }
                }
            }
        }
        // end of main loop
    }
    else {
        resultList = objectList;
    }

    resultPair.first = resultList;
    resultPair.second = incompleteList;
    return resultPair;
}
