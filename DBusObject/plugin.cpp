
#include "plugin.h"
#include "dbusobject.h"

void DBusObjectPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<DBusObject>(uri, 0, 1, "DBusObject");
}
