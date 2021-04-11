#include "dbuscommandlistener.h"
#include <QDebug>

Top* _top;
Bottom* _bottom;
Right* _right;
Left* _left;

void DBusCommandListener::init(Top* t, Bottom* b, Right* r, Left* l)
{
    _top = t;
    _bottom = b;
    _right = r;
    _left = l;
}

//dbus-send --session --type="method_call" --dest=org.MfdSystem / org.MfdSystem.command string:01 string:test string:false
void DBusCommandListener::command(QString pos, QString text, QString inverted){
    _top->updateText(pos,text,inverted);
    _bottom->updateText(pos,text,inverted);
    _right->updateText(pos,text,inverted);
    _left->updateText(pos,text,inverted);
}
