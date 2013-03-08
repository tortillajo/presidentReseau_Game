#include "serverwindow.hpp"
#include "mainwindow.hpp"

ServerWindow::ServerWindow() : QWidget()
{
    m_gboxMain = new QGridLayout(this);
    m_lineIpServer = new QLineEdit(this);
    m_linePortServer = new QLineEdit(this);
    m_buttonConnect = new QPushButton(this);
    m_buttonEfface = new QPushButton(this);
    m_buttonCancel = new QPushButton(this);
    initializeAllWidgets();
    initializeAllLayouts();
    initializeAllSignals();
}

void ServerWindow::initializeAllWidgets()
{
    this->setWindowTitle(tr("Connexion à un serveur"));
    m_lineIpServer->setText("");
    m_linePortServer->setText("10313");
    m_buttonCancel->setText(tr("&Annuler", "Quitter"));
    m_buttonConnect->setText(tr("&Connexion", "Connexion au serveur"));
    m_buttonEfface->setText(tr("&Effacer", "Effacer le contenu de la ligne"));
}

void ServerWindow::initializeAllLayouts()
{
    m_gboxMain->addWidget(m_lineIpServer,0,0,1,2);
    m_gboxMain->addWidget(m_linePortServer,0,2,1,1);
    m_gboxMain->addWidget(m_buttonConnect,1,0,1,1);
    m_gboxMain->addWidget(m_buttonEfface,1,1,1,1);
    m_gboxMain->addWidget(m_buttonCancel,2,0,1,3);
}

void ServerWindow::initializeAllSignals()
{
    connect(m_buttonCancel, SIGNAL(clicked()), this, SLOT(hide()));
}
