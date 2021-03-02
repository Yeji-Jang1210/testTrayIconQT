#include "mainWindow.h"
mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QIcon icon(":/mainWindow/icons/cat.png");
    windowTrayIcon = new QSystemTrayIcon(this);
    
    windowTrayIcon->setVisible(true);
    windowTrayIcon->setToolTip("Tray Program");
    windowTrayIcon->setIcon(icon);
    
    createTrayIconMenu();
    connect(windowTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(trayIconDoubleClick(QSystemTrayIcon::ActivationReason)));
    windowTrayIcon->setContextMenu(trayIconMenu);
    windowTrayIcon->show();
    
}
void mainWindow::createTrayIconMenu() 
{
    trayIconMenu = new QMenu(this);
    viewMainWindow = new QAction("Open", this);
    closeMainWindow = new QAction("Exit", this);

    trayIconMenu->addAction(viewMainWindow);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(closeMainWindow);

    //viewMainWindow, closeMainWindow에서 발생한 SIGNAL을 받을 this의 슬롯지정 
    connect(viewMainWindow, SIGNAL(triggered()), this, SLOT(showNormal()));
    //connect(시그널을 보낼 객체,시그널,슬롯을 가지고있는 객체,객체의 슬롯
    connect(closeMainWindow, SIGNAL(triggered()), this, SLOT(close()));
}
void mainWindow::trayIconDoubleClick(QSystemTrayIcon::ActivationReason reson)
{
    if (reson == QSystemTrayIcon::DoubleClick) 
    {
        if (this->isMinimized()) 
        {
            this->showNormal();
        }
        else 
        {
            this->showMinimized();
        }
    }
}