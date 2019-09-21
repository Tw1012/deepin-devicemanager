#pragma once

#include <QWidget>
#include <QList>
#include "DTableWidget"
#include "DScrollArea"

#include "deviceattributedefine.h"

class QLabel;
class QVBoxLayout;

struct DeviceInfo
{
    QLabel* title = nullptr;
    QList<QLabel*>  nameLabels;
    QList<QLabel*>  contentLabels;
};

class DeviceInfoWidgetBase : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceInfoWidgetBase(QWidget *parent = nullptr, const QString& deviceName = "");
    virtual ~DeviceInfoWidgetBase();

    void setTitle(const QString& title);
    void addInfo(const QStringList& names, const QStringList& contents);
    void addLinefeed();
    void addSubInfo(const QString& subTitle, const QStringList& names, const QStringList& contents);
    void addTable(const QStringList& headers, const QList<QStringList>& contentsList);

    void initDownWidget();

    QString getDeviceName();

protected:
    //virtual void focusInEvent(QFocusEvent *e) override{};
    //virtual void focusOutEvent(QFocusEvent *e) override{};
signals:

public slots:

private:
    QString deviceName_ = "DeviceInfoWidgetBase";

    DeviceInfo* titleInfo_ = nullptr;
    QList<DeviceInfo> deviceInfos_;

    QVBoxLayout* vLayout_ = nullptr;
    Dtk::Widget::DTableWidget* tableWidget_ = nullptr;
    Dtk::Widget::DWidget*   downWidget_  = nullptr;
    QVBoxLayout* downWidgetLayout = nullptr;
};
