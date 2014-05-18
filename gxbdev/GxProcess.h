#ifndef __TERMINAL_H__
#define __TERMINAL_H__

#include <QTextEdit>

class QKeyPressEvent;
class QProcess;


class Terminal : public QTextEdit
{
    Q_OBJECT

public:
    Terminal(QWidget * = 0);
    ~Terminal();

    bool isRunning();

    void keyPressEvent(QKeyEvent *e);

public slots:
    bool start();
    void sendInput(QString s);
    void dataArrival();


private:

    QProcess *termProcess;
};

#endif
