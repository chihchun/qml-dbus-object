
#include "dbusobject.h"

#include <QDBusInterface>
#include <QMetaProperty>

#include <QtDebug>

class DBusObjectPrivate
{
public:
    DBusObjectPrivate(): proxy(NULL)
    {
    }

    QString name;
    QString objectPath;
    QString interfaceName;
    QDBusInterface *proxy;
};

DBusObject::DBusObject():
    QQmlPropertyMap(this, NULL)
{
    d = new DBusObjectPrivate();
}

DBusObject::~DBusObject()
{
    delete d;
}

QString DBusObject::name() const
{
    return d->name;
}

void DBusObject::setName(const QString &name)
{
    if (d->proxy) {
        qWarning("DBusObject: cannot set name after initialization");
        return;
    }

    if (d->name != name)
        d->name = name;
}

QString DBusObject::objectPath() const
{
    return d->objectPath;
}

void DBusObject::setObjectPath(const QString &objectPath)
{
    if (d->proxy) {
        qWarning("DBusObject: cannot set objectPath after initialization");
        return;
    }

    if (d->objectPath != objectPath)
        d->objectPath = objectPath;
}

QString DBusObject::interfaceName() const
{
    return d->interfaceName;
}

void DBusObject::setInterfaceName(const QString &interfaceName)
{
    if (d->proxy) {
        qWarning("DBusObject: cannot set interfaceName after initialization");
        return;
    }

    if (d->interfaceName != interfaceName)
        d->interfaceName = interfaceName;
}

void DBusObject::classBegin()
{
}

void DBusObject::componentComplete()
{
    if (d->name.isEmpty() || d->objectPath.isEmpty() || d->interfaceName.isEmpty()) {
        qWarning("DBusObject: name, objectPath, and interfaceName must be given on initialization");
        return;
    }

    d->proxy = new QDBusInterface(d->name, d->objectPath, d->interfaceName,
                                  QDBusConnection::systemBus(), this);

    const QMetaObject *mo = d->proxy->metaObject();
    for (int i = 0; i < mo->propertyCount(); i++) {
        QMetaProperty prop = mo->property(i);
        insert(prop.name(), prop.read(d->proxy));
    }
}
