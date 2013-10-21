
import DBusObject 0.1
import QtQuick 2.0

Item {
  width: 100
  height: 100

  DBusObject {
    id: upower

    name: "org.freedesktop.UPower"
    objectPath: "/org/freedesktop/UPower"
    interfaceName: "org.freedesktop.UPower"
  }

  Text {
    text: upower.OnBattery
  }
}
