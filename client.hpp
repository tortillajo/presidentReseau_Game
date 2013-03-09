#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <QString>
#include <QtNetwork>

class Client
{
    public:
        Client();
        int setSocket(QTcpSocket sock);
        int setIp(QString ip);
        int setPort(quint16 port);
        int setPseudo(QString pseudo);
        QTcpSocket socket();
        QString ip();
        quint16 port();
        QString pseudo();

    private:
        QTcpSocket *m_sock;
        QString m_pseudo;
        QString m_ip;
        quint16 m_port;
};

#endif // CLIENT_HPP
