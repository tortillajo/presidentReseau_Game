#include "mainwindow.hpp"

MainWindow::MainWindow() : QWidget()
{
    m_vlayoutMain = new QVBoxLayout(this);
    m_menuBar = new QMenuBar(this);
    m_menuServer = new QMenu(this);
    m_menuOption = new QMenu(this);
    m_menuAbout = new QMenu(this);
    m_menuFile_actionQuit = new QAction(this);
    m_statusMainbar = new QStatusBar(this);
    m_buttonQuit = new QPushButton(this);
    initializeAllWidgets();
    initializeAllLayouts();
    initializeAllSignals();
}

void MainWindow::initializeAllWidgets()
{
    this->setWindowTitle("Cryxor2013 ");
    this->setLayout(m_vlayoutMain);
    m_vlayoutMain->setMenuBar(m_menuBar);

    m_menuServer = m_menuBar->addMenu(tr("&Connexion", "Connexion aux servs"));
    m_menuOption = m_menuBar->addMenu(tr("&Options", "Option du menu bar"));
    m_menuAbout = m_menuBar->addMenu(tr("A propos", "menu bar a propos"));
    m_menuFile_actionQuit = m_menuServer->addAction(tr("&Quitter"));

    m_buttonQuit->setText(tr("Quitter", "Quitter le programme"));

    m_statusMainbar->showMessage("En attente");
}

void MainWindow::initializeAllLayouts()
{
    m_vlayoutMain->addWidget(m_buttonQuit);
    m_vlayoutMain->addWidget(m_statusMainbar);
}

void MainWindow::initializeAllSignals()
{
    connect(m_buttonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_menuFile_actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
