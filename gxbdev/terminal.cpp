#include "terminal.h"

#include <QProcess>
#include <QtGui>
#include <X11/Xlib.h>
#include <QKeyEvent>
#include <pty.h>
#define XTERM_CMD "/usr/bin/xterm"



Terminal::Terminal(QWidget *parent):
    QTextEdit(parent), termProcess(0)
{
    termProcess = new QProcess(this);
    this->setReadOnly(true);

}


Terminal::~Terminal()
{
    close();
}

void Terminal::keyPressEvent(QKeyEvent *e)
{
    if (e->text().isEmpty() == false)
    {
        sendInput(e->text());
        e->accept();
    }
}

bool Terminal::start()
{

    if (termProcess->state() == QProcess::NotRunning)
    {
        termios termp;
        memset(&termp,0,sizeof(termios));
        winsize winsz;
        int* master;
        int* slave;
        char* name = new char[1024];
        // TODO: decide on pixel/logical sizing, or maybe even NULL if things are rough
        winsz.ws_xpixel = width();
        winsz.ws_ypixel = height();
        winsz.ws_col = 132;
        winsz.ws_row = 50;
        int result =  openpty(master,slave,NULL,&termp,NULL);

        termProcess->setProcessChannelMode(QProcess::MergedChannels);
        connect(termProcess,SIGNAL(readyRead()),this,SLOT(dataArrival()));
        QStringList args;
        args += "-i";
        termProcess->start("/bin/bash",args);
    }
    else if (termProcess->state() == QProcess::Running)
    {
        termProcess->kill();
    }
    return true;
}

void Terminal::sendInput(QString s)
{
    if (termProcess->isWritable() && termProcess->isOpen())
        termProcess->write(s.toLocal8Bit());
}

void Terminal::dataArrival()
{
    while (termProcess->isReadable() && termProcess->isOpen() &&
           termProcess->bytesAvailable() > 0)
    {
        this->document()->setPlainText(this->document()->toPlainText().append(termProcess->readAll()));
    }
}
