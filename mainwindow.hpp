#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
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
        //MENU
        QMenuBar *m_menuBar;
        QMenu *m_menuServer;
        QMenu *m_menuOption;
        QMenu *m_menuAbout;
        QAction *m_menuFile_actionQuit;
        QStatusBar *m_statusMainbar;

        QPushButton *m_buttonQuit;

        // MAIN WIDGET
        QVBoxLayout *m_vlayoutMain;
};

#endif // MAINWINDOW_HPP
