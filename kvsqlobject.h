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

#ifndef KVSQLOBJECT_H
#define KVSQLOBJECT_H

#include <QtCore/qdatastream.h>

template <class T1, class T2, class T3, class T4>
struct KvSqlObject
{
    typedef T1 schemaType;
    typedef T2 objectType;
    typedef T3 typeType;
    typedef T4 qualifierType;

    KvSqlObject() : schema(T1()), object(T2()), type(T3()), qualifier(T4()) {}
    KvSqlObject(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4) : schema(t1), object(t2), type(t3), qualifier(t4) {}

    KvSqlObject<T1, T2, T3, T4> &operator=(const KvSqlObject<T1, T2, T3, T4> &other)
    { schema = other.schema; object = other.object; type = other.type; qualifier = other.qualifier; return *this; }

    T1 schema;
    T2 object;
    T3 type;
    T4 qualifier;
};

template <class T1, class T2, class T3, class T4>
Q_INLINE_TEMPLATE bool operator==(const KvSqlObject<T1, T2, T3, T4> &p1, const KvSqlObject<T1, T2, T3, T4> &p2)
{ return p1.schema == p2.schema && p1.object == p2.object && p1.type == p2.type && p1.qualifier == p2.qualifier; }

template <class T1, class T2, class T3, class T4>
Q_INLINE_TEMPLATE bool operator!=(const KvSqlObject<T1, T2, T3, T4> &p1, const KvSqlObject<T1, T2, T3, T4> &p2)
{ return !(p1 == p2); }

template <class T1, class T2, class T3, class T4>
Q_INLINE_TEMPLATE bool operator<(const KvSqlObject<T1, T2, T3, T4> &p1, const KvSqlObject<T1, T2, T3, T4> &p2)
{
    return p1.schema < p2.schema ||
            (!(p2.schema < p1.schema) && p1.object < p2.object) ||
            (!(!(p2.schema < p1.schema) && p1.object < p2.object) && p1.type < p2.type);
}

template <class T1, class T2, class T3, class T4>
Q_INLINE_TEMPLATE bool operator>(const KvSqlObject<T1, T2, T3, T4> &p1, const KvSqlObject<T1, T2, T3, T4> &p2)
{
    return p2 < p1;
}

template <class T1, class T2, class T3, class T4>
Q_INLINE_TEMPLATE bool operator<=(const KvSqlObject<T1, T2, T3, T4> &p1, const KvSqlObject<T1, T2, T3, T4> &p2)
{
    return !(p2 < p1);
}

template <class T1, class T2, class T3, class T4>
Q_INLINE_TEMPLATE bool operator>=(const KvSqlObject<T1, T2, T3, T4> &p1, const KvSqlObject<T1, T2, T3, T4> &p2)
{
    return !(p1 < p2);
}

template <class T1, class T2, class T3, class T4>
Q_OUTOFLINE_TEMPLATE KvSqlObject<T1, T2, T3, T4> qMakeSqlObject(const T1 &s, const T2 &o, const T3 &t, const T4 &q)
{
    return KvSqlObject<T1, T2, T3, T4>(s, o, t, q);
}

#ifndef QT_NO_DATASTREAM
template <class T1, class T2, class T3, class T4>
inline QDataStream& operator>>(QDataStream& s, KvSqlObject<T1, T2, T3, T4>& p)
{
    s >> p.schema >> p.object >> p.type >> p.qualifier;
    return s;
}

template <class T1, class T2, class T3, class T4>
inline QDataStream& operator<<(QDataStream& s, const KvSqlObject<T1, T2, T3, T4>& p)
{
    s << p.schema << p.object << p.type << p.qualifier;
    return s;
}
#endif


#endif // KVSQLOBJECT_H
