#pragma once
#include <qwidget.h>
#include <QSystemTrayIcon.h>
#include <qaction.h>

namespace Ui
{
    class TrayIcon;
}
class TrayIcon : public QWidget 
{
    Q_OBJECT
protected:

public:

private slots:

private:
    Ui::TrayIcon* ui;
    QSystemTrayIcon* m_trayIcon;

};