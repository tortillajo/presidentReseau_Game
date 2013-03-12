#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <QWidget>
#include <QGridLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include <QString>
#include "serverwindow.hpp"
#include "mainwindow.hpp"
#include "client.hpp"

class ServerWindow;
class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private:
        void initializeAllWidgets();
        void initializeAllLayouts();
        void initializeAllSignals();

    public slots:
    signals:
    private:
        ServerWindow *m_serverWindow;
        Client *m_client;
        //MENU
        QMenuBar *m_menuBar;
        QMenu *m_menuServer;
        QMenu *m_menuOption;
        QMenu *m_menuAbout;
        QAction *m_menuServer_actionConnect;
        QAction *m_menuServer_actionDisconnect;
        QAction *m_menuServer_actionQuit;
        QAction *m_menuAbout_actionReadme;
        //QMenu *m_menuBoomark;
        // MAIN WIDGET
        QVBoxLayout *m_vlayoutMain;
        QStatusBar *m_statusMainbar;
        QPushButton *m_buttonQuit;
};

#endif // MAINWINDOW_HPP
