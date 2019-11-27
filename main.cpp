#include <QCoreApplication>
#include <QList>
#include <QBluetoothDeviceInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QEventLoop>
#include <QtDebug>
#include <QBluetoothUuid>

static const QBluetoothUuid ThingyServiceUuid(QStringLiteral("ef680100-9b35-4933-9b10-52ffa9740042"));

QList<QBluetoothDeviceInfo> discoverDevices() {
    QBluetoothDeviceDiscoveryAgent agent;
    QEventLoop loop;
    QList<QBluetoothDeviceInfo> devices;

    QObject::connect(&agent, SIGNAL(finished()), &loop, SLOT(quit()));
    agent.start();
    loop.exec();
    for (auto device: agent.discoveredDevices())
        if (device.serviceUuids().contains(ThingyServiceUuid))
            devices << device;
    return devices;
}

int main(int argc, char** argv) {
    	QCoreApplication application(argc, argv);

    for (auto device: discoverDevices())
        qDebug() << device.name() << device.address() << device.rssi();
}