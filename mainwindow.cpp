#include "mainwindow.hpp"
#include "serverwindow.hpp"

MainWindow::MainWindow() : QWidget()
{
    m_serverWindow = new ServerWindow();
    m_vlayoutMain = new QVBoxLayout(this);
    m_menuBar = new QMenuBar(this);
    m_menuServer = new QMenu(this);
    m_menuOption = new QMenu(this);
    m_menuAbout = new QMenu(this);
    m_menuServer_actionConnect = new QAction(this);
    m_menuServer_actionDisconnect = new QAction(this);
    m_menuServer_actionQuit = new QAction(this);
    m_menuAbout_actionReadme = new QAction(this);
    m_statusMainbar = new QStatusBar(this);
    m_buttonQuit = new QPushButton(this);
    initializeAllWidgets();
    initializeAllLayouts();
    initializeAllSignals();
}

void MainWindow::initializeAllWidgets()
{
    this->setWindowTitle(tr("Président Réseau - jeu de carte multijoueur"));
    this->setLayout(m_vlayoutMain);
    m_vlayoutMain->setMenuBar(m_menuBar);

    m_menuServer = m_menuBar->addMenu(tr("&Connexion", "Connexion aux servs"));
    m_menuOption = m_menuBar->addMenu(tr("&Options", "Option du menu bar"));
    m_menuAbout = m_menuBar->addMenu(tr("A propos", "menu bar a propos"));
    m_menuServer_actionConnect = m_menuServer->addAction(tr("&Connexion"));
    m_menuServer_actionDisconnect = m_menuServer->addAction(tr("Déconnexion"));
    m_menuServer_actionQuit = m_menuServer->addAction(tr("&Quitter"));
    m_menuAbout_actionReadme = m_menuAbout->addAction(tr("Manuel", "Readme"));

    m_buttonQuit->setText(tr("Quitter", "Quitter le programme"));
    m_statusMainbar->showMessage("En attente");
    m_serverWindow->hide();
}

void MainWindow::initializeAllLayouts()
{
    m_vlayoutMain->addWidget(m_buttonQuit);
    m_vlayoutMain->addWidget(m_statusMainbar);
}

void MainWindow::initializeAllSignals()
{
    connect(m_buttonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_menuServer_actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(m_menuServer_actionConnect, SIGNAL(triggered()), m_serverWindow, SLOT(show()));
}
