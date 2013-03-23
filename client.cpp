#include "client.hpp"
#include <iostream>

Client::Client(QString ip, quint16 port, QString pseudo) : QWidget()
{
    m_ip = ip;
    m_port = port;
    m_pseudo = pseudo;
}

Client::Client() : QWidget()
{
}

void Client::setIp(QString ip)
{
    m_ip = ip;
}

void Client::setPort(quint16 port)
{
    m_port = port;
}

void Client::setPseudo(QString pseudo)
{
    m_pseudo = pseudo;
}

void Client::setSocket(QTcpSocket *sock)
{
    m_sock = sock;
}

QString Client::ip()
{
    return m_ip;
}

quint16 Client::port()
{
    return m_port;
}

QString Client::pseudo()
{
    return m_pseudo;
}

QTcpSocket* Client::socket()
{
    return m_sock;
}

bool Client::testIp()
{
    if (!m_ip.isEmpty())
        return true;
    qDebug() << "[ERR] ip failed!";
    return false;
}

bool Client::testPort()
{
    if (m_port > 1024 && m_port < 65535)
        return true;
    qDebug() << "[ERR] port failed : " << m_port << "!";
    return false;
}

bool Client::testPseudo()
{
    if (!m_pseudo.isEmpty() && m_pseudo.length() < 16)
        return true;
    qDebug() << "[ERR] pseudo failed!";
    return false;
}

void Client::connexion()
{
    if (testIp() && testPort() && testPseudo())
    {
        qDebug() << "Succes. Waiting connexion...";
        m_sock = new QTcpSocket(this);
        m_sock->connectToHost(m_ip, m_port);
        if (m_sock->waitForConnected(2000))
        {
            qDebug() << "Connection successful!";
        }
        else
        {
            m_sock->error();
            qDebug() << "Connection failed!";
        }
    }
    else
    {
        qDebug() << "[ERR] tests failed!";
    }
    return;
}
