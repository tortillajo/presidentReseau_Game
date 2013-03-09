#include "client.hpp"

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
    return false;
}

bool Client::testPort()
{
    if (!m_port > 1024 && m_port < 65535)
        return true;
    return false;
}

bool Client::testPseudo()
{
    if (!m_pseudo.isEmpty() && m_pseudo.length() < 16)
        return true;
    return false;
}

void Client::connect()
{
    if (testIp() && testPort() && testPseudo())
    {
        m_sock->bind(QHostAddress(m_ip), m_port);
    }
    return;
}
