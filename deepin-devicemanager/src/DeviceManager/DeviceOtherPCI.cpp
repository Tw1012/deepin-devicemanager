#include "DeviceOtherPCI.h"

DeviceOtherPCI::DeviceOtherPCI()
    : DeviceBaseInfo()
    , m_Name("")
    , m_Vendor("")
    , m_Model("")
    , m_Version("")
    , m_BusInfo("")
    , m_Width("")
    , m_Clock("")
    , m_Capabilities("")
    , m_Description("")
    , m_Irq("")
    , m_Memory("")
    , m_Driver("")
    , m_Latency("")
    , m_InputOutput("")
{

}

const QString &DeviceOtherPCI::name()const
{
    return m_Name;
}

const QString &DeviceOtherPCI::vendor()const
{
    return m_Vendor;
}

const QString &DeviceOtherPCI::model()const
{
    return m_Model;
}

const QString &DeviceOtherPCI::version()const
{
    return m_Version;
}

const QString &DeviceOtherPCI::busInfo()const
{
    return m_BusInfo;
}

const QString &DeviceOtherPCI::irq()const
{
    return m_Irq;
}

const QString &DeviceOtherPCI::memory()const
{
    return m_Memory;
}

const QString &DeviceOtherPCI::width()const
{
    return m_Width;
}

const QString &DeviceOtherPCI::clock()const
{
    return m_Clock;
}

const QString &DeviceOtherPCI::capabilities()const
{
    return m_Capabilities;
}

const QString &DeviceOtherPCI::description()const
{
    return m_Description;
}

const QString &DeviceOtherPCI::driver()const
{
    return m_Driver;
}

const QString &DeviceOtherPCI::latency()const
{
    return m_Latency;
}

const QString &DeviceOtherPCI::inputOutput()const
{
    return m_InputOutput;
}

QString DeviceOtherPCI::subTitle()
{
    return m_Model;
}

const QString DeviceOtherPCI::getOverviewInfo()
{
    return m_Name.isEmpty() ? m_Model : m_Name;
}

void DeviceOtherPCI::initFilterKey()
{

}

void DeviceOtherPCI::loadBaseDeviceInfo()
{
    // 添加基本信息
    addBaseDeviceInfo(tr("Name"), m_Name.isEmpty() ? m_Vendor + m_Model : m_Name);
    addBaseDeviceInfo(tr("Vendor"), m_Vendor);
    addBaseDeviceInfo(tr("Model"), m_Model);
    addBaseDeviceInfo(tr("Bus Info"), m_BusInfo);
    addBaseDeviceInfo(tr("Version"), m_Version);
}

void DeviceOtherPCI::loadOtherDeviceInfo()
{
    // 添加其他信息,成员变量
    addOtherDeviceInfo(tr("Input/Output"), m_InputOutput);
    addOtherDeviceInfo(tr("Memory"), m_Memory);
    addOtherDeviceInfo(tr("IRQ"), m_Irq);
    addOtherDeviceInfo(tr("Latency"), m_Latency);
    addOtherDeviceInfo(tr("Clock"), m_Clock);
    addOtherDeviceInfo(tr("Width"), m_Width);
    addOtherDeviceInfo(tr("Driver"), m_Driver);
    addOtherDeviceInfo(tr("Capabilities"), m_Version);

    // 将QMap<QString, QString>内容转存为QList<QPair<QString, QString>>
    mapInfoToList();
}

void DeviceOtherPCI::loadTableData()
{
    m_TableData.append(m_Name);
    m_TableData.append(m_Vendor);
    m_TableData.append(m_Model);
}
