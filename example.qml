
import DBusObject 0.1
import QtQuick 2.0
import Ubuntu.Components 0.1

Item {
  width: 100
  height: 100

  DBusObject {
    id: upower

    name: "org.freedesktop.UPower"
    objectPath: "/org/freedesktop/UPower"
    interfaceName: "org.freedesktop.UPower"
  }
  Column {
      Text {
          text: upower.OnBattery
          // text: upower.EnumerateDevices()
      }
      Button {
          id: updateButton
          Component.onCompleted: updateButton.clicked.connect(upower.updateProperties)
      }
  }
}
