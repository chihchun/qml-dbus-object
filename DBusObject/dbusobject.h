
#ifndef DBUS_OBJECT_H
#define DBUS_OBJECT_H

#include <QQmlPropertyMap>
#include <QQmlParserStatus>

class DBusObject: public QQmlPropertyMap, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString objectPath READ objectPath WRITE setObjectPath NOTIFY objectPathChanged)
    Q_PROPERTY(QString interfaceName READ interfaceName WRITE setInterfaceName NOTIFY interfaceNameChanged)

public:
    DBusObject();
    ~DBusObject();

    QString name() const;
    void setName(const QString &name);

    QString objectPath() const;
    void setObjectPath(const QString &objectPath);

    QString interfaceName() const;
    void setInterfaceName(const QString &interfaceName);

    // QQmlParserStatus
    void classBegin();
    void componentComplete();

public Q_SLOTS:
    void updateProperties();

Q_SIGNALS:
    void nameChanged(const QString &name);
    void objectPathChanged(const QString &name);
    void interfaceNameChanged(const QString &interface);

private:
    class DBusObjectPrivate *d;
};

#endif
