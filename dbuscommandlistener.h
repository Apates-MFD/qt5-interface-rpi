#ifndef DBUSCOMMANDLISTENER_H
#define DBUSCOMMANDLISTENER_H

#include <QtCore/QObject>
#include "right.h"
#include "left.h"
#include "top.h"
#include "bottom.h"

class DBusCommandListener: public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.MfdSystem")
    public slots:
        Q_SCRIPTABLE void command(QString pos, QString text, QString inverted);
        void init(Top* t, Bottom* b, Right* r, Left* l);
};

#endif // DBUSCOMMANDLISTENER_H
