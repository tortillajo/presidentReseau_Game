#include "serverwindow.hpp"
#include "client.hpp"
#include <iostream>

ServerWindow::ServerWindow(Client *client) : QWidget()
{
    m_client = client;
    m_gboxMain = new QGridLayout(this);
    m_lineIpServer = new QLineEdit(this);
    m_linePortServer = new QSpinBox(this);
    m_linePseudoServer = new QLineEdit(this);
    m_labelIp  = new QLabel(this);
    m_labelPort  = new QLabel(this);
    m_labelPseudo  = new QLabel(this);;
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
    m_linePortServer->setMaximum(65535);
    m_linePortServer->setMinimum(1025);
    m_linePortServer->setValue(9033);
    m_lineIpServer->setText("127.0.0.1");
    m_linePseudoServer->setText("Unknow");
    m_labelIp->setText(tr("Adresse"));
    m_labelPort->setText(tr("Port"));
    m_labelPseudo->setText(tr("Pseudo"));
    m_buttonCancel->setText(tr("&Annuler", "Quitter"));
    m_buttonConnect->setText(tr("&Connexion", "Connexion au serveur"));
    m_buttonEfface->setText(tr("&Effacer", "Effacer le contenu de la ligne"));
    m_buttonEfface->setEnabled(false);
}

void ServerWindow::initializeAllLayouts()
{
    m_gboxMain->addWidget(m_labelIp,0,0);
    m_gboxMain->addWidget(m_lineIpServer,0,1);
    m_gboxMain->addWidget(m_labelPort,0,2);
    m_gboxMain->addWidget(m_linePortServer,0,3);
    m_gboxMain->addWidget(m_labelPseudo,1,0);
    m_gboxMain->addWidget(m_linePseudoServer,1,1,1,3);
    m_gboxMain->addWidget(m_buttonConnect,2,1,1,2);
    m_gboxMain->addWidget(m_buttonEfface,2,3,1,1);
    m_gboxMain->addWidget(m_buttonCancel,3,1,1,3);
}

void ServerWindow::initializeAllSignals()
{
    connect(m_buttonCancel, SIGNAL(clicked()), this, SLOT(hide()));
    connect(m_buttonConnect,SIGNAL(clicked()), this, SLOT(connexion()));
}

void ServerWindow::connexion()
{
    qDebug() << "Connexion en cours...";
    m_client->setIp(m_lineIpServer->text());
    m_client->setPort(m_linePortServer->value());
    m_client->setPseudo(m_linePseudoServer->text());
    m_client->connexion();
}
