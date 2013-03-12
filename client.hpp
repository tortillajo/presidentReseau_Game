#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <QWidget>
#include <QString>
#include <QtNetwork>

class Client : public QWidget
{
        Q_OBJECT
    public:
        Client(QString ip, quint16 port, QString pseudo);
        Client();
        void setSocket(QTcpSocket *sock);
        void setIp(QString ip);
        void setPort(quint16 port);
        void setPseudo(QString pseudo);
        QTcpSocket *socket();
        QString ip();
        quint16 port();
        QString pseudo();

    private:
        bool testIp();
        bool testPort();
        bool testPseudo();

    public slots:
        void connexion();

    private:
        QTcpSocket *m_sock;
        QString m_pseudo;
        QString m_ip;
        quint16 m_port;
};

#endif // CLIENT_HPP
