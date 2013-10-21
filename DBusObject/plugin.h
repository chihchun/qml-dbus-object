
#include <QtQml>

class DBusObjectPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.canonical.QmlDBusObject")

public:
    void registerTypes(const char *uri);
};
