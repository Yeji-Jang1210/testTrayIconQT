#pragma once

#include <QtWidgets/QMainWindow>
#include <qaction.h>
#include <qmenu.h>
#include <qsystemtrayicon.h>
#include "ui_mainWindow.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = Q_NULLPTR);

public slots:
    void createTrayIconMenu();
    void trayIconDoubleClick(QSystemTrayIcon::ActivationReason reson);

private:
    Ui::mainWindowClass ui;
    QSystemTrayIcon *windowTrayIcon;
    QMenu *trayIconMenu;
    QAction* viewMainWindow;
    QAction* closeMainWindow;
};
