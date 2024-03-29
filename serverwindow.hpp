#ifndef SERVERWINDOW_HPP
#define SERVERWINDOW_HPP
#include <QGuiApplication>
#include <QApplication>
#include <QWidget>
#include <QClipboard>
#include <QLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QSpinBox>
#include "client.hpp"
#include "serverwindow.hpp"

class MainWindow;
class ServerWindow : public QWidget
{
    Q_OBJECT

    public:
        ServerWindow(Client *client);

    private:
        void initializeAllWidgets();
        void initializeAllLayouts();
        void initializeAllSignals();

    private slots:
        void connexion();

    private:
        Client *m_client;
        QGridLayout *m_gboxMain;
        QLineEdit *m_lineIpServer;
        QSpinBox *m_linePortServer;
        QLineEdit *m_linePseudoServer;
        QLabel *m_labelIp;
        QLabel *m_labelPort;
        QLabel *m_labelPseudo;
        QPushButton *m_buttonConnect;
        QPushButton *m_buttonEfface;
        QPushButton *m_buttonCancel;

};

#endif // SERVERWINDOW_HPP
